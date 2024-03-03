#include "search.h"
#include <iostream>
#include <dirent.h>
#include <sys/stat.h>
#include <cstring>

bool searchFile(const std::string& filename, const std::string& directory) {
    DIR* dir = opendir(directory.c_str());
    if (dir == nullptr) {
        perror("opendir");
        return false;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip current and parent directories
        }

        std::string path = directory + "/" + entry->d_name;
        struct stat statbuf;
        if (lstat(path.c_str(), &statbuf) == -1) {
            perror("lstat");
            closedir(dir);
            return false;
        }

        if (S_ISLNK(statbuf.st_mode)) {
            // Skip symbolic links
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            // Recursively search subdirectories
            if (searchFile(filename, path)) {
                closedir(dir);
                return true;
            }
        } else if (S_ISREG(statbuf.st_mode)) {
            if (strcmp(entry->d_name, filename.c_str()) == 0) {
                std::cout << "File found at: " << path << std::endl;
                closedir(dir);
                return true;
            }
        }
    }

    closedir(dir);
    return false;
}



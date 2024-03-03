#include <iostream>
#include "search.h"

int main() {
    std::string filename;
    std::cout << "Enter the filename to search: ";
    std::cin >> filename;

    if (searchFile(filename, "/")) {
        std::cout << "File found!" << std::endl;
    } else {
        std::cout << "File not found." << std::endl;
    }

    return 0;
}


CC = g++
CFLAGS = -Wall -std=c++17
LDFLAGS = -pthread

APP_SRC = SearchApp.cpp
LIB_SRC = search.cpp
LIB_OBJ = search.o
LIB = libsearch.a
APP = search_app

all: $(APP)

$(LIB_OBJ): $(LIB_SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIB): $(LIB_OBJ)
	ar rcs $@ $<

$(APP): $(APP_SRC) $(LIB)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) -L. -lsearch

clean:
	rm -f $(LIB_OBJ) $(LIB) $(APP)


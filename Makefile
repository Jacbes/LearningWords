CC = gcc
CFLAGS = -Wall -Werror
EXECUTABLE = prog

all: bin/$(EXECUTABLE)

bin/$(EXECUTABLE): build/main.o build/interface.o build/wdictionary.o build/string.o
	$(CC) $(CFLAGS) $^ -o $@

build/main.o: src/main.c
	$(CC) $(CFLAGS) -c $< -o $@

build/interface.o: src/interface.c
	$(CC) $(CFLAGS) -c $< -o $@

build/wdictionary.o: src/wdictionary.c
	$(CC) $(CFLAGS) -c $< -o $@

build/string.o: src/string.c
	$(CC) $(CFALGS) -c $< -o $@

.PHONY: clean

clean:
	rm -rf build/*.o
all: bin/prog

bin/prog: build/main.o build/interface.o 
	gcc -Wall -Werror build/main.o build/interface.o -o bin/prog

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o

build/interface.o: src/interface.c
	gcc -Wall -Werror -c src/interface.c -o build/interface.o

.PHONY: clean

clean:
	rm -rf build/*.o
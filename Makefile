CC = gcc
CFLAGS = -Wall -Werror
EXECUTABLE = prog
EXETEST = test

all: bin/$(EXECUTABLE) bin/$(EXETEST)

bin/$(EXECUTABLE): build/prg/main.o build/prg/interface.o build/prg/wdictionary.o build/prg/string.o
	$(CC) $(CFLAGS) $^ -o $@

bin/$(EXETEST): build/tst/main.o build/tst/wdictionary_test.o build/prg/interface.o build/prg/string.o build/prg/wdictionary.o
	$(CC) $(CFLAGS) $^ -o $@

build/prg/main.o: src/main.c
	$(CC) $(CFLAGS) -c $< -o $@

build/prg/interface.o: src/interface.c
	$(CC) $(CFLAGS) -c $< -o $@

build/prg/wdictionary.o: src/wdictionary.c
	$(CC) $(CFLAGS) -c $< -o $@

build/prg/string.o: src/string.c
	$(CC) $(CFALGS) -c $< -o $@

build/tst/main.o: test/main.c
	$(CC) $(CFLAGS) -c $< -o $@

build/tst/wdictionary_test.o: test/wdictionary_test.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -rf build/prg/*.o build/tst/*.o
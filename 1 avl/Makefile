BINARY=trab5
SOURCES=main.c readline.c memory.c node.c tree.c game.c
INCLUDES=.

all: clean compile clean

compile:
	@gcc -o $(BINARY) $(SOURCES) -I$(INCLUDES)

clean:
	@find -name '*~' | xargs rm -rf {}
	@find -name '*.o' | xargs rm -rf {}

run:
	@./trab5

zip:
	zip -r trab5.zip *.c *.h Makefile
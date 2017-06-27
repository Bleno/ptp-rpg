CFLAGS = -Wall -pedantic
LFLAGS = `sdl-config --libs` -lSDL -lSDL_image -lSDL_ttf
OBJS   = init.o input.o graphics.o menu.o main.o font.o score.o choose.o player.o battle.o rules.o gameover.o
CC=gcc
PROG = ptp

all: $(PROG)

%.o: src/%.c src/%.h src/defs.h src/structs.h
	$(CC) $(CFLAGS) -c -s $<

ptp: $(OBJS)
	$(CC) $(OBJS) -o $(PROG) $(LFLAGS)

clean:
	rm -vf $(PROG) *.o
#bin/ptp src/main.c src/menu.c src/menu.h
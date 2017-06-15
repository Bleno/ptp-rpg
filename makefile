CC=gcc
CFLAGS = -I
PROG = ptp

ptp: src/main.c src/menu.c src/menu.h src/choose.c src/choose.h src/score.c src/score.h src/character.c src/character.h src/battle.c src/battle.h 
	$(CC) -o bin/$(PROG) src/main.c src/menu.c src/menu.h src/choose.c src/choose.h src/score.c src/score.h src/character.c src/character.h src/battle.c src/battle.h -I.

clean:
	rm -f bin/$(PROG)
#bin/ptp src/main.c src/menu.c src/menu.h
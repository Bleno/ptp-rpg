ptp: src/main.c src/menu.c src/menu.h
	gcc -o bin/ptp src/main.c src/menu.c src/menu.h -I.

#bin/ptp src/main.c src/menu.c src/menu.h


all: mygame game.so

CC=clang
LDFLAGS=-framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL $(shell pkg-config --libs raylib)
CFLAGS=$(shell pkg-config --cflags raylib)


mygame: mygame.c reload.c
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

game.so: game.c
	$(CC) $(CFLAGS) $(LDFLAGS) -fPIC -shared $^ -o $@

clean:
	rm mygame

run: mygame
	./mygame &

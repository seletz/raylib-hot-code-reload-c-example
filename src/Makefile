

all: mygame

CC=clang
LDFLAGS=-framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
CFLAGS=-I../../raylib/src
LIBS=../lib/libraylib.a


mygame: mygame.c
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBS) $^ -o $@

clean:
	rm mygame

run: mygame
	./mygame &

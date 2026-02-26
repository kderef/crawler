CC = gcc
CFLAGS = -Iraylib/src -I.

LIBRAYLIB = raylib/src/libraylib.a

BIN = bin/game
GAME = bin/game.o

ifdef OS
	# Windows
	OSFLAGS =
else
	ifeq ($(shell uname), Linux)
		# TODO
	endif
	ifeq ($(shell uname), Darwin)
		OSFLAGS = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
	endif
endif

FLAGS = $(CFLAGS) $(OSFLAGS)

$(BIN): $(LIBRAYLIB) $(GAME) src/*
	$(CC) $(FLAGS) $(LIBRAYLIB) $(GAME) src/main.c -o $(BIN)

$(GAME): game/*
	$(CC) $(FLAGS) -c game/game.c -o $(GAME)

$(LIBRAYLIB): raylib/src/*.[ch]
	make -C raylib/src

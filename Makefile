CC = gcc
CFLAGS = -Iraylib/src -I. -Wall -Wextra -s -O2

LIBRAYLIB = raylib/src/libraylib.a

BIN = bin/game
O_GAME = bin/game.o
O_MAIN = bin/main.o

ifdef OS
	# Windows
	OSFLAGS = -lgdi32 -lwinmm
else
	ifeq ($(shell uname), Linux)
		# TODO
	endif
	ifeq ($(shell uname), Darwin)
		OSFLAGS = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
	endif
endif

FLAGS = $(CFLAGS) $(OSFLAGS)

$(BIN): $(LIBRAYLIB) $(O_GAME) $(O_MAIN)
	$(CC) $(O_GAME) $(O_MAIN) $(LIBRAYLIB) -o $(BIN) $(FLAGS)

$(O_MAIN): src/main.c
	$(CC) $(FLAGS) -c src/main.c -o $(O_MAIN)

$(O_GAME): game/*
	$(CC) $(FLAGS) -c game/game.c -o $(O_GAME)

$(LIBRAYLIB): raylib/src/*.[ch]
	make -C raylib/src

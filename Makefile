CC = gcc
CFLAGS = -Iraylib/src -I. -Wall -Wextra -s -O2

LIBRAYLIB = raylib/src/libraylib.a

BIN = bin/game
O_GAME = bin/game.o
O_MAIN = bin/main.o
O_SKBX = bin/skybox.o
O_PLCM = bin/player_camera.o

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

$(BIN): $(LIBRAYLIB) $(O_GAME) $(O_SKBX) $(O_PLCM)
	$(CC) src/main.c $(O_GAME) $(O_SKBX) $(O_PLCM) $(LIBRAYLIB) -o $(BIN) $(FLAGS)

$(O_SKBX): src/skybox.*
	$(CC) $(CFLAGS) -c src/skybox.c -o $(O_SKBX)

$(O_GAME): src/game.*
	$(CC) $(CFLAGS) -c src/game.c -o $(O_GAME)

$(O_PLCM): src/player_camera.*
	$(CC) $(CFLAGS) -c src/player_camera.c -o $(O_PLCM)
	
$(LIBRAYLIB): raylib/src/*.[ch]
	make -C raylib/src

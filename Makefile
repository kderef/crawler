CC = gcc
LD = ld
CFLAGS = -O3 -Iraylib/src -Wall
CCFLAGS = -O3 

MAIN = src/main.c
BIN = bin/crawler

LIBRAYLIB = raylib/src/libraylib.a

# platform flags
LINUX_FLAGS =

# check OS
ifeq ($(OS), Windows_NT)
	# WINDOWS
	CCFLAGS += -lwinmm -lgdi32 -lopengl32
else
	UNAME_S := $(shell uname -s)
	# MACOS
	ifeq ($(UNAME_S), Darwin)
		CCFLAGS += -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL

	# LINUX (or something obscure)
	else
		CCFLAGS += 
	endif
endif

$(BIN): main.o game.o $(LIBRAYLIB)
	$(CC) main.o game.o $(LIBRAYLIB) $(CCFLAGS) -o $(BIN)

$(LIBRAYLIB):
	make -C raylib/src
	
main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c

game.o: src/game.c game_update.o game_draw.o
	$(CC) $(CFLAGS) -c src/game.c

game_update.o: src/game_update.c
	$(CC) $(CFLAGS) -c src/game_update.c
	
game_draw.o: src/game_draw.c
	$(CC) $(CFLAGS) -c src/game_draw.c

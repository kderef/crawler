CC = gcc
LD = ld
CFLAGS = -O3 -Iraylib/src -Iraygui/src -Isrc -Wall
CCFLAGS = -O3 

MAIN = src/main.cc
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

$(BIN): level.o assets.o draw.o update.o game.o main.o $(LIBRAYLIB) raygui.o
	$(CC) game.o level.o assets.o draw.o update.o main.o raygui.o $(LIBRAYLIB) $(CCFLAGS) -o $(BIN)

$(LIBRAYLIB):
	make -C raylib/src
	
raygui.o: raygui.c
	$(CC) -Iraylib/src -c raygui.c

main.o: src/main.c src/log.c src/scene/scene.c
	$(CC) $(CFLAGS) -c src/main.c

game.o:  src/game.c src/game.h src/scene/scene.c
	$(CC) $(CFLAGS) -c src/game.c

update.o: src/update/*update* src/scene/*/*update*
	$(CC) $(CFLAGS) -c src/update/update.c

draw.o: src/draw/*draw* src/scene/*/*draw*
	$(CC) $(CFLAGS) -c src/draw/draw.c

assets.o: src/assets.c src/assets.h
	$(CC) $(CFLAGS) -c src/assets.c

level.o: src/level/*
	$(CC) $(CFLAGS) -c src/level/level.c

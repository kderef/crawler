CC = gcc
LD = ld
CFLAGS = -O3 -Iraylib/src -Iraygui/src -Isrc -Wall
CCFLAGS = -O3 

MAIN = src/main.c
BIN = bin/crawler

LIBRAYLIB = raylib/src/libraylib.a

# platform flags
LINUX_FLAGS =
DEL := rm

# check OS
ifeq ($(OS), Windows_NT)
	# WINDOWS
	CCFLAGS += -lwinmm -lgdi32 -lopengl32 -static
	DEL := cmd /C del
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

$(BIN): main.o game.o $(LIBRAYLIB) raygui.o
	$(CC) game.o update.o draw.o main.o raygui.o assets.o $(LIBRAYLIB) $(CCFLAGS) -o $(BIN)

$(LIBRAYLIB):
	make -C raylib/src
	
raygui.o: raygui.c
	$(CC) -Iraylib/src -c raygui.c

main.o: src/main.c src/settings.c src/settings.h
	$(CC) $(CFLAGS) -c src/main.c

game.o: src/game.c update.o draw.o assets.o
	$(CC) $(CFLAGS) -c src/game.c

assets.o: src/assets.c src/assets.h
	$(CC) $(CFLAGS) -c src/assets.c

update.o: src/update/*.[ch]
	$(CC) $(CFLAGS) -c src/update/update.c
	
draw.o: src/draw/*.[ch]
	$(CC) $(CFLAGS) -c src/draw/draw.c

clean:
	$(DEL) *.o
	$(DEL) bin\*

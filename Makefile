CC = g++
CFLAGS := -O2 -Iraylib/src

LIBRAYLIB = raylib/src/libraylib.a
GAME = bin/game.exe
ENGINE = bin/engine.o

$(GAME): $(LIBRAYLIB) $(ENGINE) game/*
	$(CC) $(CFLAGS) $(ENGINE) game/main.cpp -o $(GAME) -I.

$(LIBRAYLIB):
	make -C raylib/src/

$(ENGINE): $(LIBRAYLIB) engine/*
	$(CC) $(CFLAGS) -c engine/engine.cpp -o $(ENGINE)

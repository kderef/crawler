package main

import "game"

main :: proc() {
	g := game.init()

	for g.running {
		game.tick(&g)
		game.draw(&g)
	}

	game.close(&g)
}

package game

import rl "vendor:raylib"

Game :: struct {
	running: bool
} //


init :: proc() -> Game {
	return {
		running = true,
	}
}

tick :: proc(g: ^Game) {
	
}
draw :: proc(g: ^Game) {
	
}

close :: proc(g: ^Game) {
	
}

mod math;
#[cfg_attr(not(debug_assertions), windows_subsystem = "windows")]
mod text;

mod font;

use minifb::{Key, Window, WindowOptions};

const WIDTH: usize = 640;
const HEIGHT: usize = 360;

pub type Buffer = Vec<u32>;

pub struct Game {
    pub width: usize,
    pub height: usize,
    pub buffer: Vec<u32>,
}

impl Game {
    pub fn new(size: (usize, usize)) -> Self {
        Self {
            width: size.0,
            height: size.1,
            buffer: Buffer::with_capacity(size.0 * size.1),
        }
    }
}

fn main() {
    font::test();
    return;

    // --- setup
    let mut window = Window::new(
        "Test - ESC to exit",
        WIDTH,
        HEIGHT,
        WindowOptions::default(),
    )
    .unwrap_or_else(|e| {
        panic!("{}", e);
    });

    // Limit to max ~60 fps update rate
    window.set_target_fps(60);

    // --- create game
    let mut game = Game::new((WIDTH, HEIGHT));

    while window.is_open() {
        // We unwrap here as we want this code to exit if it fails. Real applications may want to handle this in a different way
        window
            .update_with_buffer(&game.buffer, game.width, game.height)
            .unwrap();
    }
}

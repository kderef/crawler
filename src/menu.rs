use crate::{
    draw::draw_text_shadowed,
    scene::{Scene, SceneChange},
};
use macroquad::prelude::*;

pub struct Menu {}

impl Menu {
    pub fn new() -> Self {
        Self {}
    }
}

const BG: Color = color_u8!(25, 25, 25, 255);

impl Scene for Menu {
    fn handle_input(&mut self) {}
    fn update(&mut self) -> Option<SceneChange> {
        None
    }
    fn draw(&self) {
        clear_background(BG);

        draw_text_shadowed("Crawler", 100., 100., 30., WHITE, GRAY);
    }
}

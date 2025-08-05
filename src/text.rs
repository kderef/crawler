use std::ops::IndexMut;

pub trait DrawText {
    fn draw_text(&mut self, text: impl AsRef<str>, x: u32, y: u32, size: u32) {}
}

impl DrawText for Vec<u32> {
    fn draw_text(&mut self, text: impl AsRef<str>, x: u32, y: u32, size: u32) {}
}

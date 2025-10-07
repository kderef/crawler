use std::{cell::OnceCell, sync::LazyLock};

use macroquad::prelude::*;

pub static FONT_DATA: &[u8] = include_bytes!("../assets/BigBlueTerminal/BigBlue_TerminalPlus.TTF");
pub static mut FONT: LazyLock<Font> =
    LazyLock::new(|| load_ttf_font_from_bytes(FONT_DATA).unwrap());

pub fn get_font() -> &'static Font {
    unsafe { &*FONT }
}

pub fn draw_text_shadowed(
    text: impl AsRef<str>,
    x: f32,
    y: f32,
    ft_size: f32,
    color: Color,
    shadow: Color,
) {
    let text = text.as_ref();

    // draw shadow first
    let shadow_offset = ft_size / 10.;
    let shadow_x = x + shadow_offset;
    let shadow_y = y + shadow_offset;

    draw_text(text, shadow_x, shadow_y, ft_size, shadow);

    // then draw the text
    draw_text(text, x, y, ft_size, color);
}

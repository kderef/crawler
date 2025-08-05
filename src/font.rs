use std::{path::Path, sync::OnceLock};

use macroquad::prelude::*;

/// All the fonts used throughout the game, loaded once
pub static FONTS: OnceLock<Fonts> = OnceLock::new();

pub struct Fonts {
    pub bbt_plus: Font,
}

impl Fonts {
    // 'aaaaaa
    pub fn main<'a>(&'a self) -> &'a Font {
        &self.bbt_plus
    }
}

/// Load font, then set filter to nearest
pub async fn load_pixel_font(path: impl AsRef<str>) -> Result<Font, macroquad::Error> {
    load_ttf_font(path.as_ref()) // load font and set filter
        .await
        .map(|mut f| {
            f.set_filter(FilterMode::Nearest);
            f
        })
}

/// Get FONTS or panic
pub fn fonts() -> &'static Fonts {
    FONTS.get().unwrap()
}

pub fn custom_text(text: impl AsRef<str>, x: f32, y: f32, fs: u16, color: Color) -> TextDimensions {
    draw_text_ex(
        text.as_ref(),
        x,
        y,
        TextParams {
            font: Some(fonts().main()),
            font_size: fs,
            font_scale: 1.,
            font_scale_aspect: 1.,
            color,
            rotation: 0.,
        },
    )
}

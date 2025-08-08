use crate::font;

use font::Fonts;
use macroquad::prelude::*;

pub struct Game {
    pub fonts: Fonts,
}

impl Game {
    pub async fn init() -> anyhow::Result<Self> {
        // setup fonts
        let fonts = Fonts::load().await?;

        let game = Self { fonts };

        Ok(game)
    }

    pub fn base_font_size(&self) -> u16 {
        let sw = screen_width();
        let size = sw * 0.03;
        size as u16
    }

    // pub fn centered_text(
    //     &self,
    //     text: impl AsRef<str>,
    //     left: f32,
    //     right: f32,
    // )

    pub fn custom_text(
        &self,
        text: impl AsRef<str>,
        x: f32,
        y: f32,
        fs: u16,
        color: Color,
    ) -> TextDimensions {
        draw_text_ex(
            text.as_ref(),
            x,
            y,
            TextParams {
                font: Some(self.fonts.main()),
                font_size: fs,
                font_scale: 1.,
                font_scale_aspect: 1.,
                color,
                rotation: 0.,
            },
        )
    }
}

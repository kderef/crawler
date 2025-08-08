use std::{path::Path, sync::OnceLock};

use crate::log;

use macroquad::prelude::*;

pub struct FontDesc(pub Box<str>, pub macroquad::text::Font);

impl FontDesc {
    pub async fn load(path: &str) -> Result<Self, macroquad::Error> {
        log!("Loading font {path}");
        Ok(Self(path.into(), load_ttf_font(path).await?))
    }
    pub async fn load_pixel(path: &str) -> Result<Self, macroquad::Error> {
        Self::load(path).await.map(|mut f| {
            f.1.set_filter(FilterMode::Nearest);
            f
        })
    }
}

impl AsRef<Font> for FontDesc {
    fn as_ref(&self) -> &Font {
        &self.1
    }
}

pub struct Fonts {
    pub bbt_plus: FontDesc,
}

impl Fonts {
    pub async fn load() -> Result<Self, macroquad::Error> {
        let me = Self {
            bbt_plus: FontDesc::load_pixel("bbt/BigBlue_TerminalPlus.ttf").await?,
        };

        Ok(me)
    }

    // 'aaaaaa
    pub fn main<'a>(&'a self) -> &'a Font {
        self.bbt_plus.as_ref()
    }
}

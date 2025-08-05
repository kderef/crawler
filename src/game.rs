use crate::font;
use font::{Fonts, load_pixel_font};

pub struct Game {}

impl Game {
    pub async fn init() -> anyhow::Result<Self> {
        // setup fonts
        let bbt_plus = load_pixel_font("bbt/BigBlue_TerminalPlus.ttf").await?;

        font::FONTS.get_or_init(move || Fonts { bbt_plus });
        todo!()
    }
}

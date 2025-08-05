#[cfg_attr(not(debug_assertions), windows_subsystem = "windows")]
mod font;
mod game;

use font::*;
use game::Game;

use macroquad::prelude::*;

fn app() -> Conf {
    Conf {
        window_title: "crawler".into(),
        sample_count: 4,
        ..Default::default()
    }
}

fn base_font_size() -> u16 {
    let sw = screen_width();
    let size = sw * 0.03;
    size as u16
}

fn draw_title_text(text: &str, size: u16, color: Color) {
    let center_x = screen_width() / 2.;
    let center_y = screen_height() / 2.;

    let font = fonts().main();
    let font_scale = 1.;

    let text_dims = measure_text(text, Some(font), size, font_scale);

    let title_x = center_x - text_dims.width / 2.;
    let title_y = center_y;

    custom_text("CRAWLER", title_x, title_y, size, color);
}

#[macroquad::main(app)]
async fn main() -> anyhow::Result<()> {
    set_pc_assets_folder("assets");

    let mut game = Game::init().await?;

    // setup fonts
    let bbt_plus = load_pixel_font("bbt/BigBlue_TerminalPlus.ttf").await?;

    font::FONTS.get_or_init(move || Fonts { bbt_plus });

    let mut border;

    loop {
        let (screen_w, screen_h) = (screen_width(), screen_height());
        let base_fsize = base_font_size() as f32;
        let title_size = base_fsize * 3.;

        border = "#".repeat((screen_w / base_fsize * 2.) as usize);

        // border top
        custom_text(&border, 0., base_fsize, base_fsize as u16, GRAY);
        draw_title_text("CRAWLER", title_size as u16, RED);

        // border bottom
        custom_text(
            &border,
            0.,
            screen_h - base_font_size() as f32 / 2.,
            base_font_size(),
            GRAY,
        );

        draw_fps();
        next_frame().await;
    }
}

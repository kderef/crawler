#[cfg_attr(not(debug_assertions), windows_subsystem = "windows")]
mod font;
mod game;
mod log;

use font::*;
use game::Game;

use macroquad::prelude::*;

pub const ASSETS_FOLDER: &str = "assets";

fn app() -> Conf {
    Conf {
        window_title: "crawler".into(),
        sample_count: 4,
        ..Default::default()
    }
}

fn draw_title_text(game: &Game, text: &str, size: u16, color: Color) {
    let center_x = screen_width() / 2.;
    let center_y = screen_height() / 2.;

    let font = game.fonts.main();
    let font_scale = 1.;

    let text_dims = measure_text(text, Some(font), size, font_scale);

    let title_x = center_x - text_dims.width / 2.;
    let title_y = center_y;

    game.custom_text("CRAWLER", title_x, title_y, size, color);

    game.custom_text("1 - play test", title_x, y, fs, color)
}

#[macroquad::main(app)]
async fn main() -> anyhow::Result<()> {
    set_pc_assets_folder(ASSETS_FOLDER);

    let mut game = Game::init().await?;

    let mut border;

    loop {
        let (screen_w, screen_h) = (screen_width(), screen_height());
        let base_fsize = game.base_font_size() as f32;
        let title_size = base_fsize * 3.;

        border = "#".repeat((screen_w / base_fsize * 2.) as usize);

        // border top
        game.custom_text(&border, 0., base_fsize, base_fsize as u16, GRAY);
        draw_title_text(&game, "CRAWLER", title_size as u16, RED);

        // border bottom
        game.custom_text(
            &border,
            0.,
            screen_h - base_fsize as f32 / 2.,
            base_fsize as u16,
            GRAY,
        );

        draw_fps();
        next_frame().await;
    }
}

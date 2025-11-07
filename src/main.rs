mod terminal;

use macroquad::prelude::*;

/*
- implement Terminal struct
*/

fn conf() -> Conf {
    Conf {
        window_title: "crawler".into(),
        window_resizable: true,
        high_dpi: true,
        sample_count: 2,

        ..Default::default()
    }
}

#[macroquad::main(conf)]
async fn main() {
    loop {
        draw_text("hallo!", 50., 50., 30., WHITE);
        next_frame().await;
    }
}

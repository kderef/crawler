#[cfg_attr(not(debug_assertions), windows_subsystem = "windows")]
use macroquad::prelude::*;

fn app() -> Conf {
    Conf {
        window_title: "crawler".into(),
        ..Default::default()
    }
}

#[macroquad::main(app)]
async fn main() {
    println!("Hello, world!");

    let show_fps = true;

    loop {
        if show_fps {
            draw_fps();
        }
        next_frame().await;
    }
}

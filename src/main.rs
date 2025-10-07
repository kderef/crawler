mod draw;
mod menu;
mod scene;

use std::fs;

use macroquad::prelude::*;
use macroquad::ui;

use crate::{
    draw::get_font,
    menu::Menu,
    scene::{Scene, SceneChange},
};

fn conf() -> Conf {
    Conf {
        window_title: "crawler".into(),
        window_width: 800,
        window_height: 600,
        window_resizable: true,

        high_dpi: true,
        fullscreen: false,
        sample_count: 2,
        icon: None,
        platform: Default::default(),
    }
}

async fn panic_handler(msg: String, backtrace: String) {
    // TODO: proper crash handling
    // report crash
    eprintln!("CRASHED!");

    let report = format!("message: {msg}\n*** backtrace ***\n{backtrace}");

    eprintln!("{report}");

    // save crash to file
    let report = format!("message: {msg}\n");

    if let Err(e) = fs::write("crash.txt", &report) {
        eprintln!("failed to write to file: {e}");
    }

    let bt_lines: Vec<&str> = backtrace.split('\n').collect();

    loop {
        clear_background(RED);
        ui::root_ui().label(None, &msg);
        for line in &bt_lines {
            ui::root_ui().label(None, line);
        }
        next_frame().await;
    }
}

#[macroquad::main(conf)]
async fn main() {
    // asset loading
    let _load_font = get_font(); // load font
    set_panic_handler(panic_handler);

    // scene setup
    let mut scene_menu = Menu::new();

    let mut scenes: Vec<Box<dyn Scene>> = Vec::with_capacity(10);
    scenes.push(Box::new(scene_menu));

    loop {
        if is_key_pressed(KeyCode::Enter) {
            panic!("oh no");
        }

        // only handle input for the top-most scene
        if let Some(last) = scenes.last_mut() {
            last.handle_input();
        }

        let mut scene_change = None;

        // update and draw
        for scene in &mut scenes {
            if let Some(change) = scene.update() {
                scene_change = Some(change);
                break;
            }
            scene.draw();
        }

        // transition maybe
        if let Some(change) = scene_change {
            match change {
                SceneChange::Pop => {
                    scenes.pop();
                }
                SceneChange::Push(scene) => {
                    scenes.push(scene);
                }
                SceneChange::Quit => break,
            }
        }

        next_frame().await;
    }
}

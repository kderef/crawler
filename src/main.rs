#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

mod camera;

use macroquad::{miniquad::conf::Platform, prelude::*};

use crate::camera::CameraController;

fn conf() -> Conf {
    Conf {
        window_title: "crawler".into(),
        window_resizable: true,

        window_width: 800,
        window_height: 600,

        high_dpi: true,
        sample_count: 4,
        ..Default::default()
    }
}

#[macroquad::main(conf)]
async fn main() {
    let mut camera = CameraController::new();
    camera.set_active(true);
    camera.set_fov(70.0);
    camera.set_free(true);

    loop {
        clear_background(BLACK);

        camera.update();
        camera.movement();
        camera.look();

        set_camera(&camera);
        {
            draw_grid(1000, 20.0, GRAY, WHITE);
            draw_cube(vec3(-20., 3., 3.), vec3(2., 10., 2.), None, RED);
        }
        set_default_camera();

        draw_text("h1llo!", 50., 50., 30., WHITE);
        draw_fps();
        next_frame().await;
    }
}

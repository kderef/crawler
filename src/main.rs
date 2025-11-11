#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

mod camera;
mod player;
mod scene;

use macroquad::{miniquad::conf::Platform, prelude::*};

use crate::{camera::CameraController, player::Player, scene::test_scene};

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
    let mut player = Player::new();

    player.camera.set_active(true);
    player.camera.set_fov(70.0);
    player.camera.set_sensitivity(40.0);

    let mut scene = test_scene();

    loop {
        clear_background(BLACK);

        player.update_movement();
        player.update_camera();

        set_camera(&player.camera);
        {
            draw_grid(1000, 20.0, GRAY, WHITE);
            draw_cube(vec3(-20., 3., 3.), vec3(2., 10., 2.), None, RED);
            scene.draw();
        }
        set_default_camera();

        draw_text("h1llo!", 50., 50., 30., WHITE);
        draw_fps();
        next_frame().await;
    }
}

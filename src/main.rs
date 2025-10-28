use macroquad::prelude::*;

use crate::camera::CameraController;

mod camera;

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
    let mut camera = CameraController::new();
    let mut cam_active = true;

    camera.set_active(cam_active);

    loop {
        if is_key_pressed(KeyCode::Tab) {
            cam_active ^= true;
            camera.set_active(cam_active);
        }

        camera.look();

        set_camera(&camera);
        {
            draw_cube_wires(vec3(10., 10., 10.), vec3(10., 10., 10.), RED);
        }
        set_default_camera();

        draw_text("hello!", 50., 50., 30., WHITE);
        next_frame().await;
    }
}

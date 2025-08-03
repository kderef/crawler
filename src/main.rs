#[cfg_attr(not(debug_assertions), windows_subsystem = "windows")]
use macroquad::prelude::*;

fn app() -> Conf {
    Conf {
        window_title: "crawler".into(),
        window_width: 800,
        window_height: 600,
        window_resizable: true,

        high_dpi: false,
        sample_count: 4,

        icon: None,

        ..Default::default()
    }
}

#[macroquad::main(app)]
async fn main() {
    let show_fps = true;

    let mut pos = vec2(0., 0.);

    let camera = || Camera2D {
        rotation: 0.0,
        zoom: vec2(1., 1.),
        target: pos,
        offset: vec2(0.0, 0.0),

        render_target: None,
        viewport: None,
    };

    loop {
        set_camera(&camera());

        draw_rectangle(pos.x, pos.y, 50.0, 25.0, WHITE);

        set_default_camera();

        if show_fps {
            draw_fps();
        }
        next_frame().await;
    }
}

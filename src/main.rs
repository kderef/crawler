#[cfg_attr(not(debug_assertions), windows_subsystem = "windows")]
use macroquad::prelude::*;

fn app() -> Conf {
    Conf {
        window_title: "crawler".into(),
        sample_count: 4,
        ..Default::default()
    }
}

#[macroquad::main(app)]
async fn main() -> anyhow::Result<()> {
    set_pc_assets_folder("assets");
    let mut font = load_ttf_font("hack/bold.ttf").await?;
    // font.set_filter(FilterMode::Nearest);

    loop {
        draw_text_ex(
            "# . . # . . # @ @ %",
            10.,
            20.,
            TextParams {
                font: Some(&font),
                font_size: 20,
                font_scale: 1.,
                font_scale_aspect: 1.,
                rotation: 0.,
                color: WHITE,
            },
        );
        draw_text("# . 1 # 2 z 8 k @", 10., 30., 20., WHITE);

        next_frame().await;
    }
}

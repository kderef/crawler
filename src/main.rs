use rl::{color::Color, drawing::RaylibDraw};

fn main() {
    println!("Hello, world!");

    let (mut rl, thread) = rl::init()
        .title("Hello world!")
        .size(600, 400)
        .vsync()
        .resizable()
        .build();

    // update window or size is fucked up
    rl.set_window_size(800, 600);

    while !rl.window_should_close() {
        let mut dr = rl.begin_drawing(&thread);

        dr.clear_background(Color::BLACK);

        dr.draw_line(
            0,
            0,
            dr.get_screen_width(),
            dr.get_screen_height(),
            Color::GREEN,
        );
    }
}

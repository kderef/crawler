#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

use sdl2::event::{Event, WindowEvent};
use sdl2::keyboard::Keycode;
use sdl2::messagebox::{MessageBoxFlag, show_simple_message_box};
use sdl2::pixels::Color;
use sdl2::render::WindowCanvas;
use sdl2::{Sdl, VideoSubsystem};
use std::time::Duration;

pub struct App {
    sdl: Sdl,
    video: VideoSubsystem,
    canvas: WindowCanvas,
    display: i32,
    /// (ddpi, hdpi, vdpi)
    dpi: (f32, f32, f32),
}

fn main() {
    let sdl = sdl2::init().unwrap();
    let video = sdl.video().unwrap();
    let mut window = video
        .window("crawler", 800, 600)
        .position_centered()
        .resizable()
        .opengl()
        .allow_highdpi()
        .build()
        .unwrap();

    window.raise();

    let display = window.display_index().unwrap_or(0);
    let canvas = window.into_canvas().build().unwrap();
    let dpi = video.display_dpi(display).unwrap();

    let mut app = App {
        sdl,
        video,
        canvas,
        display,
        dpi,
    };

    if let Err(e) = run(&mut app) {
        let flags = MessageBoxFlag::ERROR;
        let title = "ERROR";
        let message = &e;
        show_simple_message_box(flags, title, message, app.canvas.window()).unwrap();
    }
}

pub fn run(app: &mut App) -> Result<(), String> {
    let App {
        canvas,
        sdl,
        video,
        display,
        dpi,
    } = app;

    canvas.set_draw_color(Color::RGB(255, 0, 0));
    canvas.clear();
    canvas.present();

    let (w, h) = canvas.output_size()?;
    let (mut w, mut h) = (w as i32, h as i32);

    let mut event_pump = sdl.event_pump()?;

    'running: loop {
        for event in event_pump.poll_iter() {
            match event {
                Event::Window {
                    timestamp: _,
                    window_id: _,
                    win_event,
                } => match win_event {
                    WindowEvent::SizeChanged(nw, nh) | WindowEvent::Resized(nw, nh) => {
                        w = (nw as f32 * dpi.1) as i32;
                        h = (nh as f32 * dpi.2) as i32;
                    }
                    WindowEvent::DisplayChanged(_) => {}
                    _ => {}
                },
                Event::Quit { .. }
                | Event::KeyDown {
                    keycode: Some(Keycode::Escape),
                    ..
                } => break 'running,
                _ => {}
            }
        }

        canvas.set_draw_color(Color::RGB(255, 0, 0));
        canvas.clear();

        canvas.set_draw_color(Color::WHITE);
        canvas.draw_line((0, 0), (w as i32, h as i32));

        canvas.present();
        std::thread::sleep(Duration::new(0, 1_000_000_000u32 / 30));
        // The rest of the game loop goes here...
    }

    Ok(())
}

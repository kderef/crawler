use macroquad::prelude::*;

use crate::{camera::CameraController, scene::HitBox};

pub struct Player {
    pub camera: CameraController,
    size: Vec3,
    freecam: bool,
}

impl Player {
    pub fn new() -> Self {
        let camera = CameraController::new();
        Self {
            camera,
            size: vec3(0.3, 2.0, 0.3),
            freecam: cfg!(debug_assertions),
        }
    }

    pub fn toggle_freecam(&mut self) {
        self.freecam = !self.freecam;
    }

    pub fn set_freecam(&mut self, enable: bool) {
        self.freecam = enable;
    }

    pub fn update_camera(&mut self) {
        self.camera.update();
        self.camera.look();
    }

    pub fn position(&self) -> Vec3 {
        self.camera.position()
    }

    fn freecam_movement(&mut self) {
        let dt = get_frame_time();
        let speed = dt * 10.0;

        let front = self.camera.front;
        let right = self.camera.right;
        let position = self.camera.position_mut();

        if is_key_down(KeyCode::W) {
            *position += front * speed;
        }
        if is_key_down(KeyCode::A) {
            *position -= right * speed;
        }
        if is_key_down(KeyCode::S) {
            *position -= front * speed;
        }
        if is_key_down(KeyCode::D) {
            *position += right * speed;
        }

        if is_key_down(KeyCode::Space) {
            position.y += speed;
        }
        if is_key_down(KeyCode::LeftShift) {
            position.y -= speed;
        }
    }

    pub fn grounded_movement(&mut self) {
        todo!()
    }

    pub fn update_movement(&mut self) {
        //
        if self.freecam {
            self.freecam_movement();
        } else {
            self.grounded_movement();
        }
    }

    pub fn hitbox(&self) -> HitBox {
        let pos = self.camera.position();

        let corner = pos - self.size / 2.0;

        HitBox {
            pos: corner,
            size: self.size,
        }
    }
}

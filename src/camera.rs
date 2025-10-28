use macroquad::{miniquad::native::apple::apple_util::load_mouse_cursor, prelude::*};

#[derive(Default)]
pub struct CameraController {
    active: bool,
    camera: Camera3D,
    sensitivity: f32,

    yaw: f32,
    pitch: f32,
    world_up: Vec3,
}

impl CameraController {
    pub fn set_active(&mut self, active: bool) {
        if active == self.active {
            return;
        }

        set_cursor_grab(active);
        show_mouse(!active);

        self.active = active;
    }

    pub fn new() -> Self {
        Self {
            active: false,
            sensitivity: 100.,
            world_up: vec3(0., 1., 0.),
            yaw: 1.18,
            pitch: 0.,

            camera: Camera3D {
                position: vec3(0., 1., 0.),
                target: vec3(0., 0., 0.),
                up: vec3(0., 1., 0.),
                aspect: None,
                projection: Projection::Perspective,
                render_target: None,
                viewport: None,
                ..Default::default()
            },
            ..Default::default()
        }
    }

    pub fn look(&mut self) {
        if !self.active {
            return;
        }

        let dt = get_frame_time();
        let mouse_delta = mouse_delta_position();

        // no movement was made
        if mouse_delta == Vec2::ZERO {
            return;
        }

        let sens = dt * self.sensitivity;

        self.yaw -= mouse_delta.x * sens;
        self.pitch -= mouse_delta.y * -sens;
        self.pitch = self.pitch.clamp(-1.5, 1.5);

        let front = vec3(
            self.yaw.cos() * self.pitch.cos(),
            self.pitch.sin(),
            self.yaw.sin() * self.pitch.cos(),
        )
        .normalize();

        let right = front.cross(self.world_up).normalize();
        // self.camera.up = right.cross(front).normalize();

        self.camera.target = self.camera.position + front;
    }
}

impl Camera for CameraController {
    fn matrix(&self) -> Mat4 {
        self.camera.matrix()
    }
    fn depth_enabled(&self) -> bool {
        self.camera.depth_enabled()
    }
    fn render_pass(&self) -> Option<RenderPass> {
        self.camera.render_pass()
    }
    fn viewport(&self) -> Option<(i32, i32, i32, i32)> {
        self.camera.viewport
    }
}

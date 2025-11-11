use macroquad::prelude::*;

#[derive(Default, Debug, Clone, Copy)]
pub struct HitBox {
    pub pos: Vec3,
    pub size: Vec3,
}

pub enum Fill {
    None,
    Texture(Texture2D),
    Color(Color),
}

pub enum Object {
    Plane { pos: Vec3, size: Vec2 },
    Cube { pos: Vec3, size: Vec3, fill: Fill },
}

impl Object {
    pub fn draw(&self) {
        match self {
            Self::Plane { pos, size } => {
                let texture = None;
                let begin = vec3(pos.x - size.x / 2., pos.y, pos.z - size.y / 2.);
                draw_plane(begin, *size, texture, LIGHTGRAY);
            }
            Self::Cube { pos, size, fill } => match fill {
                Fill::None => {
                    draw_cube_wires(*pos, *size, PURPLE);
                }
                Fill::Texture(t) => {
                    todo!()
                }
                Fill::Color(c) => {
                    draw_cube(*pos, *size, None, *c);
                }
            },
        }
    }
}

pub struct Scene {
    spawn_point: Vec3,
    objects: Vec<Object>,
}

impl Scene {
    pub fn draw(&self) {
        for tile in &self.objects {
            tile.draw();
        }
    }
}

pub fn test_scene() -> Scene {
    let mut s = Scene {
        spawn_point: vec3(10.0, 0.0, 10.0),
        objects: vec![],
    };

    s.objects = vec![
        // test
        Object::Plane {
            pos: vec3(5.0, 0.0, 5.0),
            size: vec2(20.0, 10.0),
        },
        Object::Cube {
            pos: vec3(2.0, 1.0, 2.0),
            size: vec3(1.0, 0.5, 4.0),
            fill: Fill::Color(RED),
        },
    ];

    s
}

pub enum SceneChange {
    Push(Box<dyn Scene>),
    Pop,
    Quit,
}

pub trait Scene {
    fn handle_input(&mut self);
    fn update(&mut self) -> Option<SceneChange>;
    fn draw(&self);
}

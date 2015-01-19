#[derive(Copy)]
pub struct Point
{
    pub x:  isize,
    pub y:  isize,
}

#[derive(Copy)]
pub struct Player
{
    pub coordinate: Point,
    pub direction:  f64,
    pub fov:  f64,
}

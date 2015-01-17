pub struct Point
{
    pub x:  isize,
    pub y:  isize,
}

pub struct Player
{
    pub coordinate: Point,
    pub direction:  f64,
    pub fov:  f64,
}

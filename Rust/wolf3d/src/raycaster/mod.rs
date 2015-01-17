extern crate std;

use std::f64::consts::{PI, PI_2, FRAC_PI_2};
use std::num::Float;
use std::num::Int;

pub use self::player::*;

pub mod player;

fn raycast(width: f64, player: Player, map: Vec<Vec<u8>>)
{
    let mut start = player.direction - (player.fov / 2f64);
    let step = (player.fov / width);

    for _ in range(0, width as u64)
    {
        // cast
        // trace
        // distance
        start += step;
    }
}

fn cast(player: Player, pos: Point, step: Point, map: Vec<Vec<u8>>) -> usize
{
    if check(pos.x / 64, pos.y / 64, &map)
    {
        (((player.coordinate.x - pos.x).pow(2) + (player.coordinate.y - pos.y).pow(2)) as f64).sqrt() as usize
    }
    else
    {
        cast(player, Point{x: pos.x + step.x, y: pos.y + step.y}, step, map)
    }
}

fn vertical_cast(player: Player, map: Vec<Vec<u8>>) -> Option<usize>
{
    let (a_x, xstep) = if FRAC_PI_2 < player.direction && player.direction < PI + FRAC_PI_2
    {
        (Some((player.coordinate.x / 64) * 64 - 1), -64)
    }
    else if (0f64 < player.direction && player.direction < FRAC_PI_2)
        || (PI + FRAC_PI_2 < player.direction && player.direction < PI_2)
    {
        (Some((player.coordinate.x / 64) * 64 + 64), 64)
    }
    else
    {
        (None, 0)
    };
    if a_x == None
    {
        return None
    }
    let a_y = player.coordinate.y + ((player.coordinate.x - a_x.unwrap()) as f64 / player.direction.tan()) as isize;
    let ystep = (64f64 * player.direction.tan()) as isize;
    Some(cast(player, Point{x: a_x.unwrap(), y: a_y}, Point{x: xstep, y: ystep}, map))
}

pub fn horizontal_cast(player: Player, map: Vec<Vec<u8>>) -> Option<usize>
{
    let (a_y, ystep) = if 0f64 <= player.direction && player.direction < PI
    {
        (Some((player.coordinate.y / 64) * 64 - 1), -64)
    }
    else if PI < player.direction && player.direction < PI_2
    {
        (Some((player.coordinate.y / 64) * 64 + 64), 64)
    }
    else
    {
        (None, 0)
    };
    if a_y == None
    {
        return None
    }
    let a_x = player.coordinate.x + ((player.coordinate.y - a_y.unwrap()) as f64 / player.direction.tan()) as isize;
    let xstep = (64f64 / player.direction.tan()) as isize;
    Some(cast(player, Point{x: a_x, y: a_y.unwrap()}, Point{x: xstep, y: ystep}, map))
}

fn check(col: isize, row: isize, map: &Vec<Vec<u8>>) -> bool
{
    map[row as usize][col as usize] != 0
}

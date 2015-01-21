extern crate std;
extern crate sdl2;

use sdl2::pixels::Color;
use sdl2::render::Renderer;
use sdl2::rect::Point as SDL_Point;

use std::f64::consts::{PI, PI_2, FRAC_PI_2};
use std::num::Float;
use std::num::Int;

pub use self::player::*;

pub mod player;

pub fn raycast(renderer: &Renderer, player: &Player, map: &Vec<Vec<u8>>, width: f64, height: f64)
{
    let _ = renderer.set_draw_color(Color::RGB(0, 0, 0));
    let _ = renderer.clear();
    let mut current_direction = player.direction - (player.fov / 2f64);
    let step = (player.fov / width);

    for column in range(0, width as i32)
    {
        current_direction += PI_2;
        current_direction = current_direction % PI_2;
        let distance = match (horizontal_cast(Player{coordinate: Point{x: player.coordinate.x, y: player.coordinate.y}, direction: current_direction, fov: player.fov}, map),
        vertical_cast(Player{coordinate: Point{x: player.coordinate.x, y: player.coordinate.y}, direction: current_direction, fov: player.fov}, map))
        {
            (None, Some(d))     => d,
            (Some(d), None)     => d,
            (Some(a), Some(b))  => if a < b {a} else {b},
            (None, None)        => 0
        };
        //println!("distance: {}", distance);
        let correct_distance = distance as f64 * (player.direction - current_direction).cos();
        //println!("correct_distance: {}", correct_distance);
        let slice_height = (64f64 / correct_distance * ((width / 2f64) / (player.fov / 2f64).tan())) as usize;
        println!("================slice_height: {}", slice_height);
        let top = SDL_Point{x: column, y: (height as i32 / 2i32) - (slice_height as i32 / 2i32)};
        let bot = SDL_Point{x: column, y: top.y + slice_height as i32};
        let _ = renderer.set_draw_color(Color::RGB(0, 0, 240));
        renderer.draw_line(top, bot);
        current_direction += step;
    }
    println!("-------------------------------------------------------------------------------------");
    renderer.present();
}

fn cast(player: Player, pos: Point, step: Point, map: &Vec<Vec<u8>>) -> usize
{
    if check(pos.x / 64, pos.y / 64, map)
    {
        (((player.coordinate.x - pos.x).pow(2) + (player.coordinate.y - pos.y).pow(2)) as f64).sqrt() as usize
    }
    else
    {
        cast(player, Point{x: pos.x + step.x, y: pos.y + step.y}, step, map)
    }
}

fn vertical_cast(player: Player, map: &Vec<Vec<u8>>) -> Option<usize>
{
    let (a_x, xstep) = if FRAC_PI_2 < player.direction && player.direction < PI + FRAC_PI_2
    {
        (Some((player.coordinate.x / 64) * 64 - 1), -64)
    }
    else if (0f64 <= player.direction && player.direction < FRAC_PI_2)
        || (PI + FRAC_PI_2 < player.direction && player.direction <= PI_2)
    {
        (Some((player.coordinate.x / 64) * 64 + 64), 64)
    }
    else
    {
        (None, 0)
    };
    if a_x == None
    {
        return None;
    }
    let a_y = player.coordinate.y + ((player.coordinate.x - a_x.unwrap()) as f64 * player.direction.tan()) as isize;
    let ystep = (64f64 * player.direction.tan()) as isize;
    Some(cast(player, Point{x: a_x.unwrap(), y: a_y}, Point{x: xstep, y: ystep}, map))
}

pub fn horizontal_cast(player: Player, map: &Vec<Vec<u8>>) -> Option<usize>
{
    let (a_y, ystep) = if 0f64 < player.direction && player.direction < PI
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
        return None;
    }
    let a_x = player.coordinate.x + ((player.coordinate.y - a_y.unwrap()) as f64 / player.direction.tan()) as isize;
    let xstep = (64f64 / player.direction.tan()) as isize;
    Some(cast(player, Point{x: a_x, y: a_y.unwrap()}, Point{x: xstep, y: ystep}, map))
}

fn check(col: isize, row: isize, map: &Vec<Vec<u8>>) -> bool
{
    if col < 0 || row < 0 || col as usize >= map.len() || row as usize >= map[0].len()
    {
        true
    }
    else
    {
        map[row as usize][col as usize] != 0
    }
}

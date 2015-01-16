extern crate sdl2;

use sdl2::video::{Window, WindowPos, OPENGL};
use sdl2::render::{RenderDriverIndex, ACCELERATED, Renderer};
use sdl2::pixels::Color;
use sdl2::event::poll_event;
use sdl2::event::Event::{Quit, KeyDown};
use sdl2::keycode::KeyCode;

use std::num::Float;
fn main()
{
    sdl2::init(sdl2::INIT_VIDEO);
    let window = match Window::new("Wolf3D", WindowPos::PosCentered,
                                   WindowPos::PosCentered, 800, 600, OPENGL)
    {
        Ok(window) => window,
        Err(err) => panic!("failed to create window: {}", err)
    };
    let renderer = match Renderer::from_window(window, RenderDriverIndex::Auto, ACCELERATED)
    {
        Ok(renderer) => renderer,
        Err(err) => panic!("failed to create renderer: {}", err)
    };
    let _ = renderer.set_draw_color(Color::RGB(255, 0, 0));
    let _ = renderer.clear();
    renderer.present();

    let x: u64 = 0;
    let y: u64 = 0;
    let r = 0f64;
    let width = 320f64;
    let height = 200f64;
    let fov = 60f64;
    let plane_center = (width / 2f64, height / 2f64);
    let d  = (width / 2f64) / (fov / 2f64).to_radians().tan();
    let step = (fov / width).to_radians();
    let map = vec![vec![1u8, 1, 1, 1], vec![1, 0, 0, 1], vec![1, 0, 0, 1], vec![1, 1, 1, 1]];
    println!("{:?}", cast(fov, (96, 224), map));
    loop
    {
        match poll_event()
        {
            Quit(_) => break,
            KeyDown(_, _, key, _, _, _) =>
            {
                if key == KeyCode::Escape {break;}
            }
            _ => {}
        }
    }
    sdl2::quit();
}

fn raycast(step: f64, width: f64, fov: f64, r: f64)
{
    let mut start = r - (fov / 2f64);

    for _ in range(0, width as u64)
    {
        // cast
        // trace
        // distance
        start += step;
    }
}

fn cast(angle: f64, pos: (u64, u64), map: Vec<Vec<u8>>) -> (u64, u64)
{
    let (x, y) = pos;
    let r = angle.to_radians().tan();
    let (a_y, ya) = if 0f64 <= angle && angle < 180f64
    {
        ((y / 64) * 64 - 1, -64)
    }
    else
    {
        ((y / 64) * 64 + 64, 64)
    };
    let a_x = x + ((y - a_y) as f64 / angle.to_radians().tan()) as u64;
    let xa = (64f64 / r) as u64;
    println!("{}", check(a_x / 64, a_y / 64, map));
    (a_x, a_y)
}

fn check(col: u64, row: u64, map: Vec<Vec<u8>>) -> bool
{
    map[row as usize][col as usize] != 0
}

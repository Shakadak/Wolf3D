extern crate sdl2;

use sdl2::video::{Window, WindowPos, OPENGL};
use sdl2::render::{RenderDriverIndex, ACCELERATED, Renderer};
use sdl2::pixels::Color;
use sdl2::event::poll_event;
use sdl2::event::Event::{Quit, KeyDown};
use sdl2::keycode::KeyCode;

use std::num::Float;

use raycaster::*;

pub mod raycaster;

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

    let player = player::Player{coordinate: player::Point{x: 96, y: 224}, direction: 60f64.to_radians(), fov: 60f64.to_radians()};
    let width = 320f64;
    let height = 200f64;
    let plane_center = (width / 2f64, height / 2f64);
    let d  = (width / 2f64) / (player.fov / 2f64).tan();
    let map = vec![vec![1u8, 1, 1, 1], vec![1, 0, 0, 1], vec![1, 0, 0, 1], vec![1, 1, 1, 1]];
    horizontal_cast(player, map);
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

extern crate sdl2;

use sdl2::video::{Window, WindowPos, OPENGL};
use sdl2::render::{RenderDriverIndex, ACCELERATED, Renderer};
use sdl2::event::poll_event;
use sdl2::event::Event::{Quit, KeyDown};
use sdl2::keycode::KeyCode;

use std::num::Float;
use std::f64::consts::{FRAC_PI_4, PI_2};

use raycaster::*;

pub mod raycaster;

fn main()
{
    sdl2::init(sdl2::INIT_VIDEO);
    let window = match Window::new("Wolf3D", WindowPos::PosCentered,
                                   WindowPos::PosCentered, 1366, 768, OPENGL)
    {
        Ok(window) => window,
        Err(err) => panic!("failed to create window: {}", err)
    };
    let renderer = match Renderer::from_window(window, RenderDriverIndex::Auto, ACCELERATED)
    {
        Ok(renderer) => renderer,
        Err(err) => panic!("failed to create renderer: {}", err)
    };

    let mut player = player::Player{coordinate: player::Point{x: 3 * 64 + 32, y: 3 * 64 + 32}, direction: 90f64.to_radians(), fov: 60f64.to_radians()};
    let width = 1366f64;
    let height = 768f64;
    let plane_center = (width / 2f64, height / 2f64);
    let d  = (width / 2f64) / (player.fov / 2f64).tan();
    let map = vec![
        vec![1u8, 1, 1, 1, 1, 1, 1],
        vec![1, 0, 0, 0, 0, 0, 1],
        vec![1, 0, 0, 0, 0, 0, 1],
        vec![1, 0, 0, 0, 0, 0, 1],
        vec![1, 0, 0, 0, 0, 0, 1],
        vec![1, 1, 0, 1, 0, 1, 1],
        vec![1, 1, 1, 1, 1, 1, 1]];
    loop
    {
        match poll_event()
        {
            Quit(_) => break,
            KeyDown(_, _, key, _, _, _) =>
            {
                match key
                {
                    KeyCode::Escape => break,
                    KeyCode::Left   => player.direction = (PI_2 - FRAC_PI_4 + player.direction) % PI_2,
                    KeyCode::Right  => player.direction = (PI_2 + FRAC_PI_4 + player.direction) % PI_2,
                    _               => {}
                }
            }
            _ => {}
        }
        raycast(&renderer, &player, &map, width, height);
    }
    sdl2::quit();
}

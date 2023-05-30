/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

// #define MASTER_LEFT
#define MASTER_RIGHT
// #define EE_HANDS

#define OLED_TIMEOUT 15000
#define TAPPING_FORCE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

#undef TAPPING_TERM
#define TAPPING_TERM 130
#undef RGB_MATRIX_MAXIMUM_BRIGHTNESS 
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100
// #define RGB_MATRIX_KEYPRESSES 
// #define RGB_MATRIX_KEYRELEASES 
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// standard effects
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN	 // Static gradient top to bottom, speed controls how much gradient changes
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS // Randomly changes a single key's hue and saturation
#define ENABLE_RGB_MATRIX_CYCLE_ALL // Full keyboard solid hue cycling through full gradient
#define ENABLE_RGB_MATRIX_PIXEL_RAIN  // Randomly light keys with random hues
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON // Full gradent Chevron shapped scrolling left to right
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP // How hot is your WPM

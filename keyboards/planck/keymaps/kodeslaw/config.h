/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

/*
 * Configure RGB light
 */

#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CUSTOM_limited_breathing
#define LIMITED_BREATHING_MIN_VALUE (192)

#define RGB_MATRIX_STARTUP_HUE 20                       // Sets the default hue value, if none has been set
#define RGB_MATRIX_STARTUP_SAT 239                      // Sets the default saturation value, if none has been set
#define RGB_MATRIX_STARTUP_VAL 143                      // Sets the default brightness value, if none has been set


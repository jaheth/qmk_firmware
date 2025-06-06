/* Copyright 2020 RGBKB
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

#include "quantum.h"
#include "rgb_matrix_types.h"

#if defined RGB_MATRIX_ENABLE
#    if defined(KEYBOARD_rgbkb_pan_rev1)
#        include "ws2812.h"

// Set an led in the buffer to a color
static inline void setled(int i, uint8_t r, uint8_t g, uint8_t b) {
#        if defined(RGB_ENCODERS) || defined(STAGGERED_RGB_ENCODERS)
    if (i == 0 || i == 1) {  // if encoder LEDs, change LEDs
        ws2812_set_color(i, g, b, r);
    } else
#        endif
    {
        ws2812_set_color(i, r, g, b);
    }
}

const rgb_matrix_driver_t rgb_matrix_driver = {
    .init          = ws2812_init,
    .flush         = ws2812_flush,
    .set_color     = setled,
    .set_color_all = ws2812_set_color_all,
};
#    endif

// clang-format off
    led_config_t g_led_config = { {
       { 2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14 },
       { 0, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15 },
       { 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 1 },
       { 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40 },
       { 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, NO_LED  }
    }, {
#    ifdef STAGGERED_RGB_ENCODERS
        {0, -19},{228, -19},
        {0, 0}, {14, 0}, {33, 0}, {52, 0}, {71, 0}, {90, 0}, {109, 0}, {128, 0}, {147, 0}, {166, 0}, {185, 0}, {204, 0}, {223, 0},
        {209, 19}, {190, 19}, {171, 19}, {152, 19}, {133, 19}, {114, 19}, {95, 19}, {76, 19}, {57, 19}, {38, 19}, {19, 19}, {0, 19},
        {0, 38}, {19, 38}, {38, 38}, {57, 38}, {76, 38}, {95, 38}, {114, 38}, {133, 38}, {152, 38}, {171, 38}, {190, 38}, {209, 38},
        {223, 57}, {204, 57}, {185, 57}, {171, 57}, {147, 57}, {128, 57}, {109, 57}, {90, 57}, {71, 57}, {52, 57}, {33, 57}, {14, 57}, {0, 57},
        {0, 76}, {19, 76}, {38, 76}, {57, 76}, {76, 76}, {95, 76}, {114, 76}, {133, 76}, {152, 76}, {171, 76}, {190, 76}, {209, 76},
#    elif defined RGB_ENCODERS
        {0, -19},{228, -19},
        {0, 0}, {19, 0}, {38, 0}, {57, 0}, {76, 0}, {95, 0}, {114, 0}, {133, 0}, {152, 0}, {171, 0}, {190, 0}, {209, 0},
        {209, 19}, {190, 19}, {171, 19}, {152, 19}, {133, 19}, {114, 19}, {95, 19}, {76, 19}, {57, 19}, {38, 19}, {19, 19}, {0, 19},
        {0, 38}, {19, 38}, {38, 38}, {57, 38}, {76, 38}, {95, 38}, {114, 38}, {133, 38}, {152, 38}, {171, 38}, {190, 38}, {209, 38},
        {209, 57}, {190, 57}, {171, 57}, {152, 57}, {133, 57}, {114, 57}, {95, 57}, {76, 57}, {57, 57}, {38, 57}, {19, 57}, {0, 57},
        {0, 76}, {19, 76}, {38, 76}, {57, 76}, {76, 76}, {95, 76}, {114, 76}, {133, 76}, {152, 76}, {171, 76}, {190, 76}, {209, 76},
        {0, 95},{19, 95}, //not used
#    elif defined STAGGERED_LAYOUT
        {0, 0}, {19, 0}, {38, 0}, {57, 0}, {76, 0}, {95, 0}, {114, 0}, {133, 0}, {152, 0}, {171, 0}, {190, 0}, {209, 0}, {0, 0},
        {209, 19}, {190, 19}, {171, 19}, {152, 19}, {133, 19}, {114, 19}, {95, 19}, {76, 19}, {57, 19}, {38, 19}, {19, 19}, {0, 19},
        {0, 38}, {19, 38}, {38, 38}, {57, 38}, {76, 38}, {95, 38}, {114, 38}, {133, 38}, {152, 38}, {171, 38}, {190, 38}, {209, 38},
        {209, 57}, {190, 57}, {171, 57}, {152, 57}, {133, 57}, {114, 57}, {95, 57}, {76, 57}, {57, 57}, {38, 57}, {19, 57}, {0, 57}, {0, 0},
        {0, 76}, {19, 76}, {38, 76}, {57, 76}, {76, 76}, {95, 76}, {114, 76}, {133, 76}, {152, 76}, {171, 76}, {190, 76}, {209, 76},
        {0, 95},{19, 95},//not used
#    else
        {0, 0}, {19, 0}, {38, 0}, {57, 0}, {76, 0}, {95, 0}, {114, 0}, {133, 0}, {152, 0}, {171, 0}, {190, 0}, {209, 0},
        {209, 19}, {190, 19}, {171, 19}, {152, 19}, {133, 19}, {114, 19}, {95, 19}, {76, 19}, {57, 19}, {38, 19}, {19, 19}, {0, 19},
        {0, 38}, {19, 38}, {38, 38}, {57, 38}, {76, 38}, {95, 38}, {114, 38}, {133, 38}, {152, 38}, {171, 38}, {190, 38}, {209, 38},
        {209, 57}, {190, 57}, {171, 57}, {152, 57}, {133, 57}, {114, 57}, {95, 57}, {76, 57}, {57, 57}, {38, 57}, {19, 57}, {0, 57},
        {0, 76}, {19, 76}, {38, 76}, {57, 76}, {76, 76}, {95, 76}, {114, 76}, {133, 76}, {152, 76}, {171, 76}, {190, 76}, {209, 76},
        {0, 0},{0, 0}, {0, 0},{0, 0},//not used
#    endif
    }, {
#    ifdef STAGGERED_RGB_ENCODERS
        1,                               1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
#    elif defined RGB_ENCODERS
        1,                               1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
#    elif defined STAGGERED_LAYOUT
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
#    else
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
#    endif
    } };
// clang-format on
#endif

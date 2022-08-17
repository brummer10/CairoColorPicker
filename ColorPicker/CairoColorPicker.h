/*
 *                           0BSD 
 * 
 *                    BSD Zero Clause License
 * 
 *  Copyright (c) 2021 Hermann Meyer
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted.

 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 *
 */

#include <stdint.h>
#include <stdlib.h>
#include <pwd.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <locale.h>

#include "xwidgets.h"

#pragma once

#ifndef XUICOLORCHOOSER_H_
#define XUICOLORCHOOSER_H_

#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------
-----------------------------------------------------------------------    
                macro to mark unused variables in function calls 
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

#ifdef __GNUC__
#  define UNUSED(x) UNUSED_ ## x __attribute__((__unused__))
#else
#  define UNUSED(x) UNUSED_ ## x
#endif

typedef struct {
    double r;
    double g;
    double b;
    double a;
} CairoColor;

typedef struct {
    double center_x;
    double center_y;
    double radius;
    double red;
    double green;
    double blue;
    double alpha;
    double lum;
    double focus_x;
    double focus_y;
    Widget_t* al;
    Widget_t* lu;
    Widget_t* format;
    Widget_t* color_widget;
    Colors *selected_scheme;
    CairoColor rgba[5];
} ColorChooser_t;

Widget_t *create_color_chooser (Xputty * app);

void show_color_chooser(Widget_t* w);

void set_focus_by_color(Widget_t* wid, const double r, const double g, const double b);

#ifdef __cplusplus
}
#endif

#endif //XUICOLORCHOOSER_H_

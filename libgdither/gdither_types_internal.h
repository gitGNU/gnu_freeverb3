/*
 *  Copyright (C) 2002 Steve Harris <steve@plugin.org.uk>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *  $Id: gdither_types_internal.h,v 1.2 2010/07/24 12:31:22 tkamogashira Exp $
 */

#ifndef GDITHER_TYPES_H
#define GDITHER_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif
 
#define GDITHER_SH_BUF_SIZE 8
#define GDITHER_SH_BUF_MASK 7

/* this must agree with whats in gdither_types.h */
typedef enum {
    GDitherNone = 0,
    GDitherRect,
    GDitherTri,
    GDitherShaped
} GDitherType;

typedef enum {
    GDither8bit = 8,
    GDither16bit = 16,
    GDither32bit = 32,
    GDitherFloat = 25,
    GDitherDouble = 54
} GDitherSize;

typedef struct {
    unsigned int phase;
    float buffer[GDITHER_SH_BUF_SIZE];
} GDitherShapedState;

typedef struct GDither_s {
    GDitherType type;
    unsigned int channels;
    unsigned int bit_depth;
    unsigned int dither_depth;
    float scale;
    unsigned int post_scale;
    float post_scale_fp;
    float bias;
    int   clamp_u;
    int   clamp_l;
    float *tri_state;
    GDitherShapedState *shaped_state;
} *GDither;

#ifdef __cplusplus
}
#endif

#endif

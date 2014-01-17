/*
 * Copyright (C) 2014 Franz-Josef Haider <f_haider@gmx.at>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#ifndef SURFACEFLINGER_COMPATIBILITY_LAYER_CONFIGURATION_H_
#define SURFACEFLINGER_COMPATIBILITY_LAYER_CONFIGURATION_H_

#ifdef __cplusplus
extern "C" {
#endif
	void set_display_ptr(void *ptr);
	int surfaceflinger_main(int argc, char **argv);
#ifdef __cplusplus
}
#endif

#endif // SURFACEFLINGER_COMPATIBILITY_LAYER_CONFIGURATION_H_

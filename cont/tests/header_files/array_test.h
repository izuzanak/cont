
#ifndef __ARRAY_TEST_H
#define __ARRAY_TEST_H

@begin
include "basic.h"
@end

/*
 * definition of generated structures
 */

// -- ui_array_s --
@begin
array<ui> ui_array_s;
@end

// -- ui_arrays_s --
@begin
array<ui_array_s> ui_arrays_s;
@end

// -- ui_fixed_array_s --
@begin
array<ui> options ( fixed_buffer ) ui_fixed_array_s;
@end

/*
 * inline methods of generated structures
 */

// -- ui_array_s --
@begin
inlines ui_array_s
@end

// -- ui_arrays_s --
@begin
inlines ui_arrays_s
@end

// -- ui_fixed_array_s --
@begin
inlines ui_fixed_array_s
@end

#endif


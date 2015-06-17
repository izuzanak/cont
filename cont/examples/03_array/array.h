
#ifndef __ARRAY_H
#define __ARRAY_H

@begin
include "struct.h"
@end

/*
 * definition of generated structures
 */

// -- rec_array_s --
@begin
   array<record_s> rec_array_s;
@end

/*
 * inline methods of generated structures
 */

// -- rec_array_s --
@begin
   inlines rec_array_s
@end

/*
 * definition of global methods
 */

void print_array(rec_array_s *rec_array,const char *name);

#endif


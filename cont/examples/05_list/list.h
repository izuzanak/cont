
#ifndef __LIST_H
#define __LIST_H

@begin
include "struct.h"
@end

/*
 * definition of generated structures
 */

// -- rec_list_s --
@begin
   list<record_s> rec_list_s;
@end

/*
 * inline methods of generated structures
 */

// -- rec_list_s --
@begin
   inlines rec_list_s
@end

/*
 * definition of global methods
 */

void print_list(rec_list_s *rec_list,const char *name);

#endif


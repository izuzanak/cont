
#ifndef __RB_TREE_H
#define __RB_TREE_H

@begin
include "struct.h"
@end

//#define FIXED_BUFFER

/*
 * definition of generated structures
 */

// -- ui_array_s --
@begin
   array<unsigned> ui_array_s;
@end

// -- rec_rb_tree_s --
@begin
   rb_tree<record_s> rec_rb_tree_s;
@end

/*
 * inline methods of generated structures
 */

// -- ui_array_s --
@begin
   inlines ui_array_s
@end

// -- rec_rb_tree_s --
@begin
   inlines rec_rb_tree_s
@end

inline int rec_rb_tree_s___compare_value(rec_rb_tree_s *this,record_s *a_first,record_s *a_second)
{
  register unsigned fi = a_first->index;
  register unsigned si = a_second->index;

  return fi < si ? -1 : fi > si ? 1 : 0;
}

/*
 * definition of global methods
 */

void print_tree(rec_rb_tree_s *rec_tree,const char *name);

#endif


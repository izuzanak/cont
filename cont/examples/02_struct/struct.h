
#ifndef __STRUCT_H
#define __STRUCT_H

@begin
include "base.h"
@end

/*
 * definition of generated structures
 */

// -- record_s --
@begin
struct
<
unsigned:index
unsigned:value
>

additions
{
inline unsigned record_s_get_index();
inline unsigned record_s_get_value();
}

record_s;
@end

/*
 * inline methods of generated structures
 */

// -- record_s --
@begin
inlines record_s
@end

inline unsigned record_s_get_index(record_s *this)
{
  return this->index;
}

inline unsigned record_s_get_value(record_s *this)
{
  return this->value;
}

/*
 * definition of global methods
 */

int main(int argc, char **argv);

#endif


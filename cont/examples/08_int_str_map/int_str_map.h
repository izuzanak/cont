
#ifndef __DYNAMIC_H
#define __DYNAMIC_H

@begin
include "struct.h"
@end

#include <stdarg.h>

/*
 * constants and definitions
 */

// - string terminating character -
extern const char c_string_terminating_char;

/*
 * definition of structure string_s
 */

@begin
define string_s dynamic
@end

struct string_s
{
  unsigned size;
  char *data;

  inline void init();
  inline void clear();
  inline void create(unsigned a_length);
  inline void set(unsigned a_length,const char *a_data);
  inline void flush_all() {}
  inline void swap(string_s &a_second);
  inline string_s &operator=(string_s &a_src);
  inline bool operator==(string_s &a_second);
  void setf(const char *format,...);
};

/*
 * definition of generated structures
 */

// -- ui_array_s --
@begin
   array<unsigned> ui_array_s;
@end

// -- int_string_s --
@begin
   struct
   <
   int:index
   string_s:value
   >
   int_string_s;
@end

// -- int_string_map_s --
@begin
   rb_tree<int_string_s> int_string_map_s;
@end

/*
 * inline methods of structure string_s
 */

inline void string_s::init()
{/*{{{*/
  size = 1;
  data = (char *)&c_string_terminating_char;
}/*}}}*/

inline void string_s::clear()
{/*{{{*/
  if (data != &c_string_terminating_char)
  {
    cfree(data);
  }

  init();
}/*}}}*/

inline void string_s::create(unsigned a_length)
{/*{{{*/
  clear();
  data = (char *)cmalloc((a_length + 1)*sizeof(char));

  data[a_length] = '\0';
  size = a_length + 1;
}/*}}}*/

inline void string_s::set(unsigned a_length,const char *a_data)
{/*{{{*/
  clear();
  data = (char *)cmalloc((a_length + 1)*sizeof(char));

  if (a_length != 0)
  {
    memcpy(data,a_data,a_length*sizeof(char));
  }

  data[a_length] = '\0';
  size = a_length + 1;
}/*}}}*/

inline void string_s::swap(string_s &a_second)
{/*{{{*/
  unsigned tmp_size = size;
  size = a_second.size;
  a_second.size = tmp_size;

  char *tmp_data = data;
  data = a_second.data;
  a_second.data = tmp_data;
}/*}}}*/

inline string_s &string_s::operator=(string_s &a_src)
{/*{{{*/
  clear();

  if (a_src.data == &c_string_terminating_char) return *this;
  data = (char *)cmalloc(a_src.size*sizeof(char));
  memcpy(data,a_src.data,(a_src.size - 1)*sizeof(char));
  data[a_src.size - 1] = '\0';
  size = a_src.size;

  return *this;
}/*}}}*/

inline bool string_s::operator==(string_s &a_second)
{/*{{{*/
  if (size != a_second.size) return false;
  if (data == &c_string_terminating_char) return true;
  return (memcmp(data,a_second.data,(size - 1)*sizeof(char)) == 0);
}/*}}}*/

/*
 * inline methods of generated structures
 */

// -- ui_array_s --
@begin
   inlines ui_array_s
@end

// -- int_string_s --
@begin
   inlines int_string_s
@end

// -- int_string_map_s --
@begin
   inlines int_string_map_s
@end

inline int int_string_map_s::__compare_value(int_string_s &a_first,int_string_s &a_second)
{/*{{{*/
  int &fi = a_first.index;
  int &si = a_second.index;

  return fi < si ? -1 : fi > si ? 1 : 0;
}/*}}}*/

#endif


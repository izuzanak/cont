
#ifndef __DYNAMIC_H
#define __DYNAMIC_H

@begin
include "struct.h"
@end

//#define FIXED_BUFFER

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

typedef struct string_s string_s;

struct string_s
{
  unsigned size;
  char *data;
};

static inline void string_s_init(string_s *this);
static inline void string_s_clear(string_s *this);
static inline void string_s_create(string_s *this,unsigned a_length);
static inline void string_s_set(string_s *this,unsigned a_length,const char *a_data);
static inline void string_s_flush_all(string_s *this) {}
static inline void string_s_swap(string_s *this,string_s *a_second);
static inline void string_s_copy(string_s *this,string_s *a_src);
static inline int string_s_compare(string_s *this,string_s *a_second);

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

static inline void string_s_init(string_s *this)
{/*{{{*/
  this->size = 1;
  this->data = (char *)&c_string_terminating_char;
}/*}}}*/

static inline void string_s_clear(string_s *this)
{/*{{{*/
  if (this->data != &c_string_terminating_char)
  {
    cfree(this->data);
  }

  string_s_init(this);
}/*}}}*/

static inline void string_s_create(string_s *this,unsigned a_length)
{/*{{{*/
  string_s_clear(this);
  if (a_length == 0) return;

  this->data = (char *)cmalloc((a_length + 1)*sizeof(char));

  this->data[a_length] = '\0';
  this->size = a_length + 1;
}/*}}}*/

static inline void string_s_set(string_s *this,unsigned a_length,const char *a_data)
{/*{{{*/
  string_s_clear(this);
  if (a_length == 0) return;

  this->data = (char *)cmalloc((a_length + 1)*sizeof(char));
  memcpy(this->data,a_data,a_length*sizeof(char));

  this->data[a_length] = '\0';
  this->size = a_length + 1;
}/*}}}*/

static inline void string_s_swap(string_s *this,string_s *a_second)
{/*{{{*/
  unsigned tmp_size = this->size;
  this->size = a_second->size;
  a_second->size = tmp_size;

  char *tmp_data = this->data;
  this->data = a_second->data;
  a_second->data = tmp_data;
}/*}}}*/

static inline void string_s_copy(string_s *this,string_s *a_src)
{/*{{{*/
  string_s_clear(this);

  if (a_src->data == &c_string_terminating_char) return;
  this->data = (char *)cmalloc(a_src->size*sizeof(char));
  memcpy(this->data,a_src->data,(a_src->size - 1)*sizeof(char));
  this->data[a_src->size - 1] = '\0';
  this->size = a_src->size;
}/*}}}*/

static inline int string_s_compare(string_s *this,string_s *a_second)
{/*{{{*/
  if (this->size != a_second->size) return 0;
  if (this->data == &c_string_terminating_char) return 1;
  return (memcmp(this->data,a_second->data,(this->size - 1)*sizeof(char)) == 0);
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

static inline int int_string_map_s___compare_value(int_string_map_s *this,int_string_s *a_first,int_string_s *a_second)
{/*{{{*/
  register int fi = a_first->index;
  register int si = a_second->index;

  return fi < si ? -1 : fi > si ? 1 : 0;
}/*}}}*/

#endif


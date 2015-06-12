
#ifndef __STRUCT_H
#define __STRUCT_H

@begin
include "ucl_string.h"
@end

/*
 * definition of generated structures
 */

// -- bc_array_s --
@begin
   array<char>

additions
{
  // - append characters to the end of character buffer -
  inline void append(unsigned a_count,const char *a_data);
}

   bc_array_s;
@end

// -- ui_array_s --
@begin
   array<unsigned> ui_array_s;
@end

// -- string_array_s --
@begin
   array<string_s> string_array_s;
@end

// -- string_rb_tree_s --
@begin
   rb_tree<string_s>

additions
{
  /*
   * \brief find index of string described by its length and pointer to char *
   * \param a_length - length of searched string
   * \param a_data - pointer to searched string data
   * \return index of string
   */
  inline unsigned get_idx_char_ptr(unsigned a_length,const char *a_data);
  inline void get_idxs_char_ptr(unsigned a_length,const char *a_data,ui_array_s &a_idxs_array);
  inline unsigned insert_char_ptr(unsigned a_length,const char *a_data);
  inline unsigned get_idx_char_ptr_insert(unsigned a_length,const char *a_data);
  inline unsigned get_idx_swap_insert(string_s &a_value);
}

   string_rb_tree_s;
@end

// -- lalr_stack_element_s --
@begin
struct
   <
   unsigned:lalr_state
   unsigned:terminal_start
   unsigned:terminal_end
   >
   lalr_stack_element_s;
@end

// -- lalr_stack_s --
@begin
   array<lalr_stack_element_s>

additions
{
  /*
   * \brief push new element and set only its state
   * \param a_lalr_state - state of new element
   */
  inline void push(unsigned a_lalr_state);

  /*
   * \brief push new element
   * \param a_lalr_state - state of new elemnt
   * \param a_terminal_start - start of terminal in source string
   * \param a_terminal_end - end of terminal in source string
   */
  inline void push(unsigned a_lalr_state,unsigned a_terminal_start,unsigned a_terminal_end);
}

   lalr_stack_s;
@end

/*
 * inline methods of generated structures
 */

// -- bc_array_s --
@begin
   inlines bc_array_s
@end

inline void bc_array_s::append(unsigned a_count,const char *a_data)
{/*{{{*/
  unsigned old_used = used;
  push_blanks(a_count);
  memcpy(data + old_used,a_data,a_count);
}/*}}}*/

// -- ui_array_s --
@begin
   inlines ui_array_s
@end

// -- string_array_s --
@begin
   inlines string_array_s
@end

// -- string_rb_tree_s --
@begin
   inlines string_rb_tree_s
@end

inline int string_rb_tree_s::__compare_value(string_s &a_first,string_s &a_second)
{/*{{{*/
  if (a_first.size < a_second.size) return -1;
  if (a_first.size > a_second.size) return 1;
  return strncmp(a_first.data,a_second.data,a_first.size - 1);
}/*}}}*/

inline unsigned string_rb_tree_s::get_idx_char_ptr(unsigned a_length,const char *a_data)
{/*{{{*/
  string_s tmp_str;
  tmp_str.data = (char *)a_data;
  tmp_str.size = a_length + 1;

  return get_idx(tmp_str);
}/*}}}*/

inline void string_rb_tree_s::get_idxs_char_ptr(unsigned a_length,const char *a_data,ui_array_s &a_idxs_array)
{/*{{{*/
  string_s tmp_str;
  tmp_str.data = (char *)a_data;
  tmp_str.size = a_length + 1;

  get_idxs(tmp_str,a_idxs_array);
}/*}}}*/

inline unsigned string_rb_tree_s::insert_char_ptr(unsigned a_length,const char *a_data)
{/*{{{*/
  string_s tmp_str;
  tmp_str.data = (char *)a_data;
  tmp_str.size = a_length + 1;

  return insert(tmp_str);
}/*}}}*/

inline unsigned string_rb_tree_s::get_idx_char_ptr_insert(unsigned a_length,const char *a_data)
{/*{{{*/
  unsigned idx = get_idx_char_ptr(a_length,a_data);

  if (idx == c_idx_not_exist)
  {
    return insert_char_ptr(a_length,a_data);
  }

  return idx;
}/*}}}*/

inline unsigned string_rb_tree_s::get_idx_swap_insert(string_s &a_value)
{/*{{{*/
  unsigned idx = get_idx(a_value);

  if (idx == c_idx_not_exist)
  {
    return swap_insert(a_value);
  }

  return idx;
}/*}}}*/

// -- lalr_stack_element_s --
@begin
   inlines lalr_stack_element_s
@end

// -- lalr_stack_s --
@begin
   inlines lalr_stack_s
@end

inline void lalr_stack_s::push(unsigned a_lalr_state)
{/*{{{*/
  if (used >= size)
  {
    copy_resize(size + c_array_add);
  }

  lalr_stack_element_s &target = data[used++];

  target.lalr_state = a_lalr_state;
}/*}}}*/

inline void lalr_stack_s::push(unsigned a_lalr_state,unsigned a_terminal_start,unsigned a_terminal_end)
{/*{{{*/
  if (used >= size)
  {
    copy_resize(size + c_array_add);
  }

  lalr_stack_element_s &target = data[used++];

  target.lalr_state = a_lalr_state;
  target.terminal_start = a_terminal_start;
  target.terminal_end = a_terminal_end;
}/*}}}*/

#endif


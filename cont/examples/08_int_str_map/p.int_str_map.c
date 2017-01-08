
typedef char bc;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef int bi;
typedef unsigned int ui;
typedef long int li;
typedef unsigned long uli;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef float bf;
typedef double bd;
typedef long double ld;



#ifndef __DYNAMIC_H
#define __DYNAMIC_H


#ifndef __STRUCT_H
#define __STRUCT_H


#ifndef __BASE_H
#define __BASE_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"
#include "math.h"

// - functions used by generated code of containers -
#define debug_assert assert
#define cmalloc malloc
#define cfree free

// - constants used by generated code of containers -
const unsigned c_array_add = 64;
const unsigned c_idx_not_exist = 0xffffffff;

// - logarithm of two (needed by red-black tree container) -
const float c_log_of_2 = 0.6931471805599453;

/*
 * definition of generated structures
 */

/*
 * inline methods of generated structures
 */

/*
 * definition of global methods
 */

int main(int argc, char **argv);

#endif



/*
 * definition of generated structures
 */

// -- record_s --
// structure record_s definition

typedef struct record_s record_s;

struct record_s
{
   unsigned index; //!< member - 0
   unsigned value; //!< member - 1
};

inline void record_s_init(record_s *this);
inline void record_s_clear(record_s *this);
inline void record_s_set(record_s *this,unsigned a_index,unsigned a_value);
inline void record_s_flush_all(record_s *this);
inline void record_s_swap(record_s *this,record_s *a_second);
inline void record_s_copy(record_s *this,record_s *a_src);
inline int record_s_compare(record_s *this,record_s *a_second);

inline unsigned record_s_get_index();
inline unsigned record_s_get_value();




/*
 * inline methods of generated structures
 */

// -- record_s --
// --- struct record_s inline method definition ---

inline void record_s_init(record_s *this)
{/*{{{*/
}/*}}}*/

inline void record_s_clear(record_s *this)
{/*{{{*/

   record_s_init(this);
}/*}}}*/

inline void record_s_set(record_s *this,unsigned a_index,unsigned a_value)
{/*{{{*/
   this->index = a_index;
   this->value = a_value;
}/*}}}*/

inline void record_s_flush_all(record_s *this)
{/*{{{*/
}/*}}}*/

inline void record_s_swap(record_s *this,record_s *a_second)
{/*{{{*/
   unsigned tmp_index = this->index;
   this->index = a_second->index;
   a_second->index = tmp_index;

   unsigned tmp_value = this->value;
   this->value = a_second->value;
   a_second->value = tmp_value;
}/*}}}*/

inline void record_s_copy(record_s *this,record_s *a_src)
{/*{{{*/
   this->index = a_src->index;
   this->value = a_src->value;
}/*}}}*/

inline int record_s_compare(record_s *this,record_s *a_second)
{/*{{{*/
   return (this->index == a_second->index && this->value == a_second->value);
}/*}}}*/



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



#include <stdarg.h>

/*
 * constants and definitions
 */

// - string terminating character -
extern const char c_string_terminating_char;

/*
 * definition of structure string_s
 */



typedef struct string_s string_s;

struct string_s
{
  unsigned size;
  char *data;
};

inline void string_s_init(string_s *this);
inline void string_s_clear(string_s *this);
inline void string_s_create(string_s *this,unsigned a_length);
inline void string_s_set(string_s *this,unsigned a_length,const char *a_data);
inline void string_s_flush_all(string_s *this) {}
inline void string_s_swap(string_s *this,string_s *a_second);
inline void string_s_copy(string_s *this,string_s *a_src);
inline int string_s_compare(string_s *this,string_s *a_second);

/*
 * definition of generated structures
 */

// -- ui_array_s --
// --- struct ui_array_s definition --- 

typedef struct ui_array_s ui_array_s;

struct ui_array_s
{
   unsigned size; //!< actual size of allocated space in array
   unsigned used; //!< count of used space in array
   unsigned *data; //!< pointer to array elements
};

inline void ui_array_s_init(ui_array_s *this);
inline void ui_array_s_init_size(ui_array_s *this,unsigned a_size);
inline void ui_array_s_clear(ui_array_s *this);
inline void ui_array_s_set(ui_array_s *this,unsigned a_used,unsigned *a_data);
inline void ui_array_s_flush(ui_array_s *this);
inline void ui_array_s_flush_all(ui_array_s *this);
inline void ui_array_s_swap(ui_array_s *this,ui_array_s *a_second);
inline unsigned *ui_array_s_at(ui_array_s *this,unsigned a_idx);
inline void ui_array_s_push(ui_array_s *this,unsigned a_value);
inline void ui_array_s_push_blank(ui_array_s *this);
void ui_array_s_reserve(ui_array_s *this,unsigned a_cnt);
void ui_array_s_push_blanks(ui_array_s *this,unsigned a_cnt);
inline void ui_array_s_push_clear(ui_array_s *this);
inline unsigned ui_array_s_pop(ui_array_s *this);
inline unsigned *ui_array_s_last(ui_array_s *this);
void ui_array_s_copy_resize(ui_array_s *this,unsigned a_size);
void ui_array_s_fill(ui_array_s *this,unsigned a_value);
unsigned ui_array_s_get_idx(ui_array_s *this,unsigned a_value);
inline void ui_array_s_copy(ui_array_s *this,ui_array_s *a_src);
inline int ui_array_s_compare(ui_array_s *this,ui_array_s *a_second);



// -- int_string_s --
// structure int_string_s definition

typedef struct int_string_s int_string_s;

struct int_string_s
{
   int index; //!< member - 0
   string_s value; //!< member - 1
};

inline void int_string_s_init(int_string_s *this);
inline void int_string_s_clear(int_string_s *this);
inline void int_string_s_set(int_string_s *this,int a_index,string_s *a_value);
inline void int_string_s_flush_all(int_string_s *this);
inline void int_string_s_swap(int_string_s *this,int_string_s *a_second);
inline void int_string_s_copy(int_string_s *this,int_string_s *a_src);
inline int int_string_s_compare(int_string_s *this,int_string_s *a_second);



// -- int_string_map_s --
// struct int_string_map_s definition

typedef struct int_string_map_s_node int_string_map_s_node;
typedef struct int_string_map_s int_string_map_s;

#ifndef RB_TREE_SET_LEAF_CHILDS
#define RB_TREE_SET_LEAF_CHILDS
#endif

struct int_string_map_s_node
{
   int_string_s object;
   unsigned parent_idx;
   unsigned left_idx;
   unsigned right_idx;
   char color;
};

struct int_string_map_s
{
   unsigned size;
   unsigned used;
   int_string_map_s_node *data;
   unsigned free_idx;
   unsigned root_idx;
   unsigned leaf_idx;
};

inline unsigned int_string_map_s___get_grandparent_idx(int_string_map_s *this,unsigned a_idx);
inline unsigned int_string_map_s___get_uncle_idx(int_string_map_s *this,unsigned a_idx);
inline unsigned int_string_map_s___get_sibling_idx(int_string_map_s *this,unsigned a_idx);
inline unsigned int_string_map_s_get_descent_stack_size(int_string_map_s *this);
unsigned int_string_map_s_get_stack_min_value_idx(int_string_map_s *this,unsigned a_idx,unsigned **a_s_ptr);
inline unsigned int_string_map_s_get_stack_next_idx(int_string_map_s *this,unsigned a_idx,unsigned **a_s_ptr,unsigned *a_stack_base);
unsigned int_string_map_s_get_min_value_idx(int_string_map_s *this,unsigned a_idx);
unsigned int_string_map_s_get_max_value_idx(int_string_map_s *this,unsigned a_idx);
unsigned int_string_map_s_get_next_idx(int_string_map_s *this,unsigned a_idx);
unsigned int_string_map_s_get_prev_idx(int_string_map_s *this,unsigned a_idx);
inline void int_string_map_s___rotate_left(int_string_map_s *this,unsigned a_idx);
inline void int_string_map_s___rotate_right(int_string_map_s *this,unsigned a_idx);
inline unsigned int_string_map_s___get_new_index(int_string_map_s *this);
void int_string_map_s___binary_tree_insert(int_string_map_s *this,unsigned a_new_idx,int_string_s *a_value);
inline void int_string_map_s___replace_delete_node_by_child(int_string_map_s *this,unsigned a_idx,unsigned a_ch_idx);
void int_string_map_s___remove_black_black(int_string_map_s *this,unsigned a_idx);
inline void int_string_map_s___remove_one_child(int_string_map_s *this,unsigned a_idx,unsigned a_ch_idx);
void int_string_map_s___insert_operation(int_string_map_s *this,unsigned a_idx);
inline int int_string_map_s___compare_value(int_string_map_s *this,int_string_s *a_first,int_string_s *a_second);
inline void int_string_map_s_init(int_string_map_s *this);
void int_string_map_s_clear(int_string_map_s *this);
inline void int_string_map_s_flush(int_string_map_s *this);
inline void int_string_map_s_flush_all(int_string_map_s *this);
inline void int_string_map_s_swap(int_string_map_s *this,int_string_map_s *a_second);
inline int_string_s *int_string_map_s_at(int_string_map_s *this,unsigned a_idx);
inline unsigned int_string_map_s_insert(int_string_map_s *this,int_string_s *a_value);
inline unsigned int_string_map_s_swap_insert(int_string_map_s *this,int_string_s *a_value);
void int_string_map_s_remove(int_string_map_s *this,unsigned a_idx);
void int_string_map_s_copy_resize(int_string_map_s *this,unsigned a_size);
unsigned int_string_map_s_get_idx(int_string_map_s *this,int_string_s *a_value);
unsigned int_string_map_s_get_idx_left(int_string_map_s *this,int_string_s *a_value);
unsigned int_string_map_s_get_gre_idx(int_string_map_s *this,int_string_s *a_value);
unsigned int_string_map_s_get_lee_idx(int_string_map_s *this,int_string_s *a_value);
void int_string_map_s_get_idxs(int_string_map_s *this,int_string_s *a_value,ui_array_s *a_idxs_array);
void int_string_map_s_copy(int_string_map_s *this,int_string_map_s *a_src);
int int_string_map_s_compare(int_string_map_s *this,int_string_map_s *a_second);
void int_string_map_s_rehash_tree(int_string_map_s *this);
void int_string_map_s_print_dot_code(int_string_map_s *this,FILE *a_file);
int int_string_map_s_check_rb_tree_properties(int_string_map_s *this);



/*
 * inline methods of structure string_s
 */

inline void string_s_init(string_s *this)
{/*{{{*/
  this->size = 1;
  this->data = (char *)&c_string_terminating_char;
}/*}}}*/

inline void string_s_clear(string_s *this)
{/*{{{*/
  if (this->data != &c_string_terminating_char)
  {
    cfree(this->data);
  }

  string_s_init(this);
}/*}}}*/

inline void string_s_create(string_s *this,unsigned a_length)
{/*{{{*/
  string_s_clear(this);
  if (a_length == 0) return;

  this->data = (char *)cmalloc((a_length + 1)*sizeof(char));

  this->data[a_length] = '\0';
  this->size = a_length + 1;
}/*}}}*/

inline void string_s_set(string_s *this,unsigned a_length,const char *a_data)
{/*{{{*/
  string_s_clear(this);
  if (a_length == 0) return;

  this->data = (char *)cmalloc((a_length + 1)*sizeof(char));
  memcpy(this->data,a_data,a_length*sizeof(char));

  this->data[a_length] = '\0';
  this->size = a_length + 1;
}/*}}}*/

inline void string_s_swap(string_s *this,string_s *a_second)
{/*{{{*/
  unsigned tmp_size = this->size;
  this->size = a_second->size;
  a_second->size = tmp_size;

  char *tmp_data = this->data;
  this->data = a_second->data;
  a_second->data = tmp_data;
}/*}}}*/

inline void string_s_copy(string_s *this,string_s *a_src)
{/*{{{*/
  string_s_clear(this);

  if (a_src->data == &c_string_terminating_char) return;
  this->data = (char *)cmalloc(a_src->size*sizeof(char));
  memcpy(this->data,a_src->data,(a_src->size - 1)*sizeof(char));
  this->data[a_src->size - 1] = '\0';
  this->size = a_src->size;
}/*}}}*/

inline int string_s_compare(string_s *this,string_s *a_second)
{/*{{{*/
  if (this->size != a_second->size) return 0;
  if (this->data == &c_string_terminating_char) return 1;
  return (memcmp(this->data,a_second->data,(this->size - 1)*sizeof(char)) == 0);
}/*}}}*/

/*
 * inline methods of generated structures
 */

// -- ui_array_s --
// --- struct ui_array_s inline method definition ---

inline void ui_array_s_init(ui_array_s *this)
{/*{{{*/
   this->size = 0;
   this->used = 0;
   this->data = NULL;
}/*}}}*/

inline void ui_array_s_init_size(ui_array_s *this,unsigned a_size)
{/*{{{*/
   ui_array_s_init(this);
   ui_array_s_copy_resize(this,a_size);
}/*}}}*/

inline void ui_array_s_clear(ui_array_s *this)
{/*{{{*/
   if (this->data != NULL) {
      cfree(this->data);
   }

   ui_array_s_init(this);
}/*}}}*/

inline void ui_array_s_set(ui_array_s *this,unsigned a_used,unsigned *a_data)
{/*{{{*/
   ui_array_s_clear(this);
   if (a_used == 0) return;

   debug_assert(a_data != NULL);
   ui_array_s_copy_resize(this,a_used);

   memcpy(this->data,a_data,a_used*sizeof(unsigned));
   this->used = a_used;
}/*}}}*/

inline void ui_array_s_flush(ui_array_s *this)
{/*{{{*/
   ui_array_s_copy_resize(this,this->used);
}/*}}}*/

inline void ui_array_s_flush_all(ui_array_s *this)
{/*{{{*/
   ui_array_s_copy_resize(this,this->used);
}/*}}}*/

inline void ui_array_s_swap(ui_array_s *this,ui_array_s *a_second)
{/*{{{*/
   unsigned tmp_unsigned = this->size;
   this->size = a_second->size;
   a_second->size = tmp_unsigned;

   tmp_unsigned = this->used;
   this->used = a_second->used;
   a_second->used = tmp_unsigned;

   unsigned *tmp_data = this->data;
   this->data = a_second->data;
   a_second->data = tmp_data;
}/*}}}*/

inline unsigned *ui_array_s_at(ui_array_s *this,unsigned a_idx)
{/*{{{*/
   debug_assert(a_idx < this->used);
   return this->data + a_idx;
}/*}}}*/

inline void ui_array_s_push(ui_array_s *this,unsigned a_value)
{/*{{{*/
   if (this->used >= this->size) {
      ui_array_s_copy_resize(this,(this->size << 1) + c_array_add);
   }

   this->data[this->used++] = a_value;
}/*}}}*/

inline void ui_array_s_push_blank(ui_array_s *this)
{/*{{{*/
   if (this->used >= this->size) {
      ui_array_s_copy_resize(this,(this->size << 1) + c_array_add);
   }

   this->used++;
}/*}}}*/

inline void ui_array_s_push_clear(ui_array_s *this)
{/*{{{*/
   if (this->used >= this->size) {
      ui_array_s_copy_resize(this,(this->size << 1) + c_array_add);
   }

   this->used++;
}/*}}}*/

inline unsigned ui_array_s_pop(ui_array_s *this)
{/*{{{*/
   debug_assert(this->used > 0);
   return this->data[--this->used];
}/*}}}*/

inline unsigned *ui_array_s_last(ui_array_s *this)
{/*{{{*/
   debug_assert(this->used > 0);
   return this->data + this->used - 1;
}/*}}}*/

inline void ui_array_s_copy(ui_array_s *this,ui_array_s *a_src)
{/*{{{*/
   ui_array_s_clear(this);

   if (a_src->used == 0) return;

   ui_array_s_copy_resize(this,a_src->used);
   memcpy(this->data,a_src->data,a_src->used*sizeof(unsigned));

   this->used = a_src->used;
}/*}}}*/

inline int ui_array_s_compare(ui_array_s *this,ui_array_s *a_second)
{/*{{{*/
   if (this->used != a_second->used) return 0;
   if (this->used == 0) return 1;

   return (memcmp(this->data,a_second->data,this->used*sizeof(unsigned)) == 0);
}/*}}}*/



// -- int_string_s --
// --- struct int_string_s inline method definition ---

inline void int_string_s_init(int_string_s *this)
{/*{{{*/
   string_s_init(&this->value);
}/*}}}*/

inline void int_string_s_clear(int_string_s *this)
{/*{{{*/
   string_s_clear(&this->value);

   int_string_s_init(this);
}/*}}}*/

inline void int_string_s_set(int_string_s *this,int a_index,string_s *a_value)
{/*{{{*/
   this->index = a_index;
   string_s_copy(&this->value,a_value);
}/*}}}*/

inline void int_string_s_flush_all(int_string_s *this)
{/*{{{*/
}/*}}}*/

inline void int_string_s_swap(int_string_s *this,int_string_s *a_second)
{/*{{{*/
   int tmp_index = this->index;
   this->index = a_second->index;
   a_second->index = tmp_index;

   string_s_swap(&this->value,&a_second->value);
}/*}}}*/

inline void int_string_s_copy(int_string_s *this,int_string_s *a_src)
{/*{{{*/
   this->index = a_src->index;
   string_s_copy(&this->value,&a_src->value);
}/*}}}*/

inline int int_string_s_compare(int_string_s *this,int_string_s *a_second)
{/*{{{*/
   return (this->index == a_second->index && string_s_compare(&this->value,&a_second->value));
}/*}}}*/



// -- int_string_map_s --
// --- struct int_string_map_s inline method definition ---

inline unsigned int_string_map_s___get_grandparent_idx(int_string_map_s *this,unsigned a_idx)
{/*{{{*/
   int_string_map_s_node *node = this->data + a_idx;

   if (node->parent_idx != c_idx_not_exist) {
      return this->data[node->parent_idx].parent_idx;
   }
   else {
      return c_idx_not_exist;
   }
}/*}}}*/

inline unsigned int_string_map_s___get_uncle_idx(int_string_map_s *this,unsigned a_idx)
{/*{{{*/
   unsigned gp_idx = int_string_map_s___get_grandparent_idx(this,a_idx);

   if (gp_idx == c_idx_not_exist) {
      return c_idx_not_exist;
   }
   else {
      int_string_map_s_node *gp = this->data + gp_idx;
      return gp->left_idx == this->data[a_idx].parent_idx?gp->right_idx:gp->left_idx;
   }
}/*}}}*/

inline unsigned int_string_map_s___get_sibling_idx(int_string_map_s *this,unsigned a_idx)
{/*{{{*/
   int_string_map_s_node *p = this->data + this->data[a_idx].parent_idx;
   return p->left_idx == a_idx?p->right_idx:p->left_idx;
}/*}}}*/

inline unsigned int_string_map_s_get_descent_stack_size(int_string_map_s *this)
{/*{{{*/
   return (unsigned)(logf(this->used)/c_log_of_2) << 1;
}/*}}}*/

inline unsigned int_string_map_s_get_stack_next_idx(int_string_map_s *this,unsigned a_idx,unsigned **a_s_ptr,unsigned *a_stack_base)
{/*{{{*/
   debug_assert(a_idx < this->used);

   int_string_map_s_node *node = this->data + a_idx;

   if (node->right_idx != this->leaf_idx) {
      return int_string_map_s_get_stack_min_value_idx(this,node->right_idx,a_s_ptr);
   }

   if (*a_s_ptr > a_stack_base) {
      return *(--(*a_s_ptr));
   }

   return c_idx_not_exist;
}/*}}}*/

inline void int_string_map_s___rotate_left(int_string_map_s *this,unsigned a_idx)
{/*{{{*/
   int_string_map_s_node *root = this->data + a_idx;
   int_string_map_s_node *pivot = this->data + root->right_idx;

   if (a_idx == this->root_idx) {
      this->root_idx = root->right_idx;
      pivot->parent_idx = c_idx_not_exist;
   }
   else {
      int_string_map_s_node *rp = this->data + root->parent_idx;

      if (rp->right_idx == a_idx)
      {
         rp->right_idx = root->right_idx;
      }
      else
      {
         rp->left_idx = root->right_idx;
      }

      pivot->parent_idx = root->parent_idx;
   }

   root->parent_idx = root->right_idx;

   root->right_idx = pivot->left_idx;
   this->data[root->right_idx].parent_idx = a_idx;

   pivot->left_idx = a_idx;
}/*}}}*/

inline void int_string_map_s___rotate_right(int_string_map_s *this,unsigned a_idx)
{/*{{{*/
   int_string_map_s_node *root = this->data + a_idx;
   int_string_map_s_node *pivot = this->data + root->left_idx;

   if (a_idx == this->root_idx) {
      this->root_idx = root->left_idx;
      pivot->parent_idx = c_idx_not_exist;
   }
   else {
      int_string_map_s_node *rp = this->data + root->parent_idx;

      if (rp->right_idx == a_idx)
      {
         rp->right_idx = root->left_idx;
      }
      else
      {
         rp->left_idx = root->left_idx;
      }

      pivot->parent_idx = root->parent_idx;
   }

   root->parent_idx = root->left_idx;

   root->left_idx = pivot->right_idx;
   this->data[root->left_idx].parent_idx = a_idx;

   pivot->right_idx = a_idx;
}/*}}}*/

inline unsigned int_string_map_s___get_new_index(int_string_map_s *this)
{/*{{{*/
   if (this->free_idx != c_idx_not_exist) {
      unsigned new_idx = this->free_idx;
      this->free_idx = this->data[new_idx].parent_idx;

      return new_idx;
   }
   else {
      if (this->used >= this->size) {
         int_string_map_s_copy_resize(this,(this->size << 1) + c_array_add);
      }

      return this->used++;
   }
}/*}}}*/

inline void int_string_map_s___replace_delete_node_by_child(int_string_map_s *this,unsigned a_idx,unsigned a_ch_idx)
{/*{{{*/
   int_string_map_s_node *node = this->data + a_idx;

   if (node->parent_idx != c_idx_not_exist) {
      int_string_map_s_node *parent = this->data + node->parent_idx;

      if (parent->left_idx == a_idx)
      {
         parent->left_idx = a_ch_idx;
      }
      else
      {
         parent->right_idx = a_ch_idx;
      }

      this->data[a_ch_idx].parent_idx = node->parent_idx;
   }
   else {
      this->root_idx = a_ch_idx == this->leaf_idx?c_idx_not_exist:a_ch_idx;
      this->data[a_ch_idx].parent_idx = c_idx_not_exist;
   }
}/*}}}*/

inline void int_string_map_s___remove_one_child(int_string_map_s *this,unsigned a_idx,unsigned a_ch_idx)
{/*{{{*/
   int_string_map_s_node *node = this->data + a_idx;
   int_string_map_s___replace_delete_node_by_child(this,a_idx,a_ch_idx);

   node->parent_idx = this->free_idx;
   this->free_idx = a_idx;

   if (node->color) {
      int_string_map_s_node *child_node = this->data + a_ch_idx;

      if (!child_node->color) {
         child_node->color = 1;
      }
      else {
         int_string_map_s___remove_black_black(this,a_ch_idx);
      }
   }
}/*}}}*/

inline void int_string_map_s_init(int_string_map_s *this)
{/*{{{*/
   this->size = 0;
   this->used = 0;
   this->data = NULL;
   this->free_idx = c_idx_not_exist;
   this->root_idx = c_idx_not_exist;
   this->leaf_idx = c_idx_not_exist;
}/*}}}*/

inline void int_string_map_s_flush(int_string_map_s *this)
{/*{{{*/
   int_string_map_s_copy_resize(this,this->used);
}/*}}}*/

inline void int_string_map_s_flush_all(int_string_map_s *this)
{/*{{{*/
   int_string_map_s_copy_resize(this,this->used);
}/*}}}*/

inline void int_string_map_s_swap(int_string_map_s *this,int_string_map_s *a_second)
{/*{{{*/
   unsigned tmp_unsigned = this->size;
   this->size = a_second->size;
   a_second->size = tmp_unsigned;

   tmp_unsigned = this->used;
   this->used = a_second->used;
   a_second->used = tmp_unsigned;

   int_string_map_s_node *tmp_data = this->data;
   this->data = a_second->data;
   a_second->data = tmp_data;

   tmp_unsigned = this->free_idx;
   this->free_idx = a_second->free_idx;
   a_second->free_idx = tmp_unsigned;

   tmp_unsigned = this->root_idx;
   this->root_idx = a_second->root_idx;
   a_second->root_idx = tmp_unsigned;

   tmp_unsigned = this->leaf_idx;
   this->leaf_idx = a_second->leaf_idx;
   a_second->leaf_idx = tmp_unsigned;
}/*}}}*/

inline int_string_s *int_string_map_s_at(int_string_map_s *this,unsigned a_idx)
{/*{{{*/
   debug_assert(a_idx < this->used);
   return &this->data[a_idx].object;
}/*}}}*/

inline unsigned int_string_map_s_insert(int_string_map_s *this,int_string_s *a_value)
{/*{{{*/
   unsigned new_node_idx = int_string_map_s___get_new_index(this);

   int_string_map_s___binary_tree_insert(this,new_node_idx,a_value);
   int_string_map_s___insert_operation(this,new_node_idx);

   int_string_s_copy(&this->data[new_node_idx].object,a_value);

   return new_node_idx;
}/*}}}*/

inline unsigned int_string_map_s_swap_insert(int_string_map_s *this,int_string_s *a_value)
{/*{{{*/
   unsigned new_node_idx = int_string_map_s___get_new_index(this);

   int_string_map_s___binary_tree_insert(this,new_node_idx,a_value);
   int_string_map_s___insert_operation(this,new_node_idx);

   int_string_s_swap(&this->data[new_node_idx].object,a_value);

   return new_node_idx;
}/*}}}*/



inline int int_string_map_s___compare_value(int_string_map_s *this,int_string_s *a_first,int_string_s *a_second)
{/*{{{*/
  register int fi = a_first->index;
  register int si = a_second->index;

  return fi < si ? -1 : fi > si ? 1 : 0;
}/*}}}*/

#endif



/*
 * constants and definitions
 */

// - string terminating character -
const char c_string_terminating_char = '\0';

/*
 * methods of generated structures
 */

// -- ui_array_s --
// --- struct ui_array_s method definition ---

void ui_array_s_reserve(ui_array_s *this,unsigned a_cnt)
{/*{{{*/
   unsigned required_cnt = this->used + a_cnt;
   if (required_cnt > this->size) {
      unsigned r_size = this->size;
      do {
         r_size = (r_size << 1) + c_array_add;
      } while(r_size < required_cnt);

      ui_array_s_copy_resize(this,r_size);
   }
}/*}}}*/

void ui_array_s_push_blanks(ui_array_s *this,unsigned a_cnt)
{/*{{{*/
   unsigned required_cnt = this->used + a_cnt;
   if (required_cnt > this->size) {
      unsigned r_size = this->size;
      do {
         r_size = (r_size << 1) + c_array_add;
      } while(r_size < required_cnt);

      ui_array_s_copy_resize(this,r_size);
   }

   this->used += a_cnt;
}/*}}}*/

void ui_array_s_copy_resize(ui_array_s *this,unsigned a_size)
{/*{{{*/
   debug_assert(a_size >= this->used);

   unsigned *n_data;

   if (a_size == 0) {
      n_data = NULL;
   }
   else {
      n_data = (unsigned *)cmalloc(a_size*sizeof(unsigned));
   }

   if (this->used != 0) {
      memcpy(n_data,this->data,this->used*sizeof(unsigned));
   }

   if (this->size != 0) {
      cfree(this->data);
   }

   this->data = n_data;
   this->size = a_size;
}/*}}}*/

void ui_array_s_fill(ui_array_s *this,unsigned a_value)
{/*{{{*/
   if (this->size == 0) return;

   unsigned *ptr = this->data;
   unsigned *ptr_end = this->data + this->size;

   do {
      *ptr = a_value;
   } while(++ptr < ptr_end);

   this->used = this->size;
}/*}}}*/

unsigned ui_array_s_get_idx(ui_array_s *this,unsigned a_value)
{/*{{{*/
   if (this->used == 0) return c_idx_not_exist;

   unsigned *ptr = this->data;
   unsigned *ptr_end = this->data + this->used;

   do {
      if (*ptr == a_value) {
         return ptr - this->data;
      }
   } while(++ptr < ptr_end);

   return c_idx_not_exist;
}/*}}}*/



// -- int_string_s --
// --- struct int_string_s method definition ---



// -- int_string_map_s --
// --- struct int_string_map_s method definition ---

unsigned int_string_map_s_get_stack_min_value_idx(int_string_map_s *this,unsigned a_idx,unsigned **a_s_ptr)
{/*{{{*/
   debug_assert(a_idx < this->used);

   unsigned node_idx = a_idx;
   do {
      int_string_map_s_node *node = this->data + node_idx;

      if (node->left_idx == this->leaf_idx) {
         return node_idx;
      }

      *((*a_s_ptr)++) = node_idx;
      node_idx = node->left_idx;
   } while(1);
}/*}}}*/

unsigned int_string_map_s_get_min_value_idx(int_string_map_s *this,unsigned a_idx)
{/*{{{*/
   debug_assert(a_idx < this->used);

   unsigned node_idx = a_idx;
   do {
      int_string_map_s_node *node = this->data + node_idx;

      if (node->left_idx == this->leaf_idx) {
         return node_idx;
      }

      node_idx = node->left_idx;
   } while(1);
}/*}}}*/

unsigned int_string_map_s_get_max_value_idx(int_string_map_s *this,unsigned a_idx)
{/*{{{*/
   debug_assert(a_idx < this->used);

   unsigned node_idx = a_idx;
   do {
      int_string_map_s_node *node = this->data + node_idx;

      if (node->right_idx == this->leaf_idx) {
         return node_idx;
      }

      node_idx = node->right_idx;
   } while(1);
}/*}}}*/

unsigned int_string_map_s_get_next_idx(int_string_map_s *this,unsigned a_idx)
{/*{{{*/
   debug_assert(a_idx < this->used);

   int_string_map_s_node *node = this->data + a_idx;

   if (node->right_idx != this->leaf_idx) {
      return int_string_map_s_get_min_value_idx(this,node->right_idx);
   }
   else {

      unsigned node_idx = a_idx;
      do {
         int_string_map_s_node *node = this->data + node_idx;

         if (node->parent_idx == c_idx_not_exist) {
            return c_idx_not_exist;
         }

         if (this->data[node->parent_idx].right_idx != node_idx) {
            return node->parent_idx;
         }

         node_idx = node->parent_idx;
      } while(1);
   }
}/*}}}*/

unsigned int_string_map_s_get_prev_idx(int_string_map_s *this,unsigned a_idx)
{/*{{{*/
   debug_assert(a_idx < this->used);

   int_string_map_s_node *node = this->data + a_idx;

   if (node->left_idx != this->leaf_idx) {
      return int_string_map_s_get_max_value_idx(this,node->left_idx);
   }
   else {

      unsigned node_idx = a_idx;
      do {
         int_string_map_s_node *node = this->data + node_idx;

         if (node->parent_idx == c_idx_not_exist) {
            return c_idx_not_exist;
         }

         if (this->data[node->parent_idx].left_idx != node_idx) {
            return node->parent_idx;
         }

         node_idx = node->parent_idx;
      } while(1);
   }
}/*}}}*/

void int_string_map_s___binary_tree_insert(int_string_map_s *this,unsigned a_new_idx,int_string_s *a_value)
{/*{{{*/
   if (this->root_idx == c_idx_not_exist) {
      if (this->leaf_idx == c_idx_not_exist) {
         this->leaf_idx = int_string_map_s___get_new_index(this);
         int_string_map_s_node *leaf = this->data + this->leaf_idx;

         leaf->color = 1;

#ifdef RB_TREE_SET_LEAF_CHILDS
         leaf->left_idx = c_idx_not_exist;
         leaf->right_idx = c_idx_not_exist;
#endif
      }

      this->data[a_new_idx].parent_idx = c_idx_not_exist;
      this->root_idx = a_new_idx;
   }
   else  {
      unsigned node_idx = this->root_idx;
      do {
         int_string_map_s_node *node = this->data + node_idx;

         if (int_string_map_s___compare_value(this,a_value,&node->object) < 0) {
            if (node->left_idx == this->leaf_idx) {
               node->left_idx = a_new_idx;
               break;
            }
            node_idx = node->left_idx;
         }
         else {
            if (node->right_idx == this->leaf_idx) {
               node->right_idx = a_new_idx;
               break;
            }
            node_idx = node->right_idx;
         }
      } while(1);

      this->data[a_new_idx].parent_idx = node_idx;
   }

   int_string_map_s_node *new_node = this->data + a_new_idx;
   new_node->left_idx = this->leaf_idx;
   new_node->right_idx = this->leaf_idx;
   new_node->color = 0;
}/*}}}*/

void int_string_map_s___remove_black_black(int_string_map_s *this,unsigned a_idx)
{/*{{{*/
   unsigned node_idx = a_idx;
   do {
      int_string_map_s_node *node = this->data + node_idx;

      if (node->parent_idx == c_idx_not_exist) {
         return;
      }

      unsigned parent_idx = node->parent_idx;
      int_string_map_s_node *parent = this->data + parent_idx;

      {
         unsigned sibling_idx = parent->left_idx == node_idx?parent->right_idx:parent->left_idx;
         int_string_map_s_node *sibling = this->data + sibling_idx;

         if (!sibling->color) {
            parent->color = 0;
            sibling->color = 1;

            if (node_idx == parent->left_idx) {
               int_string_map_s___rotate_left(this,parent_idx);
            }
            else {
               int_string_map_s___rotate_right(this,parent_idx);
            }
         }
      }

      {
         unsigned sibling_idx = parent->left_idx == node_idx?parent->right_idx:parent->left_idx;
         int_string_map_s_node* sibling = this->data + sibling_idx;

         if (parent->color && sibling->color && this->data[sibling->left_idx].color && this->data[sibling->right_idx].color) {
            sibling->color = 0;
            node_idx = parent_idx;
            continue;
         }
         else if (!parent->color && sibling->color && this->data[sibling->left_idx].color && this->data[sibling->right_idx].color) {
            sibling->color = 0;
            parent->color = 1;
            return;
         }
         else if (sibling->color) {
            if (node_idx == parent->left_idx && this->data[sibling->right_idx].color && !this->data[sibling->left_idx].color) {
               sibling->color = 0;
               this->data[sibling->left_idx].color = 1;
               int_string_map_s___rotate_right(this,sibling_idx);
            }
            else if (node_idx == parent->right_idx && this->data[sibling->left_idx].color && !this->data[sibling->right_idx].color) {
               sibling->color = 0;
               this->data[sibling->right_idx].color = 1;
               int_string_map_s___rotate_left(this,sibling_idx);
            }
         }

         {
            unsigned sibling_idx = parent->left_idx == node_idx?parent->right_idx:parent->left_idx;
            int_string_map_s_node *sibling = this->data + sibling_idx;

            sibling->color = parent->color;
            parent->color = 1;

            if (node_idx == parent->left_idx) {
               this->data[sibling->right_idx].color = 1;
               int_string_map_s___rotate_left(this,parent_idx);
            }
            else {
               this->data[sibling->left_idx].color = 1;
               int_string_map_s___rotate_right(this,parent_idx);
            }
         }

         return;
      }

   } while(1);
}/*}}}*/

void int_string_map_s___insert_operation(int_string_map_s *this,unsigned a_idx)
{/*{{{*/
   unsigned node_idx = a_idx;
   do {
      int_string_map_s_node *node = this->data + node_idx;

      if (node->parent_idx == c_idx_not_exist) {
         node->color = 1;
         return;
      }
      else {
         if (this->data[node->parent_idx].color) {
            return;
         }
         else {
            unsigned uncle_idx = int_string_map_s___get_uncle_idx(this,node_idx);
            if (uncle_idx != c_idx_not_exist && !this->data[uncle_idx].color) {
               this->data[node->parent_idx].color = 1;
               this->data[uncle_idx].color = 1;

               node_idx = int_string_map_s___get_grandparent_idx(this,node_idx);
               this->data[node_idx].color = 0;

               continue;
            }
            else {
               unsigned grandparent_idx = int_string_map_s___get_grandparent_idx(this,node_idx);

               if (node_idx == this->data[node->parent_idx].right_idx && node->parent_idx == this->data[grandparent_idx].left_idx) {
                  int_string_map_s___rotate_left(this,node->parent_idx);
                  node_idx = node->left_idx;
               }
               else if (node_idx == this->data[node->parent_idx].left_idx && node->parent_idx == this->data[grandparent_idx].right_idx) {
                  int_string_map_s___rotate_right(this,node->parent_idx);
                  node_idx = node->right_idx;
               }

               {
                  unsigned grandparent_idx = int_string_map_s___get_grandparent_idx(this,node_idx);
                  int_string_map_s_node *node = this->data + node_idx;

                  this->data[node->parent_idx].color = 1;
                  this->data[grandparent_idx].color = 0;

                  if (node_idx == this->data[node->parent_idx].left_idx && node->parent_idx == this->data[grandparent_idx].left_idx) {
                     int_string_map_s___rotate_right(this,grandparent_idx);
                  }
                  else {
                     int_string_map_s___rotate_left(this,grandparent_idx);
                  }
               }

               return;
            }
         }
      }
   } while(1);
}/*}}}*/

void int_string_map_s_clear(int_string_map_s *this)
{/*{{{*/
   if (this->data != NULL) {
      int_string_map_s_node *ptr = this->data;
      int_string_map_s_node *ptr_end = ptr + this->size;

      do {
         int_string_s_clear(&ptr->object);
      } while(++ptr < ptr_end);

      cfree(this->data);
   }

   int_string_map_s_init(this);
}/*}}}*/

void int_string_map_s_remove(int_string_map_s *this,unsigned a_idx)
{/*{{{*/
   debug_assert(a_idx < this->used);

   int_string_map_s_node *del_node = this->data + a_idx;

   if (del_node->left_idx != this->leaf_idx) {
      if (del_node->right_idx != this->leaf_idx) {

         unsigned found_idx = del_node->right_idx;
         do {
            int_string_map_s_node *node = this->data + found_idx;

            if (node->left_idx == this->leaf_idx) {
               break;
            }

            found_idx = node->left_idx;
         } while(1);

         int_string_map_s_node *found_node = this->data + found_idx;

         /* - process del_node parent_idx - */
         if (del_node->parent_idx != c_idx_not_exist) {
            int_string_map_s_node *del_node_parent = this->data + del_node->parent_idx;

            if (del_node_parent->left_idx == a_idx)
            {
               del_node_parent->left_idx = found_idx;
            }
            else
            {
               del_node_parent->right_idx = found_idx;
            }
         }
         else {
            this->root_idx = found_idx;
         }

         /* - process del_node left_idx - */
         this->data[del_node->left_idx].parent_idx = found_idx;

         /* - process found_node right_idx - */
         if (found_node->right_idx != this->leaf_idx) {
            this->data[found_node->right_idx].parent_idx = a_idx;
         }

         if (del_node->right_idx == found_idx) {

            /* - found node is right child of deleted node - */
            del_node->right_idx = found_node->right_idx;
            found_node->right_idx = a_idx;

            found_node->parent_idx = del_node->parent_idx;
            del_node->parent_idx = found_idx;

            found_node->left_idx = del_node->left_idx;
            del_node->left_idx = this->leaf_idx;

            char tmp_char = found_node->color;
            found_node->color = del_node->color;
            del_node->color = tmp_char;
         }
         else {

            /* - process found_node parent - */
            int_string_map_s_node *found_node_parent = this->data + found_node->parent_idx;

            if (found_node_parent->left_idx == found_idx)
            {
               found_node_parent->left_idx = a_idx;
            }
            else
            {
               found_node_parent->right_idx = a_idx;
            }

            /* - process del_node right_idx - */
            this->data[del_node->right_idx].parent_idx = found_idx;

            /* - swap index pointers between nodes - */
            unsigned tmp_unsigned = found_node->parent_idx;
            found_node->parent_idx = del_node->parent_idx;
            del_node->parent_idx = tmp_unsigned;

            found_node->left_idx = del_node->left_idx;
            del_node->left_idx = this->leaf_idx;

            tmp_unsigned = found_node->right_idx;
            found_node->right_idx = del_node->right_idx;
            del_node->right_idx = tmp_unsigned;

            char tmp_char = found_node->color;
            found_node->color = del_node->color;
            del_node->color = tmp_char;
         }

         int_string_map_s___remove_one_child(this,a_idx,del_node->right_idx);
      }
      else {
         int_string_map_s___remove_one_child(this,a_idx,del_node->left_idx);
      }
   }
   else {
      int_string_map_s___remove_one_child(this,a_idx,del_node->right_idx);
   }

}/*}}}*/

void int_string_map_s_copy_resize(int_string_map_s *this,unsigned a_size)
{/*{{{*/
   debug_assert(a_size >= this->used);

   int_string_map_s_node *n_data;

   if (a_size == 0) {
      n_data = NULL;
   }
   else {
      n_data = (int_string_map_s_node *)cmalloc(a_size*sizeof(int_string_map_s_node));

      if (a_size > this->used) {
         int_string_map_s_node *ptr = n_data + this->used;
         int_string_map_s_node *ptr_end = n_data + a_size;

         do {
            int_string_s_init(&ptr->object);
         } while(++ptr < ptr_end);
      }
   }

   if (this->used != 0) {
      memcpy(n_data,this->data,this->used*sizeof(int_string_map_s_node));
   }

   if (this->size > this->used) {
      int_string_map_s_node *ptr = this->data + this->used;
      int_string_map_s_node *ptr_end = this->data + this->size;

      do {
         int_string_s_clear(&ptr->object);
      } while(++ptr < ptr_end);
   }

   if (this->size != 0) {
      cfree(this->data);
   }

   this->data = n_data;
   this->size = a_size;
}/*}}}*/

unsigned int_string_map_s_get_idx(int_string_map_s *this,int_string_s *a_value)
{/*{{{*/
   if (this->root_idx == c_idx_not_exist) {
      return c_idx_not_exist;
   }

   unsigned node_idx = this->root_idx;
   do {
      int_string_map_s_node *node = this->data + node_idx;

      int comp_result = int_string_map_s___compare_value(this,a_value,&node->object);
      if (comp_result < 0) {
         node_idx = node->left_idx;
      }
      else {
         if (comp_result == 0) {
            return node_idx;
         }

         node_idx = node->right_idx;
      }
   } while(node_idx != this->leaf_idx);

   return c_idx_not_exist;
}/*}}}*/

unsigned int_string_map_s_get_idx_left(int_string_map_s *this,int_string_s *a_value)
{/*{{{*/
   if (this->root_idx == c_idx_not_exist) {
      return c_idx_not_exist;
   }

   unsigned good_idx = c_idx_not_exist;
   unsigned node_idx = this->root_idx;
   do {
      int_string_map_s_node *node = this->data + node_idx;

      int comp_result = int_string_map_s___compare_value(this,a_value,&node->object);
      if (comp_result < 0) {
         node_idx = node->left_idx;
      }
      else {
         if (comp_result == 0) {
            good_idx = node_idx;
            node_idx = node->left_idx;
         }
         else {
            node_idx = node->right_idx;
         }
      }
   } while(node_idx != this->leaf_idx);

   return good_idx;
}/*}}}*/

unsigned int_string_map_s_get_gre_idx(int_string_map_s *this,int_string_s *a_value)
{/*{{{*/
   if (this->root_idx == c_idx_not_exist) {
      return c_idx_not_exist;
   }

   unsigned good_idx = c_idx_not_exist;
   unsigned node_idx = this->root_idx;
   do {
      int_string_map_s_node *node = this->data + node_idx;

      int comp_result = int_string_map_s___compare_value(this,a_value,&node->object);
      if (comp_result < 0) {
         good_idx = node_idx;
         node_idx = node->left_idx;
      }
      else {
         if (comp_result == 0) {
            return node_idx;
         }

         node_idx = node->right_idx;
      }
   } while(node_idx != this->leaf_idx);

   return good_idx;
}/*}}}*/

unsigned int_string_map_s_get_lee_idx(int_string_map_s *this,int_string_s *a_value)
{/*{{{*/
   if (this->root_idx == c_idx_not_exist) {
      return c_idx_not_exist;
   }

   unsigned good_idx = c_idx_not_exist;
   unsigned node_idx = this->root_idx;
   do {
      int_string_map_s_node *node = this->data + node_idx;

      int comp_result = int_string_map_s___compare_value(this,a_value,&node->object);
      if (comp_result < 0) {
         node_idx = node->left_idx;
      }
      else {
         if (comp_result == 0) {
            return node_idx;
         }

         good_idx = node_idx;
         node_idx = node->right_idx;
      }
   } while(node_idx != this->leaf_idx);

   return good_idx;
}/*}}}*/

void int_string_map_s_get_idxs(int_string_map_s *this,int_string_s *a_value,ui_array_s *a_idxs_array)
{/*{{{*/
   a_idxs_array->used = 0;

   if (this->root_idx == c_idx_not_exist) {
      return;
   }

   unsigned stack[int_string_map_s_get_descent_stack_size(this)];
   unsigned *stack_ptr = stack;

   *(stack_ptr++) = this->root_idx;
   do {
      unsigned node_idx = *(--stack_ptr);
      int_string_map_s_node *node = this->data + node_idx;

      int comp_result = int_string_map_s___compare_value(this,a_value,&node->object);
      if (comp_result < 0) {
         if (node->left_idx != this->leaf_idx) {
            *(stack_ptr++) = node->left_idx;
         }
      }
      else {
         if (comp_result == 0) {
            ui_array_s_push(a_idxs_array,node_idx);

            if (node->left_idx != this->leaf_idx) {
               *(stack_ptr++) = node->left_idx;
            }
         }

         if (node->right_idx != this->leaf_idx) {
            *(stack_ptr++) = node->right_idx;
         }
      }
   } while(stack_ptr > stack);

   return;
}/*}}}*/

void int_string_map_s_copy(int_string_map_s *this,int_string_map_s *a_src)
{/*{{{*/
   int_string_map_s_clear(this);

   if (a_src->root_idx == c_idx_not_exist) return;

   int_string_map_s_copy_resize(this,a_src->used);

   int_string_map_s_node *ptr = this->data;
   int_string_map_s_node *s_ptr = a_src->data;
   int_string_map_s_node *s_ptr_end = s_ptr + a_src->used;

   do {
      int_string_s_copy(&ptr->object,&s_ptr->object);
      ptr->parent_idx = s_ptr->parent_idx;
      ptr->left_idx = s_ptr->left_idx;
      ptr->right_idx = s_ptr->right_idx;
      ptr->color = s_ptr->color;
   } while(++ptr,++s_ptr < s_ptr_end);

   this->used = a_src->used;
   this->free_idx = a_src->free_idx;
   this->root_idx = a_src->root_idx;
   this->leaf_idx = a_src->leaf_idx;
}/*}}}*/

int int_string_map_s_compare(int_string_map_s *this,int_string_map_s *a_second)
{/*{{{*/
   if (this->root_idx == c_idx_not_exist) {
      if (a_second->root_idx != c_idx_not_exist) {
         return 0;
      }
   }
   else {
      if (a_second->root_idx == c_idx_not_exist) {
         return 0;
      }

      unsigned stack[int_string_map_s_get_descent_stack_size(this)];
      unsigned s_stack[int_string_map_s_get_descent_stack_size(a_second)];

      unsigned *stack_ptr = stack;
      unsigned *s_stack_ptr = s_stack;

      unsigned node_idx = int_string_map_s_get_stack_min_value_idx(this,this->root_idx,&stack_ptr);
      unsigned s_node_idx = int_string_map_s_get_stack_min_value_idx(a_second,a_second->root_idx,&s_stack_ptr);
      do {
         if (!int_string_s_compare(&this->data[node_idx].object,&a_second->data[s_node_idx].object)) {
            return 0;
         }

         node_idx = int_string_map_s_get_stack_next_idx(this,node_idx,&stack_ptr,stack);
         s_node_idx = int_string_map_s_get_stack_next_idx(a_second,s_node_idx,&s_stack_ptr,s_stack);
      } while(node_idx != c_idx_not_exist && s_node_idx != c_idx_not_exist);

      if (node_idx != s_node_idx) {
         return 0;
      }
   }

   return 1;
}/*}}}*/

void int_string_map_s_rehash_tree(int_string_map_s *this)
{/*{{{*/
   if (this->root_idx == c_idx_not_exist) return;

   ui_array_s indexes;
   ui_array_s_init(&indexes);

   {
      unsigned stack[int_string_map_s_get_descent_stack_size(this)];
      unsigned *stack_ptr = stack;

      unsigned idx = int_string_map_s_get_stack_min_value_idx(this,this->root_idx,&stack_ptr);
      do {
         ui_array_s_push(&indexes,idx);

         idx = int_string_map_s_get_stack_next_idx(this,idx,&stack_ptr,stack);
      } while(idx != c_idx_not_exist);
   }

   this->root_idx = c_idx_not_exist;

   char processed[indexes.used];
   memset(processed,0,indexes.used*sizeof(char));

   unsigned step = indexes.used >> 1;
   if (step > 0) {
      do {
         unsigned idx = step;
         do {
            if (!processed[idx]) {
               unsigned node_idx = indexes.data[idx];

               int_string_map_s___binary_tree_insert(this,node_idx,&this->data[node_idx].object);
               int_string_map_s___insert_operation(this,node_idx);

               processed[idx] = 1;
            }
         } while((idx += step) < indexes.used);
      } while((step >>= 1) > 0);
   }

   unsigned node_idx = indexes.data[0];
   int_string_map_s___binary_tree_insert(this,node_idx,&this->data[node_idx].object);
   int_string_map_s___insert_operation(this,node_idx);

   ui_array_s_clear(&indexes);
}/*}}}*/

void int_string_map_s_print_dot_code(int_string_map_s *this,FILE *a_file)
{/*{{{*/
   fprintf(a_file,
"digraph G {\n"
"   rankdir = TD\n"
"   node [ shape = circle margin = 0.0 fixedsize = true width = 0.7 height = 0.7]\n"
"\n"
   );

   const char *node_colors[] = {
      "red",
      "black",
   };

   fprintf(a_file,
"   root_idx [label = \"R\" ]\n"
"   root_idx -> node_%u\n"
   ,this->root_idx);

   if (this->root_idx != c_idx_not_exist) {
      ui_array_s stack;
      ui_array_s_init(&stack);

      ui_array_s_push(&stack,this->root_idx);
      do {
         unsigned node_idx = ui_array_s_pop(&stack);
         int_string_map_s_node *node = this->data + node_idx;

         /* - print node - */
         fprintf(a_file,
"   node_%u [ color = \"%s\" label = \"%u\" ]\n"
         ,node_idx,node_colors[(int)node->color],node_idx);

         if (node->parent_idx != c_idx_not_exist) {
            fprintf(a_file,
"   node_%u -> node_%u [ color = green ] \n"
            ,node_idx,node->parent_idx);
         }

         if (node->left_idx != this->leaf_idx) {
            fprintf(a_file,
"   node_%u -> node_%u [ label = \"L\" ]\n"
            ,node_idx,node->left_idx);

            ui_array_s_push(&stack,node->left_idx);
         }

         if (node->right_idx != this->leaf_idx) {
            fprintf(a_file,
"   node_%u -> node_%u [ label = \"R\" ]\n"
            ,node_idx,node->right_idx);

            ui_array_s_push(&stack,node->right_idx);
         }
      } while(stack.used > 0);

      ui_array_s_clear(&stack);
   }

   fprintf(a_file,
"}\n"
"\n");

}/*}}}*/

int int_string_map_s_check_rb_tree_properties(int_string_map_s *this)
{/*{{{*/
   int_string_map_s_node *leaf = this->data + this->leaf_idx;
   if (!leaf->color) {
      fprintf(stderr,"ERROR: leaf_node color\n");
      return 0;
   }

   if (leaf->left_idx != c_idx_not_exist || leaf->right_idx != c_idx_not_exist) {
      fprintf(stderr,"ERROR: leaf_node indexes (INFO: is allowed setting in mt_automaton code?)\n");
      return 0;
   }

   if (this->root_idx != c_idx_not_exist) {

      /* - check if root node is black - */
      int_string_map_s_node *r_node = this->data + this->root_idx;
      if (!r_node->color) {
         fprintf(stderr,"ERROR: root node is not black\n");
         return 0;
      }

      /* - create node index and path length stacks - */
      ui_array_s ni_stack;
      ui_array_s pl_stack;

      ui_array_s_init(&ni_stack);
      ui_array_s_init(&pl_stack);

      /* - insert root on stack - */
      ui_array_s_push(&ni_stack,this->root_idx);
      ui_array_s_push(&pl_stack,0);

      unsigned r_path_length = c_idx_not_exist;
      do {
         unsigned node_idx = ui_array_s_pop(&ni_stack);
         unsigned path_length = ui_array_s_pop(&pl_stack);
         unsigned stack_depth = ni_stack.used;

         int_string_map_s_node *node = this->data + node_idx;

         if (node->color) {
            path_length++;
         }
         else {
            if (node->left_idx == c_idx_not_exist || node->right_idx == c_idx_not_exist) {
               fprintf(stderr,"ERROR: red node has not two childs!\n");
               ui_array_s_clear(&ni_stack);
               ui_array_s_clear(&pl_stack);
               return 0;
            }

            if (!this->data[node->left_idx].color || !this->data[node->right_idx].color) {
               fprintf(stderr,"ERROR: child of red node is not black!\n");
               ui_array_s_clear(&ni_stack);
               ui_array_s_clear(&pl_stack);
               return 0;
            }
         }

         if (node->left_idx != c_idx_not_exist) {
            ui_array_s_push(&ni_stack,node->left_idx);
            ui_array_s_push(&pl_stack,path_length);
         }

         if (node->right_idx != c_idx_not_exist) {
            ui_array_s_push(&ni_stack,node->right_idx);
            ui_array_s_push(&pl_stack,path_length);
         }

         /* - if node is leaf node - */
         if (stack_depth == ni_stack.used) {
            if (r_path_length != c_idx_not_exist) {
               if (r_path_length != path_length) {
                  fprintf(stderr,"ERROR: all path have no same length!\n");
                  ui_array_s_clear(&ni_stack);
                  ui_array_s_clear(&pl_stack);
                  return 0;
               }
            }
            else {
               r_path_length = path_length;
            }
         }

      } while(ni_stack.used > 0);

      ui_array_s_clear(&ni_stack);
      ui_array_s_clear(&pl_stack);
   }

   /* - test if are node values sorted - */
   if (this->root_idx != c_idx_not_exist) {
      unsigned stack[int_string_map_s_get_descent_stack_size(this)];
      unsigned *stack_ptr = stack;

      unsigned idx = int_string_map_s_get_stack_min_value_idx(this,this->root_idx,&stack_ptr);
      do {
         unsigned l_idx = idx;
         idx = int_string_map_s_get_stack_next_idx(this,idx,&stack_ptr,stack);
         if (idx == c_idx_not_exist) {
            break;
         }
         if (int_string_map_s___compare_value(this,&this->data[l_idx].object,&this->data[idx].object) == 1) {
            fprintf(stderr,"ERROR: values in rb_tree are not sorted\n");
            return 0;
         }
      } while(1);
   }

   return 1;
}/*}}}*/



int main(int argc, char **argv)
{
  int_string_map_s map;
  int_string_map_s_init(&map);

  unsigned buff_size = 64;
  char buffer[buff_size];

  // ...
  {
    string_s str;
    string_s_init(&str);

    int_string_s pair;
    int_string_s_init(&pair);

    int idx = 0;
    do {
      int length = snprintf(buffer,buff_size,"string-%d",idx);

      pair.index = rand() % 1000;
      string_s_set(&pair.value,length,buffer);

      unsigned p_idx = int_string_map_s_get_idx(&map,&pair);
      if (p_idx != c_idx_not_exist)
      {
        string_s_swap(&int_string_map_s_at(&map,p_idx)->value,&pair.value);
      }
      else
      {
        int_string_map_s_swap_insert(&map,&pair);
      }
    } while(++idx < 1000000);

    int_string_s_clear(&pair);
    string_s_clear(&str);
  }

  // ...
  if (map.root_idx != c_idx_not_exist)
  {
    unsigned stack[int_string_map_s_get_descent_stack_size(&map)];
    unsigned *stack_ptr = stack;

    unsigned idx = int_string_map_s_get_stack_min_value_idx(&map,map.root_idx,&stack_ptr);
    do
    {
      int_string_s *pair = int_string_map_s_at(&map,idx);
      printf("%d -> %s\n",pair->index,pair->value.data);

      idx = int_string_map_s_get_stack_next_idx(&map,idx,&stack_ptr,stack);
    }
    while(idx != c_idx_not_exist);
  }

  int_string_map_s_clear(&map);

  return 0;
}

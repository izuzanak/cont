
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

#define INIT_ARRAY \
.size = 0,\
.used = 0,\
.data = NULL

#define INIT_QUEUE \
.size = 0,\
.used = 0,\
.begin = 0,\
.data = NULL\

#define INIT_LIST \
.size = 0,\
.used = 0,\
.data = NULL,\
.free_idx = c_idx_not_exist,\
.first_idx = c_idx_not_exist,\
.last_idx = c_idx_not_exist

#define INIT_RB_TREE \
.size = 0,\
.used = 0,\
.data = NULL,\
.free_idx = c_idx_not_exist,\
.root_idx = c_idx_not_exist,\
.leaf_idx = c_idx_not_exist

#define INIT_SAFE_LIST \
.size = 0,\
.used = 0,\
.count = 0,\
.data = NULL,\
.free_idx = c_idx_not_exist,\
.first_idx = c_idx_not_exist,\
.last_idx = c_idx_not_exist

#define INIT_SAFE_RB_TREE \
.size = 0,\
.used = 0,\
.count = 0,\
.data = NULL,\
.free_idx = c_idx_not_exist,\
.root_idx = c_idx_not_exist,\
.leaf_idx = c_idx_not_exist

#define CONT_INIT(TYPE,NAME) \
  TYPE NAME;\
  TYPE ## _init(&NAME);

#define CONT_CLEAR(TYPE,NAME) \
  __attribute__((cleanup(TYPE ## _clear))) TYPE NAME;

#define CONT_INIT_CLEAR(TYPE,NAME) \
  __attribute__((cleanup(TYPE ## _clear))) TYPE NAME;\
  TYPE ## _init(&NAME);



#ifndef __RB_TREE_H
#define __RB_TREE_H


#ifndef __STRUCT_H
#define __STRUCT_H


#ifndef __BASE_H
#define __BASE_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"
#include "math.h"

#define ENABLED 1

// - functions used by generated code of containers -
#define debug_assert assert
#define cmalloc malloc
#define crealloc realloc
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

static inline void record_s_init(record_s *this);
static inline void record_s_clear(record_s *this);
static inline void record_s_set(record_s *this,unsigned a_index,unsigned a_value);
static inline void record_s_flush_all(record_s *this);
static inline void record_s_swap(record_s *this,record_s *a_second);
static inline void record_s_copy(record_s *this,record_s *a_src);
static inline int record_s_compare(record_s *this,record_s *a_second);
#if OPTION_TO_STRING == ENABLED
static inline void record_s_to_string(record_s *this,bc_array_s *a_trg);
#endif

inline unsigned record_s_get_index();
inline unsigned record_s_get_value();




/*
 * inline methods of generated structures
 */

// -- record_s --
// --- struct record_s inline method definition ---

static inline void record_s_init(record_s *this)
{/*{{{*/
}/*}}}*/

static inline void record_s_clear(record_s *this)
{/*{{{*/

  record_s_init(this);
}/*}}}*/

static inline void record_s_set(record_s *this,unsigned a_index,unsigned a_value)
{/*{{{*/
  this->index = a_index;
  this->value = a_value;
}/*}}}*/

static inline void record_s_flush_all(record_s *this)
{/*{{{*/
}/*}}}*/

static inline void record_s_swap(record_s *this,record_s *a_second)
{/*{{{*/
  unsigned tmp_index = this->index;
  this->index = a_second->index;
  a_second->index = tmp_index;

  unsigned tmp_value = this->value;
  this->value = a_second->value;
  a_second->value = tmp_value;
}/*}}}*/

static inline void record_s_copy(record_s *this,record_s *a_src)
{/*{{{*/
  this->index = a_src->index;
  this->value = a_src->value;
}/*}}}*/

static inline int record_s_compare(record_s *this,record_s *a_second)
{/*{{{*/
  return (this->index == a_second->index && this->value == a_second->value);
}/*}}}*/

#if OPTION_TO_STRING == ENABLED
static inline void record_s_to_string(record_s *this,bc_array_s *a_trg)
{/*{{{*/
  bc_array_s_push(a_trg,'{');
  unsigned_to_string(&this->index,a_trg);
  bc_array_s_push(a_trg,',');
  unsigned_to_string(&this->value,a_trg);
  bc_array_s_push(a_trg,'}');
}/*}}}*/
#endif



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



//#define FIXED_BUFFER

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

static inline void ui_array_s_init(ui_array_s *this);
static inline void ui_array_s_init_size(ui_array_s *this,unsigned a_size);
static inline void ui_array_s_clear(ui_array_s *this);
static inline void ui_array_s_set(ui_array_s *this,unsigned a_used,unsigned *a_data);
static inline void ui_array_s_flush(ui_array_s *this);
static inline void ui_array_s_flush_all(ui_array_s *this);
static inline void ui_array_s_swap(ui_array_s *this,ui_array_s *a_second);
static inline unsigned *ui_array_s_at(ui_array_s *this,unsigned a_idx);
static inline void ui_array_s_push(ui_array_s *this,unsigned a_value);
static inline void ui_array_s_push_blank(ui_array_s *this);
void ui_array_s_reserve(ui_array_s *this,unsigned a_cnt);
void ui_array_s_push_blanks(ui_array_s *this,unsigned a_cnt);
static inline void ui_array_s_push_clear(ui_array_s *this);
static inline unsigned ui_array_s_pop(ui_array_s *this);
static inline unsigned *ui_array_s_last(ui_array_s *this);
void ui_array_s_copy_resize(ui_array_s *this,unsigned a_size);
void ui_array_s_fill(ui_array_s *this,unsigned a_value);
unsigned ui_array_s_get_idx(ui_array_s *this,unsigned a_value);
static inline void ui_array_s_copy(ui_array_s *this,ui_array_s *a_src);
static inline int ui_array_s_compare(ui_array_s *this,ui_array_s *a_second);
#if OPTION_TO_STRING == ENABLED
void ui_array_s_to_string(ui_array_s *this,bc_array_s *a_trg);
#endif



// -- rec_rb_tree_s --
// struct rec_rb_tree_s definition

typedef struct rec_rb_tree_s_node rec_rb_tree_s_node;
typedef struct rec_rb_tree_s rec_rb_tree_s;

struct rec_rb_tree_s_node
{
  record_s object;
  unsigned parent_idx;
  unsigned left_idx;
  unsigned right_idx;
  char color;
};

struct rec_rb_tree_s
{
  unsigned size;
  unsigned used;
  rec_rb_tree_s_node *data;
  unsigned free_idx;
  unsigned root_idx;
  unsigned leaf_idx;
};

static inline unsigned rec_rb_tree_s___get_grandparent_idx(rec_rb_tree_s *this,unsigned a_idx);
static inline unsigned rec_rb_tree_s___get_uncle_idx(rec_rb_tree_s *this,unsigned a_idx);
static inline unsigned rec_rb_tree_s___get_sibling_idx(rec_rb_tree_s *this,unsigned a_idx);
static inline unsigned rec_rb_tree_s_get_descent_stack_size(rec_rb_tree_s *this);
unsigned rec_rb_tree_s_get_stack_min_value_idx(rec_rb_tree_s *this,unsigned a_idx,unsigned **a_s_ptr);
static inline unsigned rec_rb_tree_s_get_stack_next_idx(rec_rb_tree_s *this,unsigned a_idx,unsigned **a_s_ptr,unsigned *a_stack_base);
unsigned rec_rb_tree_s_get_min_value_idx(rec_rb_tree_s *this,unsigned a_idx);
unsigned rec_rb_tree_s_get_max_value_idx(rec_rb_tree_s *this,unsigned a_idx);
unsigned rec_rb_tree_s_get_next_idx(rec_rb_tree_s *this,unsigned a_idx);
unsigned rec_rb_tree_s_get_prev_idx(rec_rb_tree_s *this,unsigned a_idx);
static inline void rec_rb_tree_s___rotate_left(rec_rb_tree_s *this,unsigned a_idx);
static inline void rec_rb_tree_s___rotate_right(rec_rb_tree_s *this,unsigned a_idx);
static inline unsigned rec_rb_tree_s___get_new_index(rec_rb_tree_s *this);
unsigned rec_rb_tree_s___binary_tree_insert(rec_rb_tree_s *this,unsigned a_new_idx,record_s *a_value,int a_unique);
static inline void rec_rb_tree_s___replace_delete_node_by_child(rec_rb_tree_s *this,unsigned a_idx,unsigned a_ch_idx);
void rec_rb_tree_s___remove_black_black(rec_rb_tree_s *this,unsigned a_idx);
static inline void rec_rb_tree_s___remove_one_child(rec_rb_tree_s *this,unsigned a_idx,unsigned a_ch_idx);
void rec_rb_tree_s___insert_operation(rec_rb_tree_s *this,unsigned a_idx);
static inline int rec_rb_tree_s___compare_value(rec_rb_tree_s *this,record_s *a_first,record_s *a_second);
static inline void rec_rb_tree_s_init(rec_rb_tree_s *this);
static inline void rec_rb_tree_s_clear(rec_rb_tree_s *this);
static inline void rec_rb_tree_s_flush(rec_rb_tree_s *this);
static inline void rec_rb_tree_s_flush_all(rec_rb_tree_s *this);
static inline void rec_rb_tree_s_swap(rec_rb_tree_s *this,rec_rb_tree_s *a_second);
static inline record_s *rec_rb_tree_s_at(rec_rb_tree_s *this,unsigned a_idx);
static inline unsigned rec_rb_tree_s_insert(rec_rb_tree_s *this,record_s *a_value);
static inline unsigned rec_rb_tree_s_unique_insert(rec_rb_tree_s *this,record_s *a_value);
static inline unsigned rec_rb_tree_s_swap_insert(rec_rb_tree_s *this,record_s *a_value);
static inline unsigned rec_rb_tree_s_unique_swap_insert(rec_rb_tree_s *this,record_s *a_value);
void rec_rb_tree_s_remove(rec_rb_tree_s *this,unsigned a_idx);
void rec_rb_tree_s_copy_resize(rec_rb_tree_s *this,unsigned a_size);
unsigned rec_rb_tree_s_get_idx(rec_rb_tree_s *this,record_s *a_value);
unsigned rec_rb_tree_s_get_idx_left(rec_rb_tree_s *this,record_s *a_value);
unsigned rec_rb_tree_s_get_gre_idx(rec_rb_tree_s *this,record_s *a_value);
unsigned rec_rb_tree_s_get_lee_idx(rec_rb_tree_s *this,record_s *a_value);
void rec_rb_tree_s_get_idxs(rec_rb_tree_s *this,record_s *a_value,ui_array_s *a_idxs_array);
static inline void rec_rb_tree_s_copy(rec_rb_tree_s *this,rec_rb_tree_s *a_src);
int rec_rb_tree_s_compare(rec_rb_tree_s *this,rec_rb_tree_s *a_second);
#if OPTION_TO_STRING == ENABLED
void rec_rb_tree_s_to_string(rec_rb_tree_s *this,bc_array_s *a_trg);
#endif
void rec_rb_tree_s_rehash_tree(rec_rb_tree_s *this);



/*
 * inline methods of generated structures
 */

// -- ui_array_s --
// --- struct ui_array_s inline method definition ---

static inline void ui_array_s_init(ui_array_s *this)
{/*{{{*/
  this->size = 0;
  this->used = 0;
  this->data = NULL;
}/*}}}*/

static inline void ui_array_s_init_size(ui_array_s *this,unsigned a_size)
{/*{{{*/
  ui_array_s_init(this);
  ui_array_s_copy_resize(this,a_size);
}/*}}}*/

static inline void ui_array_s_clear(ui_array_s *this)
{/*{{{*/
  if (this->data != NULL)
  {
    cfree(this->data);
  }

  ui_array_s_init(this);
}/*}}}*/

static inline void ui_array_s_set(ui_array_s *this,unsigned a_used,unsigned *a_data)
{/*{{{*/
  debug_assert(a_data != NULL);

  ui_array_s_clear(this);

  if (a_used == 0)
  {
    return;
  }

  ui_array_s_copy_resize(this,a_used);

  memcpy(this->data,a_data,a_used*sizeof(unsigned));
  this->used = a_used;
}/*}}}*/

static inline void ui_array_s_flush(ui_array_s *this)
{/*{{{*/
  ui_array_s_copy_resize(this,this->used);
}/*}}}*/

static inline void ui_array_s_flush_all(ui_array_s *this)
{/*{{{*/
  ui_array_s_copy_resize(this,this->used);
}/*}}}*/

static inline void ui_array_s_swap(ui_array_s *this,ui_array_s *a_second)
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

static inline unsigned *ui_array_s_at(ui_array_s *this,unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < this->used);
  return this->data + a_idx;
}/*}}}*/

static inline void ui_array_s_push(ui_array_s *this,unsigned a_value)
{/*{{{*/
  if (this->used >= this->size)
  {
    ui_array_s_copy_resize(this,(this->size << 1) + c_array_add);
  }

  this->data[this->used++] = a_value;
}/*}}}*/

static inline void ui_array_s_push_blank(ui_array_s *this)
{/*{{{*/
  if (this->used >= this->size)
  {
    ui_array_s_copy_resize(this,(this->size << 1) + c_array_add);
  }

  this->used++;
}/*}}}*/

static inline void ui_array_s_push_clear(ui_array_s *this)
{/*{{{*/
  if (this->used >= this->size)
  {
    ui_array_s_copy_resize(this,(this->size << 1) + c_array_add);
  }

  this->used++;
}/*}}}*/

static inline unsigned ui_array_s_pop(ui_array_s *this)
{/*{{{*/
  debug_assert(this->used > 0);
  return this->data[--this->used];
}/*}}}*/

static inline unsigned *ui_array_s_last(ui_array_s *this)
{/*{{{*/
  debug_assert(this->used > 0);
  return this->data + this->used - 1;
}/*}}}*/

static inline void ui_array_s_copy(ui_array_s *this,ui_array_s *a_src)
{/*{{{*/
  ui_array_s_clear(this);

  if (a_src->used == 0)
  {
    return;
  }

  ui_array_s_copy_resize(this,a_src->used);

  memcpy(this->data,a_src->data,a_src->used*sizeof(unsigned));

  this->used = a_src->used;
}/*}}}*/

static inline int ui_array_s_compare(ui_array_s *this,ui_array_s *a_second)
{/*{{{*/
  if (this->used != a_second->used)
  {
    return 0;
  }

  if (this->used == 0)
  {
    return 1;
  }

  return (memcmp(this->data,a_second->data,this->used*sizeof(unsigned)) == 0);
}/*}}}*/



// -- rec_rb_tree_s --
// --- struct rec_rb_tree_s inline method definition ---

static inline unsigned rec_rb_tree_s___get_grandparent_idx(rec_rb_tree_s *this,unsigned a_idx)
{/*{{{*/
  rec_rb_tree_s_node *node = this->data + a_idx;

  if (node->parent_idx != c_idx_not_exist)
  {
    return this->data[node->parent_idx].parent_idx;
  }

  return c_idx_not_exist;
}/*}}}*/

static inline unsigned rec_rb_tree_s___get_uncle_idx(rec_rb_tree_s *this,unsigned a_idx)
{/*{{{*/
  unsigned gp_idx = rec_rb_tree_s___get_grandparent_idx(this,a_idx);

  if (gp_idx != c_idx_not_exist)
  {
    rec_rb_tree_s_node *gp = this->data + gp_idx;
    return gp->left_idx == this->data[a_idx].parent_idx?gp->right_idx:gp->left_idx;
  }

  return c_idx_not_exist;
}/*}}}*/

static inline unsigned rec_rb_tree_s___get_sibling_idx(rec_rb_tree_s *this,unsigned a_idx)
{/*{{{*/
  rec_rb_tree_s_node *p = this->data + this->data[a_idx].parent_idx;
  return p->left_idx == a_idx?p->right_idx:p->left_idx;
}/*}}}*/

static inline unsigned rec_rb_tree_s_get_descent_stack_size(rec_rb_tree_s *this)
{/*{{{*/
  return (unsigned)(logf(this->used)/c_log_of_2) << 1;
}/*}}}*/

static inline unsigned rec_rb_tree_s_get_stack_next_idx(rec_rb_tree_s *this,unsigned a_idx,unsigned **a_s_ptr,unsigned *a_stack_base)
{/*{{{*/
  debug_assert(a_idx < this->used);

  rec_rb_tree_s_node *node = this->data + a_idx;

  if (node->right_idx != this->leaf_idx)
  {
    return rec_rb_tree_s_get_stack_min_value_idx(this,node->right_idx,a_s_ptr);
  }

  if (*a_s_ptr > a_stack_base)
  {
    return *(--(*a_s_ptr));
  }

  return c_idx_not_exist;
}/*}}}*/

static inline void rec_rb_tree_s___rotate_left(rec_rb_tree_s *this,unsigned a_idx)
{/*{{{*/
  rec_rb_tree_s_node *root = this->data + a_idx;
  rec_rb_tree_s_node *pivot = this->data + root->right_idx;

  if (a_idx == this->root_idx)
  {
    this->root_idx = root->right_idx;
    pivot->parent_idx = c_idx_not_exist;
  }
  else
  {
    rec_rb_tree_s_node *rp = this->data + root->parent_idx;

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

static inline void rec_rb_tree_s___rotate_right(rec_rb_tree_s *this,unsigned a_idx)
{/*{{{*/
  rec_rb_tree_s_node *root = this->data + a_idx;
  rec_rb_tree_s_node *pivot = this->data + root->left_idx;

  if (a_idx == this->root_idx)
  {
    this->root_idx = root->left_idx;
    pivot->parent_idx = c_idx_not_exist;
  }
  else
  {
    rec_rb_tree_s_node *rp = this->data + root->parent_idx;

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

static inline unsigned rec_rb_tree_s___get_new_index(rec_rb_tree_s *this)
{/*{{{*/
  if (this->free_idx != c_idx_not_exist)
  {
    unsigned new_idx = this->free_idx;
    this->free_idx = this->data[new_idx].parent_idx;

    return new_idx;
  }

  if (this->used >= this->size)
  {
    rec_rb_tree_s_copy_resize(this,(this->size << 1) + c_array_add);
  }

  return this->used++;
}/*}}}*/

static inline void rec_rb_tree_s___replace_delete_node_by_child(rec_rb_tree_s *this,unsigned a_idx,unsigned a_ch_idx)
{/*{{{*/
  rec_rb_tree_s_node *node = this->data + a_idx;

  if (node->parent_idx != c_idx_not_exist)
  {
    rec_rb_tree_s_node *parent = this->data + node->parent_idx;

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
  else
  {
    this->root_idx = a_ch_idx == this->leaf_idx?c_idx_not_exist:a_ch_idx;
    this->data[a_ch_idx].parent_idx = c_idx_not_exist;
  }
}/*}}}*/

static inline void rec_rb_tree_s___remove_one_child(rec_rb_tree_s *this,unsigned a_idx,unsigned a_ch_idx)
{/*{{{*/
  rec_rb_tree_s_node *node = this->data + a_idx;
  rec_rb_tree_s___replace_delete_node_by_child(this,a_idx,a_ch_idx);

  node->parent_idx = this->free_idx;
  this->free_idx = a_idx;

  if (node->color)
  {
    rec_rb_tree_s_node *child_node = this->data + a_ch_idx;

    if (!child_node->color)
    {
      child_node->color = 1;
    }
    else
    {
      rec_rb_tree_s___remove_black_black(this,a_ch_idx);
    }
  }
}/*}}}*/

static inline void rec_rb_tree_s_init(rec_rb_tree_s *this)
{/*{{{*/
  this->size = 0;
  this->used = 0;
  this->data = NULL;
  this->free_idx = c_idx_not_exist;
  this->root_idx = c_idx_not_exist;
  this->leaf_idx = c_idx_not_exist;
}/*}}}*/

static inline void rec_rb_tree_s_clear(rec_rb_tree_s *this)
{/*{{{*/
  if (this->data != NULL)
  {
    cfree(this->data);
  }

  rec_rb_tree_s_init(this);
}/*}}}*/

static inline void rec_rb_tree_s_flush(rec_rb_tree_s *this)
{/*{{{*/
  rec_rb_tree_s_copy_resize(this,this->used);
}/*}}}*/

static inline void rec_rb_tree_s_flush_all(rec_rb_tree_s *this)
{/*{{{*/
  rec_rb_tree_s_copy_resize(this,this->used);
}/*}}}*/

static inline void rec_rb_tree_s_swap(rec_rb_tree_s *this,rec_rb_tree_s *a_second)
{/*{{{*/
  unsigned tmp_unsigned = this->size;
  this->size = a_second->size;
  a_second->size = tmp_unsigned;

  tmp_unsigned = this->used;
  this->used = a_second->used;
  a_second->used = tmp_unsigned;

  rec_rb_tree_s_node *tmp_data = this->data;
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

static inline record_s *rec_rb_tree_s_at(rec_rb_tree_s *this,unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < this->used);
  return &this->data[a_idx].object;
}/*}}}*/

static inline unsigned rec_rb_tree_s_insert(rec_rb_tree_s *this,record_s *a_value)
{/*{{{*/
  unsigned new_node_idx = rec_rb_tree_s___get_new_index(this);

  rec_rb_tree_s___binary_tree_insert(this,new_node_idx,a_value,0);
  rec_rb_tree_s___insert_operation(this,new_node_idx);

  record_s_copy(&this->data[new_node_idx].object,a_value);

  return new_node_idx;
}/*}}}*/

static inline unsigned rec_rb_tree_s_swap_insert(rec_rb_tree_s *this,record_s *a_value)
{/*{{{*/
  unsigned new_node_idx = rec_rb_tree_s___get_new_index(this);

  rec_rb_tree_s___binary_tree_insert(this,new_node_idx,a_value,0);
  rec_rb_tree_s___insert_operation(this,new_node_idx);

  record_s_swap(&this->data[new_node_idx].object,a_value);

  return new_node_idx;
}/*}}}*/

static inline unsigned rec_rb_tree_s_unique_insert(rec_rb_tree_s *this,record_s *a_value)
{/*{{{*/
  unsigned new_node_idx = rec_rb_tree_s___get_new_index(this);
  unsigned old_node_idx = rec_rb_tree_s___binary_tree_insert(this,new_node_idx,a_value,1);

  if (old_node_idx != c_idx_not_exist)
  {
    rec_rb_tree_s_node *new_node = this->data + new_node_idx;

    new_node->parent_idx = this->free_idx;
    this->free_idx = new_node_idx;

    return old_node_idx;
  }

  rec_rb_tree_s___insert_operation(this,new_node_idx);

  record_s_copy(&this->data[new_node_idx].object,a_value);

  return new_node_idx;
}/*}}}*/

static inline unsigned rec_rb_tree_s_unique_swap_insert(rec_rb_tree_s *this,record_s *a_value)
{/*{{{*/
  unsigned new_node_idx = rec_rb_tree_s___get_new_index(this);
  unsigned old_node_idx = rec_rb_tree_s___binary_tree_insert(this,new_node_idx,a_value,1);

  if (old_node_idx != c_idx_not_exist)
  {
    rec_rb_tree_s_node *new_node = this->data + new_node_idx;

    new_node->parent_idx = this->free_idx;
    this->free_idx = new_node_idx;

    return old_node_idx;
  }

  rec_rb_tree_s___insert_operation(this,new_node_idx);

  record_s_swap(&this->data[new_node_idx].object,a_value);

  return new_node_idx;
}/*}}}*/

static inline void rec_rb_tree_s_copy(rec_rb_tree_s *this,rec_rb_tree_s *a_src)
{/*{{{*/
  rec_rb_tree_s_clear(this);

  if (a_src->root_idx == c_idx_not_exist)
  {
    return;
  }

  rec_rb_tree_s_copy_resize(this,a_src->used);

  memcpy(this->data,a_src->data,a_src->used*sizeof(rec_rb_tree_s_node));

  this->used = a_src->used;
  this->free_idx = a_src->free_idx;
  this->root_idx = a_src->root_idx;
  this->leaf_idx = a_src->leaf_idx;
}/*}}}*/



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



/*
 * methods of generated structures
 */

// -- ui_array_s --
// --- struct ui_array_s method definition ---

void ui_array_s_reserve(ui_array_s *this,unsigned a_cnt)
{/*{{{*/
  unsigned required_cnt = this->used + a_cnt;
  if (required_cnt > this->size)
  {
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
  if (required_cnt > this->size)
  {
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

  if (a_size == 0)
  {
    if (this->data != NULL)
    {
      cfree(this->data);
    }
    this->data = NULL;
  }
  else
  {
    this->data = (unsigned *)crealloc(this->data,a_size*sizeof(unsigned));
  }

  this->size = a_size;
}/*}}}*/

void ui_array_s_fill(ui_array_s *this,unsigned a_value)
{/*{{{*/
  if (this->size == 0)
  {
    return;
  }

  unsigned *ptr = this->data;
  unsigned *ptr_end = this->data + this->size;

  do {
    *ptr = a_value;
  } while(++ptr < ptr_end);

  this->used = this->size;
}/*}}}*/

unsigned ui_array_s_get_idx(ui_array_s *this,unsigned a_value)
{/*{{{*/
  if (this->used == 0)
  {
    return c_idx_not_exist;
  }

  unsigned *ptr = this->data;
  unsigned *ptr_end = this->data + this->used;

  do {
    if (*ptr == a_value)
    {
      return ptr - this->data;
    }
  } while(++ptr < ptr_end);

  return c_idx_not_exist;
}/*}}}*/

#if OPTION_TO_STRING == ENABLED
void ui_array_s_to_string(ui_array_s *this,bc_array_s *a_trg)
{/*{{{*/
  bc_array_s_push(a_trg,'[');

  if (this->used != 0)
  {
    unsigned *ptr = this->data;
    unsigned *ptr_end = this->data + this->used;

    do {
      unsigned_to_string(ptr,a_trg);

      if (++ptr >= ptr_end)
      {
        break;
      }

      bc_array_s_push(a_trg,',');
    } while(1);
  }

  bc_array_s_push(a_trg,']');
}/*}}}*/
#endif



// -- rec_rb_tree_s --
// --- struct rec_rb_tree_s method definition ---

unsigned rec_rb_tree_s_get_stack_min_value_idx(rec_rb_tree_s *this,unsigned a_idx,unsigned **a_s_ptr)
{/*{{{*/
  debug_assert(a_idx < this->used);

  unsigned node_idx = a_idx;
  do {
    rec_rb_tree_s_node *node = this->data + node_idx;

    if (node->left_idx == this->leaf_idx)
    {
      return node_idx;
    }

    *((*a_s_ptr)++) = node_idx;
    node_idx = node->left_idx;
  } while(1);
}/*}}}*/

unsigned rec_rb_tree_s_get_min_value_idx(rec_rb_tree_s *this,unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < this->used);

  unsigned node_idx = a_idx;
  do {
    rec_rb_tree_s_node *node = this->data + node_idx;

    if (node->left_idx == this->leaf_idx)
    {
      return node_idx;
    }

    node_idx = node->left_idx;
  } while(1);
}/*}}}*/

unsigned rec_rb_tree_s_get_max_value_idx(rec_rb_tree_s *this,unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < this->used);

  unsigned node_idx = a_idx;
  do {
    rec_rb_tree_s_node *node = this->data + node_idx;

    if (node->right_idx == this->leaf_idx)
    {
      return node_idx;
    }

    node_idx = node->right_idx;
  } while(1);
}/*}}}*/

unsigned rec_rb_tree_s_get_next_idx(rec_rb_tree_s *this,unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < this->used);

  rec_rb_tree_s_node *node = this->data + a_idx;

  if (node->right_idx != this->leaf_idx)
  {
    return rec_rb_tree_s_get_min_value_idx(this,node->right_idx);
  }

  unsigned node_idx = a_idx;
  do {
    rec_rb_tree_s_node *node = this->data + node_idx;

    if (node->parent_idx == c_idx_not_exist)
    {
      return c_idx_not_exist;
    }

    if (this->data[node->parent_idx].right_idx != node_idx)
    {
      return node->parent_idx;
    }

    node_idx = node->parent_idx;
  } while(1);
}/*}}}*/

unsigned rec_rb_tree_s_get_prev_idx(rec_rb_tree_s *this,unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < this->used);

  rec_rb_tree_s_node *node = this->data + a_idx;

  if (node->left_idx != this->leaf_idx)
  {
    return rec_rb_tree_s_get_max_value_idx(this,node->left_idx);
  }

  unsigned node_idx = a_idx;
  do {
    rec_rb_tree_s_node *node = this->data + node_idx;

    if (node->parent_idx == c_idx_not_exist)
    {
      return c_idx_not_exist;
    }

    if (this->data[node->parent_idx].left_idx != node_idx)
    {
      return node->parent_idx;
    }

    node_idx = node->parent_idx;
  } while(1);
}/*}}}*/

unsigned rec_rb_tree_s___binary_tree_insert(rec_rb_tree_s *this,unsigned a_new_idx,record_s *a_value,int a_unique)
{/*{{{*/
  if (this->root_idx == c_idx_not_exist)
  {
    if (this->leaf_idx == c_idx_not_exist)
    {
      this->leaf_idx = rec_rb_tree_s___get_new_index(this);
      rec_rb_tree_s_node *leaf = this->data + this->leaf_idx;

      leaf->color = 1;

#ifdef RB_TREE_SET_LEAF_CHILDS
      leaf->left_idx = c_idx_not_exist;
      leaf->right_idx = c_idx_not_exist;
#endif
    }

    this->data[a_new_idx].parent_idx = c_idx_not_exist;
    this->root_idx = a_new_idx;
  }
  else
  {
    unsigned node_idx = this->root_idx;
    do {
      rec_rb_tree_s_node *node = this->data + node_idx;

      int comp_result = rec_rb_tree_s___compare_value(this,a_value,&node->object);
      if (comp_result < 0)
      {
        if (node->left_idx == this->leaf_idx)
        {
          node->left_idx = a_new_idx;
          break;
        }
        node_idx = node->left_idx;
      }
      else
      {
        if (a_unique && comp_result == 0)
        {
          return node_idx;
        }

        if (node->right_idx == this->leaf_idx)
        {
          node->right_idx = a_new_idx;
          break;
        }
        node_idx = node->right_idx;
      }
    } while(1);

    this->data[a_new_idx].parent_idx = node_idx;
  }

  rec_rb_tree_s_node *new_node = this->data + a_new_idx;
  new_node->left_idx = this->leaf_idx;
  new_node->right_idx = this->leaf_idx;
  new_node->color = 0;

  return c_idx_not_exist;
}/*}}}*/

void rec_rb_tree_s___remove_black_black(rec_rb_tree_s *this,unsigned a_idx)
{/*{{{*/
  unsigned node_idx = a_idx;
  do {
    rec_rb_tree_s_node *node = this->data + node_idx;

    if (node->parent_idx == c_idx_not_exist)
    {
      return;
    }

    unsigned parent_idx = node->parent_idx;
    rec_rb_tree_s_node *parent = this->data + parent_idx;

    {
      unsigned sibling_idx = parent->left_idx == node_idx?parent->right_idx:parent->left_idx;
      rec_rb_tree_s_node *sibling = this->data + sibling_idx;

      if (!sibling->color)
      {
        parent->color = 0;
        sibling->color = 1;

        if (node_idx == parent->left_idx)
        {
          rec_rb_tree_s___rotate_left(this,parent_idx);
        }
        else
        {
          rec_rb_tree_s___rotate_right(this,parent_idx);
        }
      }
    }

    {
      unsigned sibling_idx = parent->left_idx == node_idx?parent->right_idx:parent->left_idx;
      rec_rb_tree_s_node* sibling = this->data + sibling_idx;

      if (parent->color && sibling->color && this->data[sibling->left_idx].color && this->data[sibling->right_idx].color)
      {
        sibling->color = 0;
        node_idx = parent_idx;
        continue;
      }
      else if (!parent->color && sibling->color && this->data[sibling->left_idx].color && this->data[sibling->right_idx].color)
      {
        sibling->color = 0;
        parent->color = 1;
        return;
      }
      else if (sibling->color)
      {
        if (node_idx == parent->left_idx && this->data[sibling->right_idx].color && !this->data[sibling->left_idx].color)
        {
          sibling->color = 0;
          this->data[sibling->left_idx].color = 1;
          rec_rb_tree_s___rotate_right(this,sibling_idx);
        }
        else if (node_idx == parent->right_idx && this->data[sibling->left_idx].color && !this->data[sibling->right_idx].color)
        {
          sibling->color = 0;
          this->data[sibling->right_idx].color = 1;
          rec_rb_tree_s___rotate_left(this,sibling_idx);
        }
      }

      {
        unsigned sibling_idx = parent->left_idx == node_idx?parent->right_idx:parent->left_idx;
        rec_rb_tree_s_node *sibling = this->data + sibling_idx;

        sibling->color = parent->color;
        parent->color = 1;

        if (node_idx == parent->left_idx)
        {
          this->data[sibling->right_idx].color = 1;
          rec_rb_tree_s___rotate_left(this,parent_idx);
        }
        else
        {
          this->data[sibling->left_idx].color = 1;
          rec_rb_tree_s___rotate_right(this,parent_idx);
        }
      }

      return;
    }

  } while(1);
}/*}}}*/

void rec_rb_tree_s___insert_operation(rec_rb_tree_s *this,unsigned a_idx)
{/*{{{*/
  unsigned node_idx = a_idx;
  do {
    rec_rb_tree_s_node *node = this->data + node_idx;

    if (node->parent_idx == c_idx_not_exist)
    {
      node->color = 1;
      return;
    }

    if (this->data[node->parent_idx].color)
    {
      return;
    }

    unsigned uncle_idx = rec_rb_tree_s___get_uncle_idx(this,node_idx);
    if (uncle_idx != c_idx_not_exist && !this->data[uncle_idx].color)
    {
      this->data[node->parent_idx].color = 1;
      this->data[uncle_idx].color = 1;

      node_idx = rec_rb_tree_s___get_grandparent_idx(this,node_idx);
      this->data[node_idx].color = 0;

      continue;
    }
    else
    {
      unsigned grandparent_idx = rec_rb_tree_s___get_grandparent_idx(this,node_idx);

      if (node_idx == this->data[node->parent_idx].right_idx && node->parent_idx == this->data[grandparent_idx].left_idx)
      {
        rec_rb_tree_s___rotate_left(this,node->parent_idx);
        node_idx = node->left_idx;
      }
      else if (node_idx == this->data[node->parent_idx].left_idx && node->parent_idx == this->data[grandparent_idx].right_idx)
      {
        rec_rb_tree_s___rotate_right(this,node->parent_idx);
        node_idx = node->right_idx;
      }

      {
        unsigned grandparent_idx = rec_rb_tree_s___get_grandparent_idx(this,node_idx);
        rec_rb_tree_s_node *node = this->data + node_idx;

        this->data[node->parent_idx].color = 1;
        this->data[grandparent_idx].color = 0;

        if (node_idx == this->data[node->parent_idx].left_idx && node->parent_idx == this->data[grandparent_idx].left_idx)
        {
          rec_rb_tree_s___rotate_right(this,grandparent_idx);
        }
        else
        {
          rec_rb_tree_s___rotate_left(this,grandparent_idx);
        }
      }

      return;
    }
  } while(1);
}/*}}}*/

void rec_rb_tree_s_remove(rec_rb_tree_s *this,unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < this->used);

  rec_rb_tree_s_node *del_node = this->data + a_idx;

  if (del_node->left_idx != this->leaf_idx)
  {
    if (del_node->right_idx != this->leaf_idx)
    {
      unsigned found_idx = del_node->right_idx;
      do {
        rec_rb_tree_s_node *node = this->data + found_idx;

        if (node->left_idx == this->leaf_idx)
        {
          break;
        }

        found_idx = node->left_idx;
      } while(1);

      rec_rb_tree_s_node *found_node = this->data + found_idx;

      /* - process del_node parent_idx - */
      if (del_node->parent_idx != c_idx_not_exist)
      {
        rec_rb_tree_s_node *del_node_parent = this->data + del_node->parent_idx;

        if (del_node_parent->left_idx == a_idx)
        {
          del_node_parent->left_idx = found_idx;
        }
        else
        {
          del_node_parent->right_idx = found_idx;
        }
      }
      else
      {
        this->root_idx = found_idx;
      }

      /* - process del_node left_idx - */
      this->data[del_node->left_idx].parent_idx = found_idx;

      /* - process found_node right_idx - */
      if (found_node->right_idx != this->leaf_idx)
      {
        this->data[found_node->right_idx].parent_idx = a_idx;
      }

      if (del_node->right_idx == found_idx)
      {
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
      else
      {
        /* - process found_node parent - */
        rec_rb_tree_s_node *found_node_parent = this->data + found_node->parent_idx;

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

      rec_rb_tree_s___remove_one_child(this,a_idx,del_node->right_idx);
    }
    else
    {
      rec_rb_tree_s___remove_one_child(this,a_idx,del_node->left_idx);
    }
  }
  else
  {
    rec_rb_tree_s___remove_one_child(this,a_idx,del_node->right_idx);
  }

}/*}}}*/

void rec_rb_tree_s_copy_resize(rec_rb_tree_s *this,unsigned a_size)
{/*{{{*/
  debug_assert(a_size >= this->used);

  if (a_size == 0)
  {
    if (this->data != NULL)
    {
      cfree(this->data);
    }
    this->data = NULL;
  }
  else
  {
    this->data = (rec_rb_tree_s_node *)crealloc(this->data,a_size*sizeof(rec_rb_tree_s_node));
  }

  this->size = a_size;
}/*}}}*/

unsigned rec_rb_tree_s_get_idx(rec_rb_tree_s *this,record_s *a_value)
{/*{{{*/
  if (this->root_idx == c_idx_not_exist)
  {
    return c_idx_not_exist;
  }

  unsigned node_idx = this->root_idx;
  do {
    rec_rb_tree_s_node *node = this->data + node_idx;

    int comp_result = rec_rb_tree_s___compare_value(this,a_value,&node->object);
    if (comp_result < 0)
    {
      node_idx = node->left_idx;
    }
    else
    {
      if (comp_result == 0)
      {
        return node_idx;
      }

      node_idx = node->right_idx;
    }
  } while(node_idx != this->leaf_idx);

  return c_idx_not_exist;
}/*}}}*/

unsigned rec_rb_tree_s_get_idx_left(rec_rb_tree_s *this,record_s *a_value)
{/*{{{*/
  if (this->root_idx == c_idx_not_exist)
  {
    return c_idx_not_exist;
  }

  unsigned good_idx = c_idx_not_exist;
  unsigned node_idx = this->root_idx;
  do {
    rec_rb_tree_s_node *node = this->data + node_idx;

    int comp_result = rec_rb_tree_s___compare_value(this,a_value,&node->object);
    if (comp_result < 0)
    {
      node_idx = node->left_idx;
    }
    else
    {
      if (comp_result == 0)
      {
        good_idx = node_idx;
        node_idx = node->left_idx;
      }
      else
      {
        node_idx = node->right_idx;
      }
    }
  } while(node_idx != this->leaf_idx);

  return good_idx;
}/*}}}*/

unsigned rec_rb_tree_s_get_gre_idx(rec_rb_tree_s *this,record_s *a_value)
{/*{{{*/
  if (this->root_idx == c_idx_not_exist)
  {
    return c_idx_not_exist;
  }

  unsigned good_idx = c_idx_not_exist;
  unsigned node_idx = this->root_idx;
  do {
    rec_rb_tree_s_node *node = this->data + node_idx;

    int comp_result = rec_rb_tree_s___compare_value(this,a_value,&node->object);
    if (comp_result < 0)
    {
      good_idx = node_idx;
      node_idx = node->left_idx;
    }
    else
    {
      if (comp_result == 0)
      {
        return node_idx;
      }

      node_idx = node->right_idx;
    }
  } while(node_idx != this->leaf_idx);

  return good_idx;
}/*}}}*/

unsigned rec_rb_tree_s_get_lee_idx(rec_rb_tree_s *this,record_s *a_value)
{/*{{{*/
  if (this->root_idx == c_idx_not_exist)
  {
    return c_idx_not_exist;
  }

  unsigned good_idx = c_idx_not_exist;
  unsigned node_idx = this->root_idx;
  do {
    rec_rb_tree_s_node *node = this->data + node_idx;

    int comp_result = rec_rb_tree_s___compare_value(this,a_value,&node->object);
    if (comp_result < 0)
    {
      node_idx = node->left_idx;
    }
    else
    {
      if (comp_result == 0)
      {
        return node_idx;
      }

      good_idx = node_idx;
      node_idx = node->right_idx;
    }
  } while(node_idx != this->leaf_idx);

  return good_idx;
}/*}}}*/

void rec_rb_tree_s_get_idxs(rec_rb_tree_s *this,record_s *a_value,ui_array_s *a_idxs_array)
{/*{{{*/
  a_idxs_array->used = 0;

  if (this->root_idx == c_idx_not_exist)
  {
    return;
  }

  unsigned stack[rec_rb_tree_s_get_descent_stack_size(this)];
  unsigned *stack_ptr = stack;

  *(stack_ptr++) = this->root_idx;
  do {
    unsigned node_idx = *(--stack_ptr);
    rec_rb_tree_s_node *node = this->data + node_idx;

    int comp_result = rec_rb_tree_s___compare_value(this,a_value,&node->object);
    if (comp_result < 0)
    {
      if (node->left_idx != this->leaf_idx)
      {
        *(stack_ptr++) = node->left_idx;
      }
    }
    else
    {
      if (comp_result == 0)
      {
        ui_array_s_push(a_idxs_array,node_idx);

        if (node->left_idx != this->leaf_idx)
        {
          *(stack_ptr++) = node->left_idx;
        }
      }

      if (node->right_idx != this->leaf_idx)
      {
        *(stack_ptr++) = node->right_idx;
      }
    }
  } while(stack_ptr > stack);

  return;
}/*}}}*/

int rec_rb_tree_s_compare(rec_rb_tree_s *this,rec_rb_tree_s *a_second)
{/*{{{*/
  if (this->root_idx == c_idx_not_exist)
  {
    if (a_second->root_idx != c_idx_not_exist)
    {
      return 0;
    }
  }
  else
  {
    if (a_second->root_idx == c_idx_not_exist)
    {
      return 0;
    }

    unsigned stack[rec_rb_tree_s_get_descent_stack_size(this)];
    unsigned s_stack[rec_rb_tree_s_get_descent_stack_size(a_second)];

    unsigned *stack_ptr = stack;
    unsigned *s_stack_ptr = s_stack;

    unsigned node_idx = rec_rb_tree_s_get_stack_min_value_idx(this,this->root_idx,&stack_ptr);
    unsigned s_node_idx = rec_rb_tree_s_get_stack_min_value_idx(a_second,a_second->root_idx,&s_stack_ptr);
    do {
      if (!record_s_compare(&this->data[node_idx].object,&a_second->data[s_node_idx].object))
      {
        return 0;
      }

      node_idx = rec_rb_tree_s_get_stack_next_idx(this,node_idx,&stack_ptr,stack);
      s_node_idx = rec_rb_tree_s_get_stack_next_idx(a_second,s_node_idx,&s_stack_ptr,s_stack);
    } while(node_idx != c_idx_not_exist && s_node_idx != c_idx_not_exist);

    if (node_idx != s_node_idx)
    {
      return 0;
    }
  }

  return 1;
}/*}}}*/

#if OPTION_TO_STRING == ENABLED
void rec_rb_tree_s_to_string(rec_rb_tree_s *this,bc_array_s *a_trg)
{/*{{{*/
  bc_array_s_push(a_trg,'[');

  if (this->root_idx != c_idx_not_exist)
  {
    unsigned stack[rec_rb_tree_s_get_descent_stack_size(this)];
    unsigned *stack_ptr = stack;

    unsigned idx = rec_rb_tree_s_get_stack_min_value_idx(this,this->root_idx,&stack_ptr);
    do {
      record_s_to_string(&(this->data + idx)->object,a_trg);

      idx = rec_rb_tree_s_get_stack_next_idx(this,idx,&stack_ptr,stack);
      if (idx == c_idx_not_exist)
      {
        break;
      }

      bc_array_s_push(a_trg,',');
    } while(1);
  }

  bc_array_s_push(a_trg,']');
}/*}}}*/
#endif

void rec_rb_tree_s_rehash_tree(rec_rb_tree_s *this)
{/*{{{*/
  if (this->root_idx == c_idx_not_exist)
  {
    return;
  }

  ui_array_s indexes;
  ui_array_s_init(&indexes);

  {
    unsigned stack[rec_rb_tree_s_get_descent_stack_size(this)];
    unsigned *stack_ptr = stack;

    unsigned idx = rec_rb_tree_s_get_stack_min_value_idx(this,this->root_idx,&stack_ptr);
    do {
      ui_array_s_push(&indexes,idx);

      idx = rec_rb_tree_s_get_stack_next_idx(this,idx,&stack_ptr,stack);
    } while(idx != c_idx_not_exist);
  }

  this->root_idx = c_idx_not_exist;

  char *processed = (char *)cmalloc(indexes.used);
  memset(processed,0,indexes.used*sizeof(char));

  unsigned step = indexes.used >> 1;
  if (step > 0)
  {
    do {
      unsigned idx = step;
      do {
        if (!processed[idx])
        {
          unsigned node_idx = indexes.data[idx];

          rec_rb_tree_s___binary_tree_insert(this,node_idx,&this->data[node_idx].object,0);
          rec_rb_tree_s___insert_operation(this,node_idx);

          processed[idx] = 1;
        }
      } while((idx += step) < indexes.used);
    } while((step >>= 1) > 0);
  }

  unsigned node_idx = indexes.data[0];
  rec_rb_tree_s___binary_tree_insert(this,node_idx,&this->data[node_idx].object,0);
  rec_rb_tree_s___insert_operation(this,node_idx);

  cfree(processed);
  ui_array_s_clear(&indexes);
}/*}}}*/



/*
 * global methods
 */

void print_tree(rec_rb_tree_s *rec_tree,const char *name)
{
  printf("%s.size:  %u\n",name,rec_tree->size);
  printf("%s.used:  %u\n",name,rec_tree->used);
  printf("%s.free_idx: %u\n",name,rec_tree->free_idx);
  printf("%s.root_idx: %u\n",name,rec_tree->root_idx);
  printf("%s.leaf_idx: %u\n",name,rec_tree->leaf_idx);
  printf("%s: ",name);

  if (rec_tree->root_idx != c_idx_not_exist)
  {
    unsigned stack[rec_rb_tree_s_get_descent_stack_size(rec_tree)];
    unsigned *stack_ptr = stack;

    unsigned idx = rec_rb_tree_s_get_stack_min_value_idx(rec_tree,rec_tree->root_idx,&stack_ptr);
    do
    {
      record_s *rec = &rec_tree->data[idx].object;
      printf("{%u,%u}",rec->index,rec->value);

      idx = rec_rb_tree_s_get_stack_next_idx(rec_tree,idx,&stack_ptr,stack);
    }
    while(idx != c_idx_not_exist);
  }

  printf("\n");
  printf("\n");
}

int main(int argc, char **argv)
{
  record_s rec;
  record_s_init(&rec);
  record_s_set(&rec,1,1);

  rec_rb_tree_s rb_tree0;
#ifdef FIXED_BUFFER
  rec_rb_tree_s_init_buffer(&rb_tree0,10,alloca(10*sizeof(rec_rb_tree_s_node)));
#else
  rec_rb_tree_s_init(&rb_tree0);
#endif

  print_tree(&rb_tree0,"rb_tree0");

  printf("--- INSERT NEW RECORDS TO RB_TREE ---\n");
  
  unsigned idx = 0;
  do {
    rec.index = idx;
    rec_rb_tree_s_insert(&rb_tree0,&rec);
  } while(++idx < 7);

  print_tree(&rb_tree0,"rb_tree0");

  printf("--- REMOVE RECORDS FROM RB_TREE ---\n");
  
  idx = rec_rb_tree_s_get_min_value_idx(&rb_tree0,rb_tree0.root_idx);
  unsigned count = 0;
  do {
    unsigned next_idx = rec_rb_tree_s_get_next_idx(&rb_tree0,idx);
    rec_rb_tree_s_remove(&rb_tree0,idx);

    idx = next_idx;
  } while(++count < 3);

  print_tree(&rb_tree0,"rb_tree0");

  printf("--- INSERT NEW RECORDS TO RB_TREE ---\n");
  
  idx = 0;
  do {
    rec.index = idx + 4;
    rec_rb_tree_s_insert(&rb_tree0,&rec);
  } while(++idx < 4);

  print_tree(&rb_tree0,"rb_tree0");

  printf("--- CREATE NEW EMPTY RB_TREE ---\n");
  rec_rb_tree_s rb_tree1;
#ifdef FIXED_BUFFER
  rec_rb_tree_s_init_buffer(&rb_tree1,10,alloca(10*sizeof(rec_rb_tree_s_node)));
#else
  rec_rb_tree_s_init(&rb_tree1);
#endif

  print_tree(&rb_tree0,"rb_tree0");
  print_tree(&rb_tree1,"rb_tree1");

  printf("--- COMPARE RB_TREE CONTENT ---\n");
  printf("rec_rb_tree_s_compare(&rb_tree0,&rb_tree1): %s\n",rec_rb_tree_s_compare(&rb_tree0,&rb_tree1) ? "TRUE" : "FALSE");
  printf("\n");

  printf("--- ASSIGN RB_TREE CONTENT ---\n");
  rec_rb_tree_s_copy(&rb_tree1,&rb_tree0);

  print_tree(&rb_tree0,"rb_tree0");
  print_tree(&rb_tree1,"rb_tree1");

  printf("--- COMPARE RB_TREE CONTENT ---\n");
  printf("rec_rb_tree_s_compare(&rb_tree0,&rb_tree1): %s\n",rec_rb_tree_s_compare(&rb_tree0,&rb_tree1) ? "TRUE" : "FALSE");
  printf("\n");

  rec_rb_tree_s_clear(&rb_tree1);
  rec_rb_tree_s_clear(&rb_tree0);
  record_s_clear(&rec);

  return 0;
}


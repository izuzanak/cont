
typedef bool bb;
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
.data = nullptr

#define INIT_QUEUE \
.size = 0,\
.used = 0,\
.begin = 0,\
.data = nullptr\

#define INIT_LIST \
.size = 0,\
.used = 0,\
.data = nullptr,\
.free_idx = c_idx_not_exist,\
.first_idx = c_idx_not_exist,\
.last_idx = c_idx_not_exist

#define INIT_RB_TREE \
.size = 0,\
.used = 0,\
.data = nullptr,\
.free_idx = c_idx_not_exist,\
.root_idx = c_idx_not_exist,\
.leaf_idx = c_idx_not_exist

#define INIT_SAFE_LIST \
.size = 0,\
.used = 0,\
.count = 0,\
.data = nullptr,\
.free_idx = c_idx_not_exist,\
.first_idx = c_idx_not_exist,\
.last_idx = c_idx_not_exist

#define INIT_SAFE_RB_TREE \
.size = 0,\
.used = 0,\
.count = 0,\
.data = nullptr,\
.free_idx = c_idx_not_exist,\
.root_idx = c_idx_not_exist,\
.leaf_idx = c_idx_not_exist



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
#define crealloc realloc
#define cfree free

// - constants used by generated code of containers -
const unsigned c_array_add = 64;
const unsigned c_idx_not_exist = 0xffffffff;

// - logarithm of two (needed by red-black tree container) -
const float c_log_of_2 = logf(2.0f);

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

/*!
 * \brief __GEN structure
 */
struct record_s
{
  unsigned index; //!< member - 0
  unsigned value; //!< member - 1

  /*!
    * \brief __GEN initialize structure
    */
  inline void init();

  /*!
    * \brief __GEN release memory used by structure
    */
  inline void clear();

  /*!
    * \brief __GEN set structure members
    */
  inline void set(unsigned a_index,unsigned a_value);
  /*!
    * \brief __GEN flush structure memory usage, recursive on members
    */
  inline void flush_all();

  /*!
    * \brief __GEN swap structure members with another structure
    */
  inline void swap(record_s &a_second);

  /*!
    * \brief __GEN copy structure from another structure
    * \param a_src - reference to another structure
    * \return reference to this structure
    */
  inline record_s &operator=(record_s &a_src);

  /*!
    * \brief __GEN compare structure with another structure
    * \param a_second - reference to another structure
    * \return result of comparison
    */
  inline bool operator==(record_s &a_second);

  
  inline unsigned get_index();
  inline unsigned get_value();

};



/*
 * inline methods of generated structures
 */

// -- record_s --
// --- struct record_s inline method definition ---

inline void record_s::init()
{/*{{{*/
}/*}}}*/

inline void record_s::clear()
{/*{{{*/

  init();
}/*}}}*/

inline void record_s::set(unsigned a_index,unsigned a_value)
{/*{{{*/
  index = a_index;
  value = a_value;
}/*}}}*/

inline void record_s::flush_all()
{/*{{{*/
}/*}}}*/

inline void record_s::swap(record_s &a_second)
{/*{{{*/
  unsigned tmp_index = index;
  index = a_second.index;
  a_second.index = tmp_index;

  unsigned tmp_value = value;
  value = a_second.value;
  a_second.value = tmp_value;
}/*}}}*/

inline record_s &record_s::operator=(record_s &a_src)
{/*{{{*/
  index = a_src.index;
  value = a_src.value;

  return *this;
}/*}}}*/

inline bool record_s::operator==(record_s &a_second)
{/*{{{*/
  return (index == a_second.index && value == a_second.value);
}/*}}}*/



inline unsigned record_s::get_index()
{
  return index;
}

inline unsigned record_s::get_value()
{
  return value;
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
// --- struct ui_array_s definition --- 

/*!
 * \brief __GEN array of type unsigned
 */
struct ui_array_s
{
  unsigned size; //!< actual size of allocated space in array
  unsigned used; //!< count of used space in array
  unsigned *data; //!< pointer to array elements

  /*!
    * \brief __GEN initialize array
    */
  inline void init();

  /*!
    * \brief __GEN initialize array of requested size
    * \param a_size - requested size of array
    */
  inline void init_size(unsigned a_size);

  /*!
    * \brief __GEN release memory used by array
    */
  inline void clear();

  /*!
    * \brief __GEN set array content from element pointer
    * \param a_used - number of elements stored at pointed location
    * \param a_data - pointer to elements
    */
  inline void set(unsigned a_used,unsigned *a_data);

  /*!
    * \brief __GEN flush array memory usage
    */
  inline void flush();

  /*!
    * \brief __GEN flush array memory usage, recursive on elemenets
    */
  inline void flush_all();

  /*!
    * \brief __GEN swap array members with another array
    * \param a_second - reference to another array
    */
  inline void swap(ui_array_s &a_second);

  /*!
    * \brief __GEN select element of array
    * \param a_idx - index of element in array
    * \return reference to element of array
    */
  inline unsigned &operator[](unsigned a_idx);

  /*!
    * \brief __GEN insert element to end of array
    * \param a_value - value of inserted element
    */
  inline void push(unsigned a_value);

  /*!
    * \brief __GEN insert blank element to end of array
    */
  inline void push_blank();

  /*!
    * \brief __GEN reserve requested count of elements at end of array
    * \param a_cnt - count of elements to be reserved
    */
  void reserve(unsigned a_cnt);

  /*!
    * \brief __GEN insert blank elements to end of array
    * \param a_cnt - count of elements inserted to array
    */
  void push_blanks(unsigned a_cnt);

  /*!
    * \brief __GEN insert and clear element to end of array
    */
  inline void push_clear();

  /*!
    * \brief __GEN return value of last element in array, and remove it
    * \return reference to last element
    */
  inline unsigned &pop();

  /*!
    * \brief __GEN return value of last element in array
    * \return reference to last element
    */
  inline unsigned &last();

  /*!
    * \brief __GEN change array capacity
    * \param a_size - requested array capacity
    */
  void copy_resize(unsigned a_size);

  /*!
    * \brief __GEN set all elements of array to given value
    * \param a_value - new value of all elements
    */
  void fill(unsigned a_value);

  /*!
    * \brief __GEN search for index of element
    * \param a_value - value which index is searched
    */
  unsigned get_idx(unsigned a_value);

  /*!
    * \brief __GEN copy array from another array
    * \param a_src - reference to another array
    * \return reference to this array
    */
  inline ui_array_s &operator=(ui_array_s &a_src);

  /*!
    * \brief __GEN comparison of array with another array
    * \param a_second - reference to another array
    * \return result of comparison
    */
  inline bool operator==(ui_array_s &a_second);

};



// -- int_string_s --
// structure int_string_s definition

/*!
 * \brief __GEN structure
 */
struct int_string_s
{
  int index; //!< member - 0
  string_s value; //!< member - 1

  /*!
    * \brief __GEN initialize structure
    */
  inline void init();

  /*!
    * \brief __GEN release memory used by structure
    */
  inline void clear();

  /*!
    * \brief __GEN set structure members
    */
  inline void set(int a_index,string_s &a_value);
  /*!
    * \brief __GEN flush structure memory usage, recursive on members
    */
  inline void flush_all();

  /*!
    * \brief __GEN swap structure members with another structure
    */
  inline void swap(int_string_s &a_second);

  /*!
    * \brief __GEN copy structure from another structure
    * \param a_src - reference to another structure
    * \return reference to this structure
    */
  inline int_string_s &operator=(int_string_s &a_src);

  /*!
    * \brief __GEN compare structure with another structure
    * \param a_second - reference to another structure
    * \return result of comparison
    */
  inline bool operator==(int_string_s &a_second);

};



// -- int_string_map_s --
// struct int_string_map_s definition

/*!
 * \brief __GEN node of rb_tree of type int_string_s
 */

struct int_string_map_s_node
{
  int_string_s object;
  unsigned parent_idx;
  unsigned left_idx;
  unsigned right_idx;
  bool color;
};

/*!
 * \brief __GEN rb_tree of type int_string_s
 */
struct int_string_map_s
{
  unsigned size;
  unsigned used;
  int_string_map_s_node *data;
  unsigned free_idx;
  unsigned root_idx;
  unsigned leaf_idx;

  // - internal support methods -
  inline unsigned __get_grandparent_idx(unsigned a_idx);
  inline unsigned __get_uncle_idx(unsigned a_idx);
  inline unsigned __get_sibling_idx(unsigned a_idx);

  inline unsigned get_descent_stack_size();
  unsigned get_stack_min_value_idx(unsigned a_idx,unsigned **a_s_ptr);
  inline unsigned get_stack_next_idx(unsigned a_idx,unsigned **a_s_ptr,unsigned *a_stack_base);

  unsigned get_min_value_idx(unsigned a_idx);
  unsigned get_max_value_idx(unsigned a_idx);
  unsigned get_next_idx(unsigned a_idx);
  unsigned get_prev_idx(unsigned a_idx);

  inline void __rotate_left(unsigned a_idx);
  inline void __rotate_right(unsigned a_idx);

  inline unsigned __get_new_index();
  unsigned __binary_tree_insert(unsigned a_new_idx,int_string_s &a_value,bool a_unique);

  inline void __replace_delete_node_by_child(unsigned a_idx,unsigned a_ch_idx);
  void __remove_black_black(unsigned a_idx);

  inline void __remove_one_child(unsigned a_idx,unsigned a_ch_idx);

  void __insert_operation(unsigned a_idx);

  inline int __compare_value(int_string_s &a_first,int_string_s &a_second);

  /*!
    * \brief __GEN initialize rb_tree
    */
  inline void init();

  /*!
    * \brief __GEN release memory used by rb_tree
    */
  void clear();

  /*!
    * \brief __GEN flush rb_tree memory usage
    */
  inline void flush();

  /*!
    * \brief __GEN flush rb_tree memory usage, recursive on nodes
    */
  inline void flush_all();

  /*!
    * \brief __GEN swap members of rb_tree with another rb_tree
    * \param a_second - reference to another rb_tree
    */
  inline void swap(int_string_map_s &a_second);

  /*!
    * \brief __GEN select ode of rb_tree
    * \param a_idx - index of node in rb_tree
    * \return reference to node of rb_tree
    */
  inline int_string_s &operator[](unsigned a_idx);

  /*!
    * \brief __GEN insert node to rb_tree
    * \param a_value - reference to value inserted to rb_tree
    * \return - position of node in rb_tree
    */
  inline unsigned insert(int_string_s &a_value);

  /*!
    * \brief __GEN insert node to rb_tree if it not exist yet
    * \param a_value - reference to value inserted to rb_tree
    * \return - position of node in rb_tree
    */
  inline unsigned unique_insert(int_string_s &a_value);

  /*!
    * \brief __GEN insert node to rb_tree by swapping
    * \param a_value - reference to value inserted to rb_tree
    * \return - position of node in rb_tree
    */
  inline unsigned swap_insert(int_string_s &a_value);

  /*!
    * \brief __GEN insert node to rb_tree by swapping if it not exist yet
    * \param a_value - reference to value inserted to rb_tree
    * \return - position of node in rb_tree
    */
  inline unsigned unique_swap_insert(int_string_s &a_value);

  /*!
    * \brief __GEN remove node at index from rb_tree
    * \param a_idx - index of node to remove
    */
  void remove(unsigned a_idx);

  /*!
    * \brief __GEN resize rb_tree capacity
    * \param a_size - requested rb_tree capacity
    */
  void copy_resize(unsigned a_size);

  /*!
    * \brief __GEN search for index of node
    * \param a_value - value which index is searched
    */
  unsigned get_idx(int_string_s &a_value);

  /*!
    * \brief __GEN search for leftmost index of node
    * \param a_value - value which index is searched
    */
  unsigned get_idx_left(int_string_s &a_value);

  /*!
    * \brief __GEN search for index of node with greater or equal value
    * \param a_value - value which index is searched
    */
  unsigned get_gre_idx(int_string_s &a_value);

  /*!
    * \brief __GEN search for index of node with less or equal value
    * \param a_value - value which index is searched
    */
  unsigned get_lee_idx(int_string_s &a_value);
  /*!
    * \brief __GEN search for all indexes of node
    * \param a_value - value of searched index
    */
  void get_idxs(int_string_s &a_value,ui_array_s &a_idxs_array);

  /*!
    * \brief __GEN copy rb_tree from another rb_tree
    * \param a_src - reference to another rb_tree
    * \return reference to this rb_tree
    */
  int_string_map_s &operator=(int_string_map_s &a_src);

  /*!
    * \brief __GEN compare rb_tree with another rb_tree
    * \param a_second - reference to another rb_tree
    * \return result of comparision
    */
  bool operator==(int_string_map_s &a_second);

  /*!
    * \brief __GEN rehash tree (after invalidation by change of object value)
    */
    void rehash_tree();

};



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
  if (a_length == 0) return;

  data = (char *)cmalloc((a_length + 1)*sizeof(char));

  data[a_length] = '\0';
  size = a_length + 1;
}/*}}}*/

inline void string_s::set(unsigned a_length,const char *a_data)
{/*{{{*/
  clear();
  if (a_length == 0) return;

  data = (char *)cmalloc((a_length + 1)*sizeof(char));
  memcpy(data,a_data,a_length*sizeof(char));

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
// --- struct ui_array_s inline method definition ---

inline void ui_array_s::init()
{/*{{{*/
  size = 0;
  used = 0;
  data = nullptr;
}/*}}}*/

inline void ui_array_s::init_size(unsigned a_size)
{/*{{{*/
  init();
  copy_resize(a_size);
}/*}}}*/

inline void ui_array_s::clear()
{/*{{{*/
  if (data != nullptr)
  {
    cfree(data);
  }

  init();
}/*}}}*/

inline void ui_array_s::set(unsigned a_used,unsigned *a_data)
{/*{{{*/
  clear();
  if (a_used == 0)
  {
    return;
  }

  debug_assert(a_data != nullptr);
  copy_resize(a_used);

  memcpy(data,a_data,a_used*sizeof(unsigned));
  used = a_used;
}/*}}}*/

inline void ui_array_s::flush()
{/*{{{*/
  copy_resize(used);
}/*}}}*/

inline void ui_array_s::flush_all()
{/*{{{*/
  copy_resize(used);
}/*}}}*/

inline void ui_array_s::swap(ui_array_s &a_second)
{/*{{{*/
  unsigned tmp_unsigned = size;
  size = a_second.size;
  a_second.size = tmp_unsigned;

  tmp_unsigned = used;
  used = a_second.used;
  a_second.used = tmp_unsigned;

  unsigned *tmp_data = data;
  data = a_second.data;
  a_second.data = tmp_data;
}/*}}}*/

inline unsigned &ui_array_s::operator[](unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < used);
  return data[a_idx];
}/*}}}*/

inline void ui_array_s::push(unsigned a_value)
{/*{{{*/
  if (used >= size)
  {
    copy_resize((size << 1) + c_array_add);
  }

  data[used++] = a_value;
}/*}}}*/

inline void ui_array_s::push_blank()
{/*{{{*/
  if (used >= size)
  {
    copy_resize((size << 1) + c_array_add);
  }

  used++;
}/*}}}*/

inline void ui_array_s::push_clear()
{/*{{{*/
  if (used >= size)
  {
    copy_resize((size << 1) + c_array_add);
  }

  used++;
}/*}}}*/

inline unsigned &ui_array_s::pop()
{/*{{{*/
  debug_assert(used > 0);
  return data[--used];
}/*}}}*/

inline unsigned &ui_array_s::last()
{/*{{{*/
  debug_assert(used > 0);
  return data[used - 1];
}/*}}}*/

inline ui_array_s &ui_array_s::operator=(ui_array_s &a_src)
{/*{{{*/
  clear();

  if (a_src.used == 0)
  {
    return *this;
  }

  copy_resize(a_src.used);
  memcpy(data,a_src.data,a_src.used*sizeof(unsigned));

  used = a_src.used;
  return *this;
}/*}}}*/

inline bool ui_array_s::operator==(ui_array_s &a_second)
{/*{{{*/
  if (used != a_second.used)
  {
    return false;
  }

  if (used == 0)
  {
    return true;
  }

  return (memcmp(data,a_second.data,used*sizeof(unsigned)) == 0);
}/*}}}*/



// -- int_string_s --
// --- struct int_string_s inline method definition ---

inline void int_string_s::init()
{/*{{{*/
  value.init();
}/*}}}*/

inline void int_string_s::clear()
{/*{{{*/
  value.clear();

  init();
}/*}}}*/

inline void int_string_s::set(int a_index,string_s &a_value)
{/*{{{*/
  index = a_index;
  value = a_value;
}/*}}}*/

inline void int_string_s::flush_all()
{/*{{{*/
}/*}}}*/

inline void int_string_s::swap(int_string_s &a_second)
{/*{{{*/
  int tmp_index = index;
  index = a_second.index;
  a_second.index = tmp_index;

  value.swap(a_second.value);
}/*}}}*/

inline int_string_s &int_string_s::operator=(int_string_s &a_src)
{/*{{{*/
  index = a_src.index;
  value = a_src.value;

  return *this;
}/*}}}*/

inline bool int_string_s::operator==(int_string_s &a_second)
{/*{{{*/
  return (index == a_second.index && value == a_second.value);
}/*}}}*/



// -- int_string_map_s --
// --- struct int_string_map_s inline method definition ---

inline unsigned int_string_map_s::__get_grandparent_idx(unsigned a_idx)
{/*{{{*/
  int_string_map_s_node &node = data[a_idx];

  if (node.parent_idx != c_idx_not_exist)
  {
    return data[node.parent_idx].parent_idx;
  }

  return c_idx_not_exist;
}/*}}}*/

inline unsigned int_string_map_s::__get_uncle_idx(unsigned a_idx)
{/*{{{*/
  unsigned gp_idx = __get_grandparent_idx(a_idx);

  if (gp_idx != c_idx_not_exist)
  {
    int_string_map_s_node &gp = data[gp_idx];
    return gp.left_idx == data[a_idx].parent_idx?gp.right_idx:gp.left_idx;
  }

  return c_idx_not_exist;
}/*}}}*/

inline unsigned int_string_map_s::__get_sibling_idx(unsigned a_idx)
{/*{{{*/
  int_string_map_s_node &p = data[data[a_idx].parent_idx];
  return p.left_idx == a_idx?p.right_idx:p.left_idx;
}/*}}}*/

inline unsigned int_string_map_s::get_descent_stack_size()
{/*{{{*/
  return (unsigned)(logf(used)/c_log_of_2) << 1;
}/*}}}*/

inline unsigned int_string_map_s::get_stack_next_idx(unsigned a_idx,unsigned **a_s_ptr,unsigned *a_stack_base)
{/*{{{*/
  debug_assert(a_idx < used);

  int_string_map_s_node &node = data[a_idx];

  if (node.right_idx != leaf_idx)
  {
    return get_stack_min_value_idx(node.right_idx,a_s_ptr);
  }

  if (*a_s_ptr > a_stack_base)
  {
    return *(--(*a_s_ptr));
  }

  return c_idx_not_exist;
}/*}}}*/

inline void int_string_map_s::__rotate_left(unsigned a_idx)
{/*{{{*/
  int_string_map_s_node &root = data[a_idx];
  int_string_map_s_node &pivot = data[root.right_idx];

  if (a_idx == root_idx)
  {
    root_idx = root.right_idx;
    pivot.parent_idx = c_idx_not_exist;
  }
  else
  {
    int_string_map_s_node &rp = data[root.parent_idx];
    (rp.right_idx == a_idx?rp.right_idx:rp.left_idx) = root.right_idx;

    pivot.parent_idx = root.parent_idx;
  }

  root.parent_idx = root.right_idx;

  root.right_idx = pivot.left_idx;
  data[root.right_idx].parent_idx = a_idx;

  pivot.left_idx = a_idx;
}/*}}}*/

inline void int_string_map_s::__rotate_right(unsigned a_idx)
{/*{{{*/
  int_string_map_s_node &root = data[a_idx];
  int_string_map_s_node &pivot = data[root.left_idx];

  if (a_idx == root_idx)
  {
    root_idx = root.left_idx;
    pivot.parent_idx = c_idx_not_exist;
  }
  else
  {
    int_string_map_s_node &rp = data[root.parent_idx];
    (rp.right_idx == a_idx?rp.right_idx:rp.left_idx) = root.left_idx;

    pivot.parent_idx = root.parent_idx;
  }

  root.parent_idx = root.left_idx;

  root.left_idx = pivot.right_idx;
  data[root.left_idx].parent_idx = a_idx;

  pivot.right_idx = a_idx;
}/*}}}*/

inline unsigned int_string_map_s::__get_new_index()
{/*{{{*/
  if (free_idx != c_idx_not_exist)
  {
    unsigned new_idx = free_idx;
    free_idx = data[new_idx].parent_idx;

    return new_idx;
  }

  if (used >= size)
  {
    copy_resize((size << 1) + c_array_add);
  }

  return used++;
}/*}}}*/

inline void int_string_map_s::__replace_delete_node_by_child(unsigned a_idx,unsigned a_ch_idx)
{/*{{{*/
  int_string_map_s_node &node = data[a_idx];

  if (node.parent_idx != c_idx_not_exist)
  {
    int_string_map_s_node &parent = data[node.parent_idx];
    (parent.left_idx == a_idx?parent.left_idx:parent.right_idx) = a_ch_idx;

    data[a_ch_idx].parent_idx = node.parent_idx;
  }
  else
  {
    root_idx = a_ch_idx == leaf_idx?c_idx_not_exist:a_ch_idx;
    data[a_ch_idx].parent_idx = c_idx_not_exist;
  }
}/*}}}*/

inline void int_string_map_s::__remove_one_child(unsigned a_idx,unsigned a_ch_idx)
{/*{{{*/
  int_string_map_s_node &node = data[a_idx];
  __replace_delete_node_by_child(a_idx,a_ch_idx);

  node.parent_idx = free_idx;
  free_idx = a_idx;

  if (node.color)
  {
    int_string_map_s_node &child_node = data[a_ch_idx];

    if (!child_node.color)
    {
      child_node.color = true;
    }
    else
    {
      __remove_black_black(a_ch_idx);
    }
  }
}/*}}}*/

inline void int_string_map_s::init()
{/*{{{*/
  size = 0;
  used = 0;
  data = nullptr;
  free_idx = c_idx_not_exist;
  root_idx = c_idx_not_exist;
  leaf_idx = c_idx_not_exist;
}/*}}}*/

inline void int_string_map_s::flush()
{/*{{{*/
  copy_resize(used);
}/*}}}*/

inline void int_string_map_s::flush_all()
{/*{{{*/
  copy_resize(used);
}/*}}}*/

inline void int_string_map_s::swap(int_string_map_s &a_second)
{/*{{{*/
  unsigned tmp_unsigned = size;
  size = a_second.size;
  a_second.size = tmp_unsigned;

  tmp_unsigned = used;
  used = a_second.used;
  a_second.used = tmp_unsigned;

  int_string_map_s_node *tmp_data = data;
  data = a_second.data;
  a_second.data = tmp_data;

  tmp_unsigned = free_idx;
  free_idx = a_second.free_idx;
  a_second.free_idx = tmp_unsigned;

  tmp_unsigned = root_idx;
  root_idx = a_second.root_idx;
  a_second.root_idx = tmp_unsigned;

  tmp_unsigned = leaf_idx;
  leaf_idx = a_second.leaf_idx;
  a_second.leaf_idx = tmp_unsigned;
}/*}}}*/

inline int_string_s &int_string_map_s::operator[](unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < used);
  return data[a_idx].object;
}/*}}}*/

inline unsigned int_string_map_s::insert(int_string_s &a_value)
{/*{{{*/
  unsigned new_node_idx = __get_new_index();

  __binary_tree_insert(new_node_idx,a_value,false);
  __insert_operation(new_node_idx);

  data[new_node_idx].object = a_value;

  return new_node_idx;
}/*}}}*/

inline unsigned int_string_map_s::swap_insert(int_string_s &a_value)
{/*{{{*/
  unsigned new_node_idx = __get_new_index();

  __binary_tree_insert(new_node_idx,a_value,false);
  __insert_operation(new_node_idx);

  data[new_node_idx].object.swap(a_value);

  return new_node_idx;
}/*}}}*/

inline unsigned int_string_map_s::unique_insert(int_string_s &a_value)
{/*{{{*/
  unsigned new_node_idx = __get_new_index();
  unsigned old_node_idx = __binary_tree_insert(new_node_idx,a_value,true);

  if (old_node_idx != c_idx_not_exist)
  {
    int_string_map_s_node &new_node = data[new_node_idx];

    new_node.parent_idx = free_idx;
    free_idx = new_node_idx;

    return old_node_idx;
  }

  __insert_operation(new_node_idx);

  data[new_node_idx].object = a_value;

  return new_node_idx;
}/*}}}*/

inline unsigned int_string_map_s::unique_swap_insert(int_string_s &a_value)
{/*{{{*/
  unsigned new_node_idx = __get_new_index();
  unsigned old_node_idx = __binary_tree_insert(new_node_idx,a_value,true);

  if (old_node_idx != c_idx_not_exist)
  {
    int_string_map_s_node &new_node = data[new_node_idx];

    new_node.parent_idx = free_idx;
    free_idx = new_node_idx;

    return old_node_idx;
  }

  __insert_operation(new_node_idx);

  data[new_node_idx].object.swap(a_value);

  return new_node_idx;
}/*}}}*/



inline int int_string_map_s::__compare_value(int_string_s &a_first,int_string_s &a_second)
{/*{{{*/
  int &fi = a_first.index;
  int &si = a_second.index;

  return fi < si ? -1 : fi > si ? 1 : 0;
}/*}}}*/

#endif



/*
 * constants and definitions
 */

// - string terminating character -
const char c_string_terminating_char = '\0';

/*
 * methods of structure string_s
 */

void string_s::setf(const char *format,...)
{/*{{{*/
  clear();

  const int init_size = 256;
  int alloc_size = init_size;

  va_list ap;

  do
  {
    data = (char *)cmalloc(alloc_size*sizeof(char));

    va_start(ap,format);

#if SYSTEM_TYPE == SYSTEM_TYPE_DSP
    // DSP FIXME
    int cnt = vsprintf(data,format,ap);
#else
    int cnt = vsnprintf(data,alloc_size,format,ap);
#endif
    va_end(ap);

    if (cnt < alloc_size)
    {
      size = cnt + 1;
      break;
    }

    cfree(data);
    alloc_size <<= 1;

  }
  while(1);
}/*}}}*/

/*
 * methods of generated structures
 */

// -- ui_array_s --
// --- struct ui_array_s method definition ---

void ui_array_s::reserve(unsigned a_cnt)
{/*{{{*/
  unsigned required_cnt = used + a_cnt;
  if (required_cnt > size)
  {
    unsigned r_size = size;
    do {
      r_size = (r_size << 1) + c_array_add;
    } while(r_size < required_cnt);

    copy_resize(r_size);
  }
}/*}}}*/

void ui_array_s::push_blanks(unsigned a_cnt)
{/*{{{*/
  unsigned required_cnt = used + a_cnt;
  if (required_cnt > size)
  {
    unsigned r_size = size;
    do {
      r_size = (r_size << 1) + c_array_add;
    } while(r_size < required_cnt);

    copy_resize(r_size);
  }

  used += a_cnt;
}/*}}}*/

void ui_array_s::copy_resize(unsigned a_size)
{/*{{{*/
  debug_assert(a_size >= used);

  if (a_size == 0)
  {
    if (data != nullptr)
    {
      cfree(data);
    }
    data = nullptr;
  }
  else
  {
    data = (unsigned *)crealloc(data,a_size*sizeof(unsigned));
  }

  size = a_size;
}/*}}}*/

void ui_array_s::fill(unsigned a_value)
{/*{{{*/
  if (size == 0)
  {
    return;
  }

  unsigned *ptr = data;
  unsigned *ptr_end = data + size;

  do {
    *ptr = a_value;
  } while(++ptr < ptr_end);

  used = size;
}/*}}}*/

unsigned ui_array_s::get_idx(unsigned a_value)
{/*{{{*/
  if (used == 0)
  {
    return c_idx_not_exist;
  }

  unsigned *ptr = data;
  unsigned *ptr_end = data + used;

  do {
    if (*ptr == a_value)
    {
      return ptr - data;
    }
  } while(++ptr < ptr_end);

  return c_idx_not_exist;
}/*}}}*/



// -- int_string_s --
// --- struct int_string_s method definition ---



// -- int_string_map_s --
// --- struct int_string_map_s method definition ---

unsigned int_string_map_s::get_stack_min_value_idx(unsigned a_idx,unsigned **a_s_ptr)
{/*{{{*/
  debug_assert(a_idx < used);

  unsigned node_idx = a_idx;
  do {
    int_string_map_s_node &node = data[node_idx];

    if (node.left_idx == leaf_idx)
    {
      return node_idx;
    }

    *((*a_s_ptr)++) = node_idx;
    node_idx = node.left_idx;
  } while(1);
}/*}}}*/

unsigned int_string_map_s::get_min_value_idx(unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < used);

  unsigned node_idx = a_idx;
  do {
    int_string_map_s_node &node = data[node_idx];

    if (node.left_idx == leaf_idx)
    {
      return node_idx;
    }

    node_idx = node.left_idx;
  } while(1);
}/*}}}*/

unsigned int_string_map_s::get_max_value_idx(unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < used);

  unsigned node_idx = a_idx;
  do {
    int_string_map_s_node &node = data[node_idx];

    if (node.right_idx == leaf_idx)
    {
      return node_idx;
    }

    node_idx = node.right_idx;
  } while(1);
}/*}}}*/

unsigned int_string_map_s::get_next_idx(unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < used);

  int_string_map_s_node &node = data[a_idx];

  if (node.right_idx != leaf_idx)
  {
    return get_min_value_idx(node.right_idx);
  }

  unsigned node_idx = a_idx;
  do {
    int_string_map_s_node &node = data[node_idx];

    if (node.parent_idx == c_idx_not_exist)
    {
      return c_idx_not_exist;
    }

    if (data[node.parent_idx].right_idx != node_idx)
    {
      return node.parent_idx;
    }

    node_idx = node.parent_idx;
  } while(1);
}/*}}}*/

unsigned int_string_map_s::get_prev_idx(unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < used);

  int_string_map_s_node &node = data[a_idx];

  if (node.left_idx != leaf_idx)
  {
    return get_max_value_idx(node.left_idx);
  }

  unsigned node_idx = a_idx;
  do {
    int_string_map_s_node &node = data[node_idx];

    if (node.parent_idx == c_idx_not_exist)
    {
      return c_idx_not_exist;
    }

    if (data[node.parent_idx].left_idx != node_idx)
    {
      return node.parent_idx;
    }

    node_idx = node.parent_idx;
  } while(1);
}/*}}}*/

unsigned int_string_map_s::__binary_tree_insert(unsigned a_new_idx,int_string_s &a_value,bool a_unique)
{/*{{{*/
  if (root_idx == c_idx_not_exist)
  {
    if (leaf_idx == c_idx_not_exist)
    {
      leaf_idx = __get_new_index();
      int_string_map_s_node &leaf = data[leaf_idx];

      leaf.color = true;

#ifdef RB_TREE_SET_LEAF_CHILDS
      leaf.left_idx = c_idx_not_exist;
      leaf.right_idx = c_idx_not_exist;
#endif
    }

    data[a_new_idx].parent_idx = c_idx_not_exist;
    root_idx = a_new_idx;
  }
  else 
  {
    unsigned node_idx = root_idx;
    do {
      int_string_map_s_node &node = data[node_idx];

      int comp_result = __compare_value(a_value,node.object);
      if (comp_result < 0)
      {
        if (node.left_idx == leaf_idx)
        {
          node.left_idx = a_new_idx;
          break;
        }
        node_idx = node.left_idx;
      }
      else
      {
        if (a_unique && comp_result == 0)
        {
          return node_idx;
        }

        if (node.right_idx == leaf_idx)
        {
          node.right_idx = a_new_idx;
          break;
        }
        node_idx = node.right_idx;
      }
    } while(1);

    data[a_new_idx].parent_idx = node_idx;
  }

  int_string_map_s_node &new_node = data[a_new_idx];
  new_node.left_idx = leaf_idx;
  new_node.right_idx = leaf_idx;
  new_node.color = false;

  return c_idx_not_exist;
}/*}}}*/

void int_string_map_s::__remove_black_black(unsigned a_idx)
{/*{{{*/
  unsigned node_idx = a_idx;
  do {
    int_string_map_s_node &node = data[node_idx];

    if (node.parent_idx == c_idx_not_exist)
    {
      return;
    }

    unsigned parent_idx = node.parent_idx;
    int_string_map_s_node &parent = data[parent_idx];

    {
      unsigned sibling_idx = parent.left_idx == node_idx?parent.right_idx:parent.left_idx;
      int_string_map_s_node &sibling = data[sibling_idx];

      if (!sibling.color)
      {
        parent.color = false;
        sibling.color = true;

        if (node_idx == parent.left_idx)
        {
          __rotate_left(parent_idx);
        }
        else
        {
          __rotate_right(parent_idx);
        }
      }
    }

    {
      unsigned sibling_idx = parent.left_idx == node_idx?parent.right_idx:parent.left_idx;
      int_string_map_s_node& sibling = data[sibling_idx];

      if (parent.color && sibling.color && data[sibling.left_idx].color && data[sibling.right_idx].color)
      {
        sibling.color = false;
        node_idx = parent_idx;
        continue;
      }
      else if (!parent.color && sibling.color && data[sibling.left_idx].color && data[sibling.right_idx].color)
      {
        sibling.color = false;
        parent.color = true;
        return;
      }
      else if (sibling.color)
      {
        if (node_idx == parent.left_idx && data[sibling.right_idx].color && !data[sibling.left_idx].color)
        {
          sibling.color = false;
          data[sibling.left_idx].color = true;
          __rotate_right(sibling_idx);
        }
        else if (node_idx == parent.right_idx && data[sibling.left_idx].color && !data[sibling.right_idx].color)
        {
          sibling.color = false;
          data[sibling.right_idx].color = true;
          __rotate_left(sibling_idx);
        }
      }

      {
        unsigned sibling_idx = parent.left_idx == node_idx?parent.right_idx:parent.left_idx;
        int_string_map_s_node &sibling = data[sibling_idx];

        sibling.color = parent.color;
        parent.color = true;

        if (node_idx == parent.left_idx)
        {
          data[sibling.right_idx].color = true;
          __rotate_left(parent_idx);
        }
        else
        {
          data[sibling.left_idx].color = true;
          __rotate_right(parent_idx);
        }
      }

      return;
    }

  } while(1);
}/*}}}*/

void int_string_map_s::__insert_operation(unsigned a_idx)
{/*{{{*/
  unsigned node_idx = a_idx;
  do {
    int_string_map_s_node &node = data[node_idx];

    if (node.parent_idx == c_idx_not_exist)
    {
      node.color = true;
      return;
    }

    if (data[node.parent_idx].color)
    {
      return;
    }

    unsigned uncle_idx = __get_uncle_idx(node_idx);
    if (uncle_idx != c_idx_not_exist && !data[uncle_idx].color)
    {
      data[node.parent_idx].color = true;
      data[uncle_idx].color = true;

      node_idx = __get_grandparent_idx(node_idx);
      data[node_idx].color = false;

      continue;
    }
    else
    {
      unsigned grandparent_idx = __get_grandparent_idx(node_idx);

      if (node_idx == data[node.parent_idx].right_idx && node.parent_idx == data[grandparent_idx].left_idx)
      {
        __rotate_left(node.parent_idx);
        node_idx = node.left_idx;
      }
      else if (node_idx == data[node.parent_idx].left_idx && node.parent_idx == data[grandparent_idx].right_idx)
      {
        __rotate_right(node.parent_idx);
        node_idx = node.right_idx;
      }

      {
        unsigned grandparent_idx = __get_grandparent_idx(node_idx);
        int_string_map_s_node &node = data[node_idx];

        data[node.parent_idx].color = true;
        data[grandparent_idx].color = false;

        if (node_idx == data[node.parent_idx].left_idx && node.parent_idx == data[grandparent_idx].left_idx)
        {
          __rotate_right(grandparent_idx);
        }
        else
        {
          __rotate_left(grandparent_idx);
        }
      }

      return;
    }
  } while(1);
}/*}}}*/

void int_string_map_s::clear()
{/*{{{*/
  if (data != nullptr)
  {
    int_string_map_s_node *ptr = data;
    int_string_map_s_node *ptr_end = ptr + size;

    do {
      ptr->object.clear();
    } while(++ptr < ptr_end);

    cfree(data);
  }

  init();
}/*}}}*/

void int_string_map_s::remove(unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < used);

  int_string_map_s_node &del_node = data[a_idx];

  if (del_node.left_idx != leaf_idx)
  {
    if (del_node.right_idx != leaf_idx)
    {
      unsigned found_idx = del_node.right_idx;
      do {
        int_string_map_s_node &node = data[found_idx];

        if (node.left_idx == leaf_idx)
        {
          break;
        }

        found_idx = node.left_idx;
      } while(1);

      int_string_map_s_node &found_node = data[found_idx];

      /* - process del_node parent_idx - */
      if (del_node.parent_idx != c_idx_not_exist)
      {
        int_string_map_s_node &del_node_parent = data[del_node.parent_idx];
        (del_node_parent.left_idx == a_idx?del_node_parent.left_idx:del_node_parent.right_idx) = found_idx;
      }
      else
      {
        root_idx = found_idx;
      }

      /* - process del_node left_idx - */
      data[del_node.left_idx].parent_idx = found_idx;

      /* - process found_node right_idx - */
      if (found_node.right_idx != leaf_idx)
      {
        data[found_node.right_idx].parent_idx = a_idx;
      }

      if (del_node.right_idx == found_idx)
      {
        /* - found node is right child of deleted node - */
        del_node.right_idx = found_node.right_idx;
        found_node.right_idx = a_idx;

        found_node.parent_idx = del_node.parent_idx;
        del_node.parent_idx = found_idx;

        found_node.left_idx = del_node.left_idx;
        del_node.left_idx = leaf_idx;

        bool tmp_bool = found_node.color;
        found_node.color = del_node.color;
        del_node.color = tmp_bool;
      }
      else
      {
        /* - process found_node parent - */
        int_string_map_s_node &found_node_parent = data[found_node.parent_idx];
        (found_node_parent.left_idx == found_idx?found_node_parent.left_idx:found_node_parent.right_idx) = a_idx;

        /* - process del_node right_idx - */
        data[del_node.right_idx].parent_idx = found_idx;

        /* - swap index pointers between nodes - */
        unsigned tmp_unsigned = found_node.parent_idx;
        found_node.parent_idx = del_node.parent_idx;
        del_node.parent_idx = tmp_unsigned;

        found_node.left_idx = del_node.left_idx;
        del_node.left_idx = leaf_idx;

        tmp_unsigned = found_node.right_idx;
        found_node.right_idx = del_node.right_idx;
        del_node.right_idx = tmp_unsigned;

        bool tmp_bool = found_node.color;
        found_node.color = del_node.color;
        del_node.color = tmp_bool;
      }

      __remove_one_child(a_idx,del_node.right_idx);
    }
    else
    {
      __remove_one_child(a_idx,del_node.left_idx);
    }
  }
  else
  {
    __remove_one_child(a_idx,del_node.right_idx);
  }

}/*}}}*/

void int_string_map_s::copy_resize(unsigned a_size)
{/*{{{*/
  debug_assert(a_size >= used);

  if (size > a_size)
  {
    int_string_map_s_node *ptr = data + a_size;
    int_string_map_s_node *ptr_end = data + size;

    do {
      ptr->object.clear();
    } while(++ptr < ptr_end);
  }

  if (a_size == 0)
  {
    if (data != nullptr)
    {
      cfree(data);
    }
    data = nullptr;
  }
  else
  {
    data = (int_string_map_s_node *)crealloc(data,a_size*sizeof(int_string_map_s_node));
  }

  if (a_size > size)
  {
    int_string_map_s_node *ptr = data + size;
    int_string_map_s_node *ptr_end = data + a_size;

    do {
      ptr->object.init();
    } while(++ptr < ptr_end);
  }

  size = a_size;
}/*}}}*/

unsigned int_string_map_s::get_idx(int_string_s &a_value)
{/*{{{*/
  if (root_idx == c_idx_not_exist)
  {
    return c_idx_not_exist;
  }

  unsigned node_idx = root_idx;
  do {
    int_string_map_s_node &node = data[node_idx];

    int comp_result = __compare_value(a_value,node.object);
    if (comp_result < 0)
    {
      node_idx = node.left_idx;
    }
    else
    {
      if (comp_result == 0)
      {
        return node_idx;
      }

      node_idx = node.right_idx;
    }
  } while(node_idx != leaf_idx);

  return c_idx_not_exist;
}/*}}}*/

unsigned int_string_map_s::get_idx_left(int_string_s &a_value)
{/*{{{*/
  if (root_idx == c_idx_not_exist)
  {
    return c_idx_not_exist;
  }

  unsigned good_idx = c_idx_not_exist;
  unsigned node_idx = root_idx;
  do {
    int_string_map_s_node &node = data[node_idx];

    int comp_result = __compare_value(a_value,node.object);
    if (comp_result < 0)
    {
      node_idx = node.left_idx;
    }
    else
    {
      if (comp_result == 0)
      {
        good_idx = node_idx;
        node_idx = node.left_idx;
      }
      else
      {
        node_idx = node.right_idx;
      }
    }
  } while(node_idx != leaf_idx);

  return good_idx;
}/*}}}*/

unsigned int_string_map_s::get_gre_idx(int_string_s &a_value)
{/*{{{*/
  if (root_idx == c_idx_not_exist)
  {
    return c_idx_not_exist;
  }

  unsigned good_idx = c_idx_not_exist;
  unsigned node_idx = root_idx;
  do {
    int_string_map_s_node &node = data[node_idx];

    int comp_result = __compare_value(a_value,node.object);
    if (comp_result < 0)
    {
      good_idx = node_idx;
      node_idx = node.left_idx;
    }
    else
    {
      if (comp_result == 0)
      {
        return node_idx;
      }

      node_idx = node.right_idx;
    }
  } while(node_idx != leaf_idx);

  return good_idx;
}/*}}}*/

unsigned int_string_map_s::get_lee_idx(int_string_s &a_value)
{/*{{{*/
  if (root_idx == c_idx_not_exist)
  {
    return c_idx_not_exist;
  }

  unsigned good_idx = c_idx_not_exist;
  unsigned node_idx = root_idx;
  do {
    int_string_map_s_node &node = data[node_idx];

    int comp_result = __compare_value(a_value,node.object);
    if (comp_result < 0)
    {
      node_idx = node.left_idx;
    }
    else
    {
      if (comp_result == 0)
      {
        return node_idx;
      }

      good_idx = node_idx;
      node_idx = node.right_idx;
    }
  } while(node_idx != leaf_idx);

  return good_idx;
}/*}}}*/

void int_string_map_s::get_idxs(int_string_s &a_value,ui_array_s &a_idxs_array)
{/*{{{*/
  a_idxs_array.used = 0;

  if (root_idx == c_idx_not_exist)
  {
    return;
  }

  unsigned stack[get_descent_stack_size()];
  unsigned *stack_ptr = stack;

  *(stack_ptr++) = root_idx;
  do {
    unsigned node_idx = *(--stack_ptr);
    int_string_map_s_node &node = data[node_idx];

    int comp_result = __compare_value(a_value,node.object);
    if (comp_result < 0)
    {
      if (node.left_idx != leaf_idx)
      {
        *(stack_ptr++) = node.left_idx;
      }
    }
    else
    {
      if (comp_result == 0)
      {
        a_idxs_array.push(node_idx);

        if (node.left_idx != leaf_idx)
        {
          *(stack_ptr++) = node.left_idx;
        }
      }

      if (node.right_idx != leaf_idx)
      {
        *(stack_ptr++) = node.right_idx;
      }
    }
  } while(stack_ptr > stack);

  return;
}/*}}}*/

int_string_map_s &int_string_map_s::operator=(int_string_map_s &a_src)
{/*{{{*/
  clear();

  if (a_src.root_idx == c_idx_not_exist)
  {
    return *this;
  }

  copy_resize(a_src.used);

  int_string_map_s_node *ptr = data;
  int_string_map_s_node *s_ptr = a_src.data;
  int_string_map_s_node *s_ptr_end = s_ptr + a_src.used;

  do {
    ptr->object = s_ptr->object;
    ptr->parent_idx = s_ptr->parent_idx;
    ptr->left_idx = s_ptr->left_idx;
    ptr->right_idx = s_ptr->right_idx;
    ptr->color = s_ptr->color;
  } while(++ptr,++s_ptr < s_ptr_end);

  used = a_src.used;
  free_idx = a_src.free_idx;
  root_idx = a_src.root_idx;
  leaf_idx = a_src.leaf_idx;

  return *this;
}/*}}}*/

bool int_string_map_s::operator==(int_string_map_s &a_second)
{/*{{{*/
  if (root_idx == c_idx_not_exist)
  {
    if (a_second.root_idx != c_idx_not_exist)
    {
      return false;
    }
  }
  else
  {
    if (a_second.root_idx == c_idx_not_exist)
    {
      return false;
    }

    unsigned stack[get_descent_stack_size()];
    unsigned s_stack[a_second.get_descent_stack_size()];

    unsigned *stack_ptr = stack;
    unsigned *s_stack_ptr = s_stack;

    unsigned node_idx = get_stack_min_value_idx(root_idx,&stack_ptr);
    unsigned s_node_idx = a_second.get_stack_min_value_idx(a_second.root_idx,&s_stack_ptr);
    do {
      if (!(data[node_idx].object == a_second.data[s_node_idx].object))
      {
        return false;
      }

      node_idx = get_stack_next_idx(node_idx,&stack_ptr,stack);
      s_node_idx = a_second.get_stack_next_idx(s_node_idx,&s_stack_ptr,s_stack);
    } while(node_idx != c_idx_not_exist && s_node_idx != c_idx_not_exist);

    if (node_idx != s_node_idx)
    {
      return false;
    }
  }

  return true;
}/*}}}*/

void int_string_map_s::rehash_tree()
{/*{{{*/
  if (root_idx == c_idx_not_exist)
  {
    return;
  }

  ui_array_s indexes;
  indexes.init();

  {
    unsigned stack[get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned idx = get_stack_min_value_idx(root_idx,&stack_ptr);
    do {
      indexes.push(idx);

      idx = get_stack_next_idx(idx,&stack_ptr,stack);
    } while(idx != c_idx_not_exist);
  }

  root_idx = c_idx_not_exist;

  bool *processed = (bool *)cmalloc(indexes.used*sizeof(bool));
  memset(processed,false,indexes.used*sizeof(bool));

  unsigned step = indexes.used >> 1;
  if (step > 0)
  {
    do {
      unsigned idx = step;
      do {
        if (!processed[idx])
        {
          unsigned node_idx = indexes[idx];

          __binary_tree_insert(node_idx,data[node_idx].object,false);
          __insert_operation(node_idx);

          processed[idx] = true;
        }
      } while((idx += step) < indexes.used);
    } while((step >>= 1) > 0);
  }

  unsigned node_idx = indexes[0];
  __binary_tree_insert(node_idx,data[node_idx].object,false);
  __insert_operation(node_idx);

  cfree(processed);
  indexes.clear();
}/*}}}*/



int main(int argc, char **argv)
{
  int_string_map_s map;
  map.init();

  // ...
  {
    string_s str;
    str.init();

    int_string_s pair;
    pair.init();

    int idx = 0;
    do {
      pair.index = rand() % 1000;
      pair.value.setf("string-%d",idx);

      unsigned p_idx = map.get_idx(pair);
      if (p_idx != c_idx_not_exist)
      {
        map[p_idx].value.swap(pair.value);
      }
      else
      {
        map.swap_insert(pair);
      }
    } while(++idx < 1000000);

    pair.clear();
    str.clear();
  }

  // ...
  if (map.root_idx != c_idx_not_exist)
  {
    unsigned stack[map.get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned idx = map.get_stack_min_value_idx(map.root_idx,&stack_ptr);
    do
    {
      int_string_s &pair = map[idx];
      printf("%d -> %s\n",pair.index,pair.value.data);

      idx = map.get_stack_next_idx(idx,&stack_ptr,stack);
    }
    while(idx != c_idx_not_exist);
  }

  map.clear();

  return 0;
}


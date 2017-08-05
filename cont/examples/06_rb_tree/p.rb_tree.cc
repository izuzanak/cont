
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



// -- rec_rb_tree_s --
// struct rec_rb_tree_s definition

/*!
 * \brief __GEN node of rb_tree of type record_s
 */

struct rec_rb_tree_s_node
{
   record_s object;
   unsigned parent_idx;
   unsigned left_idx;
   unsigned right_idx;
   bool color;
};

/*!
 * \brief __GEN rb_tree of type record_s
 */
struct rec_rb_tree_s
{
   unsigned size;
   unsigned used;
   rec_rb_tree_s_node *data;
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
   unsigned __binary_tree_insert(unsigned a_new_idx,record_s &a_value,bool a_unique);

   inline void __replace_delete_node_by_child(unsigned a_idx,unsigned a_ch_idx);
   void __remove_black_black(unsigned a_idx);

   inline void __remove_one_child(unsigned a_idx,unsigned a_ch_idx);

   void __insert_operation(unsigned a_idx);

   inline int __compare_value(record_s &a_first,record_s &a_second);

   /*!
    * \brief __GEN initialize rb_tree
    */
   inline void init();

   /*!
    * \brief __GEN release memory used by rb_tree
    */
   inline void clear();

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
   inline void swap(rec_rb_tree_s &a_second);

   /*!
    * \brief __GEN select ode of rb_tree
    * \param a_idx - index of node in rb_tree
    * \return reference to node of rb_tree
    */
   inline record_s &operator[](unsigned a_idx);

   /*!
    * \brief __GEN insert node to rb_tree
    * \param a_value - reference to value inserted to rb_tree
    * \return - position of node in rb_tree
    */
   inline unsigned insert(record_s &a_value);

   /*!
    * \brief __GEN insert node to rb_tree if it not exist yet
    * \param a_value - reference to value inserted to rb_tree
    * \return - position of node in rb_tree
    */
   inline unsigned unique_insert(record_s &a_value);

   /*!
    * \brief __GEN insert node to rb_tree by swapping
    * \param a_value - reference to value inserted to rb_tree
    * \return - position of node in rb_tree
    */
   inline unsigned swap_insert(record_s &a_value);

   /*!
    * \brief __GEN insert node to rb_tree by swapping if it not exist yet
    * \param a_value - reference to value inserted to rb_tree
    * \return - position of node in rb_tree
    */
   inline unsigned unique_swap_insert(record_s &a_value);

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
   unsigned get_idx(record_s &a_value);

   /*!
    * \brief __GEN search for leftmost index of node
    * \param a_value - value which index is searched
    */
   unsigned get_idx_left(record_s &a_value);

   /*!
    * \brief __GEN search for index of node with greater or equal value
    * \param a_value - value which index is searched
    */
   unsigned get_gre_idx(record_s &a_value);

   /*!
    * \brief __GEN search for index of node with less or equal value
    * \param a_value - value which index is searched
    */
   unsigned get_lee_idx(record_s &a_value);
   /*!
    * \brief __GEN search for all indexes of node
    * \param a_value - value of searched index
    */
   void get_idxs(record_s &a_value,ui_array_s &a_idxs_array);

   /*!
    * \brief __GEN copy rb_tree from another rb_tree
    * \param a_src - reference to another rb_tree
    * \return reference to this rb_tree
    */
   inline rec_rb_tree_s &operator=(rec_rb_tree_s &a_src);

   /*!
    * \brief __GEN compare rb_tree with another rb_tree
    * \param a_second - reference to another rb_tree
    * \return result of comparision
    */
   bool operator==(rec_rb_tree_s &a_second);

   /*!
    * \brief __GEN rehash tree (after invalidation by change of object value)
    */
    void rehash_tree();

};



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
   if (data != nullptr) {
      cfree(data);
   }

   init();
}/*}}}*/

inline void ui_array_s::set(unsigned a_used,unsigned *a_data)
{/*{{{*/
   clear();
   if (a_used == 0) return;
   
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
   if (used >= size) {
      copy_resize((size << 1) + c_array_add);
   }

   data[used++] = a_value;
}/*}}}*/

inline void ui_array_s::push_blank()
{/*{{{*/
   if (used >= size) {
      copy_resize((size << 1) + c_array_add);
   }

   used++;
}/*}}}*/

inline void ui_array_s::push_clear()
{/*{{{*/
   if (used >= size) {
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

   if (a_src.used == 0) return *this;

   copy_resize(a_src.used);
   memcpy(data,a_src.data,a_src.used*sizeof(unsigned));

   used = a_src.used;
   return *this;
}/*}}}*/

inline bool ui_array_s::operator==(ui_array_s &a_second)
{/*{{{*/
   if (used != a_second.used) return false;
   if (used == 0) return true;

   return (memcmp(data,a_second.data,used*sizeof(unsigned)) == 0);
}/*}}}*/



// -- rec_rb_tree_s --
// --- struct rec_rb_tree_s inline method definition ---

inline unsigned rec_rb_tree_s::__get_grandparent_idx(unsigned a_idx)
{/*{{{*/
   rec_rb_tree_s_node &node = data[a_idx];

   if (node.parent_idx != c_idx_not_exist) {
      return data[node.parent_idx].parent_idx;
   }
   else {
      return c_idx_not_exist;
   }
}/*}}}*/

inline unsigned rec_rb_tree_s::__get_uncle_idx(unsigned a_idx)
{/*{{{*/
   unsigned gp_idx = __get_grandparent_idx(a_idx);

   if (gp_idx == c_idx_not_exist) {
      return c_idx_not_exist;
   }
   else {
      rec_rb_tree_s_node &gp = data[gp_idx];
      return gp.left_idx == data[a_idx].parent_idx?gp.right_idx:gp.left_idx;
   }
}/*}}}*/

inline unsigned rec_rb_tree_s::__get_sibling_idx(unsigned a_idx)
{/*{{{*/
   rec_rb_tree_s_node &p = data[data[a_idx].parent_idx];
   return p.left_idx == a_idx?p.right_idx:p.left_idx;
}/*}}}*/

inline unsigned rec_rb_tree_s::get_descent_stack_size()
{/*{{{*/
   return (unsigned)(logf(used)/c_log_of_2) << 1;
}/*}}}*/

inline unsigned rec_rb_tree_s::get_stack_next_idx(unsigned a_idx,unsigned **a_s_ptr,unsigned *a_stack_base)
{/*{{{*/
   debug_assert(a_idx < used);

   rec_rb_tree_s_node &node = data[a_idx];

   if (node.right_idx != leaf_idx) {
      return get_stack_min_value_idx(node.right_idx,a_s_ptr);
   }

   if (*a_s_ptr > a_stack_base) {
      return *(--(*a_s_ptr));
   }
   
   return c_idx_not_exist;
}/*}}}*/

inline void rec_rb_tree_s::__rotate_left(unsigned a_idx)
{/*{{{*/
   rec_rb_tree_s_node &root = data[a_idx];
   rec_rb_tree_s_node &pivot = data[root.right_idx];

   if (a_idx == root_idx) {
      root_idx = root.right_idx;
      pivot.parent_idx = c_idx_not_exist;
   }
   else {
      rec_rb_tree_s_node &rp = data[root.parent_idx];
      (rp.right_idx == a_idx?rp.right_idx:rp.left_idx) = root.right_idx;

      pivot.parent_idx = root.parent_idx;
   }

   root.parent_idx = root.right_idx;

   root.right_idx = pivot.left_idx;
   data[root.right_idx].parent_idx = a_idx;

   pivot.left_idx = a_idx;
}/*}}}*/

inline void rec_rb_tree_s::__rotate_right(unsigned a_idx)
{/*{{{*/
   rec_rb_tree_s_node &root = data[a_idx];
   rec_rb_tree_s_node &pivot = data[root.left_idx];

   if (a_idx == root_idx) {
      root_idx = root.left_idx;
      pivot.parent_idx = c_idx_not_exist;
   }
   else {
      rec_rb_tree_s_node &rp = data[root.parent_idx];
      (rp.right_idx == a_idx?rp.right_idx:rp.left_idx) = root.left_idx;

      pivot.parent_idx = root.parent_idx;
   }

   root.parent_idx = root.left_idx;

   root.left_idx = pivot.right_idx;
   data[root.left_idx].parent_idx = a_idx;

   pivot.right_idx = a_idx;
}/*}}}*/

inline unsigned rec_rb_tree_s::__get_new_index()
{/*{{{*/
   if (free_idx != c_idx_not_exist) {
      unsigned new_idx = free_idx;
      free_idx = data[new_idx].parent_idx;

      return new_idx;
   }
   else {
      if (used >= size) {
         copy_resize((size << 1) + c_array_add);
      }

      return used++;
   }
}/*}}}*/

inline void rec_rb_tree_s::__replace_delete_node_by_child(unsigned a_idx,unsigned a_ch_idx)
{/*{{{*/
   rec_rb_tree_s_node &node = data[a_idx];

   if (node.parent_idx != c_idx_not_exist) {
      rec_rb_tree_s_node &parent = data[node.parent_idx];
      (parent.left_idx == a_idx?parent.left_idx:parent.right_idx) = a_ch_idx;

      data[a_ch_idx].parent_idx = node.parent_idx;
   }
   else {
      root_idx = a_ch_idx == leaf_idx?c_idx_not_exist:a_ch_idx;
      data[a_ch_idx].parent_idx = c_idx_not_exist;
   }
}/*}}}*/

inline void rec_rb_tree_s::__remove_one_child(unsigned a_idx,unsigned a_ch_idx)
{/*{{{*/
   rec_rb_tree_s_node &node = data[a_idx];
   __replace_delete_node_by_child(a_idx,a_ch_idx);

   node.parent_idx = free_idx;
   free_idx = a_idx;

   if (node.color) {
      rec_rb_tree_s_node &child_node = data[a_ch_idx];

      if (!child_node.color) {
         child_node.color = true;
      }
      else {
         __remove_black_black(a_ch_idx);
      }
   }
}/*}}}*/

inline void rec_rb_tree_s::init()
{/*{{{*/
   size = 0;
   used = 0;
   data = nullptr;
   free_idx = c_idx_not_exist;
   root_idx = c_idx_not_exist;
   leaf_idx = c_idx_not_exist;
}/*}}}*/

inline void rec_rb_tree_s::clear()
{/*{{{*/
   if (data != nullptr) {
      cfree(data);
   }

   init();
}/*}}}*/

inline void rec_rb_tree_s::flush()
{/*{{{*/
   copy_resize(used);
}/*}}}*/

inline void rec_rb_tree_s::flush_all()
{/*{{{*/
   copy_resize(used);
}/*}}}*/

inline void rec_rb_tree_s::swap(rec_rb_tree_s &a_second)
{/*{{{*/
   unsigned tmp_unsigned = size;
   size = a_second.size;
   a_second.size = tmp_unsigned;

   tmp_unsigned = used;
   used = a_second.used;
   a_second.used = tmp_unsigned;

   rec_rb_tree_s_node *tmp_data = data;
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

inline record_s &rec_rb_tree_s::operator[](unsigned a_idx)
{/*{{{*/
   debug_assert(a_idx < used);
   return data[a_idx].object;
}/*}}}*/

inline unsigned rec_rb_tree_s::insert(record_s &a_value)
{/*{{{*/
   unsigned new_node_idx = __get_new_index();

   __binary_tree_insert(new_node_idx,a_value,false);
   __insert_operation(new_node_idx);

   data[new_node_idx].object = a_value;

   return new_node_idx;
}/*}}}*/

inline unsigned rec_rb_tree_s::swap_insert(record_s &a_value)
{/*{{{*/
   unsigned new_node_idx = __get_new_index();

   __binary_tree_insert(new_node_idx,a_value,false);
   __insert_operation(new_node_idx);

   data[new_node_idx].object.swap(a_value);

   return new_node_idx;
}/*}}}*/

inline unsigned rec_rb_tree_s::unique_insert(record_s &a_value)
{/*{{{*/
   unsigned new_node_idx = __get_new_index();
   unsigned old_node_idx = __binary_tree_insert(new_node_idx,a_value,true);

   if (old_node_idx != c_idx_not_exist) {
      rec_rb_tree_s_node &new_node = data[new_node_idx];

      new_node.parent_idx = free_idx;
      free_idx = new_node_idx;

      return old_node_idx;
   }

   __insert_operation(new_node_idx);

   data[new_node_idx].object = a_value;

  return new_node_idx;
}/*}}}*/

inline unsigned rec_rb_tree_s::unique_swap_insert(record_s &a_value)
{/*{{{*/
   unsigned new_node_idx = __get_new_index();
   unsigned old_node_idx = __binary_tree_insert(new_node_idx,a_value,true);

   if (old_node_idx != c_idx_not_exist) {
      rec_rb_tree_s_node &new_node = data[new_node_idx];

      new_node.parent_idx = free_idx;
      free_idx = new_node_idx;

      return old_node_idx;
   }

   __insert_operation(new_node_idx);

   data[new_node_idx].object.swap(a_value);

  return new_node_idx;
}/*}}}*/

inline rec_rb_tree_s &rec_rb_tree_s::operator=(rec_rb_tree_s &a_src)
{/*{{{*/
   clear();

   if (a_src.root_idx == c_idx_not_exist) return *this;

   copy_resize(a_src.used);
   memcpy(data,a_src.data,a_src.used*sizeof(rec_rb_tree_s_node));

   used = a_src.used;
   free_idx = a_src.free_idx;
   root_idx = a_src.root_idx;
   leaf_idx = a_src.leaf_idx;

   return *this;
}/*}}}*/



inline int rec_rb_tree_s::__compare_value(record_s &a_first,record_s &a_second)
{
  unsigned &fi = a_first.index;
  unsigned &si = a_second.index;

  return fi < si ? -1 : fi > si ? 1 : 0;
}

/*
 * definition of global methods
 */

void print_tree(rec_rb_tree_s &rec_tree,const char *name);

#endif



/*
 * methods of generated structures
 */

// -- ui_array_s --
// --- struct ui_array_s method definition ---

void ui_array_s::reserve(unsigned a_cnt)
{/*{{{*/
   unsigned required_cnt = used + a_cnt;
   if (required_cnt > size) {
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
   if (required_cnt > size) {
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

   if (a_size == 0) {
      if (data != nullptr) {
         cfree(data);
      }
      data = nullptr;
   }
   else {
      data = (unsigned *)crealloc(data,a_size*sizeof(unsigned));
   }

   size = a_size;
}/*}}}*/

void ui_array_s::fill(unsigned a_value)
{/*{{{*/
   if (size == 0) return;

   unsigned *ptr = data;
   unsigned *ptr_end = data + size;

   do {
      *ptr = a_value;
   } while(++ptr < ptr_end);

   used = size;
}/*}}}*/

unsigned ui_array_s::get_idx(unsigned a_value)
{/*{{{*/
   if (used == 0) return c_idx_not_exist;

   unsigned *ptr = data;
   unsigned *ptr_end = data + used;

   do {
      if (*ptr == a_value) {
         return ptr - data;
      }
   } while(++ptr < ptr_end);

   return c_idx_not_exist;
}/*}}}*/



// -- rec_rb_tree_s --
// --- struct rec_rb_tree_s method definition ---

unsigned rec_rb_tree_s::get_stack_min_value_idx(unsigned a_idx,unsigned **a_s_ptr)
{/*{{{*/
   debug_assert(a_idx < used);

   unsigned node_idx = a_idx;
   do {
      rec_rb_tree_s_node &node = data[node_idx];

      if (node.left_idx == leaf_idx) {
         return node_idx;
      }

      *((*a_s_ptr)++) = node_idx;
      node_idx = node.left_idx;
   } while(1);
}/*}}}*/

unsigned rec_rb_tree_s::get_min_value_idx(unsigned a_idx)
{/*{{{*/
   debug_assert(a_idx < used);

   unsigned node_idx = a_idx;
   do {
      rec_rb_tree_s_node &node = data[node_idx];

      if (node.left_idx == leaf_idx) {
         return node_idx;
      }

      node_idx = node.left_idx;
   } while(1);
}/*}}}*/

unsigned rec_rb_tree_s::get_max_value_idx(unsigned a_idx)
{/*{{{*/
   debug_assert(a_idx < used);

   unsigned node_idx = a_idx;
   do {
      rec_rb_tree_s_node &node = data[node_idx];

      if (node.right_idx == leaf_idx) {
         return node_idx;
      }

      node_idx = node.right_idx;
   } while(1);
}/*}}}*/

unsigned rec_rb_tree_s::get_next_idx(unsigned a_idx)
{/*{{{*/
   debug_assert(a_idx < used);

   rec_rb_tree_s_node &node = data[a_idx];

   if (node.right_idx != leaf_idx) {
      return get_min_value_idx(node.right_idx);
   }
   else {

      unsigned node_idx = a_idx;
      do {
         rec_rb_tree_s_node &node = data[node_idx];

         if (node.parent_idx == c_idx_not_exist) {
            return c_idx_not_exist;
         }
         
         if (data[node.parent_idx].right_idx != node_idx) {
            return node.parent_idx;
         }

         node_idx = node.parent_idx;
      } while(1);
   }
}/*}}}*/

unsigned rec_rb_tree_s::get_prev_idx(unsigned a_idx)
{/*{{{*/
   debug_assert(a_idx < used);

   rec_rb_tree_s_node &node = data[a_idx];

   if (node.left_idx != leaf_idx) {
      return get_max_value_idx(node.left_idx);
   }
   else {

      unsigned node_idx = a_idx;
      do {
         rec_rb_tree_s_node &node = data[node_idx];

         if (node.parent_idx == c_idx_not_exist) {
            return c_idx_not_exist;
         }
         
         if (data[node.parent_idx].left_idx != node_idx) {
            return node.parent_idx;
         }

         node_idx = node.parent_idx;
      } while(1);
   }
}/*}}}*/

unsigned rec_rb_tree_s::__binary_tree_insert(unsigned a_new_idx,record_s &a_value,bool a_unique)
{/*{{{*/
   if (root_idx == c_idx_not_exist) {
      if (leaf_idx == c_idx_not_exist) {
         leaf_idx = __get_new_index();
         rec_rb_tree_s_node &leaf = data[leaf_idx];

         leaf.color = true;

#ifdef RB_TREE_SET_LEAF_CHILDS
         leaf.left_idx = c_idx_not_exist;
         leaf.right_idx = c_idx_not_exist;
#endif
      }

      data[a_new_idx].parent_idx = c_idx_not_exist;
      root_idx = a_new_idx;
   }
   else  {
      unsigned node_idx = root_idx;
      do {
         rec_rb_tree_s_node &node = data[node_idx];
         
         int comp_result = __compare_value(a_value,node.object);
         if (comp_result < 0) {
            if (node.left_idx == leaf_idx) {
               node.left_idx = a_new_idx;
               break;
            }
            node_idx = node.left_idx;
         }
         else {
            if (a_unique && comp_result == 0) {
               return node_idx;
            }

            if (node.right_idx == leaf_idx) {
               node.right_idx = a_new_idx;
               break;
            }
            node_idx = node.right_idx;
         }
      } while(1);

      data[a_new_idx].parent_idx = node_idx;
   }

   rec_rb_tree_s_node &new_node = data[a_new_idx];
   new_node.left_idx = leaf_idx;
   new_node.right_idx = leaf_idx;
   new_node.color = false;

   return c_idx_not_exist;
}/*}}}*/

void rec_rb_tree_s::__remove_black_black(unsigned a_idx)
{/*{{{*/
   unsigned node_idx = a_idx;
   do {
      rec_rb_tree_s_node &node = data[node_idx];
      
      if (node.parent_idx == c_idx_not_exist) {
         return;
      }

      unsigned parent_idx = node.parent_idx;
      rec_rb_tree_s_node &parent = data[parent_idx];

      {
         unsigned sibling_idx = parent.left_idx == node_idx?parent.right_idx:parent.left_idx;
         rec_rb_tree_s_node &sibling = data[sibling_idx];

         if (!sibling.color) {
            parent.color = false;
            sibling.color = true;

            if (node_idx == parent.left_idx) {
               __rotate_left(parent_idx);
            }
            else {
               __rotate_right(parent_idx);
            }
         }
      }

      {
         unsigned sibling_idx = parent.left_idx == node_idx?parent.right_idx:parent.left_idx;
         rec_rb_tree_s_node& sibling = data[sibling_idx];

         if (parent.color && sibling.color && data[sibling.left_idx].color && data[sibling.right_idx].color) {
            sibling.color = false;
            node_idx = parent_idx;
            continue;
         }
         else if (!parent.color && sibling.color && data[sibling.left_idx].color && data[sibling.right_idx].color) {
            sibling.color = false;
            parent.color = true;
            return;
         }
         else if (sibling.color) {
            if (node_idx == parent.left_idx && data[sibling.right_idx].color && !data[sibling.left_idx].color) {
               sibling.color = false;
               data[sibling.left_idx].color = true;
               __rotate_right(sibling_idx);
            }
            else if (node_idx == parent.right_idx && data[sibling.left_idx].color && !data[sibling.right_idx].color) {
               sibling.color = false;
               data[sibling.right_idx].color = true;
               __rotate_left(sibling_idx);
            }
         }

         {
            unsigned sibling_idx = parent.left_idx == node_idx?parent.right_idx:parent.left_idx;
            rec_rb_tree_s_node &sibling = data[sibling_idx];

            sibling.color = parent.color;
            parent.color = true;

            if (node_idx == parent.left_idx) {
               data[sibling.right_idx].color = true;
               __rotate_left(parent_idx);
            }
            else {
               data[sibling.left_idx].color = true;
               __rotate_right(parent_idx);
            }
         }

         return;
      }

   } while(1);
}/*}}}*/

void rec_rb_tree_s::__insert_operation(unsigned a_idx)
{/*{{{*/
   unsigned node_idx = a_idx;
   do {
      rec_rb_tree_s_node &node = data[node_idx];

      if (node.parent_idx == c_idx_not_exist) {
         node.color = true;
         return;
      }
      else {
         if (data[node.parent_idx].color) {
            return;
         }
         else {
            unsigned uncle_idx = __get_uncle_idx(node_idx);
            if (uncle_idx != c_idx_not_exist && !data[uncle_idx].color) {
               data[node.parent_idx].color = true;
               data[uncle_idx].color = true;

               node_idx = __get_grandparent_idx(node_idx);
               data[node_idx].color = false;

               continue;
            }
            else {
               unsigned grandparent_idx = __get_grandparent_idx(node_idx);

               if (node_idx == data[node.parent_idx].right_idx && node.parent_idx == data[grandparent_idx].left_idx) {
                  __rotate_left(node.parent_idx);
                  node_idx = node.left_idx;
               }
               else if (node_idx == data[node.parent_idx].left_idx && node.parent_idx == data[grandparent_idx].right_idx) {
                  __rotate_right(node.parent_idx);
                  node_idx = node.right_idx;
               }

               {
                  unsigned grandparent_idx = __get_grandparent_idx(node_idx);
                  rec_rb_tree_s_node &node = data[node_idx];

                  data[node.parent_idx].color = true;
                  data[grandparent_idx].color = false;

                  if (node_idx == data[node.parent_idx].left_idx && node.parent_idx == data[grandparent_idx].left_idx) {
                     __rotate_right(grandparent_idx);
                  }
                  else {
                     __rotate_left(grandparent_idx);
                  }
               }

               return;
            }
         }
      }
   } while(1);
}/*}}}*/

void rec_rb_tree_s::remove(unsigned a_idx)
{/*{{{*/
   debug_assert(a_idx < used);

   rec_rb_tree_s_node &del_node = data[a_idx];

   if (del_node.left_idx != leaf_idx) {
      if (del_node.right_idx != leaf_idx) {
         
         unsigned found_idx = del_node.right_idx;
         do {
            rec_rb_tree_s_node &node = data[found_idx];

            if (node.left_idx == leaf_idx) {
               break;
            }

            found_idx = node.left_idx;
         } while(1);

         rec_rb_tree_s_node &found_node = data[found_idx];

         /* - process del_node parent_idx - */
         if (del_node.parent_idx != c_idx_not_exist) {
            rec_rb_tree_s_node &del_node_parent = data[del_node.parent_idx];
            (del_node_parent.left_idx == a_idx?del_node_parent.left_idx:del_node_parent.right_idx) = found_idx;
         }
         else {
            root_idx = found_idx;
         }

         /* - process del_node left_idx - */
         data[del_node.left_idx].parent_idx = found_idx;

         /* - process found_node right_idx - */
         if (found_node.right_idx != leaf_idx) {
            data[found_node.right_idx].parent_idx = a_idx;
         }

         if (del_node.right_idx == found_idx) {
            
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
         else {
            
            /* - process found_node parent - */
            rec_rb_tree_s_node &found_node_parent = data[found_node.parent_idx];
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
      else {
         __remove_one_child(a_idx,del_node.left_idx);
      }
   }
   else {
      __remove_one_child(a_idx,del_node.right_idx);
   }

}/*}}}*/

void rec_rb_tree_s::copy_resize(unsigned a_size)
{/*{{{*/
   debug_assert(a_size >= used);

   if (a_size == 0) {
      if (data != nullptr) {
         cfree(data);
      }
      data = nullptr;
   }
   else {
      data = (rec_rb_tree_s_node *)crealloc(data,a_size*sizeof(rec_rb_tree_s_node));
   }

   size = a_size;
}/*}}}*/

unsigned rec_rb_tree_s::get_idx(record_s &a_value)
{/*{{{*/
   if (root_idx == c_idx_not_exist) {
      return c_idx_not_exist;
   }

   unsigned node_idx = root_idx;
   do {
      rec_rb_tree_s_node &node = data[node_idx];

      int comp_result = __compare_value(a_value,node.object);
      if (comp_result < 0) {
         node_idx = node.left_idx;
      }
      else {
         if (comp_result == 0) {
            return node_idx;
         }

         node_idx = node.right_idx;
      }
   } while(node_idx != leaf_idx);

   return c_idx_not_exist;
}/*}}}*/

unsigned rec_rb_tree_s::get_idx_left(record_s &a_value)
{/*{{{*/
   if (root_idx == c_idx_not_exist) {
      return c_idx_not_exist;
   }

   unsigned good_idx = c_idx_not_exist;
   unsigned node_idx = root_idx;
   do {
      rec_rb_tree_s_node &node = data[node_idx];

      int comp_result = __compare_value(a_value,node.object);
      if (comp_result < 0) {
         node_idx = node.left_idx;
      }
      else {
         if (comp_result == 0) {
            good_idx = node_idx;
            node_idx = node.left_idx;
         }
         else {
            node_idx = node.right_idx;
         }
      }
   } while(node_idx != leaf_idx);

   return good_idx;
}/*}}}*/

unsigned rec_rb_tree_s::get_gre_idx(record_s &a_value)
{/*{{{*/
   if (root_idx == c_idx_not_exist) {
      return c_idx_not_exist;
   }

   unsigned good_idx = c_idx_not_exist;
   unsigned node_idx = root_idx;
   do {
      rec_rb_tree_s_node &node = data[node_idx];

      int comp_result = __compare_value(a_value,node.object);
      if (comp_result < 0) {
         good_idx = node_idx;
         node_idx = node.left_idx;
      }
      else {
         if (comp_result == 0) {
            return node_idx;
         }

         node_idx = node.right_idx;
      }
   } while(node_idx != leaf_idx);

   return good_idx;
}/*}}}*/

unsigned rec_rb_tree_s::get_lee_idx(record_s &a_value)
{/*{{{*/
   if (root_idx == c_idx_not_exist) {
      return c_idx_not_exist;
   }

   unsigned good_idx = c_idx_not_exist;
   unsigned node_idx = root_idx;
   do {
      rec_rb_tree_s_node &node = data[node_idx];

      int comp_result = __compare_value(a_value,node.object);
      if (comp_result < 0) {
         node_idx = node.left_idx;
      }
      else {
         if (comp_result == 0) {
            return node_idx;
         }

         good_idx = node_idx;
         node_idx = node.right_idx;
      }
   } while(node_idx != leaf_idx);

   return good_idx;
}/*}}}*/

void rec_rb_tree_s::get_idxs(record_s &a_value,ui_array_s &a_idxs_array)
{/*{{{*/
   a_idxs_array.used = 0;

   if (root_idx == c_idx_not_exist) {
      return;
   }

   unsigned stack[get_descent_stack_size()];
   unsigned *stack_ptr = stack;

   *(stack_ptr++) = root_idx;
   do {
      unsigned node_idx = *(--stack_ptr);
      rec_rb_tree_s_node &node = data[node_idx];

      int comp_result = __compare_value(a_value,node.object);
      if (comp_result < 0) {
         if (node.left_idx != leaf_idx) {
            *(stack_ptr++) = node.left_idx;
         }
      }
      else {
         if (comp_result == 0) {
            a_idxs_array.push(node_idx);

            if (node.left_idx != leaf_idx) {
               *(stack_ptr++) = node.left_idx;
            }
         }

         if (node.right_idx != leaf_idx) {
            *(stack_ptr++) = node.right_idx;
         }
      }
   } while(stack_ptr > stack);

   return;
}/*}}}*/

bool rec_rb_tree_s::operator==(rec_rb_tree_s &a_second)
{/*{{{*/
   if (root_idx == c_idx_not_exist) {
      if (a_second.root_idx != c_idx_not_exist) {
         return false;
      }
   }
   else {
      if (a_second.root_idx == c_idx_not_exist) {
         return false;
      }

      unsigned stack[get_descent_stack_size()];
      unsigned s_stack[a_second.get_descent_stack_size()];

      unsigned *stack_ptr = stack;
      unsigned *s_stack_ptr = s_stack;

      unsigned node_idx = get_stack_min_value_idx(root_idx,&stack_ptr);
      unsigned s_node_idx = a_second.get_stack_min_value_idx(a_second.root_idx,&s_stack_ptr);
      do {
         if (!(data[node_idx].object == a_second.data[s_node_idx].object)) {
            return false;
         }

         node_idx = get_stack_next_idx(node_idx,&stack_ptr,stack);
         s_node_idx = a_second.get_stack_next_idx(s_node_idx,&s_stack_ptr,s_stack);
      } while(node_idx != c_idx_not_exist && s_node_idx != c_idx_not_exist);

      if (node_idx != s_node_idx) {
         return false;
      }
   }

   return true;
}/*}}}*/

void rec_rb_tree_s::rehash_tree()
{/*{{{*/
   if (root_idx == c_idx_not_exist) return;

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
   if (step > 0) {
      do {
         unsigned idx = step;
         do {
            if (!processed[idx]) {
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



/*
 * global methods
 */

void print_tree(rec_rb_tree_s &rec_tree,const char *name)
{
  printf("%s.size:  %u\n",name,rec_tree.size);
  printf("%s.used:  %u\n",name,rec_tree.used);
  printf("%s.free_idx: %u\n",name,rec_tree.free_idx);
  printf("%s.root_idx: %u\n",name,rec_tree.root_idx);
  printf("%s.leaf_idx: %u\n",name,rec_tree.leaf_idx);
  printf("%s: ",name);

  if (rec_tree.root_idx != c_idx_not_exist)
  {
    unsigned stack[rec_tree.get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned idx = rec_tree.get_stack_min_value_idx(rec_tree.root_idx,&stack_ptr);
    do
    {
      record_s &rec = rec_tree[idx];
      printf("{%u,%u}",rec.index,rec.value);

      idx = rec_tree.get_stack_next_idx(idx,&stack_ptr,stack);
    }
    while(idx != c_idx_not_exist);
  }

  printf("\n");
  printf("\n");
}

int main(int argc, char **argv)
{
  record_s rec;
  rec.init();
  rec.set(1,1);

  rec_rb_tree_s rb_tree0;
  rb_tree0.init();

  print_tree(rb_tree0,"rb_tree0");

  printf("--- INSERT NEW RECORDS TO RB_TREE ---\n");
  
  unsigned idx = 0;
  do {
    rec.index = idx;
    rb_tree0.insert(rec);
  } while(++idx < 7);

  print_tree(rb_tree0,"rb_tree0");

  printf("--- REMOVE RECORDS FROM RB_TREE ---\n");
  
  idx = rb_tree0.get_min_value_idx(rb_tree0.root_idx);
  unsigned count = 0;
  do {
    unsigned next_idx = rb_tree0.get_next_idx(idx);
    rb_tree0.remove(idx);

    idx = next_idx;
  } while(++count < 3);

  print_tree(rb_tree0,"rb_tree0");

  printf("--- INSERT NEW RECORDS TO RB_TREE ---\n");
  
  idx = 0;
  do {
    rec.index = idx + 4;
    rb_tree0.insert(rec);
  } while(++idx < 4);

  print_tree(rb_tree0,"rb_tree0");

  printf("--- CREATE NEW EMPTY RB_TREE ---\n");
  rec_rb_tree_s rb_tree1;
  rb_tree1.init();

  print_tree(rb_tree0,"rb_tree0");
  print_tree(rb_tree1,"rb_tree1");

  printf("--- COMPARE RB_TREE CONTENT ---\n");
  printf("rb_tree0 == rb_tree1: %s\n",rb_tree0 == rb_tree1 ? "TRUE" : "FALSE");
  printf("\n");

  printf("--- ASSIGN RB_TREE CONTENT ---\n");
  rb_tree1 = rb_tree0;

  print_tree(rb_tree0,"rb_tree0");
  print_tree(rb_tree1,"rb_tree1");

  printf("--- COMPARE RB_TREE CONTENT ---\n");
  printf("rb_tree0 == rb_tree1: %s\n",rb_tree0 == rb_tree1 ? "TRUE" : "FALSE");
  printf("\n");

  rb_tree1.clear();
  rb_tree0.clear();
  rec.clear();

  return 0;
}


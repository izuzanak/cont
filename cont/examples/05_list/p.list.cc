
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



#ifndef __LIST_H
#define __LIST_H


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

// -- rec_list_s --
// struct rec_list_s definition

/*!
 * \brief __GEN element of list of type record_s
 */

struct rec_list_s_element
{
  record_s object;
  unsigned next_idx;
  unsigned prev_idx;
};

/*!
 * \brief __GEN list of type record_s
 */
struct rec_list_s
{
  unsigned size; //!< actual size of allocated space (element count)
  unsigned used; //!< used part of allocated space
  rec_list_s_element *data; //!< pointer to list elements
  unsigned free_idx; //!< index of first free element
  unsigned first_idx; //!< index of first element
  unsigned last_idx; //!< index of last element

  /*!
    * \brief __GEN initialize list
    */
  inline void init();

  /*!
    * \brief __GEN initialize list of requested size
    * \param a_size - requested size of list
    */
  inline void init_size(unsigned a_size);

  /*!
    * \brief __GEN release memory used by list
    */
  inline void clear();

  /*!
    * \brief __GEN flush list memory usage
    */
  inline void flush();

  /*!
    * \brief __GEN flush list memory usage, recursive on elements
    */
  inline void flush_all();

  /*!
    * \brief __GEN swap members of list with another list
    * \param a_second - reference to another list
    */
  inline void swap(rec_list_s &a_second);

  /*!
    * \brief __GEN select element of list
    * \param a_idx - index of element in list
    * \return reference to element of list
    */
  inline record_s &operator[](unsigned a_idx);

  /*!
    * \brief __GEN prepend element to list
    * \param a_value - reference to value prepended to list
    * \return - position of element in list
    */
  inline unsigned prepend(record_s &a_value);

  /*!
    * \brief __GEN append element to list
    * \param a_value - reference to value append to list
    * \return - position of element in list
    */
  inline unsigned append(record_s &a_value);

  /*!
    * \brief __GEN insert before element to list
    * \param a_value - value inserted to list
    * \return - position of element in list
    */
  inline unsigned insert_before(unsigned a_idx,record_s &a_value);

  /*!
    * \brief __GEN insert after element to list
    * \param a_value - value inserted to list
    * \return - position of element in list
    */
  inline unsigned insert_after(unsigned a_idx,record_s &a_value);

  inline unsigned prepend_blank();
  inline unsigned append_blank();
  inline unsigned insert_blank_before(unsigned a_idx);
  inline unsigned insert_blank_after(unsigned a_idx);

  /*!
    * \brief __GEN remove element at index from list
    * \param a_idx - index of element to remove
    */
  inline void remove(unsigned a_idx);

  /*!
    * \brief __GEN return index of next element in list
    * \param a_idx - index of element
    */
  inline unsigned next_idx(unsigned a_idx);

  /*!
    * \brief __GEN return index of previous element in list
    * \param a_idx - index of element
    */
  inline unsigned prev_idx(unsigned a_idx);

  /*!
    * \brief __GEN resize list capacity
    * \param a_size - requested list capacity
    */
  void copy_resize(unsigned a_size);

  /*!
    * \brief __GEN search for index of element
    * \param a_value - value which index is searched
    */
  unsigned get_idx(record_s &a_value);
  /*!
    * \brief __GEN copy list from another list
    * \param a_src - reference to another list
    * \return reference to this list
    */
  inline rec_list_s &operator=(rec_list_s &a_src);

  /*!
    * \brief __GEN compare list with another list
    * \param a_second - reference to another list
    * \return result of comparision
    */
  bool operator==(rec_list_s &a_second);

};



/*
 * inline methods of generated structures
 */

// -- rec_list_s --
// --- struct rec_list_s inline method definition ---

inline void rec_list_s::init()
{/*{{{*/
  size = 0;
  used = 0;
  data = nullptr;
  free_idx = c_idx_not_exist;
  first_idx = c_idx_not_exist;
  last_idx = c_idx_not_exist;
}/*}}}*/

inline void rec_list_s::init_size(unsigned a_size)
{/*{{{*/
  init();
  copy_resize(a_size);
}/*}}}*/

inline void rec_list_s::clear()
{/*{{{*/
  if (data != nullptr)
  {
    cfree(data);
  }

  init();
}/*}}}*/

inline void rec_list_s::flush()
{/*{{{*/
  copy_resize(used);
}/*}}}*/

inline void rec_list_s::flush_all()
{/*{{{*/
  copy_resize(used);
}/*}}}*/

inline void rec_list_s::swap(rec_list_s &a_second)
{/*{{{*/
  unsigned tmp_unsigned = size;
  size = a_second.size;
  a_second.size = tmp_unsigned;

  tmp_unsigned = used;
  used = a_second.used;
  a_second.used = tmp_unsigned;

  rec_list_s_element *tmp_data = data;
  data = a_second.data;
  a_second.data = tmp_data;

  tmp_unsigned = free_idx;
  free_idx = a_second.free_idx;
  a_second.free_idx = tmp_unsigned;

  tmp_unsigned = first_idx;
  first_idx = a_second.first_idx;
  a_second.first_idx = tmp_unsigned;

  tmp_unsigned = last_idx;
  last_idx = a_second.last_idx;
  a_second.last_idx = tmp_unsigned;
}/*}}}*/

inline record_s &rec_list_s::operator[](unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < used);
  return data[a_idx].object;
}/*}}}*/

inline unsigned rec_list_s::prepend(record_s &a_value)
{/*{{{*/
  unsigned new_idx;

  if (free_idx != c_idx_not_exist)
  {
    new_idx = free_idx;
    free_idx = data[new_idx].next_idx;
  }
  else
  {
    if (used >= size)
    {
      copy_resize((size << 1) + c_array_add);
    }

    new_idx = used++;
  }

  rec_list_s_element &new_element = data[new_idx];

  new_element.next_idx = first_idx;
  new_element.prev_idx = c_idx_not_exist;

  if (first_idx != c_idx_not_exist)
  {
    data[first_idx].prev_idx = new_idx;
  }
  else
  {
    last_idx = new_idx;
  }

  first_idx = new_idx;

  new_element.object = a_value;

  return new_idx;
}/*}}}*/

inline unsigned rec_list_s::append(record_s &a_value)
{/*{{{*/
  unsigned new_idx;

  if (free_idx != c_idx_not_exist)
  {
    new_idx = free_idx;
    free_idx = data[new_idx].next_idx;
  }
  else
  {
    if (used >= size)
    {
      copy_resize((size << 1) + c_array_add);
    }

    new_idx = used++;
  }

  rec_list_s_element &new_element = data[new_idx];

  new_element.next_idx = c_idx_not_exist;
  new_element.prev_idx = last_idx;

  if (last_idx != c_idx_not_exist)
  {
    data[last_idx].next_idx = new_idx;
  }
  else
  {
    first_idx = new_idx;
  }

  last_idx = new_idx;

  new_element.object = a_value;

  return new_idx;
}/*}}}*/

inline unsigned rec_list_s::insert_before(unsigned a_idx,record_s &a_value)
{/*{{{*/
  debug_assert(a_idx < used);

  unsigned new_idx;

  if (free_idx != c_idx_not_exist)
  {
    new_idx = free_idx;
    free_idx = data[new_idx].next_idx;
  }
  else
  {
    if (used >= size)
    {
      copy_resize((size << 1) + c_array_add);
    }

    new_idx = used++;
  }

  rec_list_s_element &idx_element = data[a_idx];
  rec_list_s_element &new_element = data[new_idx];

  new_element.next_idx = a_idx;
  new_element.prev_idx = idx_element.prev_idx;

  if (idx_element.prev_idx != c_idx_not_exist)
  {
    data[idx_element.prev_idx].next_idx = new_idx;
  }
  else
  {
    first_idx = new_idx;
  }

  idx_element.prev_idx = new_idx;

  new_element.object = a_value;

  return new_idx;
}/*}}}*/

inline unsigned rec_list_s::insert_after(unsigned a_idx,record_s &a_value)
{/*{{{*/
  debug_assert(a_idx < used);

  unsigned new_idx;

  if (free_idx != c_idx_not_exist)
  {
    new_idx = free_idx;
    free_idx = data[new_idx].next_idx;
  }
  else
  {
    if (used >= size)
    {
      copy_resize((size << 1) + c_array_add);
    }

    new_idx = used++;
  }

  rec_list_s_element &idx_element = data[a_idx];
  rec_list_s_element &new_element = data[new_idx];

  new_element.next_idx = idx_element.next_idx;
  new_element.prev_idx = a_idx;

  if (idx_element.next_idx != c_idx_not_exist)
  {
    data[idx_element.next_idx].prev_idx = new_idx;
  }
  else
  {
    last_idx = new_idx;
  }

  idx_element.next_idx = new_idx;

  new_element.object = a_value;

  return new_idx;
}/*}}}*/

inline unsigned rec_list_s::prepend_blank()
{/*{{{*/
  unsigned new_idx;

  if (free_idx != c_idx_not_exist)
  {
    new_idx = free_idx;
    free_idx = data[new_idx].next_idx;
  }
  else
  {
    if (used >= size)
    {
      copy_resize((size << 1) + c_array_add);
    }

    new_idx = used++;
  }

  rec_list_s_element &new_element = data[new_idx];

  new_element.next_idx = first_idx;
  new_element.prev_idx = c_idx_not_exist;

  if (first_idx != c_idx_not_exist)
  {
    data[first_idx].prev_idx = new_idx;
  }
  else
  {
    last_idx = new_idx;
  }

  first_idx = new_idx;

  return new_idx;
}/*}}}*/

inline unsigned rec_list_s::append_blank()
{/*{{{*/
  unsigned new_idx;

  if (free_idx != c_idx_not_exist)
  {
    new_idx = free_idx;
    free_idx = data[new_idx].next_idx;
  }
  else
  {
    if (used >= size)
    {
      copy_resize((size << 1) + c_array_add);
    }

    new_idx = used++;
  }

  rec_list_s_element &new_element = data[new_idx];

  new_element.next_idx = c_idx_not_exist;
  new_element.prev_idx = last_idx;

  if (last_idx != c_idx_not_exist)
  {
    data[last_idx].next_idx = new_idx;
  }
  else
  {
    first_idx = new_idx;
  }

  last_idx = new_idx;

  return new_idx;
}/*}}}*/

inline unsigned rec_list_s::insert_blank_before(unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < used);

  unsigned new_idx;

  if (free_idx != c_idx_not_exist)
  {
    new_idx = free_idx;
    free_idx = data[new_idx].next_idx;
  }
  else
  {
    if (used >= size)
    {
      copy_resize((size << 1) + c_array_add);
    }

    new_idx = used++;
  }

  rec_list_s_element &idx_element = data[a_idx];
  rec_list_s_element &new_element = data[new_idx];

  new_element.next_idx = a_idx;
  new_element.prev_idx = idx_element.prev_idx;

  if (idx_element.prev_idx != c_idx_not_exist)
  {
    data[idx_element.prev_idx].next_idx = new_idx;
  }
  else
  {
    first_idx = new_idx;
  }

  idx_element.prev_idx = new_idx;

  return new_idx;
}/*}}}*/

inline unsigned rec_list_s::insert_blank_after(unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < used);

  unsigned new_idx;

  if (free_idx != c_idx_not_exist)
  {
    new_idx = free_idx;
    free_idx = data[new_idx].next_idx;
  }
  else
  {
    if (used >= size)
    {
      copy_resize((size << 1) + c_array_add);
    }

    new_idx = used++;
  }

  rec_list_s_element &idx_element = data[a_idx];
  rec_list_s_element &new_element = data[new_idx];

  new_element.next_idx = idx_element.next_idx;
  new_element.prev_idx = a_idx;

  if (idx_element.next_idx != c_idx_not_exist)
  {
    data[idx_element.next_idx].prev_idx = new_idx;
  }
  else
  {
    last_idx = new_idx;
  }

  idx_element.next_idx = new_idx;

  return new_idx;
}/*}}}*/

inline void rec_list_s::remove(unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < used);

  rec_list_s_element &rm_element = data[a_idx];

  if (rm_element.next_idx != c_idx_not_exist)
  {
    data[rm_element.next_idx].prev_idx = rm_element.prev_idx;
  }
  else
  {
    last_idx = rm_element.prev_idx;
  }

  if (rm_element.prev_idx != c_idx_not_exist)
  {
    data[rm_element.prev_idx].next_idx = rm_element.next_idx;
  }
  else
  {
    first_idx = rm_element.next_idx;
  }

  rm_element.next_idx = free_idx;
  free_idx = a_idx;
}/*}}}*/

inline unsigned rec_list_s::next_idx(unsigned a_idx)
{/*{{{*/
  return data[a_idx].next_idx;
}/*}}}*/

inline unsigned rec_list_s::prev_idx(unsigned a_idx)
{/*{{{*/
  return data[a_idx].prev_idx;
}/*}}}*/

inline rec_list_s &rec_list_s::operator=(rec_list_s &a_src)
{/*{{{*/
  clear();

  if (a_src.used == 0)
  {
    return *this;
  }

  copy_resize(a_src.used);
  memcpy(data,a_src.data,a_src.used*sizeof(rec_list_s_element));

  used = a_src.used;
  free_idx = a_src.free_idx;
  first_idx = a_src.first_idx;
  last_idx = a_src.last_idx;

  return *this;
}/*}}}*/



/*
 * definition of global methods
 */

void print_list(rec_list_s &rec_list,const char *name);

#endif



/*
 * methods of generated structures
 */

// -- rec_list_s --
// --- struct rec_list_s method definition ---

void rec_list_s::copy_resize(unsigned a_size)
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
    data = (rec_list_s_element *)crealloc(data,a_size*sizeof(rec_list_s_element));
  }

  size = a_size;
}/*}}}*/

unsigned rec_list_s::get_idx(record_s &a_value)
{/*{{{*/
  if (first_idx == c_idx_not_exist)
  {
    return c_idx_not_exist;
  }

  unsigned idx = first_idx;
  do {
    rec_list_s_element &element = data[idx];

    if (element.object == a_value)
    {
      return idx;
    }

    idx = element.next_idx;
  } while(idx != c_idx_not_exist);

  return c_idx_not_exist;
}/*}}}*/

bool rec_list_s::operator==(rec_list_s &a_second)
{/*{{{*/
  if (first_idx == c_idx_not_exist)
  {
    return a_second.first_idx == c_idx_not_exist;
  }

  if (a_second.first_idx == c_idx_not_exist)
  {
    return false;
  }

  unsigned idx = first_idx;
  unsigned s_idx = a_second.first_idx;

  do {
    rec_list_s_element &element = data[idx];
    rec_list_s_element &s_element = a_second.data[s_idx];

    if (!(element.object == s_element.object))
    {
      return false;
    }

    idx = element.next_idx;
    s_idx = s_element.next_idx;

  } while(idx != c_idx_not_exist || s_idx != c_idx_not_exist);

  return idx == s_idx;
}/*}}}*/



/*
 * global methods
 */

void print_list(rec_list_s &rec_list,const char *name)
{
  printf("%s.size:  %u\n",name,rec_list.size);
  printf("%s.used:  %u\n",name,rec_list.used);
  printf("%s.free_idx:  %u\n",name,rec_list.free_idx);
  printf("%s.first_idx: %u\n",name,rec_list.first_idx);
  printf("%s.last_idx:  %u\n",name,rec_list.last_idx);
  printf("%s: ",name);

  if (rec_list.first_idx != c_idx_not_exist)
  {
    unsigned idx = rec_list.first_idx;
    do {
      record_s &rec = rec_list[idx];
      printf("{%u,%u}",rec.index,rec.value);

      idx = rec_list.next_idx(idx);
    } while(idx != c_idx_not_exist);
  }

  printf("\n");
  printf("\n");
}

int main(int argc, char **argv)
{
  record_s rec;
  rec.init();
  rec.set(1,1);

  rec_list_s list0;
  list0.init();

  print_list(list0,"list0");

  printf("--- APPEND NEW RECORDS TO LIST ---\n");

  unsigned idx = 0;
  do {
    rec.value = idx;
    list0.append(rec);
  } while(++idx < 5);

  print_list(list0,"list0");

  printf("--- PREPEND NEW RECORDS TO LIST ---\n");

  idx = 0;
  do {
    rec.value = idx;
    list0.prepend(rec);
  } while(++idx < 5);

  print_list(list0,"list0");

  printf("--- REMOVE RECORDS FROM LIST ---\n");

  unsigned count = 0;
  do {
    list0.remove(list0.first_idx);
  } while(++count < 5);

  print_list(list0,"list0");

  printf("--- INSERT AFTER FIRST RECORD ---\n");

  idx = 0;
  do {
    rec.value = idx;
    list0.insert_after(list0.first_idx,rec);
  } while(++idx < 2);

  print_list(list0,"list0");

  printf("--- INSERT BEFORE LAST RECORD ---\n");

  idx = 0;
  do {
    rec.value = idx;
    list0.insert_before(list0.last_idx,rec);
  } while(++idx < 2);

  print_list(list0,"list0");

  printf("--- CREATE NEW EMPTY LIST ---\n");
  rec_list_s list1;
  list1.init();

  print_list(list0,"list0");
  print_list(list1,"list1");

  printf("--- COMPARE LIST CONTENT ---\n");
  printf("list0 == list1: %s\n",list0 == list1 ? "TRUE" : "FALSE");
  printf("\n");

  printf("--- ASSIGN LIST CONTENT ---\n");
  list1 = list0;

  print_list(list0,"list0");
  print_list(list1,"list1");

  printf("--- COMPARE LIST CONTENT ---\n");
  printf("list0 == list1: %s\n",list0 == list1 ? "TRUE" : "FALSE");
  printf("\n");

  list1.clear();
  list0.clear();
  rec.clear();

  return 0;
}


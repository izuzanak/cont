
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
};

/*
 * definition of generated structures
 */

// -- string_array_s --
// --- struct string_array_s definition --- 

/*!
 * \brief __GEN array of type string_s
 */
struct string_array_s
{
  unsigned size; //!< actual size of allocated space in array
  unsigned used; //!< count of used space in array
  string_s *data; //!< pointer to array elements

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
  void clear();

  /*!
    * \brief __GEN set array content from element pointer
    * \param a_used - number of elements stored at pointed location
    * \param a_data - pointer to elements
    */
  void set(unsigned a_used,string_s *a_data);

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
  inline void swap(string_array_s &a_second);

  /*!
    * \brief __GEN select element of array
    * \param a_idx - index of element in array
    * \return reference to element of array
    */
  inline string_s &operator[](unsigned a_idx);

  /*!
    * \brief __GEN insert element to end of array
    * \param a_value - reference to inserted value
    */
  inline void push(string_s &a_value);

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
  inline string_s &pop();

  /*!
    * \brief __GEN return value of last element in array
    * \return reference to last element
    */
  inline string_s &last();

  /*!
    * \brief __GEN change array capacity
    * \param a_size - requested array capacity
    */
  void copy_resize(unsigned a_size);

  /*!
    * \brief __GEN set all elements of array to given value
    * \param a_value - new value of all elements
    */
  void fill(string_s &a_value);

  /*!
    * \brief __GEN search for index of element
    * \param a_value - value which index is searched
    */
  unsigned get_idx(string_s &a_value);

  /*!
    * \brief __GEN copy array from another array
    * \param a_src - reference to another array
    */
  string_array_s &operator=(string_array_s &a_src);

  /*!
    * \brief __GEN comparison of array with another array
    * \param a_second - reference to another array
    */
  bool operator==(string_array_s &a_second);

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

// -- string_array_s --
// --- struct string_array_s inline method definition ---

inline void string_array_s::init()
{/*{{{*/
  size = 0;
  used = 0;
  data = nullptr;
}/*}}}*/

inline void string_array_s::init_size(unsigned a_size)
{/*{{{*/
  init();
  copy_resize(a_size);
}/*}}}*/

inline void string_array_s::flush()
{/*{{{*/
  copy_resize(used);
}/*}}}*/

inline void string_array_s::flush_all()
{/*{{{*/
  copy_resize(used);
}/*}}}*/

inline void string_array_s::swap(string_array_s &a_second)
{/*{{{*/
  unsigned tmp_unsigned = size;
  size = a_second.size;
  a_second.size = tmp_unsigned;

  tmp_unsigned = used;
  used = a_second.used;
  a_second.used = tmp_unsigned;

  string_s *tmp_data = data;
  data = a_second.data;
  a_second.data = tmp_data;
}/*}}}*/

inline string_s &string_array_s::operator[](unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < used);
  return data[a_idx];
}/*}}}*/

inline void string_array_s::push(string_s &a_value)
{/*{{{*/
  if (used >= size) {
    copy_resize((size << 1) + c_array_add);
  }

  data[used++] = a_value;
}/*}}}*/

inline void string_array_s::push_blank()
{/*{{{*/
  if (used >= size) {
    copy_resize((size << 1) + c_array_add);
  }

  used++;
}/*}}}*/

inline void string_array_s::push_clear()
{/*{{{*/
  if (used >= size) {
    copy_resize((size << 1) + c_array_add);
  }

  data[used++].clear();
}/*}}}*/

inline string_s &string_array_s::pop()
{/*{{{*/
  debug_assert(used > 0);
  return data[--used];
}/*}}}*/

inline string_s &string_array_s::last()
{/*{{{*/
  debug_assert(used > 0);
  return data[used - 1];
}/*}}}*/



/*
 * definition of global methods
 */

void print_array(string_array_s &str_array,const char *name);

#endif



/*
 * constants and definitions
 */

// - string terminating character -
const char c_string_terminating_char = '\0';

/*
 * methods of generated structures
 */

// -- string_array_s --
// --- struct string_array_s method definition ---

void string_array_s::clear()
{/*{{{*/
  if (data != nullptr) {
    string_s *ptr = data;
    string_s *ptr_end = ptr + size;

    do {
      ptr->clear();
    } while(++ptr < ptr_end);

    cfree(data);
  }

  init();
}/*}}}*/

void string_array_s::set(unsigned a_used,string_s *a_data)
{/*{{{*/
  clear();
  if (a_used == 0) return;

  debug_assert(a_data != nullptr);
  copy_resize(a_used);

  string_s *ptr = data;
  string_s *ptr_end = ptr + a_used;
  string_s *a_ptr = a_data;

  do {
    *ptr = *a_ptr;
  } while(++a_ptr,++ptr < ptr_end);

  used = a_used;
}/*}}}*/

void string_array_s::reserve(unsigned a_cnt)
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

void string_array_s::push_blanks(unsigned a_cnt)
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

void string_array_s::copy_resize(unsigned a_size)
{/*{{{*/
  debug_assert(a_size >= used);

  if (size > a_size) {
    string_s *ptr = data + a_size;
    string_s *ptr_end = data + size;

    do {
      ptr->clear();
    } while(++ptr < ptr_end);
  }

  if (a_size == 0) {
    if (data != nullptr) {
      cfree(data);
    }
    data = nullptr;
  }
  else {
    data = (string_s *)crealloc(data,a_size*sizeof(string_s));
  }

  if (a_size > size) {
    string_s *ptr = data + size;
    string_s *ptr_end = data + a_size;

    do {
      ptr->init();
    } while(++ptr < ptr_end);
  }

  size = a_size;
}/*}}}*/

void string_array_s::fill(string_s &a_value)
{/*{{{*/
  if (size == 0) return;

  string_s *ptr = data;
  string_s *ptr_end = data + size;

  do {
    *ptr = a_value;
  } while(++ptr < ptr_end);

  used = size;
}/*}}}*/

unsigned string_array_s::get_idx(string_s &a_value)
{/*{{{*/
  if (used == 0) return c_idx_not_exist;

  string_s *ptr = data;
  string_s *ptr_end = data + used;

  do {
    if (*ptr == a_value) {
      return ptr - data;
    }
  } while(++ptr < ptr_end);

  return c_idx_not_exist;
}/*}}}*/

string_array_s &string_array_s::operator=(string_array_s &a_src)
{/*{{{*/
  clear();

  if (a_src.used == 0) return *this;

  copy_resize(a_src.used);

  string_s *ptr = data;
  string_s *s_ptr = a_src.data;
  string_s *s_ptr_end = s_ptr + a_src.used;

  do {
    *ptr = *s_ptr;
  } while(++ptr,++s_ptr < s_ptr_end);

  used = a_src.used;
  return *this;
}/*}}}*/

bool string_array_s::operator==(string_array_s &a_second)
{/*{{{*/
  if (used != a_second.used) return false;
  if (used == 0) return true;

  string_s *ptr = data;
  string_s *ptr_end = ptr + used;
  string_s *s_ptr = a_second.data;

  do {
    if (!(*ptr == *s_ptr)) {
      return false;
    }
  } while(++s_ptr,++ptr < ptr_end);

  return true;
}/*}}}*/



/*
 * global methods
 */

void print_array(string_array_s &str_array,const char *name)
{
  printf("%s.size: %u\n",name,str_array.size);
  printf("%s.used: %u\n",name,str_array.used);
  printf("%s: ",name);

  string_s *s_ptr = str_array.data;
  string_s *s_ptr_end = s_ptr + str_array.used;
  while (s_ptr < s_ptr_end)
  {
    printf("%s ",s_ptr->data);
    ++s_ptr;
  }
  printf("\n");
  printf("\n");
}

int main(int argc, char **argv)
{
  string_s string;
  string.init();
  string.set(strlen("String"),"String");

  string_array_s array0;
  array0.init();

  printf("--- CREATE EMPTY ARRAY ---\n");
  print_array(array0,"array0");

  printf("--- FILL STRINGS TO ARRAY ---\n");
  unsigned idx = 0;
  do {
    array0.push(string);
  } while(++idx < 8);

  print_array(array0,"array0");

  printf("--- POP STRINGS FROM ARRAY ---\n");
  while (array0.used > 3)
  {
    array0.pop();
  }

  print_array(array0,"array0");

  printf("--- PUSH STRINGS TO ARRAY ---\n");
  string.set(strlen("Pushed"),"Pushed");
  array0.push(string);
  array0.push(string);
  array0.push(string);

  print_array(array0,"array0");

  printf("--- MODIFY ARRAY ELEMENT ---\n");
  string.set(strlen("Modified"),"Modified");
  array0[2] = string;

  print_array(array0,"array0");

  printf("--- CREATE NEW EMPTY ARRAY ---\n");
  string_array_s array1;
  array1.init();

  print_array(array0,"array0");
  print_array(array1,"array1");

  printf("--- SWAP CONTENT OF ARRAYS ---\n");
  array0.swap(array1);

  print_array(array0,"array0");
  print_array(array1,"array1");

  printf("--- COMPARE ARRAY CONTENT ---\n");
  printf("array0 == array1: %s\n",array0 == array1 ? "TRUE" : "FALSE");
  printf("\n");

  printf("--- ASSIGN ARRAY CONTENT ---\n");
  array0 = array1;

  printf("array0 == array1: %s\n",array0 == array1 ? "TRUE" : "FALSE");
  printf("\n");

  array1.clear();
  array0.clear();
  string.clear();

  return 0;
}


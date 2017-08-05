
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
 * methods of generated structures
 */

// -- record_s --
// --- struct record_s method definition ---



/*
 * global methods
 */

int main(int argc, char **argv)
{
  record_s rec0,rec1;

  rec0.init();
  rec1.init();

  rec0.set(1,2);
  rec1.set(3,4);

  printf("rec0: {%u,%u}\n",rec0.index,rec0.value);
  printf("rec1: {%u,%u}\n",rec1.index,rec1.value);
  printf("rec0 == rec1: %s\n",rec0 == rec1 ? "TRUE" : "FALSE");
  printf("\n");

  rec1.swap(rec0);
  printf("rec0: {%u,%u}\n",rec0.index,rec0.value);
  printf("rec1: {%u,%u}\n",rec1.index,rec1.value);
  printf("rec0 == rec1: %s\n",rec0 == rec1 ? "TRUE" : "FALSE");
  printf("\n");

  rec1 = rec0;
  printf("rec0: {%u,%u}\n",rec0.index,rec0.value);
  printf("rec1: {%u,%u}\n",rec1.index,rec1.value);
  printf("rec0 == rec1: %s\n",rec0 == rec1 ? "TRUE" : "FALSE");
  printf("\n");

  printf("rec0.get_index(): %u\n",rec0.get_index());
  printf("rec0.get_value(): %u\n",rec0.get_value());

  rec0.clear();
  rec1.clear();

  return 0;
}



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

  record_s_init(&rec0);
  record_s_init(&rec1);

  record_s_set(&rec0,1,2);
  record_s_set(&rec1,3,4);

  printf("rec0: {%u,%u}\n",rec0.index,rec0.value);
  printf("rec1: {%u,%u}\n",rec1.index,rec1.value);
  printf("record_s_compare(&rec0,&rec1): %s\n",record_s_compare(&rec0,&rec1) ? "TRUE" : "FALSE");
  printf("\n");

  record_s_swap(&rec1,&rec0);
  printf("rec0: {%u,%u}\n",rec0.index,rec0.value);
  printf("rec1: {%u,%u}\n",rec1.index,rec1.value);
  printf("record_s_compare(&rec0,&rec1): %s\n",record_s_compare(&rec0,&rec1) ? "TRUE" : "FALSE");
  printf("\n");

  record_s_copy(&rec1,&rec0);
  printf("rec0: {%u,%u}\n",rec0.index,rec0.value);
  printf("rec1: {%u,%u}\n",rec1.index,rec1.value);
  printf("record_s_compare(&rec0,&rec1): %s\n",record_s_compare(&rec0,&rec1) ? "TRUE" : "FALSE");
  printf("\n");

  printf("record_s_get_index(&rec0): %u\n",record_s_get_index(&rec0));
  printf("record_s_get_value(&rec0): %u\n",record_s_get_value(&rec0));

  record_s_clear(&rec0);
  record_s_clear(&rec1);

  return 0;
}


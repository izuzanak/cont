
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



#ifndef __ARRAY_H
#define __ARRAY_H


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
 * definition of generated structures
 */

// -- rec_array_s --
// --- struct rec_array_s definition --- 

typedef struct rec_array_s rec_array_s;

struct rec_array_s
{
  unsigned size; //!< actual size of allocated space in array
  unsigned used; //!< count of used space in array
  record_s *data; //!< pointer to array elements
};

static inline void rec_array_s_init(rec_array_s *this);
static inline void rec_array_s_init_size(rec_array_s *this,unsigned a_size);
static inline void rec_array_s_clear(rec_array_s *this);
static inline void rec_array_s_set(rec_array_s *this,unsigned a_used,record_s *a_data);
static inline void rec_array_s_flush(rec_array_s *this);
static inline void rec_array_s_flush_all(rec_array_s *this);
static inline void rec_array_s_swap(rec_array_s *this,rec_array_s *a_second);
static inline record_s *rec_array_s_at(rec_array_s *this,unsigned a_idx);
static inline void rec_array_s_push(rec_array_s *this,record_s *a_value);
static inline void rec_array_s_push_blank(rec_array_s *this);
void rec_array_s_reserve(rec_array_s *this,unsigned a_cnt);
void rec_array_s_push_blanks(rec_array_s *this,unsigned a_cnt);
static inline void rec_array_s_push_clear(rec_array_s *this);
static inline record_s *rec_array_s_pop(rec_array_s *this);
static inline record_s *rec_array_s_last(rec_array_s *this);
void rec_array_s_copy_resize(rec_array_s *this,unsigned a_size);
void rec_array_s_fill(rec_array_s *this,record_s *a_value);
unsigned rec_array_s_get_idx(rec_array_s *this,record_s *a_value);
static inline void rec_array_s_copy(rec_array_s *this,rec_array_s *a_src);
static inline int rec_array_s_compare(rec_array_s *this,rec_array_s *a_second);
#if OPTION_TO_STRING == ENABLED
void rec_array_s_to_string(rec_array_s *this,bc_array_s *a_trg);
#endif



/*
 * inline methods of generated structures
 */

// -- rec_array_s --
// --- struct rec_array_s inline method definition ---

static inline void rec_array_s_init(rec_array_s *this)
{/*{{{*/
  this->size = 0;
  this->used = 0;
  this->data = NULL;
}/*}}}*/

static inline void rec_array_s_init_size(rec_array_s *this,unsigned a_size)
{/*{{{*/
  rec_array_s_init(this);
  rec_array_s_copy_resize(this,a_size);
}/*}}}*/

static inline void rec_array_s_clear(rec_array_s *this)
{/*{{{*/
  if (this->data != NULL)
  {
    cfree(this->data);
  }

  rec_array_s_init(this);
}/*}}}*/

static inline void rec_array_s_set(rec_array_s *this,unsigned a_used,record_s *a_data)
{/*{{{*/
  rec_array_s_clear(this);
  if (a_used == 0)
  {
    return;
  }

  debug_assert(a_data != NULL);
  rec_array_s_copy_resize(this,a_used);

  memcpy(this->data,a_data,a_used*sizeof(record_s));
  this->used = a_used;
}/*}}}*/

static inline void rec_array_s_flush(rec_array_s *this)
{/*{{{*/
  rec_array_s_copy_resize(this,this->used);
}/*}}}*/

static inline void rec_array_s_flush_all(rec_array_s *this)
{/*{{{*/
  rec_array_s_copy_resize(this,this->used);
}/*}}}*/

static inline void rec_array_s_swap(rec_array_s *this,rec_array_s *a_second)
{/*{{{*/
  unsigned tmp_unsigned = this->size;
  this->size = a_second->size;
  a_second->size = tmp_unsigned;

  tmp_unsigned = this->used;
  this->used = a_second->used;
  a_second->used = tmp_unsigned;

  record_s *tmp_data = this->data;
  this->data = a_second->data;
  a_second->data = tmp_data;
}/*}}}*/

static inline record_s *rec_array_s_at(rec_array_s *this,unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < this->used);
  return this->data + a_idx;
}/*}}}*/

static inline void rec_array_s_push(rec_array_s *this,record_s *a_value)
{/*{{{*/
  if (this->used >= this->size)
  {
    rec_array_s_copy_resize(this,(this->size << 1) + c_array_add);
  }

  record_s_copy(this->data + this->used++,a_value);
}/*}}}*/

static inline void rec_array_s_push_blank(rec_array_s *this)
{/*{{{*/
  if (this->used >= this->size)
  {
    rec_array_s_copy_resize(this,(this->size << 1) + c_array_add);
  }

  this->used++;
}/*}}}*/

static inline void rec_array_s_push_clear(rec_array_s *this)
{/*{{{*/
  if (this->used >= this->size)
  {
    rec_array_s_copy_resize(this,(this->size << 1) + c_array_add);
  }

  this->used++;
}/*}}}*/

static inline record_s *rec_array_s_pop(rec_array_s *this)
{/*{{{*/
  debug_assert(this->used > 0);
  return this->data + --this->used;
}/*}}}*/

static inline record_s *rec_array_s_last(rec_array_s *this)
{/*{{{*/
  debug_assert(this->used > 0);
  return this->data + this->used - 1;
}/*}}}*/

static inline void rec_array_s_copy(rec_array_s *this,rec_array_s *a_src)
{/*{{{*/
  rec_array_s_clear(this);

  if (a_src->used == 0)
  {
    return;
  }

  rec_array_s_copy_resize(this,a_src->used);
  memcpy(this->data,a_src->data,a_src->used*sizeof(record_s));

  this->used = a_src->used;
}/*}}}*/

static inline int rec_array_s_compare(rec_array_s *this,rec_array_s *a_second)
{/*{{{*/
  if (this->used != a_second->used)
  {
    return 0;
  }

  if (this->used == 0)
  {
    return 1;
  }

  return (memcmp(this->data,a_second->data,this->used*sizeof(record_s)) == 0);
}/*}}}*/



/*
 * definition of global methods
 */

void print_array(rec_array_s *rec_array,const char *name);

#endif



/*
 * methods of generated structures
 */

// -- rec_array_s --
// --- struct rec_array_s method definition ---

void rec_array_s_reserve(rec_array_s *this,unsigned a_cnt)
{/*{{{*/
  unsigned required_cnt = this->used + a_cnt;
  if (required_cnt > this->size)
  {
    unsigned r_size = this->size;
    do {
      r_size = (r_size << 1) + c_array_add;
    } while(r_size < required_cnt);

    rec_array_s_copy_resize(this,r_size);
  }
}/*}}}*/

void rec_array_s_push_blanks(rec_array_s *this,unsigned a_cnt)
{/*{{{*/
  unsigned required_cnt = this->used + a_cnt;
  if (required_cnt > this->size)
  {
    unsigned r_size = this->size;
    do {
      r_size = (r_size << 1) + c_array_add;
    } while(r_size < required_cnt);

    rec_array_s_copy_resize(this,r_size);
  }

  this->used += a_cnt;
}/*}}}*/

void rec_array_s_copy_resize(rec_array_s *this,unsigned a_size)
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
    this->data = (record_s *)crealloc(this->data,a_size*sizeof(record_s));
  }

  this->size = a_size;
}/*}}}*/

void rec_array_s_fill(rec_array_s *this,record_s *a_value)
{/*{{{*/
  if (this->size == 0)
  {
    return;
  }

  record_s *ptr = this->data;
  record_s *ptr_end = this->data + this->size;

  do {
    record_s_copy(ptr,a_value);
  } while(++ptr < ptr_end);

  this->used = this->size;
}/*}}}*/

unsigned rec_array_s_get_idx(rec_array_s *this,record_s *a_value)
{/*{{{*/
  if (this->used == 0)
  {
    return c_idx_not_exist;
  }

  record_s *ptr = this->data;
  record_s *ptr_end = this->data + this->used;

  do {
    if (record_s_compare(ptr,a_value))
    {
      return ptr - this->data;
    }
  } while(++ptr < ptr_end);

  return c_idx_not_exist;
}/*}}}*/

#if OPTION_TO_STRING == ENABLED
void rec_array_s_to_string(rec_array_s *this,bc_array_s *a_trg)
{/*{{{*/
  bc_array_s_push(a_trg,'[');

  if (this->used != 0)
  {
    record_s *ptr = this->data;
    record_s *ptr_end = this->data + this->used;

    do {
      record_s_to_string(ptr,a_trg);

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



/*
 * global methods
 */

void print_array(rec_array_s *rec_array,const char *name)
{
  printf("%s.size: %u\n",name,rec_array->size);
  printf("%s.used: %u\n",name,rec_array->used);
  printf("%s: ",name);

  record_s *r_ptr = rec_array->data;
  record_s *r_ptr_end = r_ptr + rec_array->used;
  while (r_ptr < r_ptr_end)
  {
    printf("{%u,%u}",r_ptr->index,r_ptr->value);
    ++r_ptr;
  }
  printf("\n");
  printf("\n");
}

int main(int argc, char **argv)
{
  record_s rec;
  record_s_init(&rec);
  record_s_set(&rec,1,2);

  rec_array_s array0;

  printf("--- INITIALIZE AND FILL ARRAY ---\n");
  rec_array_s_init_size(&array0,5);
  rec_array_s_fill(&array0,&rec);

  print_array(&array0,"array0");

  printf("--- POP RECORDS FROM ARRAY ---\n");
  while (array0.used > 3)
  {
    rec_array_s_pop(&array0);
  }

  print_array(&array0,"array0");

  rec.index = 3;
  rec.value = 4;

  printf("--- PUSH RECORDS TO ARRAY ---\n");
  rec_array_s_push(&array0,&rec);
  rec_array_s_push(&array0,&rec);
  rec_array_s_push(&array0,&rec);

  print_array(&array0,"array0");

  printf("--- MODIFY RECORDS OF ARRAY ---\n");
  unsigned idx = 3;
  do {
    array0.data[idx].value = 5;
  } while(++idx < array0.used);

  print_array(&array0,"array0");

  printf("--- CREATE NEW EMPTY ARRAY ---\n");
  rec_array_s array1;
  rec_array_s_init(&array1);

  print_array(&array0,"array0");
  print_array(&array1,"array1");

  printf("--- SWAP CONTENT OF ARRAYS ---\n");
  rec_array_s_swap(&array0,&array1);

  print_array(&array0,"array0");
  print_array(&array1,"array1");

  printf("--- COMPARE ARRAY CONTENT ---\n");
  printf("rec_array_s_compare(&array0,&array1): %s\n",rec_array_s_compare(&array0,&array1) ? "TRUE" : "FALSE");
  printf("\n");

  printf("--- ASSIGN ARRAY CONTENT ---\n");
  rec_array_s_copy(&array0,&array1);

  printf("rec_array_s_compare(&array0,&array1): %s\n",rec_array_s_compare(&array0,&array1) ? "TRUE" : "FALSE");
  printf("\n");

  rec_array_s_clear(&array1);
  rec_array_s_clear(&array0);
  record_s_clear(&rec);

  return 0;
}


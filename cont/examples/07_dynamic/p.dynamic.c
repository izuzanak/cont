
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

static inline void string_s_init(string_s *this);
static inline void string_s_clear(string_s *this);
static inline void string_s_create(string_s *this,unsigned a_length);
static inline void string_s_set(string_s *this,unsigned a_length,const char *a_data);
static inline void string_s_flush_all(string_s *this) {}
static inline void string_s_swap(string_s *this,string_s *a_second);
static inline void string_s_copy(string_s *this,string_s *a_src);
static inline int string_s_compare(string_s *this,string_s *a_second);

/*
 * definition of generated structures
 */

// -- string_array_s --
// --- struct string_array_s definition --- 

typedef struct string_array_s string_array_s;

struct string_array_s
{
  unsigned size; //!< actual size of allocated space in array
  unsigned used; //!< count of used space in array
  string_s *data; //!< pointer to array elements
};

static inline void string_array_s_init(string_array_s *this);
static inline void string_array_s_init_size(string_array_s *this,unsigned a_size);
void string_array_s_clear(string_array_s *this);
void string_array_s_set(string_array_s *this,unsigned a_used,string_s *a_data);
static inline void string_array_s_flush(string_array_s *this);
static inline void string_array_s_flush_all(string_array_s *this);
static inline void string_array_s_swap(string_array_s *this,string_array_s *a_second);
static inline string_s *string_array_s_at(string_array_s *this,unsigned a_idx);
static inline void string_array_s_push(string_array_s *this,string_s *a_value);
static inline void string_array_s_push_blank(string_array_s *this);
void string_array_s_reserve(string_array_s *this,unsigned a_cnt);
void string_array_s_push_blanks(string_array_s *this,unsigned a_cnt);
static inline void string_array_s_push_clear(string_array_s *this);
static inline string_s *string_array_s_pop(string_array_s *this);
static inline string_s *string_array_s_last(string_array_s *this);
void string_array_s_copy_resize(string_array_s *this,unsigned a_size);
void string_array_s_fill(string_array_s *this,string_s *a_value);
unsigned string_array_s_get_idx(string_array_s *this,string_s *a_value);
void string_array_s_copy(string_array_s *this,string_array_s *a_src);
int string_array_s_compare(string_array_s *this,string_array_s *a_second);
#if OPTION_TO_STRING == ENABLED
void string_array_s_to_string(string_array_s *this,bc_array_s *a_trg);
#endif



/*
 * inline methods of structure string_s
 */

static inline void string_s_init(string_s *this)
{/*{{{*/
  this->size = 1;
  this->data = (char *)&c_string_terminating_char;
}/*}}}*/

static inline void string_s_clear(string_s *this)
{/*{{{*/
  if (this->data != &c_string_terminating_char)
  {
    cfree(this->data);
  }

  string_s_init(this);
}/*}}}*/

static inline void string_s_create(string_s *this,unsigned a_length)
{/*{{{*/
  string_s_clear(this);
  this->data = (char *)cmalloc((a_length + 1)*sizeof(char));

  this->data[a_length] = '\0';
  this->size = a_length + 1;
}/*}}}*/

static inline void string_s_set(string_s *this,unsigned a_length,const char *a_data)
{/*{{{*/
  string_s_clear(this);
  this->data = (char *)cmalloc((a_length + 1)*sizeof(char));

  if (a_length != 0)
  {
    memcpy(this->data,a_data,a_length*sizeof(char));
  }

  this->data[a_length] = '\0';
  this->size = a_length + 1;
}/*}}}*/

static inline void string_s_swap(string_s *this,string_s *a_second)
{/*{{{*/
  unsigned tmp_size = this->size;
  this->size = a_second->size;
  a_second->size = tmp_size;

  char *tmp_data = this->data;
  this->data = a_second->data;
  a_second->data = tmp_data;
}/*}}}*/

static inline void string_s_copy(string_s *this,string_s *a_src)
{/*{{{*/
  string_s_clear(this);

  if (a_src->data == &c_string_terminating_char) return;
  this->data = (char *)cmalloc(a_src->size*sizeof(char));
  memcpy(this->data,a_src->data,(a_src->size - 1)*sizeof(char));
  this->data[a_src->size - 1] = '\0';
  this->size = a_src->size;
}/*}}}*/

static inline int string_s_compare(string_s *this,string_s *a_second)
{/*{{{*/
  if (this->size != a_second->size) return 0;
  if (this->data == &c_string_terminating_char) return 1;
  return (memcmp(this->data,a_second->data,(this->size - 1)*sizeof(char)) == 0);
}/*}}}*/

/*
 * inline methods of generated structures
 */

// -- string_array_s --
// --- struct string_array_s inline method definition ---

static inline void string_array_s_init(string_array_s *this)
{/*{{{*/
  this->size = 0;
  this->used = 0;
  this->data = NULL;
}/*}}}*/

static inline void string_array_s_init_size(string_array_s *this,unsigned a_size)
{/*{{{*/
  string_array_s_init(this);
  string_array_s_copy_resize(this,a_size);
}/*}}}*/

static inline void string_array_s_flush(string_array_s *this)
{/*{{{*/
  string_array_s_copy_resize(this,this->used);
}/*}}}*/

static inline void string_array_s_flush_all(string_array_s *this)
{/*{{{*/
  string_array_s_copy_resize(this,this->used);
}/*}}}*/

static inline void string_array_s_swap(string_array_s *this,string_array_s *a_second)
{/*{{{*/
  unsigned tmp_unsigned = this->size;
  this->size = a_second->size;
  a_second->size = tmp_unsigned;

  tmp_unsigned = this->used;
  this->used = a_second->used;
  a_second->used = tmp_unsigned;

  string_s *tmp_data = this->data;
  this->data = a_second->data;
  a_second->data = tmp_data;
}/*}}}*/

static inline string_s *string_array_s_at(string_array_s *this,unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < this->used);
  return this->data + a_idx;
}/*}}}*/

static inline void string_array_s_push(string_array_s *this,string_s *a_value)
{/*{{{*/
  if (this->used >= this->size) {
    string_array_s_copy_resize(this,(this->size << 1) + c_array_add);
  }

  string_s_copy(this->data + this->used++,a_value);
}/*}}}*/

static inline void string_array_s_push_blank(string_array_s *this)
{/*{{{*/
  if (this->used >= this->size) {
    string_array_s_copy_resize(this,(this->size << 1) + c_array_add);
  }

  this->used++;
}/*}}}*/

static inline void string_array_s_push_clear(string_array_s *this)
{/*{{{*/
  if (this->used >= this->size) {
    string_array_s_copy_resize(this,(this->size << 1) + c_array_add);
  }

  string_s_clear(this->data + this->used++);
}/*}}}*/

static inline string_s *string_array_s_pop(string_array_s *this)
{/*{{{*/
  debug_assert(this->used > 0);
  return this->data + --this->used;
}/*}}}*/

static inline string_s *string_array_s_last(string_array_s *this)
{/*{{{*/
  debug_assert(this->used > 0);
  return this->data + this->used - 1;
}/*}}}*/



/*
 * definition of global methods
 */

void print_array(string_array_s *str_array,const char *name);

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

void string_array_s_clear(string_array_s *this)
{/*{{{*/
  if (this->data != NULL) {
    string_s *ptr = this->data;
    string_s *ptr_end = ptr + this->size;

    do {
      string_s_clear(ptr);
    } while(++ptr < ptr_end);

    cfree(this->data);
  }

  string_array_s_init(this);
}/*}}}*/

void string_array_s_set(string_array_s *this,unsigned a_used,string_s *a_data)
{/*{{{*/
  string_array_s_clear(this);
  if (a_used == 0) return;

  debug_assert(a_data != NULL);
  string_array_s_copy_resize(this,a_used);

  string_s *ptr = this->data;
  string_s *ptr_end = ptr + a_used;
  string_s *a_ptr = a_data;

  do {
    string_s_copy(ptr,a_ptr);
  } while(++a_ptr,++ptr < ptr_end);

  this->used = a_used;
}/*}}}*/

void string_array_s_reserve(string_array_s *this,unsigned a_cnt)
{/*{{{*/
  unsigned required_cnt = this->used + a_cnt;
  if (required_cnt > this->size) {
    unsigned r_size = this->size;
    do {
      r_size = (r_size << 1) + c_array_add;
    } while(r_size < required_cnt);

    string_array_s_copy_resize(this,r_size);
  }
}/*}}}*/

void string_array_s_push_blanks(string_array_s *this,unsigned a_cnt)
{/*{{{*/
  unsigned required_cnt = this->used + a_cnt;
  if (required_cnt > this->size) {
    unsigned r_size = this->size;
    do {
      r_size = (r_size << 1) + c_array_add;
    } while(r_size < required_cnt);

    string_array_s_copy_resize(this,r_size);
  }

  this->used += a_cnt;
}/*}}}*/

void string_array_s_copy_resize(string_array_s *this,unsigned a_size)
{/*{{{*/
  debug_assert(a_size >= this->used);

  if (this->size > a_size) {
    string_s *ptr = this->data + a_size;
    string_s *ptr_end = this->data + this->size;

    do {
      string_s_clear(ptr);
    } while(++ptr < ptr_end);
  }

  if (a_size == 0) {
    if (this->data != NULL) {
      cfree(this->data);
    }
    this->data = NULL;
  }
  else {
    this->data = (string_s *)crealloc(this->data,a_size*sizeof(string_s));
  }

  if (a_size > this->size) {
    string_s *ptr = this->data + this->size;
    string_s *ptr_end = this->data + a_size;

    do {
      string_s_init(ptr);
    } while(++ptr < ptr_end);
  }

  this->size = a_size;
}/*}}}*/

void string_array_s_fill(string_array_s *this,string_s *a_value)
{/*{{{*/
  if (this->size == 0) return;

  string_s *ptr = this->data;
  string_s *ptr_end = this->data + this->size;

  do {
    string_s_copy(ptr,a_value);
  } while(++ptr < ptr_end);

  this->used = this->size;
}/*}}}*/

unsigned string_array_s_get_idx(string_array_s *this,string_s *a_value)
{/*{{{*/
  if (this->used == 0) return c_idx_not_exist;

  string_s *ptr = this->data;
  string_s *ptr_end = this->data + this->used;

  do {
    if (string_s_compare(ptr,a_value)) {
      return ptr - this->data;
    }
  } while(++ptr < ptr_end);

  return c_idx_not_exist;
}/*}}}*/

void string_array_s_copy(string_array_s *this,string_array_s *a_src)
{/*{{{*/
  string_array_s_clear(this);

  if (a_src->used == 0) return;

  string_array_s_copy_resize(this,a_src->used);

  string_s *ptr = this->data;
  string_s *s_ptr = a_src->data;
  string_s *s_ptr_end = s_ptr + a_src->used;

  do {
    string_s_copy(ptr,s_ptr);
  } while(++ptr,++s_ptr < s_ptr_end);

  this->used = a_src->used;
}/*}}}*/

int string_array_s_compare(string_array_s *this,string_array_s *a_second)
{/*{{{*/
  if (this->used != a_second->used) return 0;
  if (this->used == 0) return 1;

  string_s *ptr = this->data;
  string_s *ptr_end = ptr + this->used;
  string_s *s_ptr = a_second->data;

  do {
    if (!string_s_compare(ptr,s_ptr)) {
      return 0;
    }
  } while(++s_ptr,++ptr < ptr_end);

  return 1;
}/*}}}*/

#if OPTION_TO_STRING == ENABLED
void string_array_s_to_string(string_array_s *this,bc_array_s *a_trg)
{/*{{{*/
  bc_array_s_push(a_trg,'[');

  if (this->used != 0) {
    string_s *ptr = this->data;
    string_s *ptr_end = this->data + this->used;

    do {
      string_s_to_string(ptr,a_trg);

      if (++ptr >= ptr_end)
        break;

      bc_array_s_push(a_trg,',');
    } while(1);
  }

  bc_array_s_push(a_trg,']');
}/*}}}*/
#endif



/*
 * global methods
 */

void print_array(string_array_s *str_array,const char *name)
{
  printf("%s.size: %u\n",name,str_array->size);
  printf("%s.used: %u\n",name,str_array->used);
  printf("%s: ",name);

  string_s *s_ptr = str_array->data;
  string_s *s_ptr_end = s_ptr + str_array->used;
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
  string_s_init(&string);
  string_s_set(&string,strlen("String"),"String");

  string_array_s array0;
  string_array_s_init(&array0);

  printf("--- CREATE EMPTY ARRAY ---\n");
  print_array(&array0,"array0");

  printf("--- FILL STRINGS TO ARRAY ---\n");
  unsigned idx = 0;
  do {
    string_array_s_push(&array0,&string);
  } while(++idx < 8);

  print_array(&array0,"array0");

  printf("--- POP STRINGS FROM ARRAY ---\n");
  while (array0.used > 3)
  {
    string_array_s_pop(&array0);
  }

  print_array(&array0,"array0");

  printf("--- PUSH STRINGS TO ARRAY ---\n");
  string_s_set(&string,strlen("Pushed"),"Pushed");
  string_array_s_push(&array0,&string);
  string_array_s_push(&array0,&string);
  string_array_s_push(&array0,&string);

  print_array(&array0,"array0");

  printf("--- MODIFY ARRAY ELEMENT ---\n");
  string_s_set(&string,strlen("Modified"),"Modified");
  string_s_copy(array0.data + 2,&string);

  print_array(&array0,"array0");

  printf("--- CREATE NEW EMPTY ARRAY ---\n");
  string_array_s array1;
  string_array_s_init(&array1);

  print_array(&array0,"array0");
  print_array(&array1,"array1");

  printf("--- SWAP CONTENT OF ARRAYS ---\n");
  string_array_s_swap(&array0,&array1);

  print_array(&array0,"array0");
  print_array(&array1,"array1");

  printf("--- COMPARE ARRAY CONTENT ---\n");
  printf("string_array_s_compare(&array0,&array1): %s\n",string_array_s_compare(&array0,&array1) ? "TRUE" : "FALSE");
  printf("\n");

  printf("--- ASSIGN ARRAY CONTENT ---\n");
  string_array_s_copy(&array1,&array0);

  printf("string_array_s_compare(&array0,&array1): %s\n",string_array_s_compare(&array0,&array1) ? "TRUE" : "FALSE");
  printf("\n");

  string_array_s_clear(&array1);
  string_array_s_clear(&array0);
  string_s_clear(&string);

  return 0;
}


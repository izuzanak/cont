
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

// -- rec_list_s --
// struct rec_list_s definition

typedef struct rec_list_s_element rec_list_s_element;
typedef struct rec_list_s rec_list_s;

struct rec_list_s_element
{
  record_s object;
  unsigned next_idx;
  unsigned prev_idx;
};

struct rec_list_s
{
  unsigned size; //!< actual size of allocated space (element count)
  unsigned used; //!< used part of allocated space
  rec_list_s_element *data; //!< pointer to list elements
  unsigned free_idx; //!< index of first free element
  unsigned first_idx; //!< index of first element
  unsigned last_idx; //!< index of last element
};

static inline void rec_list_s_init(rec_list_s *this);
static inline void rec_list_s_init_size(rec_list_s *this,unsigned a_size);
static inline void rec_list_s_clear(rec_list_s *this);
static inline void rec_list_s_flush(rec_list_s *this);
static inline void rec_list_s_flush_all(rec_list_s *this);
static inline void rec_list_s_swap(rec_list_s *this,rec_list_s *a_second);
static inline record_s *rec_list_s_at(rec_list_s *this,unsigned a_idx);
static inline unsigned rec_list_s_prepend(rec_list_s *this,record_s *a_value);
static inline unsigned rec_list_s_append(rec_list_s *this,record_s *a_value);
static inline unsigned rec_list_s_insert_before(rec_list_s *this,unsigned a_idx,record_s *a_value);
static inline unsigned rec_list_s_insert_after(rec_list_s *this,unsigned a_idx,record_s *a_value);
static inline unsigned rec_list_s_prepend_blank(rec_list_s *this);
static inline unsigned rec_list_s_append_blank(rec_list_s *this);
static inline unsigned rec_list_s_insert_blank_before(rec_list_s *this,unsigned a_idx);
static inline unsigned rec_list_s_insert_blank_after(rec_list_s *this,unsigned a_idx);
static inline void rec_list_s_remove(rec_list_s *this,unsigned a_idx);
static inline unsigned rec_list_s_next_idx(rec_list_s *this,unsigned a_idx);
static inline unsigned rec_list_s_prev_idx(rec_list_s *this,unsigned a_idx);
void rec_list_s_copy_resize(rec_list_s *this,unsigned a_size);
unsigned rec_list_s_get_idx(rec_list_s *this,record_s *a_value);
static inline void rec_list_s_copy(rec_list_s *this,rec_list_s *a_src);
int rec_list_s_compare(rec_list_s *this,rec_list_s *a_second);
#if OPTION_TO_STRING == ENABLED
void rec_list_s_to_string(rec_list_s *this,bc_array_s *a_trg);
#endif



/*
 * inline methods of generated structures
 */

// -- rec_list_s --
// --- struct rec_list_s inline method definition ---

static inline void rec_list_s_init(rec_list_s *this)
{/*{{{*/
  this->size = 0;
  this->used = 0;
  this->data = NULL;
  this->free_idx = c_idx_not_exist;
  this->first_idx = c_idx_not_exist;
  this->last_idx = c_idx_not_exist;
}/*}}}*/

static inline void rec_list_s_init_size(rec_list_s *this,unsigned a_size)
{/*{{{*/
  rec_list_s_init(this);
  rec_list_s_copy_resize(this,a_size);
}/*}}}*/

static inline void rec_list_s_clear(rec_list_s *this)
{/*{{{*/
  if (this->data != NULL)
  {
    cfree(this->data);
  }

  rec_list_s_init(this);
}/*}}}*/

static inline void rec_list_s_flush(rec_list_s *this)
{/*{{{*/
  rec_list_s_copy_resize(this,this->used);
}/*}}}*/

static inline void rec_list_s_flush_all(rec_list_s *this)
{/*{{{*/
  rec_list_s_copy_resize(this,this->used);
}/*}}}*/

static inline void rec_list_s_swap(rec_list_s *this,rec_list_s *a_second)
{/*{{{*/
  unsigned tmp_unsigned = this->size;
  this->size = a_second->size;
  a_second->size = tmp_unsigned;

  tmp_unsigned = this->used;
  this->used = a_second->used;
  a_second->used = tmp_unsigned;

  rec_list_s_element *tmp_data = this->data;
  this->data = a_second->data;
  a_second->data = tmp_data;

  tmp_unsigned = this->free_idx;
  this->free_idx = a_second->free_idx;
  a_second->free_idx = tmp_unsigned;

  tmp_unsigned = this->first_idx;
  this->first_idx = a_second->first_idx;
  a_second->first_idx = tmp_unsigned;

  tmp_unsigned = this->last_idx;
  this->last_idx = a_second->last_idx;
  a_second->last_idx = tmp_unsigned;
}/*}}}*/

static inline record_s *rec_list_s_at(rec_list_s *this,unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < this->used);
  return &this->data[a_idx].object;
}/*}}}*/

static inline unsigned rec_list_s_prepend(rec_list_s *this,record_s *a_value)
{/*{{{*/
  unsigned new_idx;

  if (this->free_idx != c_idx_not_exist)
  {
    new_idx = this->free_idx;
    this->free_idx = this->data[new_idx].next_idx;
  }
  else
  {
    if (this->used >= this->size)
    {
      rec_list_s_copy_resize(this,(this->size << 1) + c_array_add);
    }

    new_idx = this->used++;
  }

  rec_list_s_element *new_element = this->data + new_idx;

  new_element->next_idx = this->first_idx;
  new_element->prev_idx = c_idx_not_exist;

  if (this->first_idx != c_idx_not_exist)
  {
    this->data[this->first_idx].prev_idx = new_idx;
  }
  else
  {
    this->last_idx = new_idx;
  }

  this->first_idx = new_idx;

  record_s_copy(&new_element->object,a_value);

  return new_idx;
}/*}}}*/

static inline unsigned rec_list_s_append(rec_list_s *this,record_s *a_value)
{/*{{{*/
  unsigned new_idx;

  if (this->free_idx != c_idx_not_exist)
  {
    new_idx = this->free_idx;
    this->free_idx = this->data[new_idx].next_idx;
  }
  else
  {
    if (this->used >= this->size)
    {
      rec_list_s_copy_resize(this,(this->size << 1) + c_array_add);
    }

    new_idx = this->used++;
  }

  rec_list_s_element *new_element = this->data + new_idx;

  new_element->next_idx = c_idx_not_exist;
  new_element->prev_idx = this->last_idx;

  if (this->last_idx != c_idx_not_exist)
  {
    this->data[this->last_idx].next_idx = new_idx;
  }
  else
  {
    this->first_idx = new_idx;
  }

  this->last_idx = new_idx;

  record_s_copy(&new_element->object,a_value);

  return new_idx;
}/*}}}*/

static inline unsigned rec_list_s_insert_before(rec_list_s *this,unsigned a_idx,record_s *a_value)
{/*{{{*/
  debug_assert(a_idx < this->used);

  unsigned new_idx;

  if (this->free_idx != c_idx_not_exist)
  {
    new_idx = this->free_idx;
    this->free_idx = this->data[new_idx].next_idx;
  }
  else
  {
    if (this->used >= this->size)
    {
      rec_list_s_copy_resize(this,(this->size << 1) + c_array_add);
    }

    new_idx = this->used++;
  }

  rec_list_s_element *idx_element = this->data + a_idx;
  rec_list_s_element *new_element = this->data + new_idx;

  new_element->next_idx = a_idx;
  new_element->prev_idx = idx_element->prev_idx;

  if (idx_element->prev_idx != c_idx_not_exist)
  {
    this->data[idx_element->prev_idx].next_idx = new_idx;
  }
  else
  {
    this->first_idx = new_idx;
  }

  idx_element->prev_idx = new_idx;

  record_s_copy(&new_element->object,a_value);

  return new_idx;
}/*}}}*/

static inline unsigned rec_list_s_insert_after(rec_list_s *this,unsigned a_idx,record_s *a_value)
{/*{{{*/
  debug_assert(a_idx < this->used);

  unsigned new_idx;

  if (this->free_idx != c_idx_not_exist)
  {
    new_idx = this->free_idx;
    this->free_idx = this->data[new_idx].next_idx;
  }
  else
  {
    if (this->used >= this->size)
    {
      rec_list_s_copy_resize(this,(this->size << 1) + c_array_add);
    }

    new_idx = this->used++;
  }

  rec_list_s_element *idx_element = this->data + a_idx;
  rec_list_s_element *new_element = this->data + new_idx;

  new_element->next_idx = idx_element->next_idx;
  new_element->prev_idx = a_idx;

  if (idx_element->next_idx != c_idx_not_exist)
  {
    this->data[idx_element->next_idx].prev_idx = new_idx;
  }
  else
  {
    this->last_idx = new_idx;
  }

  idx_element->next_idx = new_idx;

  record_s_copy(&new_element->object,a_value);

  return new_idx;
}/*}}}*/

static inline unsigned rec_list_s_prepend_blank(rec_list_s *this)
{/*{{{*/
  unsigned new_idx;

  if (this->free_idx != c_idx_not_exist)
  {
    new_idx = this->free_idx;
    this->free_idx = this->data[new_idx].next_idx;
  }
  else
  {
    if (this->used >= this->size)
    {
      rec_list_s_copy_resize(this,(this->size << 1) + c_array_add);
    }

    new_idx = this->used++;
  }

  rec_list_s_element *new_element = this->data + new_idx;

  new_element->next_idx = this->first_idx;
  new_element->prev_idx = c_idx_not_exist;

  if (this->first_idx != c_idx_not_exist)
  {
    this->data[this->first_idx].prev_idx = new_idx;
  }
  else
  {
    this->last_idx = new_idx;
  }

  this->first_idx = new_idx;

  return new_idx;
}/*}}}*/

static inline unsigned rec_list_s_append_blank(rec_list_s *this)
{/*{{{*/
  unsigned new_idx;

  if (this->free_idx != c_idx_not_exist)
  {
    new_idx = this->free_idx;
    this->free_idx = this->data[new_idx].next_idx;
  }
  else
  {
    if (this->used >= this->size)
    {
      rec_list_s_copy_resize(this,(this->size << 1) + c_array_add);
    }

    new_idx = this->used++;
  }

  rec_list_s_element *new_element = this->data + new_idx;

  new_element->next_idx = c_idx_not_exist;
  new_element->prev_idx = this->last_idx;

  if (this->last_idx != c_idx_not_exist)
  {
    this->data[this->last_idx].next_idx = new_idx;
  }
  else
  {
    this->first_idx = new_idx;
  }

  this->last_idx = new_idx;

  return new_idx;
}/*}}}*/

static inline unsigned rec_list_s_insert_blank_before(rec_list_s *this,unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < this->used);

  unsigned new_idx;

  if (this->free_idx != c_idx_not_exist)
  {
    new_idx = this->free_idx;
    this->free_idx = this->data[new_idx].next_idx;
  }
  else
  {
    if (this->used >= this->size)
    {
      rec_list_s_copy_resize(this,(this->size << 1) + c_array_add);
    }

    new_idx = this->used++;
  }

  rec_list_s_element *idx_element = this->data + a_idx;
  rec_list_s_element *new_element = this->data + new_idx;

  new_element->next_idx = a_idx;
  new_element->prev_idx = idx_element->prev_idx;

  if (idx_element->prev_idx != c_idx_not_exist)
  {
    this->data[idx_element->prev_idx].next_idx = new_idx;
  }
  else
  {
    this->first_idx = new_idx;
  }

  idx_element->prev_idx = new_idx;

  return new_idx;
}/*}}}*/

static inline unsigned rec_list_s_insert_blank_after(rec_list_s *this,unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < this->used);

  unsigned new_idx;

  if (this->free_idx != c_idx_not_exist)
  {
    new_idx = this->free_idx;
    this->free_idx = this->data[new_idx].next_idx;
  }
  else
  {
    if (this->used >= this->size)
    {
      rec_list_s_copy_resize(this,(this->size << 1) + c_array_add);
    }

    new_idx = this->used++;
  }

  rec_list_s_element *idx_element = this->data + a_idx;
  rec_list_s_element *new_element = this->data + new_idx;

  new_element->next_idx = idx_element->next_idx;
  new_element->prev_idx = a_idx;

  if (idx_element->next_idx != c_idx_not_exist)
  {
    this->data[idx_element->next_idx].prev_idx = new_idx;
  }
  else
  {
    this->last_idx = new_idx;
  }

  idx_element->next_idx = new_idx;

  return new_idx;
}/*}}}*/

static inline void rec_list_s_remove(rec_list_s *this,unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < this->used);

  rec_list_s_element *rm_element = this->data + a_idx;

  if (rm_element->next_idx != c_idx_not_exist)
  {
    this->data[rm_element->next_idx].prev_idx = rm_element->prev_idx;
  }
  else
  {
    this->last_idx = rm_element->prev_idx;
  }

  if (rm_element->prev_idx != c_idx_not_exist)
  {
    this->data[rm_element->prev_idx].next_idx = rm_element->next_idx;
  }
  else
  {
    this->first_idx = rm_element->next_idx;
  }

  rm_element->next_idx = this->free_idx;
  this->free_idx = a_idx;
}/*}}}*/

static inline unsigned rec_list_s_next_idx(rec_list_s *this,unsigned a_idx)
{/*{{{*/
  return this->data[a_idx].next_idx;
}/*}}}*/

static inline unsigned rec_list_s_prev_idx(rec_list_s *this,unsigned a_idx)
{/*{{{*/
  return this->data[a_idx].prev_idx;
}/*}}}*/

static inline void rec_list_s_copy(rec_list_s *this,rec_list_s *a_src)
{/*{{{*/
  rec_list_s_clear(this);

  if (a_src->used == 0)
  {
    return;
  }

  rec_list_s_copy_resize(this,a_src->used);

  memcpy(this->data,a_src->data,a_src->used*sizeof(rec_list_s_element));

  this->used = a_src->used;
  this->free_idx = a_src->free_idx;
  this->first_idx = a_src->first_idx;
  this->last_idx = a_src->last_idx;
}/*}}}*/



/*
 * definition of global methods
 */

void print_list(rec_list_s *rec_list,const char *name);

#endif



/*
 * methods of generated structures
 */

// -- rec_list_s --
// --- struct rec_list_s method definition ---

void rec_list_s_copy_resize(rec_list_s *this,unsigned a_size)
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
    this->data = (rec_list_s_element *)crealloc(this->data,a_size*sizeof(rec_list_s_element));
  }

  this->size = a_size;
}/*}}}*/

unsigned rec_list_s_get_idx(rec_list_s *this,record_s *a_value)
{/*{{{*/
  if (this->first_idx == c_idx_not_exist)
  {
    return c_idx_not_exist;
  }

  unsigned idx = this->first_idx;
  do {
    rec_list_s_element *element = this->data + idx;

    if (record_s_compare(&element->object,a_value))
    {
      return idx;
    }

    idx = element->next_idx;
  } while(idx != c_idx_not_exist);

  return c_idx_not_exist;
}/*}}}*/

int rec_list_s_compare(rec_list_s *this,rec_list_s *a_second)
{/*{{{*/
  if (this->first_idx == c_idx_not_exist)
  {
    return a_second->first_idx == c_idx_not_exist;
  }

  if (a_second->first_idx == c_idx_not_exist)
  {
    return 0;
  }

  unsigned idx = this->first_idx;
  unsigned s_idx = a_second->first_idx;

  do {
    rec_list_s_element *element = this->data + idx;
    rec_list_s_element *s_element = a_second->data + s_idx;

    if (!record_s_compare(&element->object,&s_element->object))
    {
      return 0;
    }

    idx = element->next_idx;
    s_idx = s_element->next_idx;

  } while(idx != c_idx_not_exist || s_idx != c_idx_not_exist);

  return idx == s_idx;
}/*}}}*/

#if OPTION_TO_STRING == ENABLED
void rec_list_s_to_string(rec_list_s *this,bc_array_s *a_trg)
{/*{{{*/
  bc_array_s_push(a_trg,'[');

  if (this->first_idx != c_idx_not_exist)
  {
    unsigned idx = this->first_idx;

    do {
      rec_list_s_element *element = this->data + idx;
      record_s_to_string(&element->object,a_trg);

      if ((idx = element->next_idx) == c_idx_not_exist)
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

void print_list(rec_list_s *rec_list,const char *name)
{
  printf("%s.size:  %u\n",name,rec_list->size);
  printf("%s.used:  %u\n",name,rec_list->used);
  printf("%s.free_idx:  %u\n",name,rec_list->free_idx);
  printf("%s.first_idx: %u\n",name,rec_list->first_idx);
  printf("%s.last_idx:  %u\n",name,rec_list->last_idx);
  printf("%s: ",name);

  if (rec_list->first_idx != c_idx_not_exist)
  {
    unsigned idx = rec_list->first_idx;
    do {
      record_s *rec = rec_list_s_at(rec_list,idx);
      printf("{%u,%u}",rec->index,rec->value);

      idx = rec_list_s_next_idx(rec_list,idx);
    } while(idx != c_idx_not_exist);
  }

  printf("\n");
  printf("\n");
}

int main(int argc, char **argv)
{
  record_s rec;
  record_s_init(&rec);
  record_s_set(&rec,1,1);

  rec_list_s list0;
#ifdef FIXED_BUFFER
  rec_list_s_init_buffer(&list0,10,alloca(10*sizeof(rec_list_s_element)));
#else
  rec_list_s_init(&list0);
#endif

  print_list(&list0,"list0");

  printf("--- APPEND NEW RECORDS TO LIST ---\n");

  unsigned idx = 0;
  do {
    rec.value = idx;
    rec_list_s_append(&list0,&rec);
  } while(++idx < 5);

  print_list(&list0,"list0");

  printf("--- PREPEND NEW RECORDS TO LIST ---\n");

  idx = 0;
  do {
    rec.value = idx;
    rec_list_s_prepend(&list0,&rec);
  } while(++idx < 5);

  print_list(&list0,"list0");

  printf("--- REMOVE RECORDS FROM LIST ---\n");

  unsigned count = 0;
  do {
    rec_list_s_remove(&list0,list0.first_idx);
  } while(++count < 5);

  print_list(&list0,"list0");

  printf("--- INSERT AFTER FIRST RECORD ---\n");

  idx = 0;
  do {
    rec.value = idx;
    rec_list_s_insert_after(&list0,list0.first_idx,&rec);
  } while(++idx < 2);

  print_list(&list0,"list0");

  printf("--- INSERT BEFORE LAST RECORD ---\n");

  idx = 0;
  do {
    rec.value = idx;
    rec_list_s_insert_before(&list0,list0.last_idx,&rec);
  } while(++idx < 2);

  print_list(&list0,"list0");

  printf("--- CREATE NEW EMPTY LIST ---\n");
  rec_list_s list1;
#ifdef FIXED_BUFFER
  rec_list_s_init_buffer(&list1,10,alloca(10*sizeof(rec_list_s_element)));
#else
  rec_list_s_init(&list1);
#endif

  print_list(&list0,"list0");
  print_list(&list1,"list1");

  printf("--- COMPARE LIST CONTENT ---\n");
  printf("rec_list_s_compare(&list0,&list1): %s\n",rec_list_s_compare(&list0,&list1) ? "TRUE" : "FALSE");
  printf("\n");

  printf("--- ASSIGN LIST CONTENT ---\n");
  rec_list_s_copy(&list1,&list0);

  print_list(&list0,"list0");
  print_list(&list1,"list1");

  printf("--- COMPARE LIST CONTENT ---\n");
  printf("rec_list_s_compare(&list0,&list1): %s\n",rec_list_s_compare(&list0,&list1) ? "TRUE" : "FALSE");
  printf("\n");

  rec_list_s_clear(&list1);
  rec_list_s_clear(&list0);
  record_s_clear(&rec);

  return 0;
}


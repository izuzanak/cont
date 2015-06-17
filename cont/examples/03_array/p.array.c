
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

// - functions used by generated code of containers -
#define debug_assert assert
#define cmalloc malloc
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

inline void record_s_init(record_s *this);
inline void record_s_clear(record_s *this);
inline void record_s_set(record_s *this,unsigned a_index,unsigned a_value);
inline void record_s_flush_all(record_s *this);
inline void record_s_swap(record_s *this,record_s *a_second);
inline void record_s_copy(record_s *this,record_s *a_src);
inline int record_s_compare(record_s *this,record_s *a_second);

inline unsigned record_s_get_index();
inline unsigned record_s_get_value();




/*
 * inline methods of generated structures
 */

// -- record_s --
// --- struct record_s inline method definition ---

inline void record_s_init(record_s *this)
{/*{{{*/
}/*}}}*/

inline void record_s_clear(record_s *this)
{/*{{{*/

   record_s_init(this);
}/*}}}*/

inline void record_s_set(record_s *this,unsigned a_index,unsigned a_value)
{/*{{{*/
   this->index = a_index;
   this->value = a_value;
}/*}}}*/

inline void record_s_flush_all(record_s *this)
{/*{{{*/
}/*}}}*/

inline void record_s_swap(record_s *this,record_s *a_second)
{/*{{{*/
   unsigned tmp_index = this->index;
   this->index = a_second->index;
   a_second->index = tmp_index;

   unsigned tmp_value = this->value;
   this->value = a_second->value;
   a_second->value = tmp_value;
}/*}}}*/

inline void record_s_copy(record_s *this,record_s *a_src)
{/*{{{*/
   this->index = a_src->index;
   this->value = a_src->value;
}/*}}}*/

inline int record_s_compare(record_s *this,record_s *a_second)
{/*{{{*/
   return (this->index == a_second->index && this->value == a_second->value);
}/*}}}*/



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

inline void rec_array_s_init(rec_array_s *this);
inline void rec_array_s_init_size(rec_array_s *this,unsigned a_size);
inline void rec_array_s_clear(rec_array_s *this);
inline void rec_array_s_set(rec_array_s *this,unsigned a_used,record_s *a_data);
inline void rec_array_s_flush(rec_array_s *this);
inline void rec_array_s_flush_all(rec_array_s *this);
inline void rec_array_s_swap(rec_array_s *this,rec_array_s *a_second);
inline record_s *rec_array_s_at(rec_array_s *this,unsigned a_idx);
inline void rec_array_s_push(rec_array_s *this,record_s *a_value);
inline void rec_array_s_push_blank(rec_array_s *this);
void rec_array_s_reserve(rec_array_s *this,unsigned a_cnt);
void rec_array_s_push_blanks(rec_array_s *this,unsigned a_cnt);
inline void rec_array_s_push_clear(rec_array_s *this);
inline record_s *rec_array_s_pop(rec_array_s *this);
inline record_s *rec_array_s_last(rec_array_s *this);
void rec_array_s_copy_resize(rec_array_s *this,unsigned a_size);
void rec_array_s_fill(rec_array_s *this,record_s *a_value);
unsigned rec_array_s_get_idx(rec_array_s *this,record_s *a_value);
inline void rec_array_s_copy(rec_array_s *this,rec_array_s *a_src);
inline int rec_array_s_compare(rec_array_s *this,rec_array_s *a_second);



/*
 * inline methods of generated structures
 */

// -- rec_array_s --
// --- struct rec_array_s inline method definition ---

inline void rec_array_s_init(rec_array_s *this)
{/*{{{*/
   this->size = 0;
   this->used = 0;
   this->data = NULL;
}/*}}}*/

inline void rec_array_s_init_size(rec_array_s *this,unsigned a_size)
{/*{{{*/
   rec_array_s_init(this);
   rec_array_s_copy_resize(this,a_size);
}/*}}}*/

inline void rec_array_s_clear(rec_array_s *this)
{/*{{{*/
   if (this->data != NULL) {
      cfree(this->data);
   }

   rec_array_s_init(this);
}/*}}}*/

inline void rec_array_s_set(rec_array_s *this,unsigned a_used,record_s *a_data)
{/*{{{*/
   rec_array_s_clear(this);
   if (a_used == 0) return;

   debug_assert(a_data != NULL);
   rec_array_s_copy_resize(this,a_used);

   memcpy(this->data,a_data,a_used*sizeof(record_s));
   this->used = a_used;
}/*}}}*/

inline void rec_array_s_flush(rec_array_s *this)
{/*{{{*/
   rec_array_s_copy_resize(this,this->used);
}/*}}}*/

inline void rec_array_s_flush_all(rec_array_s *this)
{/*{{{*/
   rec_array_s_copy_resize(this,this->used);
}/*}}}*/

inline void rec_array_s_swap(rec_array_s *this,rec_array_s *a_second)
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

inline record_s *rec_array_s_at(rec_array_s *this,unsigned a_idx)
{/*{{{*/
   debug_assert(a_idx < this->used);
   return this->data + a_idx;
}/*}}}*/

inline void rec_array_s_push(rec_array_s *this,record_s *a_value)
{/*{{{*/
   if (this->used >= this->size) {
      rec_array_s_copy_resize(this,(this->size << 1) + c_array_add);
   }

   record_s_copy(this->data + this->used++,a_value);
}/*}}}*/

inline void rec_array_s_push_blank(rec_array_s *this)
{/*{{{*/
   if (this->used >= this->size) {
      rec_array_s_copy_resize(this,(this->size << 1) + c_array_add);
   }

   this->used++;
}/*}}}*/

inline void rec_array_s_push_clear(rec_array_s *this)
{/*{{{*/
   if (this->used >= this->size) {
      rec_array_s_copy_resize(this,(this->size << 1) + c_array_add);
   }

   this->used++;
}/*}}}*/

inline record_s *rec_array_s_pop(rec_array_s *this)
{/*{{{*/
   debug_assert(this->used > 0);
   return this->data + --this->used;
}/*}}}*/

inline record_s *rec_array_s_last(rec_array_s *this)
{/*{{{*/
   debug_assert(this->used > 0);
   return this->data + this->used - 1;
}/*}}}*/

inline void rec_array_s_copy(rec_array_s *this,rec_array_s *a_src)
{/*{{{*/
   rec_array_s_clear(this);

   if (a_src->used == 0) return;

   rec_array_s_copy_resize(this,a_src->used);
   memcpy(this->data,a_src->data,a_src->used*sizeof(record_s));

   this->used = a_src->used;
}/*}}}*/

inline int rec_array_s_compare(rec_array_s *this,rec_array_s *a_second)
{/*{{{*/
   if (this->used != a_second->used) return 0;
   if (this->used == 0) return 1;

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
   if (required_cnt > this->size) {
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
   if (required_cnt > this->size) {
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

   record_s *n_data;

   if (a_size == 0) {
      n_data = NULL;
   }
   else {
      n_data = (record_s *)cmalloc(a_size*sizeof(record_s));
   }

   if (this->used != 0) {
      memcpy(n_data,this->data,this->used*sizeof(record_s));
   }

   if (this->size != 0) {
      cfree(this->data);
   }

   this->data = n_data;
   this->size = a_size;
}/*}}}*/

void rec_array_s_fill(rec_array_s *this,record_s *a_value)
{/*{{{*/
   if (this->size == 0) return;

   record_s *ptr = this->data;
   record_s *ptr_end = this->data + this->size;

   do {
      record_s_copy(ptr,a_value);
   } while(++ptr < ptr_end);

   this->used = this->size;
}/*}}}*/

unsigned rec_array_s_get_idx(rec_array_s *this,record_s *a_value)
{/*{{{*/
   if (this->used == 0) return c_idx_not_exist;

   record_s *ptr = this->data;
   record_s *ptr_end = this->data + this->used;

   do {
      if (record_s_compare(ptr,a_value)) {
         return ptr - this->data;
      }
   } while(++ptr < ptr_end);

   return c_idx_not_exist;
}/*}}}*/



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



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



#ifndef __QUEUE_H
#define __QUEUE_H


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

// -- rec_queue_s --
// struct rec_queue_s definition

typedef struct rec_queue_s rec_queue_s;

struct rec_queue_s
{
   unsigned size; //!< actual size of allocated space (element count)
   unsigned used; //!< count of stored elements
   unsigned begin; //!< position of first element
   record_s *data; //!< pointer to queue elements
};

static inline void rec_queue_s_init(rec_queue_s *this);
static inline void rec_queue_s_init_size(rec_queue_s *this,unsigned a_size);
static inline void rec_queue_s_clear(rec_queue_s *this);
static inline void rec_queue_s_flush(rec_queue_s *this);
static inline void rec_queue_s_flush_all(rec_queue_s *this);
static inline void rec_queue_s_swap(rec_queue_s *this,rec_queue_s *a_second);
static inline unsigned rec_queue_s_insert(rec_queue_s *this,record_s *a_value);
static inline unsigned rec_queue_s_insert_blank(rec_queue_s *this);
static inline record_s *rec_queue_s_next(rec_queue_s *this);
static inline record_s *rec_queue_s_last(rec_queue_s *this);
void rec_queue_s_copy_resize(rec_queue_s *this,unsigned a_size);
static inline void rec_queue_s_copy(rec_queue_s *this,rec_queue_s *a_src);
int rec_queue_s_compare(rec_queue_s *this,rec_queue_s *a_second);
#if OPTION_TO_STRING == ENABLED
void rec_queue_s_to_string(rec_queue_s *this,bc_array_s *a_trg);
#endif



/*
 * inline methods of generated structures
 */

// -- rec_queue_s --
// --- struct rec_queue_s inline method definition ---

static inline void rec_queue_s_init(rec_queue_s *this)
{/*{{{*/
   this->size = 0;
   this->used = 0;
   this->begin = 0;
   this->data = NULL;
}/*}}}*/

static inline void rec_queue_s_init_size(rec_queue_s *this,unsigned a_size)
{/*{{{*/
   rec_queue_s_init(this);
   rec_queue_s_copy_resize(this,a_size);
}/*}}}*/

static inline void rec_queue_s_clear(rec_queue_s *this)
{/*{{{*/
   if (this->data != NULL) {
      cfree(this->data);
   }

   rec_queue_s_init(this);
}/*}}}*/

static inline void rec_queue_s_flush(rec_queue_s *this)
{/*{{{*/
   rec_queue_s_copy_resize(this,this->used);
}/*}}}*/

static inline void rec_queue_s_flush_all(rec_queue_s *this)
{/*{{{*/
   rec_queue_s_copy_resize(this,this->used);
}/*}}}*/

static inline void rec_queue_s_swap(rec_queue_s *this,rec_queue_s *a_second)
{/*{{{*/
   unsigned tmp_unsigned = this->size;
   this->size = a_second->size;
   a_second->size = tmp_unsigned;

   tmp_unsigned = this->used;
   this->used = a_second->used;
   a_second->used = tmp_unsigned;

   tmp_unsigned = this->begin;
   this->begin = a_second->begin;
   a_second->begin = tmp_unsigned;

   record_s *tmp_data = this->data;
   this->data = a_second->data;
   a_second->data = tmp_data;
}/*}}}*/

static inline unsigned rec_queue_s_insert(rec_queue_s *this,record_s *a_value)
{/*{{{*/
   if (this->used >= this->size) {
      rec_queue_s_copy_resize(this,(this->size << 1) + c_array_add);
   }

   unsigned inserted_idx = this->begin + this->used++;

   if (inserted_idx >= this->size) {
      inserted_idx -= this->size;
   }

   record_s_copy(this->data + inserted_idx,a_value);

   return inserted_idx;
}/*}}}*/

static inline unsigned rec_queue_s_insert_blank(rec_queue_s *this)
{/*{{{*/
   if (this->used >= this->size) {
      rec_queue_s_copy_resize(this,(this->size << 1) + c_array_add);
   }

   unsigned inserted_idx = this->begin + this->used++;

   if (inserted_idx >= this->size) {
      inserted_idx -= this->size;
   }

   return inserted_idx;
}/*}}}*/

static inline record_s *rec_queue_s_next(rec_queue_s *this)
{/*{{{*/
   debug_assert(this->used > 0);

   unsigned ret_idx = this->begin;

   if (++this->begin >= this->size) {
      this->begin = 0;
   }

   this->used--;

   return this->data + ret_idx;
}/*}}}*/

static inline record_s *rec_queue_s_last(rec_queue_s *this)
{/*{{{*/
   debug_assert(this->used > 0);

   unsigned last_idx = this->begin + (this->used - 1);
   if (last_idx >= this->size) {
      return this->data + last_idx - this->size;
   }
   else {
      return this->data + last_idx;
   }
}/*}}}*/

static inline void rec_queue_s_copy(rec_queue_s *this,rec_queue_s *a_src)
{/*{{{*/
   rec_queue_s_clear(this);

   if (a_src->used == 0) return;

   rec_queue_s_copy_resize(this,a_src->used);

   unsigned fir_cnt;
   unsigned sec_cnt;

   if (a_src->begin + a_src->used > a_src->size) {
      sec_cnt = a_src->begin + a_src->used - a_src->size;
      fir_cnt = a_src->used - sec_cnt;
   }
   else {
      fir_cnt = a_src->used;
      sec_cnt = 0;
   }

   memcpy(this->data,a_src->data + a_src->begin,fir_cnt*sizeof(record_s));

   if (sec_cnt != 0) {
      memcpy(this->data + fir_cnt,a_src->data,sec_cnt*sizeof(record_s));
   }

   this->used = a_src->used;
}/*}}}*/



/*
 * definition of global methods
 */

void print_queue(rec_queue_s *rec_queue,const char *name);

#endif



/*
 * methods of generated structures
 */

// -- rec_queue_s --
// --- struct rec_queue_s method definition ---

void rec_queue_s_copy_resize(rec_queue_s *this,unsigned a_size)
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
      unsigned fir_cnt;
      unsigned sec_cnt;

      if (this->begin + this->used > this->size) {
         sec_cnt = this->begin + this->used - this->size;
         fir_cnt = this->used - sec_cnt;
      }
      else {
         fir_cnt = this->used;
         sec_cnt = 0;
      }

      memcpy(n_data,this->data + this->begin,fir_cnt*sizeof(record_s));

      if (sec_cnt != 0) {
         memcpy(n_data + fir_cnt,this->data,sec_cnt*sizeof(record_s));
      }
   }

   if (this->size != 0) {
      cfree(this->data);
   }

   this->data = n_data;
   this->size = a_size;
   this->begin = 0;
}/*}}}*/

int rec_queue_s_compare(rec_queue_s *this,rec_queue_s *a_second)
{/*{{{*/
   if (this->used != a_second->used) return 0;
   if (this->used == 0) return 1;

   int _break;
   int s_break;
   unsigned pos;
   unsigned pos_end;
   unsigned s_pos;

   _break = (this->begin + this->used > this->size);
   s_break = (a_second->begin + a_second->used > a_second->size);
   pos = this->begin;
   s_pos = a_second->begin;

   if (_break) {
      pos_end = this->begin + this->used - this->size;
   }
   else {
      pos_end = this->begin + this->used;
   }

   do {
      if (_break) {
         unsigned offset = this->size - pos;

         if (s_break) {
            unsigned s_offset = a_second->size = s_pos;

            if (offset < s_offset) {
               if (memcmp(this->data + pos,a_second->data + s_pos,offset*sizeof(record_s)) != 0) {
                  return 0;
               }

               s_pos += offset;
               pos = 0;
               _break = 0;
            }
            else {
               if (memcmp(this->data + pos,a_second->data + s_pos,s_offset*sizeof(record_s)) != 0) {
                  return 0;
               }

               if (pos += s_offset >= this->size) {
                  pos = 0;
                  _break = 0;
               }
               s_pos = 0;
               s_break = 0;
            }
         }
         else {
            if (memcmp(this->data + pos,a_second->data + s_pos,offset*sizeof(record_s)) != 0) {
               return 0;
            }
            s_pos += offset;
            pos = 0;
            _break = 0;
         }
      }
      else {
         if (s_break) {
            unsigned s_offset = a_second->size - s_pos;

            if (memcmp(this->data + pos,a_second->data + s_pos,s_offset*sizeof(record_s)) != 0) {
               return 0;
            }
            pos += s_offset;
            s_pos = 0;
            s_break = 0;
         }
         else {
            if (memcmp(this->data + pos,a_second->data + s_pos,(pos_end - pos)*sizeof(record_s)) != 0) {
               return 0;
            }
            else {
               return 1;
            }
         }
      }
   } while(1);
}/*}}}*/

#if OPTION_TO_STRING == ENABLED
void rec_queue_s_to_string(rec_queue_s *this,bc_array_s *a_trg)
{/*{{{*/
   bc_array_s_push(a_trg,'[');

   if (this->used != 0)
   {
      unsigned sec_cnt;
      record_s *ptr = this->data + this->begin;
      record_s *ptr_end;

      if (this->begin + this->used > this->size) {
         ptr_end = this->data + this->size;
         sec_cnt = this->begin + this->used - this->size;
      }
      else {
         ptr_end = ptr + this->used;
         sec_cnt = 0;
      }

      do {
         record_s_to_string(ptr,a_trg);

         if (++ptr >= ptr_end)
            break;

         bc_array_s_push(a_trg,',');
      } while(1);

      if (sec_cnt != 0) {
         ptr = this->data;
         ptr_end = ptr + sec_cnt;

         do {
            bc_array_s_push(a_trg,',');
            record_s_to_string(ptr,a_trg);
         } while(++ptr < ptr_end);
      }
   }

   bc_array_s_push(a_trg,']');
}/*}}}*/
#endif



/*
 * global methods
 */

void print_queue(rec_queue_s *rec_queue,const char *name)
{
  printf("%s.size:  %u\n",name,rec_queue->size);
  printf("%s.used:  %u\n",name,rec_queue->used);
  printf("%s.begin: %u\n",name,rec_queue->begin);
  printf("%s: ",name);

  if (rec_queue->used > 0)
  {
    unsigned idx = rec_queue->begin;
    unsigned idx_end = (idx + rec_queue->used) % rec_queue->size;
    do {
      record_s *rec = rec_queue->data + idx;
      printf("{%u,%u}",rec->index,rec->value);

      idx = (idx + 1) % rec_queue->size;
    } while(idx != idx_end); 
  }

  printf("\n");
  printf("\n");
}

int main(int argc, char **argv)
{
  record_s rec;
  record_s_init(&rec);
  record_s_set(&rec,1,1);

  printf("--- CREATE AND FILL RECORDS QUEUE ---\n");
  rec_queue_s queue0;
  rec_queue_s_init_size(&queue0,10);

  unsigned idx = 0;
  do {
    rec.value = idx;
    rec_queue_s_insert(&queue0,&rec);
  } while(++idx < 5);

  print_queue(&queue0,"queue0");

  printf("--- RETRIEVE RECORDS FROM QUEUE ---\n");
  idx = 0;
  do {
    rec_queue_s_next(&queue0);
  } while(++idx < 3);

  print_queue(&queue0,"queue0");

  printf("--- INSERT NEW RECORDS TO QUEUE ---\n");

  idx = 0;
  do {
    rec.value = idx;
    rec_queue_s_insert(&queue0,&rec);
  } while(++idx < 7);

  print_queue(&queue0,"queue0");

  printf("--- CREATE NEW EMPTY QUEUE ---\n");
  rec_queue_s queue1;
  rec_queue_s_init(&queue1);

  print_queue(&queue0,"queue0");
  print_queue(&queue1,"queue1");

  printf("--- COMPARE QUEUE CONTENT ---\n");
  printf("rec_queue_s_compare(&queue0,&queue1): %s\n",rec_queue_s_compare(&queue0,&queue1) ? "TRUE" : "FALSE");
  printf("\n");

  printf("--- ASSIGN QUEUE CONTENT ---\n");
  rec_queue_s_copy(&queue1,&queue0);

  print_queue(&queue0,"queue0");
  print_queue(&queue1,"queue1");

  printf("--- COMPARE QUEUE CONTENT ---\n");
  printf("rec_queue_s_compare(&queue0,&queue1): %s\n",rec_queue_s_compare(&queue0,&queue1) ? "TRUE" : "FALSE");
  printf("\n");

  printf("--- CLEAR QUEUE CONTENT ---\n");
  rec_queue_s_clear(&queue0);

  print_queue(&queue0,"queue0");

  rec_queue_s_clear(&queue1);
  rec_queue_s_clear(&queue0);
  record_s_clear(&rec);

  return 0;
}



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

// -- rec_queue_s --
// struct rec_queue_s definition

/*!
 * \brief __GEN queue of type record_s
 */
struct rec_queue_s
{
   unsigned size; //!< actual size of allocated space (element count)
   unsigned used; //!< count of stored elements
   unsigned begin; //!< position of first element
   record_s *data; //!< pointer to queue elements

   /*!
    * \brief __GEN initialize queue
    */
   inline void init();

   /*!
    * \brief __GEN initialize queue of requested size
    * \param a_size - requested size of queue
    */
   inline void init_size(unsigned a_size);

   /*!
    * \brief __GEN release memory used by queue
    */
   inline void clear();

   /*!
    * \brief __GEN flush queue memory usage
    */
   inline void flush();

   /*!
    * \brief __GEN flush queue memory usage, recursive on elements
    */
   inline void flush_all();

   /*!
    * \brief __GEN swap members of queue with another queue
    * \param a_second - reference to another queue
    */
   inline void swap(rec_queue_s &a_second);

   /*!
    * \brief __GEN insert element to end of queue
    * \param a_value - value inserted to end of queue
    * \return index of inserted element
    */
   inline unsigned insert(record_s &a_value);

   /*!
    * \brief __GEN insert blank element to the end of queue
    * \return index of inserted element
    */
   inline unsigned insert_blank();

   /*!
    * \brief __GEN return value of next element in queue, and remove it
    * \return reference to next element
    */
   inline record_s &next();

   /*!
    * \brief __GEN return value of last element in queue
    * \return reference to last element
    */
   inline record_s &last();

   /*!
    * \brief __GEN change queue capacity
    * \param a_size - requested queue capacity
    */
   void copy_resize(unsigned a_size);

   /*!
    * \brief __GEN copy queue from another queue
    * \param a_src - reference to another queue
    * \return reference to this queue
    */
   inline rec_queue_s &operator=(rec_queue_s &a_src);

   /*!
    * \brief __GEN compare queue with another queue
    * \param a_second - reference to another queue
    * \return result of comparision
    */
   bool operator==(rec_queue_s &a_second);

};



/*
 * inline methods of generated structures
 */

// -- rec_queue_s --
// --- struct rec_queue_s inline method definition ---

inline void rec_queue_s::init()
{/*{{{*/
   size = 0;
   used = 0;
   begin = 0;
   data = nullptr;
}/*}}}*/

inline void rec_queue_s::init_size(unsigned a_size)
{/*{{{*/
   init();
   copy_resize(a_size);
}/*}}}*/

inline void rec_queue_s::clear()
{/*{{{*/
   if (data != nullptr) {
      cfree(data);
   }

   init();
}/*}}}*/

inline void rec_queue_s::flush()
{/*{{{*/
   copy_resize(used);
}/*}}}*/

inline void rec_queue_s::flush_all()
{/*{{{*/
   copy_resize(used);
}/*}}}*/

inline void rec_queue_s::swap(rec_queue_s &a_second)
{/*{{{*/
   unsigned tmp_unsigned = size;
   size = a_second.size;
   a_second.size = tmp_unsigned;

   tmp_unsigned = used;
   used = a_second.used;
   a_second.used = tmp_unsigned;

   tmp_unsigned = begin;
   begin = a_second.begin;
   a_second.begin = tmp_unsigned;

   record_s *tmp_data = data;
   data = a_second.data;
   a_second.data = tmp_data;
}/*}}}*/

inline unsigned rec_queue_s::insert(record_s &a_value)
{/*{{{*/
   if (used >= size) {
      copy_resize((size << 1) + c_array_add);
   }

   unsigned inserted_idx = begin + used++;
   if (inserted_idx >= size) {
      inserted_idx -= size;
   }

   data[inserted_idx] = a_value;

   return inserted_idx;
}/*}}}*/

inline unsigned rec_queue_s::insert_blank()
{/*{{{*/
   if (used >= size) {
      copy_resize((size << 1) + c_array_add);
   }

   unsigned inserted_idx = begin + used++;
   if (inserted_idx >= size) {
      inserted_idx -= size;
   }

   return inserted_idx;
}/*}}}*/

inline record_s &rec_queue_s::next()
{/*{{{*/
   debug_assert(used > 0);

   unsigned ret_idx = begin;

   if (++begin >= size) {
      begin = 0;
   }

   used--;
   
   return data[ret_idx];
}/*}}}*/

inline record_s &rec_queue_s::last()
{/*{{{*/
   debug_assert(used > 0);

   unsigned last_idx = begin + (used - 1);
   if (last_idx >= size) {
      return data[last_idx - size];
   }
   else {
      return data[last_idx];
   }
}/*}}}*/

inline rec_queue_s &rec_queue_s::operator=(rec_queue_s &a_src)
{/*{{{*/
   clear();

   if (a_src.used == 0) return *this;

   copy_resize(a_src.used);

   unsigned fir_cnt;
   unsigned sec_cnt;

   if (a_src.begin + a_src.used > a_src.size) {
      sec_cnt = a_src.begin + a_src.used - a_src.size;
      fir_cnt = a_src.used - sec_cnt;
   }
   else {
      fir_cnt = a_src.used;
      sec_cnt = 0;
   }

   memcpy(data,a_src.data + a_src.begin,fir_cnt*sizeof(record_s));

   if (sec_cnt != 0) {
      memcpy(data + fir_cnt,a_src.data,sec_cnt*sizeof(record_s));
   }

   used = a_src.used;
   return *this;
}/*}}}*/



/*
 * definition of global methods
 */

void print_queue(rec_queue_s &rec_queue,const char *name);

#endif



/*
 * methods of generated structures
 */

// -- rec_queue_s --
// --- struct rec_queue_s method definition ---

void rec_queue_s::copy_resize(unsigned a_size)
{/*{{{*/
   debug_assert(a_size >= used);

   record_s *n_data;

   if (a_size == 0) {
      n_data = nullptr;
   }
   else {
      n_data = (record_s *)cmalloc(a_size*sizeof(record_s));
   }

   if (used != 0) {
      unsigned fir_cnt;
      unsigned sec_cnt;

      if (begin + used > size) {
         sec_cnt = begin + used - size;
         fir_cnt = used - sec_cnt;
      }
      else {
         fir_cnt = used;
         sec_cnt = 0;
      }

      memcpy(n_data,data + begin,fir_cnt*sizeof(record_s));

      if (sec_cnt != 0) {
         memcpy(n_data + fir_cnt,data,sec_cnt*sizeof(record_s));
      }
   }

   if (size != 0) {
      cfree(data);
   }

   data = n_data;
   size = a_size;
   begin = 0;
}/*}}}*/

bool rec_queue_s::operator==(rec_queue_s &a_second)
{/*{{{*/
   if (used != a_second.used) return false;
   if (used == 0) return true;

   bool _break;
   bool s_break;
   unsigned pos;
   unsigned pos_end;
   unsigned s_pos;

   _break = (begin + used > size);
   s_break = (a_second.begin + a_second.used > a_second.size);
   pos = begin;
   s_pos = a_second.begin;

   if (_break) {
      pos_end = begin + used - size;
   }
   else {
      pos_end = begin + used;
   }

   do {
      if (_break) {
         unsigned offset = size - pos;
         
         if (s_break) {
            unsigned s_offset = a_second.size = s_pos;

            if (offset < s_offset) {
               if (memcmp(data + pos,a_second.data + s_pos,offset*sizeof(record_s)) != 0) {
                  return false;
               }

               s_pos += offset;
               pos = 0;
               _break = false;
            }
            else {
               if (memcmp(data + pos,a_second.data + s_pos,s_offset*sizeof(record_s)) != 0) {
                  return false;
               }

               if (pos += s_offset >= size) {
                  pos = 0;
                  _break = false;
               }
               s_pos = 0;
               s_break = false;
            }
         }
         else {
            if (memcmp(data + pos,a_second.data + s_pos,offset*sizeof(record_s)) != 0) {
               return false;
            }
            s_pos += offset;
            pos = 0;
            _break = false;
         }
      }
      else {
         if (s_break) {
            unsigned s_offset = a_second.size - s_pos;

            if (memcmp(data + pos,a_second.data + s_pos,s_offset*sizeof(record_s)) != 0) {
               return false;
            }
            pos += s_offset;
            s_pos = 0;
            s_break = false;
         }
         else {
            if (memcmp(data + pos,a_second.data + s_pos,(pos_end - pos)*sizeof(record_s)) != 0) {
               return false;
            }
            else {
               return true;
            }
         }
      }
   } while(1);
}/*}}}*/



/*
 * global methods
 */

void print_queue(rec_queue_s &rec_queue,const char *name)
{
  printf("%s.size:  %u\n",name,rec_queue.size);
  printf("%s.used:  %u\n",name,rec_queue.used);
  printf("%s.begin: %u\n",name,rec_queue.begin);
  printf("%s: ",name);

  if (rec_queue.used > 0)
  {
    unsigned idx = rec_queue.begin;
    unsigned idx_end = (idx + rec_queue.used) % rec_queue.size;
    do {
      record_s &rec = rec_queue.data[idx];
      printf("{%u,%u}",rec.index,rec.value);

      idx = (idx + 1) % rec_queue.size;
    } while(idx != idx_end); 
  }

  printf("\n");
  printf("\n");
}

int main(int argc, char **argv)
{
  record_s rec;
  rec.init();
  rec.set(1,1);

  printf("--- CREATE AND FILL RECORDS QUEUE ---\n");
  rec_queue_s queue0;
  queue0.init_size(10);

  unsigned idx = 0;
  do {
    rec.value = idx;
    queue0.insert(rec);
  } while(++idx < 5);

  print_queue(queue0,"queue0");

  printf("--- RETRIEVE RECORDS FROM QUEUE ---\n");
  idx = 0;
  do {
    queue0.next();
  } while(++idx < 3);

  print_queue(queue0,"queue0");

  printf("--- INSERT NEW RECORDS TO QUEUE ---\n");

  idx = 0;
  do {
    rec.value = idx;
    queue0.insert(rec);
  } while(++idx < 7);

  print_queue(queue0,"queue0");

  printf("--- CREATE NEW EMPTY QUEUE ---\n");
  rec_queue_s queue1;
  queue1.init();

  print_queue(queue0,"queue0");
  print_queue(queue1,"queue1");

  printf("--- COMPARE QUEUE CONTENT ---\n");
  printf("queue0 == queue1: %s\n",queue0 == queue1 ? "TRUE" : "FALSE");
  printf("\n");

  printf("--- ASSIGN QUEUE CONTENT ---\n");
  queue1 = queue0;

  print_queue(queue0,"queue0");
  print_queue(queue1,"queue1");

  printf("--- COMPARE QUEUE CONTENT ---\n");
  printf("queue0 == queue1: %s\n",queue0 == queue1 ? "TRUE" : "FALSE");
  printf("\n");

  printf("--- CLEAR QUEUE CONTENT ---\n");
  queue0.clear();

  print_queue(queue0,"queue0");

  queue1.clear();
  queue0.clear();
  rec.clear();

  return 0;
}



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



#ifndef __PROCESS_H
#define __PROCESS_H


#ifndef __BASIC_H
#define __BASIC_H

#define ENABLE 1

// - system type selection -
#define SYSTEM_TYPE_UNIX      1 // - for system calls use unix environment
#define SYSTEM_TYPE_WINDOWS   2 // - for system calls use windows environment
// --

// - mutex library selection -
#define MUTEX_TYPE_PTHREAD    1 // - for mutex implementation use pthread mutex
#define MUTEX_TYPE_WINDOWS    2 // - for mutex implementation use win32 library
// --

// - basic system configuration -
#ifdef LINUX
#define SYSTEM_TYPE SYSTEM_TYPE_UNIX
#define MUTEX_TYPE MUTEX_TYPE_PTHREAD
#endif

#ifdef WINDOWS
#define _WIN32_WINNT 0x0500
#define SYSTEM_TYPE SYSTEM_TYPE_WINDOWS
#define MUTEX_TYPE MUTEX_TYPE_WINDOWS
#endif

// - system includes -
#if THREAD_LIB == THREAD_LIB_PTHREAD || MUTEX_TYPE == MUTEX_TYPE_PTHREAD
#include <pthread.h>
#include <errno.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#if SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
#include <windows.h>
#include <math.h>
#endif

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>
#include <sys/time.h>
#endif

// - asserts definitions -
#define DEBUG_ASSERT ENABLE
#define CASSERT ENABLE

#if DEBUG_ASSERT == ENABLE
#define debug_assert(A_COND)\
{\
   if (!(A_COND)) {\
      fprintf(stderr,"DEBUG_ASSERT: %s, line: %d, function: %s\n",__FILE__,__LINE__,__FUNCTION__);\
      fflush(stderr);\
      abort();\
   }\
}
#else
#define debug_assert(A_COND)
#endif

#if CASSERT == ENABLE
#define cassert(A_COND)\
{\
   if (!(A_COND)) {\
      fprintf(stderr,"CASSERT: %s, line: %d, function: %s\n",__FILE__,__LINE__,__FUNCTION__);\
      fflush(stderr);\
      abort();\
   }\
}
#else
#define cassert(A_COND)
#endif

// - basic constants -
const unsigned c_array_add = 64;
const unsigned c_idx_not_exist = UINT_MAX;

// - bit count of basic types -
const unsigned INT_BIT = (sizeof(int)*CHAR_BIT);
const unsigned UINT_BIT = (sizeof(unsigned)*CHAR_BIT);

// - pi number definitions -
const float c_pi_number = 3.14159265358979323844;
const float c_2pi_number = 6.28318530717958647688;
const float c_pid2_number = 1.57079632679489661922;

// - logarithm of two (needed by red-black tree container) -
const float c_log_of_2 = logf(2.0f);

// - count of system cpu cores -
const unsigned c_cpu_core_cnt = 2;

// - system errors -
enum {
   c_error_OK,
   c_error_UNKNOWN,
   c_error_EINVAL,
   c_error_EBUSY,
   c_error_EDEADLK,
   c_error_EPERM,
   c_error_EAGAIN,
   c_error_ESRCH,
};

/*
 * debug_message macro definition
 */

#define DEBUG_MESSAGES 0

#if DEBUG_MESSAGES >= 1
   #if THREAD_LIB == THREAD_LIB_PTHREAD
   #define debug_message_1(MSG) fprintf(stderr,"thread %u, DLvl. 1: ",(unsigned)pthread_self()); MSG
   #else
   #define debug_message_1(MSG) fprintf(stderr,"DLvl. 1: "); MSG
   #endif
#else
   #define debug_message_1(MSG) 
#endif

#if DEBUG_MESSAGES >= 2
   #if THREAD_LIB == THREAD_LIB_PTHREAD
   #define debug_message_2(MSG) fprintf(stderr,"thread %u, DLvl. 2: ",(unsigned)pthread_self()); MSG
   #else
   #define debug_message_2(MSG) fprintf(stderr,"DLvl. 2: "); MSG
   #endif
#else
   #define debug_message_2(MSG) 
#endif

#if DEBUG_MESSAGES >= 3
   #if THREAD_LIB == THREAD_LIB_PTHREAD
   #define debug_message_3(MSG) fprintf(stderr,"thread %u, DLvl. 3: ",(unsigned)pthread_self()); MSG
   #else
   #define debug_message_3(MSG) fprintf(stderr,"DLvl. 3: "); MSG
   #endif
#else
   #define debug_message_3(MSG) 
#endif

#if DEBUG_MESSAGES >= 4
   #if THREAD_LIB == THREAD_LIB_PTHREAD
   #define debug_message_4(MSG) fprintf(stderr,"thread %u, DLvl. 4: ",(unsigned)pthread_self()); MSG
   #else
   #define debug_message_4(MSG) fprintf(stderr,"DLvl. 4: "); MSG
   #endif
#else
   #define debug_message_4(MSG) 
#endif

#if DEBUG_MESSAGES >= 5
   #if THREAD_LIB == THREAD_LIB_PTHREAD
   #define debug_message_5(MSG) fprintf(stderr,"thread %u, DLvl. 5: ",(unsigned)pthread_self()); MSG
   #else
   #define debug_message_5(MSG) fprintf(stderr,"DLvl. 5: "); MSG
   #endif
#else
   #define debug_message_5(MSG) 
#endif

#if DEBUG_MESSAGES >= 6
   #if THREAD_LIB == THREAD_LIB_PTHREAD
   #define debug_message_6(MSG) fprintf(stderr,"thread %u, DLvl. 6: ",(unsigned)pthread_self()); MSG
   #else
   #define debug_message_6(MSG) fprintf(stderr,"DLvl. 6: "); MSG
   #endif
#else
   #define debug_message_6(MSG) 
#endif

/*
 * definition of basic types
 */

// - unsigned integer with same size as pointer -
typedef long unsigned t_ps_uint;

// - pointer typedef -
typedef void * pointer;


// - pointer_ptr typedef -
typedef void ** pointer_ptr;


typedef FILE * FILE_ptr;



/*
 * definitions of generated structures
 */

/*
 * inline methods of generated structures
 */

#endif


#ifndef __MEM_CHECK_H
#define __MEM_CHECK_H


#ifndef __MUTEX_H
#define __MUTEX_H



/*
 * definition of structure mutex_s
 */



struct mutex_s
{
#if MUTEX_TYPE == MUTEX_TYPE_PTHREAD
   pthread_mutex_t mutex;
#elif MUTEX_TYPE == MUTEX_TYPE_WINDOWS
   HANDLE handle;
#endif

   inline unsigned init();
   inline unsigned clear();
   inline void flush_all() {}
   inline void swap(mutex_s &a_second) {cassert(0);}
   inline mutex_s &operator=(mutex_s &a_src) {cassert(0); return *this;}
   inline bool operator==(mutex_s &a_second) {cassert(0); return false;}

   /*!
    * \brief lock mutex
    * \return error code
    */
   inline unsigned lock();

   /*!
    * \brief try to lock mutex
    * \return error code
    */
   inline unsigned try_lock();

   /*!
    * \brief unlock mutex
    * \return error code
    */
   inline unsigned unlock();
};

/*
 * inline methods of structure mutex_s
 */

inline unsigned mutex_s::init()
{/*{{{*/
#if MUTEX_TYPE == MUTEX_TYPE_PTHREAD
   pthread_mutexattr_t attr;
   pthread_mutexattr_init(&attr);

   pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE_NP);

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
   int res = pthread_mutexattr_setpshared(&attr,PTHREAD_PROCESS_SHARED);
   if (res != 0) {
      switch (res) {
      case EINVAL:
         return c_error_EINVAL;
      default:
         return c_error_UNKNOWN;
      }
   }
#endif

   pthread_mutex_init(&mutex,&attr);
   pthread_mutexattr_destroy(&attr);

   return c_error_OK;
#elif MUTEX_TYPE == MUTEX_TYPE_WINDOWS
   if ((handle = CreateMutex(NULL,FALSE,NULL)) == NULL) {
      return c_error_UNKNOWN;
   }

   return c_error_OK;
#else
   cassert(0);
   return c_error_UNKNOWN;
#endif
}/*}}}*/

inline unsigned mutex_s::clear()
{/*{{{*/
#if MUTEX_TYPE == MUTEX_TYPE_PTHREAD
   int ret = pthread_mutex_destroy(&mutex);
   switch (ret) {
   case 0:
      return c_error_OK;
   case EBUSY:
      return c_error_EBUSY;
   default:
      return c_error_UNKNOWN;
   }
#elif MUTEX_TYPE == MUTEX_TYPE_WINDOWS
   if (CloseHandle(handle) == 0) {
      return c_error_UNKNOWN;
   }

   return c_error_OK;
#else
   cassert(0);
   return c_error_UNKNOWN;
#endif
}/*}}}*/

inline unsigned mutex_s::lock()
{/*{{{*/
#if MUTEX_TYPE == MUTEX_TYPE_PTHREAD
   int ret = pthread_mutex_lock(&mutex);
   switch (ret) {
   case 0:
      return c_error_OK;
   case EINVAL:
      return c_error_EINVAL;
   case EDEADLK:
      return c_error_EDEADLK;
   default:
      return c_error_UNKNOWN;
   }
#elif MUTEX_TYPE == MUTEX_TYPE_WINDOWS
   DWORD ret = WaitForSingleObject(handle,INFINITE);
   if (ret == WAIT_FAILED) {
      return c_error_UNKNOWN;
   }

   return c_error_OK;
#else
   cassert(0);
   return c_error_UNKNOWN;
#endif
}/*}}}*/

inline unsigned mutex_s::try_lock()
{/*{{{*/
#if MUTEX_TYPE == MUTEX_TYPE_PTHREAD
   int ret = pthread_mutex_trylock(&mutex);
   switch (ret) {
   case 0:
      return c_error_OK;
   case EBUSY:
      return c_error_EBUSY;
   case EINVAL:
      return c_error_EINVAL;
   default:
      return c_error_UNKNOWN;
   }
#elif MUTEX_TYPE == MUTEX_TYPE_WINDOWS
   DWORD ret = WaitForSingleObject(handle,(DWORD)0);
   switch (ret) {
   case WAIT_ABANDONED:
   case WAIT_OBJECT_0:
      return c_error_OK;
   case WAIT_TIMEOUT:
      return c_error_EBUSY;
   default:
      return c_error_UNKNOWN;
   }
#else
   cassert(0);
   return c_error_UNKNOWN;
#endif
}/*}}}*/

inline unsigned mutex_s::unlock()
{/*{{{*/
#if MUTEX_TYPE == MUTEX_TYPE_PTHREAD
   int ret = pthread_mutex_unlock(&mutex);
   switch (ret) {
   case 0:
      return c_error_OK;
   case EINVAL:
      return c_error_EINVAL;
   case EPERM:
      return c_error_EPERM;
   default:
      return c_error_UNKNOWN;
   }
#elif MUTEX_TYPE == MUTEX_TYPE_WINDOWS
   if (ReleaseMutex(handle) == 0) {
      return c_error_UNKNOWN;
   }

   return c_error_OK;
#else
   cassert(0);
   return c_error_UNKNOWN;
#endif
}/*}}}*/

#endif



//#define MEM_CHECK ENABLE

// - declare cmalloc/cfree functions -
inline void *cmalloc(unsigned a_size);
inline void cfree(void *a_location);

/*
 * definition of generated structures
 */

// -- ui_array_s --
// --- struct ui_array_s definition --- 

/*!
 * \brief __GEN array of type unsigned
 */
struct ui_array_s
{
   unsigned size; //!< actual size of allocated space in array
   unsigned used; //!< count of used space in array
   unsigned *data; //!< pointer to array elements

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
   inline void clear();

   /*!
    * \brief __GEN set array content from element pointer
    * \param a_used - number of elements stored at pointed location
    * \param a_data - pointer to elements
    */
   inline void set(unsigned a_used,unsigned *a_data);

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
   inline void swap(ui_array_s &a_second);

   /*!
    * \brief __GEN select element of array
    * \param a_idx - index of element in array
    * \return reference to element of array
    */
   inline unsigned &operator[](unsigned a_idx);

   /*!
    * \brief __GEN insert element to end of array
    * \param a_value - value of inserted element
    */
   inline void push(unsigned a_value);

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
   inline unsigned &pop();

   /*!
    * \brief __GEN return value of last element in array
    * \return reference to last element
    */
   inline unsigned &last();

   /*!
    * \brief __GEN change array capacity
    * \param a_size - requested array capacity
    */
   void copy_resize(unsigned a_size);

   /*!
    * \brief __GEN set all elements of array to given value
    * \param a_value - new value of all elements
    */
   void fill(unsigned a_value);

   /*!
    * \brief __GEN search for index of element
    * \param a_value - value which index is searched
    */
   unsigned get_idx(unsigned a_value);

   /*!
    * \brief __GEN copy array from another array
    * \param a_src - reference to another array
    * \return reference to this array
    */
   inline ui_array_s &operator=(ui_array_s &a_src);

   /*!
    * \brief __GEN comparison of array with another array
    * \param a_second - reference to another array
    * \return result of comparison
    */
   inline bool operator==(ui_array_s &a_second);

};



#if MEM_CHECK == ENABLE

// -- mc_block_s --
// structure mc_block_s definition

/*!
 * \brief __GEN structure
 */
struct mc_block_s
{
   pointer location; //!< member - 0
   unsigned size; //!< member - 1

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
   inline void set(pointer a_location,unsigned a_size);
   /*!
    * \brief __GEN flush structure memory usage, recursive on members
    */
   inline void flush_all();

   /*!
    * \brief __GEN swap structure members with another structure
    */
   inline void swap(mc_block_s &a_second);

   /*!
    * \brief __GEN copy structure from another structure
    * \param a_src - reference to another structure
    * \return reference to this structure
    */
   inline mc_block_s &operator=(mc_block_s &a_src);

   /*!
    * \brief __GEN compare structure with another structure
    * \param a_second - reference to another structure
    * \return result of comparison
    */
   inline bool operator==(mc_block_s &a_second);

};



// -- mc_block_rb_tree_s --
// struct mc_block_rb_tree_s definition

/*!
 * \brief __GEN node of rb_tree of type mc_block_s
 */

struct mc_block_rb_tree_s_node
{
   mc_block_s object;
   bool valid;
   unsigned parent_idx;
   unsigned left_idx;
   unsigned right_idx;
   bool color;
};

/*!
 * \brief __GEN rb_tree of type mc_block_s
 */
struct mc_block_rb_tree_s
{
   unsigned size;
   unsigned used;
   unsigned count;
   mc_block_rb_tree_s_node *data;
   unsigned free_idx;
   unsigned root_idx;
   unsigned leaf_idx;

   // - internal support methods -
   inline unsigned __get_grandparent_idx(unsigned a_idx);
   inline unsigned __get_uncle_idx(unsigned a_idx);
   inline unsigned __get_sibling_idx(unsigned a_idx);

   inline unsigned get_descent_stack_size();
   unsigned get_stack_min_value_idx(unsigned a_idx,unsigned **a_s_ptr);
   inline unsigned get_stack_next_idx(unsigned a_idx,unsigned **a_s_ptr,unsigned *a_stack_base);

   unsigned get_min_value_idx(unsigned a_idx);
   unsigned get_max_value_idx(unsigned a_idx);
   unsigned get_next_idx(unsigned a_idx);
   unsigned get_prev_idx(unsigned a_idx);

   inline void __rotate_left(unsigned a_idx);
   inline void __rotate_right(unsigned a_idx);

   inline unsigned __get_new_index();
   bool __binary_tree_insert(unsigned a_new_idx,mc_block_s &a_value,bool a_unique);

   inline void __replace_delete_node_by_child(unsigned a_idx,unsigned a_ch_idx);
   void __remove_black_black(unsigned a_idx);

   inline void __remove_one_child(unsigned a_idx,unsigned a_ch_idx);

   void __insert_operation(unsigned a_idx);

   inline int __compare_value(mc_block_s &a_first,mc_block_s &a_second);

   /*!
    * \brief __GEN initialize rb_tree
    */
   inline void init();

   /*!
    * \brief __GEN release memory used by rb_tree
    */
   inline void clear();

   /*!
    * \brief __GEN flush rb_tree memory usage
    */
   inline void flush();

   /*!
    * \brief __GEN flush rb_tree memory usage, recursive on nodes
    */
   inline void flush_all();

   /*!
    * \brief __GEN swap members of rb_tree with another rb_tree
    * \param a_second - reference to another rb_tree
    */
   inline void swap(mc_block_rb_tree_s &a_second);

   /*!
    * \brief __GEN select ode of rb_tree
    * \param a_idx - index of node in rb_tree
    * \return reference to node of rb_tree
    */
   inline mc_block_s &operator[](unsigned a_idx);

   /*!
    * \brief __GEN insert node to rb_tree
    * \param a_value - reference to value inserted to rb_tree
    * \return - position of node in rb_tree
    */
   inline unsigned insert(mc_block_s &a_value);

   /*!
    * \brief __GEN insert node to rb_tree by swapping
    * \param a_value - reference to value inserted to rb_tree
    * \return - position of node in rb_tree
    */
   inline unsigned swap_insert(mc_block_s &a_value);
   /*!
    * \brief __GEN remove node at index from rb_tree
    * \param a_idx - index of node to remove
    */
   void remove(unsigned a_idx);

   /*!
    * \brief __GEN resize rb_tree capacity
    * \param a_size - desired rb_tree capacity
    */
   void copy_resize(unsigned a_size);

   /*!
    * \brief __GEN search for index of node
    * \param a_value - value which index is searched
    */
   unsigned get_idx(mc_block_s &a_value);

   /*!
    * \brief __GEN search for leftmost index of node
    * \param a_value - value which index is searched
    */
   unsigned get_idx_left(mc_block_s &a_value);

   /*!
    * \brief __GEN search for index of node with greater or equal value
    * \param a_value - value which index is searched
    */
   unsigned get_gre_idx(mc_block_s &a_value);

   /*!
    * \brief __GEN search for index of node with less or equal value
    * \param a_value - value which index is searched
    */
   unsigned get_lee_idx(mc_block_s &a_value);

   /*!
    * \brief __GEN search for all indexes of node
    * \param a_value - value of searched index
    */
   void get_idxs(mc_block_s &a_value,ui_array_s &a_idxs_array);

   /*!
    * \brief __GEN copy rb_tree from another rb_tree
    * \param a_src - reference to another rb_tree
    * \return reference to this rb_tree
    */
   inline mc_block_rb_tree_s &operator=(mc_block_rb_tree_s &a_src);

   /*!
    * \brief __GEN compare rb_tree with another rb_tree
    * \param a_second - reference to another rb_tree
    * \return result of comparision
    */
   bool operator==(mc_block_rb_tree_s &a_second);

   /*!
    * \brief __GEN rehash tree (after invalidation by change of object value)
    */
    void rehash_tree();

   
      
      /*!
       * \brief cmalloc for mc_block_rb_tree_s structure overriding global
       *
       */
      inline void *cmalloc(unsigned a_size);

      /*!
       * \brief cfree for mc_block_rb_tree_s structure overriding global
       */
      inline void cfree(void *a_location);
   
};



// -- mc_struct_s --
// structure mc_struct_s definition

/*!
 * \brief __GEN structure
 */
struct mc_struct_s
{
   mutex_s mutex; //!< member - 0
   mc_block_rb_tree_s mc_block_set; //!< member - 1
   unsigned alloc_size; //!< member - 2
   unsigned max_alloc_size; //!< member - 3
   unsigned act_alloc_size; //!< member - 4

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
   inline void set(mutex_s &a_mutex,mc_block_rb_tree_s &a_mc_block_set,unsigned a_alloc_size,unsigned a_max_alloc_size,unsigned a_act_alloc_size);
   /*!
    * \brief __GEN flush structure memory usage, recursive on members
    */
   inline void flush_all();

   /*!
    * \brief __GEN swap structure members with another structure
    */
   inline void swap(mc_struct_s &a_second);

   /*!
    * \brief __GEN copy structure from another structure
    * \param a_src - reference to another structure
    * \return reference to this structure
    */
   inline mc_struct_s &operator=(mc_struct_s &a_src);

   /*!
    * \brief __GEN compare structure with another structure
    * \param a_second - reference to another structure
    * \return result of comparison
    */
   inline bool operator==(mc_struct_s &a_second);

   
      
      /*!
       * \brief return location of new allocated memory block of size a_size
       */
      inline void *get_block(unsigned a_size);

      /*!
       * \brief release block of memory by its location
       */
      inline void release_block(void *a_location);

      /*!
       * \brief check if all blocks of memory was released
       */
      void check();
   
};



#endif

/*
 * inline methods of generated structures
 */

// -- ui_array_s --
// --- struct ui_array_s inline method definition ---

inline void ui_array_s::init()
{/*{{{*/
   size = 0;
   used = 0;
   data = NULL;
}/*}}}*/

inline void ui_array_s::init_size(unsigned a_size)
{/*{{{*/
   init();
   copy_resize(a_size);
}/*}}}*/

inline void ui_array_s::clear()
{/*{{{*/
   if (data != NULL) {
      cfree(data);
   }

   init();
}/*}}}*/

inline void ui_array_s::set(unsigned a_used,unsigned *a_data)
{/*{{{*/
   clear();
   if (a_used == 0) return;
   
   debug_assert(a_data != NULL);
   copy_resize(a_used);

   memcpy(data,a_data,a_used*sizeof(unsigned));
   used = a_used;
}/*}}}*/

inline void ui_array_s::flush()
{/*{{{*/
   copy_resize(used);
}/*}}}*/

inline void ui_array_s::flush_all()
{/*{{{*/
   copy_resize(used);
}/*}}}*/

inline void ui_array_s::swap(ui_array_s &a_second)
{/*{{{*/
   unsigned tmp_unsigned = size;
   size = a_second.size;
   a_second.size = tmp_unsigned;

   tmp_unsigned = used;
   used = a_second.used;
   a_second.used = tmp_unsigned;

   unsigned *tmp_data = data;
   data = a_second.data;
   a_second.data = tmp_data;
}/*}}}*/

inline unsigned &ui_array_s::operator[](unsigned a_idx)
{/*{{{*/
   debug_assert(a_idx < used);
   return data[a_idx];
}/*}}}*/

inline void ui_array_s::push(unsigned a_value)
{/*{{{*/
   if (used >= size) {
      copy_resize((size << 1) + c_array_add);
   }

   data[used++] = a_value;
}/*}}}*/

inline void ui_array_s::push_blank()
{/*{{{*/
   if (used >= size) {
      copy_resize((size << 1) + c_array_add);
   }

   used++;
}/*}}}*/

inline void ui_array_s::push_clear()
{/*{{{*/
   if (used >= size) {
      copy_resize((size << 1) + c_array_add);
   }

   used++;
}/*}}}*/

inline unsigned &ui_array_s::pop()
{/*{{{*/
   debug_assert(used > 0);
   return data[--used];
}/*}}}*/

inline unsigned &ui_array_s::last()
{/*{{{*/
   debug_assert(used > 0);
   return data[used - 1];
}/*}}}*/

inline ui_array_s &ui_array_s::operator=(ui_array_s &a_src)
{/*{{{*/
   clear();

   if (a_src.used == 0) return *this;

   copy_resize(a_src.used);
   memcpy(data,a_src.data,a_src.used*sizeof(unsigned));

   used = a_src.used;
   return *this;
}/*}}}*/

inline bool ui_array_s::operator==(ui_array_s &a_second)
{/*{{{*/
   if (used != a_second.used) return false;
   if (used == 0) return true;

   return (memcmp(data,a_second.data,used*sizeof(unsigned)) == 0);
}/*}}}*/



#if MEM_CHECK == ENABLE

// -- mc_block_s --
// --- struct mc_block_s inline method definition ---

inline void mc_block_s::init()
{/*{{{*/
}/*}}}*/

inline void mc_block_s::clear()
{/*{{{*/

   init();
}/*}}}*/

inline void mc_block_s::set(pointer a_location,unsigned a_size)
{/*{{{*/
   location = a_location;
   size = a_size;
}/*}}}*/

inline void mc_block_s::flush_all()
{/*{{{*/
}/*}}}*/

inline void mc_block_s::swap(mc_block_s &a_second)
{/*{{{*/
   pointer tmp_location = location;
   location = a_second.location;
   a_second.location = tmp_location;

   unsigned tmp_size = size;
   size = a_second.size;
   a_second.size = tmp_size;
}/*}}}*/

inline mc_block_s &mc_block_s::operator=(mc_block_s &a_src)
{/*{{{*/
   location = a_src.location;
   size = a_src.size;

   return *this;
}/*}}}*/

inline bool mc_block_s::operator==(mc_block_s &a_second)
{/*{{{*/
   return (location == a_second.location && size == a_second.size);
}/*}}}*/



// -- mc_block_rb_tree_s --
// --- struct mc_block_rb_tree_s inline method definition ---

inline unsigned mc_block_rb_tree_s::__get_grandparent_idx(unsigned a_idx)
{/*{{{*/
   mc_block_rb_tree_s_node &node = data[a_idx];

   if (node.parent_idx != c_idx_not_exist) {
      return data[node.parent_idx].parent_idx;
   }
   else {
      return c_idx_not_exist;
   }
}/*}}}*/

inline unsigned mc_block_rb_tree_s::__get_uncle_idx(unsigned a_idx)
{/*{{{*/
   unsigned gp_idx = __get_grandparent_idx(a_idx);

   if (gp_idx == c_idx_not_exist) {
      return c_idx_not_exist;
   }
   else {
      mc_block_rb_tree_s_node &gp = data[gp_idx];
      return gp.left_idx == data[a_idx].parent_idx?gp.right_idx:gp.left_idx;
   }
}/*}}}*/

inline unsigned mc_block_rb_tree_s::__get_sibling_idx(unsigned a_idx)
{/*{{{*/
   mc_block_rb_tree_s_node &p = data[data[a_idx].parent_idx];
   return p.left_idx == a_idx?p.right_idx:p.left_idx;
}/*}}}*/

inline unsigned mc_block_rb_tree_s::get_descent_stack_size()
{/*{{{*/
   return (unsigned)(logf(used)/c_log_of_2) << 1;
}/*}}}*/

inline unsigned mc_block_rb_tree_s::get_stack_next_idx(unsigned a_idx,unsigned **a_s_ptr,unsigned *a_stack_base)
{/*{{{*/
   debug_assert(a_idx < used && data[a_idx].valid);

   mc_block_rb_tree_s_node &node = data[a_idx];

   if (node.right_idx != leaf_idx) {
      return get_stack_min_value_idx(node.right_idx,a_s_ptr);
   }

   if (*a_s_ptr > a_stack_base) {
      return *(--(*a_s_ptr));
   }
   
   return c_idx_not_exist;
}/*}}}*/

inline void mc_block_rb_tree_s::__rotate_left(unsigned a_idx)
{/*{{{*/
   mc_block_rb_tree_s_node &root = data[a_idx];
   mc_block_rb_tree_s_node &pivot = data[root.right_idx];

   if (a_idx == root_idx) {
      root_idx = root.right_idx;
      pivot.parent_idx = c_idx_not_exist;
   }
   else {
      mc_block_rb_tree_s_node &rp = data[root.parent_idx];
      (rp.right_idx == a_idx?rp.right_idx:rp.left_idx) = root.right_idx;

      pivot.parent_idx = root.parent_idx;
   }

   root.parent_idx = root.right_idx;

   root.right_idx = pivot.left_idx;
   data[root.right_idx].parent_idx = a_idx;

   pivot.left_idx = a_idx;
}/*}}}*/

inline void mc_block_rb_tree_s::__rotate_right(unsigned a_idx)
{/*{{{*/
   mc_block_rb_tree_s_node &root = data[a_idx];
   mc_block_rb_tree_s_node &pivot = data[root.left_idx];

   if (a_idx == root_idx) {
      root_idx = root.left_idx;
      pivot.parent_idx = c_idx_not_exist;
   }
   else {
      mc_block_rb_tree_s_node &rp = data[root.parent_idx];
      (rp.right_idx == a_idx?rp.right_idx:rp.left_idx) = root.left_idx;

      pivot.parent_idx = root.parent_idx;
   }

   root.parent_idx = root.left_idx;

   root.left_idx = pivot.right_idx;
   data[root.left_idx].parent_idx = a_idx;

   pivot.right_idx = a_idx;
}/*}}}*/

inline unsigned mc_block_rb_tree_s::__get_new_index()
{/*{{{*/
   unsigned new_idx;

   if (free_idx != c_idx_not_exist) {
      new_idx = free_idx;
      free_idx = data[new_idx].parent_idx;
   }
   else {
      if (used >= size) {
         copy_resize((size << 1) + c_array_add);
      }

      new_idx = used++;
   }

   data[new_idx].valid = true;
   count++;

   return new_idx;
}/*}}}*/

inline void mc_block_rb_tree_s::__replace_delete_node_by_child(unsigned a_idx,unsigned a_ch_idx)
{/*{{{*/
   mc_block_rb_tree_s_node &node = data[a_idx];

   if (node.parent_idx != c_idx_not_exist) {
      mc_block_rb_tree_s_node &parent = data[node.parent_idx];
      (parent.left_idx == a_idx?parent.left_idx:parent.right_idx) = a_ch_idx;

      data[a_ch_idx].parent_idx = node.parent_idx;
   }
   else {
      root_idx = a_ch_idx == leaf_idx?c_idx_not_exist:a_ch_idx;
      data[a_ch_idx].parent_idx = c_idx_not_exist;
   }
}/*}}}*/

inline void mc_block_rb_tree_s::__remove_one_child(unsigned a_idx,unsigned a_ch_idx)
{/*{{{*/
   mc_block_rb_tree_s_node &node = data[a_idx];
   __replace_delete_node_by_child(a_idx,a_ch_idx);

   node.parent_idx = free_idx;
   free_idx = a_idx;

   node.valid = false;
   count--;

   if (node.color) {
      mc_block_rb_tree_s_node &child_node = data[a_ch_idx];

      if (!child_node.color) {
         child_node.color = true;
      }
      else {
         __remove_black_black(a_ch_idx);
      }
   }
}/*}}}*/

inline void mc_block_rb_tree_s::init()
{/*{{{*/
   size = 0;
   used = 0;
   count = 0;
   data = NULL;
   free_idx = c_idx_not_exist;
   root_idx = c_idx_not_exist;
   leaf_idx = c_idx_not_exist;
}/*}}}*/

inline void mc_block_rb_tree_s::clear()
{/*{{{*/
   if (data != NULL) {
      cfree(data);
   }

   init();
}/*}}}*/

inline void mc_block_rb_tree_s::flush()
{/*{{{*/
   copy_resize(used);
}/*}}}*/

inline void mc_block_rb_tree_s::flush_all()
{/*{{{*/
   copy_resize(used);
}/*}}}*/

inline void mc_block_rb_tree_s::swap(mc_block_rb_tree_s &a_second)
{/*{{{*/
   unsigned tmp_unsigned = size;
   size = a_second.size;
   a_second.size = tmp_unsigned;

   tmp_unsigned = used;
   used = a_second.used;
   a_second.used = tmp_unsigned;

   tmp_unsigned = count;
   count = a_second.count;
   a_second.count = tmp_unsigned;

   mc_block_rb_tree_s_node *tmp_data = data;
   data = a_second.data;
   a_second.data = tmp_data;

   tmp_unsigned = free_idx;
   free_idx = a_second.free_idx;
   a_second.free_idx = tmp_unsigned;

   tmp_unsigned = root_idx;
   root_idx = a_second.root_idx;
   a_second.root_idx = tmp_unsigned;

   tmp_unsigned = leaf_idx;
   leaf_idx = a_second.leaf_idx;
   a_second.leaf_idx = tmp_unsigned;
}/*}}}*/

inline mc_block_s &mc_block_rb_tree_s::operator[](unsigned a_idx)
{/*{{{*/
   debug_assert(a_idx < used && data[a_idx].valid);
   return data[a_idx].object;
}/*}}}*/

inline unsigned mc_block_rb_tree_s::insert(mc_block_s &a_value)
{/*{{{*/
   unsigned new_node_idx = __get_new_index();

   __binary_tree_insert(new_node_idx,a_value,false);
   __insert_operation(new_node_idx);

   data[new_node_idx].object = a_value;

   return new_node_idx;
}/*}}}*/

inline unsigned mc_block_rb_tree_s::swap_insert(mc_block_s &a_value)
{/*{{{*/
   unsigned new_node_idx = __get_new_index();

   __binary_tree_insert(new_node_idx,a_value,false);
   __insert_operation(new_node_idx);

   data[new_node_idx].object.swap(a_value);

   return new_node_idx;
}/*}}}*/

inline mc_block_rb_tree_s &mc_block_rb_tree_s::operator=(mc_block_rb_tree_s &a_src)
{/*{{{*/
   clear();

   if (a_src.root_idx == c_idx_not_exist) return *this;

   copy_resize(a_src.used);
   memcpy(data,a_src.data,a_src.used*sizeof(mc_block_rb_tree_s_node));

   used = a_src.used;
   count = a_src.count;
   free_idx = a_src.free_idx;
   root_idx = a_src.root_idx;
   leaf_idx = a_src.leaf_idx;

   return *this;
}/*}}}*/



inline void *mc_block_rb_tree_s::cmalloc(unsigned a_size)
{/*{{{*/
   return malloc(a_size);
}/*}}}*/

inline void mc_block_rb_tree_s::cfree(void *a_location)
{/*{{{*/
   free(a_location);
}/*}}}*/

int mc_block_rb_tree_s::__compare_value(mc_block_s &a_first,mc_block_s &a_second)
{/*{{{*/
  pointer &fl = a_first.location;
  pointer &sl = a_second.location;

  return fl < sl ? -1 : fl > sl ? 1 : 0;
}/*}}}*/

// -- mc_struct_s --
// --- struct mc_struct_s inline method definition ---

inline void mc_struct_s::init()
{/*{{{*/
   mutex.init();
   mc_block_set.init();
}/*}}}*/

inline void mc_struct_s::clear()
{/*{{{*/
   mutex.clear();
   mc_block_set.clear();

   init();
}/*}}}*/

inline void mc_struct_s::set(mutex_s &a_mutex,mc_block_rb_tree_s &a_mc_block_set,unsigned a_alloc_size,unsigned a_max_alloc_size,unsigned a_act_alloc_size)
{/*{{{*/
   mutex = a_mutex;
   mc_block_set = a_mc_block_set;
   alloc_size = a_alloc_size;
   max_alloc_size = a_max_alloc_size;
   act_alloc_size = a_act_alloc_size;
}/*}}}*/

inline void mc_struct_s::flush_all()
{/*{{{*/
   mc_block_set.flush_all();
}/*}}}*/

inline void mc_struct_s::swap(mc_struct_s &a_second)
{/*{{{*/
   mutex.swap(a_second.mutex);

   mc_block_set.swap(a_second.mc_block_set);

   unsigned tmp_alloc_size = alloc_size;
   alloc_size = a_second.alloc_size;
   a_second.alloc_size = tmp_alloc_size;

   unsigned tmp_max_alloc_size = max_alloc_size;
   max_alloc_size = a_second.max_alloc_size;
   a_second.max_alloc_size = tmp_max_alloc_size;

   unsigned tmp_act_alloc_size = act_alloc_size;
   act_alloc_size = a_second.act_alloc_size;
   a_second.act_alloc_size = tmp_act_alloc_size;
}/*}}}*/

inline mc_struct_s &mc_struct_s::operator=(mc_struct_s &a_src)
{/*{{{*/
   mutex = a_src.mutex;
   mc_block_set = a_src.mc_block_set;
   alloc_size = a_src.alloc_size;
   max_alloc_size = a_src.max_alloc_size;
   act_alloc_size = a_src.act_alloc_size;

   return *this;
}/*}}}*/

inline bool mc_struct_s::operator==(mc_struct_s &a_second)
{/*{{{*/
   return (mutex == a_second.mutex && mc_block_set == a_second.mc_block_set && alloc_size == a_second.alloc_size && max_alloc_size == a_second.max_alloc_size && act_alloc_size == a_second.act_alloc_size);
}/*}}}*/



inline void *mc_struct_s::get_block(unsigned a_size)
{/*{{{*/
   mutex.lock();

   void *location = malloc(a_size);

   mc_block_s mc_block = {location,a_size};
   mc_block_set.insert(mc_block);

   // - increase size of allocated memory -
   alloc_size += a_size;
   act_alloc_size += a_size;
   if (act_alloc_size > max_alloc_size) {
      max_alloc_size = act_alloc_size;
   }

   mutex.unlock();

   return location;
}/*}}}*/

inline void mc_struct_s::release_block(void *a_location)
{/*{{{*/
   mutex.lock();

   mc_block_s mc_block = {a_location,0};
   unsigned idx = mc_block_set.get_idx(mc_block);
   cassert(idx != c_idx_not_exist);

   // - decrease size of allocated memory -
   act_alloc_size -= mc_block_set[idx].size;

   mc_block_set.remove(idx);
   free(a_location);

   mutex.unlock();
}/*}}}*/

extern mc_struct_s mc_struct;

/*
 * mem_check global functions
 */
inline void mc_init()
{
   mc_struct.init();
   mc_struct.alloc_size = 0;
   mc_struct.max_alloc_size = 0;
   mc_struct.act_alloc_size = 0;
}

inline void mc_clear()
{
   mc_struct.check();
   mc_struct.clear();
}

inline void *cmalloc(unsigned a_size)
{/*{{{*/
   return mc_struct.get_block(a_size);
}/*}}}*/

inline void cfree(void *a_location)
{/*{{{*/
   mc_struct.release_block(a_location);
}/*}}}*/
#else
inline void mc_init() {}
inline void mc_clear() {}

inline void *cmalloc(unsigned a_size)
{/*{{{*/
   return malloc(a_size);
}/*}}}*/

inline void cfree(void *a_location)
{/*{{{*/
   free(a_location);
}/*}}}*/
#endif

#endif


#ifndef __UCL_STRING_H
#define __UCL_STRING_H



/*
 * constants and definitions
 */

// - string terminating character -
extern const char c_string_terminating_char;

// - tabulator size -
const unsigned c_tabulator_size = 8;

/*
 * definition of structure string_s
 */



struct string_s
{
  unsigned size;
  char *data;

  /*!
   * \brief initialization of string variables
   */
  inline void init();

  /*!
   * \brief release of string variables
   */
  inline void clear();

  /*!
   * \brief create new string
   * \param a_length - length of new string
   */
  inline void create(unsigned a_length);

  /*!
   * \brief set string to given data
   * \param a_length - length of new string
   * \param a_data - pointer to data of new string
   */
  inline void set(unsigned a_length,const char *a_data);

  /*!
   * \brief create new string by concatenation of two strings described by length and pointer
   * \param a_flength - length of first string
   * \param a_fdata - pointer to data of first string
   * \param a_slength - length of second string
   * \param a_sdata - pointer to data of second string
   */
  inline void conc_set(unsigned a_flength,const char *a_fdata,unsigned a_slength,const char *a_sdata);

  /*!
   * \brief flush all variables of string
   */
  inline void flush_all() {}

  /*!
   * \brief swap string variables with another string
   * \param a_second - reference to another string
   */
  inline void swap(string_s &a_second);

  /*!
   * \brief select one character from string
   * \param a_idx - index of selected character
   * \return reference to character
   */
  inline char &operator[](unsigned a_idx);

  /*!
   * \brief set string to value of another string
   * \param a_src - reference to another string
   * \return reference to this string
   */
  inline string_s &operator=(string_s &a_src);

  /*!
   * \brief compare value with another string
   * \param a_second - reference to another string
   * \return result of comparison
   */
  inline bool operator==(string_s &a_second);

  /*!
   * \brief compare string with string described by its length and its data
   * \param a_length - length of second string
   * \param a_data - data of second string
   * \return result of comparison
   */
  inline bool compare_char_ptr(unsigned a_length,const char *a_data);

  /*!
   * \brief multiply character string a_mult times
   *
   * \param a_length - length of string to be multiplied
   * \param a_data - pointer to string data
   * \param a_mult - multiplier of string
   */
  void mult_char_ptr(unsigned a_length,const char *a_data,unsigned a_mult);

  /*!
   * \brief convert utf8 string to utf32 unsigned int string
   * \param a_src - pointer to source utf8 characters
   * \param a_trg - pointer to target utf32 unsigned integers
   * \param a_size - count of characters to be converted
   * \return count of converted integers
   */
  static int utf8_to_utf32(char *a_src,unsigned *a_trg,unsigned a_size);

  /*!
   * \brief convert utf32 unsigned int string to utf8 string
   * \param a_src - pointer to source utf32 unsigned integers
   * \param a_trg - pointer to target utf8 characters
   * \param a_size - count of integers to be converted
   * \return count of converted characters
   */
  static unsigned utf32_to_utf8(unsigned *a_src,char *a_trg,unsigned a_size);

  /*!
   * \brief print string to standard output
   * \return count of writed characters
   */
  inline unsigned print();

  /*!
   * \brief load string from given stream
   * \param a_stream - stream from which is string loaded
   */
  bool read_line_from_stream(FILE *a_stream);

  /*!
   * \brief load string from text file
   * \param a_file - name of file containing string text
   * \return true if string is successfully loaded
   */
  inline bool load_text_file(const char *a_file);

  /*!
   * \brief save string to text file
   * \param a_file - name of target file
   * \return true if string is successfully saved
   */
  inline bool save_text_file(const char *a_file);

  /*!
   * \brief create string of desired format
   * \param a_format - format as in printf functions family
   * \param ... - list of parameters desired in format
   */
  void setf(const char *a_format,...);

  /*!
   * \brief conctenate string of desired format
   * \param a_format - format as in printf functions family
   * \param ... - list of parameters demanded in format
   */
  void concf(const char *a_format,...);

  /*!
   * \brief find position of given string in string from given index
   * \param a_idx - position from which is substring searched
   * \param a_length - length of searched string
   * \param a_data - data of searched string
   */
  unsigned get_idx(unsigned a_idx,unsigned a_length,const char *a_data);

  /*!
   * \brief return print size between two character indexes in string
   * \param f_idx - index of first character
   * \param s_idx - index of second character
   * \return print size
   */
  unsigned get_print_size_between(unsigned f_idx,unsigned s_idx);

  /*!
   * \brief return number of line of character index
   * \param c_idx - character index
   * \return line number
   */
  unsigned get_character_line(unsigned c_idx);

  /*!
   * \brief return index of character at beginning of line on which is located given character
   * \param c_idx - index of given character
   * \return index of begin of line
   */
  unsigned get_character_line_begin(unsigned c_idx);

  /*!
   * \brief return index of character at end of line on which is located given character
   * \param c_idx - index of given character
   * \return index of end of line
   */
  unsigned get_character_line_end(unsigned c_idx);
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

inline void string_s::conc_set(unsigned a_flength,const char *a_fdata,unsigned a_slength,const char *a_sdata)
{/*{{{*/
  clear();
  data = (char *)cmalloc((a_flength + a_slength + 1)*sizeof(char));

  if (a_flength != 0)
  {
    memcpy(data,a_fdata,a_flength*sizeof(char));
  }

  if (a_slength != 0)
  {
    memcpy(data + a_flength,a_sdata,a_slength*sizeof(char));
  }

  data[a_flength + a_slength] = '\0';
  size = a_flength + a_slength + 1;
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

inline char &string_s::operator[](unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < size - 1);
  return data[a_idx];
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

inline bool string_s::compare_char_ptr(unsigned a_length,const char *a_data)
{/*{{{*/
  if (size != a_length + 1) return false;
  if (a_length == 0) return true;
  return (memcmp(data,a_data,a_length*sizeof(char)) == 0);
}/*}}}*/

inline unsigned string_s::print()
{/*{{{*/
  return fwrite(data,size - 1,1,stdout);
}/*}}}*/

inline bool string_s::load_text_file(const char *a_file)
{/*{{{*/
  if (a_file == NULL) return false;
  FILE *f = fopen(a_file,"r");
  if (f == NULL) return false;

  fseek(f,0,SEEK_END);
  unsigned file_size = ftell(f);
  fseek(f,0,SEEK_SET);

  clear();
  data = (char *)cmalloc((file_size + 1)*sizeof(char));
  if (fread(data,file_size,1,f) != 1)
  {
    fclose(f);
    return false;
  }
  fclose(f);

  data[file_size] = '\0';
  size = file_size + 1;

  return true;
}/*}}}*/

inline bool string_s::save_text_file(const char *a_file)
{/*{{{*/
  if (a_file == NULL) return false;
  FILE *f = fopen(a_file,"w");
  if (f == NULL) return false;

  if (size > 1)
  {
    if (fwrite(data,size - 1,1,f) != 1)
    {
      fclose(f);
      return false;
    }
  }

  fclose(f);
  return true;
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
   data = NULL;
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



#endif


#ifndef __PROCESSOR_H
#define __PROCESSOR_H



/*
 * definition of basic functions and constants
 */

#define STRUCT_NAME abbs[0].data
#define IM_STRUCT_NAME abbreviations[abb_idx].name.data
#define TYPE_CNT type_cnt
#define TYPE_NAME abbreviations[type_abb_idx].name.data
#define TYPE_NUMBER type.properties
#define TYPE_NAMES(IDX) (type_names[IDX].data)
#define IM_TYPE_NAMES(IDX) (data_type.types[IDX].data)
#define TYPE_NUMBERS(IDX) (types[IDX]->properties)
#define VAR_NAMES_CNT (data_type.variables.used)
#define VAR_NAMES(IDX) (data_type.variables[IDX].data)

// - constants describing begin and end of definition block -
extern const char *c_begin_str;
extern const char *c_end_str;

const unsigned c_end_str_len = strlen(c_end_str);

// - data type settings -
enum {
   c_type_basic = 0x00000001,
   c_type_static = 0x00000002,
   c_type_dynamic = 0x00000004,
};

const unsigned c_type_byte_neg_mod_mask = 0xf8;
const unsigned c_type_flushable = 0x00000010;
const unsigned c_type_setting_mask = 0xffffff00;

enum {
   c_type_setting_not_generate_init = 0x00000100,
   c_type_setting_not_generate_clear = 0x00000200,
   c_type_setting_not_generate_swap = 0x00000400,
   c_type_setting_not_generate_operator_equal = 0x00000800,

   c_type_setting_strict_dynamic = 0x00001000,
};


// - names of basic data types -
enum {
   c_bt_bool = 0,
   c_bt_char,
   c_bt_unsigned_char,
   c_bt_short,
   c_bt_unsigned_short,
   c_bt_int,
   c_bt_unsigned,
   c_bt_long,
   c_bt_unsigned_long,
   c_bt_long_long,
   c_bt_unsigned_long_long,
   c_bt_float,
   c_bt_double,
   c_bt_long_double,
};

const unsigned c_basic_type_cnt = 15;
extern const char *c_basic_types[c_basic_type_cnt];

extern unsigned c_basic_type_types[c_basic_type_cnt];

// - abbreviations of basic data types -
const unsigned c_basic_abbreviation_cnt = 37;
extern const char *c_basic_abbreviations[c_basic_abbreviation_cnt];

extern const int c_basic_abbreviation_types[c_basic_abbreviation_cnt];

// - constant describing containers -
const unsigned c_cont_cnt = 7;

enum {
   c_cont_array = 0,
   c_cont_queue,
   c_cont_list,
   c_cont_struct,
   c_cont_rb_tree,
   c_cont_safe_list,
   c_cont_safe_rb_tree,
};

extern const char *c_cont_names[c_cont_cnt];
extern const char *c_cont_postfixes[c_cont_cnt];

/*
 * definitions of generated structures
 */

// -- data_type_s --
// structure data_type_s definition

/*!
 * \brief __GEN structure
 */
struct data_type_s
{
   unsigned cont_idx; //!< member - 0
   string_s name; //!< member - 1
   string_s real_name; //!< member - 2
   unsigned properties; //!< member - 3
   string_array_s types; //!< member - 4
   string_array_s variables; //!< member - 5

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
   inline void set(unsigned a_cont_idx,string_s &a_name,string_s &a_real_name,unsigned a_properties,string_array_s &a_types,string_array_s &a_variables);
   /*!
    * \brief __GEN flush structure memory usage, recursive on members
    */
   inline void flush_all();

   /*!
    * \brief __GEN swap structure members with another structure
    */
   inline void swap(data_type_s &a_second);

   /*!
    * \brief __GEN copy structure from another structure
    * \param a_src - reference to another structure
    * \return reference to this structure
    */
   inline data_type_s &operator=(data_type_s &a_src);

   /*!
    * \brief __GEN compare structure with another structure
    * \param a_second - reference to another structure
    * \return result of comparison
    */
   inline bool operator==(data_type_s &a_second);

};



// -- data_type_array_s --
// --- struct data_type_array_s definition --- 

/*!
 * \brief __GEN array of type data_type_s
 */
struct data_type_array_s
{
   unsigned size; //!< actual size of allocated space in array
   unsigned used; //!< count of used space in array
   data_type_s *data; //!< pointer to array elements

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
   void set(unsigned a_used,data_type_s *a_data);

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
   inline void swap(data_type_array_s &a_second);

   /*!
    * \brief __GEN select element of array
    * \param a_idx - index of element in array
    * \return reference to element of array
    */
   inline data_type_s &operator[](unsigned a_idx);

   /*!
    * \brief __GEN insert element to end of array
    * \param a_value - reference to inserted value
    */
   inline void push(data_type_s &a_value);

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
   inline data_type_s &pop();

   /*!
    * \brief __GEN return value of last element in array
    * \return reference to last element
    */
   inline data_type_s &last();

   /*!
    * \brief __GEN change array capacity
    * \param a_size - requested array capacity
    */
   void copy_resize(unsigned a_size);

   /*!
    * \brief __GEN set all elements of array to given value
    * \param a_value - new value of all elements
    */
   void fill(data_type_s &a_value);

   /*!
    * \brief __GEN search for index of element
    * \param a_value - value which index is searched
    */
   unsigned get_idx(data_type_s &a_value);

   /*!
    * \brief __GEN copy array from another array
    * \param a_src - reference to another array
    */
   data_type_array_s &operator=(data_type_array_s &a_src);

   /*!
    * \brief __GEN comparison of array with another array
    * \param a_second - reference to another array
    */
   bool operator==(data_type_array_s &a_second);

   

   unsigned get_idx_by_real_name(unsigned n_length,char *n_data);

   
};



// -- abbreviation_s --
// structure abbreviation_s definition

/*!
 * \brief __GEN structure
 */
struct abbreviation_s
{
   string_s name; //!< member - 0
   unsigned data_type_idx; //!< member - 1

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
   inline void set(string_s &a_name,unsigned a_data_type_idx);
   /*!
    * \brief __GEN flush structure memory usage, recursive on members
    */
   inline void flush_all();

   /*!
    * \brief __GEN swap structure members with another structure
    */
   inline void swap(abbreviation_s &a_second);

   /*!
    * \brief __GEN copy structure from another structure
    * \param a_src - reference to another structure
    * \return reference to this structure
    */
   inline abbreviation_s &operator=(abbreviation_s &a_src);

   /*!
    * \brief __GEN compare structure with another structure
    * \param a_second - reference to another structure
    * \return result of comparison
    */
   inline bool operator==(abbreviation_s &a_second);

};



// -- abbreviation_array_s --
// --- struct abbreviation_array_s definition --- 

/*!
 * \brief __GEN array of type abbreviation_s
 */
struct abbreviation_array_s
{
   unsigned size; //!< actual size of allocated space in array
   unsigned used; //!< count of used space in array
   abbreviation_s *data; //!< pointer to array elements

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
   void set(unsigned a_used,abbreviation_s *a_data);

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
   inline void swap(abbreviation_array_s &a_second);

   /*!
    * \brief __GEN select element of array
    * \param a_idx - index of element in array
    * \return reference to element of array
    */
   inline abbreviation_s &operator[](unsigned a_idx);

   /*!
    * \brief __GEN insert element to end of array
    * \param a_value - reference to inserted value
    */
   inline void push(abbreviation_s &a_value);

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
   inline abbreviation_s &pop();

   /*!
    * \brief __GEN return value of last element in array
    * \return reference to last element
    */
   inline abbreviation_s &last();

   /*!
    * \brief __GEN change array capacity
    * \param a_size - requested array capacity
    */
   void copy_resize(unsigned a_size);

   /*!
    * \brief __GEN set all elements of array to given value
    * \param a_value - new value of all elements
    */
   void fill(abbreviation_s &a_value);

   /*!
    * \brief __GEN search for index of element
    * \param a_value - value which index is searched
    */
   unsigned get_idx(abbreviation_s &a_value);

   /*!
    * \brief __GEN copy array from another array
    * \param a_src - reference to another array
    */
   abbreviation_array_s &operator=(abbreviation_array_s &a_src);

   /*!
    * \brief __GEN comparison of array with another array
    * \param a_second - reference to another array
    */
   bool operator==(abbreviation_array_s &a_second);

   

   unsigned get_idx_by_name(unsigned a_length,const char *a_data);

   
};



// -- container_parameters_s --
// structure container_parameters_s definition

/*!
 * \brief __GEN structure
 */
struct container_parameters_s
{
   string_array_s types; //!< member - 0
   string_array_s variables; //!< member - 1
   string_array_s compare; //!< member - 2
   string_array_s functions; //!< member - 3
   string_array_s names; //!< member - 4

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
   inline void set(string_array_s &a_types,string_array_s &a_variables,string_array_s &a_compare,string_array_s &a_functions,string_array_s &a_names);
   /*!
    * \brief __GEN flush structure memory usage, recursive on members
    */
   inline void flush_all();

   /*!
    * \brief __GEN swap structure members with another structure
    */
   inline void swap(container_parameters_s &a_second);

   /*!
    * \brief __GEN copy structure from another structure
    * \param a_src - reference to another structure
    * \return reference to this structure
    */
   inline container_parameters_s &operator=(container_parameters_s &a_src);

   /*!
    * \brief __GEN compare structure with another structure
    * \param a_second - reference to another structure
    * \return result of comparison
    */
   inline bool operator==(container_parameters_s &a_second);

   
      inline void clean_out();
   
};



// -- processor_s --
// structure processor_s definition

/*!
 * \brief __GEN structure
 */
struct processor_s
{
   FILE_ptr out_file; //!< member - 0
   string_array_s include_dirs; //!< member - 1
   string_array_s include_names; //!< member - 2
   data_type_array_s data_types; //!< member - 3
   abbreviation_array_s abbreviations; //!< member - 4
   unsigned type_settings; //!< member - 5
   container_parameters_s cont_params; //!< member - 6

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
   inline void set(FILE_ptr a_out_file,string_array_s &a_include_dirs,string_array_s &a_include_names,data_type_array_s &a_data_types,abbreviation_array_s &a_abbreviations,unsigned a_type_settings,container_parameters_s &a_cont_params);
   /*!
    * \brief __GEN flush structure memory usage, recursive on members
    */
   inline void flush_all();

   /*!
    * \brief __GEN swap structure members with another structure
    */
   inline void swap(processor_s &a_second);

   /*!
    * \brief __GEN copy structure from another structure
    * \param a_src - reference to another structure
    * \return reference to this structure
    */
   inline processor_s &operator=(processor_s &a_src);

   /*!
    * \brief __GEN compare structure with another structure
    * \param a_second - reference to another structure
    * \return result of comparison
    */
   inline bool operator==(processor_s &a_second);

   

   void generate_array_type();
   void generate_array_inlines(unsigned abb_idx,unsigned a_dt_idx);
   void generate_array_methods(unsigned abb_idx,unsigned a_dt_idx);
   void generate_queue_type();
   void generate_queue_inlines(unsigned abb_idx,unsigned a_dt_idx);
   void generate_queue_methods(unsigned abb_idx,unsigned a_dt_idx);
   void generate_list_type();
   void generate_list_inlines(unsigned abb_idx,unsigned a_dt_idx);
   void generate_list_methods(unsigned abb_idx,unsigned a_dt_idx);
   void generate_struct_type();
   void generate_struct_inlines(unsigned abb_idx,unsigned a_dt_idx);
   void generate_struct_methods(unsigned abb_idx,unsigned a_dt_idx);
   void generate_rb_tree_type();
   void generate_rb_tree_inlines(unsigned abb_idx,unsigned a_dt_idx);
   void generate_rb_tree_methods(unsigned abb_idx,unsigned a_dt_idx);
   void generate_safe_list_type();
   void generate_safe_list_inlines(unsigned abb_idx,unsigned a_dt_idx);
   void generate_safe_list_methods(unsigned abb_idx,unsigned a_dt_idx);
   void generate_safe_rb_tree_type();
   void generate_safe_rb_tree_inlines(unsigned abb_idx,unsigned a_dt_idx);
   void generate_safe_rb_tree_methods(unsigned abb_idx,unsigned a_dt_idx);

   void generate_type_inlines(unsigned a_length,char *a_data);
   void generate_type_methods(unsigned a_length,char *a_data);
   void generate_container_def(string_s &a_cont_name);

   bool find_include_file(const char *a_file, string_s &a_file_path);

   void initialize_data_types();
   bool run(const char *a_file_name, string_array_s &a_include_dirs, 
            FILE *a_file);

   
};



// - processor_s_ptr definition -
typedef processor_s * processor_s_ptr;


/*
 * inline methods of generated structures
 */

// -- data_type_s --
// --- struct data_type_s inline method definition ---

inline void data_type_s::init()
{/*{{{*/
   name.init();
   real_name.init();
   types.init();
   variables.init();
}/*}}}*/

inline void data_type_s::clear()
{/*{{{*/
   name.clear();
   real_name.clear();
   types.clear();
   variables.clear();

   init();
}/*}}}*/

inline void data_type_s::set(unsigned a_cont_idx,string_s &a_name,string_s &a_real_name,unsigned a_properties,string_array_s &a_types,string_array_s &a_variables)
{/*{{{*/
   cont_idx = a_cont_idx;
   name = a_name;
   real_name = a_real_name;
   properties = a_properties;
   types = a_types;
   variables = a_variables;
}/*}}}*/

inline void data_type_s::flush_all()
{/*{{{*/
   types.flush_all();
   variables.flush_all();
}/*}}}*/

inline void data_type_s::swap(data_type_s &a_second)
{/*{{{*/
   unsigned tmp_cont_idx = cont_idx;
   cont_idx = a_second.cont_idx;
   a_second.cont_idx = tmp_cont_idx;

   name.swap(a_second.name);

   real_name.swap(a_second.real_name);

   unsigned tmp_properties = properties;
   properties = a_second.properties;
   a_second.properties = tmp_properties;

   types.swap(a_second.types);

   variables.swap(a_second.variables);
}/*}}}*/

inline data_type_s &data_type_s::operator=(data_type_s &a_src)
{/*{{{*/
   cont_idx = a_src.cont_idx;
   name = a_src.name;
   real_name = a_src.real_name;
   properties = a_src.properties;
   types = a_src.types;
   variables = a_src.variables;

   return *this;
}/*}}}*/

inline bool data_type_s::operator==(data_type_s &a_second)
{/*{{{*/
   return (cont_idx == a_second.cont_idx && name == a_second.name && real_name == a_second.real_name && properties == a_second.properties && types == a_second.types && variables == a_second.variables);
}/*}}}*/



// -- data_type_array_s --
// --- struct data_type_array_s inline method definition ---

inline void data_type_array_s::init()
{/*{{{*/
   size = 0;
   used = 0;
   data = NULL;
}/*}}}*/

inline void data_type_array_s::init_size(unsigned a_size)
{/*{{{*/
   init();
   copy_resize(a_size);
}/*}}}*/

inline void data_type_array_s::flush()
{/*{{{*/
   copy_resize(used);
}/*}}}*/

inline void data_type_array_s::flush_all()
{/*{{{*/
   copy_resize(used);
}/*}}}*/

inline void data_type_array_s::swap(data_type_array_s &a_second)
{/*{{{*/
   unsigned tmp_unsigned = size;
   size = a_second.size;
   a_second.size = tmp_unsigned;

   tmp_unsigned = used;
   used = a_second.used;
   a_second.used = tmp_unsigned;

   data_type_s *tmp_data = data;
   data = a_second.data;
   a_second.data = tmp_data;
}/*}}}*/

inline data_type_s &data_type_array_s::operator[](unsigned a_idx)
{/*{{{*/
   debug_assert(a_idx < used);
   return data[a_idx];
}/*}}}*/

inline void data_type_array_s::push(data_type_s &a_value)
{/*{{{*/
   if (used >= size) {
      copy_resize((size << 1) + c_array_add);
   }

   data[used++] = a_value;
}/*}}}*/

inline void data_type_array_s::push_blank()
{/*{{{*/
   if (used >= size) {
      copy_resize((size << 1) + c_array_add);
   }

   used++;
}/*}}}*/

inline void data_type_array_s::push_clear()
{/*{{{*/
   if (used >= size) {
      copy_resize((size << 1) + c_array_add);
   }

   data[used++].clear();
}/*}}}*/

inline data_type_s &data_type_array_s::pop()
{/*{{{*/
   debug_assert(used > 0);
   return data[--used];
}/*}}}*/

inline data_type_s &data_type_array_s::last()
{/*{{{*/
   debug_assert(used > 0);
   return data[used - 1];
}/*}}}*/



// -- abbreviation_s --
// --- struct abbreviation_s inline method definition ---

inline void abbreviation_s::init()
{/*{{{*/
   name.init();
}/*}}}*/

inline void abbreviation_s::clear()
{/*{{{*/
   name.clear();

   init();
}/*}}}*/

inline void abbreviation_s::set(string_s &a_name,unsigned a_data_type_idx)
{/*{{{*/
   name = a_name;
   data_type_idx = a_data_type_idx;
}/*}}}*/

inline void abbreviation_s::flush_all()
{/*{{{*/
}/*}}}*/

inline void abbreviation_s::swap(abbreviation_s &a_second)
{/*{{{*/
   name.swap(a_second.name);

   unsigned tmp_data_type_idx = data_type_idx;
   data_type_idx = a_second.data_type_idx;
   a_second.data_type_idx = tmp_data_type_idx;
}/*}}}*/

inline abbreviation_s &abbreviation_s::operator=(abbreviation_s &a_src)
{/*{{{*/
   name = a_src.name;
   data_type_idx = a_src.data_type_idx;

   return *this;
}/*}}}*/

inline bool abbreviation_s::operator==(abbreviation_s &a_second)
{/*{{{*/
   return (name == a_second.name && data_type_idx == a_second.data_type_idx);
}/*}}}*/



// -- abbreviation_array_s --
// --- struct abbreviation_array_s inline method definition ---

inline void abbreviation_array_s::init()
{/*{{{*/
   size = 0;
   used = 0;
   data = NULL;
}/*}}}*/

inline void abbreviation_array_s::init_size(unsigned a_size)
{/*{{{*/
   init();
   copy_resize(a_size);
}/*}}}*/

inline void abbreviation_array_s::flush()
{/*{{{*/
   copy_resize(used);
}/*}}}*/

inline void abbreviation_array_s::flush_all()
{/*{{{*/
   copy_resize(used);
}/*}}}*/

inline void abbreviation_array_s::swap(abbreviation_array_s &a_second)
{/*{{{*/
   unsigned tmp_unsigned = size;
   size = a_second.size;
   a_second.size = tmp_unsigned;

   tmp_unsigned = used;
   used = a_second.used;
   a_second.used = tmp_unsigned;

   abbreviation_s *tmp_data = data;
   data = a_second.data;
   a_second.data = tmp_data;
}/*}}}*/

inline abbreviation_s &abbreviation_array_s::operator[](unsigned a_idx)
{/*{{{*/
   debug_assert(a_idx < used);
   return data[a_idx];
}/*}}}*/

inline void abbreviation_array_s::push(abbreviation_s &a_value)
{/*{{{*/
   if (used >= size) {
      copy_resize((size << 1) + c_array_add);
   }

   data[used++] = a_value;
}/*}}}*/

inline void abbreviation_array_s::push_blank()
{/*{{{*/
   if (used >= size) {
      copy_resize((size << 1) + c_array_add);
   }

   used++;
}/*}}}*/

inline void abbreviation_array_s::push_clear()
{/*{{{*/
   if (used >= size) {
      copy_resize((size << 1) + c_array_add);
   }

   data[used++].clear();
}/*}}}*/

inline abbreviation_s &abbreviation_array_s::pop()
{/*{{{*/
   debug_assert(used > 0);
   return data[--used];
}/*}}}*/

inline abbreviation_s &abbreviation_array_s::last()
{/*{{{*/
   debug_assert(used > 0);
   return data[used - 1];
}/*}}}*/



// -- container_parameters_s --
// --- struct container_parameters_s inline method definition ---

inline void container_parameters_s::init()
{/*{{{*/
   types.init();
   variables.init();
   compare.init();
   functions.init();
   names.init();
}/*}}}*/

inline void container_parameters_s::clear()
{/*{{{*/
   types.clear();
   variables.clear();
   compare.clear();
   functions.clear();
   names.clear();

   init();
}/*}}}*/

inline void container_parameters_s::set(string_array_s &a_types,string_array_s &a_variables,string_array_s &a_compare,string_array_s &a_functions,string_array_s &a_names)
{/*{{{*/
   types = a_types;
   variables = a_variables;
   compare = a_compare;
   functions = a_functions;
   names = a_names;
}/*}}}*/

inline void container_parameters_s::flush_all()
{/*{{{*/
   types.flush_all();
   variables.flush_all();
   compare.flush_all();
   functions.flush_all();
   names.flush_all();
}/*}}}*/

inline void container_parameters_s::swap(container_parameters_s &a_second)
{/*{{{*/
   types.swap(a_second.types);

   variables.swap(a_second.variables);

   compare.swap(a_second.compare);

   functions.swap(a_second.functions);

   names.swap(a_second.names);
}/*}}}*/

inline container_parameters_s &container_parameters_s::operator=(container_parameters_s &a_src)
{/*{{{*/
   types = a_src.types;
   variables = a_src.variables;
   compare = a_src.compare;
   functions = a_src.functions;
   names = a_src.names;

   return *this;
}/*}}}*/

inline bool container_parameters_s::operator==(container_parameters_s &a_second)
{/*{{{*/
   return (types == a_second.types && variables == a_second.variables && compare == a_second.compare && functions == a_second.functions && names == a_second.names);
}/*}}}*/



inline void container_parameters_s::clean_out()
{/*{{{*/
   types.used = 0;
   variables.used = 0;
   compare.used = 0;
   functions.used = 0;
   names.used = 0;
}/*}}}*/

// -- processor_s --
// --- struct processor_s inline method definition ---

inline void processor_s::init()
{/*{{{*/
   include_dirs.init();
   include_names.init();
   data_types.init();
   abbreviations.init();
   cont_params.init();
}/*}}}*/

inline void processor_s::clear()
{/*{{{*/
   include_dirs.clear();
   include_names.clear();
   data_types.clear();
   abbreviations.clear();
   cont_params.clear();

   init();
}/*}}}*/

inline void processor_s::set(FILE_ptr a_out_file,string_array_s &a_include_dirs,string_array_s &a_include_names,data_type_array_s &a_data_types,abbreviation_array_s &a_abbreviations,unsigned a_type_settings,container_parameters_s &a_cont_params)
{/*{{{*/
   out_file = a_out_file;
   include_dirs = a_include_dirs;
   include_names = a_include_names;
   data_types = a_data_types;
   abbreviations = a_abbreviations;
   type_settings = a_type_settings;
   cont_params = a_cont_params;
}/*}}}*/

inline void processor_s::flush_all()
{/*{{{*/
   include_dirs.flush_all();
   include_names.flush_all();
   data_types.flush_all();
   abbreviations.flush_all();
}/*}}}*/

inline void processor_s::swap(processor_s &a_second)
{/*{{{*/
   FILE_ptr tmp_out_file = out_file;
   out_file = a_second.out_file;
   a_second.out_file = tmp_out_file;

   include_dirs.swap(a_second.include_dirs);

   include_names.swap(a_second.include_names);

   data_types.swap(a_second.data_types);

   abbreviations.swap(a_second.abbreviations);

   unsigned tmp_type_settings = type_settings;
   type_settings = a_second.type_settings;
   a_second.type_settings = tmp_type_settings;

   cont_params.swap(a_second.cont_params);
}/*}}}*/

inline processor_s &processor_s::operator=(processor_s &a_src)
{/*{{{*/
   out_file = a_src.out_file;
   include_dirs = a_src.include_dirs;
   include_names = a_src.include_names;
   data_types = a_src.data_types;
   abbreviations = a_src.abbreviations;
   type_settings = a_src.type_settings;
   cont_params = a_src.cont_params;

   return *this;
}/*}}}*/

inline bool processor_s::operator==(processor_s &a_second)
{/*{{{*/
   return (out_file == a_second.out_file && include_dirs == a_second.include_dirs && include_names == a_second.include_names && data_types == a_second.data_types && abbreviations == a_second.abbreviations && type_settings == a_second.type_settings && cont_params == a_second.cont_params);
}/*}}}*/



#endif



/*
 * definitions of generated structures
 */

// -- lalr_stack_element_s --
// structure lalr_stack_element_s definition

/*!
 * \brief __GEN structure
 */
struct lalr_stack_element_s
{
   unsigned lalr_state; //!< member - 0
   unsigned terminal_start; //!< member - 1
   unsigned terminal_end; //!< member - 2

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
   inline void set(unsigned a_lalr_state,unsigned a_terminal_start,unsigned a_terminal_end);
   /*!
    * \brief __GEN flush structure memory usage, recursive on members
    */
   inline void flush_all();

   /*!
    * \brief __GEN swap structure members with another structure
    */
   inline void swap(lalr_stack_element_s &a_second);

   /*!
    * \brief __GEN copy structure from another structure
    * \param a_src - reference to another structure
    * \return reference to this structure
    */
   inline lalr_stack_element_s &operator=(lalr_stack_element_s &a_src);

   /*!
    * \brief __GEN compare structure with another structure
    * \param a_second - reference to another structure
    * \return result of comparison
    */
   inline bool operator==(lalr_stack_element_s &a_second);

};



// -- lalr_stack_s --
// --- struct lalr_stack_s definition --- 

/*!
 * \brief __GEN array of type lalr_stack_element_s
 */
struct lalr_stack_s
{
   unsigned size; //!< actual size of allocated space in array
   unsigned used; //!< count of used space in array
   lalr_stack_element_s *data; //!< pointer to array elements

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
   inline void clear();

   /*!
    * \brief __GEN set array content from element pointer
    * \param a_used - number of elements stored at pointed location
    * \param a_data - pointer to elements
    */
   inline void set(unsigned a_used,lalr_stack_element_s *a_data);

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
   inline void swap(lalr_stack_s &a_second);

   /*!
    * \brief __GEN select element of array
    * \param a_idx - index of element in array
    * \return reference to element of array
    */
   inline lalr_stack_element_s &operator[](unsigned a_idx);

   /*!
    * \brief __GEN insert element to end of array
    * \param a_value - reference to inserted value
    */
   inline void push(lalr_stack_element_s &a_value);

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
   inline lalr_stack_element_s &pop();

   /*!
    * \brief __GEN return value of last element in array
    * \return reference to last element
    */
   inline lalr_stack_element_s &last();

   /*!
    * \brief __GEN change array capacity
    * \param a_size - requested array capacity
    */
   void copy_resize(unsigned a_size);

   /*!
    * \brief __GEN set all elements of array to given value
    * \param a_value - new value of all elements
    */
   void fill(lalr_stack_element_s &a_value);

   /*!
    * \brief __GEN search for index of element
    * \param a_value - value which index is searched
    */
   unsigned get_idx(lalr_stack_element_s &a_value);

   /*!
    * \brief __GEN copy array from another array
    * \param a_src - reference to another array
    * \return reference to this array
    */
   inline lalr_stack_s &operator=(lalr_stack_s &a_src);

   /*!
    * \brief __GEN comparison of array with another array
    * \param a_second - reference to another array
    * \return result of comparison
    */
   inline bool operator==(lalr_stack_s &a_second);

   

   inline void push(unsigned a_lalr_state);
   inline void push(unsigned a_lalr_state,unsigned a_terminal_start,unsigned a_terminal_end);

   
};



// -- process_s --
// structure process_s definition

/*!
 * \brief __GEN structure
 */
struct process_s
{
   processor_s_ptr processor_ptr; //!< member - 0
   string_s source_string; //!< member - 1
   string_s code; //!< member - 2
   lalr_stack_s lalr_stack; //!< member - 3

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
   inline void set(processor_s_ptr a_processor_ptr,string_s &a_source_string,string_s &a_code,lalr_stack_s &a_lalr_stack);
   /*!
    * \brief __GEN flush structure memory usage, recursive on members
    */
   inline void flush_all();

   /*!
    * \brief __GEN swap structure members with another structure
    */
   inline void swap(process_s &a_second);

   /*!
    * \brief __GEN copy structure from another structure
    * \param a_src - reference to another structure
    * \return reference to this structure
    */
   inline process_s &operator=(process_s &a_src);

   /*!
    * \brief __GEN compare structure with another structure
    * \param a_second - reference to another structure
    * \return result of comparison
    */
   inline bool operator==(process_s &a_second);

   

   unsigned find_terminal(unsigned &a_input_idx);
   bool parse_code(string_s &a_code);
   bool run_on(const char *a_file_name);

   static void pa_reduce_null(process_s &proc);
   static void pa_reduce_include(process_s &proc);
   static void pa_reduce_inlines(process_s &proc);
   static void pa_reduce_methods(process_s &proc);
   static void pa_reduce_define(process_s &proc);
   static void pa_reduce_mod_basic(process_s &proc);
   static void pa_reduce_mod_static(process_s &proc);
   static void pa_reduce_mod_dynamic(process_s &proc);
   static void pa_reduce_mod_flushable(process_s &proc);
   static void pa_reduce_gen_container(process_s &proc);
   static void pa_reduce_type(process_s &proc);
   static void pa_reduce_type_and_name(process_s &proc);
   static void pa_reduce_not_generate_init(process_s &proc);
   static void pa_reduce_not_generate_clear(process_s &proc);
   static void pa_reduce_not_generate_swap(process_s &proc);
   static void pa_reduce_not_generate_operator_equal(process_s &proc);
   static void pa_reduce_option_strict_dynamic(process_s &proc);
   static void pa_reduce_additions_body(process_s &proc);
   static void pa_reduce_name(process_s &proc);

   
};



// - array of callback parse functions -
extern void(*parse_callbacks[])(process_s &proc);

/*
 * inline methods of generated structures
 */

// -- lalr_stack_element_s --
// --- struct lalr_stack_element_s inline method definition ---

inline void lalr_stack_element_s::init()
{/*{{{*/
}/*}}}*/

inline void lalr_stack_element_s::clear()
{/*{{{*/

   init();
}/*}}}*/

inline void lalr_stack_element_s::set(unsigned a_lalr_state,unsigned a_terminal_start,unsigned a_terminal_end)
{/*{{{*/
   lalr_state = a_lalr_state;
   terminal_start = a_terminal_start;
   terminal_end = a_terminal_end;
}/*}}}*/

inline void lalr_stack_element_s::flush_all()
{/*{{{*/
}/*}}}*/

inline void lalr_stack_element_s::swap(lalr_stack_element_s &a_second)
{/*{{{*/
   unsigned tmp_lalr_state = lalr_state;
   lalr_state = a_second.lalr_state;
   a_second.lalr_state = tmp_lalr_state;

   unsigned tmp_terminal_start = terminal_start;
   terminal_start = a_second.terminal_start;
   a_second.terminal_start = tmp_terminal_start;

   unsigned tmp_terminal_end = terminal_end;
   terminal_end = a_second.terminal_end;
   a_second.terminal_end = tmp_terminal_end;
}/*}}}*/

inline lalr_stack_element_s &lalr_stack_element_s::operator=(lalr_stack_element_s &a_src)
{/*{{{*/
   lalr_state = a_src.lalr_state;
   terminal_start = a_src.terminal_start;
   terminal_end = a_src.terminal_end;

   return *this;
}/*}}}*/

inline bool lalr_stack_element_s::operator==(lalr_stack_element_s &a_second)
{/*{{{*/
   return (lalr_state == a_second.lalr_state && terminal_start == a_second.terminal_start && terminal_end == a_second.terminal_end);
}/*}}}*/



// -- lalr_stack_s --
// --- struct lalr_stack_s inline method definition ---

inline void lalr_stack_s::init()
{/*{{{*/
   size = 0;
   used = 0;
   data = NULL;
}/*}}}*/

inline void lalr_stack_s::init_size(unsigned a_size)
{/*{{{*/
   init();
   copy_resize(a_size);
}/*}}}*/

inline void lalr_stack_s::clear()
{/*{{{*/
   if (data != NULL) {
      cfree(data);
   }

   init();
}/*}}}*/

inline void lalr_stack_s::set(unsigned a_used,lalr_stack_element_s *a_data)
{/*{{{*/
   clear();
   if (a_used == 0) return;
   
   debug_assert(a_data != NULL);
   copy_resize(a_used);

   memcpy(data,a_data,a_used*sizeof(lalr_stack_element_s));
   used = a_used;
}/*}}}*/

inline void lalr_stack_s::flush()
{/*{{{*/
   copy_resize(used);
}/*}}}*/

inline void lalr_stack_s::flush_all()
{/*{{{*/
   copy_resize(used);
}/*}}}*/

inline void lalr_stack_s::swap(lalr_stack_s &a_second)
{/*{{{*/
   unsigned tmp_unsigned = size;
   size = a_second.size;
   a_second.size = tmp_unsigned;

   tmp_unsigned = used;
   used = a_second.used;
   a_second.used = tmp_unsigned;

   lalr_stack_element_s *tmp_data = data;
   data = a_second.data;
   a_second.data = tmp_data;
}/*}}}*/

inline lalr_stack_element_s &lalr_stack_s::operator[](unsigned a_idx)
{/*{{{*/
   debug_assert(a_idx < used);
   return data[a_idx];
}/*}}}*/

inline void lalr_stack_s::push(lalr_stack_element_s &a_value)
{/*{{{*/
   if (used >= size) {
      copy_resize((size << 1) + c_array_add);
   }

   data[used++] = a_value;
}/*}}}*/

inline void lalr_stack_s::push_blank()
{/*{{{*/
   if (used >= size) {
      copy_resize((size << 1) + c_array_add);
   }

   used++;
}/*}}}*/

inline void lalr_stack_s::push_clear()
{/*{{{*/
   if (used >= size) {
      copy_resize((size << 1) + c_array_add);
   }

   used++;
}/*}}}*/

inline lalr_stack_element_s &lalr_stack_s::pop()
{/*{{{*/
   debug_assert(used > 0);
   return data[--used];
}/*}}}*/

inline lalr_stack_element_s &lalr_stack_s::last()
{/*{{{*/
   debug_assert(used > 0);
   return data[used - 1];
}/*}}}*/

inline lalr_stack_s &lalr_stack_s::operator=(lalr_stack_s &a_src)
{/*{{{*/
   clear();

   if (a_src.used == 0) return *this;

   copy_resize(a_src.used);
   memcpy(data,a_src.data,a_src.used*sizeof(lalr_stack_element_s));

   used = a_src.used;
   return *this;
}/*}}}*/

inline bool lalr_stack_s::operator==(lalr_stack_s &a_second)
{/*{{{*/
   if (used != a_second.used) return false;
   if (used == 0) return true;

   return (memcmp(data,a_second.data,used*sizeof(lalr_stack_element_s)) == 0);
}/*}}}*/



inline void lalr_stack_s::push(unsigned a_lalr_state)
{
   if (used >= size) {
      copy_resize(size + c_array_add);
   }

   lalr_stack_element_s &target = data[used++];

   target.lalr_state = a_lalr_state;
}

inline void lalr_stack_s::push(unsigned a_lalr_state,unsigned a_terminal_start,unsigned a_terminal_end)
{
   if (used >= size) {
      copy_resize(size + c_array_add);
   }

   lalr_stack_element_s &target = data[used++];

   target.lalr_state = a_lalr_state;
   target.terminal_start = a_terminal_start;
   target.terminal_end = a_terminal_end;
}

// -- process_s --
// --- struct process_s inline method definition ---

inline void process_s::init()
{/*{{{*/
   source_string.init();
   code.init();
   lalr_stack.init();
}/*}}}*/

inline void process_s::clear()
{/*{{{*/
   source_string.clear();
   code.clear();
   lalr_stack.clear();

   init();
}/*}}}*/

inline void process_s::set(processor_s_ptr a_processor_ptr,string_s &a_source_string,string_s &a_code,lalr_stack_s &a_lalr_stack)
{/*{{{*/
   processor_ptr = a_processor_ptr;
   source_string = a_source_string;
   code = a_code;
   lalr_stack = a_lalr_stack;
}/*}}}*/

inline void process_s::flush_all()
{/*{{{*/
   lalr_stack.flush_all();
}/*}}}*/

inline void process_s::swap(process_s &a_second)
{/*{{{*/
   processor_s_ptr tmp_processor_ptr = processor_ptr;
   processor_ptr = a_second.processor_ptr;
   a_second.processor_ptr = tmp_processor_ptr;

   source_string.swap(a_second.source_string);

   code.swap(a_second.code);

   lalr_stack.swap(a_second.lalr_stack);
}/*}}}*/

inline process_s &process_s::operator=(process_s &a_src)
{/*{{{*/
   processor_ptr = a_src.processor_ptr;
   source_string = a_src.source_string;
   code = a_src.code;
   lalr_stack = a_src.lalr_stack;

   return *this;
}/*}}}*/

inline bool process_s::operator==(process_s &a_second)
{/*{{{*/
   return (processor_ptr == a_second.processor_ptr && source_string == a_second.source_string && code == a_second.code && lalr_stack == a_second.lalr_stack);
}/*}}}*/



#endif



/*
 * constants and definitions
 */

void(*parse_callbacks[])(process_s &proc) = 
{
   process_s::pa_reduce_null,
   process_s::pa_reduce_null,
   process_s::pa_reduce_null,
   process_s::pa_reduce_include,
   process_s::pa_reduce_inlines,
   process_s::pa_reduce_methods,
   process_s::pa_reduce_define,
   process_s::pa_reduce_null,
   process_s::pa_reduce_null,
   process_s::pa_reduce_mod_basic,
   process_s::pa_reduce_mod_static,
   process_s::pa_reduce_mod_dynamic,
   process_s::pa_reduce_mod_flushable,
   process_s::pa_reduce_gen_container,
   process_s::pa_reduce_null,
   process_s::pa_reduce_null,
   process_s::pa_reduce_null,
   process_s::pa_reduce_null,
   process_s::pa_reduce_null,
   process_s::pa_reduce_type,
   process_s::pa_reduce_type_and_name,
   process_s::pa_reduce_null,
   process_s::pa_reduce_null,
   process_s::pa_reduce_null,
   process_s::pa_reduce_not_generate_init,
   process_s::pa_reduce_not_generate_clear,
   process_s::pa_reduce_not_generate_swap,
   process_s::pa_reduce_not_generate_operator_equal,
   process_s::pa_reduce_null,
   process_s::pa_reduce_null,
   process_s::pa_reduce_null,
   process_s::pa_reduce_option_strict_dynamic,
   process_s::pa_reduce_additions_body,
   process_s::pa_reduce_name,
};

// - parse constants -
const unsigned short c_escape_char = 256;
const unsigned c_rule_cnt = 34;
const unsigned rule_head_idxs[c_rule_cnt] = {28, 29, 29, 30, 30, 30, 30, 31, 31, 32, 32, 32, 32, 30, 33, 33, 34, 35, 35, 36, 36, 34, 37, 37, 38, 38, 38, 38, 34, 39, 39, 40, 34, 34, };
const unsigned rule_body_lengths[c_rule_cnt] = {4, 2, 1, 2, 2, 2, 3, 2, 1, 1, 1, 1, 1, 3, 2, 1, 3, 2, 1, 1, 3, 2, 2, 1, 1, 1, 1, 1, 2, 2, 1, 1, 2, 1, };

// - parsing table -
#define blank c_idx_not_exist
#define SHIFT(VALUE) VALUE
#define REDUCE(VALUE) c_lalr_table_reduce_base + VALUE
#define GOTO(VALUE) VALUE

const unsigned c_lalr_table_reduce_base = 0x80000000;
const unsigned c_terminal_plus_nonterminal_cnt = 41;
const unsigned lalr_state_cnt = 51;

const unsigned lalr_table[lalr_state_cnt*c_terminal_plus_nonterminal_cnt] = {
    SHIFT(1),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,    SHIFT(4),    SHIFT(5),    SHIFT(6),       blank,    SHIFT(7),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    SHIFT(8),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,     GOTO(2),     GOTO(3),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,   SHIFT(10),    SHIFT(4),    SHIFT(5),    SHIFT(6),       blank,    SHIFT(7),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    SHIFT(8),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,     GOTO(9),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,   REDUCE(2),   REDUCE(2),   REDUCE(2),   REDUCE(2),       blank,   REDUCE(2),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   REDUCE(2),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(11),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(12),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(13),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(14),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,   SHIFT(20),       blank,       blank,       blank,       blank,       blank,   SHIFT(18),       blank,       blank,       blank,       blank,   SHIFT(19),       blank,       blank,       blank,   SHIFT(21),   SHIFT(17),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(15),    GOTO(16),       blank,       blank,       blank,       blank,       blank,       blank,
       blank,   REDUCE(1),   REDUCE(1),   REDUCE(1),   REDUCE(1),       blank,   REDUCE(1),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   REDUCE(1),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(22),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,   REDUCE(3),   REDUCE(3),   REDUCE(3),   REDUCE(3),       blank,   REDUCE(3),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   REDUCE(3),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,   REDUCE(4),   REDUCE(4),   REDUCE(4),   REDUCE(4),       blank,   REDUCE(4),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   REDUCE(4),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,   REDUCE(5),   REDUCE(5),   REDUCE(5),   REDUCE(5),       blank,   REDUCE(5),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   REDUCE(5),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(25),   SHIFT(26),   SHIFT(27),   SHIFT(28),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(23),    GOTO(24),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,   SHIFT(20),       blank,       blank,       blank,       blank,       blank,   SHIFT(18),       blank,       blank,       blank,       blank,   SHIFT(19),       blank,       blank,       blank,   SHIFT(21),   SHIFT(17),       blank,       blank,   SHIFT(30),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(29),       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,  REDUCE(15),       blank,       blank,       blank,       blank,       blank,  REDUCE(15),       blank,       blank,       blank,       blank,  REDUCE(15),       blank,       blank,       blank,  REDUCE(15),  REDUCE(15),       blank,       blank,  REDUCE(15),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(33),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(31),    GOTO(32),       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(36),   SHIFT(37),   SHIFT(38),   SHIFT(39),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(34),    GOTO(35),       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(42),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(40),    GOTO(41),
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(43),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,  REDUCE(33),       blank,       blank,       blank,       blank,       blank,  REDUCE(33),       blank,       blank,       blank,       blank,  REDUCE(33),       blank,       blank,       blank,  REDUCE(33),  REDUCE(33),       blank,       blank,  REDUCE(33),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,   REDUCE(6),   REDUCE(6),   REDUCE(6),   REDUCE(6),       blank,   REDUCE(6),   SHIFT(25),   SHIFT(26),   SHIFT(27),   SHIFT(28),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   REDUCE(6),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(44),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,   REDUCE(8),   REDUCE(8),   REDUCE(8),   REDUCE(8),       blank,   REDUCE(8),   REDUCE(8),   REDUCE(8),   REDUCE(8),   REDUCE(8),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   REDUCE(8),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,   REDUCE(9),   REDUCE(9),   REDUCE(9),   REDUCE(9),       blank,   REDUCE(9),   REDUCE(9),   REDUCE(9),   REDUCE(9),   REDUCE(9),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   REDUCE(9),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,  REDUCE(10),  REDUCE(10),  REDUCE(10),  REDUCE(10),       blank,  REDUCE(10),  REDUCE(10),  REDUCE(10),  REDUCE(10),  REDUCE(10),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(10),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,  REDUCE(11),  REDUCE(11),  REDUCE(11),  REDUCE(11),       blank,  REDUCE(11),  REDUCE(11),  REDUCE(11),  REDUCE(11),  REDUCE(11),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(11),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,  REDUCE(12),  REDUCE(12),  REDUCE(12),  REDUCE(12),       blank,  REDUCE(12),  REDUCE(12),  REDUCE(12),  REDUCE(12),  REDUCE(12),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(12),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,  REDUCE(14),       blank,       blank,       blank,       blank,       blank,  REDUCE(14),       blank,       blank,       blank,       blank,  REDUCE(14),       blank,       blank,       blank,  REDUCE(14),  REDUCE(14),       blank,       blank,  REDUCE(14),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,  REDUCE(13),  REDUCE(13),  REDUCE(13),  REDUCE(13),       blank,  REDUCE(13),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(13),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(33),       blank,   SHIFT(46),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(45),       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(18),       blank,  REDUCE(18),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(19),       blank,  REDUCE(19),   SHIFT(47),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,  REDUCE(21),       blank,       blank,       blank,       blank,       blank,  REDUCE(21),   SHIFT(36),   SHIFT(37),   SHIFT(38),   SHIFT(39),  REDUCE(21),       blank,       blank,       blank,  REDUCE(21),  REDUCE(21),       blank,       blank,  REDUCE(21),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(48),       blank,       blank,
       blank,       blank,       blank,       blank,       blank,  REDUCE(23),       blank,       blank,       blank,       blank,       blank,  REDUCE(23),  REDUCE(23),  REDUCE(23),  REDUCE(23),  REDUCE(23),  REDUCE(23),       blank,       blank,       blank,  REDUCE(23),  REDUCE(23),       blank,       blank,  REDUCE(23),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,  REDUCE(24),       blank,       blank,       blank,       blank,       blank,  REDUCE(24),  REDUCE(24),  REDUCE(24),  REDUCE(24),  REDUCE(24),  REDUCE(24),       blank,       blank,       blank,  REDUCE(24),  REDUCE(24),       blank,       blank,  REDUCE(24),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,  REDUCE(25),       blank,       blank,       blank,       blank,       blank,  REDUCE(25),  REDUCE(25),  REDUCE(25),  REDUCE(25),  REDUCE(25),  REDUCE(25),       blank,       blank,       blank,  REDUCE(25),  REDUCE(25),       blank,       blank,  REDUCE(25),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,  REDUCE(26),       blank,       blank,       blank,       blank,       blank,  REDUCE(26),  REDUCE(26),  REDUCE(26),  REDUCE(26),  REDUCE(26),  REDUCE(26),       blank,       blank,       blank,  REDUCE(26),  REDUCE(26),       blank,       blank,  REDUCE(26),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,  REDUCE(27),       blank,       blank,       blank,       blank,       blank,  REDUCE(27),  REDUCE(27),  REDUCE(27),  REDUCE(27),  REDUCE(27),  REDUCE(27),       blank,       blank,       blank,  REDUCE(27),  REDUCE(27),       blank,       blank,  REDUCE(27),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,  REDUCE(28),       blank,       blank,       blank,       blank,       blank,  REDUCE(28),       blank,       blank,       blank,       blank,  REDUCE(28),   SHIFT(42),       blank,       blank,  REDUCE(28),  REDUCE(28),       blank,       blank,  REDUCE(28),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,    GOTO(49),
       blank,       blank,       blank,       blank,       blank,  REDUCE(30),       blank,       blank,       blank,       blank,       blank,  REDUCE(30),       blank,       blank,       blank,       blank,  REDUCE(30),  REDUCE(30),       blank,       blank,  REDUCE(30),  REDUCE(30),       blank,       blank,  REDUCE(30),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,  REDUCE(31),       blank,       blank,       blank,       blank,       blank,  REDUCE(31),       blank,       blank,       blank,       blank,  REDUCE(31),  REDUCE(31),       blank,       blank,  REDUCE(31),  REDUCE(31),       blank,       blank,  REDUCE(31),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,  REDUCE(32),       blank,       blank,       blank,       blank,       blank,  REDUCE(32),       blank,       blank,       blank,       blank,  REDUCE(32),       blank,       blank,       blank,  REDUCE(32),  REDUCE(32),       blank,       blank,  REDUCE(32),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,   REDUCE(7),   REDUCE(7),   REDUCE(7),   REDUCE(7),       blank,   REDUCE(7),   REDUCE(7),   REDUCE(7),   REDUCE(7),   REDUCE(7),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   REDUCE(7),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(17),       blank,  REDUCE(17),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,  REDUCE(16),       blank,       blank,       blank,       blank,       blank,  REDUCE(16),       blank,       blank,       blank,       blank,  REDUCE(16),       blank,       blank,       blank,  REDUCE(16),  REDUCE(16),       blank,       blank,  REDUCE(16),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,   SHIFT(50),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,  REDUCE(22),       blank,       blank,       blank,       blank,       blank,  REDUCE(22),  REDUCE(22),  REDUCE(22),  REDUCE(22),  REDUCE(22),  REDUCE(22),       blank,       blank,       blank,  REDUCE(22),  REDUCE(22),       blank,       blank,  REDUCE(22),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,  REDUCE(29),       blank,       blank,       blank,       blank,       blank,  REDUCE(29),       blank,       blank,       blank,       blank,  REDUCE(29),  REDUCE(29),       blank,       blank,  REDUCE(29),  REDUCE(29),       blank,       blank,  REDUCE(29),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,  REDUCE(20),       blank,  REDUCE(20),       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,       blank,
};

/*
 * methods of generated structures
 */

// -- lalr_stack_element_s --
// --- struct lalr_stack_element_s method definition ---



// -- lalr_stack_s --
// --- struct lalr_stack_s method definition ---

void lalr_stack_s::reserve(unsigned a_cnt)
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

void lalr_stack_s::push_blanks(unsigned a_cnt)
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

void lalr_stack_s::copy_resize(unsigned a_size)
{/*{{{*/
   debug_assert(a_size >= used);

   lalr_stack_element_s *n_data;

   if (a_size == 0) {
      n_data = NULL;
   }
   else {
      n_data = (lalr_stack_element_s *)cmalloc(a_size*sizeof(lalr_stack_element_s));
   }

   if (used != 0) {
      memcpy(n_data,data,used*sizeof(lalr_stack_element_s));
   }

   if (size != 0) {
      cfree(data);
   }

   data = n_data;
   size = a_size;
}/*}}}*/

void lalr_stack_s::fill(lalr_stack_element_s &a_value)
{/*{{{*/
   if (size == 0) return;

   lalr_stack_element_s *ptr = data;
   lalr_stack_element_s *ptr_end = data + size;

   do {
      *ptr = a_value;
   } while(++ptr < ptr_end);

   used = size;
}/*}}}*/

unsigned lalr_stack_s::get_idx(lalr_stack_element_s &a_value)
{/*{{{*/
   if (used == 0) return c_idx_not_exist;

   lalr_stack_element_s *ptr = data;
   lalr_stack_element_s *ptr_end = data + used;

   do {
      if (*ptr == a_value) {
         return ptr - data;
      }
   } while(++ptr < ptr_end);

   return c_idx_not_exist;
}/*}}}*/



// -- process_s --
// --- struct process_s method definition ---



unsigned process_s::find_terminal(unsigned &a_input_idx)
{/*{{{*/
   unsigned code_length = code.size - 1;

#define GET_NEXT_CHAR() \
{\
   if (a_input_idx < code_length) {\
      in_char = (unsigned char)code[a_input_idx];\
   }\
   else {\
      in_char = '\0';\
   }\
}

#define CLOSE_CHAR(RET_TERM_IDX) \
{\
   if (in_char == '\0') {\
      return RET_TERM_IDX;\
   }\
\
   a_input_idx++;\
}

   unsigned short in_char;

// - STATE 0 - 
   GET_NEXT_CHAR();

   if (in_char == 0)
      goto state_1_label;

   if (in_char >= 9 && in_char < 11)
      goto state_21_label;

   if (in_char == 32)
      goto state_21_label;

   if (in_char == 34)
      goto state_2_label;

   if (in_char == 36)
      goto state_3_label;

   if (in_char == 58)
      goto state_4_label;

   if (in_char == 59)
      goto state_5_label;

   if (in_char == 60)
      goto state_6_label;

   if (in_char == 62)
      goto state_7_label;

   if (in_char == 64)
      goto state_8_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char == 97)
      goto state_10_label;

   if (in_char == 98)
      goto state_11_label;

   if (in_char == 99)
      goto state_12_label;

   if (in_char == 100)
      goto state_13_label;

   if (in_char == 101)
      goto state_9_label;

   if (in_char == 102)
      goto state_14_label;

   if (in_char >= 103 && in_char < 105)
      goto state_9_label;

   if (in_char == 105)
      goto state_15_label;

   if (in_char >= 106 && in_char < 109)
      goto state_9_label;

   if (in_char == 109)
      goto state_16_label;

   if (in_char == 110)
      goto state_17_label;

   if (in_char == 111)
      goto state_18_label;

   if (in_char >= 112 && in_char < 115)
      goto state_9_label;

   if (in_char == 115)
      goto state_19_label;

   if (in_char >= 116 && in_char < 123)
      goto state_9_label;

   if (in_char == 123)
      goto state_20_label;

   return c_idx_not_exist;

// - STATE 1 - 
state_1_label:
   CLOSE_CHAR(27)
   return 27;

// - STATE 2 - 
state_2_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char < 34)
      goto state_2_label;

   if (in_char == 34)
      goto state_22_label;

   if (in_char >= 35 && in_char < 257)
      goto state_2_label;

   return c_idx_not_exist;

// - STATE 3 - 
state_3_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char < 10)
      goto state_3_label;

   if (in_char == 10)
      goto state_23_label;

   if (in_char >= 11 && in_char < 257)
      goto state_3_label;

   return c_idx_not_exist;

// - STATE 4 - 
state_4_label:
   CLOSE_CHAR(23)
   return 23;

// - STATE 5 - 
state_5_label:
   CLOSE_CHAR(24)
   return 24;

// - STATE 6 - 
state_6_label:
   CLOSE_CHAR(21)
   return 21;

// - STATE 7 - 
state_7_label:
   CLOSE_CHAR(22)
   return 22;

// - STATE 8 - 
state_8_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 98)
      goto state_24_label;

   if (in_char == 101)
      goto state_25_label;

   return c_idx_not_exist;

// - STATE 9 - 
state_9_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 10 - 
state_10_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 100)
      goto state_9_label;

   if (in_char == 100)
      goto state_26_label;

   if (in_char >= 101 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 11 - 
state_11_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char == 97)
      goto state_27_label;

   if (in_char >= 98 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 12 - 
state_12_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 108)
      goto state_9_label;

   if (in_char == 108)
      goto state_28_label;

   if (in_char >= 109 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 13 - 
state_13_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 101)
      goto state_9_label;

   if (in_char == 101)
      goto state_29_label;

   if (in_char >= 102 && in_char < 121)
      goto state_9_label;

   if (in_char == 121)
      goto state_30_label;

   if (in_char == 122)
      goto state_9_label;

   return 20;

// - STATE 14 - 
state_14_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 108)
      goto state_9_label;

   if (in_char == 108)
      goto state_31_label;

   if (in_char >= 109 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 15 - 
state_15_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 110)
      goto state_9_label;

   if (in_char == 110)
      goto state_32_label;

   if (in_char >= 111 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 16 - 
state_16_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 101)
      goto state_9_label;

   if (in_char == 101)
      goto state_33_label;

   if (in_char >= 102 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 17 - 
state_17_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 111)
      goto state_9_label;

   if (in_char == 111)
      goto state_34_label;

   if (in_char >= 112 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 18 - 
state_18_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 112)
      goto state_9_label;

   if (in_char == 112)
      goto state_35_label;

   if (in_char >= 113 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 19 - 
state_19_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 116)
      goto state_9_label;

   if (in_char == 116)
      goto state_36_label;

   if (in_char >= 117 && in_char < 119)
      goto state_9_label;

   if (in_char == 119)
      goto state_37_label;

   if (in_char >= 120 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 20 - 
state_20_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char < 125)
      goto state_20_label;

   if (in_char == 125)
      goto state_38_label;

   if (in_char >= 126 && in_char < 257)
      goto state_20_label;

   return c_idx_not_exist;

// - STATE 21 - 
state_21_label:
   CLOSE_CHAR(25)
   GET_NEXT_CHAR();

   if (in_char >= 9 && in_char < 11)
      goto state_21_label;

   if (in_char == 32)
      goto state_21_label;

   return 25;

// - STATE 22 - 
state_22_label:
   CLOSE_CHAR(18)
   return 18;

// - STATE 23 - 
state_23_label:
   CLOSE_CHAR(26)
   return 26;

// - STATE 24 - 
state_24_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 101)
      goto state_39_label;

   return c_idx_not_exist;

// - STATE 25 - 
state_25_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 110)
      goto state_40_label;

   return c_idx_not_exist;

// - STATE 26 - 
state_26_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 100)
      goto state_9_label;

   if (in_char == 100)
      goto state_41_label;

   if (in_char >= 101 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 27 - 
state_27_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 115)
      goto state_9_label;

   if (in_char == 115)
      goto state_42_label;

   if (in_char >= 116 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 28 - 
state_28_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 101)
      goto state_9_label;

   if (in_char == 101)
      goto state_43_label;

   if (in_char >= 102 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 29 - 
state_29_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 102)
      goto state_9_label;

   if (in_char == 102)
      goto state_44_label;

   if (in_char >= 103 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 30 - 
state_30_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 110)
      goto state_9_label;

   if (in_char == 110)
      goto state_45_label;

   if (in_char >= 111 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 31 - 
state_31_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 117)
      goto state_9_label;

   if (in_char == 117)
      goto state_46_label;

   if (in_char >= 118 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 32 - 
state_32_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 99)
      goto state_9_label;

   if (in_char == 99)
      goto state_47_label;

   if (in_char >= 100 && in_char < 105)
      goto state_9_label;

   if (in_char == 105)
      goto state_48_label;

   if (in_char >= 106 && in_char < 108)
      goto state_9_label;

   if (in_char == 108)
      goto state_49_label;

   if (in_char >= 109 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 33 - 
state_33_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 116)
      goto state_9_label;

   if (in_char == 116)
      goto state_50_label;

   if (in_char >= 117 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 34 - 
state_34_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 116)
      goto state_9_label;

   if (in_char == 116)
      goto state_51_label;

   if (in_char >= 117 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 35 - 
state_35_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 101)
      goto state_9_label;

   if (in_char == 101)
      goto state_52_label;

   if (in_char >= 102 && in_char < 116)
      goto state_9_label;

   if (in_char == 116)
      goto state_53_label;

   if (in_char >= 117 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 36 - 
state_36_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char == 97)
      goto state_54_label;

   if (in_char >= 98 && in_char < 114)
      goto state_9_label;

   if (in_char == 114)
      goto state_55_label;

   if (in_char >= 115 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 37 - 
state_37_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char == 97)
      goto state_56_label;

   if (in_char >= 98 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 38 - 
state_38_label:
   CLOSE_CHAR(19)
   return 19;

// - STATE 39 - 
state_39_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 103)
      goto state_57_label;

   return c_idx_not_exist;

// - STATE 40 - 
state_40_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 100)
      goto state_58_label;

   return c_idx_not_exist;

// - STATE 41 - 
state_41_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 105)
      goto state_9_label;

   if (in_char == 105)
      goto state_59_label;

   if (in_char >= 106 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 42 - 
state_42_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 105)
      goto state_9_label;

   if (in_char == 105)
      goto state_60_label;

   if (in_char >= 106 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 43 - 
state_43_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char == 97)
      goto state_61_label;

   if (in_char >= 98 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 44 - 
state_44_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 105)
      goto state_9_label;

   if (in_char == 105)
      goto state_62_label;

   if (in_char >= 106 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 45 - 
state_45_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char == 97)
      goto state_63_label;

   if (in_char >= 98 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 46 - 
state_46_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 115)
      goto state_9_label;

   if (in_char == 115)
      goto state_64_label;

   if (in_char >= 116 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 47 - 
state_47_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 108)
      goto state_9_label;

   if (in_char == 108)
      goto state_65_label;

   if (in_char >= 109 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 48 - 
state_48_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 116)
      goto state_9_label;

   if (in_char == 116)
      goto state_66_label;

   if (in_char >= 117 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 49 - 
state_49_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 105)
      goto state_9_label;

   if (in_char == 105)
      goto state_67_label;

   if (in_char >= 106 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 50 - 
state_50_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 104)
      goto state_9_label;

   if (in_char == 104)
      goto state_68_label;

   if (in_char >= 105 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 51 - 
state_51_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_69_label;

   if (in_char >= 97 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 52 - 
state_52_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 114)
      goto state_9_label;

   if (in_char == 114)
      goto state_70_label;

   if (in_char >= 115 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 53 - 
state_53_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 105)
      goto state_9_label;

   if (in_char == 105)
      goto state_71_label;

   if (in_char >= 106 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 54 - 
state_54_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 116)
      goto state_9_label;

   if (in_char == 116)
      goto state_72_label;

   if (in_char >= 117 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 55 - 
state_55_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 105)
      goto state_9_label;

   if (in_char == 105)
      goto state_73_label;

   if (in_char >= 106 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 56 - 
state_56_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 112)
      goto state_9_label;

   if (in_char == 112)
      goto state_74_label;

   if (in_char >= 113 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 57 - 
state_57_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 105)
      goto state_75_label;

   return c_idx_not_exist;

// - STATE 58 - 
state_58_label:
   CLOSE_CHAR(1)
   return 1;

// - STATE 59 - 
state_59_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 116)
      goto state_9_label;

   if (in_char == 116)
      goto state_76_label;

   if (in_char >= 117 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 60 - 
state_60_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 99)
      goto state_9_label;

   if (in_char == 99)
      goto state_77_label;

   if (in_char >= 100 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 61 - 
state_61_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 114)
      goto state_9_label;

   if (in_char == 114)
      goto state_78_label;

   if (in_char >= 115 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 62 - 
state_62_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 110)
      goto state_9_label;

   if (in_char == 110)
      goto state_79_label;

   if (in_char >= 111 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 63 - 
state_63_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 109)
      goto state_9_label;

   if (in_char == 109)
      goto state_80_label;

   if (in_char >= 110 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 64 - 
state_64_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 104)
      goto state_9_label;

   if (in_char == 104)
      goto state_81_label;

   if (in_char >= 105 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 65 - 
state_65_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 117)
      goto state_9_label;

   if (in_char == 117)
      goto state_82_label;

   if (in_char >= 118 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 66 - 
state_66_label:
   CLOSE_CHAR(12)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 123)
      goto state_9_label;

   return 12;

// - STATE 67 - 
state_67_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 110)
      goto state_9_label;

   if (in_char == 110)
      goto state_83_label;

   if (in_char >= 111 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 68 - 
state_68_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 111)
      goto state_9_label;

   if (in_char == 111)
      goto state_84_label;

   if (in_char >= 112 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 69 - 
state_69_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 103)
      goto state_9_label;

   if (in_char == 103)
      goto state_85_label;

   if (in_char >= 104 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 70 - 
state_70_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char == 97)
      goto state_86_label;

   if (in_char >= 98 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 71 - 
state_71_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 111)
      goto state_9_label;

   if (in_char == 111)
      goto state_87_label;

   if (in_char >= 112 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 72 - 
state_72_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 105)
      goto state_9_label;

   if (in_char == 105)
      goto state_88_label;

   if (in_char >= 106 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 73 - 
state_73_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 99)
      goto state_9_label;

   if (in_char == 99)
      goto state_89_label;

   if (in_char >= 100 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 74 - 
state_74_label:
   CLOSE_CHAR(14)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 123)
      goto state_9_label;

   return 14;

// - STATE 75 - 
state_75_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 110)
      goto state_90_label;

   return c_idx_not_exist;

// - STATE 76 - 
state_76_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 105)
      goto state_9_label;

   if (in_char == 105)
      goto state_91_label;

   if (in_char >= 106 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 77 - 
state_77_label:
   CLOSE_CHAR(7)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 123)
      goto state_9_label;

   return 7;

// - STATE 78 - 
state_78_label:
   CLOSE_CHAR(13)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 123)
      goto state_9_label;

   return 13;

// - STATE 79 - 
state_79_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 101)
      goto state_9_label;

   if (in_char == 101)
      goto state_92_label;

   if (in_char >= 102 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 80 - 
state_80_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 105)
      goto state_9_label;

   if (in_char == 105)
      goto state_93_label;

   if (in_char >= 106 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 81 - 
state_81_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char == 97)
      goto state_94_label;

   if (in_char >= 98 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 82 - 
state_82_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 100)
      goto state_9_label;

   if (in_char == 100)
      goto state_95_label;

   if (in_char >= 101 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 83 - 
state_83_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 101)
      goto state_9_label;

   if (in_char == 101)
      goto state_96_label;

   if (in_char >= 102 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 84 - 
state_84_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 100)
      goto state_9_label;

   if (in_char == 100)
      goto state_97_label;

   if (in_char >= 101 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 85 - 
state_85_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 101)
      goto state_9_label;

   if (in_char == 101)
      goto state_98_label;

   if (in_char >= 102 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 86 - 
state_86_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 116)
      goto state_9_label;

   if (in_char == 116)
      goto state_99_label;

   if (in_char >= 117 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 87 - 
state_87_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 110)
      goto state_9_label;

   if (in_char == 110)
      goto state_100_label;

   if (in_char >= 111 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 88 - 
state_88_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 99)
      goto state_9_label;

   if (in_char == 99)
      goto state_101_label;

   if (in_char >= 100 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 89 - 
state_89_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 116)
      goto state_9_label;

   if (in_char == 116)
      goto state_102_label;

   if (in_char >= 117 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 90 - 
state_90_label:
   CLOSE_CHAR(0)
   return 0;

// - STATE 91 - 
state_91_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 111)
      goto state_9_label;

   if (in_char == 111)
      goto state_103_label;

   if (in_char >= 112 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 92 - 
state_92_label:
   CLOSE_CHAR(6)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 123)
      goto state_9_label;

   return 6;

// - STATE 93 - 
state_93_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 99)
      goto state_9_label;

   if (in_char == 99)
      goto state_104_label;

   if (in_char >= 100 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 94 - 
state_94_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char == 97)
      goto state_9_label;

   if (in_char == 98)
      goto state_105_label;

   if (in_char >= 99 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 95 - 
state_95_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 101)
      goto state_9_label;

   if (in_char == 101)
      goto state_106_label;

   if (in_char >= 102 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 96 - 
state_96_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 115)
      goto state_9_label;

   if (in_char == 115)
      goto state_107_label;

   if (in_char >= 116 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 97 - 
state_97_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 115)
      goto state_9_label;

   if (in_char == 115)
      goto state_108_label;

   if (in_char >= 116 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 98 - 
state_98_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 110)
      goto state_9_label;

   if (in_char == 110)
      goto state_109_label;

   if (in_char >= 111 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 99 - 
state_99_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 111)
      goto state_9_label;

   if (in_char == 111)
      goto state_110_label;

   if (in_char >= 112 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 100 - 
state_100_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 115)
      goto state_9_label;

   if (in_char == 115)
      goto state_111_label;

   if (in_char >= 116 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 101 - 
state_101_label:
   CLOSE_CHAR(8)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 123)
      goto state_9_label;

   return 8;

// - STATE 102 - 
state_102_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_112_label;

   if (in_char >= 97 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 103 - 
state_103_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 110)
      goto state_9_label;

   if (in_char == 110)
      goto state_113_label;

   if (in_char >= 111 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 104 - 
state_104_label:
   CLOSE_CHAR(9)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 123)
      goto state_9_label;

   return 9;

// - STATE 105 - 
state_105_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 108)
      goto state_9_label;

   if (in_char == 108)
      goto state_114_label;

   if (in_char >= 109 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 106 - 
state_106_label:
   CLOSE_CHAR(2)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 123)
      goto state_9_label;

   return 2;

// - STATE 107 - 
state_107_label:
   CLOSE_CHAR(3)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 123)
      goto state_9_label;

   return 3;

// - STATE 108 - 
state_108_label:
   CLOSE_CHAR(4)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 123)
      goto state_9_label;

   return 4;

// - STATE 109 - 
state_109_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 101)
      goto state_9_label;

   if (in_char == 101)
      goto state_115_label;

   if (in_char >= 102 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 110 - 
state_110_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 114)
      goto state_9_label;

   if (in_char == 114)
      goto state_116_label;

   if (in_char >= 115 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 111 - 
state_111_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char == 58)
      goto state_117_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 112 - 
state_112_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 100)
      goto state_9_label;

   if (in_char == 100)
      goto state_118_label;

   if (in_char >= 101 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 113 - 
state_113_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 115)
      goto state_9_label;

   if (in_char == 115)
      goto state_119_label;

   if (in_char >= 116 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 114 - 
state_114_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 101)
      goto state_9_label;

   if (in_char == 101)
      goto state_120_label;

   if (in_char >= 102 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 115 - 
state_115_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 114)
      goto state_9_label;

   if (in_char == 114)
      goto state_121_label;

   if (in_char >= 115 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 116 - 
state_116_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char == 61)
      goto state_122_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 117 - 
state_117_label:
   CLOSE_CHAR(16)
   return 16;

// - STATE 118 - 
state_118_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 121)
      goto state_9_label;

   if (in_char == 121)
      goto state_123_label;

   if (in_char == 122)
      goto state_9_label;

   return 20;

// - STATE 119 - 
state_119_label:
   CLOSE_CHAR(5)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 123)
      goto state_9_label;

   return 5;

// - STATE 120 - 
state_120_label:
   CLOSE_CHAR(10)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 123)
      goto state_9_label;

   return 10;

// - STATE 121 - 
state_121_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char == 97)
      goto state_124_label;

   if (in_char >= 98 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 122 - 
state_122_label:
   CLOSE_CHAR(15)
   return 15;

// - STATE 123 - 
state_123_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 110)
      goto state_9_label;

   if (in_char == 110)
      goto state_125_label;

   if (in_char >= 111 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 124 - 
state_124_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 116)
      goto state_9_label;

   if (in_char == 116)
      goto state_126_label;

   if (in_char >= 117 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 125 - 
state_125_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char == 97)
      goto state_127_label;

   if (in_char >= 98 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 126 - 
state_126_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 101)
      goto state_9_label;

   if (in_char == 101)
      goto state_128_label;

   if (in_char >= 102 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 127 - 
state_127_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 109)
      goto state_9_label;

   if (in_char == 109)
      goto state_129_label;

   if (in_char >= 110 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 128 - 
state_128_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char == 58)
      goto state_130_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 129 - 
state_129_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 105)
      goto state_9_label;

   if (in_char == 105)
      goto state_131_label;

   if (in_char >= 106 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 130 - 
state_130_label:
   CLOSE_CHAR(11)
   return 11;

// - STATE 131 - 
state_131_label:
   CLOSE_CHAR(20)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 99)
      goto state_9_label;

   if (in_char == 99)
      goto state_132_label;

   if (in_char >= 100 && in_char < 123)
      goto state_9_label;

   return 20;

// - STATE 132 - 
state_132_label:
   CLOSE_CHAR(17)
   GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_9_label;

   if (in_char >= 65 && in_char < 91)
      goto state_9_label;

   if (in_char == 95)
      goto state_9_label;

   if (in_char >= 97 && in_char < 123)
      goto state_9_label;

   return 17;

}/*}}}*/

bool process_s::parse_code(string_s &a_code)
{/*{{{*/
   lalr_stack.used = 0;
   lalr_stack.push(0);

   unsigned old_input_idx = 0;
   unsigned input_idx = 0;
   unsigned ret_term = c_idx_not_exist;

   do {

      while (ret_term == c_idx_not_exist) {
         old_input_idx = input_idx;

         ret_term = find_terminal(input_idx);
         if (ret_term == c_idx_not_exist) {
            fprintf(stderr,
"ERROR: Cannot recognize terminal symbol\n"
"SOURCE CODE: %s\n",a_code.data);
            return false;
         }

         if (ret_term == 25 || ret_term == 26) {
            ret_term = c_idx_not_exist;
         }
      }

      // - search for action in parse table -
      unsigned parse_action = lalr_table[lalr_stack.last().lalr_state*c_terminal_plus_nonterminal_cnt + ret_term];
      if (parse_action == c_idx_not_exist) {
         fprintf(stderr,
"ERROR: Cannot find proper parse action\n"
"SOURCE CODE: %s\n",a_code.data);
         return false;
      }

      // - SHIFT action -
      if (parse_action < c_lalr_table_reduce_base) {

         if (ret_term == 27) {
            break;
         }

         // - push new state to stack and position of terminal in source string -
         lalr_stack.push(parse_action,old_input_idx,input_idx);
         ret_term = c_idx_not_exist;
      }

      // - REDUCE action -
      else {
         parse_action -= c_lalr_table_reduce_base;

         // - call parse callback -
         parse_callbacks[parse_action](*this);

         // - remove rule body from stack -
         lalr_stack.used -= rule_body_lengths[parse_action];

         // - push new automata state to stack -
         unsigned goto_val = lalr_table[lalr_stack.last().lalr_state*c_terminal_plus_nonterminal_cnt + rule_head_idxs[parse_action]];
         lalr_stack.push(goto_val);
      }

   } while(1);

   lalr_stack.clear();

   return true;
}/*}}}*/

bool process_s::run_on(const char *a_file_name)
{/*{{{*/
  string_s file_path;
  file_path.init();

  // - retrieve file full path (search in include directories) -
  if (!processor_ptr->find_include_file(a_file_name, file_path))
  {
    fprintf(stderr,"ERROR: Cannot found source file: \"%s\".\n", a_file_name);

    file_path.clear();
    return false;
  }

  if (!source_string.load_text_file(file_path.data)) {
    fprintf(stderr,"ERROR: Cannot read source file: \"%s\".\n", file_path.data);

    file_path.clear();
    return false;
  }

  file_path.clear();

  unsigned source_idx = 0;
  do {
    char *b_ptr = strstr(source_string.data + source_idx,c_begin_str);

    if (b_ptr == NULL) {
      fprintf(processor_ptr->out_file,"%s",source_string.data + source_idx);
      break;
    }
    else {
      *b_ptr = '\0';
      fprintf(processor_ptr->out_file,"%s",source_string.data + source_idx);
      *b_ptr = c_begin_str[0];

      source_idx = b_ptr - source_string.data;

      char *e_ptr = strstr(source_string.data + source_idx,c_end_str);
      if (e_ptr == NULL) {
        fprintf(stderr,"ERROR: Cannot find ending mark \"%s\".\n",c_end_str);
        return false;
      }

      unsigned tmp_char_idx = (e_ptr - b_ptr) + c_end_str_len;
      char tmp_char = b_ptr[tmp_char_idx];

      b_ptr[tmp_char_idx] = '\0';

      code.size = (e_ptr - b_ptr) + c_end_str_len + 1;
      code.data = b_ptr;

      // - parse definition code -
      parse_code(code);

      code.size = 1;
      code.data = (char *)&c_string_terminating_char;

      b_ptr[tmp_char_idx] = tmp_char;
      source_idx = e_ptr - source_string.data + c_end_str_len;
    }

  } while(true);

  return true;
}/*}}}*/

void process_s::pa_reduce_null(process_s &proc)
{/*{{{*/
}/*}}}*/

void process_s::pa_reduce_include(process_s &proc)
{/*{{{*/
   processor_s &processor = *proc.processor_ptr;
   string_s &code = proc.code;
   lalr_stack_element_s &lse = proc.lalr_stack.last();

   // -----

   unsigned tmp_char_idx = lse.terminal_end - 1;
   char tmp_char = code.data[tmp_char_idx];
   code.data[tmp_char_idx] = '\0';

   // - create included string -
   string_s include_str;
   include_str.data = code.data + lse.terminal_start + 1;
   include_str.size = (lse.terminal_end - lse.terminal_start) - 1;
   
   if (processor.include_names.get_idx(include_str) == c_idx_not_exist) {
      
      // - insert included file to include names array -
      processor.include_names.push_blank();
      processor.include_names.last().set(include_str.size - 1,include_str.data);

      // - process included file -
      process_s process;
      process.init();

      process.processor_ptr = proc.processor_ptr;
      process.run_on(code.data + lse.terminal_start + 1);
      process.clear();
   }

   code.data[tmp_char_idx] = tmp_char;
}/*}}}*/

void process_s::pa_reduce_inlines(process_s &proc)
{/*{{{*/
   processor_s &processor = *proc.processor_ptr;
   string_s &code = proc.code;
   lalr_stack_element_s &lse = proc.lalr_stack.last();

   // -----
   
   processor.generate_type_inlines(lse.terminal_end - lse.terminal_start,code.data + lse.terminal_start);
}/*}}}*/

void process_s::pa_reduce_methods(process_s &proc)
{/*{{{*/
   processor_s &processor = *proc.processor_ptr;
   string_s &code = proc.code;
   lalr_stack_element_s &lse = proc.lalr_stack.last();

   // -----
   
   processor.generate_type_methods(lse.terminal_end - lse.terminal_start,code.data + lse.terminal_start);
}/*}}}*/

void process_s::pa_reduce_define(process_s &proc)
{/*{{{*/
   processor_s &processor = *proc.processor_ptr;
   string_s &code = proc.code;
   lalr_stack_element_s &lse = proc.lalr_stack[proc.lalr_stack.used - 2];

   // -----

   unsigned str_length = lse.terminal_end - lse.terminal_start;
   char *str_data = code.data + lse.terminal_start;

   unsigned abb_idx = processor.abbreviations.get_idx_by_name(str_length,str_data);

   if (abb_idx != c_idx_not_exist) {
      fprintf(stderr,"ERROR: Cannot define type, type name already exist.\n");
      cassert(0);
   }

   // - define new data type -
   processor.data_types.push_blank();
   data_type_s &data_type = processor.data_types.last();

   data_type.name.set(str_length,str_data);
   data_type.real_name.set(str_length,str_data);
   data_type.properties = processor.type_settings;

   // - define data type abbreviation -
   processor.abbreviations.push_blank();
   abbreviation_s &abb = processor.abbreviations.last();

   abb.name.set(str_length,str_data);
   abb.data_type_idx = processor.data_types.used - 1;

   // - reset type_setting -
   processor.type_settings = 0;
}/*}}}*/

void process_s::pa_reduce_mod_basic(process_s &proc)
{/*{{{*/
   processor_s &processor = *proc.processor_ptr;

   // -----

   processor.type_settings = (processor.type_settings & c_type_byte_neg_mod_mask) | c_type_basic;
}/*}}}*/

void process_s::pa_reduce_mod_static(process_s &proc)
{/*{{{*/
   processor_s &processor = *proc.processor_ptr;

   // -----

   processor.type_settings = (processor.type_settings & c_type_byte_neg_mod_mask) | c_type_static;
}/*}}}*/

void process_s::pa_reduce_mod_dynamic(process_s &proc)
{/*{{{*/
   processor_s &processor = *proc.processor_ptr;

   // -----

   processor.type_settings = (processor.type_settings & c_type_byte_neg_mod_mask) | c_type_dynamic;
}/*}}}*/

void process_s::pa_reduce_mod_flushable(process_s &proc)
{/*{{{*/
   processor_s &processor = *proc.processor_ptr;

   // -----

   processor.type_settings |= c_type_flushable;
}/*}}}*/

void process_s::pa_reduce_gen_container(process_s &proc)
{/*{{{*/
   processor_s &processor = *proc.processor_ptr;
   string_s &code = proc.code;
   lalr_stack_element_s &lse = proc.lalr_stack[proc.lalr_stack.used - 3];

   // -----

   unsigned tmp_char_idx = lse.terminal_end;
   char tmp_char = code.data[tmp_char_idx];
   code.data[tmp_char_idx] = '\0';

   string_s cont_name;
   cont_name.size = lse.terminal_end - lse.terminal_start + 1;
   cont_name.data = code.data + lse.terminal_start;

   processor.generate_container_def(cont_name);
   code.data[tmp_char_idx] = tmp_char;

   processor.type_settings = 0;
   processor.cont_params.clean_out();
}/*}}}*/

void process_s::pa_reduce_type(process_s &proc)
{/*{{{*/
   processor_s &processor = *proc.processor_ptr;
   string_s &code = proc.code;
   lalr_stack_element_s &lse = proc.lalr_stack.last();

   // -----

   string_array_s &param = processor.cont_params.types;

   param.push_blank();
   param.last().set(lse.terminal_end - lse.terminal_start,code.data + lse.terminal_start);
}/*}}}*/

void process_s::pa_reduce_type_and_name(process_s &proc)
{/*{{{*/
   processor_s &processor = *proc.processor_ptr;
   string_s &code = proc.code;
   lalr_stack_element_s &t_lse = proc.lalr_stack[proc.lalr_stack.used - 3];
   lalr_stack_element_s &v_lse = proc.lalr_stack.last();

   // -----

   string_array_s &type_param = processor.cont_params.types;

   type_param.push_blank();
   type_param.last().set(t_lse.terminal_end - t_lse.terminal_start,code.data + t_lse.terminal_start);

   string_array_s &var_param = processor.cont_params.variables;

   var_param.push_blank();
   var_param.last().set(v_lse.terminal_end - v_lse.terminal_start,code.data + v_lse.terminal_start);
}/*}}}*/

void process_s::pa_reduce_not_generate_init(process_s &proc)
{/*{{{*/
   proc.processor_ptr->type_settings |= c_type_setting_not_generate_init;
}/*}}}*/

void process_s::pa_reduce_not_generate_clear(process_s &proc)
{/*{{{*/
   proc.processor_ptr->type_settings |= c_type_setting_not_generate_clear;
}/*}}}*/

void process_s::pa_reduce_not_generate_swap(process_s &proc)
{/*{{{*/
   proc.processor_ptr->type_settings |= c_type_setting_not_generate_swap;
}/*}}}*/

void process_s::pa_reduce_not_generate_operator_equal(process_s &proc)
{/*{{{*/
   proc.processor_ptr->type_settings |= c_type_setting_not_generate_operator_equal;
}/*}}}*/

void process_s::pa_reduce_option_strict_dynamic(process_s &proc)
{/*{{{*/
   proc.processor_ptr->type_settings |= c_type_setting_strict_dynamic;
}/*}}}*/

void process_s::pa_reduce_additions_body(process_s &proc)
{/*{{{*/
   processor_s &processor = *proc.processor_ptr;
   string_s &code = proc.code;
   lalr_stack_element_s &lse = proc.lalr_stack.last();

   // -----

   string_array_s &param = processor.cont_params.functions;
   
   param.push_blank();
   param.last().set((lse.terminal_end - lse.terminal_start) - 2,code.data + lse.terminal_start + 1);
}/*}}}*/

void process_s::pa_reduce_name(process_s &proc)
{/*{{{*/
   processor_s &processor = *proc.processor_ptr;
   string_s &code = proc.code;
   lalr_stack_element_s &lse = proc.lalr_stack.last();

   // -----

   string_array_s &param = processor.cont_params.names;
   
   param.push_blank();
   param.last().set(lse.terminal_end - lse.terminal_start,code.data + lse.terminal_start);
}/*}}}*/


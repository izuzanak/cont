
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



#ifndef __UCL_STRING_H
#define __UCL_STRING_H


#ifndef __BASIC_H
#define __BASIC_H

#define ENABLE 1

#if __cplusplus < 201103
#define nullptr NULL
#endif

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
inline void *crealloc(void *a_location,unsigned a_size);
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
  unsigned __binary_tree_insert(unsigned a_new_idx,mc_block_s &a_value,bool a_unique);

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
    * \brief __GEN insert node to rb_tree if it not exist yet
    * \param a_value - reference to value inserted to rb_tree
    * \return - position of node in rb_tree
    */
  inline unsigned unique_insert(mc_block_s &a_value);

  /*!
    * \brief __GEN insert node to rb_tree by swapping
    * \param a_value - reference to value inserted to rb_tree
    * \return - position of node in rb_tree
    */
  inline unsigned swap_insert(mc_block_s &a_value);

  /*!
    * \brief __GEN insert node to rb_tree by swapping if it not exist yet
    * \param a_value - reference to value inserted to rb_tree
    * \return - position of node in rb_tree
    */
  inline unsigned unique_swap_insert(mc_block_s &a_value);

  /*!
    * \brief __GEN remove node at index from rb_tree
    * \param a_idx - index of node to remove
    */
  void remove(unsigned a_idx);

  /*!
    * \brief __GEN resize rb_tree capacity
    * \param a_size - requested rb_tree capacity
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
       * \brief crealloc for mc_block_rb_tree_s structure overriding global
       *
       */
      inline void *crealloc(void *a_location,unsigned a_size);

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
       * \brief reallocate memory block to size a_size
       */
      inline void *reget_block(void *a_location,unsigned a_size);

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
  data = nullptr;
}/*}}}*/

inline void ui_array_s::init_size(unsigned a_size)
{/*{{{*/
  init();
  copy_resize(a_size);
}/*}}}*/

inline void ui_array_s::clear()
{/*{{{*/
  if (data != nullptr)
  {
    cfree(data);
  }

  init();
}/*}}}*/

inline void ui_array_s::set(unsigned a_used,unsigned *a_data)
{/*{{{*/
  debug_assert(a_data != nullptr);

  clear();

  if (a_used == 0)
  {
    return;
  }

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
  if (used >= size)
  {
    copy_resize((size << 1) + c_array_add);
  }

  data[used++] = a_value;
}/*}}}*/

inline void ui_array_s::push_blank()
{/*{{{*/
  if (used >= size)
  {
    copy_resize((size << 1) + c_array_add);
  }

  used++;
}/*}}}*/

inline void ui_array_s::push_clear()
{/*{{{*/
  if (used >= size)
  {
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

  if (a_src.used == 0)
  {
    return *this;
  }

  copy_resize(a_src.used);

  memcpy(data,a_src.data,a_src.used*sizeof(unsigned));

  used = a_src.used;
  return *this;
}/*}}}*/

inline bool ui_array_s::operator==(ui_array_s &a_second)
{/*{{{*/
  if (used != a_second.used)
  {
    return false;
  }

  if (used == 0)
  {
    return true;
  }

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

  if (node.parent_idx != c_idx_not_exist)
  {
    return data[node.parent_idx].parent_idx;
  }

  return c_idx_not_exist;
}/*}}}*/

inline unsigned mc_block_rb_tree_s::__get_uncle_idx(unsigned a_idx)
{/*{{{*/
  unsigned gp_idx = __get_grandparent_idx(a_idx);

  if (gp_idx != c_idx_not_exist)
  {
    mc_block_rb_tree_s_node &gp = data[gp_idx];
    return gp.left_idx == data[a_idx].parent_idx?gp.right_idx:gp.left_idx;
  }

  return c_idx_not_exist;
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

  if (node.right_idx != leaf_idx)
  {
    return get_stack_min_value_idx(node.right_idx,a_s_ptr);
  }

  if (*a_s_ptr > a_stack_base)
  {
    return *(--(*a_s_ptr));
  }

  return c_idx_not_exist;
}/*}}}*/

inline void mc_block_rb_tree_s::__rotate_left(unsigned a_idx)
{/*{{{*/
  mc_block_rb_tree_s_node &root = data[a_idx];
  mc_block_rb_tree_s_node &pivot = data[root.right_idx];

  if (a_idx == root_idx)
  {
    root_idx = root.right_idx;
    pivot.parent_idx = c_idx_not_exist;
  }
  else
  {
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

  if (a_idx == root_idx)
  {
    root_idx = root.left_idx;
    pivot.parent_idx = c_idx_not_exist;
  }
  else
  {
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

  if (free_idx != c_idx_not_exist)
  {
    new_idx = free_idx;
    free_idx = data[new_idx].parent_idx;
  }
  else
  {
    if (used >= size)
    {
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

  if (node.parent_idx != c_idx_not_exist)
  {
    mc_block_rb_tree_s_node &parent = data[node.parent_idx];
    (parent.left_idx == a_idx?parent.left_idx:parent.right_idx) = a_ch_idx;

    data[a_ch_idx].parent_idx = node.parent_idx;
  }
  else
  {
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

  if (node.color)
  {
    mc_block_rb_tree_s_node &child_node = data[a_ch_idx];

    if (!child_node.color)
    {
      child_node.color = true;
    }
    else
    {
      __remove_black_black(a_ch_idx);
    }
  }
}/*}}}*/

inline void mc_block_rb_tree_s::init()
{/*{{{*/
  size = 0;
  used = 0;
  count = 0;
  data = nullptr;
  free_idx = c_idx_not_exist;
  root_idx = c_idx_not_exist;
  leaf_idx = c_idx_not_exist;
}/*}}}*/

inline void mc_block_rb_tree_s::clear()
{/*{{{*/
  if (data != nullptr)
  {
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

inline unsigned mc_block_rb_tree_s::unique_insert(mc_block_s &a_value)
{/*{{{*/
  unsigned new_node_idx = __get_new_index();
  unsigned old_node_idx = __binary_tree_insert(new_node_idx,a_value,true);

  if (old_node_idx != c_idx_not_exist)
  {
    mc_block_rb_tree_s_node &new_node = data[new_node_idx];

    new_node.parent_idx = free_idx;
    free_idx = new_node_idx;

    new_node.valid = false;
    count--;

    return old_node_idx;
  }

  __insert_operation(new_node_idx);

  data[new_node_idx].object = a_value;

  return new_node_idx;
}/*}}}*/

inline unsigned mc_block_rb_tree_s::unique_swap_insert(mc_block_s &a_value)
{/*{{{*/
  unsigned new_node_idx = __get_new_index();
  unsigned old_node_idx = __binary_tree_insert(new_node_idx,a_value,true);

  if (old_node_idx != c_idx_not_exist)
  {
    mc_block_rb_tree_s_node &new_node = data[new_node_idx];

    new_node.parent_idx = free_idx;
    free_idx = new_node_idx;

    new_node.valid = false;
    count--;

    return old_node_idx;
  }

  __insert_operation(new_node_idx);

  data[new_node_idx].object.swap(a_value);

  return new_node_idx;
}/*}}}*/

inline mc_block_rb_tree_s &mc_block_rb_tree_s::operator=(mc_block_rb_tree_s &a_src)
{/*{{{*/
  clear();

  if (a_src.root_idx == c_idx_not_exist)
  {
    return *this;
  }

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

inline void *mc_block_rb_tree_s::crealloc(void *a_location,unsigned a_size)
{/*{{{*/
   return realloc(a_location,a_size);
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

inline void *mc_struct_s::reget_block(void *a_location,unsigned a_size)
{/*{{{*/
   mutex.lock();

   if (a_location != NULL)
   {
     mc_block_s mc_block = {a_location,0};
     unsigned idx = mc_block_set.get_idx(mc_block);
     cassert(idx != c_idx_not_exist);

     // - decrease size of allocated memory -
     act_alloc_size -= mc_block_set[idx].size;

     mc_block_set.remove(idx);
   }

   void *location = realloc(a_location,a_size);

   {
     mc_block_s mc_block = {location,a_size};
     mc_block_set.insert(mc_block);

     // - increase size of allocated memory -
     alloc_size += a_size;
     act_alloc_size += a_size;
     if (act_alloc_size > max_alloc_size) {
        max_alloc_size = act_alloc_size;
     }
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

inline void *crealloc(void *a_location,unsigned a_size)
{/*{{{*/
  return mc_struct.reget_block(a_location,a_size);
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

inline void *crealloc(void *a_location,unsigned a_size)
{/*{{{*/
   return realloc(a_location,a_size);
}/*}}}*/

inline void cfree(void *a_location)
{/*{{{*/
   free(a_location);
}/*}}}*/
#endif

#endif



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
   * \brief concatenate string of desired format
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
  if (a_length == 0) return;

  data = (char *)cmalloc((a_length + 1)*sizeof(char));

  data[a_length] = '\0';
  size = a_length + 1;
}/*}}}*/

inline void string_s::set(unsigned a_length,const char *a_data)
{/*{{{*/
  clear();
  if (a_length == 0) return;

  data = (char *)cmalloc((a_length + 1)*sizeof(char));
  memcpy(data,a_data,a_length*sizeof(char));

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
  if (used >= size)
  {
    copy_resize((size << 1) + c_array_add);
  }

  data[used++] = a_value;
}/*}}}*/

inline void string_array_s::push_blank()
{/*{{{*/
  if (used >= size)
  {
    copy_resize((size << 1) + c_array_add);
  }

  used++;
}/*}}}*/

inline void string_array_s::push_clear()
{/*{{{*/
  if (used >= size)
  {
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



/*
 * constants and definitions
 */

// - string terminating character -
const char c_string_terminating_char = '\0';

/*
 * methods of structure string_s
 */

void string_s::mult_char_ptr(unsigned a_length,const char *a_data,unsigned a_mult)
{/*{{{*/
  if (a_length == 0 || a_mult == 0)
  {
    clear();
    return;
  }

  create(a_length*a_mult);

  char *s_ptr = data;
  do
  {
    memcpy(s_ptr,a_data,a_length*sizeof(char));
  }
  while(s_ptr += a_length, --a_mult > 0);

}/*}}}*/

int string_s::utf8_to_utf32(char *a_src,unsigned *a_trg,unsigned a_size)
{/*{{{*/
  if (a_size == 0)
  {
    return 0;
  }

  unsigned char *s_ptr = (unsigned char *)a_src;
  unsigned char *s_ptr_end = s_ptr + a_size;
  unsigned *t_ptr = a_trg;
  do {

    if (*s_ptr <= 127)
    {
      *t_ptr = (unsigned)*s_ptr++;
    }
    else
    {
      unsigned char value = *s_ptr++ << 2;
      unsigned count = 2;
      unsigned code = *s_ptr++ & 0x3f;

      while (value & 0x80)
      {
        if ((*s_ptr & 0xc0) != 0x80)
        {
          return -1;
        }

        code |= (code << 6) | (*s_ptr++ & 0x3f);
        value <<= 1;
        count++;
      }

      *t_ptr = code | (value << (5*count - 6));
    }

  } while(++t_ptr,s_ptr < s_ptr_end);

  return t_ptr - a_trg;
}/*}}}*/

unsigned string_s::utf32_to_utf8(unsigned *a_src,char *a_trg,unsigned a_size)
{/*{{{*/
  if (a_size == 0)
  {
    return 0;
  }

  unsigned *s_ptr = a_src;
  unsigned *s_ptr_end = s_ptr + a_size;
  unsigned char *t_ptr = (unsigned char *)a_trg;
  do {
    register unsigned value = *s_ptr;

    if (value <= 0x7f)
    {
      *t_ptr++ = value;
      continue;
    }

    if (value <= 0x7ff)
    {
      t_ptr[0] = 0xc0 | value >> 6;
      t_ptr[1] = 0x80 | (value & 0x3f);
      t_ptr += 2;
      continue;
    }
    
    if (value <= 0xffff)
    {
      t_ptr[0] = 0xe0 |   value >> 12;
      t_ptr[1] = 0x80 | ((value >>  6) & 0x3f);
      t_ptr[2] = 0x80 |  (value        & 0x3f);
      t_ptr += 3;
      continue;
    }
    
    if (value <= 0x1fffff)
    {
      t_ptr[0] = 0xf0 |   value >> 18;
      t_ptr[1] = 0x80 | ((value >> 12) & 0x3f);
      t_ptr[2] = 0x80 | ((value >>  6) & 0x3f);
      t_ptr[3] = 0x80 |  (value        & 0x3f);
      t_ptr += 4;
      continue;
    }
    
    if (value <= 0x3ffffff)
    {
      t_ptr[0] = 0xf8 |   value >> 24;
      t_ptr[1] = 0x80 | ((value >> 18) & 0x3f);
      t_ptr[2] = 0x80 | ((value >> 12) & 0x3f);
      t_ptr[3] = 0x80 | ((value >>  6) & 0x3f);
      t_ptr[4] = 0x80 |  (value        & 0x3f);
      t_ptr += 5;
      continue;
    }
    
    if (value <= 0x7fffffff)
    {
      t_ptr[0] = 0xfc |   value >> 30;
      t_ptr[1] = 0x80 | ((value >> 24) & 0x3f);
      t_ptr[2] = 0x80 | ((value >> 18) & 0x3f);
      t_ptr[3] = 0x80 | ((value >> 12) & 0x3f);
      t_ptr[4] = 0x80 | ((value >>  6) & 0x3f);
      t_ptr[5] = 0x80 |  (value        & 0x3f);
      t_ptr += 6;
      continue;
    }
    
  } while(++s_ptr < s_ptr_end);

  return t_ptr - (unsigned char *)a_trg;
}/*}}}*/

void string_s::setf(const char *a_format,...)
{/*{{{*/
  clear();

  const int init_size = 256;
  int alloc_size = init_size;

  va_list ap;

  do
  {
    data = (char *)cmalloc(alloc_size*sizeof(char));

    va_start(ap,a_format);

#if SYSTEM_TYPE == SYSTEM_TYPE_DSP
    // DSP FIXME
    int cnt = vsprintf(data,a_format,ap);
#else
    int cnt = vsnprintf(data,alloc_size,a_format,ap);
#endif
    va_end(ap);

    if (cnt < alloc_size)
    {
      size = cnt + 1;
      break;
    }

    cfree(data);
    alloc_size <<= 1;

  }
  while(1);
}/*}}}*/

void string_s::concf(const char *a_format,...)
{/*{{{*/
  const int init_size = 256;
  int alloc_size = init_size;

  // - creation of formated string -
  string_s fmt_str;
  fmt_str.init();

  va_list ap;

  do
  {
    fmt_str.data = (char *)cmalloc(alloc_size*sizeof(char));

    va_start(ap,a_format);

#if SYSTEM_TYPE == SYSTEM_TYPE_DSP
    // DSP FIXME
    int cnt = vsprintf(fmt_str.data,a_format,ap);
#else
    int cnt = vsnprintf(fmt_str.data,alloc_size,a_format,ap);
#endif
    va_end(ap);

    if (cnt < alloc_size)
    {
      fmt_str.size = cnt + 1;
      break;
    }

    cfree(fmt_str.data);
    alloc_size <<= 1;

  }
  while(1);

  // - concatenation to result string -
  string_s res_str;
  res_str.init();
  res_str.conc_set(size - 1,data,fmt_str.size - 1,fmt_str.data);

  // - swap this string with result string -
  swap(res_str);

  // - clear temporary strings -
  res_str.clear();
  fmt_str.clear();
}/*}}}*/

unsigned string_s::get_idx(unsigned a_idx,unsigned a_length,const char *a_data)
{/*{{{*/
  if (a_idx >= (size - 1) || a_length >= (size - a_idx))
  {
    return c_idx_not_exist;
  }

  char *s_ptr = data + a_idx;
  char *s_ptr_end = data + (size - a_length);
  do
  {
    char *ss_ptr = s_ptr;
    char *ss_ptr_end = ss_ptr + a_length;
    const char *a_ptr = a_data;
    do
    {
      if (*ss_ptr != *a_ptr)
      {
        break;
      }

      if (++a_ptr,++ss_ptr >= ss_ptr_end)
      {
        return s_ptr - data;
      }
    }
    while(1);

  }
  while(++s_ptr < s_ptr_end);

  return c_idx_not_exist;
}/*}}}*/

unsigned string_s::get_print_size_between(unsigned f_idx,unsigned s_idx)
{/*{{{*/
  debug_assert(f_idx < size && s_idx < size);

  if (f_idx >= s_idx) return 0;

  unsigned char_cnt = s_idx - f_idx;
  unsigned utf32_data[char_cnt];

  int utf32_cnt = utf8_to_utf32(data + f_idx,utf32_data,char_cnt);
  if (utf32_cnt < 0) return 0;

  unsigned *c_ptr = utf32_data;
  unsigned *c_ptr_end = c_ptr + utf32_cnt;
  unsigned print_size = 0;

  do
  {
    if (*c_ptr == '\t')
    {
      print_size += c_tabulator_size;
    }
    else
    {
      print_size++;
    }
  }
  while(++c_ptr < c_ptr_end);

  return print_size;
}/*}}}*/

unsigned string_s::get_character_line(unsigned c_idx)
{/*{{{*/
  if (size <= c_idx) return 0;

  char *c_ptr = data;
  char *c_ptr_end = c_ptr + c_idx;
  unsigned line_cnt = 1;

  do
  {
    if (*c_ptr == '\n')
    {
      line_cnt++;
    }
  }
  while(++c_ptr < c_ptr_end);

  return line_cnt;
}/*}}}*/

unsigned string_s::get_character_line_begin(unsigned c_idx)
{/*{{{*/
  char *s_ptr = data + c_idx;

  do
  {
    if (*s_ptr == '\n')
    {
      break;
    }
  }
  while(--s_ptr >= data);

  return (s_ptr - data) + 1;
}/*}}}*/

unsigned string_s::get_character_line_end(unsigned c_idx)
{/*{{{*/
  char *e_ptr = data + c_idx;
  char *e_ptr_end = data + size - 1;

  while(e_ptr < e_ptr_end)
  {
    if (*e_ptr == '\n')
    {
      break;
    }

    ++e_ptr;
  }

  return e_ptr - data;
}/*}}}*/

/*
 * methods of generated structures
 */

// -- string_array_s --
// --- struct string_array_s method definition ---

void string_array_s::clear()
{/*{{{*/
  if (data != nullptr)
  {
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
  debug_assert(a_data != nullptr);

  clear();

  if (a_used == 0)
  {
    return;
  }

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
  if (required_cnt > size)
  {
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
  if (required_cnt > size)
  {
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

  if (size > a_size)
  {
    string_s *ptr = data + a_size;
    string_s *ptr_end = data + size;

    do {
      ptr->clear();
    } while(++ptr < ptr_end);
  }

  if (a_size == 0)
  {
    if (data != nullptr)
    {
      cfree(data);
    }
    data = nullptr;
  }
  else
  {
    data = (string_s *)crealloc(data,a_size*sizeof(string_s));
  }

  if (a_size > size)
  {
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
  if (size == 0)
  {
    return;
  }

  string_s *ptr = data;
  string_s *ptr_end = data + size;

  do {
    *ptr = a_value;
  } while(++ptr < ptr_end);

  used = size;
}/*}}}*/

unsigned string_array_s::get_idx(string_s &a_value)
{/*{{{*/
  if (used == 0)
  {
    return c_idx_not_exist;
  }

  string_s *ptr = data;
  string_s *ptr_end = data + used;

  do {
    if (*ptr == a_value)
    {
      return ptr - data;
    }
  } while(++ptr < ptr_end);

  return c_idx_not_exist;
}/*}}}*/

string_array_s &string_array_s::operator=(string_array_s &a_src)
{/*{{{*/
  clear();

  if (a_src.used == 0)
  {
    return *this;
  }

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
  if (used != a_second.used)
  {
    return false;
  }

  if (used == 0)
  {
    return true;
  }

  string_s *ptr = data;
  string_s *ptr_end = ptr + used;
  string_s *s_ptr = a_second.data;

  do {
    if (!(*ptr == *s_ptr))
    {
      return false;
    }
  } while(++s_ptr,++ptr < ptr_end);

  return true;
}/*}}}*/




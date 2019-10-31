
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



#ifndef __MEM_CHECK_H
#define __MEM_CHECK_H


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

// - thread library selection -
#define THREAD_LIB_PTHREAD 1 // - for thread manipulation use pthread library
#define THREAD_LIB_DSP_TSK 2 // - for thread implementation use DSP Task library
// --

// - basic system configuration -
#if defined(__linux__) || defined(__APPLE__) || (defined(__CYGWIN__) && !defined(_WIN32))
#define SYSTEM_TYPE SYSTEM_TYPE_UNIX
#define MUTEX_TYPE MUTEX_TYPE_PTHREAD
#define EXPORT
#elif defined(_WIN32)
#define _WIN32_WINNT 0x0500
#define SYSTEM_TYPE SYSTEM_TYPE_WINDOWS
#define MUTEX_TYPE MUTEX_TYPE_WINDOWS
#define EXPORT __declspec(dllexport) 
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
const float c_pi_number = 3.14159265358979323844f;
const float c_2pi_number = 6.28318530717958647688f;
const float c_pid2_number = 1.57079632679489661922f;

// - logarithm of two (needed by red-black tree container) -
const float c_log_of_2 = logf(2.0f);

// - red-black tree descent stack size -
#ifdef _MSC_VER
#define RB_TREE_STACK_SIZE(VAR) 32
#else
#define RB_TREE_STACK_SIZE(VAR) (VAR).get_descent_stack_size()
#endif

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

#if defined(__APPLE__) || (defined(__CYGWIN__) && !defined(_WIN32))
   pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE);
#else
   pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE_NP);
#endif

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
   if ((handle = CreateMutex(nullptr,FALSE,nullptr)) == nullptr) {
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
  EXPORT void reserve(unsigned a_cnt);

  /*!
    * \brief __GEN insert blank elements to end of array
    * \param a_cnt - count of elements inserted to array
    */
  EXPORT void push_blanks(unsigned a_cnt);

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
  EXPORT void copy_resize(unsigned a_size);

  /*!
    * \brief __GEN set all elements of array to given value
    * \param a_value - new value of all elements
    */
  EXPORT void fill(unsigned a_value);

  /*!
    * \brief __GEN search for index of element
    * \param a_value - value which index is searched
    */
  EXPORT unsigned get_idx(unsigned a_value);

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
  unsigned parent_idx;
  unsigned left_idx;
  unsigned right_idx;
  bool color;
  bool valid;
  mc_block_s object;
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
  EXPORT unsigned get_stack_min_value_idx(unsigned a_idx,unsigned **a_s_ptr);
  inline unsigned get_stack_next_idx(unsigned a_idx,unsigned **a_s_ptr,unsigned *a_stack_base);

  EXPORT unsigned get_min_value_idx(unsigned a_idx);
  EXPORT unsigned get_max_value_idx(unsigned a_idx);
  EXPORT unsigned get_next_idx(unsigned a_idx);
  EXPORT unsigned get_prev_idx(unsigned a_idx);

  inline void __rotate_left(unsigned a_idx);
  inline void __rotate_right(unsigned a_idx);

  inline unsigned __get_new_index();
  EXPORT unsigned __binary_tree_insert(unsigned a_new_idx,mc_block_s &a_value,bool a_unique);

  inline void __replace_delete_node_by_child(unsigned a_idx,unsigned a_ch_idx);
  void __remove_black_black(unsigned a_idx);

  inline void __remove_one_child(unsigned a_idx,unsigned a_ch_idx);

  EXPORT void __insert_operation(unsigned a_idx);

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
  EXPORT void remove(unsigned a_idx);

  /*!
    * \brief __GEN resize rb_tree capacity
    * \param a_size - requested rb_tree capacity
    */
  EXPORT void copy_resize(unsigned a_size);

  /*!
    * \brief __GEN search for index of node
    * \param a_value - value which index is searched
    */
  EXPORT unsigned get_idx(mc_block_s &a_value);

  /*!
    * \brief __GEN search for leftmost index of node
    * \param a_value - value which index is searched
    */
  EXPORT unsigned get_idx_left(mc_block_s &a_value);

  /*!
    * \brief __GEN search for index of node with greater or equal value
    * \param a_value - value which index is searched
    */
  EXPORT unsigned get_gre_idx(mc_block_s &a_value);

  /*!
    * \brief __GEN search for index of node with less or equal value
    * \param a_value - value which index is searched
    */
  EXPORT unsigned get_lee_idx(mc_block_s &a_value);

  /*!
    * \brief __GEN search for all indexes of node
    * \param a_value - value of searched index
    */
  EXPORT void get_idxs(mc_block_s &a_value,ui_array_s &a_idxs_array);

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
  EXPORT bool operator==(mc_block_rb_tree_s &a_second);

  
      
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

  size = 0;
  used = 0;
  count = 0;
  data = nullptr;
  free_idx = c_idx_not_exist;
  root_idx = c_idx_not_exist;
  leaf_idx = c_idx_not_exist;
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

   if (a_location != nullptr)
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
 * methods of generated structures
 */

// -- ui_array_s --
// --- struct ui_array_s method definition ---

void ui_array_s::reserve(unsigned a_cnt)
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

void ui_array_s::push_blanks(unsigned a_cnt)
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

void ui_array_s::copy_resize(unsigned a_size)
{/*{{{*/
  debug_assert(a_size >= used);

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
    data = (unsigned *)crealloc(data,a_size*sizeof(unsigned));
  }

  size = a_size;
}/*}}}*/

void ui_array_s::fill(unsigned a_value)
{/*{{{*/
  if (size == 0)
  {
    return;
  }

  unsigned *ptr = data;
  unsigned *ptr_end = data + size;

  do {
    *ptr = a_value;
  } while(++ptr < ptr_end);

  used = size;
}/*}}}*/

unsigned ui_array_s::get_idx(unsigned a_value)
{/*{{{*/
  if (used == 0)
  {
    return c_idx_not_exist;
  }

  unsigned *ptr = data;
  unsigned *ptr_end = data + used;

  do {
    if (*ptr == a_value)
    {
      return ptr - data;
    }
  } while(++ptr < ptr_end);

  return c_idx_not_exist;
}/*}}}*/



#if MEM_CHECK == ENABLE

// -- mc_block_s --
// --- struct mc_block_s method definition ---



// -- mc_block_rb_tree_s --
// --- struct mc_block_rb_tree_s method definition ---

unsigned mc_block_rb_tree_s::get_stack_min_value_idx(unsigned a_idx,unsigned **a_s_ptr)
{/*{{{*/
  debug_assert(a_idx < used && data[a_idx].valid);

  unsigned node_idx = a_idx;
  do {
    mc_block_rb_tree_s_node &node = data[node_idx];

    if (node.left_idx == leaf_idx)
    {
      return node_idx;
    }

    *((*a_s_ptr)++) = node_idx;
    node_idx = node.left_idx;
  } while(1);
}/*}}}*/

unsigned mc_block_rb_tree_s::get_min_value_idx(unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < used && data[a_idx].valid);

  unsigned node_idx = a_idx;
  do {
    mc_block_rb_tree_s_node &node = data[node_idx];

    if (node.left_idx == leaf_idx)
    {
      return node_idx;
    }

    node_idx = node.left_idx;
  } while(1);
}/*}}}*/

unsigned mc_block_rb_tree_s::get_max_value_idx(unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < used && data[a_idx].valid);

  unsigned node_idx = a_idx;
  do {
    mc_block_rb_tree_s_node &node = data[node_idx];

    if (node.right_idx == leaf_idx)
    {
      return node_idx;
    }

    node_idx = node.right_idx;
  } while(1);
}/*}}}*/

unsigned mc_block_rb_tree_s::get_next_idx(unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < used && data[a_idx].valid);

  mc_block_rb_tree_s_node &node = data[a_idx];

  if (node.right_idx != leaf_idx)
  {
    return get_min_value_idx(node.right_idx);
  }

  unsigned node_idx = a_idx;
  do {
    mc_block_rb_tree_s_node &node = data[node_idx];

    if (node.parent_idx == c_idx_not_exist)
    {
      return c_idx_not_exist;
    }

    if (data[node.parent_idx].right_idx != node_idx)
    {
      return node.parent_idx;
    }

    node_idx = node.parent_idx;
  } while(1);
}/*}}}*/

unsigned mc_block_rb_tree_s::get_prev_idx(unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < used && data[a_idx].valid);

  mc_block_rb_tree_s_node &node = data[a_idx];

  if (node.left_idx != leaf_idx)
  {
    return get_max_value_idx(node.left_idx);
  }

  unsigned node_idx = a_idx;
  do {
    mc_block_rb_tree_s_node &node = data[node_idx];

    if (node.parent_idx == c_idx_not_exist)
    {
      return c_idx_not_exist;
    }

    if (data[node.parent_idx].left_idx != node_idx)
    {
      return node.parent_idx;
    }

    node_idx = node.parent_idx;
  } while(1);
}/*}}}*/

unsigned mc_block_rb_tree_s::__binary_tree_insert(unsigned a_new_idx,mc_block_s &a_value,bool a_unique)
{/*{{{*/
  if (root_idx == c_idx_not_exist)
  {
    if (leaf_idx == c_idx_not_exist)
    {
      leaf_idx = __get_new_index();
      mc_block_rb_tree_s_node &leaf = data[leaf_idx];

      leaf.valid = false;
      leaf.color = true;
      count--;
    }

    data[a_new_idx].parent_idx = c_idx_not_exist;
    root_idx = a_new_idx;
  }
  else
  {
    unsigned node_idx = root_idx;
    do {
      mc_block_rb_tree_s_node &node = data[node_idx];

      int comp_result = __compare_value(a_value,node.object);
      if (comp_result < 0)
      {
        if (node.left_idx == leaf_idx)
        {
          node.left_idx = a_new_idx;
          break;
        }
        node_idx = node.left_idx;
      }
      else
      {
        if (a_unique && comp_result == 0)
        {
          return node_idx;
        }

        if (node.right_idx == leaf_idx)
        {
          node.right_idx = a_new_idx;
          break;
        }
        node_idx = node.right_idx;
      }
    } while(1);

    data[a_new_idx].parent_idx = node_idx;
  }

  mc_block_rb_tree_s_node &new_node = data[a_new_idx];
  new_node.left_idx = leaf_idx;
  new_node.right_idx = leaf_idx;
  new_node.color = false;

  return c_idx_not_exist;
}/*}}}*/

void mc_block_rb_tree_s::__remove_black_black(unsigned a_idx)
{/*{{{*/
  unsigned node_idx = a_idx;
  do {
    mc_block_rb_tree_s_node &node = data[node_idx];

    if (node.parent_idx == c_idx_not_exist)
    {
      return;
    }

    unsigned parent_idx = node.parent_idx;
    mc_block_rb_tree_s_node &parent = data[parent_idx];

    {
      unsigned sibling_idx = parent.left_idx == node_idx?parent.right_idx:parent.left_idx;
      mc_block_rb_tree_s_node &sibling = data[sibling_idx];

      if (!sibling.color)
      {
        parent.color = false;
        sibling.color = true;

        if (node_idx == parent.left_idx)
        {
          __rotate_left(parent_idx);
        }
        else
        {
          __rotate_right(parent_idx);
        }
      }
    }

    {
      unsigned sibling_idx = parent.left_idx == node_idx?parent.right_idx:parent.left_idx;
      mc_block_rb_tree_s_node& sibling = data[sibling_idx];

      if (parent.color && sibling.color && data[sibling.left_idx].color && data[sibling.right_idx].color)
      {
        sibling.color = false;
        node_idx = parent_idx;
        continue;
      }
      else if (!parent.color && sibling.color && data[sibling.left_idx].color && data[sibling.right_idx].color)
      {
        sibling.color = false;
        parent.color = true;
        return;
      }
      else if (sibling.color)
      {
        if (node_idx == parent.left_idx && data[sibling.right_idx].color && !data[sibling.left_idx].color)
        {
          sibling.color = false;
          data[sibling.left_idx].color = true;
          __rotate_right(sibling_idx);
        }
        else if (node_idx == parent.right_idx && data[sibling.left_idx].color && !data[sibling.right_idx].color)
        {
          sibling.color = false;
          data[sibling.right_idx].color = true;
          __rotate_left(sibling_idx);
        }
      }

      {
        unsigned sibling_idx = parent.left_idx == node_idx?parent.right_idx:parent.left_idx;
        mc_block_rb_tree_s_node &sibling = data[sibling_idx];

        sibling.color = parent.color;
        parent.color = true;

        if (node_idx == parent.left_idx)
        {
          data[sibling.right_idx].color = true;
          __rotate_left(parent_idx);
        }
        else
        {
          data[sibling.left_idx].color = true;
          __rotate_right(parent_idx);
        }
      }

      return;
    }

  } while(1);
}/*}}}*/

void mc_block_rb_tree_s::__insert_operation(unsigned a_idx)
{/*{{{*/
  unsigned node_idx = a_idx;
  do {
    mc_block_rb_tree_s_node &node = data[node_idx];

    if (node.parent_idx == c_idx_not_exist)
    {
      node.color = true;
      return;
    }

    if (data[node.parent_idx].color)
    {
      return;
    }

    unsigned uncle_idx = __get_uncle_idx(node_idx);
    if (uncle_idx != c_idx_not_exist && !data[uncle_idx].color)
    {
      data[node.parent_idx].color = true;
      data[uncle_idx].color = true;

      node_idx = __get_grandparent_idx(node_idx);
      data[node_idx].color = false;

      continue;
    }
    else
    {
      unsigned grandparent_idx = __get_grandparent_idx(node_idx);

      if (node_idx == data[node.parent_idx].right_idx && node.parent_idx == data[grandparent_idx].left_idx)
      {
        __rotate_left(node.parent_idx);
        node_idx = node.left_idx;
      }
      else if (node_idx == data[node.parent_idx].left_idx && node.parent_idx == data[grandparent_idx].right_idx)
      {
        __rotate_right(node.parent_idx);
        node_idx = node.right_idx;
      }

      {
        unsigned grandparent_idx = __get_grandparent_idx(node_idx);
        mc_block_rb_tree_s_node &node = data[node_idx];

        data[node.parent_idx].color = true;
        data[grandparent_idx].color = false;

        if (node_idx == data[node.parent_idx].left_idx && node.parent_idx == data[grandparent_idx].left_idx)
        {
          __rotate_right(grandparent_idx);
        }
        else
        {
          __rotate_left(grandparent_idx);
        }
      }

      return;
    }
  } while(1);
}/*}}}*/

void mc_block_rb_tree_s::remove(unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < used && data[a_idx].valid);

  mc_block_rb_tree_s_node &del_node = data[a_idx];

  if (del_node.left_idx != leaf_idx)
  {
    if (del_node.right_idx != leaf_idx)
    {
      unsigned found_idx = del_node.right_idx;
      do {
        mc_block_rb_tree_s_node &node = data[found_idx];

        if (node.left_idx == leaf_idx)
        {
          break;
        }

        found_idx = node.left_idx;
      } while(1);

      mc_block_rb_tree_s_node &found_node = data[found_idx];

      /* - process del_node parent_idx - */
      if (del_node.parent_idx != c_idx_not_exist)
      {
        mc_block_rb_tree_s_node &del_node_parent = data[del_node.parent_idx];
        (del_node_parent.left_idx == a_idx?del_node_parent.left_idx:del_node_parent.right_idx) = found_idx;
      }
      else
      {
        root_idx = found_idx;
      }

      /* - process del_node left_idx - */
      data[del_node.left_idx].parent_idx = found_idx;

      /* - process found_node right_idx - */
      if (found_node.right_idx != leaf_idx)
      {
        data[found_node.right_idx].parent_idx = a_idx;
      }

      if (del_node.right_idx == found_idx)
      {
        /* - found node is right child of deleted node - */
        del_node.right_idx = found_node.right_idx;
        found_node.right_idx = a_idx;

        found_node.parent_idx = del_node.parent_idx;
        del_node.parent_idx = found_idx;

        found_node.left_idx = del_node.left_idx;
        del_node.left_idx = leaf_idx;

        bool tmp_bool = found_node.color;
        found_node.color = del_node.color;
        del_node.color = tmp_bool;
      }
      else
      {
        /* - process found_node parent - */
        mc_block_rb_tree_s_node &found_node_parent = data[found_node.parent_idx];
        (found_node_parent.left_idx == found_idx?found_node_parent.left_idx:found_node_parent.right_idx) = a_idx;

        /* - process del_node right_idx - */
        data[del_node.right_idx].parent_idx = found_idx;

        /* - swap index pointers between nodes - */
        unsigned tmp_unsigned = found_node.parent_idx;
        found_node.parent_idx = del_node.parent_idx;
        del_node.parent_idx = tmp_unsigned;

        found_node.left_idx = del_node.left_idx;
        del_node.left_idx = leaf_idx;

        tmp_unsigned = found_node.right_idx;
        found_node.right_idx = del_node.right_idx;
        del_node.right_idx = tmp_unsigned;

        bool tmp_bool = found_node.color;
        found_node.color = del_node.color;
        del_node.color = tmp_bool;
      }

      __remove_one_child(a_idx,del_node.right_idx);
    }
    else
    {
      __remove_one_child(a_idx,del_node.left_idx);
    }
  }
  else
  {
    __remove_one_child(a_idx,del_node.right_idx);
  }

}/*}}}*/

void mc_block_rb_tree_s::copy_resize(unsigned a_size)
{/*{{{*/
  debug_assert(a_size >= used);

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
    data = (mc_block_rb_tree_s_node *)crealloc(data,a_size*sizeof(mc_block_rb_tree_s_node));
  }

  size = a_size;
}/*}}}*/

unsigned mc_block_rb_tree_s::get_idx(mc_block_s &a_value)
{/*{{{*/
  if (root_idx == c_idx_not_exist)
  {
    return c_idx_not_exist;
  }

  unsigned node_idx = root_idx;
  do {
    mc_block_rb_tree_s_node &node = data[node_idx];

    int comp_result = __compare_value(a_value,node.object);
    if (comp_result < 0)
    {
      node_idx = node.left_idx;
    }
    else
    {
      if (comp_result == 0)
      {
        return node_idx;
      }

      node_idx = node.right_idx;
    }
  } while(node_idx != leaf_idx);

  return c_idx_not_exist;
}/*}}}*/

unsigned mc_block_rb_tree_s::get_idx_left(mc_block_s &a_value)
{/*{{{*/
  if (root_idx == c_idx_not_exist)
  {
    return c_idx_not_exist;
  }

  unsigned good_idx = c_idx_not_exist;
  unsigned node_idx = root_idx;
  do {
    mc_block_rb_tree_s_node &node = data[node_idx];

    int comp_result = __compare_value(a_value,node.object);
    if (comp_result < 0)
    {
      node_idx = node.left_idx;
    }
    else
    {
      if (comp_result == 0)
      {
        good_idx = node_idx;
        node_idx = node.left_idx;
      }
      else
      {
        node_idx = node.right_idx;
      }
    }
  } while(node_idx != leaf_idx);

  return good_idx;
}/*}}}*/

unsigned mc_block_rb_tree_s::get_gre_idx(mc_block_s &a_value)
{/*{{{*/
  if (root_idx == c_idx_not_exist)
  {
    return c_idx_not_exist;
  }

  unsigned good_idx = c_idx_not_exist;
  unsigned node_idx = root_idx;
  do {
    mc_block_rb_tree_s_node &node = data[node_idx];

    int comp_result = __compare_value(a_value,node.object);
    if (comp_result < 0)
    {
      good_idx = node_idx;
      node_idx = node.left_idx;
    }
    else
    {
      if (comp_result == 0)
      {
        return node_idx;
      }

      node_idx = node.right_idx;
    }
  } while(node_idx != leaf_idx);

  return good_idx;
}/*}}}*/

unsigned mc_block_rb_tree_s::get_lee_idx(mc_block_s &a_value)
{/*{{{*/
  if (root_idx == c_idx_not_exist)
  {
    return c_idx_not_exist;
  }

  unsigned good_idx = c_idx_not_exist;
  unsigned node_idx = root_idx;
  do {
    mc_block_rb_tree_s_node &node = data[node_idx];

    int comp_result = __compare_value(a_value,node.object);
    if (comp_result < 0)
    {
      node_idx = node.left_idx;
    }
    else
    {
      if (comp_result == 0)
      {
        return node_idx;
      }

      good_idx = node_idx;
      node_idx = node.right_idx;
    }
  } while(node_idx != leaf_idx);

  return good_idx;
}/*}}}*/

void mc_block_rb_tree_s::get_idxs(mc_block_s &a_value,ui_array_s &a_idxs_array)
{/*{{{*/
  a_idxs_array.used = 0;

  if (root_idx == c_idx_not_exist)
  {
    return;
  }

  unsigned stack[RB_TREE_STACK_SIZE(*this)];
  unsigned *stack_ptr = stack;

  *(stack_ptr++) = root_idx;
  do {
    unsigned node_idx = *(--stack_ptr);
    mc_block_rb_tree_s_node &node = data[node_idx];

    int comp_result = __compare_value(a_value,node.object);
    if (comp_result < 0)
    {
      if (node.left_idx != leaf_idx)
      {
        *(stack_ptr++) = node.left_idx;
      }
    }
    else
    {
      if (comp_result == 0)
      {
        a_idxs_array.push(node_idx);

        if (node.left_idx != leaf_idx)
        {
          *(stack_ptr++) = node.left_idx;
        }
      }

      if (node.right_idx != leaf_idx)
      {
        *(stack_ptr++) = node.right_idx;
      }
    }
  } while(stack_ptr > stack);

  return;
}/*}}}*/

bool mc_block_rb_tree_s::operator==(mc_block_rb_tree_s &a_second)
{/*{{{*/
  if (count != a_second.count)
  {
     return false;
  }

  if (root_idx == c_idx_not_exist)
  {
    if (a_second.root_idx != c_idx_not_exist)
    {
      return false;
    }
  }
  else
  {
    if (a_second.root_idx == c_idx_not_exist)
    {
      return false;
    }

    unsigned stack[RB_TREE_STACK_SIZE(*this)];
    unsigned s_stack[RB_TREE_STACK_SIZE(a_second)];

    unsigned *stack_ptr = stack;
    unsigned *s_stack_ptr = s_stack;

    unsigned node_idx = get_stack_min_value_idx(root_idx,&stack_ptr);
    unsigned s_node_idx = a_second.get_stack_min_value_idx(a_second.root_idx,&s_stack_ptr);
    do {
      if (!(data[node_idx].object == a_second.data[s_node_idx].object))
      {
        return false;
      }

      node_idx = get_stack_next_idx(node_idx,&stack_ptr,stack);
      s_node_idx = a_second.get_stack_next_idx(s_node_idx,&s_stack_ptr,s_stack);
    } while(node_idx != c_idx_not_exist && s_node_idx != c_idx_not_exist);

    if (node_idx != s_node_idx)
    {
      return false;
    }
  }

  return true;
}/*}}}*/



// -- mc_struct_s --
// --- struct mc_struct_s method definition ---



void mc_struct_s::check()
{/*{{{*/

   // - print info about allocated memory -
   fprintf(stderr,"actually allocated memory: %4.3f KB\nallocated memory: %4.3f KB\nmax used memory: %4.3f KB\n",act_alloc_size/1024.0,alloc_size/1024.0,max_alloc_size/1024.0);

   // - test if all blocks was released -
   if (mc_block_set.root_idx == c_idx_not_exist) {
      return;
   }

   if (mc_block_set.count != 0)
   {
     unsigned stack[RB_TREE_STACK_SIZE(mc_block_set)];
     unsigned *stack_ptr = stack;

     unsigned idx = mc_block_set.get_stack_min_value_idx(mc_block_set.root_idx,&stack_ptr);

     do
     {
       mc_block_s &mc_block = mc_block_set[idx];

       fprintf(stderr,"MEM_CHECK: unreleased memory at: %lu, of size: %u\n",(unsigned long)mc_block.location,mc_block.size);
       free(mc_block.location);

       idx = mc_block_set.get_stack_next_idx(idx,&stack_ptr,stack);
     }
     while(idx != c_idx_not_exist);
   }
}/*}}}*/

mc_struct_s mc_struct;
#endif


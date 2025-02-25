

#ifndef CONT_PROCESSOR_H
#define CONT_PROCESSOR_H


#ifndef CONT_BASIC_H
#define CONT_BASIC_H

#define ENABLE 1

#ifdef _MSC_VER
#if _MSC_VER < 1600
#define nullptr NULL
#endif
#else
#if __cplusplus < 201103
#define nullptr NULL
#endif
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


#ifndef CONT_MEM_CHECK_H
#define CONT_MEM_CHECK_H


#ifndef CONT_MUTEX_H
#define CONT_MUTEX_H



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

  ui_array_s() = default;
  ui_array_s(ui_array_s &a_src) = delete;

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

  mc_block_s() = default;
  mc_block_s(mc_block_s &a_src) = delete;

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
  inline unsigned get_stack_next_idx(unsigned a_idx,unsigned **a_s_ptr,const unsigned *a_stack_base);

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

  mc_block_rb_tree_s() = default;
  mc_block_rb_tree_s(mc_block_rb_tree_s &a_src) = delete;

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

  mc_struct_s() = default;
  mc_struct_s(mc_struct_s &a_src) = delete;

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
// LCOV_EXCL_START

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
    unsigned new_size = (size << 1) + c_array_add;
    debug_assert(new_size != 0);

    copy_resize(new_size);
  }

  data[used++] = a_value;
}/*}}}*/

inline void ui_array_s::push_blank()
{/*{{{*/
  if (used >= size)
  {
    unsigned new_size = (size << 1) + c_array_add;
    debug_assert(new_size != 0);

    copy_resize(new_size);
  }

  used++;
}/*}}}*/

inline void ui_array_s::push_clear()
{/*{{{*/
  if (used >= size)
  {
    unsigned new_size = (size << 1) + c_array_add;
    debug_assert(new_size != 0);

    copy_resize(new_size);
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

// LCOV_EXCL_STOP



#if MEM_CHECK == ENABLE

// -- mc_block_s --
// --- struct mc_block_s inline method definition ---
// LCOV_EXCL_START

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

// LCOV_EXCL_STOP



// -- mc_block_rb_tree_s --
// --- struct mc_block_rb_tree_s inline method definition ---
// LCOV_EXCL_START

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

inline unsigned mc_block_rb_tree_s::get_stack_next_idx(unsigned a_idx,unsigned **a_s_ptr,const unsigned *a_stack_base)
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
      unsigned new_size = (size << 1) + c_array_add;
      debug_assert(new_size != 0);

      copy_resize(new_size);
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

  debug_assert(a_src.used != 0);
  copy_resize(a_src.used);

  memcpy(data,a_src.data,a_src.used*sizeof(mc_block_rb_tree_s_node));

  used = a_src.used;
  count = a_src.count;
  free_idx = a_src.free_idx;
  root_idx = a_src.root_idx;
  leaf_idx = a_src.leaf_idx;

  return *this;
}/*}}}*/

// LCOV_EXCL_STOP



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
// LCOV_EXCL_START

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

// LCOV_EXCL_STOP



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


#ifndef CONT_UCL_STRING_H
#define CONT_UCL_STRING_H



/*
 * constants and definitions
 */

// - string terminating character -
EXPORT extern const char c_string_terminating_char;

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
  EXPORT void mult_char_ptr(unsigned a_length,const char *a_data,unsigned a_mult);

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
  EXPORT void setf(const char *a_format,...);

  /*!
   * \brief find position of given string in string from given index
   * \param a_idx - position from which is substring searched
   * \param a_length - length of searched string
   * \param a_data - data of searched string
   */
  EXPORT unsigned get_idx(unsigned a_idx,unsigned a_length,const char *a_data);

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
  EXPORT unsigned get_character_line(unsigned c_idx);

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

  string_array_s() = default;
  string_array_s(string_array_s &a_src) = delete;

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
  EXPORT void clear();

  /*!
    * \brief __GEN set array content from element pointer
    * \param a_used - number of elements stored at pointed location
    * \param a_data - pointer to elements
    */
  EXPORT void set(unsigned a_used,string_s *a_data);

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
  EXPORT void copy_resize(unsigned a_size);

  /*!
    * \brief __GEN set all elements of array to given value
    * \param a_value - new value of all elements
    */
  EXPORT void fill(string_s &a_value);

  /*!
    * \brief __GEN search for index of element
    * \param a_value - value which index is searched
    */
  EXPORT unsigned get_idx(string_s &a_value);

  /*!
    * \brief __GEN copy array from another array
    * \param a_src - reference to another array
    */
  EXPORT string_array_s &operator=(string_array_s &a_src);

  /*!
    * \brief __GEN comparison of array with another array
    * \param a_second - reference to another array
    * \return result of comparison
    */
  EXPORT bool operator==(string_array_s &a_second);

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

  if (a_length == 0)
  {
    return;
  }

  data = (char *)cmalloc((a_length + 1)*sizeof(char));

  data[a_length] = '\0';
  size = a_length + 1;
}/*}}}*/

inline void string_s::set(unsigned a_length,const char *a_data)
{/*{{{*/
  clear();

  if (a_length == 0)
  {
    return;
  }

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

  if (a_src.data == &c_string_terminating_char)
  {
    return *this;
  }

  data = (char *)cmalloc(a_src.size*sizeof(char));
  memcpy(data,a_src.data,(a_src.size - 1)*sizeof(char));
  data[a_src.size - 1] = '\0';
  size = a_src.size;

  return *this;
}/*}}}*/

inline bool string_s::operator==(string_s &a_second)
{/*{{{*/
  if (size != a_second.size) { return false; }
  if (data == &c_string_terminating_char) { return true; }
  return (memcmp(data,a_second.data,(size - 1)*sizeof(char)) == 0);
}/*}}}*/

inline bool string_s::compare_char_ptr(unsigned a_length,const char *a_data)
{/*{{{*/
  if (size != a_length + 1) { return false; }
  if (a_length == 0) { return true; }
  return (memcmp(data,a_data,a_length*sizeof(char)) == 0);
}/*}}}*/

inline unsigned string_s::print()
{/*{{{*/
  return fwrite(data,size - 1,1,stdout);
}/*}}}*/

inline bool string_s::load_text_file(const char *a_file)
{/*{{{*/
  if (a_file == nullptr)
  {
    return false;
  }

  FILE *f = fopen(a_file,"rb");
  if (f == nullptr)
  {
    return false;
  }

  fseek(f,0,SEEK_END);
  unsigned file_size = ftell(f);
  fseek(f,0,SEEK_SET);

  clear();
  data = (char *)cmalloc((file_size + 1)*sizeof(char));
  if (fread(data,file_size,1,f) != 1)
  {
    clear();

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
  if (a_file == nullptr)
  {
    return false;
  }

  FILE *f = fopen(a_file,"w");
  if (f == nullptr)
  {
    return false;
  }

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
// LCOV_EXCL_START

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
    unsigned new_size = (size << 1) + c_array_add;
    debug_assert(new_size != 0);

    copy_resize(new_size);
  }

  data[used++] = a_value;
}/*}}}*/

inline void string_array_s::push_blank()
{/*{{{*/
  if (used >= size)
  {
    unsigned new_size = (size << 1) + c_array_add;
    debug_assert(new_size != 0);

    copy_resize(new_size);
  }

  used++;
}/*}}}*/

inline void string_array_s::push_clear()
{/*{{{*/
  if (used >= size)
  {
    unsigned new_size = (size << 1) + c_array_add;
    debug_assert(new_size != 0);

    copy_resize(new_size);
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

// LCOV_EXCL_STOP



#endif



/*
 * definition of basic functions and constants
 */

#define STRUCT_NAME abbs[0].data
#define STRUCT_NUMBER data_type.properties
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

extern const unsigned c_end_str_len;

// - processor generate options -
enum {
  c_option_gen_code         = 1 << 0,
  c_option_gen_dependencies = 1 << 1,
  c_option_gen_includes     = 1 << 2,
};

// - data type settings -
enum {
   c_type_basic = 0x00000001,
   c_type_static = 0x00000002,
   c_type_dynamic = 0x00000004,
};

const unsigned c_type_byte_neg_mod_mask = 0xf8;
const unsigned c_type_flushable = 0x00000010;
const unsigned c_type_option_mask = 0xffffff00;

enum {
   c_type_option_nogen_init     = 0x100,
   c_type_option_nogen_clear    = 0x100 << 1,
   c_type_option_nogen_swap     = 0x100 << 2,
   c_type_option_nogen_copy     = 0x100 << 3,

   c_type_option_strict_dynamic = 0x100 << 4,
   c_type_option_fixed_buffer   = 0x100 << 5,

   c_type_option_safe             = 0x100 << 6,
   c_type_option_rehash           = 0x100 << 7,
   c_type_option_print_dot_code   = 0x100 << 8,
   c_type_option_check_properties = 0x100 << 9,
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
const unsigned c_cont_cnt = 8;

enum {
   c_cont_array = 0,
   c_cont_queue,
   c_cont_list,
   c_cont_struct,
   c_cont_rb_tree,
   c_cont_safe_list,
   c_cont_safe_rb_tree,
   c_gen_ucl_param,
};

extern const char *c_cont_names[c_cont_cnt];
extern const char *c_cont_postfixes[c_cont_cnt];

/*
 * definitions of generated structures
 */

// -- string_tree_s --
// struct string_tree_s definition

/*!
 * \brief __GEN node of rb_tree of type string_s
 */

struct string_tree_s_node
{
  unsigned parent_idx;
  unsigned left_idx;
  unsigned right_idx;
  bool color;
  string_s object;
};

/*!
 * \brief __GEN rb_tree of type string_s
 */
struct string_tree_s
{
  unsigned size;
  unsigned used;
  string_tree_s_node *data;
  unsigned free_idx;
  unsigned root_idx;
  unsigned leaf_idx;

  // - internal support methods -
  inline unsigned __get_grandparent_idx(unsigned a_idx);
  inline unsigned __get_uncle_idx(unsigned a_idx);
  inline unsigned __get_sibling_idx(unsigned a_idx);

  inline unsigned get_descent_stack_size();
  EXPORT unsigned get_stack_min_value_idx(unsigned a_idx,unsigned **a_s_ptr);
  inline unsigned get_stack_next_idx(unsigned a_idx,unsigned **a_s_ptr,const unsigned *a_stack_base);

  EXPORT unsigned get_min_value_idx(unsigned a_idx);
  EXPORT unsigned get_max_value_idx(unsigned a_idx);
  EXPORT unsigned get_next_idx(unsigned a_idx);
  EXPORT unsigned get_prev_idx(unsigned a_idx);

  inline void __rotate_left(unsigned a_idx);
  inline void __rotate_right(unsigned a_idx);

  inline unsigned __get_new_index();
  EXPORT unsigned __binary_tree_insert(unsigned a_new_idx,string_s &a_value,bool a_unique);

  inline void __replace_delete_node_by_child(unsigned a_idx,unsigned a_ch_idx);
  void __remove_black_black(unsigned a_idx);

  inline void __remove_one_child(unsigned a_idx,unsigned a_ch_idx);

  EXPORT void __insert_operation(unsigned a_idx);

  inline int __compare_value(string_s &a_first,string_s &a_second);

  string_tree_s() = default;
  string_tree_s(string_tree_s &a_src) = delete;

  /*!
    * \brief __GEN initialize rb_tree
    */
  inline void init();

  /*!
    * \brief __GEN release memory used by rb_tree
    */
  EXPORT void clear();

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
  inline void swap(string_tree_s &a_second);

  /*!
    * \brief __GEN select ode of rb_tree
    * \param a_idx - index of node in rb_tree
    * \return reference to node of rb_tree
    */
  inline string_s &operator[](unsigned a_idx);

  /*!
    * \brief __GEN insert node to rb_tree
    * \param a_value - reference to value inserted to rb_tree
    * \return - position of node in rb_tree
    */
  inline unsigned insert(string_s &a_value);

  /*!
    * \brief __GEN insert node to rb_tree if it not exist yet
    * \param a_value - reference to value inserted to rb_tree
    * \return - position of node in rb_tree
    */
  inline unsigned unique_insert(string_s &a_value);

  /*!
    * \brief __GEN insert node to rb_tree by swapping
    * \param a_value - reference to value inserted to rb_tree
    * \return - position of node in rb_tree
    */
  inline unsigned swap_insert(string_s &a_value);

  /*!
    * \brief __GEN insert node to rb_tree by swapping if it not exist yet
    * \param a_value - reference to value inserted to rb_tree
    * \return - position of node in rb_tree
    */
  inline unsigned unique_swap_insert(string_s &a_value);

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
  EXPORT unsigned get_idx(string_s &a_value);

  /*!
    * \brief __GEN search for leftmost index of node
    * \param a_value - value which index is searched
    */
  EXPORT unsigned get_idx_left(string_s &a_value);

  /*!
    * \brief __GEN search for index of node with greater or equal value
    * \param a_value - value which index is searched
    */
  EXPORT unsigned get_gre_idx(string_s &a_value);

  /*!
    * \brief __GEN search for index of node with less or equal value
    * \param a_value - value which index is searched
    */
  EXPORT unsigned get_lee_idx(string_s &a_value);

  /*!
    * \brief __GEN search for all indexes of node
    * \param a_value - value of searched index
    */
  EXPORT void get_idxs(string_s &a_value,ui_array_s &a_idxs_array);

  /*!
    * \brief __GEN copy rb_tree from another rb_tree
    * \param a_src - reference to another rb_tree
    * \return reference to this rb_tree
    */
  EXPORT string_tree_s &operator=(string_tree_s &a_src);

  /*!
    * \brief __GEN compare rb_tree with another rb_tree
    * \param a_second - reference to another rb_tree
    * \return result of comparision
    */
  EXPORT bool operator==(string_tree_s &a_second);

};



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

  data_type_s() = default;
  data_type_s(data_type_s &a_src) = delete;

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

  data_type_array_s() = default;
  data_type_array_s(data_type_array_s &a_src) = delete;

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
  EXPORT void clear();

  /*!
    * \brief __GEN set array content from element pointer
    * \param a_used - number of elements stored at pointed location
    * \param a_data - pointer to elements
    */
  EXPORT void set(unsigned a_used,data_type_s *a_data);

  /*!
    * \brief __GEN flush array memory usage
    */
  inline void flush();

  /*!
    * \brief __GEN flush array memory usage, recursive on elemenets
    */
  EXPORT void flush_all();

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
  EXPORT void copy_resize(unsigned a_size);

  /*!
    * \brief __GEN set all elements of array to given value
    * \param a_value - new value of all elements
    */
  EXPORT void fill(data_type_s &a_value);

  /*!
    * \brief __GEN search for index of element
    * \param a_value - value which index is searched
    */
  EXPORT unsigned get_idx(data_type_s &a_value);

  /*!
    * \brief __GEN copy array from another array
    * \param a_src - reference to another array
    */
  EXPORT data_type_array_s &operator=(data_type_array_s &a_src);

  /*!
    * \brief __GEN comparison of array with another array
    * \param a_second - reference to another array
    * \return result of comparison
    */
  EXPORT bool operator==(data_type_array_s &a_second);

  

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

  abbreviation_s() = default;
  abbreviation_s(abbreviation_s &a_src) = delete;

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

  abbreviation_array_s() = default;
  abbreviation_array_s(abbreviation_array_s &a_src) = delete;

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
  EXPORT void clear();

  /*!
    * \brief __GEN set array content from element pointer
    * \param a_used - number of elements stored at pointed location
    * \param a_data - pointer to elements
    */
  EXPORT void set(unsigned a_used,abbreviation_s *a_data);

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
  EXPORT void copy_resize(unsigned a_size);

  /*!
    * \brief __GEN set all elements of array to given value
    * \param a_value - new value of all elements
    */
  EXPORT void fill(abbreviation_s &a_value);

  /*!
    * \brief __GEN search for index of element
    * \param a_value - value which index is searched
    */
  EXPORT unsigned get_idx(abbreviation_s &a_value);

  /*!
    * \brief __GEN copy array from another array
    * \param a_src - reference to another array
    */
  EXPORT abbreviation_array_s &operator=(abbreviation_array_s &a_src);

  /*!
    * \brief __GEN comparison of array with another array
    * \param a_second - reference to another array
    * \return result of comparison
    */
  EXPORT bool operator==(abbreviation_array_s &a_second);

  

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
  string_array_s functions; //!< member - 2
  string_array_s names; //!< member - 3

  container_parameters_s() = default;
  container_parameters_s(container_parameters_s &a_src) = delete;

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
  inline void set(string_array_s &a_types,string_array_s &a_variables,string_array_s &a_functions,string_array_s &a_names);
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
  unsigned gen_options; //!< member - 1
  unsigned include_level; //!< member - 2
  string_array_s include_dirs; //!< member - 3
  string_array_s include_names; //!< member - 4
  data_type_array_s data_types; //!< member - 5
  abbreviation_array_s abbreviations; //!< member - 6
  unsigned type_settings; //!< member - 7
  container_parameters_s cont_params; //!< member - 8
  string_tree_s define_tree; //!< member - 9
  ui_array_s enable_stack; //!< member - 10

  processor_s() = default;
  processor_s(processor_s &a_src) = delete;

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
  inline void set(FILE_ptr a_out_file,unsigned a_gen_options,unsigned a_include_level,string_array_s &a_include_dirs,string_array_s &a_include_names,data_type_array_s &a_data_types,abbreviation_array_s &a_abbreviations,unsigned a_type_settings,container_parameters_s &a_cont_params,string_tree_s &a_define_tree,ui_array_s &a_enable_stack);
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
   void generate_ucl_params();

   void generate_type_inlines(unsigned a_length,char *a_data);
   void generate_type_methods(unsigned a_length,char *a_data);
   void generate_container_def(string_s &a_cont_name);

   bool find_include_file(const char *a_file, string_s &a_file_path);

   void initialize_data_types();
   bool run(const char *a_file_name, string_array_s &a_include_dirs, 
            FILE *a_file,unsigned a_gen_options);

   
};



// - processor_s_ptr definition -
typedef processor_s * processor_s_ptr;


/*
 * inline methods of generated structures
 */

// -- string_tree_s --
// --- struct string_tree_s inline method definition ---
// LCOV_EXCL_START

inline unsigned string_tree_s::__get_grandparent_idx(unsigned a_idx)
{/*{{{*/
  string_tree_s_node &node = data[a_idx];

  if (node.parent_idx != c_idx_not_exist)
  {
    return data[node.parent_idx].parent_idx;
  }

  return c_idx_not_exist;
}/*}}}*/

inline unsigned string_tree_s::__get_uncle_idx(unsigned a_idx)
{/*{{{*/
  unsigned gp_idx = __get_grandparent_idx(a_idx);

  if (gp_idx != c_idx_not_exist)
  {
    string_tree_s_node &gp = data[gp_idx];
    return gp.left_idx == data[a_idx].parent_idx?gp.right_idx:gp.left_idx;
  }

  return c_idx_not_exist;
}/*}}}*/

inline unsigned string_tree_s::__get_sibling_idx(unsigned a_idx)
{/*{{{*/
  string_tree_s_node &p = data[data[a_idx].parent_idx];
  return p.left_idx == a_idx?p.right_idx:p.left_idx;
}/*}}}*/

inline unsigned string_tree_s::get_descent_stack_size()
{/*{{{*/
  return (unsigned)(logf(used)/c_log_of_2) << 1;
}/*}}}*/

inline unsigned string_tree_s::get_stack_next_idx(unsigned a_idx,unsigned **a_s_ptr,const unsigned *a_stack_base)
{/*{{{*/
  debug_assert(a_idx < used);

  string_tree_s_node &node = data[a_idx];

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

inline void string_tree_s::__rotate_left(unsigned a_idx)
{/*{{{*/
  string_tree_s_node &root = data[a_idx];
  string_tree_s_node &pivot = data[root.right_idx];

  if (a_idx == root_idx)
  {
    root_idx = root.right_idx;
    pivot.parent_idx = c_idx_not_exist;
  }
  else
  {
    string_tree_s_node &rp = data[root.parent_idx];
    (rp.right_idx == a_idx?rp.right_idx:rp.left_idx) = root.right_idx;

    pivot.parent_idx = root.parent_idx;
  }

  root.parent_idx = root.right_idx;

  root.right_idx = pivot.left_idx;
  data[root.right_idx].parent_idx = a_idx;

  pivot.left_idx = a_idx;
}/*}}}*/

inline void string_tree_s::__rotate_right(unsigned a_idx)
{/*{{{*/
  string_tree_s_node &root = data[a_idx];
  string_tree_s_node &pivot = data[root.left_idx];

  if (a_idx == root_idx)
  {
    root_idx = root.left_idx;
    pivot.parent_idx = c_idx_not_exist;
  }
  else
  {
    string_tree_s_node &rp = data[root.parent_idx];
    (rp.right_idx == a_idx?rp.right_idx:rp.left_idx) = root.left_idx;

    pivot.parent_idx = root.parent_idx;
  }

  root.parent_idx = root.left_idx;

  root.left_idx = pivot.right_idx;
  data[root.left_idx].parent_idx = a_idx;

  pivot.right_idx = a_idx;
}/*}}}*/

inline unsigned string_tree_s::__get_new_index()
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
      unsigned new_size = (size << 1) + c_array_add;
      debug_assert(new_size != 0);

      copy_resize(new_size);
    }

    new_idx = used++;
  }

  return new_idx;
}/*}}}*/

inline void string_tree_s::__replace_delete_node_by_child(unsigned a_idx,unsigned a_ch_idx)
{/*{{{*/
  string_tree_s_node &node = data[a_idx];

  if (node.parent_idx != c_idx_not_exist)
  {
    string_tree_s_node &parent = data[node.parent_idx];
    (parent.left_idx == a_idx?parent.left_idx:parent.right_idx) = a_ch_idx;

    data[a_ch_idx].parent_idx = node.parent_idx;
  }
  else
  {
    root_idx = a_ch_idx == leaf_idx?c_idx_not_exist:a_ch_idx;
    data[a_ch_idx].parent_idx = c_idx_not_exist;
  }
}/*}}}*/

inline void string_tree_s::__remove_one_child(unsigned a_idx,unsigned a_ch_idx)
{/*{{{*/
  string_tree_s_node &node = data[a_idx];
  __replace_delete_node_by_child(a_idx,a_ch_idx);

  node.parent_idx = free_idx;
  free_idx = a_idx;

  if (node.color)
  {
    string_tree_s_node &child_node = data[a_ch_idx];

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

inline void string_tree_s::init()
{/*{{{*/
  size = 0;
  used = 0;
  data = nullptr;
  free_idx = c_idx_not_exist;
  root_idx = c_idx_not_exist;
  leaf_idx = c_idx_not_exist;
}/*}}}*/

inline void string_tree_s::flush()
{/*{{{*/
  copy_resize(used);
}/*}}}*/

inline void string_tree_s::flush_all()
{/*{{{*/
  copy_resize(used);
}/*}}}*/

inline void string_tree_s::swap(string_tree_s &a_second)
{/*{{{*/
  unsigned tmp_unsigned = size;
  size = a_second.size;
  a_second.size = tmp_unsigned;

  tmp_unsigned = used;
  used = a_second.used;
  a_second.used = tmp_unsigned;

  string_tree_s_node *tmp_data = data;
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

inline string_s &string_tree_s::operator[](unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < used);
  return data[a_idx].object;
}/*}}}*/

inline unsigned string_tree_s::insert(string_s &a_value)
{/*{{{*/
  unsigned new_node_idx = __get_new_index();

  __binary_tree_insert(new_node_idx,a_value,false);
  __insert_operation(new_node_idx);

  data[new_node_idx].object = a_value;

  return new_node_idx;
}/*}}}*/

inline unsigned string_tree_s::swap_insert(string_s &a_value)
{/*{{{*/
  unsigned new_node_idx = __get_new_index();

  __binary_tree_insert(new_node_idx,a_value,false);
  __insert_operation(new_node_idx);

  data[new_node_idx].object.swap(a_value);

  return new_node_idx;
}/*}}}*/

inline unsigned string_tree_s::unique_insert(string_s &a_value)
{/*{{{*/
  unsigned new_node_idx = __get_new_index();
  unsigned old_node_idx = __binary_tree_insert(new_node_idx,a_value,true);

  if (old_node_idx != c_idx_not_exist)
  {
    string_tree_s_node &new_node = data[new_node_idx];

    new_node.parent_idx = free_idx;
    free_idx = new_node_idx;

    return old_node_idx;
  }

  __insert_operation(new_node_idx);

  data[new_node_idx].object = a_value;

  return new_node_idx;
}/*}}}*/

inline unsigned string_tree_s::unique_swap_insert(string_s &a_value)
{/*{{{*/
  unsigned new_node_idx = __get_new_index();
  unsigned old_node_idx = __binary_tree_insert(new_node_idx,a_value,true);

  if (old_node_idx != c_idx_not_exist)
  {
    string_tree_s_node &new_node = data[new_node_idx];

    new_node.parent_idx = free_idx;
    free_idx = new_node_idx;

    return old_node_idx;
  }

  __insert_operation(new_node_idx);

  data[new_node_idx].object.swap(a_value);

  return new_node_idx;
}/*}}}*/

// LCOV_EXCL_STOP



int string_tree_s::__compare_value(string_s &a_first,string_s &a_second)
{/*{{{*/
  if (a_first.size < a_second.size) { return -1; }
  if (a_first.size > a_second.size) { return 1; }
  return memcmp(a_first.data,a_second.data,a_first.size - 1);
}/*}}}*/

// -- data_type_s --
// --- struct data_type_s inline method definition ---
// LCOV_EXCL_START

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

// LCOV_EXCL_STOP



// -- data_type_array_s --
// --- struct data_type_array_s inline method definition ---
// LCOV_EXCL_START

inline void data_type_array_s::init()
{/*{{{*/
  size = 0;
  used = 0;
  data = nullptr;
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
  if (used >= size)
  {
    unsigned new_size = (size << 1) + c_array_add;
    debug_assert(new_size != 0);

    copy_resize(new_size);
  }

  data[used++] = a_value;
}/*}}}*/

inline void data_type_array_s::push_blank()
{/*{{{*/
  if (used >= size)
  {
    unsigned new_size = (size << 1) + c_array_add;
    debug_assert(new_size != 0);

    copy_resize(new_size);
  }

  used++;
}/*}}}*/

inline void data_type_array_s::push_clear()
{/*{{{*/
  if (used >= size)
  {
    unsigned new_size = (size << 1) + c_array_add;
    debug_assert(new_size != 0);

    copy_resize(new_size);
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

// LCOV_EXCL_STOP



// -- abbreviation_s --
// --- struct abbreviation_s inline method definition ---
// LCOV_EXCL_START

inline void abbreviation_s::init()
{/*{{{*/
  name.init();
}/*}}}*/

inline void abbreviation_s::clear()
{/*{{{*/
  name.clear();
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

// LCOV_EXCL_STOP



// -- abbreviation_array_s --
// --- struct abbreviation_array_s inline method definition ---
// LCOV_EXCL_START

inline void abbreviation_array_s::init()
{/*{{{*/
  size = 0;
  used = 0;
  data = nullptr;
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
  if (used >= size)
  {
    unsigned new_size = (size << 1) + c_array_add;
    debug_assert(new_size != 0);

    copy_resize(new_size);
  }

  data[used++] = a_value;
}/*}}}*/

inline void abbreviation_array_s::push_blank()
{/*{{{*/
  if (used >= size)
  {
    unsigned new_size = (size << 1) + c_array_add;
    debug_assert(new_size != 0);

    copy_resize(new_size);
  }

  used++;
}/*}}}*/

inline void abbreviation_array_s::push_clear()
{/*{{{*/
  if (used >= size)
  {
    unsigned new_size = (size << 1) + c_array_add;
    debug_assert(new_size != 0);

    copy_resize(new_size);
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

// LCOV_EXCL_STOP



// -- container_parameters_s --
// --- struct container_parameters_s inline method definition ---
// LCOV_EXCL_START

inline void container_parameters_s::init()
{/*{{{*/
  types.init();
  variables.init();
  functions.init();
  names.init();
}/*}}}*/

inline void container_parameters_s::clear()
{/*{{{*/
  types.clear();
  variables.clear();
  functions.clear();
  names.clear();
}/*}}}*/

inline void container_parameters_s::set(string_array_s &a_types,string_array_s &a_variables,string_array_s &a_functions,string_array_s &a_names)
{/*{{{*/
  types = a_types;
  variables = a_variables;
  functions = a_functions;
  names = a_names;
}/*}}}*/

inline void container_parameters_s::flush_all()
{/*{{{*/
  types.flush_all();
  variables.flush_all();
  functions.flush_all();
  names.flush_all();
}/*}}}*/

inline void container_parameters_s::swap(container_parameters_s &a_second)
{/*{{{*/
  types.swap(a_second.types);

  variables.swap(a_second.variables);

  functions.swap(a_second.functions);

  names.swap(a_second.names);
}/*}}}*/

inline container_parameters_s &container_parameters_s::operator=(container_parameters_s &a_src)
{/*{{{*/
  types = a_src.types;
  variables = a_src.variables;
  functions = a_src.functions;
  names = a_src.names;

  return *this;
}/*}}}*/

inline bool container_parameters_s::operator==(container_parameters_s &a_second)
{/*{{{*/
  return (types == a_second.types && variables == a_second.variables && functions == a_second.functions && names == a_second.names);
}/*}}}*/

// LCOV_EXCL_STOP



inline void container_parameters_s::clean_out()
{/*{{{*/
   types.used = 0;
   variables.used = 0;
   functions.used = 0;
   names.used = 0;
}/*}}}*/

// -- processor_s --
// --- struct processor_s inline method definition ---
// LCOV_EXCL_START

inline void processor_s::init()
{/*{{{*/
  include_dirs.init();
  include_names.init();
  data_types.init();
  abbreviations.init();
  cont_params.init();
  define_tree.init();
  enable_stack.init();
}/*}}}*/

inline void processor_s::clear()
{/*{{{*/
  include_dirs.clear();
  include_names.clear();
  data_types.clear();
  abbreviations.clear();
  cont_params.clear();
  define_tree.clear();
  enable_stack.clear();
}/*}}}*/

inline void processor_s::set(FILE_ptr a_out_file,unsigned a_gen_options,unsigned a_include_level,string_array_s &a_include_dirs,string_array_s &a_include_names,data_type_array_s &a_data_types,abbreviation_array_s &a_abbreviations,unsigned a_type_settings,container_parameters_s &a_cont_params,string_tree_s &a_define_tree,ui_array_s &a_enable_stack)
{/*{{{*/
  out_file = a_out_file;
  gen_options = a_gen_options;
  include_level = a_include_level;
  include_dirs = a_include_dirs;
  include_names = a_include_names;
  data_types = a_data_types;
  abbreviations = a_abbreviations;
  type_settings = a_type_settings;
  cont_params = a_cont_params;
  define_tree = a_define_tree;
  enable_stack = a_enable_stack;
}/*}}}*/

inline void processor_s::flush_all()
{/*{{{*/
  include_dirs.flush_all();
  include_names.flush_all();
  data_types.flush_all();
  abbreviations.flush_all();
  cont_params.flush_all();
  define_tree.flush_all();
  enable_stack.flush_all();
}/*}}}*/

inline void processor_s::swap(processor_s &a_second)
{/*{{{*/
  FILE_ptr tmp_out_file = out_file;
  out_file = a_second.out_file;
  a_second.out_file = tmp_out_file;

  unsigned tmp_gen_options = gen_options;
  gen_options = a_second.gen_options;
  a_second.gen_options = tmp_gen_options;

  unsigned tmp_include_level = include_level;
  include_level = a_second.include_level;
  a_second.include_level = tmp_include_level;

  include_dirs.swap(a_second.include_dirs);

  include_names.swap(a_second.include_names);

  data_types.swap(a_second.data_types);

  abbreviations.swap(a_second.abbreviations);

  unsigned tmp_type_settings = type_settings;
  type_settings = a_second.type_settings;
  a_second.type_settings = tmp_type_settings;

  cont_params.swap(a_second.cont_params);

  define_tree.swap(a_second.define_tree);

  enable_stack.swap(a_second.enable_stack);
}/*}}}*/

inline processor_s &processor_s::operator=(processor_s &a_src)
{/*{{{*/
  out_file = a_src.out_file;
  gen_options = a_src.gen_options;
  include_level = a_src.include_level;
  include_dirs = a_src.include_dirs;
  include_names = a_src.include_names;
  data_types = a_src.data_types;
  abbreviations = a_src.abbreviations;
  type_settings = a_src.type_settings;
  cont_params = a_src.cont_params;
  define_tree = a_src.define_tree;
  enable_stack = a_src.enable_stack;

  return *this;
}/*}}}*/

inline bool processor_s::operator==(processor_s &a_second)
{/*{{{*/
  return (out_file == a_second.out_file && gen_options == a_second.gen_options && include_level == a_second.include_level && include_dirs == a_second.include_dirs && include_names == a_second.include_names && data_types == a_second.data_types && abbreviations == a_second.abbreviations && type_settings == a_second.type_settings && cont_params == a_second.cont_params && define_tree == a_second.define_tree && enable_stack == a_second.enable_stack);
}/*}}}*/

// LCOV_EXCL_STOP



#endif


#ifndef CONT_PROCESS_H
#define CONT_PROCESS_H



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

  lalr_stack_element_s() = default;
  lalr_stack_element_s(lalr_stack_element_s &a_src) = delete;

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

  lalr_stack_s() = default;
  lalr_stack_s(lalr_stack_s &a_src) = delete;

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
  EXPORT void copy_resize(unsigned a_size);

  /*!
    * \brief __GEN set all elements of array to given value
    * \param a_value - new value of all elements
    */
  EXPORT void fill(lalr_stack_element_s &a_value);

  /*!
    * \brief __GEN search for index of element
    * \param a_value - value which index is searched
    */
  EXPORT unsigned get_idx(lalr_stack_element_s &a_value);

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
  EXPORT bool operator==(lalr_stack_s &a_second);

  

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

  process_s() = default;
  process_s(process_s &a_src) = delete;

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
   static void pa_reduce_abbreviation(process_s &proc);
   static void pa_reduce_mod_basic(process_s &proc);
   static void pa_reduce_mod_static(process_s &proc);
   static void pa_reduce_mod_dynamic(process_s &proc);
   static void pa_reduce_mod_flushable(process_s &proc);
   static void pa_reduce_gen_container(process_s &proc);
   static void pa_reduce_type(process_s &proc);
   static void pa_reduce_type_and_name(process_s &proc);
   static void pa_reduce_if(process_s &proc);
   static void pa_reduce_endif(process_s &proc);
   static void pa_reduce_else(process_s &proc);
   static void pa_reduce_exp_double_ampersand(process_s &proc);
   static void pa_reduce_exp_double_pipe(process_s &proc);
   static void pa_reduce_exp_exclamation(process_s &proc);
   static void pa_reduce_exp_id(process_s &proc);
   static void pa_reduce_option(process_s &proc);
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
// LCOV_EXCL_START

inline void lalr_stack_element_s::init()
{/*{{{*/
}/*}}}*/

inline void lalr_stack_element_s::clear()
{/*{{{*/
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

// LCOV_EXCL_STOP



// -- lalr_stack_s --
// --- struct lalr_stack_s inline method definition ---
// LCOV_EXCL_START

inline void lalr_stack_s::init()
{/*{{{*/
  size = 0;
  used = 0;
  data = nullptr;
}/*}}}*/

inline void lalr_stack_s::init_size(unsigned a_size)
{/*{{{*/
  init();
  copy_resize(a_size);
}/*}}}*/

inline void lalr_stack_s::clear()
{/*{{{*/
  if (data != nullptr)
  {
    cfree(data);
  }

  init();
}/*}}}*/

inline void lalr_stack_s::set(unsigned a_used,lalr_stack_element_s *a_data)
{/*{{{*/
  debug_assert(a_data != nullptr);

  clear();

  if (a_used == 0)
  {
    return;
  }

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
  if (used >= size)
  {
    unsigned new_size = (size << 1) + c_array_add;
    debug_assert(new_size != 0);

    copy_resize(new_size);
  }

  data[used++] = a_value;
}/*}}}*/

inline void lalr_stack_s::push_blank()
{/*{{{*/
  if (used >= size)
  {
    unsigned new_size = (size << 1) + c_array_add;
    debug_assert(new_size != 0);

    copy_resize(new_size);
  }

  used++;
}/*}}}*/

inline void lalr_stack_s::push_clear()
{/*{{{*/
  if (used >= size)
  {
    unsigned new_size = (size << 1) + c_array_add;
    debug_assert(new_size != 0);

    copy_resize(new_size);
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

  if (a_src.used == 0)
  {
    return *this;
  }

  copy_resize(a_src.used);

  memcpy(data,a_src.data,a_src.used*sizeof(lalr_stack_element_s));

  used = a_src.used;
  return *this;
}/*}}}*/

// LCOV_EXCL_STOP



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
// LCOV_EXCL_START

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

// LCOV_EXCL_STOP



#endif



/*
 * basic functions and constants
 */

const char *c_begin_str = "@""begin";
const char *c_end_str = "@""end";

const unsigned c_end_str_len = strlen(c_end_str);

// - names of basic data types -
const char *c_basic_types[c_basic_type_cnt] = {
   "bb",
   "bc",
   "sc",
   "uc",
   "si",
   "usi",
   "bi",
   "ui",
   "li",
   "uli",
   "lli",
   "ulli",
   "bf",
   "bd",
   "ld",
};

unsigned c_basic_type_types[c_basic_type_cnt] = {
   c_type_basic,
   c_type_basic,
   c_type_basic,
   c_type_basic,
   c_type_basic,
   c_type_basic,
   c_type_basic,
   c_type_basic,
   c_type_basic,
   c_type_basic,
   c_type_basic,
   c_type_basic,
   c_type_basic,
   c_type_basic,
   c_type_basic,
};

// - abbreviations of basic data types -
const char *c_basic_abbreviations[c_basic_abbreviation_cnt] = {
   "bb","bool",
   "bc","char",
   "sc","signed_char",
   "uc","unsigned_char",
   "si","short","short_int",
   "usi","unsigned_short","unsigned_short_int",
   "bi","int",
   "ui","unsigned","unsigned_int",
   "li","long","long_int",
   "uli","unsigned_long","unsigned_long_int",
   "lli","long_long","long_long_int",
   "ulli","unsigned_long_long","unsigned_long_long_int",
   "bf","float",
   "bd","double",
   "ld","long_double",
};

const int c_basic_abbreviation_types[c_basic_abbreviation_cnt] = {
   0,0,
   1,1,
   2,2,
   3,3,
   4,4,4,
   5,5,5,
   6,6,
   7,7,7,
   8,8,8,
   9,9,9,
   10,10,10,
   11,11,11,
   12,12,
   13,13,
   14,14,
};

// - constant describing containers -

const char *c_cont_names[c_cont_cnt] = {
   "array",
   "queue",
   "list",
   "struct",
   "rb_tree",
   "safe_list",
   "safe_rb_tree",
   "ucl_params",
};

const char *c_cont_postfixes[c_cont_cnt] = {
   "_a",
   "_q",
   "_l",
   "_s",
   "_rbt",
   "_sl",
   "_srbt",
   "_uclp",
};

/*
 * methods of generated structures
 */

// -- string_tree_s --
// --- struct string_tree_s method definition ---
// LCOV_EXCL_START

unsigned string_tree_s::get_stack_min_value_idx(unsigned a_idx,unsigned **a_s_ptr)
{/*{{{*/
  debug_assert(a_idx < used);

  unsigned node_idx = a_idx;
  do {
    string_tree_s_node &node = data[node_idx];

    if (node.left_idx == leaf_idx)
    {
      return node_idx;
    }

    *((*a_s_ptr)++) = node_idx;
    node_idx = node.left_idx;
  } while(true);
}/*}}}*/

unsigned string_tree_s::get_min_value_idx(unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < used);

  unsigned node_idx = a_idx;
  do {
    string_tree_s_node &node = data[node_idx];

    if (node.left_idx == leaf_idx)
    {
      return node_idx;
    }

    node_idx = node.left_idx;
  } while(true);
}/*}}}*/

unsigned string_tree_s::get_max_value_idx(unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < used);

  unsigned node_idx = a_idx;
  do {
    string_tree_s_node &node = data[node_idx];

    if (node.right_idx == leaf_idx)
    {
      return node_idx;
    }

    node_idx = node.right_idx;
  } while(true);
}/*}}}*/

unsigned string_tree_s::get_next_idx(unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < used);

  string_tree_s_node &node = data[a_idx];

  if (node.right_idx != leaf_idx)
  {
    return get_min_value_idx(node.right_idx);
  }

  unsigned node_idx = a_idx;
  do {
    string_tree_s_node &node = data[node_idx];

    if (node.parent_idx == c_idx_not_exist)
    {
      return c_idx_not_exist;
    }

    if (data[node.parent_idx].right_idx != node_idx)
    {
      return node.parent_idx;
    }

    node_idx = node.parent_idx;
  } while(true);
}/*}}}*/

unsigned string_tree_s::get_prev_idx(unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < used);

  string_tree_s_node &node = data[a_idx];

  if (node.left_idx != leaf_idx)
  {
    return get_max_value_idx(node.left_idx);
  }

  unsigned node_idx = a_idx;
  do {
    string_tree_s_node &node = data[node_idx];

    if (node.parent_idx == c_idx_not_exist)
    {
      return c_idx_not_exist;
    }

    if (data[node.parent_idx].left_idx != node_idx)
    {
      return node.parent_idx;
    }

    node_idx = node.parent_idx;
  } while(true);
}/*}}}*/

unsigned string_tree_s::__binary_tree_insert(unsigned a_new_idx,string_s &a_value,bool a_unique)
{/*{{{*/
  if (root_idx == c_idx_not_exist)
  {
    if (leaf_idx == c_idx_not_exist)
    {
      leaf_idx = __get_new_index();
      string_tree_s_node &leaf = data[leaf_idx];

      leaf.color = true;
    }

    data[a_new_idx].parent_idx = c_idx_not_exist;
    root_idx = a_new_idx;
  }
  else
  {
    unsigned node_idx = root_idx;
    do {
      string_tree_s_node &node = data[node_idx];

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
    } while(true);

    data[a_new_idx].parent_idx = node_idx;
  }

  string_tree_s_node &new_node = data[a_new_idx];
  new_node.left_idx = leaf_idx;
  new_node.right_idx = leaf_idx;
  new_node.color = false;

  return c_idx_not_exist;
}/*}}}*/

void string_tree_s::__remove_black_black(unsigned a_idx)
{/*{{{*/
  unsigned node_idx = a_idx;
  do {
    string_tree_s_node &node = data[node_idx];

    if (node.parent_idx == c_idx_not_exist)
    {
      return;
    }

    unsigned parent_idx = node.parent_idx;
    string_tree_s_node &parent = data[parent_idx];

    {
      unsigned sibling_idx = parent.left_idx == node_idx?parent.right_idx:parent.left_idx;
      string_tree_s_node &sibling = data[sibling_idx];

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
      string_tree_s_node& sibling = data[sibling_idx];

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
        string_tree_s_node &sibling = data[sibling_idx];

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

  } while(true);
}/*}}}*/

void string_tree_s::__insert_operation(unsigned a_idx)
{/*{{{*/
  unsigned node_idx = a_idx;
  do {
    string_tree_s_node &node = data[node_idx];

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
        string_tree_s_node &node = data[node_idx];

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
  } while(true);
}/*}}}*/

void string_tree_s::clear()
{/*{{{*/
  if (data != nullptr)
  {
    string_tree_s_node *ptr = data;
    string_tree_s_node *ptr_end = ptr + size;

    do {
      ptr->object.clear();
    } while(++ptr < ptr_end);

    cfree(data);
  }

  size = 0;
  used = 0;
  data = nullptr;
  free_idx = c_idx_not_exist;
  root_idx = c_idx_not_exist;
  leaf_idx = c_idx_not_exist;
}/*}}}*/

void string_tree_s::remove(unsigned a_idx)
{/*{{{*/
  debug_assert(a_idx < used);

  string_tree_s_node &del_node = data[a_idx];

  if (del_node.left_idx != leaf_idx)
  {
    if (del_node.right_idx != leaf_idx)
    {
      unsigned found_idx = del_node.right_idx;
      do {
        string_tree_s_node &node = data[found_idx];

        if (node.left_idx == leaf_idx)
        {
          break;
        }

        found_idx = node.left_idx;
      } while(true);

      string_tree_s_node &found_node = data[found_idx];

      /* - process del_node parent_idx - */
      if (del_node.parent_idx != c_idx_not_exist)
      {
        string_tree_s_node &del_node_parent = data[del_node.parent_idx];
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
        string_tree_s_node &found_node_parent = data[found_node.parent_idx];
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

void string_tree_s::copy_resize(unsigned a_size)
{/*{{{*/
  debug_assert(a_size >= used);

  if (size > a_size)
  {
    string_tree_s_node *ptr = data + a_size;
    string_tree_s_node *ptr_end = data + size;

    do {
      ptr->object.clear();
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
    data = (string_tree_s_node *)crealloc(data,a_size*sizeof(string_tree_s_node));
  }

  if (a_size > size)
  {
    debug_assert(memset(data + size,0,(a_size - size)*sizeof(string_tree_s_node)) == (data + size));

    string_tree_s_node *ptr = data + size;
    string_tree_s_node *ptr_end = data + a_size;

    do {
      ptr->object.init();
    } while(++ptr < ptr_end);
  }

  size = a_size;
}/*}}}*/

unsigned string_tree_s::get_idx(string_s &a_value)
{/*{{{*/
  if (root_idx == c_idx_not_exist)
  {
    return c_idx_not_exist;
  }

  unsigned node_idx = root_idx;
  do {
    string_tree_s_node &node = data[node_idx];

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

unsigned string_tree_s::get_idx_left(string_s &a_value)
{/*{{{*/
  if (root_idx == c_idx_not_exist)
  {
    return c_idx_not_exist;
  }

  unsigned good_idx = c_idx_not_exist;
  unsigned node_idx = root_idx;
  do {
    string_tree_s_node &node = data[node_idx];

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

unsigned string_tree_s::get_gre_idx(string_s &a_value)
{/*{{{*/
  if (root_idx == c_idx_not_exist)
  {
    return c_idx_not_exist;
  }

  unsigned good_idx = c_idx_not_exist;
  unsigned node_idx = root_idx;
  do {
    string_tree_s_node &node = data[node_idx];

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

unsigned string_tree_s::get_lee_idx(string_s &a_value)
{/*{{{*/
  if (root_idx == c_idx_not_exist)
  {
    return c_idx_not_exist;
  }

  unsigned good_idx = c_idx_not_exist;
  unsigned node_idx = root_idx;
  do {
    string_tree_s_node &node = data[node_idx];

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

void string_tree_s::get_idxs(string_s &a_value,ui_array_s &a_idxs_array)
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
    string_tree_s_node &node = data[node_idx];

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
}/*}}}*/

string_tree_s &string_tree_s::operator=(string_tree_s &a_src)
{/*{{{*/
  clear();

  if (a_src.root_idx == c_idx_not_exist)
  {
    return *this;
  }

  debug_assert(a_src.used != 0);
  copy_resize(a_src.used);

  string_tree_s_node *ptr = data;
  string_tree_s_node *s_ptr = a_src.data;
  string_tree_s_node *s_ptr_end = s_ptr + a_src.used;

  do {
    ptr->object = s_ptr->object;
    ptr->parent_idx = s_ptr->parent_idx;
    ptr->left_idx = s_ptr->left_idx;
    ptr->right_idx = s_ptr->right_idx;
    ptr->color = s_ptr->color;
  } while(++ptr,++s_ptr < s_ptr_end);

  used = a_src.used;
  free_idx = a_src.free_idx;
  root_idx = a_src.root_idx;
  leaf_idx = a_src.leaf_idx;

  return *this;
}/*}}}*/

bool string_tree_s::operator==(string_tree_s &a_second)
{/*{{{*/
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

// LCOV_EXCL_STOP



// -- data_type_s --
// --- struct data_type_s method definition ---
// LCOV_EXCL_START

// LCOV_EXCL_STOP



// -- data_type_array_s --
// --- struct data_type_array_s method definition ---
// LCOV_EXCL_START

void data_type_array_s::clear()
{/*{{{*/
  if (data != nullptr)
  {
    data_type_s *ptr = data;
    data_type_s *ptr_end = ptr + size;

    do {
      ptr->clear();
    } while(++ptr < ptr_end);

    cfree(data);
  }

  init();
}/*}}}*/

void data_type_array_s::set(unsigned a_used,data_type_s *a_data)
{/*{{{*/
  debug_assert(a_data != nullptr);

  clear();

  if (a_used == 0)
  {
    return;
  }

  copy_resize(a_used);

  data_type_s *ptr = data;
  data_type_s *ptr_end = ptr + a_used;
  data_type_s *a_ptr = a_data;

  do {
    *ptr = *a_ptr;
  } while(++a_ptr,++ptr < ptr_end);

  used = a_used;
}/*}}}*/

void data_type_array_s::flush_all()
{/*{{{*/
  copy_resize(used);

  if (used == 0)
  {
    return;
  }

  data_type_s *ptr = data;
  data_type_s *ptr_end = ptr + used;

  do {
    ptr->flush_all();
  } while(++ptr < ptr_end);
}/*}}}*/

void data_type_array_s::reserve(unsigned a_cnt)
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

void data_type_array_s::push_blanks(unsigned a_cnt)
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

void data_type_array_s::copy_resize(unsigned a_size)
{/*{{{*/
  debug_assert(a_size >= used);

  if (size > a_size)
  {
    data_type_s *ptr = data + a_size;
    data_type_s *ptr_end = data + size;

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
    data = (data_type_s *)crealloc(data,a_size*sizeof(data_type_s));
  }

  if (a_size > size)
  {
    data_type_s *ptr = data + size;
    data_type_s *ptr_end = data + a_size;

    do {
      ptr->init();
    } while(++ptr < ptr_end);
  }

  size = a_size;
}/*}}}*/

void data_type_array_s::fill(data_type_s &a_value)
{/*{{{*/
  if (size == 0)
  {
    return;
  }

  data_type_s *ptr = data;
  data_type_s *ptr_end = data + size;

  do {
    *ptr = a_value;
  } while(++ptr < ptr_end);

  used = size;
}/*}}}*/

unsigned data_type_array_s::get_idx(data_type_s &a_value)
{/*{{{*/
  if (used == 0)
  {
    return c_idx_not_exist;
  }

  data_type_s *ptr = data;
  data_type_s *ptr_end = data + used;

  do {
    if (*ptr == a_value)
    {
      return ptr - data;
    }
  } while(++ptr < ptr_end);

  return c_idx_not_exist;
}/*}}}*/

data_type_array_s &data_type_array_s::operator=(data_type_array_s &a_src)
{/*{{{*/
  clear();

  if (a_src.used == 0)
  {
    return *this;
  }

  copy_resize(a_src.used);

  data_type_s *ptr = data;
  data_type_s *s_ptr = a_src.data;
  data_type_s *s_ptr_end = s_ptr + a_src.used;

  do {
    *ptr = *s_ptr;
  } while(++ptr,++s_ptr < s_ptr_end);

  used = a_src.used;
  return *this;
}/*}}}*/

bool data_type_array_s::operator==(data_type_array_s &a_second)
{/*{{{*/
  if (used != a_second.used)
  {
    return false;
  }

  if (used == 0)
  {
    return true;
  }

  data_type_s *ptr = data;
  data_type_s *ptr_end = ptr + used;
  data_type_s *s_ptr = a_second.data;

  do {
    if (!(*ptr == *s_ptr))
    {
      return false;
    }
  } while(++s_ptr,++ptr < ptr_end);

  return true;
}/*}}}*/

// LCOV_EXCL_STOP



unsigned data_type_array_s::get_idx_by_real_name(unsigned n_length,char *n_data)
{/*{{{*/
   if (used == 0) return c_idx_not_exist;

   data_type_s *ptr = data;
   data_type_s *ptr_end = ptr + used;
   do {
      if (ptr->real_name.compare_char_ptr(n_length,n_data)) {
         return ptr - data;
      }
   } while(++ptr < ptr_end);

   return c_idx_not_exist;
}/*}}}*/

// -- abbreviation_s --
// --- struct abbreviation_s method definition ---
// LCOV_EXCL_START

// LCOV_EXCL_STOP



// -- abbreviation_array_s --
// --- struct abbreviation_array_s method definition ---
// LCOV_EXCL_START

void abbreviation_array_s::clear()
{/*{{{*/
  if (data != nullptr)
  {
    abbreviation_s *ptr = data;
    abbreviation_s *ptr_end = ptr + size;

    do {
      ptr->clear();
    } while(++ptr < ptr_end);

    cfree(data);
  }

  init();
}/*}}}*/

void abbreviation_array_s::set(unsigned a_used,abbreviation_s *a_data)
{/*{{{*/
  debug_assert(a_data != nullptr);

  clear();

  if (a_used == 0)
  {
    return;
  }

  copy_resize(a_used);

  abbreviation_s *ptr = data;
  abbreviation_s *ptr_end = ptr + a_used;
  abbreviation_s *a_ptr = a_data;

  do {
    *ptr = *a_ptr;
  } while(++a_ptr,++ptr < ptr_end);

  used = a_used;
}/*}}}*/

void abbreviation_array_s::reserve(unsigned a_cnt)
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

void abbreviation_array_s::push_blanks(unsigned a_cnt)
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

void abbreviation_array_s::copy_resize(unsigned a_size)
{/*{{{*/
  debug_assert(a_size >= used);

  if (size > a_size)
  {
    abbreviation_s *ptr = data + a_size;
    abbreviation_s *ptr_end = data + size;

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
    data = (abbreviation_s *)crealloc(data,a_size*sizeof(abbreviation_s));
  }

  if (a_size > size)
  {
    abbreviation_s *ptr = data + size;
    abbreviation_s *ptr_end = data + a_size;

    do {
      ptr->init();
    } while(++ptr < ptr_end);
  }

  size = a_size;
}/*}}}*/

void abbreviation_array_s::fill(abbreviation_s &a_value)
{/*{{{*/
  if (size == 0)
  {
    return;
  }

  abbreviation_s *ptr = data;
  abbreviation_s *ptr_end = data + size;

  do {
    *ptr = a_value;
  } while(++ptr < ptr_end);

  used = size;
}/*}}}*/

unsigned abbreviation_array_s::get_idx(abbreviation_s &a_value)
{/*{{{*/
  if (used == 0)
  {
    return c_idx_not_exist;
  }

  abbreviation_s *ptr = data;
  abbreviation_s *ptr_end = data + used;

  do {
    if (*ptr == a_value)
    {
      return ptr - data;
    }
  } while(++ptr < ptr_end);

  return c_idx_not_exist;
}/*}}}*/

abbreviation_array_s &abbreviation_array_s::operator=(abbreviation_array_s &a_src)
{/*{{{*/
  clear();

  if (a_src.used == 0)
  {
    return *this;
  }

  copy_resize(a_src.used);

  abbreviation_s *ptr = data;
  abbreviation_s *s_ptr = a_src.data;
  abbreviation_s *s_ptr_end = s_ptr + a_src.used;

  do {
    *ptr = *s_ptr;
  } while(++ptr,++s_ptr < s_ptr_end);

  used = a_src.used;
  return *this;
}/*}}}*/

bool abbreviation_array_s::operator==(abbreviation_array_s &a_second)
{/*{{{*/
  if (used != a_second.used)
  {
    return false;
  }

  if (used == 0)
  {
    return true;
  }

  abbreviation_s *ptr = data;
  abbreviation_s *ptr_end = ptr + used;
  abbreviation_s *s_ptr = a_second.data;

  do {
    if (!(*ptr == *s_ptr))
    {
      return false;
    }
  } while(++s_ptr,++ptr < ptr_end);

  return true;
}/*}}}*/

// LCOV_EXCL_STOP



unsigned abbreviation_array_s::get_idx_by_name(unsigned a_length,const char *a_data)
{/*{{{*/
   if (used == 0) return c_idx_not_exist;

   abbreviation_s *ptr = data;
   abbreviation_s *ptr_end = ptr + used;
   do {
      if (ptr->name.compare_char_ptr(a_length,a_data)) {
         return ptr - data;
      }
   } while(++ptr < ptr_end);

   return c_idx_not_exist;
}/*}}}*/

// -- container_parameters_s --
// --- struct container_parameters_s method definition ---
// LCOV_EXCL_START

// LCOV_EXCL_STOP



// -- processor_s --
// --- struct processor_s method definition ---
// LCOV_EXCL_START

// LCOV_EXCL_STOP




#define ARRAY_GEN_PARAMS FILE *out_file,abbreviation_array_s &abbreviations,unsigned abb_idx,unsigned type_abb_idx,data_type_s &type,data_type_s &data_type
#define ARRAY_GEN_VALUES out_file,abbreviations,abb_idx,type_abb_idx,type,data_type

void ARRAY_INIT(ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::init()\n"
"{/*{{{*/\n"
"  size = 0;\n"
"  used = 0;\n"
"  data = nullptr;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void ARRAY_INIT_SIZE(ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::init_size(unsigned a_size)\n"
"{/*{{{*/\n"
"  init();\n"
"  copy_resize(a_size);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void ARRAY_INIT_BUFFER(ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::init_buffer(unsigned a_size,%s *a_data)\n"
"{/*{{{*/\n"
"  init();\n"
"  set_buffer(a_size,a_data);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,TYPE_NAME);
}/*}}}*/

void ARRAY_CLEAR(ARRAY_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"inline void %s::clear()\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"void %s::clear()\n"
,IM_STRUCT_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
);
   if (TYPE_NUMBER & c_type_dynamic || !(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  if (data != nullptr)\n"
"  {\n"
);
      if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"    %s *ptr = data;\n"
"    %s *ptr_end = ptr + size;\n"
"\n"
"    do {\n"
"      ptr->clear();\n"
"    } while(++ptr < ptr_end);\n"
,TYPE_NAME,TYPE_NAME);
      }
      if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
         if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"\n"
);
         }
fprintf(out_file,
"    cfree(data);\n"
);
      }
fprintf(out_file,
"  }\n"
"\n"
);
   }
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  init();\n"
);
   }
   else {
fprintf(out_file,
"  used = 0;\n"
);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_SET_BUFFER(ARRAY_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"inline void %s::set_buffer(unsigned a_size,%s *a_data)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"void %s::set_buffer(unsigned a_size,%s *a_data)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
"  debug_assert(a_size != 0 && a_data != nullptr);\n"
"\n"
"  clear();\n"
);
   if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"\n"
"  %s *ptr = a_data;\n"
"  %s *ptr_end = a_data + a_size;\n"
"\n"
"  do {\n"
"    ptr->init();\n"
"  } while(++ptr < ptr_end);\n"
,TYPE_NAME,TYPE_NAME);
   }
fprintf(out_file,
"\n"
"  size = a_size;\n"
"  data = a_data;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_SET(ARRAY_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"inline void %s::set(unsigned a_used,%s *a_data)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"void %s::set(unsigned a_used,%s *a_data)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
);
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
fprintf(out_file,
"  debug_assert(a_used <= size);\n"
);
   }
fprintf(out_file,
"  debug_assert(a_data != nullptr);\n"
"\n"
"  clear();\n"
"\n"
"  if (a_used == 0)\n"
"  {\n"
"    return;\n"
"  }\n"
"\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  copy_resize(a_used);\n"
"\n"
);
   }
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"  memcpy(data,a_data,a_used*sizeof(%s));\n"
,TYPE_NAME);
   }
   else {
fprintf(out_file,
"  %s *ptr = data;\n"
"  %s *ptr_end = ptr + a_used;\n"
"  %s *a_ptr = a_data;\n"
"\n"
"  do {\n"
"    *ptr = *a_ptr;\n"
"  } while(++a_ptr,++ptr < ptr_end);\n"
"\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   }
fprintf(out_file,
"  used = a_used;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_FLUSH(ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::flush()\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  copy_resize(used);\n"
);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_FLUSH_ALL(ARRAY_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_flushable)) {
fprintf(out_file,
"inline void %s::flush_all()\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"void %s::flush_all()\n"
,IM_STRUCT_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  copy_resize(used);\n"
);
   }
   if (TYPE_NUMBER & c_type_flushable) {
      if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"\n"
);
      }
fprintf(out_file,
"  if (used == 0)\n"
"  {\n"
"    return;\n"
"  }\n"
"\n"
"  %s *ptr = data;\n"
"  %s *ptr_end = ptr + used;\n"
"\n"
"  do {\n"
"    ptr->flush_all();\n"
"  } while(++ptr < ptr_end);\n"
,TYPE_NAME,TYPE_NAME);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_SWAP(ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::swap(%s &a_second)\n"
"{/*{{{*/\n"
"  unsigned tmp_unsigned = size;\n"
"  size = a_second.size;\n"
"  a_second.size = tmp_unsigned;\n"
"\n"
"  tmp_unsigned = used;\n"
"  used = a_second.used;\n"
"  a_second.used = tmp_unsigned;\n"
"\n"
"  %s *tmp_data = data;\n"
"  data = a_second.data;\n"
"  a_second.data = tmp_data;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
}/*}}}*/

void ARRAY_OPERATOR_LE_BR_RE_BR(ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline %s &%s::operator[](unsigned a_idx)\n"
"{/*{{{*/\n"
"  debug_assert(a_idx < used);\n"
"  return data[a_idx];\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME,IM_STRUCT_NAME);
}/*}}}*/

void ARRAY_PUSH(ARRAY_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"inline void %s::push(%s a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"inline void %s::push(%s &a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  if (used >= size)\n"
"  {\n"
"    unsigned new_size = (size << 1) + c_array_add;\n"
"    debug_assert(new_size != 0);\n"
"\n"
"    copy_resize(new_size);\n"
"  }\n"
"\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert(used < size);\n"
);
   }
fprintf(out_file,
"  data[used++] = a_value;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_PUSH_BLANK(ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::push_blank()\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  if (used >= size)\n"
"  {\n"
"    unsigned new_size = (size << 1) + c_array_add;\n"
"    debug_assert(new_size != 0);\n"
"\n"
"    copy_resize(new_size);\n"
"  }\n"
"\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert(used < size);\n"
);
   }
fprintf(out_file,
"  used++;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_RESERVE(ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"void %s::reserve(unsigned a_cnt)\n"
"{/*{{{*/\n"
"  unsigned required_cnt = used + a_cnt;\n"
"  if (required_cnt > size)\n"
"  {\n"
"    unsigned r_size = size;\n"
"    do {\n"
"      r_size = (r_size << 1) + c_array_add;\n"
"    } while(r_size < required_cnt);\n"
"\n"
"    copy_resize(r_size);\n"
"  }\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void ARRAY_PUSH_BLANKS(ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"void %s::push_blanks(unsigned a_cnt)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  unsigned required_cnt = used + a_cnt;\n"
"  if (required_cnt > size)\n"
"  {\n"
"    unsigned r_size = size;\n"
"    do {\n"
"      r_size = (r_size << 1) + c_array_add;\n"
"    } while(r_size < required_cnt);\n"
"\n"
"    copy_resize(r_size);\n"
"  }\n"
"\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert(used + a_cnt <= size);\n"
);
   }
fprintf(out_file,
"  used += a_cnt;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_PUSH_CLEAR(ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::push_clear()\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  if (used >= size)\n"
"  {\n"
"    unsigned new_size = (size << 1) + c_array_add;\n"
"    debug_assert(new_size != 0);\n"
"\n"
"    copy_resize(new_size);\n"
"  }\n"
"\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert(used < size);\n"
);
   }
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"  used++;\n"
);
   }
   else {
fprintf(out_file,
"  data[used++].clear();\n"
);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_POP(ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline %s &%s::pop()\n"
"{/*{{{*/\n"
"  debug_assert(used > 0);\n"
"  return data[--used];\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME,IM_STRUCT_NAME);
}/*}}}*/

void ARRAY_LAST(ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline %s &%s::last()\n"
"{/*{{{*/\n"
"  debug_assert(used > 0);\n"
"  return data[used - 1];\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME,IM_STRUCT_NAME);
}/*}}}*/

void ARRAY_COPY_RESIZE(ARRAY_GEN_PARAMS)
{/*{{{*/
if (TYPE_NUMBER & c_type_option_strict_dynamic)
{/*{{{*/
fprintf(out_file,
"void %s::copy_resize(unsigned a_size)\n"
"{/*{{{*/\n"
"  debug_assert(a_size >= used);\n"
"\n"
"  %s *n_data;\n"
"\n"
"  if (a_size == 0)\n"
"  {\n"
"    n_data = nullptr;\n"
"  }\n"
"  else\n"
"  {\n"
"    n_data = (%s *)cmalloc(a_size*sizeof(%s));\n"
,IM_STRUCT_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);
fprintf(out_file,
"\n"
"    %s *ptr = n_data;\n"
"    %s *ptr_end = n_data + a_size;\n"
"\n"
"    do {\n"
"      ptr->init();\n"
"    } while(++ptr < ptr_end);\n"
"  }\n"
"\n"
,TYPE_NAME,TYPE_NAME);
fprintf(out_file,
"  if (used > 0)\n"
"  {\n"
"    %s *ptr = data;\n"
"    %s *ptr_end = ptr + used;\n"
"    %s *n_ptr = n_data;\n"
"\n"
"    do {\n"
"      n_ptr->swap(*ptr);\n"
"    } while(++n_ptr,++ptr < ptr_end);\n"
"  }\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME);
fprintf(out_file,
"\n"
"  if (size > used)\n"
"  {\n"
"    %s *ptr = data + used;\n"
"    %s *ptr_end = data + size;\n"
"\n"
"    do {\n"
"      ptr->clear();\n"
"    } while(++ptr < ptr_end);\n"
"  }\n"
"\n"
"  if (size != 0)\n"
"  {\n"
"    cfree(data);\n"
"  }\n"
"\n"
"  data = n_data;\n"
"  size = a_size;\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME,TYPE_NAME);
}/*}}}*/
else
{/*{{{*/
fprintf(out_file,
"void %s::copy_resize(unsigned a_size)\n"
"{/*{{{*/\n"
"  debug_assert(a_size >= used);\n"
,IM_STRUCT_NAME);
   if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"\n"
"  if (size > a_size)\n"
"  {\n"
"    %s *ptr = data + a_size;\n"
"    %s *ptr_end = data + size;\n"
"\n"
"    do {\n"
"      ptr->clear();\n"
"    } while(++ptr < ptr_end);\n"
"  }\n"
,TYPE_NAME,TYPE_NAME);
   }
fprintf(out_file,
"\n"
"  if (a_size == 0)\n"
"  {\n"
"    if (data != nullptr)\n"
"    {\n"
"      cfree(data);\n"
"    }\n"
"\n"
"    data = nullptr;\n"
"  }\n"
"  else\n"
"  {\n"
"    data = (%s *)crealloc(data,a_size*sizeof(%s));\n"
"  }\n"
,TYPE_NAME,TYPE_NAME);
   if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"\n"
"  if (a_size > size)\n"
"  {\n"
"    %s *ptr = data + size;\n"
"    %s *ptr_end = data + a_size;\n"
"\n"
"    do {\n"
"      ptr->init();\n"
"    } while(++ptr < ptr_end);\n"
"  }\n"
,TYPE_NAME,TYPE_NAME);
   }
fprintf(out_file,
"\n"
"  size = a_size;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/
}/*}}}*/

void ARRAY_FILL(ARRAY_GEN_PARAMS,unsigned type_idx)
{/*{{{*/
   if (type_idx == c_bt_bool || type_idx == c_bt_char || type_idx == c_bt_unsigned_char){
fprintf(out_file,
"inline void %s::fill(%s a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
      if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"void %s::fill(%s a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
      }
      else {
fprintf(out_file,
"void %s::fill(%s &a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
      }
   }
fprintf(out_file,
"{/*{{{*/\n"
"  if (size == 0)\n"
"  {\n"
"    return;\n"
"  }\n"
"\n"
);
   if (type_idx == c_bt_bool || type_idx == c_bt_char || type_idx == c_bt_unsigned_char) {
fprintf(out_file,
"  memset(data,a_value,size);\n"
);
   }
   else {
fprintf(out_file,
"  %s *ptr = data;\n"
"  %s *ptr_end = data + size;\n"
"\n"
"  do {\n"
"    *ptr = a_value;\n"
"  } while(++ptr < ptr_end);\n"
,TYPE_NAME,TYPE_NAME);
   }
fprintf(out_file,
"\n"
"  used = size;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_GET_IDX(ARRAY_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"unsigned %s::get_idx(%s a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"unsigned %s::get_idx(%s &a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
"  if (used == 0)\n"
"  {\n"
"    return c_idx_not_exist;\n"
"  }\n"
"\n"
"  %s *ptr = data;\n"
"  %s *ptr_end = data + used;\n"
"\n"
"  do {\n"
"    if (*ptr == a_value)\n"
"    {\n"
"      return ptr - data;\n"
"    }\n"
"  } while(++ptr < ptr_end);\n"
"\n"
"  return c_idx_not_exist;\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME,TYPE_NAME);
}/*}}}*/

void ARRAY_OPERATOR_EQUAL(ARRAY_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"inline %s &%s::operator=(%s &a_src)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"%s &%s::operator=(%s &a_src)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
);
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
fprintf(out_file,
"  debug_assert(a_src.used <= size);\n"
"\n"
);
   }
fprintf(out_file,
"  clear();\n"
"\n"
"  if (a_src.used == 0)\n"
"  {\n"
"    return *this;\n"
"  }\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"\n"
"  copy_resize(a_src.used);\n"
);
   }
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"\n"
"  memcpy(data,a_src.data,a_src.used*sizeof(%s));\n"
,TYPE_NAME);
   }
   else {
fprintf(out_file,
"\n"
"  %s *ptr = data;\n"
"  %s *s_ptr = a_src.data;\n"
"  %s *s_ptr_end = s_ptr + a_src.used;\n"
"\n"
"  do {\n"
"    *ptr = *s_ptr;\n"
"  } while(++ptr,++s_ptr < s_ptr_end);\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   }
fprintf(out_file,
"\n"
"  used = a_src.used;\n"
"  return *this;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_OPERATOR_DOUBLE_EQUAL(ARRAY_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"inline bool %s::operator==(%s &a_second)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"bool %s::operator==(%s &a_second)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
"  if (used != a_second.used)\n"
"  {\n"
"    return false;\n"
"  }\n"
"\n"
"  if (used == 0)\n"
"  {\n"
"    return true;\n"
"  }\n"
);
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"\n"
"  return (memcmp(data,a_second.data,used*sizeof(%s)) == 0);\n"
,TYPE_NAME);
   }
   else {
fprintf(out_file,
"\n"
"  %s *ptr = data;\n"
"  %s *ptr_end = ptr + used;\n"
"  %s *s_ptr = a_second.data;\n"
"\n"
"  do {\n"
"    if (!(*ptr == *s_ptr))\n"
"    {\n"
"      return false;\n"
"    }\n"
"  } while(++s_ptr,++ptr < ptr_end);\n"
"\n"
"  return true;\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void processor_s::generate_array_type()
{/*{{{*/
   string_array_s &type_names = cont_params.types;
   string_array_s &fun_defs = cont_params.functions;
   string_array_s &abbs = cont_params.names;

   if (type_names.used != 1) {
      fprintf(stderr,"array: not given name (or too many names) of contained type\n");
      cassert(0);
   }

   if (abbs.used < 1) {
      fprintf(stderr,"array: not given name of generated structure\n");
      cassert(0);
   }

   unsigned type_abb_idx = abbreviations.get_idx_by_name(type_names[0].size - 1,type_names[0].data);
   if (type_abb_idx == c_idx_not_exist) {
      fprintf(stderr,"array: contained type \"%s\" does not exist\n",type_names[0].data);
      cassert(0);
   }

   unsigned type_idx = abbreviations[type_abb_idx].data_type_idx;
   string_s real_name;
   real_name.init();

   {
      data_type_s &type = data_types[type_idx];

      // - test type options -
      if (type.properties & c_type_option_strict_dynamic) {
         cassert(type.properties & c_type_dynamic);
      }

      real_name.conc_set(type.name.size - 1,type.name.data,strlen(c_cont_postfixes[c_cont_array]),(char *)c_cont_postfixes[c_cont_array]);
   }

   string_s &data_type_name = abbs[0];

   unsigned data_type_idx;

   if ((data_type_idx = abbreviations.get_idx_by_name(data_type_name.size - 1,data_type_name.data)) == c_idx_not_exist) {

      // - do not report duplicate structures -
      //unsigned d_idx = data_types.get_idx_by_real_name(real_name.size - 1,real_name.data);
      //if (d_idx != c_idx_not_exist) {
      //   fprintf(stderr,"DUPLICATE STRUCTURES: %s <-> %s\n",data_type_name.data,data_types[d_idx].name.data);
      //}

      data_types.push_blank();
      data_type_s &data_type = data_types.last();

      data_type.cont_idx = c_cont_array;
      data_type.name.set(data_type_name.size - 1,data_type_name.data);
      data_type.real_name.swap(real_name);

      data_type.properties = c_type_dynamic | c_type_flushable | (type_settings & c_type_option_mask);

      data_type.types.push(abbreviations[type_abb_idx].name);

      data_type_idx = data_types.used - 1;
   }
   else {
      fprintf(stderr,"array: name of generated structure \"%s\" is already used\n",data_type_name.data);
      cassert(0);
   }

   real_name.clear();

   // - check and write abbreviations -
   if (abbs.used != 0) {
      unsigned idx = 0;
      do {
         string_s &abb = abbs[idx];

         if (abbreviations.get_idx_by_name(abb.size - 1,abb.data) != c_idx_not_exist) {
            fprintf(stderr,"array: abreviated name \"%s\" for generated structure is already used\n",abb.data);
            cassert(0);
         }

         abbreviations.push_blank();
         abbreviations.last().set(abb,data_type_idx);
      } while(++idx < abbs.used);
   }

   data_type_s &type = data_types[type_idx];
   data_type_s &data_type = data_types[data_type_idx];

   if (gen_options & c_option_gen_code &&
      (include_level == 0 || gen_options & c_option_gen_includes))
   {
   // --- definition of structure array ---

fprintf(out_file,
"// --- struct %s definition --- \n"
"\n"
,STRUCT_NAME);

   if (abbs.used > 1) {
      unsigned idx = 1;
      do {
fprintf(out_file,
"typedef struct %s %s;\n"
,abbs[0].data,abbs[idx].data);
      } while(++idx < abbs.used);
fprintf(out_file,
"\n"
);
   }

fprintf(out_file,
"/*!\n"
" * \\brief __GEN array of type %s\n"
" */\n"
"struct %s\n"
"{\n"
"  unsigned size; //!< actual size of allocated space in array\n"
"  unsigned used; //!< count of used space in array\n"
"  %s *data; //!< pointer to array elements\n"
"\n"
,TYPE_NAME,STRUCT_NAME,TYPE_NAME);
fprintf(out_file,
"  %s() = default;\n"
"  %s(%s &a_src) = delete;\n"
"\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_nogen_init)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN initialize array\n"
"    */\n"
"  inline void init();\n"
"\n"
);
   }
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN initialize array of requested size\n"
"    * \\param a_size - requested size of array\n"
"    */\n"
"  inline void init_size(unsigned a_size);\n"
"\n"
);
   }
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN initialize/set underlaying data buffer\n"
"    * \\param a_size - size of data buffer\n"
"    * \\param a_data - pointer to data buffer\n"
"    */\n"
"  inline void init_buffer(unsigned a_size,%s *a_data);\n"
"\n"
,TYPE_NAME);
   }
   if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
      if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN release memory used by array\n"
"    */\n"
"  inline void clear();\n"
"\n"
);
      }
      else {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN release memory used by array\n"
"    */\n"
"  EXPORT void clear();\n"
"\n"
);
      }
   }
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
     if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN set underlaying data buffer\n"
"    * \\param a_size - size of data buffer\n"
"    * \\param a_data - pointer to data buffer\n"
"    */\n"
"  inline void set_buffer(unsigned a_size,%s *a_data);\n"
"\n"
,TYPE_NAME);
      }
      else {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN set underlaying data buffer\n"
"    * \\param a_size - size of data buffer\n"
"    * \\param a_data - pointer to data buffer\n"
"    */\n"
"  EXPORT void set_buffer(unsigned a_size,%s *a_data);\n"
"\n"
,TYPE_NAME);
      }
   }
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN set array content from element pointer\n"
"    * \\param a_used - number of elements stored at pointed location\n"
"    * \\param a_data - pointer to elements\n"
"    */\n"
"  inline void set(unsigned a_used,%s *a_data);\n"
"\n"
,TYPE_NAME);
   }
   else {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN set array content from element pointer\n"
"    * \\param a_used - number of elements stored at pointed location\n"
"    * \\param a_data - pointer to elements\n"
"    */\n"
"  EXPORT void set(unsigned a_used,%s *a_data);\n"
"\n"
,TYPE_NAME);
   }
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN flush array memory usage\n"
"    */\n"
"  inline void flush();\n"
"\n"
);
   if (!(TYPE_NUMBER & c_type_flushable)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN flush array memory usage, recursive on elemenets\n"
"    */\n"
"  inline void flush_all();\n"
"\n"
);
   }
   else {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN flush array memory usage, recursive on elemenets\n"
"    */\n"
"  EXPORT void flush_all();\n"
"\n"
);
   }
   if (!(STRUCT_NUMBER & c_type_option_nogen_swap)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN swap array members with another array\n"
"    * \\param a_second - reference to another array\n"
"    */\n"
"  inline void swap(%s &a_second);\n"
"\n"
,STRUCT_NAME);
   }
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN select element of array\n"
"    * \\param a_idx - index of element in array\n"
"    * \\return reference to element of array\n"
"    */\n"
"  inline %s &operator[](unsigned a_idx);\n"
"\n"
,TYPE_NAME);
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN insert element to end of array\n"
"    * \\param a_value - value of inserted element\n"
"    */\n"
"  inline void push(%s a_value);\n"
"\n"
,TYPE_NAME);
   }
   else {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN insert element to end of array\n"
"    * \\param a_value - reference to inserted value\n"
"    */\n"
"  inline void push(%s &a_value);\n"
"\n"
,TYPE_NAME);
   }
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN insert blank element to end of array\n"
"    */\n"
"  inline void push_blank();\n"
"\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN reserve requested count of elements at end of array\n"
"    * \\param a_cnt - count of elements to be reserved\n"
"    */\n"
"  EXPORT void reserve(unsigned a_cnt);\n"
"\n"
);
   }
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN insert blank elements to end of array\n"
"    * \\param a_cnt - count of elements inserted to array\n"
"    */\n"
"  EXPORT void push_blanks(unsigned a_cnt);\n"
"\n"
"  /*!\n"
"    * \\brief __GEN insert and clear element to end of array\n"
"    */\n"
"  inline void push_clear();\n"
"\n"
"  /*!\n"
"    * \\brief __GEN return value of last element in array, and remove it\n"
"    * \\return reference to last element\n"
"    */\n"
"  inline %s &pop();\n"
"\n"
"  /*!\n"
"    * \\brief __GEN return value of last element in array\n"
"    * \\return reference to last element\n"
"    */\n"
"  inline %s &last();\n"
"\n"
,TYPE_NAME,TYPE_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN change array capacity\n"
"    * \\param a_size - requested array capacity\n"
"    */\n"
"  EXPORT void copy_resize(unsigned a_size);\n"
"\n"
);
   }
   if (type_idx == c_bt_bool || type_idx == c_bt_char || type_idx == c_bt_unsigned_char) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN set all elements of array to given value\n"
"    * \\param a_value - new value of all elements\n"
"    */\n"
"  inline void fill(%s a_value);\n"
"\n"
,TYPE_NAME);
   }
   else {
      if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN set all elements of array to given value\n"
"    * \\param a_value - new value of all elements\n"
"    */\n"
"  EXPORT void fill(%s a_value);\n"
"\n"
,TYPE_NAME);
      }
      else {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN set all elements of array to given value\n"
"    * \\param a_value - new value of all elements\n"
"    */\n"
"  EXPORT void fill(%s &a_value);\n"
"\n"
,TYPE_NAME);
      }
   }
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN search for index of element\n"
"    * \\param a_value - value which index is searched\n"
"    */\n"
"  EXPORT unsigned get_idx(%s a_value);\n"
"\n"
,TYPE_NAME);
   }
   else {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN search for index of element\n"
"    * \\param a_value - value which index is searched\n"
"    */\n"
"  EXPORT unsigned get_idx(%s &a_value);\n"
"\n"
,TYPE_NAME);
   }
   if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
      if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN copy array from another array\n"
"    * \\param a_src - reference to another array\n"
"    * \\return reference to this array\n"
"    */\n"
"  inline %s &operator=(%s &a_src);\n"
"\n"
,STRUCT_NAME,STRUCT_NAME);
      }
      else
      {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN copy array from another array\n"
"    * \\param a_src - reference to another array\n"
"    */\n"
"  EXPORT %s &operator=(%s &a_src);\n"
"\n"
,STRUCT_NAME,STRUCT_NAME);
      }
   }
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN comparison of array with another array\n"
"    * \\param a_second - reference to another array\n"
"    * \\return result of comparison\n"
"    */\n"
"  inline bool operator==(%s &a_second);\n"
"\n"
,STRUCT_NAME);
   }
   else {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN comparison of array with another array\n"
"    * \\param a_second - reference to another array\n"
"    * \\return result of comparison\n"
"    */\n"
"  EXPORT bool operator==(%s &a_second);\n"
"\n"
,STRUCT_NAME);
   }
   if (fun_defs.used != 0) {
      unsigned f_idx = 0;
      do {
fprintf(out_file,
"  %s\n"
,fun_defs[f_idx].data);
      } while(++f_idx < fun_defs.used);
   }
fprintf(out_file,
"};\n"
"\n"
);
   }
}/*}}}*/

void processor_s::generate_array_inlines(unsigned abb_idx,unsigned a_dt_idx)
{/*{{{*/
   data_type_s &data_type = data_types[a_dt_idx];

   string_s &type_abb_string = data_type.types[0];
   unsigned type_abb_idx = abbreviations.get_idx_by_name(type_abb_string.size - 1,type_abb_string.data);

   if (type_abb_idx == c_idx_not_exist) {
      fprintf(stderr,"array: inlines: abbreviated type name \"%s\" does not exist\n",type_abb_string.data);
      cassert(0);
   }

   unsigned type_idx = abbreviations[type_abb_idx].data_type_idx;
   data_type_s &type = data_types[type_idx];

   if (gen_options & c_option_gen_code &&
      (include_level == 0 || gen_options & c_option_gen_includes))
   {
   // --- definition of inline methods ---

fprintf(out_file,
"// --- struct %s inline method definition ---\n"
"// LCOV_EXCL_START\n"
"\n"
,IM_STRUCT_NAME);

   // - array init method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_init)) {
ARRAY_INIT(ARRAY_GEN_VALUES);
   }

   // - array init_size method -
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
ARRAY_INIT_SIZE(ARRAY_GEN_VALUES);
   }

   // - array init_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
ARRAY_INIT_BUFFER(ARRAY_GEN_VALUES);
   }

   // - array clear method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
ARRAY_CLEAR(ARRAY_GEN_VALUES);
      }
   }

   // - array set_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer && !(TYPE_NUMBER & c_type_dynamic)) {
ARRAY_SET_BUFFER(ARRAY_GEN_VALUES);
   }

   // - array set method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
ARRAY_SET(ARRAY_GEN_VALUES);
   }

   // - array_flush_method -
ARRAY_FLUSH(ARRAY_GEN_VALUES);

   // - array flush_all method -
   if (!(TYPE_NUMBER & c_type_flushable)) {
ARRAY_FLUSH_ALL(ARRAY_GEN_VALUES);
   }

   // - array swap method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_swap)) {
ARRAY_SWAP(ARRAY_GEN_VALUES);
   }

   // - array operator[] method -
ARRAY_OPERATOR_LE_BR_RE_BR(ARRAY_GEN_VALUES);

   // - array push method -
ARRAY_PUSH(ARRAY_GEN_VALUES);

   // - array push_blank method -
ARRAY_PUSH_BLANK(ARRAY_GEN_VALUES);

   // - array reserve method -

   // - array push_blanks method -

   // - array push_clear method -
ARRAY_PUSH_CLEAR(ARRAY_GEN_VALUES);

   // - array pop method -
ARRAY_POP(ARRAY_GEN_VALUES);

   // - array last method -
ARRAY_LAST(ARRAY_GEN_VALUES);

   // - array copy_resize method -

   // - array fill method -
   if (type_idx == c_bt_bool || type_idx == c_bt_char || type_idx == c_bt_unsigned_char) {
ARRAY_FILL(ARRAY_GEN_VALUES,type_idx);
   }

   // - array get_idx method -

   // - array operator= method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
ARRAY_OPERATOR_EQUAL(ARRAY_GEN_VALUES);
      }
   }

   // - array operator== method -
   if (TYPE_NUMBER & c_type_basic) {
ARRAY_OPERATOR_DOUBLE_EQUAL(ARRAY_GEN_VALUES);
   }

fprintf(out_file,
"// LCOV_EXCL_STOP\n"
"\n");
   }
}/*}}}*/

void processor_s::generate_array_methods(unsigned abb_idx,unsigned a_dt_idx)
{/*{{{*/
   data_type_s &data_type = data_types[a_dt_idx];

   string_s &type_abb_string = data_type.types[0];
   unsigned type_abb_idx = abbreviations.get_idx_by_name(type_abb_string.size - 1,type_abb_string.data);

   if (type_abb_idx == c_idx_not_exist) {
      fprintf(stderr,"array: methods: abreviated type name \"%s\" does not exist\n",type_abb_string.data);
      cassert(0);
   }

   unsigned type_idx = abbreviations[type_abb_idx].data_type_idx;
   data_type_s &type = data_types[type_idx];

   if (gen_options & c_option_gen_code &&
      (include_level == 0 || gen_options & c_option_gen_includes))
   {
   // --- definition of methods ---

fprintf(out_file,
"// --- struct %s method definition ---\n"
"// LCOV_EXCL_START\n"
"\n"
,IM_STRUCT_NAME);

   // - array init method -

   // - array init_size method -

   // - array init_buffer method -

   // - array clear method -
   if (TYPE_NUMBER & c_type_dynamic) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
ARRAY_CLEAR(ARRAY_GEN_VALUES);
      }
   }

   // - array set_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer && TYPE_NUMBER & c_type_dynamic) {
ARRAY_SET_BUFFER(ARRAY_GEN_VALUES);
   }

   // - array set method -
   if (TYPE_NUMBER & c_type_dynamic) {
ARRAY_SET(ARRAY_GEN_VALUES);
   }

   // - array_flush_method -

   // - array flush_all method -
   if (TYPE_NUMBER & c_type_flushable) {
ARRAY_FLUSH_ALL(ARRAY_GEN_VALUES);
   }

   // - array swap method -

   // - array operator[] method -

   // - array push method -

   // - array push_blank method -

   // - array reserve method -
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
ARRAY_RESERVE(ARRAY_GEN_VALUES);
   }

   // - array push_blanks method -
ARRAY_PUSH_BLANKS(ARRAY_GEN_VALUES);

   // - array push_clear method -

   // - array pop method -

   // - array last method -

   // - array copy_resize method -
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
ARRAY_COPY_RESIZE(ARRAY_GEN_VALUES);
   }

   // - array fill method -
   if (type_idx != c_bt_bool && type_idx != c_bt_char && type_idx != c_bt_unsigned_char) {
ARRAY_FILL(ARRAY_GEN_VALUES,type_idx);
   }

   // - array get_idx method -
ARRAY_GET_IDX(ARRAY_GEN_VALUES);

   // - array operator= method -
   if (TYPE_NUMBER & c_type_dynamic) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
ARRAY_OPERATOR_EQUAL(ARRAY_GEN_VALUES);
      }
   }

   // - array operator== method -
   if (!(TYPE_NUMBER & c_type_basic)) {
ARRAY_OPERATOR_DOUBLE_EQUAL(ARRAY_GEN_VALUES);
   }

fprintf(out_file,
"// LCOV_EXCL_STOP\n"
"\n");
   }
}/*}}}*/


#define QUEUE_GEN_PARAMS FILE *out_file,abbreviation_array_s &abbreviations,unsigned abb_idx,unsigned type_abb_idx,data_type_s &type,data_type_s &data_type
#define QUEUE_GEN_VALUES out_file,abbreviations,abb_idx,type_abb_idx,type,data_type

void  QUEUE_INIT(QUEUE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::init()\n"
"{/*{{{*/\n"
"  size = 0;\n"
"  used = 0;\n"
"  begin = 0;\n"
"  data = nullptr;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void  QUEUE_INIT_SIZE(QUEUE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::init_size(unsigned a_size)\n"
"{/*{{{*/\n"
"  init();\n"
"  copy_resize(a_size);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void QUEUE_INIT_BUFFER(QUEUE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::init_buffer(unsigned a_size,%s *a_data)\n"
"{/*{{{*/\n"
"  init();\n"
"  set_buffer(a_size,a_data);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,TYPE_NAME);
}/*}}}*/

void  QUEUE_CLEAR(QUEUE_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"inline void %s::clear()\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"void %s::clear()\n"
,IM_STRUCT_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
);
   if (TYPE_NUMBER & c_type_dynamic || !(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  if (data != nullptr)\n"
"  {\n"
);
      if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"    %s *ptr = data;\n"
"    %s *ptr_end = ptr + size;\n"
"\n"
"    do {\n"
"      ptr->clear();\n"
"    } while(++ptr < ptr_end);\n"
,TYPE_NAME,TYPE_NAME);
      }
      if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
         if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"\n"
);
         }
fprintf(out_file,
"    cfree(data);\n"
);
      }
fprintf(out_file,
"  }\n"
"\n"
);
   }
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  init();\n"
);
   }
   else {
fprintf(out_file,
"  this->used = 0;\n"
"  this->begin = 0;\n"
);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void QUEUE_SET_BUFFER(QUEUE_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"inline void %s::set_buffer(unsigned a_size,%s *a_data)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"void %s::set_buffer(unsigned a_size,%s *a_data)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
"  debug_assert(a_size != 0 && a_data != nullptr);\n"
"\n"
"  clear();\n"
);
   if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"\n"
"  %s *ptr = a_data;\n"
"  %s *ptr_end = a_data + a_size;\n"
"\n"
"  do {\n"
"    ptr->init();\n"
"  } while(++ptr < ptr_end);\n"
,TYPE_NAME,TYPE_NAME);
   }
fprintf(out_file,
"\n"
"  size = a_size;\n"
"  data = a_data;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void  QUEUE_FLUSH(QUEUE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::flush()\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  copy_resize(used);\n"
);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void  QUEUE_FLUSH_ALL(QUEUE_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_flushable)) {
fprintf(out_file,
"inline void %s::flush_all()\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"void %s::flush_all()\n"
,IM_STRUCT_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  copy_resize(used);\n"
);
   }
   if (TYPE_NUMBER & c_type_flushable) {
      if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"\n"
);
      }
fprintf(out_file,
"  if (used == 0)\n"
"  {\n"
"    return;\n"
"  }\n"
"\n"
"  %s *ptr = data;\n"
"  %s *ptr_end = ptr + used;\n"
"\n"
"  do {\n"
"    ptr->flush_all();\n"
"  } while(++ptr < ptr_end);\n"
,TYPE_NAME,TYPE_NAME);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void  QUEUE_SWAP(QUEUE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::swap(%s &a_second)\n"
"{/*{{{*/\n"
"  unsigned tmp_unsigned = size;\n"
"  size = a_second.size;\n"
"  a_second.size = tmp_unsigned;\n"
"\n"
"  tmp_unsigned = used;\n"
"  used = a_second.used;\n"
"  a_second.used = tmp_unsigned;\n"
"\n"
"  tmp_unsigned = begin;\n"
"  begin = a_second.begin;\n"
"  a_second.begin = tmp_unsigned;\n"
"\n"
"  %s *tmp_data = data;\n"
"  data = a_second.data;\n"
"  a_second.data = tmp_data;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
}/*}}}*/

void  QUEUE_INSERT(QUEUE_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"inline void %s::insert(%s a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"inline void %s::insert(%s &a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  if (used >= size)\n"
"  {\n"
"    unsigned new_size = (size << 1) + c_array_add;\n"
"    debug_assert(new_size != 0);\n"
"\n"
"    copy_resize(new_size);\n"
"  }\n"
"\n"
);
  }
  else {
fprintf(out_file,
"  debug_assert(used < size);\n"
);
  }
fprintf(out_file,
"  unsigned inserted_idx = begin + used++;\n"
"\n"
"  if (inserted_idx >= size)\n"
"  {\n"
"    inserted_idx -= size;\n"
"  }\n"
"\n"
"  data[inserted_idx] = a_value;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void  QUEUE_INSERT_BLANK(QUEUE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::insert_blank()\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  if (used >= size)\n"
"  {\n"
"    unsigned new_size = (size << 1) + c_array_add;\n"
"    debug_assert(new_size != 0);\n"
"\n"
"    copy_resize(new_size);\n"
"  }\n"
"\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert(used < size);\n"
);
   }
fprintf(out_file,
"  ++used;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void  QUEUE_NEXT(QUEUE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline %s &%s::next()\n"
"{/*{{{*/\n"
"  debug_assert(used > 0);\n"
"\n"
"  unsigned ret_idx = begin;\n"
"\n"
"  if (++begin >= size)\n"
"  {\n"
"    begin = 0;\n"
"  }\n"
"\n"
"  used--;\n"
"\n"
"  return data[ret_idx];\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME,IM_STRUCT_NAME);
}/*}}}*/

void  QUEUE_LAST(QUEUE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline %s &%s::last()\n"
"{/*{{{*/\n"
"  debug_assert(used > 0);\n"
"\n"
"  unsigned last_idx = begin + (used - 1);\n"
"  if (last_idx >= size)\n"
"  {\n"
"    return data[last_idx - size];\n"
"  }\n"
"\n"
"  return data[last_idx];\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME,IM_STRUCT_NAME);
}/*}}}*/

void  QUEUE_COPY_RESIZE(QUEUE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"void %s::copy_resize(unsigned a_size)\n"
"{/*{{{*/\n"
"  debug_assert(a_size >= used);\n"
"\n"
"  %s *n_data;\n"
"\n"
"  if (a_size == 0)\n"
"  {\n"
"    n_data = nullptr;\n"
"  }\n"
"  else\n"
"  {\n"
"    n_data = (%s *)cmalloc(a_size*sizeof(%s));\n"
,IM_STRUCT_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"\n"
"    if (a_size > used)\n"
"    {\n"
"      debug_assert(memset(n_data + used,0,(a_size - used)*sizeof(%s)) == (n_data + used));\n"
"\n"
"      %s *ptr = n_data + used;\n"
"      %s *ptr_end = n_data + a_size;\n"
"\n"
"      do {\n"
"        ptr->init();\n"
"      } while(++ptr < ptr_end);\n"
"    }\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   }
fprintf(out_file,
"  }\n"
"\n"
"  if (used != 0)\n"
"  {\n"
"    unsigned fir_cnt;\n"
"    unsigned sec_cnt;\n"
"\n"
"    if (begin + used > size)\n"
"    {\n"
"      sec_cnt = begin + used - size;\n"
"      fir_cnt = used - sec_cnt;\n"
"    }\n"
"    else\n"
"    {\n"
"      fir_cnt = used;\n"
"      sec_cnt = 0;\n"
"    }\n"
"\n"
"    memcpy(n_data,data + begin,fir_cnt*sizeof(%s));\n"
"\n"
"    if (sec_cnt != 0)\n"
"    {\n"
"      memcpy(n_data + fir_cnt,data,sec_cnt*sizeof(%s));\n"
"    }\n"
"  }\n"
"\n"
,TYPE_NAME,TYPE_NAME);
   if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"  if (size > used)\n"
"  {\n"
"    %s *ptr;\n"
"    %s *ptr_end;\n"
"    %s *s_ptr;\n"
"\n"
"    if (begin + used >= size)\n"
"    {\n"
"      ptr = data + (begin + used - size);\n"
"      ptr_end = data + begin;\n"
"      s_ptr = nullptr;\n"
"    }\n"
"    else\n"
"    {\n"
"      ptr = data;\n"
"      ptr_end = data + begin;\n"
"      s_ptr = ptr_end + used;\n"
"    }\n"
"\n"
"    if (ptr < ptr_end)\n"
"    {\n"
"      do {\n"
"        ptr->clear();\n"
"      } while(++ptr < ptr_end);\n"
"    }\n"
"\n"
"    if (s_ptr != nullptr)\n"
"    {\n"
"      %s *s_ptr_end = data + size;\n"
"      do {\n"
"        s_ptr->clear();\n"
"      } while(++s_ptr < s_ptr_end);\n"
"    }\n"
"  }\n"
"\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   }
fprintf(out_file,
"  if (size != 0)\n"
"  {\n"
"    cfree(data);\n"
"  }\n"
"\n"
"  data = n_data;\n"
"  size = a_size;\n"
"  begin = 0;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void  QUEUE_OPERATOR_EQUAL(QUEUE_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"inline %s &%s::operator=(%s &a_src)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"%s &%s::operator=(%s &a_src)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
);
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
fprintf(out_file,
"  debug_assert(a_src.used <= size);\n"
"\n"
);
   }
fprintf(out_file,
"  clear();\n"
"\n"
"  if (a_src.used == 0)\n"
"  {\n"
"    return *this;\n"
"  }\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"\n"
"  copy_resize(a_src.used);\n"
);
   }
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"\n"
"  unsigned fir_cnt;\n"
"  unsigned sec_cnt;\n"
"\n"
"  if (a_src.begin + a_src.used > a_src.size)\n"
"  {\n"
"    sec_cnt = a_src.begin + a_src.used - a_src.size;\n"
"    fir_cnt = a_src.used - sec_cnt;\n"
"  }\n"
"  else\n"
"  {\n"
"    fir_cnt = a_src.used;\n"
"    sec_cnt = 0;\n"
"  }\n"
"\n"
"  memcpy(data,a_src.data + a_src.begin,fir_cnt*sizeof(%s));\n"
"\n"
"  if (sec_cnt != 0)\n"
"  {\n"
"    memcpy(data + fir_cnt,a_src.data,sec_cnt*sizeof(%s));\n"
"  }\n"
"\n"
,TYPE_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"\n"
"  unsigned sec_cnt;\n"
"  %s *ptr = data;\n"
"  %s *s_ptr = a_src.data + a_src.begin;\n"
"  %s *s_ptr_end;\n"
"\n"
"  if (a_src.begin + a_src.used > a_src.size)\n"
"  {\n"
"    s_ptr_end = a_src.data + a_src.size;\n"
"    sec_cnt = a_src.begin + a_src.used - a_src.size;\n"
"  }\n"
"  else\n"
"  {\n"
"    s_ptr_end = s_ptr + a_src.used;\n"
"    sec_cnt = 0;\n"
"  }\n"
"\n"
"  do {\n"
"    *ptr = *s_ptr; \n"
"  } while(++ptr,++s_ptr < s_ptr_end);\n"
"\n"
"  if (sec_cnt != 0)\n"
"  {\n"
"    s_ptr = a_src.data;\n"
"    s_ptr_end = s_ptr + sec_cnt;\n"
"\n"
"    do {\n"
"      *ptr = *s_ptr;\n"
"    } while(++ptr,++s_ptr < s_ptr_end);\n"
"  }\n"
"\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   }
fprintf(out_file,
"  used = a_src.used;\n"
"  return *this;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void  QUEUE_OPERATOR_DOUBLE_EQUAL(QUEUE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"bool %s::operator==(%s &a_second)\n"
"{/*{{{*/\n"
"  if (used != a_second.used)\n"
"  {\n"
"    return false;\n"
"  }\n"
"\n"
"  if (used == 0)\n"
"  {\n"
"    return true;\n"
"  }\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"  bool _break;\n"
"  bool s_break;\n"
"  unsigned pos;\n"
"  unsigned pos_end;\n"
"  unsigned s_pos;\n"
"\n"
"  _break = (begin + used > size);\n"
"  s_break = (a_second.begin + a_second.used > a_second.size);\n"
"  pos = begin;\n"
"  s_pos = a_second.begin;\n"
"\n"
"  if (_break)\n"
"  {\n"
"    pos_end = begin + used - size;\n"
"  }\n"
"  else\n"
"  {\n"
"    pos_end = begin + used;\n"
"  }\n"
"\n"
"  do {\n"
"    if (_break)\n"
"    {\n"
"      unsigned offset = size - pos;\n"
"\n"
"      if (s_break)\n"
"      {\n"
"        unsigned s_offset = a_second.size - s_pos;\n"
"\n"
"        if (offset < s_offset)\n"
"        {\n"
"          if (memcmp(data + pos,a_second.data + s_pos,offset*sizeof(%s)) != 0)\n"
"          {\n"
"            return false;\n"
"          }\n"
"\n"
"          s_pos += offset;\n"
"          pos = 0;\n"
"          _break = false;\n"
"        }\n"
"        else\n"
"        {\n"
"          if (memcmp(data + pos,a_second.data + s_pos,s_offset*sizeof(%s)) != 0)\n"
"          {\n"
"            return false;\n"
"          }\n"
"\n"
"          if ((pos += s_offset) >= size)\n"
"          {\n"
"            pos = 0;\n"
"            _break = false;\n"
"          }\n"
"          s_pos = 0;\n"
"          s_break = false;\n"
"        }\n"
"      }\n"
"      else\n"
"      {\n"
"        if (memcmp(data + pos,a_second.data + s_pos,offset*sizeof(%s)) != 0)\n"
"        {\n"
"          return false;\n"
"        }\n"
"        s_pos += offset;\n"
"        pos = 0;\n"
"        _break = false;\n"
"      }\n"
"    }\n"
"    else\n"
"    {\n"
"      if (s_break)\n"
"      {\n"
"        unsigned s_offset = a_second.size - s_pos;\n"
"\n"
"        if (memcmp(data + pos,a_second.data + s_pos,s_offset*sizeof(%s)) != 0)\n"
"        {\n"
"          return false;\n"
"        }\n"
"        pos += s_offset;\n"
"        s_pos = 0;\n"
"        s_break = false;\n"
"      }\n"
"      else\n"
"      {\n"
"        return memcmp(data + pos,a_second.data + s_pos,(pos_end - pos)*sizeof(%s)) == 0;\n"
"      }\n"
"    }\n"
"  } while(true);\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"  %s *ptr = data + begin;\n"
"  %s *ptr_break = data + size;\n"
"  %s *ptr_end;\n"
"  %s *s_ptr = a_second.data + a_second.begin;\n"
"  %s *s_ptr_break = a_second.data + a_second.size;\n"
"\n"
"  if (begin + used > size)\n"
"  {\n"
"    ptr_end = data + (begin + used - size);\n"
"  }\n"
"  else\n"
"  {\n"
"    ptr_end = ptr + used;\n"
"  }\n"
"\n"
"  do {\n"
"    if (!(*ptr == *s_ptr))\n"
"    {\n"
"      return false;\n"
"    }\n"
"\n"
"    if (++ptr >= ptr_break)\n"
"    {\n"
"      ptr = data;\n"
"    }\n"
"\n"
"    if (++s_ptr >= s_ptr_break)\n"
"    {\n"
"      s_ptr = a_second.data;\n"
"    }\n"
"\n"
"  } while(ptr != ptr_end);\n"
"\n"
"  return true;\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void processor_s::generate_queue_type()
{/*{{{*/
   string_array_s &type_names = cont_params.types;
   string_array_s &fun_defs = cont_params.functions;
   string_array_s &abbs = cont_params.names;

   if (type_names.used != 1) {
      fprintf(stderr,"queue: not given name (or too many names) of contained type\n");
      cassert(0);
   }

   if (abbs.used < 1) {
      fprintf(stderr,"queue: not given name of generated structures\n");
      cassert(0);
   }

   unsigned type_abb_idx = abbreviations.get_idx_by_name(type_names[0].size - 1,type_names[0].data);
   if (type_abb_idx == c_idx_not_exist) {
      fprintf(stderr,"queue: contained type \"%s\" does not exist\n",type_names[0].data);
      cassert(0);
   }

   unsigned type_idx = abbreviations[type_abb_idx].data_type_idx;
   string_s real_name;
   real_name.init();

   {
      data_type_s &type = data_types[type_idx];

      // - test type options -
      if (type.properties & c_type_option_strict_dynamic) {
         fprintf(stderr,"queue: container have not implemented processing of types with option strict_dynamic\n");
         cassert(0);
      }

      real_name.conc_set(type.name.size - 1,type.name.data,strlen(c_cont_postfixes[c_cont_queue]),(char *)c_cont_postfixes[c_cont_queue]);
   }

   string_s &data_type_name = abbs[0];

   unsigned data_type_idx;

   if ((data_type_idx = abbreviations.get_idx_by_name(data_type_name.size - 1,data_type_name.data)) == c_idx_not_exist) {

      // - do not report duplicate structures -
      //unsigned d_idx = data_types.get_idx_by_real_name(real_name.size - 1,real_name.data);
      //if (d_idx != c_idx_not_exist) {
      //   fprintf(stderr,"DUPLICATE STRUCTURES: %s <-> %s\n",data_type_name.data,data_types[d_idx].name.data);
      //}

      data_types.push_blank();
      data_type_s &data_type = data_types.last();

      data_type.cont_idx = c_cont_queue;
      data_type.name.set(data_type_name.size - 1,data_type_name.data);
      data_type.real_name.swap(real_name);

      data_type.properties = c_type_dynamic | c_type_flushable | (type_settings & c_type_option_mask);
      data_type.types.push(abbreviations[type_abb_idx].name);

      data_type_idx = data_types.used - 1;
   }
   else {
      fprintf(stderr,"queue: name of generated structure \"%s\" already exist\n",data_type_name.data);
      cassert(0);
   }

   real_name.clear();

   // - check and write abbreviations -
   if (abbs.used != 0) {
      unsigned idx = 0;
      do {
         string_s &abb = abbs[idx];

         if (abbreviations.get_idx_by_name(abb.size - 1,abb.data) != c_idx_not_exist) {
            fprintf(stderr,"queue: abreaviated name \"%s\" for generated structure is already used\n",abb.data);
            cassert(0);
         }

         abbreviations.push_blank();
         abbreviations.last().set(abb,data_type_idx);
      } while(++idx < abbs.used);
   }

   data_type_s &type = data_types[type_idx];
   data_type_s &data_type = data_types[data_type_idx];

   if (gen_options & c_option_gen_code &&
      (include_level == 0 || gen_options & c_option_gen_includes))
   {
   // - definition of structure queue -

fprintf(out_file,
"// struct %s definition\n"
"\n"
,STRUCT_NAME);

   if (abbs.used > 1) {
      unsigned idx = 1;
      do {
fprintf(out_file,
"typedef struct %s %s;\n"
,abbs[0].data,abbs[idx].data);
      } while(++idx < abbs.used);
fprintf(out_file,
"\n"
);
   }

fprintf(out_file,
"/*!\n"
" * \\brief __GEN queue of type %s\n"
" */\n"
"struct %s\n"
"{\n"
"  unsigned size; //!< actual size of allocated space (element count)\n"
"  unsigned used; //!< count of stored elements\n"
"  unsigned begin; //!< position of first element\n"
"  %s *data; //!< pointer to queue elements\n"
"\n"
,TYPE_NAME,STRUCT_NAME,TYPE_NAME);
fprintf(out_file,
"  %s() = default;\n"
"  %s(%s &a_src) = delete;\n"
"\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_nogen_init)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN initialize queue\n"
"    */\n"
"  inline void init();\n"
"\n"
);
   }
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN initialize queue of requested size\n"
"    * \\param a_size - requested size of queue\n"
"    */\n"
"  inline void init_size(unsigned a_size);\n"
"\n"
);
   }
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN initialize/set underlaying data buffer\n"
"    * \\param a_size - size of data buffer\n"
"    * \\param a_data - pointer to data buffer\n"
"    */\n"
"  inline void init_buffer(unsigned a_size,%s *a_data);\n"
"\n"
,TYPE_NAME);
   }
   if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
      if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN release memory used by queue\n"
"    */\n"
"  inline void clear();\n"
"\n"
);
      }
      else {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN release memory used by queue\n"
"    */\n"
"  EXPORT void clear();\n"
"\n"
);
      }
   }
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
     if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN set underlaying data buffer\n"
"    * \\param a_size - size of data buffer\n"
"    * \\param a_data - pointer to data buffer\n"
"    */\n"
"  inline void set_buffer(unsigned a_size,%s *a_data);\n"
"\n"
,TYPE_NAME);
      }
      else {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN set underlaying data buffer\n"
"    * \\param a_size - size of data buffer\n"
"    * \\param a_data - pointer to data buffer\n"
"    */\n"
"  EXPORT void set_buffer(unsigned a_size,%s *a_data);\n"
"\n"
,TYPE_NAME);
      }
   }
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN flush queue memory usage\n"
"    */\n"
"  inline void flush();\n"
"\n"
);
   if (!(TYPE_NUMBER & c_type_flushable)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN flush queue memory usage, recursive on elements\n"
"    */\n"
"  inline void flush_all();\n"
"\n"
);
   }
   else {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN flush queue memory usage, recursive on elements\n"
"    */\n"
"  EXPORT void flush_all();\n"
"\n"
);
   }
   if (!(STRUCT_NUMBER & c_type_option_nogen_swap)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN swap members of queue with another queue\n"
"    * \\param a_second - reference to another queue\n"
"    */\n"
"  inline void swap(%s &a_second);\n"
"\n"
,STRUCT_NAME);
   }
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN insert element to end of queue\n"
"    * \\param a_value - value inserted to end of queue\n"
"    * \\return index of inserted element\n"
"    */\n"
"  inline void insert(%s a_value);\n"
"\n"
,TYPE_NAME);
   }
   else {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN insert element to end of queue\n"
"    * \\param a_value - value inserted to end of queue\n"
"    * \\return index of inserted element\n"
"    */\n"
"  inline void insert(%s &a_value);\n"
"\n"
,TYPE_NAME);
   }
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN insert blank element to the end of queue\n"
"    * \\return index of inserted element\n"
"    */\n"
"  inline void insert_blank();\n"
"\n"
"  /*!\n"
"    * \\brief __GEN return value of next element in queue, and remove it\n"
"    * \\return reference to next element\n"
"    */\n"
"  inline %s &next();\n"
"\n"
"  /*!\n"
"    * \\brief __GEN return value of last element in queue\n"
"    * \\return reference to last element\n"
"    */\n"
"  inline %s &last();\n"
"\n"
,TYPE_NAME,TYPE_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN change queue capacity\n"
"    * \\param a_size - requested queue capacity\n"
"    */\n"
"  EXPORT void copy_resize(unsigned a_size);\n"
"\n"
);
   }
   if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
      if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN copy queue from another queue\n"
"    * \\param a_src - reference to another queue\n"
"    * \\return reference to this queue\n"
"    */\n"
"  inline %s &operator=(%s &a_src);\n"
"\n"
,STRUCT_NAME,STRUCT_NAME);
      }
      else {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN copy queue from another queue\n"
"    * \\param a_src - reference to another queue\n"
"    * \\return reference to this queue\n"
"    */\n"
"  EXPORT %s &operator=(%s &a_src);\n"
"\n"
,STRUCT_NAME,STRUCT_NAME);
      }
   }
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN compare queue with another queue\n"
"    * \\param a_second - reference to another queue\n"
"    * \\return result of comparision\n"
"    */\n"
"  EXPORT bool operator==(%s &a_second);\n"
"\n"
,STRUCT_NAME);
   if (fun_defs.used != 0) {
      unsigned f_idx = 0;
      do {
fprintf(out_file,
"  %s\n"
,fun_defs[f_idx].data);
      } while(++f_idx < fun_defs.used);
   }
fprintf(out_file,
"};\n"
"\n"
);
   }
}/*}}}*/

void processor_s::generate_queue_inlines(unsigned abb_idx,unsigned a_dt_idx)
{/*{{{*/
   data_type_s &data_type = data_types[a_dt_idx];

   string_s &type_abb_string = data_type.types[0];
   unsigned type_abb_idx = abbreviations.get_idx_by_name(type_abb_string.size - 1,type_abb_string.data);

   if (type_abb_idx == c_idx_not_exist) {
      fprintf(stderr,"queue: inlines: abbeviated type name \"%s\" does not exist\n",type_abb_string.data);
      cassert(0);
   }

   unsigned type_idx = abbreviations[type_abb_idx].data_type_idx;
   data_type_s &type = data_types[type_idx];

   if (gen_options & c_option_gen_code &&
      (include_level == 0 || gen_options & c_option_gen_includes))
   {
   // - definition of inline methods -

fprintf(out_file,
"// --- struct %s inline method definition ---\n"
"// LCOV_EXCL_START\n"
"\n"
,IM_STRUCT_NAME);

   // - queue init method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_init)) {
QUEUE_INIT(QUEUE_GEN_VALUES);
   }

   // - queue init_size method -
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
QUEUE_INIT_SIZE(QUEUE_GEN_VALUES);
   }

   // - queue init_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
QUEUE_INIT_BUFFER(QUEUE_GEN_VALUES);
   }

   // - queue clear method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
QUEUE_CLEAR(QUEUE_GEN_VALUES);
      }
   }

   // - queue set_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer && !(TYPE_NUMBER & c_type_dynamic)) {
QUEUE_SET_BUFFER(QUEUE_GEN_VALUES);
   }

   // - queue flush method -
QUEUE_FLUSH(QUEUE_GEN_VALUES);

   // - queue flush_all method -
   if (!(TYPE_NUMBER & c_type_flushable)) {
QUEUE_FLUSH_ALL(QUEUE_GEN_VALUES);
   }

   // - queue swap method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_swap)) {
QUEUE_SWAP(QUEUE_GEN_VALUES);
   }

   // - queue insert method -
QUEUE_INSERT(QUEUE_GEN_VALUES);

   // - queue insert_blank method -
QUEUE_INSERT_BLANK(QUEUE_GEN_VALUES);

   // - queue next method -
QUEUE_NEXT(QUEUE_GEN_VALUES);

   // - queue last method -
QUEUE_LAST(QUEUE_GEN_VALUES);

   // - queue copy_resize method -

   // - queue operator= method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
QUEUE_OPERATOR_EQUAL(QUEUE_GEN_VALUES);
      }
   }

   // - queue operator== method -

fprintf(out_file,
"// LCOV_EXCL_STOP\n"
"\n");
   }
}/*}}}*/

void processor_s::generate_queue_methods(unsigned abb_idx,unsigned a_dt_idx)
{/*{{{*/
   data_type_s &data_type = data_types[a_dt_idx];

   string_s &type_abb_string = data_type.types[0];
   unsigned type_abb_idx = abbreviations.get_idx_by_name(type_abb_string.size - 1,type_abb_string.data);

   if (type_abb_idx == c_idx_not_exist) {
      fprintf(stderr,"queue: methods: abreviated type name \"%s\" does not exist\n",type_abb_string.data);
      cassert(0);
   }

   unsigned type_idx = abbreviations[type_abb_idx].data_type_idx;
   data_type_s &type = data_types[type_idx];

   if (gen_options & c_option_gen_code &&
      (include_level == 0 || gen_options & c_option_gen_includes))
   {
   // - definition of methods -

fprintf(out_file,
"// --- struct %s method definition ---\n"
"// LCOV_EXCL_START\n"
"\n"
,IM_STRUCT_NAME);

   // - queue init method -

   // - queue init_size method -

   // - queue init_buffer method -

   // - queue clear method -
   if (TYPE_NUMBER & c_type_dynamic) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
QUEUE_CLEAR(QUEUE_GEN_VALUES);
      }
   }

   // - queue set_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer && TYPE_NUMBER & c_type_dynamic) {
QUEUE_SET_BUFFER(QUEUE_GEN_VALUES);
   }

   // - queue flush method -

   // - queue flush_all method -
   if (TYPE_NUMBER & c_type_flushable) {
QUEUE_FLUSH_ALL(QUEUE_GEN_VALUES);
   }

   // - queue swap method -

   // - queue insert method -

   // - queue insert_blank method -

   // - queue next method -

   // - queue last method -

   // - queue copy_resize method -
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
QUEUE_COPY_RESIZE(QUEUE_GEN_VALUES);
   }

   // - queue operator= method -
   if (TYPE_NUMBER & c_type_dynamic) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
QUEUE_OPERATOR_EQUAL(QUEUE_GEN_VALUES);
      }
   }

   // - queue operator== method -
QUEUE_OPERATOR_DOUBLE_EQUAL(QUEUE_GEN_VALUES);

fprintf(out_file,
"// LCOV_EXCL_STOP\n"
"\n");
   }
}/*}}}*/


#define LIST_GEN_PARAMS FILE *out_file,abbreviation_array_s &abbreviations,unsigned abb_idx,unsigned type_abb_idx,data_type_s &type,data_type_s &data_type
#define LIST_GEN_VALUES out_file,abbreviations,abb_idx,type_abb_idx,type,data_type

void LIST_INIT(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::init()\n"
"{/*{{{*/\n"
"  size = 0;\n"
"  used = 0;\n"
,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  count = 0;\n"
);
   }
fprintf(out_file,
"  data = nullptr;\n"
"  free_idx = c_idx_not_exist;\n"
"  first_idx = c_idx_not_exist;\n"
"  last_idx = c_idx_not_exist;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_INIT_SIZE(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::init_size(unsigned a_size)\n"
"{/*{{{*/\n"
"  init();\n"
"  copy_resize(a_size);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void LIST_INIT_BUFFER(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::init_buffer(unsigned a_size,%s_element *a_data)\n"
"{/*{{{*/\n"
"  init();\n"
"  set_buffer(a_size,a_data);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void LIST_CLEAR(LIST_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"inline void %s::clear()\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"void %s::clear()\n"
,IM_STRUCT_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
);
   if (TYPE_NUMBER & c_type_dynamic || !(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  if (data != nullptr)\n"
"  {\n"
);
      if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"    %s_element *ptr = data;\n"
"    %s_element *ptr_end = ptr + size;\n"
"\n"
"    do {\n"
"      ptr->object.clear();\n"
"    } while(++ptr < ptr_end);\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
      }
      if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
         if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"\n"
);
         }
fprintf(out_file,
"    cfree(data);\n"
);
      }
fprintf(out_file,
"  }\n"
"\n"
);
   }
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  init();\n"
);
   }
   else {
fprintf(out_file,
"  used = 0;\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  count = 0;\n"
);
   }
fprintf(out_file,
"  free_idx = c_idx_not_exist;\n"
"  first_idx = c_idx_not_exist;\n"
"  last_idx = c_idx_not_exist;\n"
);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_SET_BUFFER(LIST_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"inline void %s::set_buffer(unsigned a_size,%s_element *a_data)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"void %s::set_buffer(unsigned a_size,%s_element *a_data)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
"  debug_assert(a_size != 0 && a_data != nullptr);\n"
"\n"
"  clear();\n"
);
   if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"\n"
"  %s_element *ptr = data + size;\n"
"  %s_element *ptr_end = data + a_size;\n"
"\n"
"  do {\n"
"    ptr->object.init();\n"
"  } while(++ptr < ptr_end);\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
fprintf(out_file,
"\n"
"  size = a_size;\n"
"  data = a_data;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_FLUSH(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::flush()\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  copy_resize(used);\n"
);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_FLUSH_ALL(LIST_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_flushable)) {
fprintf(out_file,
"inline void %s::flush_all()\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"void %s::flush_all()\n"
,IM_STRUCT_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  copy_resize(used);\n"
);
   }
   if (TYPE_NUMBER & c_type_flushable) {
      if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"\n"
);
      }
fprintf(out_file,
"  if (used == 0)\n"
"  {\n"
"    return;\n"
"  }\n"
"\n"
"  %s_element *ptr = data;\n"
"  %s_element *ptr_end = ptr + used;\n"
"\n"
"  do {\n"
"    ptr->object.flush_all();\n"
"  } while(++ptr < ptr_end);\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_SWAP(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::swap(%s &a_second)\n"
"{/*{{{*/\n"
"  unsigned tmp_unsigned = size;\n"
"  size = a_second.size;\n"
"  a_second.size = tmp_unsigned;\n"
"\n"
"  tmp_unsigned = used;\n"
"  used = a_second.used;\n"
"  a_second.used = tmp_unsigned;\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  tmp_unsigned = count;\n"
"  count = a_second.count;\n"
"  a_second.count = tmp_unsigned;\n"
"\n"
);
   }
fprintf(out_file,
"  %s_element *tmp_data = data;\n"
"  data = a_second.data;\n"
"  a_second.data = tmp_data;\n"
"\n"
"  tmp_unsigned = free_idx;\n"
"  free_idx = a_second.free_idx;\n"
"  a_second.free_idx = tmp_unsigned;\n"
"\n"
"  tmp_unsigned = first_idx;\n"
"  first_idx = a_second.first_idx;\n"
"  a_second.first_idx = tmp_unsigned;\n"
"\n"
"  tmp_unsigned = last_idx;\n"
"  last_idx = a_second.last_idx;\n"
"  a_second.last_idx = tmp_unsigned;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void LIST_OPERATOR_LE_BR_RE_BR(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline %s &%s::operator[](unsigned a_idx)\n"
"{/*{{{*/\n"
,TYPE_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  debug_assert(a_idx < used && data[a_idx].valid);\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert(a_idx < used);\n"
);
   }
fprintf(out_file,
"  return data[a_idx].object;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_PREPEND(LIST_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"inline unsigned %s::prepend(%s a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"inline unsigned %s::prepend(%s &a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
"  unsigned new_idx;\n"
"\n"
"  if (free_idx != c_idx_not_exist)\n"
"  {\n"
"    new_idx = free_idx;\n"
"    free_idx = data[new_idx].next_idx;\n"
"  }\n"
"  else\n"
"  {\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"    if (used >= size)\n"
"    {\n"
"      unsigned new_size = (size << 1) + c_array_add;\n"
"      debug_assert(new_size != 0);\n"
"\n"
"      copy_resize(new_size);\n"
"    }\n"
"\n"
);
   }
   else {
fprintf(out_file,
"    debug_assert(used < size);\n"
);
   }
fprintf(out_file,
"    new_idx = used++;\n"
"  }\n"
"\n"
"  %s_element &new_element = data[new_idx];\n"
"\n"
,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  new_element.valid = true;\n"
);
   }
fprintf(out_file,
"  new_element.next_idx = first_idx;\n"
"  new_element.prev_idx = c_idx_not_exist;\n"
"\n"
"  if (first_idx != c_idx_not_exist)\n"
"  {\n"
"    data[first_idx].prev_idx = new_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    last_idx = new_idx;\n"
"  }\n"
"\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  count++;\n"
);
   }
fprintf(out_file,
"  first_idx = new_idx;\n"
"\n"
"  new_element.object = a_value;\n"
"\n"
"  return new_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_APPEND(LIST_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"inline unsigned %s::append(%s a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"inline unsigned %s::append(%s &a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
"  unsigned new_idx;\n"
"\n"
"  if (free_idx != c_idx_not_exist)\n"
"  {\n"
"    new_idx = free_idx;\n"
"    free_idx = data[new_idx].next_idx;\n"
"  }\n"
"  else\n"
"  {\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"    if (used >= size)\n"
"    {\n"
"      unsigned new_size = (size << 1) + c_array_add;\n"
"      debug_assert(new_size != 0);\n"
"\n"
"      copy_resize(new_size);\n"
"    }\n"
"\n"
);
   }
   else {
fprintf(out_file,
"    debug_assert(used < size);\n"
);
   }
fprintf(out_file,
"    new_idx = used++;\n"
"  }\n"
"\n"
"  %s_element &new_element = data[new_idx];\n"
"\n"
,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  new_element.valid = true;\n"
);
   }
fprintf(out_file,
"  new_element.next_idx = c_idx_not_exist;\n"
"  new_element.prev_idx = last_idx;\n"
"\n"
"  if (last_idx != c_idx_not_exist)\n"
"  {\n"
"    data[last_idx].next_idx = new_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    first_idx = new_idx;\n"
"  }\n"
"\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  count++;\n"
);
   }
fprintf(out_file,
"  last_idx = new_idx;\n"
"\n"
"  new_element.object = a_value;\n"
"\n"
"  return new_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_INSERT_BEFORE(LIST_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"inline unsigned %s::insert_before(unsigned a_idx,%s a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"inline unsigned %s::insert_before(unsigned a_idx,%s &a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  debug_assert(a_idx < used && data[a_idx].valid);\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert(a_idx < used);\n"
);
   }
fprintf(out_file,
"\n"
"  unsigned new_idx;\n"
"\n"
"  if (free_idx != c_idx_not_exist)\n"
"  {\n"
"    new_idx = free_idx;\n"
"    free_idx = data[new_idx].next_idx;\n"
"  }\n"
"  else\n"
"  {\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"    if (used >= size)\n"
"    {\n"
"      unsigned new_size = (size << 1) + c_array_add;\n"
"      debug_assert(new_size != 0);\n"
"\n"
"      copy_resize(new_size);\n"
"    }\n"
"\n"
);
   }
   else {
fprintf(out_file,
"    debug_assert(used < size);\n"
);
   }
fprintf(out_file,
"    new_idx = used++;\n"
"  }\n"
"\n"
"  %s_element &idx_element = data[a_idx];\n"
"  %s_element &new_element = data[new_idx];\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  new_element.valid = true;\n"
);
   }
fprintf(out_file,
"  new_element.next_idx = a_idx;\n"
"  new_element.prev_idx = idx_element.prev_idx;\n"
"\n"
"  if (idx_element.prev_idx != c_idx_not_exist)\n"
"  {\n"
"    data[idx_element.prev_idx].next_idx = new_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    first_idx = new_idx;\n"
"  }\n"
"\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  count++;\n"
);
   }
fprintf(out_file,
"  idx_element.prev_idx = new_idx;\n"
"\n"
"  new_element.object = a_value;\n"
"\n"
"  return new_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_INSERT_AFTER(LIST_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"inline unsigned %s::insert_after(unsigned a_idx,%s a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"inline unsigned %s::insert_after(unsigned a_idx,%s &a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  debug_assert(a_idx < used && data[a_idx].valid);\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert(a_idx < used);\n"
);
   }
fprintf(out_file,
"\n"
"  unsigned new_idx;\n"
"\n"
"  if (free_idx != c_idx_not_exist)\n"
"  {\n"
"    new_idx = free_idx;\n"
"    free_idx = data[new_idx].next_idx;\n"
"  }\n"
"  else\n"
"  {\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"    if (used >= size)\n"
"    {\n"
"      unsigned new_size = (size << 1) + c_array_add;\n"
"      debug_assert(new_size != 0);\n"
"\n"
"      copy_resize(new_size);\n"
"    }\n"
"\n"
);
   }
   else {
fprintf(out_file,
"    debug_assert(used < size);\n"
);
   }
fprintf(out_file,
"    new_idx = used++;\n"
"  }\n"
"\n"
"  %s_element &idx_element = data[a_idx];\n"
"  %s_element &new_element = data[new_idx];\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  new_element.valid = true;\n"
);
   }
fprintf(out_file,
"  new_element.next_idx = idx_element.next_idx;\n"
"  new_element.prev_idx = a_idx;\n"
"\n"
"  if (idx_element.next_idx != c_idx_not_exist)\n"
"  {\n"
"    data[idx_element.next_idx].prev_idx = new_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    last_idx = new_idx;\n"
"  }\n"
"\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  count++;\n"
);
   }
fprintf(out_file,
"  idx_element.next_idx = new_idx;\n"
"\n"
"  new_element.object = a_value;\n"
"\n"
"  return new_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_PREPEND_BLANK(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline unsigned %s::prepend_blank()\n"
"{/*{{{*/\n"
"  unsigned new_idx;\n"
"\n"
"  if (free_idx != c_idx_not_exist)\n"
"  {\n"
"    new_idx = free_idx;\n"
"    free_idx = data[new_idx].next_idx;\n"
"  }\n"
"  else\n"
"  {\n"
,IM_STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"    if (used >= size)\n"
"    {\n"
"      unsigned new_size = (size << 1) + c_array_add;\n"
"      debug_assert(new_size != 0);\n"
"\n"
"      copy_resize(new_size);\n"
"    }\n"
"\n"
);
   }
   else {
fprintf(out_file,
"    debug_assert(used < size);\n"
);
   }
fprintf(out_file,
"    new_idx = used++;\n"
"  }\n"
"\n"
"  %s_element &new_element = data[new_idx];\n"
"\n"
,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  new_element.valid = true;\n"
);
   }
fprintf(out_file,
"  new_element.next_idx = first_idx;\n"
"  new_element.prev_idx = c_idx_not_exist;\n"
"\n"
"  if (first_idx != c_idx_not_exist)\n"
"  {\n"
"    data[first_idx].prev_idx = new_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    last_idx = new_idx;\n"
"  }\n"
"\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  count++;\n"
);
   }
fprintf(out_file,
"  first_idx = new_idx;\n"
"\n"
"  return new_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_APPEND_BLANK(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline unsigned %s::append_blank()\n"
"{/*{{{*/\n"
"  unsigned new_idx;\n"
"\n"
"  if (free_idx != c_idx_not_exist)\n"
"  {\n"
"    new_idx = free_idx;\n"
"    free_idx = data[new_idx].next_idx;\n"
"  }\n"
"  else\n"
"  {\n"
,IM_STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"    if (used >= size)\n"
"    {\n"
"      unsigned new_size = (size << 1) + c_array_add;\n"
"      debug_assert(new_size != 0);\n"
"\n"
"      copy_resize(new_size);\n"
"    }\n"
"\n"
);
   }
   else {
fprintf(out_file,
"    debug_assert(used < size);\n"
);
   }
fprintf(out_file,
"    new_idx = used++;\n"
"  }\n"
"\n"
"  %s_element &new_element = data[new_idx];\n"
"\n"
,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  new_element.valid = true;\n"
);
   }
fprintf(out_file,
"  new_element.next_idx = c_idx_not_exist;\n"
"  new_element.prev_idx = last_idx;\n"
"\n"
"  if (last_idx != c_idx_not_exist)\n"
"  {\n"
"    data[last_idx].next_idx = new_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    first_idx = new_idx;\n"
"  }\n"
"\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  count++;\n"
);
   }
fprintf(out_file,
"  last_idx = new_idx;\n"
"\n"
"  return new_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_INSERT_BLANK_BEFORE(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline unsigned %s::insert_blank_before(unsigned a_idx)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  debug_assert(a_idx < used && data[a_idx].valid);\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert(a_idx < used);\n"
);
   }
fprintf(out_file,
"\n"
"  unsigned new_idx;\n"
"\n"
"  if (free_idx != c_idx_not_exist)\n"
"  {\n"
"    new_idx = free_idx;\n"
"    free_idx = data[new_idx].next_idx;\n"
"  }\n"
"  else\n"
"  {\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"    if (used >= size)\n"
"    {\n"
"      unsigned new_size = (size << 1) + c_array_add;\n"
"      debug_assert(new_size != 0);\n"
"\n"
"      copy_resize(new_size);\n"
"    }\n"
"\n"
);
   }
   else {
fprintf(out_file,
"    debug_assert(used < size);\n"
);
   }
fprintf(out_file,
"    new_idx = used++;\n"
"  }\n"
"\n"
"  %s_element &idx_element = data[a_idx];\n"
"  %s_element &new_element = data[new_idx];\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  new_element.valid = true;\n"
);
   }
fprintf(out_file,
"  new_element.next_idx = a_idx;\n"
"  new_element.prev_idx = idx_element.prev_idx;\n"
"\n"
"  if (idx_element.prev_idx != c_idx_not_exist)\n"
"  {\n"
"    data[idx_element.prev_idx].next_idx = new_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    first_idx = new_idx;\n"
"  }\n"
"\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  count++;\n"
);
   }
fprintf(out_file,
"  idx_element.prev_idx = new_idx;\n"
"\n"
"  return new_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_INSERT_BLANK_AFTER(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline unsigned %s::insert_blank_after(unsigned a_idx)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  debug_assert(a_idx < used && data[a_idx].valid);\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert(a_idx < used);\n"
);
   }
fprintf(out_file,
"\n"
"  unsigned new_idx;\n"
"\n"
"  if (free_idx != c_idx_not_exist)\n"
"  {\n"
"    new_idx = free_idx;\n"
"    free_idx = data[new_idx].next_idx;\n"
"  }\n"
"  else\n"
"  {\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"    if (used >= size)\n"
"    {\n"
"      unsigned new_size = (size << 1) + c_array_add;\n"
"      debug_assert(new_size != 0);\n"
"\n"
"      copy_resize(new_size);\n"
"    }\n"
"\n"
);
   }
   else {
fprintf(out_file,
"    debug_assert(used < size);\n"
);
   }
fprintf(out_file,
"    new_idx = used++;\n"
"  }\n"
"\n"
"  %s_element &idx_element = data[a_idx];\n"
"  %s_element &new_element = data[new_idx];\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  new_element.valid = true;\n"
);
   }
fprintf(out_file,
"  new_element.next_idx = idx_element.next_idx;\n"
"  new_element.prev_idx = a_idx;\n"
"\n"
"  if (idx_element.next_idx != c_idx_not_exist)\n"
"  {\n"
"    data[idx_element.next_idx].prev_idx = new_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    last_idx = new_idx;\n"
"  }\n"
"\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  count++;\n"
);
   }
fprintf(out_file,
"  idx_element.next_idx = new_idx;\n"
"\n"
"  return new_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_REMOVE(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::remove(unsigned a_idx)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  debug_assert(a_idx < used && data[a_idx].valid);\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert(a_idx < used);\n"
);
   }
fprintf(out_file,
"\n"
"  %s_element &rm_element = data[a_idx];\n"
"\n"
"  if (rm_element.next_idx != c_idx_not_exist)\n"
"  {\n"
"    data[rm_element.next_idx].prev_idx = rm_element.prev_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    last_idx = rm_element.prev_idx;\n"
"  }\n"
"\n"
"  if (rm_element.prev_idx != c_idx_not_exist)\n"
"  {\n"
"    data[rm_element.prev_idx].next_idx = rm_element.next_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    first_idx = rm_element.next_idx;\n"
"  }\n"
"\n"
,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  rm_element.valid = false;\n"
"  rm_element.next_idx = free_idx;\n"
"\n"
"  count--;\n"
);
   }
   else {
fprintf(out_file,
"  rm_element.next_idx = free_idx;\n"
);
   }
fprintf(out_file,
"  free_idx = a_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_NEXT_IDX(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline unsigned %s::next_idx(unsigned a_idx)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  debug_assert(data[a_idx].valid);\n"
);
   }
fprintf(out_file,
"  return data[a_idx].next_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_PREV_IDX(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline unsigned %s::prev_idx(unsigned a_idx)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  debug_assert(data[a_idx].valid);\n"
);
   }
fprintf(out_file,
"  return data[a_idx].prev_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_COPY_RESIZE(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"void %s::copy_resize(unsigned a_size)\n"
"{/*{{{*/\n"
"  debug_assert(a_size >= used);\n"
,IM_STRUCT_NAME);
   if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"\n"
"  if (size > a_size)\n"
"  {\n"
"    %s_element *ptr = data + a_size;\n"
"    %s_element *ptr_end = data + size;\n"
"\n"
"    do {\n"
"      ptr->object.clear();\n"
"    } while(++ptr < ptr_end);\n"
"  }\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
fprintf(out_file,
"\n"
"  if (a_size == 0)\n"
"  {\n"
"    if (data != nullptr)\n"
"    {\n"
"      cfree(data);\n"
"    }\n"
"\n"
"    data = nullptr;\n"
"  }\n"
"  else\n"
"  {\n"
"    data = (%s_element *)crealloc(data,a_size*sizeof(%s_element));\n"
"  }\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"\n"
"  if (a_size > size)\n"
"  {\n"
"    %s_element *ptr = data + size;\n"
"    %s_element *ptr_end = data + a_size;\n"
"\n"
"    do {\n"
"      ptr->object.init();\n"
"    } while(++ptr < ptr_end);\n"
"  }\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
fprintf(out_file,
"\n"
"  size = a_size;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_GET_IDX(LIST_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"unsigned %s::get_idx(%s a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"unsigned %s::get_idx(%s &a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
"  if (first_idx == c_idx_not_exist)\n"
"  {\n"
"    return c_idx_not_exist;\n"
"  }\n"
"\n"
"  unsigned idx = first_idx;\n"
"  do {\n"
"    %s_element &element = data[idx];\n"
"\n"
"    if (element.object == a_value)\n"
"    {\n"
"      return idx;\n"
"    }\n"
"\n"
"    idx = element.next_idx;\n"
"  } while(idx != c_idx_not_exist);\n"
"\n"
"  return c_idx_not_exist;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void LIST_OPERATOR_EQUAL(LIST_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"%s &%s::operator=(%s &a_src)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"inline %s &%s::operator=(%s &a_src)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
);
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
fprintf(out_file,
"  debug_assert(a_src.used <= size);\n"
"\n"
);
   }
fprintf(out_file,
"  clear();\n"
"\n"
"  if (a_src.used == 0)\n"
"  {\n"
"    return *this;\n"
"  }\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"\n"
"  copy_resize(a_src.used);\n"
);
   }
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"\n"
"  memcpy(data,a_src.data,a_src.used*sizeof(%s_element));\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"\n"
"  %s_element *ptr = data;\n"
"  %s_element *s_ptr = a_src.data;\n"
"  %s_element *s_ptr_end = s_ptr + a_src.used;\n"
"\n"
"  do {\n"
"    ptr->object = s_ptr->object;\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"    ptr->valid = s_ptr->valid;\n"
);
   }
fprintf(out_file,
"    ptr->next_idx = s_ptr->next_idx;\n"
"    ptr->prev_idx = s_ptr->prev_idx;\n"
"  } while(++ptr,++s_ptr < s_ptr_end);\n"
);
   }
fprintf(out_file,
"\n"
"  used = a_src.used;\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  count = a_src.count;\n"
);
   }
fprintf(out_file,
"  free_idx = a_src.free_idx;\n"
"  first_idx = a_src.first_idx;\n"
"  last_idx = a_src.last_idx;\n"
"\n"
"  return *this;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_OPERATOR_DOUBLE_EQUAL(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"bool %s::operator==(%s &a_second)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  if (count != a_second.count)\n"
"  {\n"
"    return false;\n"
"  }\n"
"\n"
);
   }
fprintf(out_file,
"  if (first_idx == c_idx_not_exist)\n"
"  {\n"
"    return a_second.first_idx == c_idx_not_exist;\n"
"  }\n"
"\n"
"  if (a_second.first_idx == c_idx_not_exist)\n"
"  {\n"
"    return false;\n"
"  }\n"
"\n"
"  unsigned idx = first_idx;\n"
"  unsigned s_idx = a_second.first_idx;\n"
"\n"
"  do {\n"
"    %s_element &element = data[idx];\n"
"    %s_element &s_element = a_second.data[s_idx];\n"
"\n"
"    if (!(element.object == s_element.object))\n"
"    {\n"
"      return false;\n"
"    }\n"
"\n"
"    idx = element.next_idx;\n"
"    s_idx = s_element.next_idx;\n"
"\n"
"  } while(idx != c_idx_not_exist || s_idx != c_idx_not_exist);\n"
"\n"
"  return idx == s_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void processor_s::generate_list_type()
{/*{{{*/
   string_array_s &type_names = cont_params.types;
   string_array_s &fun_defs = cont_params.functions;
   string_array_s &abbs = cont_params.names;

   if (type_names.used != 1) {
      fprintf(stderr,"list: not given name (or too many names) of contained type\n");
      cassert(0);
   }

   if (abbs.used < 1) {
      fprintf(stderr,"list: not given name of generated structure\n");
      cassert(0);
   }

   unsigned type_abb_idx = abbreviations.get_idx_by_name(type_names[0].size - 1,type_names[0].data);
   if (type_abb_idx == c_idx_not_exist) {
      fprintf(stderr,"list: contained type \"%s\" does not exist\n",type_names[0].data);
      cassert(0);
   }

   unsigned type_idx = abbreviations[type_abb_idx].data_type_idx;
   string_s real_name;
   real_name.init();

   {
      data_type_s &type = data_types[type_idx];

      // - test type options -
      if (type.properties & c_type_option_strict_dynamic) {
         fprintf(stderr,"list: container have not implemented processing of types with option strict_dynamic\n");
         cassert(0);
      }

      real_name.conc_set(type.name.size - 1,type.name.data,strlen(c_cont_postfixes[c_cont_list]),(char *)c_cont_postfixes[c_cont_list]);
   }

   string_s &data_type_name = abbs[0];

   unsigned data_type_idx;

   if ((data_type_idx = abbreviations.get_idx_by_name(data_type_name.size - 1,data_type_name.data)) == c_idx_not_exist) {

      // - do not report duplicate structures -
      //unsigned d_idx = data_types.get_idx_by_real_name(real_name.size - 1,real_name.data);
      //if (d_idx != c_idx_not_exist) {
      //   fprintf(stderr,"DUPLICATE STRUCTURES: %s <-> %s\n",data_type_name.data,data_types[d_idx].name.data);
      //}

      data_types.push_blank();
      data_type_s &data_type = data_types.last();

      data_type.cont_idx = c_cont_list;
      data_type.name.set(data_type_name.size - 1,data_type_name.data);
      data_type.real_name.swap(real_name);

      data_type.properties = c_type_dynamic | c_type_flushable | (type_settings & c_type_option_mask);
      data_type.types.push(abbreviations[type_abb_idx].name);

      data_type_idx = data_types.used - 1;
   }
   else {
      fprintf(stderr,"list: name of generated structure \"%s\" is already used\n",data_type_name.data);
      cassert(0);
   }

   real_name.clear();

   // - check and write abbreviations -
   if (abbs.used != 0) {
      unsigned idx = 0;
      do {
         string_s &abb = abbs[idx];

         if (abbreviations.get_idx_by_name(abb.size - 1,abb.data) != c_idx_not_exist) {
            fprintf(stderr,"list: abreviated name \"%s\" for generated structure is already used\n",abb.data);
            cassert(0);
         }

         abbreviations.push_blank();
         abbreviations.last().set(abb,data_type_idx);
      } while(++idx < abbs.used);
   }

   data_type_s &type = data_types[type_idx];
   data_type_s &data_type = data_types[data_type_idx];

   if (gen_options & c_option_gen_code &&
      (include_level == 0 || gen_options & c_option_gen_includes))
   {
   // - definition of structure list -

fprintf(out_file,
"// struct %s definition\n"
"\n"
,STRUCT_NAME);

   if (abbs.used > 1) {
      unsigned idx = 1;
      do {
fprintf(out_file,
"typedef struct %s %s;\n"
,abbs[0].data,abbs[idx].data);
      } while(++idx < abbs.used);
fprintf(out_file,
"\n"
);
   }

fprintf(out_file,
"/*!\n"
" * \\brief __GEN element of list of type %s\n"
" */\n"
"\n"
"struct %s_element\n"
"{\n"
"  unsigned next_idx;\n"
"  unsigned prev_idx;\n"
,TYPE_NAME,STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  bool valid;\n"
);
   }
fprintf(out_file,
"  %s object;\n"
"};\n"
"\n"
"/*!\n"
" * \\brief __GEN list of type %s\n"
" */\n"
"struct %s\n"
"{\n"
"  unsigned size; //!< actual size of allocated space (element count)\n"
"  unsigned used; //!< used part of allocated space\n"
,TYPE_NAME,TYPE_NAME,STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  unsigned count; //!< count of stored elements\n"
);
   }
fprintf(out_file,
"  %s_element *data; //!< pointer to list elements\n"
"  unsigned free_idx; //!< index of first free element\n"
"  unsigned first_idx; //!< index of first element\n"
"  unsigned last_idx; //!< index of last element\n"
"\n"
,STRUCT_NAME);
fprintf(out_file,
"  %s() = default;\n"
"  %s(%s &a_src) = delete;\n"
"\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_nogen_init)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN initialize list\n"
"    */\n"
"  inline void init();\n"
"\n"
);
   }
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN initialize list of requested size\n"
"    * \\param a_size - requested size of list\n"
"    */\n"
"  inline void init_size(unsigned a_size);\n"
"\n"
);
   }
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN initialize/set underlaying data buffer\n"
"    * \\param a_size - size of data buffer\n"
"    * \\param a_data - pointer to data buffer\n"
"    */\n"
"  inline void init_buffer(unsigned a_size,%s_element *a_data);\n"
"\n"
,STRUCT_NAME);
   }
   if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
      if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN release memory used by list\n"
"    */\n"
"  inline void clear();\n"
"\n"
);
      }
      else {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN release memory used by list\n"
"    */\n"
"  EXPORT void clear();\n"
"\n"
);
      }
   }
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
     if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN set underlaying data buffer\n"
"    * \\param a_size - size of data buffer\n"
"    * \\param a_data - pointer to data buffer\n"
"    */\n"
"  inline void set_buffer(unsigned a_size,%s_element *a_data);\n"
"\n"
,STRUCT_NAME);
      }
      else {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN set underlaying data buffer\n"
"    * \\param a_size - size of data buffer\n"
"    * \\param a_data - pointer to data buffer\n"
"    */\n"
"  EXPORT void set_buffer(unsigned a_size,%s_element *a_data);\n"
"\n"
,STRUCT_NAME);
      }
   }
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN flush list memory usage\n"
"    */\n"
"  inline void flush();\n"
"\n"
);
   if (!(TYPE_NUMBER & c_type_flushable)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN flush list memory usage, recursive on elements\n"
"    */\n"
"  inline void flush_all();\n"
"\n"
);
   }
   else {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN flush list memory usage, recursive on elements\n"
"    */\n"
"  EXPORT void flush_all();\n"
"\n"
);
   }
   if (!(STRUCT_NUMBER & c_type_option_nogen_swap)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN swap members of list with another list\n"
"    * \\param a_second - reference to another list\n"
"    */\n"
"  inline void swap(%s &a_second);\n"
"\n"
,STRUCT_NAME);
   }
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN select element of list\n"
"    * \\param a_idx - index of element in list\n"
"    * \\return reference to element of list\n"
"    */\n"
"  inline %s &operator[](unsigned a_idx);\n"
"\n"
,TYPE_NAME);
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN prepend element to list\n"
"    * \\param a_value - value prepended to list\n"
"    * \\return - position of element in list\n"
"    */\n"
"  inline unsigned prepend(%s a_value);\n"
"\n"
"  /*!\n"
"    * \\brief __GEN append element to list\n"
"    * \\param a_value - value appended to list\n"
"    * \\return - position of element in list\n"
"    */\n"
"  inline unsigned append(%s a_value);\n"
"\n"
"  /*!\n"
"    * \\brief __GEN insert before element to list\n"
"    * \\param a_value - value inserted to list\n"
"    * \\return - position of element in list\n"
"    */\n"
"  inline unsigned insert_before(unsigned a_idx,%s a_value);\n"
"\n"
"  /*!\n"
"    * \\brief __GEN insert after element to list\n"
"    * \\param a_value - value inserted to list\n"
"    * \\return - position of element in list\n"
"    */\n"
"  inline unsigned insert_after(unsigned a_idx,%s a_value);\n"
"\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN prepend element to list\n"
"    * \\param a_value - reference to value prepended to list\n"
"    * \\return - position of element in list\n"
"    */\n"
"  inline unsigned prepend(%s &a_value);\n"
"\n"
"  /*!\n"
"    * \\brief __GEN append element to list\n"
"    * \\param a_value - reference to value append to list\n"
"    * \\return - position of element in list\n"
"    */\n"
"  inline unsigned append(%s &a_value);\n"
"\n"
"  /*!\n"
"    * \\brief __GEN insert before element to list\n"
"    * \\param a_value - value inserted to list\n"
"    * \\return - position of element in list\n"
"    */\n"
"  inline unsigned insert_before(unsigned a_idx,%s &a_value);\n"
"\n"
"  /*!\n"
"    * \\brief __GEN insert after element to list\n"
"    * \\param a_value - value inserted to list\n"
"    * \\return - position of element in list\n"
"    */\n"
"  inline unsigned insert_after(unsigned a_idx,%s &a_value);\n"
"\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   }
fprintf(out_file,
"  inline unsigned prepend_blank();\n"
"  inline unsigned append_blank();\n"
"  inline unsigned insert_blank_before(unsigned a_idx);\n"
"  inline unsigned insert_blank_after(unsigned a_idx);\n"
"\n"
);
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN remove element at index from list\n"
"    * \\param a_idx - index of element to remove\n"
"    */\n"
"  inline void remove(unsigned a_idx);\n"
"\n"
"  /*!\n"
"    * \\brief __GEN return index of next element in list\n"
"    * \\param a_idx - index of element\n"
"    */\n"
"  inline unsigned next_idx(unsigned a_idx);\n"
"\n"
"  /*!\n"
"    * \\brief __GEN return index of previous element in list\n"
"    * \\param a_idx - index of element\n"
"    */\n"
"  inline unsigned prev_idx(unsigned a_idx);\n"
"\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN resize list capacity\n"
"    * \\param a_size - requested list capacity\n"
"    */\n"
"  EXPORT void copy_resize(unsigned a_size);\n"
"\n"
);
   }
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN search for index of element\n"
"    * \\param a_value - value which index is searched\n"
"    */\n"
"  EXPORT unsigned get_idx(%s a_value);\n"
,TYPE_NAME);
   }
   else {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN search for index of element\n"
"    * \\param a_value - value which index is searched\n"
"    */\n"
"  EXPORT unsigned get_idx(%s &a_value);\n"
,TYPE_NAME);
   }
   if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
      if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN copy list from another list\n"
"    * \\param a_src - reference to another list\n"
"    * \\return reference to this list\n"
"    */\n"
"  inline %s &operator=(%s &a_src);\n"
"\n"
,STRUCT_NAME,STRUCT_NAME);
      }
      else {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN copy list from another list\n"
"    * \\param a_src - reference to another list\n"
"    * \\return reference to this list\n"
"    */\n"
"  EXPORT %s &operator=(%s &a_src);\n"
"\n"
,STRUCT_NAME,STRUCT_NAME);
      }
   }
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN compare list with another list\n"
"    * \\param a_second - reference to another list\n"
"    * \\return result of comparision\n"
"    */\n"
"  EXPORT bool operator==(%s &a_second);\n"
"\n"
,STRUCT_NAME);
   if (fun_defs.used != 0) {
      unsigned f_idx = 0;
      do {
fprintf(out_file,
"  %s\n"
,fun_defs[f_idx].data);
      } while(++f_idx < fun_defs.used);
   }
fprintf(out_file,
"};\n"
"\n"
);
   }
}/*}}}*/

void processor_s::generate_list_inlines(unsigned abb_idx,unsigned a_dt_idx)
{/*{{{*/
   data_type_s &data_type = data_types[a_dt_idx];

   string_s &type_abb_string = data_type.types[0];
   unsigned type_abb_idx = abbreviations.get_idx_by_name(type_abb_string.size - 1,type_abb_string.data);

   if (type_abb_idx == c_idx_not_exist) {
      fprintf(stderr,"list: inlines: abbreviated type name \"%s\" does not exist\n",type_abb_string.data);
      cassert(0);
   }

   unsigned type_idx = abbreviations[type_abb_idx].data_type_idx;
   data_type_s &type = data_types[type_idx];

   if (gen_options & c_option_gen_code &&
      (include_level == 0 || gen_options & c_option_gen_includes))
   {
   // --- definition of inline methods ---

fprintf(out_file,
"// --- struct %s inline method definition ---\n"
"// LCOV_EXCL_START\n"
"\n"
,IM_STRUCT_NAME);

   // - list init method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_init)) {
LIST_INIT(LIST_GEN_VALUES);
   }

   // - list init_size method -
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
LIST_INIT_SIZE(LIST_GEN_VALUES);
   }

   // - list init_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
LIST_INIT_BUFFER(LIST_GEN_VALUES);
   }

   // - list clear method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
LIST_CLEAR(LIST_GEN_VALUES);
      }
   }

   // - list set_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer && !(TYPE_NUMBER & c_type_dynamic)) {
LIST_SET_BUFFER(LIST_GEN_VALUES);
   }

   // - list flush method -
LIST_FLUSH(LIST_GEN_VALUES);

   // - list flush_all method -
   if (!(TYPE_NUMBER & c_type_flushable)) {
LIST_FLUSH_ALL(LIST_GEN_VALUES);
   }

   // - list swap method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_swap)) {
LIST_SWAP(LIST_GEN_VALUES);
   }

   // - list operator[] method -
LIST_OPERATOR_LE_BR_RE_BR(LIST_GEN_VALUES);

   // - list prepend method -
LIST_PREPEND(LIST_GEN_VALUES);

   // - list append method -
LIST_APPEND(LIST_GEN_VALUES);

   // - list insert_before method -
LIST_INSERT_BEFORE(LIST_GEN_VALUES);

   // - list insert_after method -
LIST_INSERT_AFTER(LIST_GEN_VALUES);

   // - list prepend_blank method -
LIST_PREPEND_BLANK(LIST_GEN_VALUES);

   // - list append_blank method -
LIST_APPEND_BLANK(LIST_GEN_VALUES);

   // - list insert_blank_before method -
LIST_INSERT_BLANK_BEFORE(LIST_GEN_VALUES);

   // - list insert_blank_after method -
LIST_INSERT_BLANK_AFTER(LIST_GEN_VALUES);

   // - list remove method -
LIST_REMOVE(LIST_GEN_VALUES);

   // - list next_idx method -
LIST_NEXT_IDX(LIST_GEN_VALUES);

   // - list prev_idx method -
LIST_PREV_IDX(LIST_GEN_VALUES);

   // - list copy_resize method -

   // - list get_idx method -

   // - list operator= method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
LIST_OPERATOR_EQUAL(LIST_GEN_VALUES);
      }
   }

   // - list operator== method -

fprintf(out_file,
"// LCOV_EXCL_STOP\n"
"\n");
   }
}/*}}}*/

void processor_s::generate_list_methods(unsigned abb_idx,unsigned a_dt_idx)
{/*{{{*/
   data_type_s &data_type = data_types[a_dt_idx];

   string_s &type_abb_string = data_type.types[0];
   unsigned type_abb_idx = abbreviations.get_idx_by_name(type_abb_string.size - 1,type_abb_string.data);

   if (type_abb_idx == c_idx_not_exist) {
      fprintf(stderr,"list: methods: abreviated type name \"%s\" does not exist\n",type_abb_string.data);
      cassert(0);
   }

   unsigned type_idx = abbreviations[type_abb_idx].data_type_idx;
   data_type_s &type = data_types[type_idx];

   if (gen_options & c_option_gen_code &&
      (include_level == 0 || gen_options & c_option_gen_includes))
   {
   // --- definition of methods ---

fprintf(out_file,
"// --- struct %s method definition ---\n"
"// LCOV_EXCL_START\n"
"\n"
,IM_STRUCT_NAME);

   // - list init method -

   // - list init_size method -

   // - list init_buffer method -

   // - list clear method -
   if (TYPE_NUMBER & c_type_dynamic) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
LIST_CLEAR(LIST_GEN_VALUES);
      }
   }

   // - list set_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer && TYPE_NUMBER & c_type_dynamic) {
LIST_SET_BUFFER(LIST_GEN_VALUES);
   }

   // - list flush method -

   // - list flush_all method -
   if (TYPE_NUMBER & c_type_flushable) {
LIST_FLUSH_ALL(LIST_GEN_VALUES);
   }

   // - list swap method -

   // - list operator[] method -

   // - list prepend method -

   // - list append method -

   // - list insert_before method -

   // - list insert_after method -

   // - list prepend_blank method -

   // - list append_blank method -

   // - list insert_blank_before method -

   // - list insert_blank_after method -

   // - list remove method -

   // - list next_idx method -

   // - list prev_idx method -

   // - list copy_resize method -
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
LIST_COPY_RESIZE(LIST_GEN_VALUES);
   }

   // - list get_idx method -
LIST_GET_IDX(LIST_GEN_VALUES);

   // - list operator= method -
   if (TYPE_NUMBER & c_type_dynamic) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
LIST_OPERATOR_EQUAL(LIST_GEN_VALUES);
      }
   }

   // - list operator== method -
LIST_OPERATOR_DOUBLE_EQUAL(LIST_GEN_VALUES);

fprintf(out_file,
"// LCOV_EXCL_STOP\n"
"\n");
   }
}/*}}}*/


#define STRUCT_GEN_PARAMS FILE *out_file,abbreviation_array_s &abbreviations,unsigned abb_idx,unsigned type_cnt,data_type_s &data_type,data_type_s **types
#define STRUCT_GEN_VALUES out_file,abbreviations,abb_idx,type_cnt,data_type,types

void STRUCT_INIT(STRUCT_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::init()\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME);
   unsigned t_idx = 0;
   do {
      if (TYPE_NUMBERS(t_idx) & c_type_dynamic) {
fprintf(out_file,
"  %s.init();\n"
,VAR_NAMES(t_idx));
      }
   } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void STRUCT_CLEAR(STRUCT_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::clear()\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME);
   unsigned t_idx = 0;
   do {
      if (TYPE_NUMBERS(t_idx) & c_type_dynamic) {
fprintf(out_file,
"  %s.clear();\n"
,VAR_NAMES(t_idx));
      }
   } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void STRUCT_SET(STRUCT_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::set("
,IM_STRUCT_NAME);
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"%s a_%s"
,IM_TYPE_NAMES(0),VAR_NAMES(0));
   }
   else {
fprintf(out_file,
"%s &a_%s"
,IM_TYPE_NAMES(0),VAR_NAMES(0));
   }
   if (TYPE_CNT > 1) {
      unsigned t_idx = 1;
      do {
         if (TYPE_NUMBERS(t_idx) & c_type_basic) {
fprintf(out_file,
",%s a_%s"
,IM_TYPE_NAMES(t_idx),VAR_NAMES(t_idx));
         }
         else {
fprintf(out_file,
",%s &a_%s"
,IM_TYPE_NAMES(t_idx),VAR_NAMES(t_idx));
         }
      } while(++t_idx < TYPE_CNT);
   }
fprintf(out_file,
")\n"
"{/*{{{*/\n"
);
   unsigned t_idx = 0;
   do {
fprintf(out_file,
"  %s = a_%s;\n"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
   } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void STRUCT_FLUSH_ALL(STRUCT_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::flush_all()\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME);
   unsigned t_idx = 0;
   do {
      if (TYPE_NUMBERS(t_idx) & c_type_flushable) {
fprintf(out_file,
"  %s.flush_all();\n"
,VAR_NAMES(t_idx));
      }
   } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void STRUCT_SWAP(STRUCT_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::swap(%s &a_second)\n"
"{/*{{{*/"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   unsigned t_idx = 0;
   do {
fprintf(out_file,
"\n"
);
      if (TYPE_NUMBERS(t_idx) & c_type_basic) {
fprintf(out_file,
"  %s tmp_%s = %s;\n"
"  %s = a_second.%s;\n"
"  a_second.%s = tmp_%s;\n"
,IM_TYPE_NAMES(t_idx),VAR_NAMES(t_idx),VAR_NAMES(t_idx),VAR_NAMES(t_idx),VAR_NAMES(t_idx),VAR_NAMES(t_idx),VAR_NAMES(t_idx));
      }
      else {
fprintf(out_file,
"  %s.swap(a_second.%s);\n"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
      }
   } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void STRUCT_OPERATOR_EQUAL(STRUCT_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline %s &%s::operator=(%s &a_src)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   unsigned t_idx = 0;
   do {
fprintf(out_file,
"  %s = a_src.%s;\n"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
   } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"\n"
"  return *this;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void STRUCT_OPERATOR_DOUBLE_EQUAL(STRUCT_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline bool %s::operator==(%s &a_second)\n"
"{/*{{{*/\n"
"  return (%s == a_second.%s"
,IM_STRUCT_NAME,IM_STRUCT_NAME,VAR_NAMES(0),VAR_NAMES(0));
   if (TYPE_CNT > 1) {
      unsigned t_idx = 1;
      do {
fprintf(out_file,
" && %s == a_second.%s"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
      } while(++t_idx < TYPE_CNT);
   }
fprintf(out_file,
");\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void processor_s::generate_struct_type()
{/*{{{*/
   string_array_s &type_names = cont_params.types;
   string_array_s &variables = cont_params.variables;
   string_array_s &fun_defs = cont_params.functions;
   string_array_s &abbs = cont_params.names;

   if (type_names.used < 1 || type_names.used != variables.used) {
      fprintf(stderr,"struct: not given name of contained type, or not same count of types and variables\n");
      cassert(0);
   }

   if (abbs.used < 1) {
      fprintf(stderr,"struct: not given name of generated structure\n");
      cassert(0);
   }

   unsigned type_cnt = type_names.used;

#ifdef _MSC_VER
   unsigned type_idxs[256];
   data_type_s *types[256];

   if (type_cnt > 256) {
      fprintf(stderr,"struct: too many contained types, max 256 supported\n");
      cassert(0);
   }
#else
   unsigned type_idxs[type_cnt];
   data_type_s *types[type_cnt];
#endif

   {
      unsigned tn_idx = 0;
      do {
         unsigned type_abb_idx = abbreviations.get_idx_by_name(type_names[tn_idx].size - 1,type_names[tn_idx].data);
         if (type_abb_idx == c_idx_not_exist) {
            fprintf(stderr,"struct: contained type \"%s\" does not exist\n",type_names[tn_idx].data);
            cassert(0);
         }

         unsigned type_idx = abbreviations[type_abb_idx].data_type_idx;
         type_idxs[tn_idx] = type_idx;

         // - test type options -
         data_type_s &type = data_types[type_idx];
         if (type.properties & c_type_option_strict_dynamic) {
            cassert(type.properties & c_type_dynamic);
         }

      } while(++tn_idx < type_cnt);
   }

   // - compute length of type name -
   unsigned data_type_name_len = 0;
   {
      unsigned t_idx = 0;
      do {
         data_type_name_len += data_types[type_idxs[t_idx]].name.size;
      } while(++t_idx < type_cnt);

      data_type_name_len += strlen(c_cont_postfixes[c_cont_struct]) - 1;
   }

   // - compose type name -
   string_s real_name;
   real_name.init();
   real_name.create(data_type_name_len);

   {
      unsigned t_idx = 0;
      char *dtn_ptr = real_name.data;
      do {
         data_type_s &type = data_types[type_idxs[t_idx]];
         memcpy(dtn_ptr,type.name.data,type.name.size - 1);
         dtn_ptr += type.name.size - 1;
         *dtn_ptr++ = '_';
      } while(++t_idx < type_cnt);

      memcpy(--dtn_ptr,c_cont_postfixes[c_cont_struct],strlen(c_cont_postfixes[c_cont_struct]));
   }

   string_s &data_type_name = abbs[0];

   unsigned data_type_idx;

   // - create abbreviation for new data type -
   if ((data_type_idx = abbreviations.get_idx_by_name(data_type_name.size - 1,data_type_name.data)) == c_idx_not_exist) {

      // - do not report duplicate structures -
      //unsigned d_idx = data_types.get_idx_by_real_name(real_name.size - 1,real_name.data);
      //if (d_idx != c_idx_not_exist) {
      //   fprintf(stderr,"DUPLICATE STRUCTURES: %s <-> %s\n",data_type_name.data,data_types[d_idx].name.data);
      //}

      data_types.push_blank();
      data_type_s &data_type = data_types.last();

      data_type.cont_idx = c_cont_struct;
      data_type.name.set(data_type_name.size - 1,data_type_name.data);
      data_type.real_name.swap(real_name);

      // - retrieve of types pointers -
      {
         unsigned tn_idx = 0;
         do {
            types[tn_idx] = &data_types[type_idxs[tn_idx]];
         } while(++tn_idx < type_cnt);
      }

      bool dynamic = false;
      bool flushable = false;

      data_type_s **t_pptr = types;
      data_type_s **t_pptr_end = types + type_cnt;
      do {
         if ((*t_pptr)->properties & c_type_dynamic) {
            dynamic = true;
            break;
         }
      } while(++t_pptr < t_pptr_end);

      t_pptr = types;
      do {
         if ((*t_pptr)->properties & c_type_flushable) {
            flushable = true;
            break;
         }
      } while(++t_pptr < t_pptr_end);

      data_type.properties =
        (dynamic ? c_type_dynamic : c_type_static) |
        (flushable ? c_type_flushable : 0);

      data_type.properties |= type_settings & c_type_option_mask;

      {
         string_array_s &dt_type_names = data_type.types;
         string_s *tn_ptr = type_names.data;
         string_s *tn_ptr_end = type_names.data + type_cnt;

         do {
            dt_type_names.push(*tn_ptr);
         } while(++tn_ptr < tn_ptr_end);
      }

      data_type.variables.swap(variables);

      data_type_idx = data_types.used - 1;
   }
   else {
      fprintf(stderr,"struct: name of generated structure \"%s\" is already used\n",data_type_name.data);
      cassert(0);
   }

   real_name.clear();

   // - check and write abbreviations -
   if (abbs.used != 0) {
      unsigned idx = 0;
      do {
         string_s &abb = abbs[idx];

         if (abbreviations.get_idx_by_name(abb.size - 1,abb.data) != c_idx_not_exist) {
            fprintf(stderr,"struct: abreviated name \"%s\" for generated structure is already used\n",abb.data);
            cassert(0);
         }

         abbreviations.push_blank();
         abbreviations.last().set(abb,data_type_idx);
      } while(++idx < abbs.used);
   }

   data_type_s &data_type = data_types[data_type_idx];

   if (gen_options & c_option_gen_code &&
      (include_level == 0 || gen_options & c_option_gen_includes))
   {
   // - definition of structure struct -

fprintf(out_file,
"// structure %s definition\n"
"\n"
,STRUCT_NAME);

   if (abbs.used > 1) {
      unsigned idx = 1;
      do {
fprintf(out_file,
"typedef struct %s %s;\n"
,abbs[0].data,abbs[idx].data);
      } while(++idx < abbs.used);
fprintf(out_file,
"\n"
);
   }

fprintf(out_file,
"/*!\n"
" * \\brief __GEN structure\n"
" */\n"
"struct %s\n"
"{\n"
,STRUCT_NAME);
   unsigned t_idx = 0;
   do {
fprintf(out_file,
"  %s %s; //!< member - %u\n"
,TYPE_NAMES(t_idx),VAR_NAMES(t_idx),t_idx);
   } while(++t_idx < TYPE_CNT);
fprintf(out_file,
"\n"
"  %s() = default;\n"
"  %s(%s &a_src) = delete;\n"
"\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_nogen_init)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN initialize structure\n"
"    */\n"
"  inline void init();\n"
"\n"
);
   }
   if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN release memory used by structure\n"
"    */\n"
"  inline void clear();\n"
"\n"
);
   }
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN set structure members\n"
"    */\n"
"  inline void set("
);
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"%s a_%s"
,TYPE_NAMES(0),VAR_NAMES(0));
   }
   else {
fprintf(out_file,
"%s &a_%s"
,TYPE_NAMES(0),VAR_NAMES(0));
   }
   if (TYPE_CNT > 1) {
      unsigned t_idx = 1;
      do {
         if (TYPE_NUMBERS(t_idx) & c_type_basic) {
fprintf(out_file,
",%s a_%s"
,TYPE_NAMES(t_idx),VAR_NAMES(t_idx));
         }
         else {
fprintf(out_file,
",%s &a_%s"
,TYPE_NAMES(t_idx),VAR_NAMES(t_idx));
         }
      } while(++t_idx < TYPE_CNT);
   }
fprintf(out_file,
");\n"
"  /*!\n"
"    * \\brief __GEN flush structure memory usage, recursive on members\n"
"    */\n"
"  inline void flush_all();\n"
"\n"
);
   if (!(STRUCT_NUMBER & c_type_option_nogen_swap)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN swap structure members with another structure\n"
"    */\n"
"  inline void swap(%s &a_second);\n"
"\n"
,STRUCT_NAME);
   }
   if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN copy structure from another structure\n"
"    * \\param a_src - reference to another structure\n"
"    * \\return reference to this structure\n"
"    */\n"
"  inline %s &operator=(%s &a_src);\n"
"\n"
,STRUCT_NAME,STRUCT_NAME);
   }
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN compare structure with another structure\n"
"    * \\param a_second - reference to another structure\n"
"    * \\return result of comparison\n"
"    */\n"
"  inline bool operator==(%s &a_second);\n"
"\n"
,STRUCT_NAME);
   if (fun_defs.used != 0) {
      unsigned f_idx = 0;
      do {
fprintf(out_file,
"  %s\n"
,fun_defs[f_idx].data);
      } while(++f_idx < fun_defs.used);
   }
fprintf(out_file,
"};\n"
"\n"
);
   }
}/*}}}*/

void processor_s::generate_struct_inlines(unsigned abb_idx,unsigned a_dt_idx)
{/*{{{*/
   data_type_s &data_type = data_types[a_dt_idx];

   unsigned type_cnt = data_type.types.used;

#ifdef _MSC_VER
   unsigned type_idxs[256];
   data_type_s *types[256];

   if (type_cnt > 256) {
      fprintf(stderr,"struct: inlines: too many contained types, max 256 supported\n");
      cassert(0);
   }
#else
   unsigned type_idxs[type_cnt];
   data_type_s *types[type_cnt];
#endif

   {
      unsigned tn_idx = 0;
      do {
         string_s &type_abb_string = data_type.types[tn_idx];
         unsigned type_abb_idx = abbreviations.get_idx_by_name(type_abb_string.size - 1,type_abb_string.data);

         if (type_abb_idx == c_idx_not_exist) {
            fprintf(stderr,"struct: inlines: abbreviated type name \"%s\" does not exist\n",type_abb_string.data);
            cassert(0);
         }

         type_idxs[tn_idx] = abbreviations[type_abb_idx].data_type_idx;
         types[tn_idx] = &data_types[type_idxs[tn_idx]];

      } while(++tn_idx < type_cnt);
   }

   if (gen_options & c_option_gen_code &&
      (include_level == 0 || gen_options & c_option_gen_includes))
   {
   // - definition of inline methods -

fprintf(out_file,
"// --- struct %s inline method definition ---\n"
"// LCOV_EXCL_START\n"
"\n"
,IM_STRUCT_NAME);

   // - struct init method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_init)) {
STRUCT_INIT(STRUCT_GEN_VALUES);
   }

   // - struct clear method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
STRUCT_CLEAR(STRUCT_GEN_VALUES);
   }

   // - struct set method -
STRUCT_SET(STRUCT_GEN_VALUES);

   // - struct flush_all method  -
STRUCT_FLUSH_ALL(STRUCT_GEN_VALUES);

   // - struct swap method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_swap)) {
STRUCT_SWAP(STRUCT_GEN_VALUES);
   }

   // - struct operator= method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
STRUCT_OPERATOR_EQUAL(STRUCT_GEN_VALUES);
   }

   // - struct operator== method -
STRUCT_OPERATOR_DOUBLE_EQUAL(STRUCT_GEN_VALUES);

fprintf(out_file,
"// LCOV_EXCL_STOP\n"
"\n");
   }
}/*}}}*/

void processor_s::generate_struct_methods(unsigned abb_idx,unsigned a_dt_idx)
{/*{{{*/
   data_type_s &data_type = data_types[a_dt_idx];

   unsigned type_cnt = data_type.types.used;

   {
      unsigned tn_idx = 0;
      do {
         string_s &type_abb_string = data_type.types[tn_idx];
         unsigned type_abb_idx = abbreviations.get_idx_by_name(type_abb_string.size - 1,type_abb_string.data);

         if (type_abb_idx == c_idx_not_exist) {
            fprintf(stderr,"struct: methods: abreviated type name \"%s\" does not exist\n",type_abb_string.data);
            cassert(0);
         }

      } while(++tn_idx < type_cnt);
   }

   if (gen_options & c_option_gen_code &&
      (include_level == 0 || gen_options & c_option_gen_includes))
   {
   // - definition of methods -

fprintf(out_file,
"// --- struct %s method definition ---\n"
"// LCOV_EXCL_START\n"
"\n"
,IM_STRUCT_NAME);

   // - struct init method -

   // - struct clear method -

   // - struct set method -

   // - struct flush_all method  -

   // - struct swap method -

   // - struct operator= method -

   // - struct operator== method -

fprintf(out_file,
"// LCOV_EXCL_STOP\n"
"\n");
   }
}/*}}}*/


#define RB_TREE_GEN_PARAMS FILE *out_file,abbreviation_array_s &abbreviations,unsigned abb_idx,data_type_s &data_type,data_type_s **types
#define RB_TREE_GEN_VALUES out_file,abbreviations,abb_idx,data_type,types

void RB_TREE___GET_GRANDPARENT_IDX(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline unsigned %s::__get_grandparent_idx(unsigned a_idx)\n"
"{/*{{{*/\n"
"  %s_node &node = data[a_idx];\n"
"\n"
"  if (node.parent_idx != c_idx_not_exist)\n"
"  {\n"
"    return data[node.parent_idx].parent_idx;\n"
"  }\n"
"\n"
"  return c_idx_not_exist;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE___GET_UNCLE_IDX(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline unsigned %s::__get_uncle_idx(unsigned a_idx)\n"
"{/*{{{*/\n"
"  unsigned gp_idx = __get_grandparent_idx(a_idx);\n"
"\n"
"  if (gp_idx != c_idx_not_exist)\n"
"  {\n"
"    %s_node &gp = data[gp_idx];\n"
"    return gp.left_idx == data[a_idx].parent_idx?gp.right_idx:gp.left_idx;\n"
"  }\n"
"\n"
"  return c_idx_not_exist;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE___GET_SIBLING_IDX(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline unsigned %s::__get_sibling_idx(unsigned a_idx)\n"
"{/*{{{*/\n"
"  %s_node &p = data[data[a_idx].parent_idx];\n"
"  return p.left_idx == a_idx?p.right_idx:p.left_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_GET_DESCENT_STACK_SIZE(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline unsigned %s::get_descent_stack_size()\n"
"{/*{{{*/\n"
"  return (unsigned)(logf(used)/c_log_of_2) << 1;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_GET_STACK_MIN_VALUE_IDX(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"unsigned %s::get_stack_min_value_idx(unsigned a_idx,unsigned **a_s_ptr)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  debug_assert(a_idx < used && data[a_idx].valid);\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert(a_idx < used);\n"
);
   }
fprintf(out_file,
"\n"
"  unsigned node_idx = a_idx;\n"
"  do {\n"
"    %s_node &node = data[node_idx];\n"
"\n"
"    if (node.left_idx == leaf_idx)\n"
"    {\n"
"      return node_idx;\n"
"    }\n"
"\n"
"    *((*a_s_ptr)++) = node_idx;\n"
"    node_idx = node.left_idx;\n"
"  } while(true);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_GET_STACK_NEXT_IDX(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline unsigned %s::get_stack_next_idx(unsigned a_idx,unsigned **a_s_ptr,const unsigned *a_stack_base)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  debug_assert(a_idx < used && data[a_idx].valid);\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert(a_idx < used);\n"
);
   }
fprintf(out_file,
"\n"
"  %s_node &node = data[a_idx];\n"
"\n"
"  if (node.right_idx != leaf_idx)\n"
"  {\n"
"    return get_stack_min_value_idx(node.right_idx,a_s_ptr);\n"
"  }\n"
"\n"
"  if (*a_s_ptr > a_stack_base)\n"
"  {\n"
"    return *(--(*a_s_ptr));\n"
"  }\n"
"\n"
"  return c_idx_not_exist;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_GET_MIN_VALUE_IDX(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"unsigned %s::get_min_value_idx(unsigned a_idx)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  debug_assert(a_idx < used && data[a_idx].valid);\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert(a_idx < used);\n"
);
   }
fprintf(out_file,
"\n"
"  unsigned node_idx = a_idx;\n"
"  do {\n"
"    %s_node &node = data[node_idx];\n"
"\n"
"    if (node.left_idx == leaf_idx)\n"
"    {\n"
"      return node_idx;\n"
"    }\n"
"\n"
"    node_idx = node.left_idx;\n"
"  } while(true);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_GET_MAX_VALUE_IDX(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"unsigned %s::get_max_value_idx(unsigned a_idx)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  debug_assert(a_idx < used && data[a_idx].valid);\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert(a_idx < used);\n"
);
   }
fprintf(out_file,
"\n"
"  unsigned node_idx = a_idx;\n"
"  do {\n"
"    %s_node &node = data[node_idx];\n"
"\n"
"    if (node.right_idx == leaf_idx)\n"
"    {\n"
"      return node_idx;\n"
"    }\n"
"\n"
"    node_idx = node.right_idx;\n"
"  } while(true);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_GET_NEXT_IDX(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"unsigned %s::get_next_idx(unsigned a_idx)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  debug_assert(a_idx < used && data[a_idx].valid);\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert(a_idx < used);\n"
);
   }
fprintf(out_file,
"\n"
"  %s_node &node = data[a_idx];\n"
"\n"
"  if (node.right_idx != leaf_idx)\n"
"  {\n"
"    return get_min_value_idx(node.right_idx);\n"
"  }\n"
"\n"
"  unsigned node_idx = a_idx;\n"
"  do {\n"
"    %s_node &node = data[node_idx];\n"
"\n"
"    if (node.parent_idx == c_idx_not_exist)\n"
"    {\n"
"      return c_idx_not_exist;\n"
"    }\n"
"\n"
"    if (data[node.parent_idx].right_idx != node_idx)\n"
"    {\n"
"      return node.parent_idx;\n"
"    }\n"
"\n"
"    node_idx = node.parent_idx;\n"
"  } while(true);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_GET_PREV_IDX(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"unsigned %s::get_prev_idx(unsigned a_idx)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  debug_assert(a_idx < used && data[a_idx].valid);\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert(a_idx < used);\n"
);
   }
fprintf(out_file,
"\n"
"  %s_node &node = data[a_idx];\n"
"\n"
"  if (node.left_idx != leaf_idx)\n"
"  {\n"
"    return get_max_value_idx(node.left_idx);\n"
"  }\n"
"\n"
"  unsigned node_idx = a_idx;\n"
"  do {\n"
"    %s_node &node = data[node_idx];\n"
"\n"
"    if (node.parent_idx == c_idx_not_exist)\n"
"    {\n"
"      return c_idx_not_exist;\n"
"    }\n"
"\n"
"    if (data[node.parent_idx].left_idx != node_idx)\n"
"    {\n"
"      return node.parent_idx;\n"
"    }\n"
"\n"
"    node_idx = node.parent_idx;\n"
"  } while(true);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE___ROTATE_LEFT(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::__rotate_left(unsigned a_idx)\n"
"{/*{{{*/\n"
"  %s_node &root = data[a_idx];\n"
"  %s_node &pivot = data[root.right_idx];\n"
"\n"
"  if (a_idx == root_idx)\n"
"  {\n"
"    root_idx = root.right_idx;\n"
"    pivot.parent_idx = c_idx_not_exist;\n"
"  }\n"
"  else\n"
"  {\n"
"    %s_node &rp = data[root.parent_idx];\n"
"    (rp.right_idx == a_idx?rp.right_idx:rp.left_idx) = root.right_idx;\n"
"\n"
"    pivot.parent_idx = root.parent_idx;\n"
"  }\n"
"\n"
"  root.parent_idx = root.right_idx;\n"
"\n"
"  root.right_idx = pivot.left_idx;\n"
"  data[root.right_idx].parent_idx = a_idx;\n"
"\n"
"  pivot.left_idx = a_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE___ROTATE_RIGHT(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::__rotate_right(unsigned a_idx)\n"
"{/*{{{*/\n"
"  %s_node &root = data[a_idx];\n"
"  %s_node &pivot = data[root.left_idx];\n"
"\n"
"  if (a_idx == root_idx)\n"
"  {\n"
"    root_idx = root.left_idx;\n"
"    pivot.parent_idx = c_idx_not_exist;\n"
"  }\n"
"  else\n"
"  {\n"
"    %s_node &rp = data[root.parent_idx];\n"
"    (rp.right_idx == a_idx?rp.right_idx:rp.left_idx) = root.left_idx;\n"
"\n"
"    pivot.parent_idx = root.parent_idx;\n"
"  }\n"
"\n"
"  root.parent_idx = root.left_idx;\n"
"\n"
"  root.left_idx = pivot.right_idx;\n"
"  data[root.left_idx].parent_idx = a_idx;\n"
"\n"
"  pivot.right_idx = a_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE___GET_NEW_INDEX(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline unsigned %s::__get_new_index()\n"
"{/*{{{*/\n"
"  unsigned new_idx;\n"
"\n"
"  if (free_idx != c_idx_not_exist)\n"
"  {\n"
"    new_idx = free_idx;\n"
"    free_idx = data[new_idx].parent_idx;\n"
"  }\n"
"  else\n"
"  {\n"
,IM_STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"    if (used >= size)\n"
"    {\n"
"      unsigned new_size = (size << 1) + c_array_add;\n"
"      debug_assert(new_size != 0);\n"
"\n"
"      copy_resize(new_size);\n"
"    }\n"
"\n"
);
   }
   else {
fprintf(out_file,
"    debug_assert(used < size);\n"
);
   }
fprintf(out_file,
"    new_idx = used++;\n"
"  }\n"
"\n" 
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  data[new_idx].valid = true;\n" 
"  count++;\n" 
"\n" 
);
   }
fprintf(out_file,
"  return new_idx;\n" 
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RB_TREE___BINARY_TREE_INSERT(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"unsigned %s::__binary_tree_insert(unsigned a_new_idx,%s &a_value,bool a_unique)\n"
"{/*{{{*/\n"
"  if (root_idx == c_idx_not_exist)\n"
"  {\n"
"    if (leaf_idx == c_idx_not_exist)\n"
"    {\n"
"      leaf_idx = __get_new_index();\n"
"      %s_node &leaf = data[leaf_idx];\n"
"\n"
,IM_STRUCT_NAME,IM_TYPE_NAMES(0),IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"      leaf.valid = false;\n"
"      leaf.color = true;\n"
"      count--;\n"
);
   }
   else {
fprintf(out_file,
"      leaf.color = true;\n"
);
   }
   if (STRUCT_NUMBER & c_type_option_check_properties) {
fprintf(out_file,
"\n"
"      leaf.left_idx = c_idx_not_exist;\n"
"      leaf.right_idx = c_idx_not_exist;\n"
);
   }
fprintf(out_file,
"    }\n"
"\n"
"    data[a_new_idx].parent_idx = c_idx_not_exist;\n"
"    root_idx = a_new_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    unsigned node_idx = root_idx;\n"
"    do {\n"
"      %s_node &node = data[node_idx];\n"
"\n"
"      int comp_result = __compare_value(a_value,node.object);\n"
"      if (comp_result < 0)\n"
"      {\n"
"        if (node.left_idx == leaf_idx)\n"
"        {\n"
"          node.left_idx = a_new_idx;\n"
"          break;\n"
"        }\n"
"        node_idx = node.left_idx;\n"
"      }\n"
"      else\n"
"      {\n"
"        if (a_unique && comp_result == 0)\n"
"        {\n"
"          return node_idx;\n"
"        }\n"
"\n"
"        if (node.right_idx == leaf_idx)\n"
"        {\n"
"          node.right_idx = a_new_idx;\n"
"          break;\n"
"        }\n"
"        node_idx = node.right_idx;\n"
"      }\n"
"    } while(true);\n"
"\n"
"    data[a_new_idx].parent_idx = node_idx;\n"
"  }\n"
"\n"
"  %s_node &new_node = data[a_new_idx];\n"
"  new_node.left_idx = leaf_idx;\n"
"  new_node.right_idx = leaf_idx;\n"
"  new_node.color = false;\n"
"\n"
"  return c_idx_not_exist;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE___REPLACE_DELETE_NODE_BY_CHILD(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::__replace_delete_node_by_child(unsigned a_idx,unsigned a_ch_idx)\n"
"{/*{{{*/\n"
"  %s_node &node = data[a_idx];\n"
"\n"
"  if (node.parent_idx != c_idx_not_exist)\n"
"  {\n"
"    %s_node &parent = data[node.parent_idx];\n"
"    (parent.left_idx == a_idx?parent.left_idx:parent.right_idx) = a_ch_idx;\n"
"\n"
"    data[a_ch_idx].parent_idx = node.parent_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    root_idx = a_ch_idx == leaf_idx?c_idx_not_exist:a_ch_idx;\n"
"    data[a_ch_idx].parent_idx = c_idx_not_exist;\n"
"  }\n"
"}/*}}}*/\n"
"\n" 
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE___REMOVE_BLACK_BLACK(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"void %s::__remove_black_black(unsigned a_idx)\n"
"{/*{{{*/\n"
"  unsigned node_idx = a_idx;\n"
"  do {\n"
"    %s_node &node = data[node_idx];\n"
"\n"
"    if (node.parent_idx == c_idx_not_exist)\n"
"    {\n"
"      return;\n"
"    }\n"
"\n"
"    unsigned parent_idx = node.parent_idx;\n"
"    %s_node &parent = data[parent_idx];\n"
"\n"
"    {\n"
"      unsigned sibling_idx = parent.left_idx == node_idx?parent.right_idx:parent.left_idx;\n"
"      %s_node &sibling = data[sibling_idx];\n"
"\n"
"      if (!sibling.color)\n"
"      {\n"
"        parent.color = false;\n"
"        sibling.color = true;\n"
"\n"
"        if (node_idx == parent.left_idx)\n"
"        {\n"
"          __rotate_left(parent_idx);\n"
"        }\n"
"        else\n"
"        {\n"
"          __rotate_right(parent_idx);\n"
"        }\n"
"      }\n"
"    }\n"
"\n"
"    {\n"
"      unsigned sibling_idx = parent.left_idx == node_idx?parent.right_idx:parent.left_idx;\n"
"      %s_node& sibling = data[sibling_idx];\n"
"\n"
"      if (parent.color && sibling.color && data[sibling.left_idx].color && data[sibling.right_idx].color)\n"
"      {\n"
"        sibling.color = false;\n"
"        node_idx = parent_idx;\n"
"        continue;\n"
"      }\n"
"      else if (!parent.color && sibling.color && data[sibling.left_idx].color && data[sibling.right_idx].color)\n"
"      {\n"
"        sibling.color = false;\n"
"        parent.color = true;\n"
"        return;\n"
"      }\n"
"      else if (sibling.color)\n"
"      {\n"
"        if (node_idx == parent.left_idx && data[sibling.right_idx].color && !data[sibling.left_idx].color)\n"
"        {\n"
"          sibling.color = false;\n"
"          data[sibling.left_idx].color = true;\n"
"          __rotate_right(sibling_idx);\n"
"        }\n"
"        else if (node_idx == parent.right_idx && data[sibling.left_idx].color && !data[sibling.right_idx].color)\n"
"        {\n"
"          sibling.color = false;\n"
"          data[sibling.right_idx].color = true;\n"
"          __rotate_left(sibling_idx);\n"
"        }\n"
"      }\n"
"\n"
"      {\n"
"        unsigned sibling_idx = parent.left_idx == node_idx?parent.right_idx:parent.left_idx;\n"
"        %s_node &sibling = data[sibling_idx];\n"
"\n"
"        sibling.color = parent.color;\n"
"        parent.color = true;\n"
"\n"
"        if (node_idx == parent.left_idx)\n"
"        {\n"
"          data[sibling.right_idx].color = true;\n"
"          __rotate_left(parent_idx);\n"
"        }\n"
"        else\n"
"        {\n"
"          data[sibling.left_idx].color = true;\n"
"          __rotate_right(parent_idx);\n"
"        }\n"
"      }\n"
"\n"
"      return;\n"
"    }\n"
"\n"
"  } while(true);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE___REMOVE_ONE_CHILD(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::__remove_one_child(unsigned a_idx,unsigned a_ch_idx)\n"
"{/*{{{*/\n"
"  %s_node &node = data[a_idx];\n"
"  __replace_delete_node_by_child(a_idx,a_ch_idx);\n"
"\n"
"  node.parent_idx = free_idx;\n"
"  free_idx = a_idx;\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  node.valid = false;\n"
"  count--;\n"
"\n"
);
   }
fprintf(out_file,
"  if (node.color)\n"
"  {\n"
"    %s_node &child_node = data[a_ch_idx];\n"
"\n"
"    if (!child_node.color)\n"
"    {\n"
"      child_node.color = true;\n"
"    }\n"
"    else\n"
"    {\n"
"      __remove_black_black(a_ch_idx);\n"
"    }\n"
"  }\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE___INSERT_OPERATION(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"void %s::__insert_operation(unsigned a_idx)\n"
"{/*{{{*/\n"
"  unsigned node_idx = a_idx;\n"
"  do {\n"
"    %s_node &node = data[node_idx];\n"
"\n"
"    if (node.parent_idx == c_idx_not_exist)\n"
"    {\n"
"      node.color = true;\n"
"      return;\n"
"    }\n"
"\n"
"    if (data[node.parent_idx].color)\n"
"    {\n"
"      return;\n"
"    }\n"
"\n"
"    unsigned uncle_idx = __get_uncle_idx(node_idx);\n"
"    if (uncle_idx != c_idx_not_exist && !data[uncle_idx].color)\n"
"    {\n"
"      data[node.parent_idx].color = true;\n"
"      data[uncle_idx].color = true;\n"
"\n"
"      node_idx = __get_grandparent_idx(node_idx);\n"
"      data[node_idx].color = false;\n"
"\n"
"      continue;\n"
"    }\n"
"    else\n"
"    {\n"
"      unsigned grandparent_idx = __get_grandparent_idx(node_idx);\n"
"\n"
"      if (node_idx == data[node.parent_idx].right_idx && node.parent_idx == data[grandparent_idx].left_idx)\n"
"      {\n"
"        __rotate_left(node.parent_idx);\n"
"        node_idx = node.left_idx;\n"
"      }\n"
"      else if (node_idx == data[node.parent_idx].left_idx && node.parent_idx == data[grandparent_idx].right_idx)\n"
"      {\n"
"        __rotate_right(node.parent_idx);\n"
"        node_idx = node.right_idx;\n"
"      }\n"
"\n"
"      {\n"
"        unsigned grandparent_idx = __get_grandparent_idx(node_idx);\n"
"        %s_node &node = data[node_idx];\n"
"\n"
"        data[node.parent_idx].color = true;\n"
"        data[grandparent_idx].color = false;\n"
"\n"
"        if (node_idx == data[node.parent_idx].left_idx && node.parent_idx == data[grandparent_idx].left_idx)\n"
"        {\n"
"          __rotate_right(grandparent_idx);\n"
"        }\n"
"        else\n"
"        {\n"
"          __rotate_left(grandparent_idx);\n"
"        }\n"
"      }\n"
"\n"
"      return;\n"
"    }\n"
"  } while(true);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_INIT(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::init()\n"
"{/*{{{*/\n"
"  size = 0;\n"
"  used = 0;\n"
,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  count = 0;\n"
);
   }
fprintf(out_file,
"  data = nullptr;\n"
"  free_idx = c_idx_not_exist;\n"
"  root_idx = c_idx_not_exist;\n"
"  leaf_idx = c_idx_not_exist;\n"
);
   if (VAR_NAMES_CNT > 0) {
fprintf(out_file,
"\n"
);
      unsigned t_idx = 0;
      do {
         if (TYPE_NUMBERS(t_idx + 1) & c_type_dynamic) {
fprintf(out_file,
"  %s.init();\n"
,VAR_NAMES(t_idx));
         }
      } while(++t_idx < VAR_NAMES_CNT);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RB_TREE_INIT_BUFFER(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::init_buffer(unsigned a_size,%s_node *a_data)\n"
"{/*{{{*/\n"
"  init();\n"
"  set_buffer(a_size,a_data);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_CLEAR(RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
fprintf(out_file,
"inline void %s::clear()\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"void %s::clear()\n"
,IM_STRUCT_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
);
   if (TYPE_NUMBERS(0) & c_type_dynamic || !(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  if (data != nullptr)\n"
"  {\n"
);
      if (TYPE_NUMBERS(0) & c_type_dynamic) {
fprintf(out_file,
"    %s_node *ptr = data;\n"
"    %s_node *ptr_end = ptr + size;\n"
"\n"
"    do {\n"
"      ptr->object.clear();\n"
"    } while(++ptr < ptr_end);\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
      }
      if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
         if (TYPE_NUMBERS(0) & c_type_dynamic) {
fprintf(out_file,
"\n"
);
         }
fprintf(out_file,
"    cfree(data);\n"
);
      }
fprintf(out_file,
"  }\n"
"\n"
);
   }
   if (VAR_NAMES_CNT > 0) {
      unsigned t_idx = 0;
      do {
         if (TYPE_NUMBERS(t_idx + 1) & c_type_dynamic) {
fprintf(out_file,
"  %s.clear();\n"
,VAR_NAMES(t_idx));
         }
      } while(++t_idx < VAR_NAMES_CNT);
fprintf(out_file,
"\n"
);
   }
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  size = 0;\n"
);
   }
fprintf(out_file,
"  used = 0;\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  count = 0;\n"
);
   }
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  data = nullptr;\n"
);
   }
fprintf(out_file,
"  free_idx = c_idx_not_exist;\n"
"  root_idx = c_idx_not_exist;\n"
"  leaf_idx = c_idx_not_exist;\n"
);
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RB_TREE_SET_BUFFER(RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
fprintf(out_file,
"inline void %s::set_buffer(unsigned a_size,%s_node *a_data)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"void %s::set_buffer(unsigned a_size,%s_node *a_data)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
"  debug_assert(a_size != 0 && a_data != nullptr);\n"
"\n"
"  clear();\n"
);
   if (TYPE_NUMBERS(0) & c_type_dynamic) {
fprintf(out_file,
"\n"
"  %s_node *ptr = a_data;\n"
"  %s_node *ptr_end = a_data + a_size;\n"
"\n"
"  do {\n"
"    ptr->object.init();\n"
"  } while(++ptr < ptr_end);\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
fprintf(out_file,
"\n"
"  size = a_size;\n"
"  data = a_data;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RB_TREE_FLUSH(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::flush()\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  copy_resize(used);\n"
);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RB_TREE_FLUSH_ALL(RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBERS(0) & c_type_flushable)) {
fprintf(out_file,
"inline void %s::flush_all()\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"void %s::flush_all()\n"
,IM_STRUCT_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  copy_resize(used);\n"
);
   }
   if (VAR_NAMES_CNT > 0) {
      if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"\n"
);
      }
      unsigned t_idx = 0;
      do {
         if (TYPE_NUMBERS(t_idx + 1) & c_type_flushable) {
fprintf(out_file,
"  %s.flush_all();\n"
,VAR_NAMES(t_idx));
         }
      } while(++t_idx < VAR_NAMES_CNT);
   }
   if (TYPE_NUMBERS(0) & c_type_flushable) {
      if (!(STRUCT_NUMBER & c_type_option_fixed_buffer) || VAR_NAMES_CNT > 0) {
fprintf(out_file,
"\n"
);
      }
fprintf(out_file,
"  if (used == 0)\n"
"  {\n"
"    return;\n"
"  }\n"
"\n"
"  %s_node *ptr = data;\n"
"  %s_node *ptr_end = ptr + used;\n"
"\n"
"  do {\n"
"    ptr->object.flush_all();\n"
"  } while(++ptr < ptr_end);\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RB_TREE_SWAP(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline void %s::swap(%s &a_second)\n"
"{/*{{{*/\n"
"  unsigned tmp_unsigned = size;\n"
"  size = a_second.size;\n"
"  a_second.size = tmp_unsigned;\n"
"\n"
"  tmp_unsigned = used;\n"
"  used = a_second.used;\n"
"  a_second.used = tmp_unsigned;\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  tmp_unsigned = count;\n"
"  count = a_second.count;\n"
"  a_second.count = tmp_unsigned;\n"
"\n"
);
   }
fprintf(out_file,
"  %s_node *tmp_data = data;\n"
"  data = a_second.data;\n"
"  a_second.data = tmp_data;\n"
"\n"
"  tmp_unsigned = free_idx;\n"
"  free_idx = a_second.free_idx;\n"
"  a_second.free_idx = tmp_unsigned;\n"
"\n"
"  tmp_unsigned = root_idx;\n"
"  root_idx = a_second.root_idx;\n"
"  a_second.root_idx = tmp_unsigned;\n"
"\n"
"  tmp_unsigned = leaf_idx;\n"
"  leaf_idx = a_second.leaf_idx;\n"
"  a_second.leaf_idx = tmp_unsigned;\n"
,IM_STRUCT_NAME);
   if (VAR_NAMES_CNT > 0) {
      unsigned t_idx = 0;
      do {
fprintf(out_file,
"\n"
);
         if (TYPE_NUMBERS(t_idx + 1) & c_type_basic) {
fprintf(out_file,
"  %s tmp_%s = %s;\n"
"  %s = a_second.%s;\n"
"  a_second.%s = tmp_%s;\n"
,IM_TYPE_NAMES(t_idx + 1),VAR_NAMES(t_idx),VAR_NAMES(t_idx),VAR_NAMES(t_idx),VAR_NAMES(t_idx),VAR_NAMES(t_idx),VAR_NAMES(t_idx));
         }
         else {
fprintf(out_file,
"  %s.swap(a_second.%s);\n"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
         }
      } while(++t_idx < VAR_NAMES_CNT);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RB_TREE_OPERATOR_LE_BR_RE_BR(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"inline %s &%s::operator[](unsigned a_idx)\n"
"{/*{{{*/\n"
,IM_TYPE_NAMES(0),IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  debug_assert(a_idx < used && data[a_idx].valid);\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert(a_idx < used);\n"
);
   }
fprintf(out_file,
"  return data[a_idx].object;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

#define TEMPLATE_RB_TREE_INSERT(FUN_NAME,VALUE_SET_CODE) \
{/*{{{*/\
   if (TYPE_NUMBERS(0) & c_type_basic) {\
fprintf(out_file,\
"inline unsigned %s::%s(%s a_value)\n"\
,IM_STRUCT_NAME,#FUN_NAME,IM_TYPE_NAMES(0));\
   }\
   else {\
fprintf(out_file,\
"inline unsigned %s::%s(%s &a_value)\n"\
,IM_STRUCT_NAME,#FUN_NAME,IM_TYPE_NAMES(0));\
   }\
fprintf(out_file,\
"{/*{{{*/\n"\
"  unsigned new_node_idx = __get_new_index();\n"\
"\n"\
"  __binary_tree_insert(new_node_idx,a_value,false);\n"\
"  __insert_operation(new_node_idx);\n"\
"\n"\
);\
   VALUE_SET_CODE;\
fprintf(out_file,\
"\n"\
"  return new_node_idx;\n"\
"}/*}}}*/\n"\
"\n"\
);\
}/*}}}*/

void RB_TREE_INSERT(RB_TREE_GEN_PARAMS)
{/*{{{*/
TEMPLATE_RB_TREE_INSERT(insert,
fprintf(out_file,
"  data[new_node_idx].object = a_value;\n"
);
);
}/*}}}*/

void RB_TREE_SWAP_INSERT(RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBERS(0) & c_type_basic)) {
TEMPLATE_RB_TREE_INSERT(swap_insert,
fprintf(out_file,
"  data[new_node_idx].object.swap(a_value);\n"
);
);
   }
}/*}}}*/

#define TEMPLATE_RB_TREE_UNIQUE_INSERT(FUN_NAME,VALUE_SET_CODE) \
{/*{{{*/\
   if (TYPE_NUMBERS(0) & c_type_basic) {\
fprintf(out_file,\
"inline unsigned %s::%s(%s a_value)\n"\
,IM_STRUCT_NAME,#FUN_NAME,IM_TYPE_NAMES(0));\
   }\
   else {\
fprintf(out_file,\
"inline unsigned %s::%s(%s &a_value)\n"\
,IM_STRUCT_NAME,#FUN_NAME,IM_TYPE_NAMES(0));\
   }\
fprintf(out_file,\
"{/*{{{*/\n"\
"  unsigned new_node_idx = __get_new_index();\n"\
"  unsigned old_node_idx = __binary_tree_insert(new_node_idx,a_value,true);\n"\
"\n"\
"  if (old_node_idx != c_idx_not_exist)\n"\
"  {\n"\
"    %s_node &new_node = data[new_node_idx];\n"\
"\n"\
"    new_node.parent_idx = free_idx;\n"\
"    free_idx = new_node_idx;\n"\
"\n"\
,IM_STRUCT_NAME);\
   if (STRUCT_NUMBER & c_type_option_safe) {\
fprintf(out_file,\
"    new_node.valid = false;\n"\
"    count--;\n"\
"\n"\
);\
   }\
fprintf(out_file,\
"    return old_node_idx;\n"\
"  }\n"\
"\n"\
"  __insert_operation(new_node_idx);\n"\
"\n"\
);\
   VALUE_SET_CODE;\
fprintf(out_file,\
"\n"\
"  return new_node_idx;\n"\
"}/*}}}*/\n"\
"\n"\
);\
}/*}}}*/

void RB_TREE_UNIQUE_INSERT(RB_TREE_GEN_PARAMS)
{/*{{{*/
TEMPLATE_RB_TREE_UNIQUE_INSERT(unique_insert,
fprintf(out_file,
"  data[new_node_idx].object = a_value;\n"
);
);
}/*}}}*/

void RB_TREE_UNIQUE_SWAP_INSERT(RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBERS(0) & c_type_basic)) {
TEMPLATE_RB_TREE_UNIQUE_INSERT(unique_swap_insert,
fprintf(out_file,
"  data[new_node_idx].object.swap(a_value);\n"
);
);
   }
}/*}}}*/

void RB_TREE_REMOVE(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"void %s::remove(unsigned a_idx)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  debug_assert(a_idx < used && data[a_idx].valid);\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert(a_idx < used);\n"
);
   }
fprintf(out_file,
"\n"
"  %s_node &del_node = data[a_idx];\n"
"\n"
"  if (del_node.left_idx != leaf_idx)\n"
"  {\n"
"    if (del_node.right_idx != leaf_idx)\n"
"    {\n"
"      unsigned found_idx = del_node.right_idx;\n"
"      do {\n"
"        %s_node &node = data[found_idx];\n"
"\n"
"        if (node.left_idx == leaf_idx)\n"
"        {\n"
"          break;\n"
"        }\n"
"\n"
"        found_idx = node.left_idx;\n"
"      } while(true);\n"
"\n"
"      %s_node &found_node = data[found_idx];\n"
"\n"
"      /* - process del_node parent_idx - */\n"
"      if (del_node.parent_idx != c_idx_not_exist)\n"
"      {\n"
"        %s_node &del_node_parent = data[del_node.parent_idx];\n"
"        (del_node_parent.left_idx == a_idx?del_node_parent.left_idx:del_node_parent.right_idx) = found_idx;\n"
"      }\n"
"      else\n"
"      {\n"
"        root_idx = found_idx;\n"
"      }\n"
"\n"
"      /* - process del_node left_idx - */\n"
"      data[del_node.left_idx].parent_idx = found_idx;\n"
"\n"
"      /* - process found_node right_idx - */\n"
"      if (found_node.right_idx != leaf_idx)\n"
"      {\n"
"        data[found_node.right_idx].parent_idx = a_idx;\n"
"      }\n"
"\n"
"      if (del_node.right_idx == found_idx)\n"
"      {\n"
"        /* - found node is right child of deleted node - */\n"
"        del_node.right_idx = found_node.right_idx;\n"
"        found_node.right_idx = a_idx;\n"
"\n"
"        found_node.parent_idx = del_node.parent_idx;\n"
"        del_node.parent_idx = found_idx;\n"
"\n"
"        found_node.left_idx = del_node.left_idx;\n"
"        del_node.left_idx = leaf_idx;\n"
"\n"
"        bool tmp_bool = found_node.color;\n"
"        found_node.color = del_node.color;\n"
"        del_node.color = tmp_bool;\n"
"      }\n"
"      else\n"
"      {\n"
"        /* - process found_node parent - */\n"
"        %s_node &found_node_parent = data[found_node.parent_idx];\n"
"        (found_node_parent.left_idx == found_idx?found_node_parent.left_idx:found_node_parent.right_idx) = a_idx;\n"
"\n"
"        /* - process del_node right_idx - */\n"
"        data[del_node.right_idx].parent_idx = found_idx;\n"
"\n"
"        /* - swap index pointers between nodes - */\n"
"        unsigned tmp_unsigned = found_node.parent_idx;\n"
"        found_node.parent_idx = del_node.parent_idx;\n"
"        del_node.parent_idx = tmp_unsigned;\n"
"\n"
"        found_node.left_idx = del_node.left_idx;\n"
"        del_node.left_idx = leaf_idx;\n"
"\n"
"        tmp_unsigned = found_node.right_idx;\n"
"        found_node.right_idx = del_node.right_idx;\n"
"        del_node.right_idx = tmp_unsigned;\n"
"\n"
"        bool tmp_bool = found_node.color;\n"
"        found_node.color = del_node.color;\n"
"        del_node.color = tmp_bool;\n"
"      }\n"
"\n"
"      __remove_one_child(a_idx,del_node.right_idx);\n"
"    }\n"
"    else\n"
"    {\n"
"      __remove_one_child(a_idx,del_node.left_idx);\n"
"    }\n"
"  }\n"
"  else\n"
"  {\n"
"    __remove_one_child(a_idx,del_node.right_idx);\n"
"  }\n"
"\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_COPY_RESIZE(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"void %s::copy_resize(unsigned a_size)\n"
"{/*{{{*/\n"
"  debug_assert(a_size >= used);\n"
,IM_STRUCT_NAME);
   if (TYPE_NUMBERS(0) & c_type_dynamic) {
fprintf(out_file,
"\n"
"  if (size > a_size)\n"
"  {\n"
"    %s_node *ptr = data + a_size;\n"
"    %s_node *ptr_end = data + size;\n"
"\n"
"    do {\n"
"      ptr->object.clear();\n"
"    } while(++ptr < ptr_end);\n"
"  }\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
fprintf(out_file,
"\n"
"  if (a_size == 0)\n"
"  {\n"
"    if (data != nullptr)\n"
"    {\n"
"      cfree(data);\n"
"    }\n"
"\n"
"    data = nullptr;\n"
"  }\n"
"  else\n"
"  {\n"
"    data = (%s_node *)crealloc(data,a_size*sizeof(%s_node));\n"
"  }\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (TYPE_NUMBERS(0) & c_type_dynamic) {
fprintf(out_file,
"\n"
"  if (a_size > size)\n"
"  {\n"
"    debug_assert(memset(data + size,0,(a_size - size)*sizeof(%s_node)) == (data + size));\n"
"\n"
"    %s_node *ptr = data + size;\n"
"    %s_node *ptr_end = data + a_size;\n"
"\n"
"    do {\n"
"      ptr->object.init();\n"
"    } while(++ptr < ptr_end);\n"
"  }\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
fprintf(out_file,
"\n"
"  size = a_size;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RB_TREE_GET_IDX(RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"unsigned %s::get_idx(%s a_value)\n"
,IM_STRUCT_NAME,IM_TYPE_NAMES(0));
   }
   else {
fprintf(out_file,
"unsigned %s::get_idx(%s &a_value)\n"
,IM_STRUCT_NAME,IM_TYPE_NAMES(0));
   }
fprintf(out_file,
"{/*{{{*/\n"
"  if (root_idx == c_idx_not_exist)\n"
"  {\n"
"    return c_idx_not_exist;\n"
"  }\n"
"\n"
"  unsigned node_idx = root_idx;\n"
"  do {\n"
"    %s_node &node = data[node_idx];\n"
"\n"
"    int comp_result = __compare_value(a_value,node.object);\n"
"    if (comp_result < 0)\n"
"    {\n"
"      node_idx = node.left_idx;\n"
"    }\n"
"    else\n"
"    {\n"
"      if (comp_result == 0)\n"
"      {\n"
"        return node_idx;\n"
"      }\n"
"\n"
"      node_idx = node.right_idx;\n"
"    }\n"
"  } while(node_idx != leaf_idx);\n"
"\n"
"  return c_idx_not_exist;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_GET_IDX_LEFT(RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"unsigned %s::get_idx_left(%s a_value)\n"
,IM_STRUCT_NAME,IM_TYPE_NAMES(0));
   }
   else {
fprintf(out_file,
"unsigned %s::get_idx_left(%s &a_value)\n"
,IM_STRUCT_NAME,IM_TYPE_NAMES(0));
   }
fprintf(out_file,
"{/*{{{*/\n"
"  if (root_idx == c_idx_not_exist)\n"
"  {\n"
"    return c_idx_not_exist;\n"
"  }\n"
"\n"
"  unsigned good_idx = c_idx_not_exist;\n"
"  unsigned node_idx = root_idx;\n"
"  do {\n"
"    %s_node &node = data[node_idx];\n"
"\n"
"    int comp_result = __compare_value(a_value,node.object);\n"
"    if (comp_result < 0)\n"
"    {\n"
"      node_idx = node.left_idx;\n"
"    }\n"
"    else\n"
"    {\n"
"      if (comp_result == 0)\n"
"      {\n"
"        good_idx = node_idx;\n"
"        node_idx = node.left_idx;\n"
"      }\n"
"      else\n"
"      {\n"
"        node_idx = node.right_idx;\n"
"      }\n"
"    }\n"
"  } while(node_idx != leaf_idx);\n"
"\n"
"  return good_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_GET_GRE_IDX(RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"unsigned %s::get_gre_idx(%s a_value)\n"
,IM_STRUCT_NAME,IM_TYPE_NAMES(0));
   }
   else {
fprintf(out_file,
"unsigned %s::get_gre_idx(%s &a_value)\n"
,IM_STRUCT_NAME,IM_TYPE_NAMES(0));
   }
fprintf(out_file,
"{/*{{{*/\n"
"  if (root_idx == c_idx_not_exist)\n"
"  {\n"
"    return c_idx_not_exist;\n"
"  }\n"
"\n"
"  unsigned good_idx = c_idx_not_exist;\n"
"  unsigned node_idx = root_idx;\n"
"  do {\n"
"    %s_node &node = data[node_idx];\n"
"\n"
"    int comp_result = __compare_value(a_value,node.object);\n"
"    if (comp_result < 0)\n"
"    {\n"
"      good_idx = node_idx;\n"
"      node_idx = node.left_idx;\n"
"    }\n"
"    else\n"
"    {\n"
"      if (comp_result == 0)\n"
"      {\n"
"        return node_idx;\n"
"      }\n"
"\n"
"      node_idx = node.right_idx;\n"
"    }\n"
"  } while(node_idx != leaf_idx);\n"
"\n"
"  return good_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_GET_LEE_IDX(RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"unsigned %s::get_lee_idx(%s a_value)\n"
,IM_STRUCT_NAME,IM_TYPE_NAMES(0));
   }
   else {
fprintf(out_file,
"unsigned %s::get_lee_idx(%s &a_value)\n"
,IM_STRUCT_NAME,IM_TYPE_NAMES(0));
   }
fprintf(out_file,
"{/*{{{*/\n"
"  if (root_idx == c_idx_not_exist)\n"
"  {\n"
"    return c_idx_not_exist;\n"
"  }\n"
"\n"
"  unsigned good_idx = c_idx_not_exist;\n"
"  unsigned node_idx = root_idx;\n"
"  do {\n"
"    %s_node &node = data[node_idx];\n"
"\n"
"    int comp_result = __compare_value(a_value,node.object);\n"
"    if (comp_result < 0)\n"
"    {\n"
"      node_idx = node.left_idx;\n"
"    }\n"
"    else\n"
"    {\n"
"      if (comp_result == 0)\n"
"      {\n"
"        return node_idx;\n"
"      }\n"
"\n"
"      good_idx = node_idx;\n"
"      node_idx = node.right_idx;\n"
"    }\n"
"  } while(node_idx != leaf_idx);\n"
"\n"
"  return good_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_GET_IDXS(RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"void %s::get_idxs(%s a_value,ui_array_s &a_idxs_array)\n"
,IM_STRUCT_NAME,IM_TYPE_NAMES(0));
   }
   else {
fprintf(out_file,
"void %s::get_idxs(%s &a_value,ui_array_s &a_idxs_array)\n"
,IM_STRUCT_NAME,IM_TYPE_NAMES(0));
   }
fprintf(out_file,
"{/*{{{*/\n"
"  a_idxs_array.used = 0;\n"
"\n"
"  if (root_idx == c_idx_not_exist)\n"
"  {\n"
"    return;\n"
"  }\n"
"\n"
"  unsigned stack[RB_TREE_STACK_SIZE(*this)];\n"
"  unsigned *stack_ptr = stack;\n"
"\n"
"  *(stack_ptr++) = root_idx;\n"
"  do {\n"
"    unsigned node_idx = *(--stack_ptr);\n"
"    %s_node &node = data[node_idx];\n"
"\n"
"    int comp_result = __compare_value(a_value,node.object);\n"
"    if (comp_result < 0)\n"
"    {\n"
"      if (node.left_idx != leaf_idx)\n"
"      {\n"
"        *(stack_ptr++) = node.left_idx;\n"
"      }\n"
"    }\n"
"    else\n"
"    {\n"
"      if (comp_result == 0)\n"
"      {\n"
"        a_idxs_array.push(node_idx);\n"
"\n"
"        if (node.left_idx != leaf_idx)\n"
"        {\n"
"          *(stack_ptr++) = node.left_idx;\n"
"        }\n"
"      }\n"
"\n"
"      if (node.right_idx != leaf_idx)\n"
"      {\n"
"        *(stack_ptr++) = node.right_idx;\n"
"      }\n"
"    }\n"
"  } while(stack_ptr > stack);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_OPERATOR_EQUAL(RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBERS(0) & c_type_dynamic) {
fprintf(out_file,
"%s &%s::operator=(%s &a_src)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"inline %s &%s::operator=(%s &a_src)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
);
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
fprintf(out_file,
"  debug_assert(a_src.used <= size);\n"
"\n"
);
   }
fprintf(out_file,
"  clear();\n"
"\n"
"  if (a_src.root_idx == c_idx_not_exist)\n"
"  {\n"
"    return *this;\n"
"  }\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"\n"
"  debug_assert(a_src.used != 0);\n"
"  copy_resize(a_src.used);\n"
);
   }
   if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
fprintf(out_file,
"\n"
"  memcpy(data,a_src.data,a_src.used*sizeof(%s_node));\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"\n"
"  %s_node *ptr = data;\n"
"  %s_node *s_ptr = a_src.data;\n"
"  %s_node *s_ptr_end = s_ptr + a_src.used;\n"
"\n"
"  do {\n"
"    ptr->object = s_ptr->object;\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"    ptr->valid = s_ptr->valid;\n"
);
   }
fprintf(out_file,
"    ptr->parent_idx = s_ptr->parent_idx;\n"
"    ptr->left_idx = s_ptr->left_idx;\n"
"    ptr->right_idx = s_ptr->right_idx;\n"
"    ptr->color = s_ptr->color;\n"
"  } while(++ptr,++s_ptr < s_ptr_end);\n"
);
   }
fprintf(out_file,
"\n"
"  used = a_src.used;\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  count = a_src.count;\n"
);
   }
fprintf(out_file,
"  free_idx = a_src.free_idx;\n"
"  root_idx = a_src.root_idx;\n"
"  leaf_idx = a_src.leaf_idx;\n"
);
   if (VAR_NAMES_CNT > 0) {
fprintf(out_file,
"\n"
);
      unsigned t_idx = 0;
      do {
fprintf(out_file,
"  %s = a_src.%s;\n"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
      } while(++t_idx < VAR_NAMES_CNT);
   }
fprintf(out_file,
"\n"
"  return *this;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RB_TREE_OPERATOR_DOUBLE_EQUAL(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"bool %s::operator==(%s &a_second)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  if (count != a_second.count)\n"
"  {\n"
"     return false;\n"
"  }\n"
"\n"
);
   }
fprintf(out_file,
"  if (root_idx == c_idx_not_exist)\n"
"  {\n"
"    if (a_second.root_idx != c_idx_not_exist)\n"
"    {\n"
"      return false;\n"
"    }\n"
"  }\n"
"  else\n"
"  {\n"
"    if (a_second.root_idx == c_idx_not_exist)\n"
"    {\n"
"      return false;\n"
"    }\n"
"\n"
"    unsigned stack[RB_TREE_STACK_SIZE(*this)];\n"
"    unsigned s_stack[RB_TREE_STACK_SIZE(a_second)];\n"
"\n"
"    unsigned *stack_ptr = stack;\n"
"    unsigned *s_stack_ptr = s_stack;\n"
"\n"
"    unsigned node_idx = get_stack_min_value_idx(root_idx,&stack_ptr);\n"
"    unsigned s_node_idx = a_second.get_stack_min_value_idx(a_second.root_idx,&s_stack_ptr);\n"
"    do {\n"
"      if (!(data[node_idx].object == a_second.data[s_node_idx].object))\n"
"      {\n"
"        return false;\n"
"      }\n"
"\n"
"      node_idx = get_stack_next_idx(node_idx,&stack_ptr,stack);\n"
"      s_node_idx = a_second.get_stack_next_idx(s_node_idx,&s_stack_ptr,s_stack);\n"
"    } while(node_idx != c_idx_not_exist && s_node_idx != c_idx_not_exist);\n"
"\n"
"    if (node_idx != s_node_idx)\n"
"    {\n"
"      return false;\n"
"    }\n"
"  }\n"
"\n"
);
   if (VAR_NAMES_CNT > 0) {
fprintf(out_file,
"  return (%s == a_second.%s"
,VAR_NAMES(0),VAR_NAMES(0));
      if (VAR_NAMES_CNT > 1) {
         unsigned t_idx = 1;
         do {
fprintf(out_file,
" && %s == a_second.%s"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
         } while(++t_idx < VAR_NAMES_CNT);
      }
fprintf(out_file,
");\n"
);
   }
   else {
fprintf(out_file,
"  return true;\n"
);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RB_TREE_REHASH_TREE(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"void %s::rehash_tree()\n"
"{/*{{{*/\n"
"  if (root_idx == c_idx_not_exist)\n"
"  {\n"
"    return;\n"
"  }\n"
"\n"
"  ui_array_s indexes;\n"
"  indexes.init();\n"
"\n"
"  {\n"
"    unsigned stack[RB_TREE_STACK_SIZE(*this)];\n"
"    unsigned *stack_ptr = stack;\n"
"\n"
"    unsigned idx = get_stack_min_value_idx(root_idx,&stack_ptr);\n"
"    do {\n"
"      indexes.push(idx);\n"
"\n"
"      idx = get_stack_next_idx(idx,&stack_ptr,stack);\n"
"    } while(idx != c_idx_not_exist);\n"
"  }\n"
"\n"
"  root_idx = c_idx_not_exist;\n"
"\n"
"  bool *processed = (bool *)cmalloc(indexes.used*sizeof(bool));\n"
"  memset(processed,false,indexes.used*sizeof(bool));\n"
"\n"
"  unsigned step = indexes.used >> 1;\n"
"  if (step > 0)\n"
"  {\n"
"    do {\n"
"      unsigned idx = step;\n"
"      do {\n"
"        if (!processed[idx])\n"
"        {\n"
"          unsigned node_idx = indexes[idx];\n"
"\n"
"          __binary_tree_insert(node_idx,data[node_idx].object,false);\n"
"          __insert_operation(node_idx);\n"
"\n"
"          processed[idx] = true;\n"
"        }\n"
"      } while((idx += step) < indexes.used);\n"
"    } while((step >>= 1) > 0);\n"
"  }\n"
"\n"
"  unsigned node_idx = indexes[0];\n"
"  __binary_tree_insert(node_idx,data[node_idx].object,false);\n"
"  __insert_operation(node_idx);\n"
"\n"
"  cfree(processed);\n"
"  indexes.clear();\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_PRINT_DOT_CODE(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"void %s::print_dot_code(FILE *a_file)\n"
"{/*{{{*/\n"
"  fprintf(a_file,\n"
"\"digraph G {\\n\"\n"
"\"   rankdir = TD\\n\"\n"
"\"   node [ shape = circle margin = 0.0 fixedsize = true width = 0.7 height = 0.7]\\n\"\n"
"\"\\n\"\n"
"  );\n"
"\n"
"  const char *node_colors[] = {\n"
"    \"red\",\n"
"    \"black\",\n"
"  };\n"
"\n"
"  fprintf(a_file,\n"
"\"   root_idx [label = \\\"R\\\" ]\\n\"\n"
"\"   root_idx -> node_%%u\\n\"\n"
"  ,root_idx);\n"
"\n"
"  if (root_idx != c_idx_not_exist)\n"
"  {\n"
"    ui_array_s stack;\n"
"    stack.init();\n"
"\n"
"    stack.push(root_idx);\n"
"    do {\n"
"      unsigned node_idx = stack.pop();\n"
"      %s_node &node = data[node_idx];\n"
"\n"
"      /* - print node - */\n"
"      fprintf(a_file,\n"
"\"   node_%%u [ color = \\\"%%s\\\" label = \\\"%%u\\\" ]\\n\"\n"
"      ,node_idx,node_colors[node.color],node_idx);\n"
"\n"
"      if (node.parent_idx != c_idx_not_exist)\n"
"      {\n"
"        fprintf(a_file,\n"
"\"   node_%%u -> node_%%u [ color = green ] \\n\"\n"
"        ,node_idx,node.parent_idx);\n"
"      }\n"
"\n"
"      if (node.left_idx != leaf_idx)\n"
"      {\n"
"        fprintf(a_file,\n"
"\"   node_%%u -> node_%%u [ label = \\\"L\\\" ]\\n\"\n"
"        ,node_idx,node.left_idx);\n"
"\n"
"        stack.push(node.left_idx);\n"
"      }\n"
"\n"
"      if (node.right_idx != leaf_idx)\n"
"      {\n"
"        fprintf(a_file,\n"
"\"   node_%%u -> node_%%u [ label = \\\"R\\\" ]\\n\"\n"
"        ,node_idx,node.right_idx);\n"
"\n"
"        stack.push(node.right_idx);\n"
"      }\n"
"    } while(stack.used > 0);\n"
"\n"
"    stack.clear();\n"
"  }\n"
"\n"
"  fprintf(a_file,\n"
"\"}\\n\"\n"
"\"\\n\");\n"
"\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_CHECK_PROPERTIES(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"bool %s::check_properties()\n"
"{/*{{{*/\n"
"  %s_node &leaf = data[leaf_idx];\n"
"  if (!leaf.color)\n"
"  {\n"
"    fprintf(stderr,\"ERROR: leaf_node color\\n\");\n"
"    return false;\n"
"  }\n"
"\n"
"  if (leaf.left_idx != c_idx_not_exist || leaf.right_idx != c_idx_not_exist)\n"
"  {\n"
"    fprintf(stderr,\"ERROR: leaf_node indexes (INFO: is allowed setting in mt_automaton code?)\\n\");\n"
"    return false;\n"
"  }\n"
"\n"
"  if (root_idx != c_idx_not_exist)\n"
"  {\n"
"    /* - check if root node is black - */\n"
"    %s_node &r_node = data[root_idx];\n"
"    if (!r_node.color)\n"
"    {\n"
"      fprintf(stderr,\"ERROR: root node is not black\\n\");\n"
"      return false;\n"
"    }\n"
"\n"
"    /* - create node index and path length stacks - */\n"
"    ui_array_s ni_stack;\n"
"    ui_array_s pl_stack;\n"
"\n"
"    ni_stack.init();\n"
"    pl_stack.init();\n"
"\n"
"    /* - insert root on stack - */\n"
"    ni_stack.push(root_idx);\n"
"    pl_stack.push(0);\n"
"\n"
"    unsigned r_path_length = c_idx_not_exist;\n"
"    do {\n"
"      unsigned node_idx = ni_stack.pop();\n"
"      unsigned path_length = pl_stack.pop();\n"
"      unsigned stack_depth = ni_stack.used;\n"
"\n"
"      %s_node &node = data[node_idx];\n"
"\n"
"      if (node.color)\n"
"      {\n"
"        path_length++;\n"
"      }\n"
"      else\n"
"      {\n"
"        if (node.left_idx == c_idx_not_exist || node.right_idx == c_idx_not_exist)\n"
"        {\n"
"          fprintf(stderr,\"ERROR: red node has not two childs!\\n\");\n"
"          ni_stack.clear();\n"
"          pl_stack.clear();\n"
"          return false;\n"
"        }\n"
"\n"
"        if (!data[node.left_idx].color || !data[node.right_idx].color)\n"
"        {\n"
"          fprintf(stderr,\"ERROR: child of red node is not black!\\n\");\n"
"          ni_stack.clear();\n"
"          pl_stack.clear();\n"
"          return false;\n"
"        }\n"
"      }\n"
"\n"
"      if (node.left_idx != c_idx_not_exist)\n"
"      {\n"
"        ni_stack.push(node.left_idx);\n"
"        pl_stack.push(path_length);\n"
"      }\n"
"\n"
"      if (node.right_idx != c_idx_not_exist)\n"
"      {\n"
"        ni_stack.push(node.right_idx);\n"
"        pl_stack.push(path_length);\n"
"      }\n"
"\n"
"      /* - if node is leaf node - */\n"
"      if (stack_depth == ni_stack.used)\n"
"      {\n"
"        if (r_path_length != c_idx_not_exist)\n"
"        {\n"
"          if (r_path_length != path_length)\n"
"          {\n"
"            fprintf(stderr,\"ERROR: all path have no same length!\\n\");\n"
"            ni_stack.clear();\n"
"            pl_stack.clear();\n"
"            return false;\n"
"          }\n"
"        }\n"
"        else\n"
"        {\n"
"          r_path_length = path_length;\n"
"        }\n"
"      }\n"
"\n"
"    } while(ni_stack.used > 0);\n"
"\n"
"    ni_stack.clear();\n"
"    pl_stack.clear();\n"
"  }\n"
"\n"
"  /* - test if are node values sorted - */\n"
"  if (root_idx != c_idx_not_exist)\n"
"  {\n"
"    unsigned stack[RB_TREE_STACK_SIZE(*this)];\n"
"    unsigned *stack_ptr = stack;\n"
"\n"
"    unsigned idx = get_stack_min_value_idx(root_idx,&stack_ptr);\n"
"    do {\n"
"      unsigned l_idx = idx;\n"
"      idx = get_stack_next_idx(idx,&stack_ptr,stack);\n"
"      if (idx == c_idx_not_exist)\n"
"      {\n"
"        break;\n"
"      }\n"
"\n"
"      if (__compare_value(data[l_idx].object,data[idx].object) == 1)\n"
"      {\n"
"        fprintf(stderr,\"ERROR: values in rb_tree are not sorted\\n\");\n"
"        return false;\n"
"      }\n"
"    } while(true);\n"
"  }\n"
"\n"
"  return true;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void processor_s::generate_rb_tree_type()
{/*{{{*/
   string_array_s &type_names = cont_params.types;
   string_array_s &variables = cont_params.variables;
   string_array_s &fun_defs = cont_params.functions;
   string_array_s &abbs = cont_params.names;

   if (type_names.used < 1) {
      fprintf(stderr,"rb_tree: not given name of contained type\n");
      cassert(0);
   }

   if (variables.used != (type_names.used - 1)) {
      fprintf(stderr,"rb_tree: not enought names for variables\n");
      cassert(0);
   }

   if (abbs.used < 1) {
      fprintf(stderr,"rb_tree: not given name of generated structure\n");
      cassert(0);
   }

   unsigned type_cnt = type_names.used;

#ifdef _MSC_VER
   unsigned type_idxs[256];
   data_type_s *types[256];

   if (type_cnt > 256) {
      fprintf(stderr,"rb_tree: too many contained types, max 256 supported\n");
      cassert(0);
   }
#else
   unsigned type_idxs[type_cnt];
   data_type_s *types[type_cnt];
#endif

   {
      unsigned tn_idx = 0;
      do {
         unsigned type_abb_idx = abbreviations.get_idx_by_name(type_names[tn_idx].size - 1,type_names[tn_idx].data);
         if (type_abb_idx == c_idx_not_exist) {
            fprintf(stderr,"rb_tree: contained type \"%s\" does not exist\n",type_names[tn_idx].data);
            cassert(0);
         }

         unsigned type_idx = abbreviations[type_abb_idx].data_type_idx;
         type_idxs[tn_idx] = type_idx;

         // - test type options -
         if (data_types[type_idx].properties & c_type_option_strict_dynamic) {
            fprintf(stderr,"rb_tree: container have not implemented processing of types with option strict_dynamic\n");
            cassert(0);
         }

      } while(++tn_idx < type_cnt);
   }

   // - compute length of type name -
   unsigned data_type_name_len = 0;
   {
      unsigned t_idx = 0;
      do {
         data_type_name_len += data_types[type_idxs[t_idx]].name.size;
      } while(++t_idx < type_cnt);

      data_type_name_len += strlen(c_cont_postfixes[c_cont_rb_tree]) - 1;
   }

   // - compose name of type -
   string_s real_name;
   real_name.init();
   real_name.create(data_type_name_len);

   {
      unsigned t_idx = 0;
      char *dtn_ptr = real_name.data;
      do {
         data_type_s &type = data_types[type_idxs[t_idx]];
         memcpy(dtn_ptr,type.name.data,type.name.size - 1);
         dtn_ptr += type.name.size - 1;
         *dtn_ptr++ = '_';
      } while(++t_idx < type_cnt);

      memcpy(--dtn_ptr,c_cont_postfixes[c_cont_rb_tree],strlen(c_cont_postfixes[c_cont_rb_tree]));
   }

   string_s &data_type_name = abbs[0];

   unsigned data_type_idx;

   if ((data_type_idx = abbreviations.get_idx_by_name(data_type_name.size - 1,data_type_name.data)) == c_idx_not_exist) {

      // - do not report duplicate structures -
      //unsigned d_idx = data_types.get_idx_by_real_name(real_name.size - 1,real_name.data);
      //if (d_idx != c_idx_not_exist) {
      //   fprintf(stderr,"DUPLICATE STRUCTURES: %s <-> %s\n",data_type_name.data,data_types[d_idx].name.data);
      //}

      data_types.push_blank();
      data_type_s &data_type = data_types.last();

      data_type.cont_idx = c_cont_rb_tree;
      data_type.name.set(data_type_name.size - 1,data_type_name.data);
      data_type.real_name.swap(real_name);

      // - retrieve of types pointers -
      {
         unsigned tn_idx = 0;
         do {
            types[tn_idx] = &data_types[type_idxs[tn_idx]];
         } while(++tn_idx < type_cnt);
      }

      data_type.properties = c_type_dynamic | c_type_flushable | (type_settings & c_type_option_mask);

      {
         string_array_s &dt_type_names = data_type.types;
         string_s *tn_ptr = type_names.data;
         string_s *tn_ptr_end = type_names.data + type_cnt;

         do {
            dt_type_names.push(*tn_ptr);
         } while(++tn_ptr < tn_ptr_end);
      }

      data_type.variables.swap(variables);

      data_type_idx = data_types.used - 1;
   }
   else {
      fprintf(stderr,"rb_tree: name of generated structure \"%s\" is already used\n",data_type_name.data);
      cassert(0);
   }

   real_name.clear();

   // - check and write abbreviations -
   if (abbs.used != 0) {
      unsigned idx = 0;
      do {
         string_s &abb = abbs[idx];

         if (abbreviations.get_idx_by_name(abb.size - 1,abb.data) != c_idx_not_exist) {
            fprintf(stderr,"rb_tree: abreviated name \"%s\" for generated structure is already used\n",abb.data);
            cassert(0);
         }

         abbreviations.push_blank();
         abbreviations.last().set(abb,data_type_idx);
      } while(++idx < abbs.used);
   }

   data_type_s &data_type = data_types[data_type_idx];

   if (gen_options & c_option_gen_code &&
      (include_level == 0 || gen_options & c_option_gen_includes))
   {
   // - definition of structure rb_tree -

fprintf(out_file,
"// struct %s definition\n"
"\n"
,STRUCT_NAME);

   if (abbs.used > 1) {
      unsigned idx = 1;
      do {
fprintf(out_file,
"typedef struct %s %s;\n"
,abbs[0].data,abbs[idx].data);
      } while(++idx < abbs.used);
fprintf(out_file,
"\n"
);
   }

fprintf(out_file,
"/*!\n"
" * \\brief __GEN node of rb_tree of type %s\n"
" */\n"
"\n"
"struct %s_node\n"
"{\n"
"  unsigned parent_idx;\n"
"  unsigned left_idx;\n"
"  unsigned right_idx;\n"
"  bool color;\n"
,IM_TYPE_NAMES(0),STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  bool valid;\n"
);
   }
fprintf(out_file,
"  %s object;\n"
"};\n"
"\n"
"/*!\n"
" * \\brief __GEN rb_tree of type %s\n"
" */\n"
"struct %s\n"
"{\n"
"  unsigned size;\n"
"  unsigned used;\n"
,IM_TYPE_NAMES(0),IM_TYPE_NAMES(0),STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  unsigned count;\n"
);
   }
fprintf(out_file,
"  %s_node *data;\n"
"  unsigned free_idx;\n"
"  unsigned root_idx;\n"
"  unsigned leaf_idx;\n"
,STRUCT_NAME);
   if (VAR_NAMES_CNT > 0) {
      unsigned t_idx = 0;
      do {
fprintf(out_file,
"  %s %s; //!< member - %u\n"
,TYPE_NAMES(t_idx + 1),VAR_NAMES(t_idx),t_idx);
      } while(++t_idx < VAR_NAMES_CNT);
   }
fprintf(out_file,
"\n"
"  // - internal support methods -\n"
"  inline unsigned __get_grandparent_idx(unsigned a_idx);\n"
"  inline unsigned __get_uncle_idx(unsigned a_idx);\n"
"  inline unsigned __get_sibling_idx(unsigned a_idx);\n"
"\n"
"  inline unsigned get_descent_stack_size();\n"
"  EXPORT unsigned get_stack_min_value_idx(unsigned a_idx,unsigned **a_s_ptr);\n"
"  inline unsigned get_stack_next_idx(unsigned a_idx,unsigned **a_s_ptr,const unsigned *a_stack_base);\n"
"\n"
"  EXPORT unsigned get_min_value_idx(unsigned a_idx);\n"
"  EXPORT unsigned get_max_value_idx(unsigned a_idx);\n"
"  EXPORT unsigned get_next_idx(unsigned a_idx);\n"
"  EXPORT unsigned get_prev_idx(unsigned a_idx);\n"
"\n"
"  inline void __rotate_left(unsigned a_idx);\n"
"  inline void __rotate_right(unsigned a_idx);\n"
"\n"
"  inline unsigned __get_new_index();\n"
"  EXPORT unsigned __binary_tree_insert(unsigned a_new_idx,%s &a_value,bool a_unique);\n"
"\n"
"  inline void __replace_delete_node_by_child(unsigned a_idx,unsigned a_ch_idx);\n"
"  void __remove_black_black(unsigned a_idx);\n"
"\n"
"  inline void __remove_one_child(unsigned a_idx,unsigned a_ch_idx);\n"
"\n"
"  EXPORT void __insert_operation(unsigned a_idx);\n"
"\n"
"  inline int __compare_value(%s &a_first,%s &a_second);\n"
"\n"
,IM_TYPE_NAMES(0),IM_TYPE_NAMES(0),IM_TYPE_NAMES(0));
fprintf(out_file,
"  %s() = default;\n"
"  %s(%s &a_src) = delete;\n"
"\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_nogen_init)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN initialize rb_tree\n"
"    */\n"
"  inline void init();\n"
"\n"
);
   }
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN initialize/set underlaying data buffer\n"
"    * \\param a_size - size of data buffer\n"
"    * \\param a_data - pointer to data buffer\n"
"    */\n"
"  inline void init_buffer(unsigned a_size,%s_node *a_data);\n"
"\n"
,STRUCT_NAME);
   }
   if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
      if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN release memory used by rb_tree\n"
"    */\n"
"  inline void clear();\n"
"\n"
);
      }
      else {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN release memory used by rb_tree\n"
"    */\n"
"  EXPORT void clear();\n"
"\n"
);
      }
   }
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
     if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN set underlaying data buffer\n"
"    * \\param a_size - size of data buffer\n"
"    * \\param a_data - pointer to data buffer\n"
"    */\n"
"  inline void set_buffer(unsigned a_size,%s_node *a_data);\n"
"\n"
,STRUCT_NAME);
      }
      else {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN set underlaying data buffer\n"
"    * \\param a_size - size of data buffer\n"
"    * \\param a_data - pointer to data buffer\n"
"    */\n"
"  EXPORT void set_buffer(unsigned a_size,%s_node *a_data);\n"
"\n"
,STRUCT_NAME);
      }
   }
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN flush rb_tree memory usage\n"
"    */\n"
"  inline void flush();\n"
"\n"
);
   if (!(TYPE_NUMBERS(0) & c_type_flushable)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN flush rb_tree memory usage, recursive on nodes\n"
"    */\n"
"  inline void flush_all();\n"
"\n"
);
   }
   else {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN flush rb_tree memory usage, recursive on nodes\n"
"    */\n"
"  EXPORT void flush_all();\n"
"\n"
);
   }
   if (!(STRUCT_NUMBER & c_type_option_nogen_swap)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN swap members of rb_tree with another rb_tree\n"
"    * \\param a_second - reference to another rb_tree\n"
"    */\n"
"  inline void swap(%s &a_second);\n"
"\n"
,STRUCT_NAME);
   }
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN select ode of rb_tree\n"
"    * \\param a_idx - index of node in rb_tree\n"
"    * \\return reference to node of rb_tree\n"
"    */\n"
"  inline %s &operator[](unsigned a_idx);\n"
"\n"
,IM_TYPE_NAMES(0));
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN insert node to rb_tree\n"
"    * \\param a_value - value inserted to rb_tree\n"
"    * \\return - position of node in rb_tree\n"
"    */\n"
"  inline unsigned insert(%s a_value);\n"
"\n"
"  /*!\n"
"    * \\brief __GEN insert node to rb_tree if it not exist yet\n"
"    * \\param a_value - value inserted to rb_tree\n"
"    * \\return - position of node in rb_tree\n"
"    */\n"
"  inline unsigned unique_insert(%s a_value);\n"
"\n"
,IM_TYPE_NAMES(0),IM_TYPE_NAMES(0));
   }
   else {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN insert node to rb_tree\n"
"    * \\param a_value - reference to value inserted to rb_tree\n"
"    * \\return - position of node in rb_tree\n"
"    */\n"
"  inline unsigned insert(%s &a_value);\n"
"\n"
"  /*!\n"
"    * \\brief __GEN insert node to rb_tree if it not exist yet\n"
"    * \\param a_value - reference to value inserted to rb_tree\n"
"    * \\return - position of node in rb_tree\n"
"    */\n"
"  inline unsigned unique_insert(%s &a_value);\n"
"\n"
,IM_TYPE_NAMES(0),IM_TYPE_NAMES(0));
   }
   if (!(TYPE_NUMBERS(0) & c_type_basic)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN insert node to rb_tree by swapping\n"
"    * \\param a_value - reference to value inserted to rb_tree\n"
"    * \\return - position of node in rb_tree\n"
"    */\n"
"  inline unsigned swap_insert(%s &a_value);\n"
"\n"
"  /*!\n"
"    * \\brief __GEN insert node to rb_tree by swapping if it not exist yet\n"
"    * \\param a_value - reference to value inserted to rb_tree\n"
"    * \\return - position of node in rb_tree\n"
"    */\n"
"  inline unsigned unique_swap_insert(%s &a_value);\n"
"\n"
,IM_TYPE_NAMES(0),IM_TYPE_NAMES(0));
   }
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN remove node at index from rb_tree\n"
"    * \\param a_idx - index of node to remove\n"
"    */\n"
"  EXPORT void remove(unsigned a_idx);\n"
"\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN resize rb_tree capacity\n"
"    * \\param a_size - requested rb_tree capacity\n"
"    */\n"
"  EXPORT void copy_resize(unsigned a_size);\n"
"\n"
);
   }
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN search for index of node\n"
"    * \\param a_value - value which index is searched\n"
"    */\n"
"  EXPORT unsigned get_idx(%s a_value);\n"
"\n"
"  /*!\n"
"    * \\brief __GEN search for leftmost index of node\n"
"    * \\param a_value - value which index is searched\n"
"    */\n"
"  EXPORT unsigned get_idx_left(%s a_value);\n"
"\n"
"  /*!\n"
"    * \\brief __GEN search for index of node with greater or equal value\n"
"    * \\param a_value - value which index is searched\n"
"    */\n"
"  EXPORT unsigned get_gre_idx(%s a_value);\n"
"\n"
"  /*!\n"
"    * \\brief __GEN search for index of node with less or equal value\n"
"    * \\param a_value - value which index is searched\n"
"    */\n"
"  EXPORT unsigned get_lee_idx(%s a_value);\n"
"\n"
,IM_TYPE_NAMES(0),IM_TYPE_NAMES(0),IM_TYPE_NAMES(0),IM_TYPE_NAMES(0));
   }
   else {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN search for index of node\n"
"    * \\param a_value - value which index is searched\n"
"    */\n"
"  EXPORT unsigned get_idx(%s &a_value);\n"
"\n"
"  /*!\n"
"    * \\brief __GEN search for leftmost index of node\n"
"    * \\param a_value - value which index is searched\n"
"    */\n"
"  EXPORT unsigned get_idx_left(%s &a_value);\n"
"\n"
"  /*!\n"
"    * \\brief __GEN search for index of node with greater or equal value\n"
"    * \\param a_value - value which index is searched\n"
"    */\n"
"  EXPORT unsigned get_gre_idx(%s &a_value);\n"
"\n"
"  /*!\n"
"    * \\brief __GEN search for index of node with less or equal value\n"
"    * \\param a_value - value which index is searched\n"
"    */\n"
"  EXPORT unsigned get_lee_idx(%s &a_value);\n"
"\n"
,IM_TYPE_NAMES(0),IM_TYPE_NAMES(0),IM_TYPE_NAMES(0),IM_TYPE_NAMES(0));
   }
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN search for all indexes of node\n"
"    * \\param a_value - value of searched index\n"
"    */\n"
"  EXPORT void get_idxs(%s a_value,ui_array_s &a_idxs_array);\n"
"\n"
,IM_TYPE_NAMES(0));
   }
   else {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN search for all indexes of node\n"
"    * \\param a_value - value of searched index\n"
"    */\n"
"  EXPORT void get_idxs(%s &a_value,ui_array_s &a_idxs_array);\n"
"\n"
,IM_TYPE_NAMES(0));
   }
   if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
      if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN copy rb_tree from another rb_tree\n"
"    * \\param a_src - reference to another rb_tree\n"
"    * \\return reference to this rb_tree\n"
"    */\n"
"  inline %s &operator=(%s &a_src);\n"
"\n"
,STRUCT_NAME,STRUCT_NAME);
      }
      else {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN copy rb_tree from another rb_tree\n"
"    * \\param a_src - reference to another rb_tree\n"
"    * \\return reference to this rb_tree\n"
"    */\n"
"  EXPORT %s &operator=(%s &a_src);\n"
"\n"
,STRUCT_NAME,STRUCT_NAME);
      }
   }
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN compare rb_tree with another rb_tree\n"
"    * \\param a_second - reference to another rb_tree\n"
"    * \\return result of comparision\n"
"    */\n"
"  EXPORT bool operator==(%s &a_second);\n"
"\n"
,STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_rehash) {
fprintf(out_file,
"  /*!\n"
"    * \\brief __GEN rehash tree (after invalidation by change of object value)\n"
"    */\n"
"  EXPORT void rehash_tree();\n"
"\n"
);
   }
   if (STRUCT_NUMBER & c_type_option_print_dot_code) {
fprintf(out_file,
"  /*\n"
"    * \\brief __GEN print dot code of rb_tree (for debugging)\n"
"    * \\param a_file - file to which is code writed\n"
"    */\n"
"  EXPORT void print_dot_code(FILE *a_file);\n"
"\n"
);
   }
   if (STRUCT_NUMBER & c_type_option_check_properties) {
fprintf(out_file,
"  /*\n"
"    * \\brief __GEN test properties of red black tree\n"
"    * \\return true if all red black tree properties are valid\n"
"    */\n"
"  EXPORT bool check_properties();\n"
"\n"
);
   }
   if (fun_defs.used != 0) {
      unsigned f_idx = 0;
      do {
fprintf(out_file,
"  %s\n"
,fun_defs[f_idx].data);
      } while(++f_idx < fun_defs.used);
   }
fprintf(out_file,
"};\n"
"\n"
);
  }
}/*}}}*/

void processor_s::generate_rb_tree_inlines(unsigned abb_idx,unsigned a_dt_idx)
{/*{{{*/
   data_type_s &data_type = data_types[a_dt_idx];

   unsigned type_cnt = data_type.types.used;

#ifdef _MSC_VER
   unsigned type_idxs[256];
   data_type_s *types[256];

   if (type_cnt > 256) {
      fprintf(stderr,"rb_tree: inlines: too many contained types, max 256 supported\n");
      cassert(0);
   }
#else
   unsigned type_idxs[type_cnt];
   data_type_s *types[type_cnt];
#endif

   {
      unsigned tn_idx = 0;
      do {
         string_s &type_abb_string = data_type.types[tn_idx];
         unsigned type_abb_idx = abbreviations.get_idx_by_name(type_abb_string.size - 1,type_abb_string.data);

         if (type_abb_idx == c_idx_not_exist) {
            fprintf(stderr,"rb_tree: inlines: abbreviated type name \"%s\" does not exist\n",type_abb_string.data);
            cassert(0);
         }

         type_idxs[tn_idx] = abbreviations[type_abb_idx].data_type_idx;
         types[tn_idx] = &data_types[type_idxs[tn_idx]];

      } while(++tn_idx < type_cnt);
   }

   if (gen_options & c_option_gen_code &&
      (include_level == 0 || gen_options & c_option_gen_includes))
   {
   // --- definition of inline methods ---

fprintf(out_file,
"// --- struct %s inline method definition ---\n"
"// LCOV_EXCL_START\n"
"\n"
,IM_STRUCT_NAME);

   // - rb_tree __get_grandparent_idx method -
RB_TREE___GET_GRANDPARENT_IDX(RB_TREE_GEN_VALUES);

   // - rb_tree __get_uncle_idx method -
RB_TREE___GET_UNCLE_IDX(RB_TREE_GEN_VALUES);

   // - rb_tree __get_sibling_idx method -
RB_TREE___GET_SIBLING_IDX(RB_TREE_GEN_VALUES);

   // - rb_tree get_descent_stack_size -
RB_TREE_GET_DESCENT_STACK_SIZE(RB_TREE_GEN_VALUES);

   // - rb_tree get_stack_min_value_idx method -

   // - rb_tree get_stack_next_idx method -
RB_TREE_GET_STACK_NEXT_IDX(RB_TREE_GEN_VALUES);

   // - rb_tree get_min_value_idx method -

   // - rb_tree get_max_value_idx method -

   // - rb_tree get_next_idx method -

   // - rb_tree get_prev_idx method -

   // - rb_tree __rotate_left method -
RB_TREE___ROTATE_LEFT(RB_TREE_GEN_VALUES);

   // - rb_tree __rotate_right method -
RB_TREE___ROTATE_RIGHT(RB_TREE_GEN_VALUES);

   // - rb_tree __get_new_index method -
RB_TREE___GET_NEW_INDEX(RB_TREE_GEN_VALUES);

   // - rb_tree __binary_tree_insert method -

   // - rb_tree __replace_delete_node_by_child method -
RB_TREE___REPLACE_DELETE_NODE_BY_CHILD(RB_TREE_GEN_VALUES);

   // - rb_tree __remove_black_black method -

   // - rb_tree __remove_one_child method -
RB_TREE___REMOVE_ONE_CHILD(RB_TREE_GEN_VALUES);

   // - rb_tree __insert_operation method -

   // - rb_tree init method -
RB_TREE_INIT(RB_TREE_GEN_VALUES);

   // - rb_tree init_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
RB_TREE_INIT_BUFFER(RB_TREE_GEN_VALUES);
   }

   // - rb_tree clear method -
   if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
RB_TREE_CLEAR(RB_TREE_GEN_VALUES);
      }
   }

   // - rb_tree set_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer && !(TYPE_NUMBERS(0) & c_type_dynamic)) {
RB_TREE_SET_BUFFER(RB_TREE_GEN_VALUES);
   }

   // - rb_tree flush method -
RB_TREE_FLUSH(RB_TREE_GEN_VALUES);

   // - rb_tree flush_all method -
   if (!(TYPE_NUMBERS(0) & c_type_flushable)) {
RB_TREE_FLUSH_ALL(RB_TREE_GEN_VALUES);
   }

   // - rb_tree swap method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_swap)) {
RB_TREE_SWAP(RB_TREE_GEN_VALUES);
   }

   // - rb_tree operator[] method -
RB_TREE_OPERATOR_LE_BR_RE_BR(RB_TREE_GEN_VALUES);

   // - rb_tree insert method -
RB_TREE_INSERT(RB_TREE_GEN_VALUES);

   // - rb_tree swap_insert method -
RB_TREE_SWAP_INSERT(RB_TREE_GEN_VALUES);

   // - rb_tree unique_insert method -
RB_TREE_UNIQUE_INSERT(RB_TREE_GEN_VALUES);

   // - rb_tree unique_swap_insert method -
RB_TREE_UNIQUE_SWAP_INSERT(RB_TREE_GEN_VALUES);

   // - rb_tree remove method -

   // - rb_tree copy_resize method -

   // - rb_tree get_idx method -

   // - rb_tree get_idx_left method -

   // - rb_tree get_gre_idx method -

   // - rb_tree get_lee_idx method -

   // - rb_tree get_idxs method -

   // - rb_tree operator= method -
   if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
RB_TREE_OPERATOR_EQUAL(RB_TREE_GEN_VALUES);
      }
   }

   // - rb_tree operator== method -

   // - rb_tree rehash_tree -

   // - rb_tree print_dot_code -

   // - rb_tree check_properties -

fprintf(out_file,
"// LCOV_EXCL_STOP\n"
"\n");
   }
}/*}}}*/

void processor_s::generate_rb_tree_methods(unsigned abb_idx,unsigned a_dt_idx)
{/*{{{*/
   data_type_s &data_type = data_types[a_dt_idx];

   unsigned type_cnt = data_type.types.used;

#ifdef _MSC_VER
   unsigned type_idxs[256];
   data_type_s *types[256];

   if (type_cnt > 256) {
      fprintf(stderr,"rb_tree: methods: too many contained types, max 256 supported\n");
      cassert(0);
   }
#else
   unsigned type_idxs[type_cnt];
   data_type_s *types[type_cnt];
#endif

   {
      unsigned tn_idx = 0;
      do {
         string_s &type_abb_string = data_type.types[tn_idx];
         unsigned type_abb_idx = abbreviations.get_idx_by_name(type_abb_string.size - 1,type_abb_string.data);

         if (type_abb_idx == c_idx_not_exist) {
            fprintf(stderr,"rb_tree: methods: abreviated type name \"%s\" does not exist\n",type_abb_string.data);
            cassert(0);
         }

         type_idxs[tn_idx] = abbreviations[type_abb_idx].data_type_idx;
         types[tn_idx] = &data_types[type_idxs[tn_idx]];

      } while(++tn_idx < type_cnt);
   }

   if (gen_options & c_option_gen_code &&
      (include_level == 0 || gen_options & c_option_gen_includes))
   {
   // --- definition of methods ---

fprintf(out_file,
"// --- struct %s method definition ---\n"
"// LCOV_EXCL_START\n"
"\n"
,IM_STRUCT_NAME);

   // - rb_tree __get_grandparent_idx method -

   // - rb_tree __get_uncle_idx method -

   // - rb_tree __get_sibling_idx method -

   // - rb_tree get_descent_stack_size -

   // - rb_tree get_stack_min_value_idx method -
RB_TREE_GET_STACK_MIN_VALUE_IDX(RB_TREE_GEN_VALUES);

   // - rb_tree get_stack_next_idx method -

   // - rb_tree get_min_value_idx method -
RB_TREE_GET_MIN_VALUE_IDX(RB_TREE_GEN_VALUES);

   // - rb_tree get_max_value_idx method -
RB_TREE_GET_MAX_VALUE_IDX(RB_TREE_GEN_VALUES);

   // - rb_tree get_next_idx method -
RB_TREE_GET_NEXT_IDX(RB_TREE_GEN_VALUES);

   // - rb_tree get_prev_idx method -
RB_TREE_GET_PREV_IDX(RB_TREE_GEN_VALUES);

   // - rb_tree __rotate_left method -

   // - rb_tree __rotate_right method -

   // - rb_tree __get_new_index method -

   // - rb_tree __binary_tree_insert method -
RB_TREE___BINARY_TREE_INSERT(RB_TREE_GEN_VALUES);

   // - rb_tree __replace_delete_node_by_child method -

   // - rb_tree __remove_black_black method -
RB_TREE___REMOVE_BLACK_BLACK(RB_TREE_GEN_VALUES);

   // - rb_tree __remove_one_child method -

   // - rb_tree __insert_operation method -
RB_TREE___INSERT_OPERATION(RB_TREE_GEN_VALUES);

   // - rb_tree init method -

   // - rb_tree init_buffer method -

   // - rb_tree clear method -
   if (TYPE_NUMBERS(0) & c_type_dynamic) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
RB_TREE_CLEAR(RB_TREE_GEN_VALUES);
      }
   }

   // - rb_tree set_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer && TYPE_NUMBERS(0) & c_type_dynamic) {
RB_TREE_SET_BUFFER(RB_TREE_GEN_VALUES);
   }

   // - rb_tree flush method -

   // - rb_tree flush_all method -
   if (TYPE_NUMBERS(0) & c_type_flushable) {
RB_TREE_FLUSH_ALL(RB_TREE_GEN_VALUES);
   }

   // - rb_tree swap method -

   // - rb_tree operator[] method -

   // - rb_tree insert method -

   // - rb_tree swap_insert method -

   // - rb_tree unique_insert method -

   // - rb_tree unique_swap_insert method -

   // - rb_tree remove method -
RB_TREE_REMOVE(RB_TREE_GEN_VALUES);

   // - rb_tree copy_resize method -
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
RB_TREE_COPY_RESIZE(RB_TREE_GEN_VALUES);
   }

   // - rb_tree get_idx method -
RB_TREE_GET_IDX(RB_TREE_GEN_VALUES);

   // - rb_tree get_idx_left method -
RB_TREE_GET_IDX_LEFT(RB_TREE_GEN_VALUES);

   // - rb_tree get_gre_idx method -
RB_TREE_GET_GRE_IDX(RB_TREE_GEN_VALUES);

   // - rb_tree get_lee_idx method -
RB_TREE_GET_LEE_IDX(RB_TREE_GEN_VALUES);

   // - rb_tree get_idxs method -
RB_TREE_GET_IDXS(RB_TREE_GEN_VALUES);

   // - rb_tree operator= method -
   if (TYPE_NUMBERS(0) & c_type_dynamic) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
RB_TREE_OPERATOR_EQUAL(RB_TREE_GEN_VALUES);
      }
   }

   // - rb_tree operator== method -
RB_TREE_OPERATOR_DOUBLE_EQUAL(RB_TREE_GEN_VALUES);

   // - rb_tree rehash_tree -
   if (STRUCT_NUMBER & c_type_option_rehash) {
RB_TREE_REHASH_TREE(RB_TREE_GEN_VALUES);
   }

   // - rb_tree print_dot_code -
   if (STRUCT_NUMBER & c_type_option_print_dot_code) {
RB_TREE_PRINT_DOT_CODE(RB_TREE_GEN_VALUES);
   }

   // - rb_tree check_properties -
   if (STRUCT_NUMBER & c_type_option_check_properties) {
RB_TREE_CHECK_PROPERTIES(RB_TREE_GEN_VALUES);
   }

fprintf(out_file,
"// LCOV_EXCL_STOP\n"
"\n");
   }
}/*}}}*/


const unsigned c_ucl_max_param_types = 32;

// - ucl parameter types -
enum
{/*{{{*/
  c_test_class_ignore = 0,
  c_test_class_retrieve_integer,
  c_test_class_retrieve_float,
  c_test_class_retrieve_integer_init,
  c_test_class_retrieve_float_init,
  c_test_class_retrieve_data_buffer,
  c_test_class_type,
};/*}}}*/

// - ucl parameter options -
enum
{/*{{{*/
  c_option_method = 0,
  c_option_class,
  c_option_static_method,
  c_option_macro,
  c_option_ignore,
  c_option_retrieve_integer,
  c_option_retrieve_float,
  c_option_retrieve_integer_init,
  c_option_retrieve_float_init,
  c_option_retrieve_data_buffer,
};/*}}}*/

unsigned recognize_ucl_params_option(char *source_string)
{/*{{{*/
#define GET_NEXT_UCL_PARAMS_CHAR() \
{\
   in_char = (unsigned char)source_string[input_idx];\
}

#define CLOSE_UCL_PARAMS_CHAR(RET_TERM_IDX) \
{\
   if (in_char == '\0') {\
      return RET_TERM_IDX;\
   }\
\
   input_idx++;\
}

   unsigned input_idx = 0;
   unsigned char in_char;

// - STATE 0 -
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 99)
      goto state_1_label;

   if (in_char == 105)
      goto state_2_label;

   if (in_char == 109)
      goto state_3_label;

   if (in_char == 114)
      goto state_4_label;

   if (in_char == 115)
      goto state_5_label;

   return c_idx_not_exist;

// - STATE 1 -
state_1_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 108)
      goto state_6_label;

   return c_idx_not_exist;

// - STATE 2 -
state_2_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 103)
      goto state_7_label;

   return c_idx_not_exist;

// - STATE 3 -
state_3_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 97)
      goto state_8_label;

   if (in_char == 101)
      goto state_9_label;

   return c_idx_not_exist;

// - STATE 4 -
state_4_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 101)
      goto state_10_label;

   return c_idx_not_exist;

// - STATE 5 -
state_5_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 116)
      goto state_11_label;

   return c_idx_not_exist;

// - STATE 6 -
state_6_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 97)
      goto state_12_label;

   return c_idx_not_exist;

// - STATE 7 -
state_7_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 110)
      goto state_13_label;

   return c_idx_not_exist;

// - STATE 8 -
state_8_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 99)
      goto state_14_label;

   return c_idx_not_exist;

// - STATE 9 -
state_9_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 116)
      goto state_15_label;

   return c_idx_not_exist;

// - STATE 10 -
state_10_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 116)
      goto state_16_label;

   return c_idx_not_exist;

// - STATE 11 -
state_11_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 97)
      goto state_17_label;

   return c_idx_not_exist;

// - STATE 12 -
state_12_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 115)
      goto state_18_label;

   return c_idx_not_exist;

// - STATE 13 -
state_13_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 111)
      goto state_19_label;

   return c_idx_not_exist;

// - STATE 14 -
state_14_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 114)
      goto state_20_label;

   return c_idx_not_exist;

// - STATE 15 -
state_15_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 104)
      goto state_21_label;

   return c_idx_not_exist;

// - STATE 16 -
state_16_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 114)
      goto state_22_label;

   return c_idx_not_exist;

// - STATE 17 -
state_17_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 116)
      goto state_23_label;

   return c_idx_not_exist;

// - STATE 18 -
state_18_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 115)
      goto state_24_label;

   return c_idx_not_exist;

// - STATE 19 -
state_19_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 114)
      goto state_25_label;

   return c_idx_not_exist;

// - STATE 20 -
state_20_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 111)
      goto state_26_label;

   return c_idx_not_exist;

// - STATE 21 -
state_21_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 111)
      goto state_27_label;

   return c_idx_not_exist;

// - STATE 22 -
state_22_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 105)
      goto state_28_label;

   return c_idx_not_exist;

// - STATE 23 -
state_23_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 105)
      goto state_29_label;

   return c_idx_not_exist;

// - STATE 24 -
state_24_label:
   CLOSE_UCL_PARAMS_CHAR(1);
   return 1;

// - STATE 25 -
state_25_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 101)
      goto state_30_label;

   return c_idx_not_exist;

// - STATE 26 -
state_26_label:
   CLOSE_UCL_PARAMS_CHAR(3);
   return 3;

// - STATE 27 -
state_27_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 100)
      goto state_31_label;

   return c_idx_not_exist;

// - STATE 28 -
state_28_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 101)
      goto state_32_label;

   return c_idx_not_exist;

// - STATE 29 -
state_29_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 99)
      goto state_33_label;

   return c_idx_not_exist;

// - STATE 30 -
state_30_label:
   CLOSE_UCL_PARAMS_CHAR(4);
   return 4;

// - STATE 31 -
state_31_label:
   CLOSE_UCL_PARAMS_CHAR(0);
   return 0;

// - STATE 32 -
state_32_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 118)
      goto state_34_label;

   return c_idx_not_exist;

// - STATE 33 -
state_33_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 95)
      goto state_35_label;

   return c_idx_not_exist;

// - STATE 34 -
state_34_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 101)
      goto state_36_label;

   return c_idx_not_exist;

// - STATE 35 -
state_35_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 109)
      goto state_37_label;

   return c_idx_not_exist;

// - STATE 36 -
state_36_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 95)
      goto state_38_label;

   return c_idx_not_exist;

// - STATE 37 -
state_37_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 101)
      goto state_39_label;

   return c_idx_not_exist;

// - STATE 38 -
state_38_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 100)
      goto state_40_label;

   if (in_char == 102)
      goto state_41_label;

   if (in_char == 105)
      goto state_42_label;

   return c_idx_not_exist;

// - STATE 39 -
state_39_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 116)
      goto state_43_label;

   return c_idx_not_exist;

// - STATE 40 -
state_40_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 97)
      goto state_44_label;

   return c_idx_not_exist;

// - STATE 41 -
state_41_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 108)
      goto state_45_label;

   return c_idx_not_exist;

// - STATE 42 -
state_42_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 110)
      goto state_46_label;

   return c_idx_not_exist;

// - STATE 43 -
state_43_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 104)
      goto state_47_label;

   return c_idx_not_exist;

// - STATE 44 -
state_44_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 116)
      goto state_48_label;

   return c_idx_not_exist;

// - STATE 45 -
state_45_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 111)
      goto state_49_label;

   return c_idx_not_exist;

// - STATE 46 -
state_46_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 116)
      goto state_50_label;

   return c_idx_not_exist;

// - STATE 47 -
state_47_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 111)
      goto state_51_label;

   return c_idx_not_exist;

// - STATE 48 -
state_48_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 97)
      goto state_52_label;

   return c_idx_not_exist;

// - STATE 49 -
state_49_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 97)
      goto state_53_label;

   return c_idx_not_exist;

// - STATE 50 -
state_50_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 101)
      goto state_54_label;

   return c_idx_not_exist;

// - STATE 51 -
state_51_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 100)
      goto state_55_label;

   return c_idx_not_exist;

// - STATE 52 -
state_52_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 95)
      goto state_56_label;

   return c_idx_not_exist;

// - STATE 53 -
state_53_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 116)
      goto state_57_label;

   return c_idx_not_exist;

// - STATE 54 -
state_54_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 103)
      goto state_58_label;

   return c_idx_not_exist;

// - STATE 55 -
state_55_label:
   CLOSE_UCL_PARAMS_CHAR(2);
   return 2;

// - STATE 56 -
state_56_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 98)
      goto state_59_label;

   return c_idx_not_exist;

// - STATE 57 -
state_57_label:
   CLOSE_UCL_PARAMS_CHAR(6);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 95)
      goto state_60_label;

   return 6;

// - STATE 58 -
state_58_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 101)
      goto state_61_label;

   return c_idx_not_exist;

// - STATE 59 -
state_59_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 117)
      goto state_62_label;

   return c_idx_not_exist;

// - STATE 60 -
state_60_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 105)
      goto state_63_label;

   return c_idx_not_exist;

// - STATE 61 -
state_61_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 114)
      goto state_64_label;

   return c_idx_not_exist;

// - STATE 62 -
state_62_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 102)
      goto state_65_label;

   return c_idx_not_exist;

// - STATE 63 -
state_63_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 110)
      goto state_66_label;

   return c_idx_not_exist;

// - STATE 64 -
state_64_label:
   CLOSE_UCL_PARAMS_CHAR(5);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 95)
      goto state_67_label;

   return 5;

// - STATE 65 -
state_65_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 102)
      goto state_68_label;

   return c_idx_not_exist;

// - STATE 66 -
state_66_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 105)
      goto state_69_label;

   return c_idx_not_exist;

// - STATE 67 -
state_67_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 105)
      goto state_70_label;

   return c_idx_not_exist;

// - STATE 68 -
state_68_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 101)
      goto state_71_label;

   return c_idx_not_exist;

// - STATE 69 -
state_69_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 116)
      goto state_72_label;

   return c_idx_not_exist;

// - STATE 70 -
state_70_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 110)
      goto state_73_label;

   return c_idx_not_exist;

// - STATE 71 -
state_71_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 114)
      goto state_74_label;

   return c_idx_not_exist;

// - STATE 72 -
state_72_label:
   CLOSE_UCL_PARAMS_CHAR(8);
   return 8;

// - STATE 73 -
state_73_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 105)
      goto state_75_label;

   return c_idx_not_exist;

// - STATE 74 -
state_74_label:
   CLOSE_UCL_PARAMS_CHAR(9);
   return 9;

// - STATE 75 -
state_75_label:
   CLOSE_UCL_PARAMS_CHAR(c_idx_not_exist);
   GET_NEXT_UCL_PARAMS_CHAR();

   if (in_char == 116)
      goto state_76_label;

   return c_idx_not_exist;

// - STATE 76 -
state_76_label:
   CLOSE_UCL_PARAMS_CHAR(7);
   return 7;

}/*}}}*/

void processor_s::generate_ucl_params()
{/*{{{*/
  string_array_s &names = cont_params.types;
  string_array_s &types = cont_params.variables;
  string_array_s &additions = cont_params.functions;
  string_array_s &props = cont_params.names;

  if (names.used != types.used)
  {
    fprintf(stderr,"ucl_params: different count of variable names and types\n");
    cassert(0);
  }

  if (types.used > c_ucl_max_param_types)
  {
    fprintf(stderr,"ucl_params: maximal count of parameter types (%u) exceeded\n",c_ucl_max_param_types);
    cassert(0);
  }

  string_s *method_name = nullptr;
  string_s *class_name = nullptr;
  bool static_method = false;
  bool macro = false;
  const char *line_end = "\n";

  // - process parameters properties -
  if (props.used != 0)
  {
    string_s *p_ptr = props.data;
    string_s *p_ptr_end = p_ptr + props.used;
    do {
      unsigned option_idx = recognize_ucl_params_option(p_ptr->data);
      switch (option_idx)
      {
        case c_option_method:
        case c_option_class:
          if (++p_ptr >= p_ptr_end)
          {
            fprintf(stderr,"ucl_params: missing value of property %s\n",(p_ptr - 1)->data);
            cassert(0);
          }

          switch (option_idx)
          {
          case c_option_method:
            method_name = p_ptr;
            break;
          case c_option_class:
            class_name = p_ptr;
            break;
          }
          break;
        case c_option_static_method:
          static_method = true;
          break;
        case c_option_macro:
          macro = true;
          line_end = "\\\n";
          break;
        default:
          fprintf(stderr,"ucl_params: unrecognized propery: \"%s\"\n",p_ptr->data);
          cassert(0);
      }
    } while(++p_ptr < p_ptr_end);
  }

  unsigned param_count = 0;
  unsigned test_count = 0;
  bool retrieve_params = false;

  unsigned type_test_classes[c_ucl_max_param_types];
  unsigned map_type_param[c_ucl_max_param_types];
  unsigned param_test_counts[c_ucl_max_param_types];
  unsigned map_test_type[c_ucl_max_param_types];

  // - process parameters -
  if (types.used != 0)
  {
    unsigned type_idx = 0;
    unsigned param_idx = 0;
    do {
      string_s &type = types[type_idx];
      string_s &name = names[type_idx];
      unsigned &type_test_class = type_test_classes[type_idx];

      // - recognize type test class -
      switch (recognize_ucl_params_option(type.data))
      {
        case c_option_ignore:
          type_test_class = c_test_class_ignore;
          break;
        case c_option_retrieve_integer:
          type_test_class = c_test_class_retrieve_integer;
          retrieve_params = true;
          break;
        case c_option_retrieve_float:
          type_test_class = c_test_class_retrieve_float;
          retrieve_params = true;
          break;
        case c_option_retrieve_integer_init:
          type_test_class = c_test_class_retrieve_integer_init;
          retrieve_params = true;
          break;
        case c_option_retrieve_float_init:
          type_test_class = c_test_class_retrieve_float_init;
          retrieve_params = true;
          break;
        case c_option_retrieve_data_buffer:
          type_test_class = c_test_class_retrieve_data_buffer;
          retrieve_params = true;
          break;
        default:
          type_test_class = c_test_class_type;
      }

      // - process new parameter -
      unsigned name_idx = names.get_idx(name);
      if (name_idx == type_idx)
      {
        param_idx = param_count++;
        param_test_counts[param_idx] = 0;
      }
      else
      {
        if (map_type_param[name_idx] != param_idx)
        {
          fprintf(stderr,"ucl_params: parameter name \"%s\" out of order\n",name.data);
          cassert(0);
        }
      }

      // - update type to parameter map -
      map_type_param[type_idx] = param_idx;

      // - process new test -
      if (type_test_class != c_test_class_ignore)
      {
        // - update test to type map -
        map_test_type[test_count++] = type_idx;

        ++param_test_counts[param_idx];
      }
    } while(++type_idx < types.used);
  }

  if (gen_options & c_option_gen_code &&
     (include_level == 0 || gen_options & c_option_gen_includes))
  {
  // - generate uclang parameters code -

  // - retrieve destination for non static methods -
  if (!static_method)
  {
fprintf(out_file,
"  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);"
);
  }

  // - retrieve source locations -
  if (param_count != 0)
  {
    unsigned p_idx = 0;
    do {
fprintf(out_file,
"%s  location_s *src_%d_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_%d_op_idx]);"
,(static_method && p_idx == 0) ? "" : line_end,p_idx,p_idx);
    } while(++p_idx < param_count);
  }

  if (test_count > 0)
  {
    fprintf(out_file,"%s",line_end);

    // - declare retrieve variables -
    if (retrieve_params)
    {
      unsigned t_idx = 0;
      do {
        switch (type_test_classes[t_idx])
        {
        case c_test_class_retrieve_integer:
          fprintf(out_file,"%s  long long int %s;",line_end,names[t_idx].data);
          break;
        case c_test_class_retrieve_float:
          fprintf(out_file,"%s  double %s;",line_end,names[t_idx].data);
          break;
        case c_test_class_retrieve_integer_init:
          fprintf(out_file,"%s  long long int %s = 0;",line_end,names[t_idx].data);
          break;
        case c_test_class_retrieve_float_init:
          fprintf(out_file,"%s  double %s = 0.0;",line_end,names[t_idx].data);
          break;
        case c_test_class_retrieve_data_buffer:
          fprintf(out_file,
            "%s  const void *%s_ptr;"
            "%s  unsigned %s_size;",
          line_end,names[t_idx].data,line_end,names[t_idx].data);
          break;
        }
      } while(++t_idx < types.used);

      fprintf(out_file,"%s",line_end);
    }

   if (additions.used != 0)
   {
      unsigned f_idx = 0;
      do {
fprintf(out_file,
"%s  %s"
,line_end,additions[f_idx].data);
      } while(++f_idx < additions.used);

      fprintf(out_file,"%s",line_end);
   }

fprintf(out_file,
"%s  %s"
,line_end,macro ? "/* - ERROR - */" : "// - ERROR -");

    fprintf(out_file,"%s  if (",line_end);

    unsigned test_idx = 0;
    unsigned param_test_idx = 0;
    do {
      unsigned type_idx = map_test_type[test_idx];
      unsigned param_idx = map_type_param[type_idx];
      unsigned param_test_count = param_test_counts[param_idx];

      // - more than one test for parameter -
      if (param_test_count > 1)
      {
        fprintf(out_file,"%c",param_test_idx == 0 ? '(' : ' ');
      }

      switch (type_test_classes[type_idx])
      {
      case c_test_class_retrieve_integer:
      case c_test_class_retrieve_integer_init:
        fprintf(out_file,"!it.retrieve_integer(src_%u_location,%s)",param_idx,names[type_idx].data);
        break;
      case c_test_class_retrieve_float:
      case c_test_class_retrieve_float_init:
        fprintf(out_file,"!it.retrieve_float(src_%u_location,%s)",param_idx,names[type_idx].data);
        break;
      case c_test_class_retrieve_data_buffer:
        fprintf(out_file,"!it.retrieve_data_buffer(src_%u_location,%s_ptr,%s_size)",
            param_idx,names[type_idx].data,names[type_idx].data);
        break;
      case c_test_class_type:
        fprintf(out_file,"src_%u_location->v_type != %s",param_idx,types[type_idx].data);
        break;
      default:
        fprintf(stderr,"ucl_params: unrecognized test class %s\n",types[type_idx].data);
        cassert(0);
      }

      // - all parameter tests processed -
      if (++param_test_idx >= param_test_count)
      {
        // - more than one test of parameter -
        if (param_test_count > 1)
        {
          fprintf(out_file,")");
        }

        // - some remaining tests exist -
        if (++test_idx < test_count)
        {
          fprintf(out_file," ||");
        }
        else
        {
          break;
        }

        // - reset parameter test index -
        param_test_idx = 0;
      }
      else
      {
        // - next parameter test index -
        ++test_idx;
        fprintf(out_file," &&");
      }

      fprintf(out_file,"%s      ",line_end);
    } while(true);

fprintf(out_file,
")"
"%s  {"
,line_end);

fprintf(out_file,
"%s    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);"
,line_end);

    // - ERROR -
    if (method_name == nullptr)
    {
      fprintf(stderr,"ucl_params: missing method name value\n");
      cassert(0);
    }

    if (static_method)
    {
      // - ERROR -
      if (class_name == nullptr)
      {
        fprintf(stderr,"ucl_params: missing class name value\n");
        cassert(0);
      }

      if (macro)
      {
fprintf(out_file,
"%s    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,%s,%s);"
,line_end,class_name->data,method_name->data);
      }
      else
      {
fprintf(out_file,
"%s    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,%s,\"%s#%u\");"
,line_end,class_name->data,method_name->data,param_count);
      }
    }
    else
    {
      if (macro)
      {
fprintf(out_file,
"%s    BIC_EXCEPTION_PUSH_METHOD_RI(%s);"
,line_end,method_name->data);
      }
      else
      {
fprintf(out_file,
"%s    BIC_EXCEPTION_PUSH_METHOD_RI(\"%s#%u\");"
,line_end,method_name->data,param_count);
      }
    }

fprintf(out_file,
"%s    new_exception->params.push(%u);"
,line_end,param_count);

    unsigned param_idx = 0;
    do {
fprintf(out_file,
"%s    new_exception->params.push(src_%u_location->v_type);"
,line_end,param_idx);
    } while(++param_idx < param_count);

fprintf(out_file,
"%s"
"%s    return false;"
,line_end,line_end);

fprintf(out_file,
"%s  }"
,line_end);
  }
  }
}/*}}}*/



void processor_s::generate_type_inlines(unsigned a_length,char *a_data)
{/*{{{*/
   unsigned abb_idx = abbreviations.get_idx_by_name(a_length,a_data);

   if (abb_idx == c_idx_not_exist) {
      char tmp_char = a_data[a_length];
      a_data[a_length] = '\0';
      fprintf(stderr,"ERROR: Unknown type abbreviation: \"%s\" while generating inline methods.\n",a_data);
      a_data[a_length] = tmp_char;

      cassert(0);
   }

   unsigned data_type_idx = abbreviations[abb_idx].data_type_idx;

   switch (data_types[data_type_idx].cont_idx) {
   case c_cont_array:
      generate_array_inlines(abb_idx,data_type_idx);
      break;
   case c_cont_queue:
      generate_queue_inlines(abb_idx,data_type_idx);
      break;
   case c_cont_list:
      generate_list_inlines(abb_idx,data_type_idx);
      break;
   case c_cont_struct:
      generate_struct_inlines(abb_idx,data_type_idx);
      break;
   case c_cont_rb_tree:
      generate_rb_tree_inlines(abb_idx,data_type_idx);
      break;
   case c_cont_safe_list:
      generate_list_inlines(abb_idx,data_type_idx);
      break;
   case c_cont_safe_rb_tree:
      generate_rb_tree_inlines(abb_idx,data_type_idx);
      break;
   default:
      cassert(0);
   }
}/*}}}*/

void processor_s::generate_type_methods(unsigned a_length,char *a_data)
{/*{{{*/
   unsigned abb_idx = abbreviations.get_idx_by_name(a_length,a_data);

   if (abb_idx == c_idx_not_exist) {
      char tmp_char = a_data[a_length];
      a_data[a_length] = '\0';
      fprintf(stderr,"ERROR: Unknown type abbreviation: \"%s\" while generating methods.\n",a_data);
      a_data[a_length] = tmp_char;

      cassert(0);
   }

   unsigned data_type_idx = abbreviations[abb_idx].data_type_idx;

   switch (data_types[data_type_idx].cont_idx) {
   case c_cont_array:
      generate_array_methods(abb_idx,data_type_idx);
      break;
   case c_cont_queue:
      generate_queue_methods(abb_idx,data_type_idx);
      break;
   case c_cont_list:
      generate_list_methods(abb_idx,data_type_idx);
      break;
   case c_cont_struct:
      generate_struct_methods(abb_idx,data_type_idx);
      break;
   case c_cont_rb_tree:
      generate_rb_tree_methods(abb_idx,data_type_idx);
      break;
   case c_cont_safe_list:
      generate_list_methods(abb_idx,data_type_idx);
      break;
   case c_cont_safe_rb_tree:
      generate_rb_tree_methods(abb_idx,data_type_idx);
      break;
   default:
      cassert(0);
   }
}/*}}}*/

void processor_s::generate_container_def(string_s &a_cont_name)
{/*{{{*/
   unsigned idx = 0;
   do {
      if (a_cont_name.compare_char_ptr(strlen(c_cont_names[idx]),(char *)c_cont_names[idx])) {
         break;
      }
   } while(++idx < c_cont_cnt);

   if (idx >= c_cont_cnt) {
      fprintf(stderr,"ERROR: container name \"%s\" is not defined\n",a_cont_name.data);
      cassert(0);
   }

   switch (idx) {
   case c_cont_array:
      generate_array_type();
      break;
   case c_cont_queue:
      generate_queue_type();
      break;
   case c_cont_list:
      generate_list_type();
      break;
   case c_cont_struct:
      generate_struct_type();
      break;
   case c_cont_rb_tree:
      generate_rb_tree_type();
      break;
   case c_cont_safe_list:
      type_settings |= c_type_option_safe;
      generate_list_type();
      break;
   case c_cont_safe_rb_tree:
      type_settings |= c_type_option_safe;
      generate_rb_tree_type();
      break;
   case c_gen_ucl_param:
      generate_ucl_params();
      break;
   default:
      cassert(0);
   }
}/*}}}*/

bool processor_s::find_include_file(const char *a_file, string_s &a_file_path)
{/*{{{*/
  if (include_dirs.used == 0)
  {
    return false;
  }

  // - complete file name -
  string_s file_path;
  file_path.init();

  string_s *d_ptr = include_dirs.data;
  string_s *d_ptr_end = d_ptr + include_dirs.used;
  do {
    
    // - if include directory is empty -
    if (d_ptr->size < 2)
    {
      file_path.set(strlen(a_file),a_file);
    }
    else
    {
      // - create complete file path -
#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
      file_path.setf(d_ptr->data[d_ptr->size - 2] == '/' ? "%s%s" : "%s/%s", d_ptr->data, a_file);
#elif SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
      file_path.setf(d_ptr->data[d_ptr->size - 2] == '\\' ? "%s%s" : "%s\\%s", d_ptr->data, a_file);
#else
      cassert(0);
#endif
    }

    // - brute file existence test -
    FILE *f = fopen(file_path.data,"rb");

    if (f != nullptr) {
      fclose(f);

      // - set target file path -
      a_file_path.swap(file_path);

      file_path.clear();
      return true;
    }

  } while(++d_ptr < d_ptr_end);

  file_path.clear();
  return false;
}/*}}}*/

void processor_s::initialize_data_types()
{/*{{{*/

   // - basic data types -
   data_types.used = 0;

   {
      unsigned idx = 0;
      do {
         data_types.push_blank();
         data_type_s &data_type = data_types.last();

         const char *c_basic_type = c_basic_types[idx];

         unsigned c_basic_type_length = strlen(c_basic_type);
         data_type.name.set(c_basic_type_length,(char *)c_basic_type);
         data_type.real_name.set(c_basic_type_length,(char *)c_basic_type);

         data_type.properties = c_basic_type_types[idx];
      } while(++idx < c_basic_type_cnt);
   }

   // - basic abbreviations -
   abbreviations.used = 0;

   {
      unsigned idx = 0;
      do {
         abbreviations.push_blank();
         abbreviation_s &abbreviation = abbreviations.last();

         const char *c_basic_abbreviation = c_basic_abbreviations[idx];
         abbreviation.name.set(strlen(c_basic_abbreviation),(char *)c_basic_abbreviation);
         abbreviation.data_type_idx = c_basic_abbreviation_types[idx];
      } while(++idx < c_basic_abbreviation_cnt);
   }
}/*}}}*/

bool processor_s::run(const char *a_file_name,string_array_s &a_include_dirs,FILE *a_file,unsigned a_gen_options)
{/*{{{*/
   out_file = a_file;
   gen_options = a_gen_options;
   include_level = 0;
   type_settings = 0;

   include_dirs.swap(a_include_dirs);
   include_dirs.push_blank();
   include_dirs.last().set(0,"");

   enable_stack.used = 0;
   enable_stack.push(1);

   // - not used any more -
#if 0
   if (gen_options & c_option_gen_code && gen_options & c_option_gen_includes)
   {
     fprintf(out_file,
"\n"
"typedef bool bb;\n"
"typedef char bc;\n"
"typedef unsigned char uc;\n"
"typedef short int si;\n"
"typedef unsigned short int usi;\n"
"typedef int bi;\n"
"typedef unsigned int ui;\n"
"typedef long int li;\n"
"typedef unsigned long uli;\n"
"typedef long long int lli;\n"
"typedef unsigned long long int ulli;\n"
"typedef float bf;\n"
"typedef double bd;\n"
"typedef long double ld;\n"
"\n"
"#define INIT_ARRAY \\\n"
".size = 0,\\\n"
".used = 0,\\\n"
".data = nullptr\n"
"\n"
"#define INIT_QUEUE \\\n"
".size = 0,\\\n"
".used = 0,\\\n"
".begin = 0,\\\n"
".data = nullptr\\\n"
"\n"
"#define INIT_LIST \\\n"
".size = 0,\\\n"
".used = 0,\\\n"
".data = nullptr,\\\n"
".free_idx = c_idx_not_exist,\\\n"
".first_idx = c_idx_not_exist,\\\n"
".last_idx = c_idx_not_exist\n"
"\n"
"#define INIT_RB_TREE \\\n"
".size = 0,\\\n"
".used = 0,\\\n"
".data = nullptr,\\\n"
".free_idx = c_idx_not_exist,\\\n"
".root_idx = c_idx_not_exist,\\\n"
".leaf_idx = c_idx_not_exist\n"
"\n"
"#define INIT_SAFE_LIST \\\n"
".size = 0,\\\n"
".used = 0,\\\n"
".count = 0,\\\n"
".data = nullptr,\\\n"
".free_idx = c_idx_not_exist,\\\n"
".first_idx = c_idx_not_exist,\\\n"
".last_idx = c_idx_not_exist\n"
"\n"
"#define INIT_SAFE_RB_TREE \\\n"
".size = 0,\\\n"
".used = 0,\\\n"
".count = 0,\\\n"
".data = nullptr,\\\n"
".free_idx = c_idx_not_exist,\\\n"
".root_idx = c_idx_not_exist,\\\n"
".leaf_idx = c_idx_not_exist\n"
"\n"
     );
   }
#endif

   process_s process;
   process.init();

   process.processor_ptr = this;
   if (!process.run_on(a_file_name)) {
      fprintf(stderr,"ERROR: Cannot process source file \"%s\".\n",a_file_name);
      return false;
   }
   
   process.clear();

   return true;
}/*}}}*/


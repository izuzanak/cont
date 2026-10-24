
#ifndef __BASE_H
#define __BASE_H

#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "stdint.h"
#include "string.h"
#include "assert.h"
#include "math.h"

#ifdef _MSC_VER
#if _MSC_VER < 1600
#define nullptr NULL
#endif
#else
#if __cplusplus < 201103
#define nullptr NULL
#endif
#endif

// - export of dynamically linked symbols -
#define EXPORT

// - red-black tree descent stack size -
#define RB_TREE_STACK_SIZE(VAR) (VAR).get_descent_stack_size()

// - functions used by generated code of containers -
#define debug_assert assert
#define cassert(A_COND)\
{\
  if (!(A_COND)) {\
    fprintf(stderr,"CASSERT: %s, line: %d, function: %s\n",__FILE__,__LINE__,__FUNCTION__);\
    fflush(stderr);\
    abort();\
  }\
}

inline void *cmalloc(size_t a_size)
{/*{{{*/

  // - ERROR -
  cassert(a_size <= UINT_MAX);

  void *location = malloc(a_size);

  // - ERROR -
  cassert(location != nullptr || a_size == 0);

  return location;
}/*}}}*/

inline void *cmalloc_array(size_t a_count,size_t a_size)
{/*{{{*/

  // - ERROR -
  cassert(a_size == 0 || a_count <= SIZE_MAX/a_size);

  return cmalloc(a_count*a_size);
}/*}}}*/

inline void *crealloc(void *a_location,size_t a_size)
{/*{{{*/

  // - ERROR -
  cassert(a_size <= UINT_MAX);

  void *location = realloc(a_location,a_size);

  // - ERROR -
  cassert(location != nullptr || a_size == 0);

  return location;
}/*}}}*/

inline void *crealloc_array(void *a_location,size_t a_count,size_t a_size)
{/*{{{*/

  // - ERROR -
  cassert(a_size == 0 || a_count <= SIZE_MAX/a_size);

  return crealloc(a_location,a_count*a_size);
}/*}}}*/

// - definition of cfree function -
inline void cfree(void *a_location)
{/*{{{*/
  free(a_location);
}/*}}}*/

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


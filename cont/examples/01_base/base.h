
#ifndef __BASE_H
#define __BASE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <stdint.h>

// - basic data types -
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

#define ENABLED 1

// - export of dynamically linked symbols -
#define EXPORT

// - red-black tree descent stack size -
#define RB_TREE_STACK_SIZE(TYPE,VALUE) TYPE ## _get_descent_stack_size(VALUE)

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

static inline void *cmalloc(size_t a_size)
{/*{{{*/

  // - ERROR -
  cassert(a_size <= UINT_MAX);

  void *location = malloc(a_size);

  // - ERROR -
  cassert(location != NULL || a_size == 0);

  return location;
}/*}}}*/

static inline void *crealloc(void *a_location,size_t a_size)
{/*{{{*/

  // - ERROR -
  cassert(a_size <= UINT_MAX);

  void *location = realloc(a_location,a_size);

  // - ERROR -
  cassert(location != NULL || a_size == 0);

  return location;
}/*}}}*/

static inline void cfree(void *a_location)
{/*{{{*/
  free(a_location);
}/*}}}*/

static inline void *cmalloc_array(size_t a_count,size_t a_size)
{/*{{{*/

  // - ERROR -
  cassert(a_size == 0 || a_count <= SIZE_MAX/a_size);

  return cmalloc(a_count*a_size);
}/*}}}*/

static inline void *crealloc_array(void *a_location,size_t a_count,size_t a_size)
{/*{{{*/

  // - ERROR -
  cassert(a_size == 0 || a_count <= SIZE_MAX/a_size);

  return crealloc(a_location,a_count*a_size);
}/*}}}*/

// - basic constants -
#define c_array_add 4
#define c_idx_not_exist UINT_MAX

// - logarithm of two (needed by red-black tree container) -
#define c_log_of_2 0.69314718055994530941

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

// - macros for automatic resource management -
#define CONT_INIT(TYPE,NAME) \
  TYPE NAME = {0};\
  TYPE ## _init(&(NAME));

#define CONT_CLEAR(TYPE,NAME) \
  __attribute__((cleanup(TYPE ## _clear))) TYPE NAME;

#define CONT_INIT_CLEAR(TYPE,NAME) \
  __attribute__((cleanup(TYPE ## _clear))) TYPE NAME = {0};\
  TYPE ## _init(&(NAME));

#endif


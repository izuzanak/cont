
#ifndef __BASE_H
#define __BASE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <limits.h>

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
#define cmalloc malloc
#define crealloc realloc
#define cfree free

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

#endif



#ifndef __BASIC_H
#define __BASIC_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"
#include "math.h"

#define ENABLED 1
#define OPTION_TO_STRING ENABLED

// - functions used by generated code of containers -
#define debug_assert assert
#define cassert assert
#define cmalloc malloc
#define crealloc realloc
#define cfree free

// - constants used by generated code of containers -
#define c_array_add 4
#define c_idx_not_exist 0xffffffff

// - logarithm of two (needed by red-black tree container) -
#define c_log_of_2 0.6931471805599453

// - pointer typedef -
typedef void * pointer;
@begin
define pointer basic
@end

/*
 * definition of generated structures
 */

// -- bc_array_s --
@begin
array<bc> bc_array_s;
@end

/*
 * definition of to_string methods for basic data types
 */

#if OPTION_TO_STRING == ENABLED
#define BASIC_TYPE_TO_STRING_DEFINE(TYPE) \
static inline void TYPE ## _to_string(TYPE *this,bc_array_s *a_trg);

BASIC_TYPE_TO_STRING_DEFINE(bc);
BASIC_TYPE_TO_STRING_DEFINE(si);
BASIC_TYPE_TO_STRING_DEFINE(usi);
BASIC_TYPE_TO_STRING_DEFINE(bi);
BASIC_TYPE_TO_STRING_DEFINE(ui);
BASIC_TYPE_TO_STRING_DEFINE(lli);
BASIC_TYPE_TO_STRING_DEFINE(bd);
BASIC_TYPE_TO_STRING_DEFINE(pointer);
#endif

/*
 * inline methods of generated structures
 */

// -- bc_array_s --
@begin
inlines bc_array_s
@end

/*
 * inline basic data types to_string methods
 */

#if OPTION_TO_STRING == ENABLED
#define BASIC_TYPE_TO_STRING_INLINE(TYPE,FORMAT) \
static inline void TYPE ## _to_string(TYPE *this,bc_array_s *a_trg)\
{/*{{{*/\
  int space = a_trg->size - a_trg->used;\
  int length = snprintf(a_trg->data + a_trg->used,space,FORMAT,*this);\
\
  if (length >= space)\
  {\
    bc_array_s_reserve(a_trg,length + 1);\
\
    space = a_trg->size - a_trg->used;\
    length = snprintf(a_trg->data + a_trg->used,space,FORMAT,*this);\
  }\
\
  a_trg->used += length;\
}/*}}}*/

BASIC_TYPE_TO_STRING_INLINE(bc,"%c");
BASIC_TYPE_TO_STRING_INLINE(si,"%hd");
BASIC_TYPE_TO_STRING_INLINE(usi,"%hu");
BASIC_TYPE_TO_STRING_INLINE(bi,"%d");
BASIC_TYPE_TO_STRING_INLINE(ui,"%u");
BASIC_TYPE_TO_STRING_INLINE(lli,"%lld");
BASIC_TYPE_TO_STRING_INLINE(bd,"%f");
BASIC_TYPE_TO_STRING_INLINE(pointer,"%p");
#endif

#endif


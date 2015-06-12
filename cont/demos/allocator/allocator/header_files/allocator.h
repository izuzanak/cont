
#ifndef __ALLOCATOR_H
#define __ALLOCATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <new>
#include <vector>

using namespace std;

/*
 * basic types and definitions
 */

#define debug_assert(A_COND)
//#define debug_assert(A_COND) cassert(A_COND)
#define cassert assert

//#define USE_MEM_FROM_CHUNK

#ifdef USE_MEM_FROM_CHUNK
#define cmalloc(A_SIZE) allocator_ptr->malloc(A_SIZE)
#define cfree(A_ADDR) allocator_ptr->free(A_ADDR)
#else
#define cmalloc(A_SIZE) malloc(A_SIZE)
#define cfree(A_ADDR) free(A_ADDR)
#endif

// - basic constants -
const unsigned c_array_add = 4; // 64
const unsigned c_idx_not_exist = UINT_MAX;

const unsigned c_alloc_allign_to = 4;
const unsigned c_alloc_allign_to_mo = c_alloc_allign_to - 1;

// - logarithm of two (needed by red-black tree container) -
const float c_log_of_2 = logf(2.0f);

// - pointer typedef -
typedef void * pointer;
@begin
define pointer basic
@end

// - global allocator pointer -
struct allocator_s;
extern allocator_s *allocator_ptr;

/*
 * definition of generated structures
 */

// -- ui_array_s --
@begin
array<unsigned> ui_array_s;
@end

// -- ui_arrays_s --
@begin
array<ui_array_s> ui_arrays_s;
@end

// -- block_s --
@begin
struct
<
pointer:addr
unsigned:size
bool:free
unsigned:tree_idx
>
block_s;
@end

// -- block_list_s --
@begin
safe_list<block_s> block_list_s
additions
{
  void safe_copy_resize(unsigned a_size);
};
@end

// -- free_tree_s --
@begin
rb_tree<unsigned
pointer:list_ptr
>
additions
{
  inline int compare_eqgr_size(unsigned int &a_size, unsigned int &a_second);
  unsigned get_eqgr_size_idx(unsigned a_value);
  void safe_copy_resize(unsigned a_size);
}
free_tree_s;
@end

// -- alloc_tree_s --
@begin
rb_tree<unsigned
  pointer:list_ptr
>
additions
{
  inline int compare_addr(pointer &a_addr, unsigned int &a_second);
  unsigned get_addr_idx(pointer a_addr);
  void safe_copy_resize(unsigned a_size);
}
alloc_tree_s;
@end

// -- mem_info_s --
@begin
struct
<
unsigned:total_size
unsigned:free_size
unsigned:used_size
unsigned:total_block_cnt
unsigned:free_block_cnt
unsigned:used_block_cnt
>
additions
{
  void DEBUG_print(FILE *out_f);
}
mem_info_s;
@end

// -- allocator_s --
@begin
struct
<
block_list_s:block_list
free_tree_s:free_tree
alloc_tree_s:alloc_tree
bool:resizing
>
additions
{
  void create(pointer a_mem_addr,unsigned a_mem_size,unsigned a_block_cnt);
  void destroy();
  pointer malloc(unsigned a_size);
  void free(pointer a_addr);
  unsigned size(pointer a_addr);
  void get_info(mem_info_s &a_info);

  void DEBUG_dump(FILE *out_f);
  void DEBUG_check();
}
allocator_s;
@end

/*
 * inline methods of generated structures
 */

// -- ui_array_s --
@begin
inlines ui_array_s
@end

// -- ui_arrays_s --
@begin
inlines ui_arrays_s
@end

// -- block_s --
@begin
inlines block_s
@end

// -- block_list_s --
@begin
inlines block_list_s
@end

// -- free_tree_s --
@begin
inlines free_tree_s
@end

inline int free_tree_s::__compare_value(unsigned int &a_first, unsigned int &a_second)
{/*{{{*/
  block_list_s &block_list = *((block_list_s *)list_ptr);

  unsigned f_size = block_list[a_first].size;
  unsigned s_size = block_list[a_second].size;

  return f_size < s_size ? -1 : f_size > s_size ? 1 : 0;
}/*}}}*/

inline int free_tree_s::compare_eqgr_size(unsigned int &a_size, unsigned int &a_second)
{/*{{{*/
  block_list_s &block_list = *((block_list_s *)list_ptr);

  unsigned s_size = block_list[a_second].size;

  return a_size < s_size ? -1 : a_size > s_size ? 1 : 0;
}/*}}}*/

// -- alloc_tree_s --
@begin
inlines alloc_tree_s
@end

inline int alloc_tree_s::__compare_value(unsigned int &a_first, unsigned int &a_second)
{/*{{{*/
  block_list_s &block_list = *((block_list_s *)list_ptr);

  pointer fir_addr = block_list[a_first].addr;
  pointer sec_addr = block_list[a_second].addr;

  return fir_addr < sec_addr ? -1 : fir_addr > sec_addr ? 1 : 0;
}/*}}}*/

inline int alloc_tree_s::compare_addr(pointer &a_addr, unsigned int &a_second)
{/*{{{*/
  block_list_s &block_list = *((block_list_s *)list_ptr);

  pointer sec_addr = block_list[a_second].addr;

  return a_addr < sec_addr ? -1 : a_addr > sec_addr ? 1 : 0;
}/*}}}*/

// -- mem_info_s --
@begin
inlines mem_info_s
@end

// -- allocator_s --
@begin
inlines allocator_s
@end

// - remap native new/delete hooks -
inline void *operator new(size_t a_size) throw(std::bad_alloc)
{
  return allocator_ptr->malloc(a_size);
}

inline void operator delete(void *a_addr) throw(std::bad_alloc)
{
  allocator_ptr->free(a_addr);
}

#endif


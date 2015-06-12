
@begin
include "allocator.h"
@end

// - global allocator pointer -
allocator_s *allocator_ptr = NULL;

/*
 * methods of generated structures
 */

// -- ui_array_s --
@begin
methods ui_array_s
@end

// -- ui_arrays_s --
@begin
methods ui_arrays_s
@end

// -- block_s --
@begin
methods block_s
@end

// -- block_list_s --
@begin
methods block_list_s
@end

void block_list_s::safe_copy_resize(unsigned a_size)
{/*{{{*/
   debug_assert(a_size >= used);

   block_list_s_element *n_data;

   if (a_size == 0) {
      n_data = NULL;
   }
   else {
      n_data = (block_list_s_element *)cmalloc(a_size*sizeof(block_list_s_element));
   }

   if (used != 0) {
      memcpy(n_data,data,used*sizeof(block_list_s_element));
   }

   block_list_s_element *rm_data = size != 0 ? data : NULL;

   data = n_data;
   size = a_size;

   if (rm_data) {
      cfree(rm_data);
   }
}/*}}}*/

// -- free_tree_s --
@begin
methods free_tree_s
@end

unsigned free_tree_s::get_eqgr_size_idx(unsigned a_size)
{/*{{{*/
   if (root_idx == c_idx_not_exist)
   {
      return c_idx_not_exist;
   }

   unsigned good_idx = c_idx_not_exist;
   unsigned node_idx = root_idx;
   do {
      free_tree_s_node &node = data[node_idx];

      int comp_result = compare_eqgr_size(a_size,node.object);
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

void free_tree_s::safe_copy_resize(unsigned a_size)
{/*{{{*/
   debug_assert(a_size >= used);

   free_tree_s_node *n_data;

   if (a_size == 0) {
      n_data = NULL;
   }
   else {
      n_data = (free_tree_s_node *)cmalloc(a_size*sizeof(free_tree_s_node));
   }

   if (used != 0) {
      memcpy(n_data,data,used*sizeof(free_tree_s_node));
   }

   free_tree_s_node *rm_data = size != 0 ? data : NULL;

   data = n_data;
   size = a_size;

   if (rm_data) {
      cfree(rm_data);
   }
}/*}}}*/

// -- alloc_tree_s --
@begin
methods alloc_tree_s
@end

unsigned alloc_tree_s::get_addr_idx(pointer a_addr)
{/*{{{*/
   if (root_idx == c_idx_not_exist) {
      return c_idx_not_exist;
   }

   unsigned node_idx = root_idx;
   do {
      alloc_tree_s_node &node = data[node_idx];

      int comp_result = compare_addr(a_addr,node.object);
      if (comp_result < 0) {
         node_idx = node.left_idx;
      }
      else {
         if (comp_result == 0) {
            return node_idx;
         }

         node_idx = node.right_idx;
      }
   } while(node_idx != leaf_idx);

   return c_idx_not_exist;
}/*}}}*/

void alloc_tree_s::safe_copy_resize(unsigned a_size)
{/*{{{*/
   debug_assert(a_size >= used);

   alloc_tree_s_node *n_data;

   if (a_size == 0) {
      n_data = NULL;
   }
   else {
      n_data = (alloc_tree_s_node *)cmalloc(a_size*sizeof(alloc_tree_s_node));
   }

   if (used != 0) {
      memcpy(n_data,data,used*sizeof(alloc_tree_s_node));
   }

   alloc_tree_s_node *rm_data = size != 0 ? data : NULL;

   data = n_data;
   size = a_size;

   if (rm_data) {
      cfree(rm_data);
   }
}/*}}}*/

// -- mem_info_s --
@begin
methods mem_info_s
@end

void mem_info_s::DEBUG_print(FILE *out_f)
{/*{{{*/
  fprintf(out_f,
"Total size: %u\n"
"Free size:  %u\n"
"Used size:  %u\n"
"\n"
"Total block count: %u\n"
"Free block count:  %u\n"
"Used block count:  %u\n"
"\n"
  ,total_size
  ,free_size
  ,used_size
  ,total_block_cnt
  ,free_block_cnt
  ,used_block_cnt);
}/*}}}*/

// -- allocator_s --
@begin
methods allocator_s
@end

void allocator_s::create(pointer a_mem_addr,unsigned a_mem_size,unsigned a_block_cnt)
{/*{{{*/
  clear();

  // - reset resizing flag -
  resizing = false;

  // - initialize block list pointers -
  free_tree.list_ptr = &block_list;
  alloc_tree.list_ptr = &block_list;

  // - byte memory pointer -
  char *mem_addr = (char *)a_mem_addr;

#ifdef USE_MEM_FROM_CHUNK
  {
    // - initialize block list -
    pointer block_list_addr = mem_addr;
    unsigned block_list_size = a_block_cnt*sizeof(block_list_s_element);

    block_list.data = (block_list_s_element *)block_list_addr;
    block_list.size = a_block_cnt;

    mem_addr += block_list_size;
    a_mem_size -= block_list_size;

    // - initialize free tree -
    pointer free_tree_addr = mem_addr;
    unsigned free_tree_size = a_block_cnt*sizeof(free_tree_s_node);

    free_tree.data = (free_tree_s_node *)free_tree_addr;
    free_tree.size = a_block_cnt;

    mem_addr += free_tree_size;
    a_mem_size -= free_tree_size;

    // - initialize alloc tree -
    pointer alloc_tree_addr = mem_addr;
    unsigned alloc_tree_size = a_block_cnt*sizeof(alloc_tree_s_node);

    alloc_tree.data = (alloc_tree_s_node *)alloc_tree_addr;
    alloc_tree.size = a_block_cnt;

    mem_addr += alloc_tree_size;
    a_mem_size -= alloc_tree_size;

    // - register allocated memory blocks -
    block_s bl_block = {block_list_addr,block_list_size,0,0};
    unsigned bl_block_idx = block_list.append(bl_block);
    block_list[bl_block_idx].tree_idx = alloc_tree.insert(bl_block_idx);

    block_s ft_block = {free_tree_addr,free_tree_size,0,0};
    unsigned ft_block_idx = block_list.append(ft_block);
    block_list[ft_block_idx].tree_idx = alloc_tree.insert(ft_block_idx);

    block_s at_block = {alloc_tree_addr,alloc_tree_size,0,0};
    unsigned at_block_idx = block_list.append(at_block);
    block_list[at_block_idx].tree_idx = alloc_tree.insert(at_block_idx);
  }
#else
  block_list.copy_resize(a_block_cnt);
  free_tree.copy_resize(a_block_cnt);
  alloc_tree.copy_resize(a_block_cnt);
#endif

  // - register free memory block -
  block_s block = {mem_addr,a_mem_size,1,0};
  unsigned block_idx = block_list.append(block);
  block_list[block_idx].tree_idx = free_tree.insert(block_idx);
}/*}}}*/

void allocator_s::destroy()
{/*{{{*/

  // - destroy block list -
  block_list.data = NULL;
  block_list.size = 0;

  // - destroy free tree -
  free_tree.data = NULL;
  free_tree.size = 0;

  // - destroy alloc tree -
  alloc_tree.data = NULL;
  alloc_tree.size = 0;

}/*}}}*/

pointer allocator_s::malloc(unsigned a_size)
{/*{{{*/

#ifdef USE_MEM_FROM_CHUNK
  // - resize block list and trees if needed -
  if (!resizing && block_list.used + 3 >= block_list.size)
  {
    unsigned new_size = (block_list.size << 1) + c_array_add;

    resizing = true;
    block_list.safe_copy_resize(new_size);
    free_tree.safe_copy_resize(new_size);
    alloc_tree.safe_copy_resize(new_size);
    resizing = false;
  }
#endif

  // - allign allocated memory size -
  unsigned alloc_size = (a_size + c_alloc_allign_to_mo) & ~c_alloc_allign_to_mo;

  // - retrieve smallest fitting block -
  unsigned free_tree_idx = free_tree.get_eqgr_size_idx(alloc_size);

  // - ERROR -
  if (free_tree_idx == c_idx_not_exist)
  {
    throw std::bad_alloc();
  }

  unsigned fb_idx = free_tree[free_tree_idx];
  block_s *fb_ptr = &block_list[fb_idx];

  // - remove block from free tree -
  free_tree.remove(free_tree_idx);

  if (fb_ptr->size > alloc_size)
  {
    // - create second block -
    block_s sb = {(char *)fb_ptr->addr + alloc_size,fb_ptr->size - alloc_size,1,0};
    unsigned sb_idx = block_list.insert_after(fb_idx,sb);

    // - update first block pointer -
    fb_ptr = &block_list[fb_idx];

    // - insert second block to free tree -
    block_list[sb_idx].tree_idx = free_tree.insert(sb_idx);

    // - adjust first block size -
    fb_ptr->size = alloc_size;
  }

  debug_assert(fb_ptr->size == alloc_size);

  // - adjust first block free flag -
  fb_ptr->free = false;

  // - insert first block to alloc tree -
  fb_ptr->tree_idx = alloc_tree.insert(fb_idx);

  return fb_ptr->addr;
}/*}}}*/

void allocator_s::free(pointer a_addr)
{/*{{{*/
  unsigned alloc_tree_idx = alloc_tree.get_addr_idx(a_addr);

  // - ERROR -
  if (alloc_tree_idx == c_idx_not_exist)
  {
    throw std::bad_alloc();
  }

  unsigned block_idx = alloc_tree[alloc_tree_idx];
  block_list_s_element &block_elm = block_list.data[block_idx];

  // - remove block from alloc tree -
  alloc_tree.remove(alloc_tree_idx);

  // - append to previous free block - 
  if (block_elm.prev_idx != c_idx_not_exist)
  {
    block_s &prev_block = block_list[block_elm.prev_idx];

    if (prev_block.free)
    {
      block_elm.object.addr = prev_block.addr;
      block_elm.object.size += prev_block.size;

      free_tree.remove(prev_block.tree_idx);
      block_list.remove(block_elm.prev_idx);
    }
  }

  // - append to next free block - 
  if (block_elm.next_idx != c_idx_not_exist)
  {
    block_s &next_block = block_list[block_elm.next_idx];

    if (next_block.free)
    {
      block_elm.object.size += next_block.size;

      free_tree.remove(next_block.tree_idx);
      block_list.remove(block_elm.next_idx);
    }
  }

  // - update block free flag -
  block_elm.object.free = true;

  // - insert block to free tree -
  block_elm.object.tree_idx = free_tree.insert(block_idx);
}/*}}}*/

unsigned allocator_s::size(pointer a_addr)
{/*{{{*/
  unsigned alloc_tree_idx = alloc_tree.get_addr_idx(a_addr);

  // - ERROR -
  if (alloc_tree_idx == c_idx_not_exist)
  {
    throw std::bad_alloc();
  }

  return block_list[alloc_tree[alloc_tree_idx]].size;
}/*}}}*/

void allocator_s::get_info(mem_info_s &a_info)
{/*{{{*/

  // - reset info structure -
  a_info.total_size = 0;
  a_info.free_size = 0;
  a_info.used_size = 0;
  a_info.total_block_cnt = block_list.count;
  a_info.free_block_cnt = 0;
  a_info.used_block_cnt = 0;

  // - check blocks continuity -
  if (block_list.first_idx != c_idx_not_exist)
  {
    unsigned idx = block_list.first_idx;
    do {
      block_s &block = block_list[idx];

      a_info.total_size += block.size;

      if (block.free)
      {
        a_info.free_size += block.size;
        ++a_info.free_block_cnt;
      }
      else
      {
        a_info.used_size += block.size;
        ++a_info.used_block_cnt;
      }

      idx = block_list.next_idx(idx);
    } while(idx != c_idx_not_exist);
  }
}/*}}}*/

void allocator_s::DEBUG_dump(FILE *out_f)
{/*{{{*/
  
  if (block_list.first_idx != c_idx_not_exist)
  {
    unsigned idx = block_list.first_idx;
    do {
      block_s &block = block_list[idx];

      fprintf(out_f,"%4.4u - %p, %u, %s\n",idx,block.addr,block.size,block.free ? "free" : "alloc");
      idx = block_list.next_idx(idx);
    } while(idx != c_idx_not_exist);
  }

  if (free_tree.root_idx != c_idx_not_exist)
  {
    unsigned stack[free_tree.get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned idx = free_tree.get_stack_min_value_idx(free_tree.root_idx,&stack_ptr);
    do {
      block_s &block = block_list[free_tree[idx]];
      fprintf(out_f,"free %4.4u - %u\n",free_tree[idx],block.size);

      idx = free_tree.get_stack_next_idx(idx,&stack_ptr,stack);
    } while(idx != c_idx_not_exist);
  }

  if (alloc_tree.root_idx != c_idx_not_exist)
  {
    unsigned stack[alloc_tree.get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned idx = alloc_tree.get_stack_min_value_idx(alloc_tree.root_idx,&stack_ptr);
    do {
      fprintf(out_f,"alloc %4.4u\n",alloc_tree[idx]); 
      idx = alloc_tree.get_stack_next_idx(idx,&stack_ptr,stack);
    } while(idx != c_idx_not_exist);
  }
}/*}}}*/

void allocator_s::DEBUG_check()
{/*{{{*/

  // - check blocks continuity -
  if (block_list.first_idx != c_idx_not_exist)
  {
    char *address = (char *)block_list[block_list.first_idx].addr;
    unsigned idx = block_list.first_idx;
    do {
      block_s &block = block_list[idx];
      cassert(address == block.addr);

      address += block.size;

      idx = block_list.next_idx(idx);
    } while(idx != c_idx_not_exist);
  }

  // - check free tree structure -
  if (free_tree.root_idx != c_idx_not_exist)
  {
    unsigned stack[free_tree.get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned idx = free_tree.get_stack_min_value_idx(free_tree.root_idx,&stack_ptr);
    do {
      block_s &block = block_list[free_tree[idx]];
      if (block.tree_idx != idx || !block.free)
      {
        cassert(0);
      }

      idx = free_tree.get_stack_next_idx(idx,&stack_ptr,stack);
    } while(idx != c_idx_not_exist);
  }

  // - check alloc tree structure -
  if (alloc_tree.root_idx != c_idx_not_exist)
  {
    unsigned stack[alloc_tree.get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned idx = alloc_tree.get_stack_min_value_idx(alloc_tree.root_idx,&stack_ptr);
    do {
      block_s &block = block_list[alloc_tree[idx]];
      if (block.tree_idx != idx || block.free)
      {
        cassert(0);
      }

      idx = alloc_tree.get_stack_next_idx(idx,&stack_ptr,stack);
    } while(idx != c_idx_not_exist);
  }
}/*}}}*/

int main (int argc,char **argv)
{/*{{{*/
  unsigned mem_size = 5*1024*1024;
  void *mem_ptr = malloc(mem_size);

  allocator_s allocator;
  allocator_ptr = &allocator;

  allocator.init();
  allocator.create(mem_ptr,mem_size,128);
  allocator.DEBUG_dump(stderr);

  {
    mem_info_s mi;
    allocator.get_info(mi);
    mi.DEBUG_print(stderr);
  }

  {
    int c_idx = 0;
    do {
      vector<vector<int> > vecs;
      int v_idx = 0;
      do {
        vector<int> vec;
        int idx = 0;
        do {
          vec.push_back(idx);
        } while(++idx < 100);

        vecs.push_back(vec);
      } while(++v_idx < 5000);

      vecs.clear();
    } while(++c_idx < 10);
  }

  pointer mem0 = allocator.malloc(7);
  //pointer mem1 = allocator.malloc(8);
  //pointer mem2 = allocator.malloc(16);
  //pointer mem3 = allocator.malloc(16);
  //pointer mem4 = allocator.malloc(16);
  //pointer mem5 = allocator.malloc(16);
  
  allocator.free(mem0);
  //allocator.free(mem1);
  //allocator.free(mem2);
  //allocator.free(mem3);
  //allocator.free(mem4);
  //allocator.free(mem5);

  {
    mem_info_s mi;
    allocator.get_info(mi);
    mi.DEBUG_print(stderr);
  }

  allocator.DEBUG_dump(stderr);

#ifdef USE_MEM_FROM_CHUNK
  allocator.destroy();
#endif

  allocator.clear();

  free(mem_ptr);

  return 0;
}/*}}}*/


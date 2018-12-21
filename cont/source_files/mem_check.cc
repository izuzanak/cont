
@begin
   include "mem_check.h"
@end

/*
 * methods of generated structures
 */

// -- ui_array_s --
@begin
   methods ui_array_s
@end

#if MEM_CHECK == ENABLE

// -- mc_block_s --
@begin
   methods mc_block_s
@end

// -- mc_block_rb_tree_s --
@begin
   methods mc_block_rb_tree_s
@end

// -- mc_struct_s --
@begin
   methods mc_struct_s
@end

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


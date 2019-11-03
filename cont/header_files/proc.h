
#ifndef CONT_C_PROCESS_H
#define CONT_C_PROCESS_H

@begin
   include "basic.h"
   include "mem_check.h"
   include "ucl_string.h"
   include "processor.h"
@end

/*
 * definitions of generated structures
 */

// -- lalr_stack_element_s --
@begin
   struct
   <
   unsigned:lalr_state
   unsigned:terminal_start
   unsigned:terminal_end
   >
   lalr_stack_element_s;
@end

// -- lalr_stack_s --
@begin
   array<lalr_stack_element_s>
   
   additions {

   inline void push(unsigned a_lalr_state);
   inline void push(unsigned a_lalr_state,unsigned a_terminal_start,unsigned a_terminal_end);

   }
   
   lalr_stack_s;
@end

// -- process_s --
@begin
   struct
   <
   processor_s_ptr:processor_ptr
   string_s:source_string
   string_s:code
   lalr_stack_s:lalr_stack
   >

   additions {

   unsigned find_terminal(unsigned &a_input_idx);
   bool parse_code(string_s &a_code);
   bool run_on(const char *a_file_name);

   static void pa_reduce_null(process_s &proc);
   static void pa_reduce_include(process_s &proc);
   static void pa_reduce_inlines(process_s &proc);
   static void pa_reduce_methods(process_s &proc);
   static void pa_reduce_define(process_s &proc);
   static void pa_reduce_mod_basic(process_s &proc);
   static void pa_reduce_mod_static(process_s &proc);
   static void pa_reduce_mod_dynamic(process_s &proc);
   static void pa_reduce_mod_flushable(process_s &proc);
   static void pa_reduce_gen_container(process_s &proc);
   static void pa_reduce_type(process_s &proc);
   static void pa_reduce_type_and_name(process_s &proc);
   static void pa_reduce_option(process_s &proc);
   static void pa_reduce_additions_body(process_s &proc);
   static void pa_reduce_name(process_s &proc);

   }

   process_s;
@end

// - array of callback parse functions -
extern void(*parse_callbacks[])(process_s &proc);

/*
 * inline methods of generated structures
 */

// -- lalr_stack_element_s --
@begin
   inlines lalr_stack_element_s
@end

// -- lalr_stack_s --
@begin
   inlines lalr_stack_s
@end

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
@begin
   inlines process_s
@end

#endif


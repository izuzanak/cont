
#ifndef CONT_C_PROCESSOR_H
#define CONT_C_PROCESSOR_H

@begin
   include "basic.h"
   include "mem_check.h"
   include "ucl_string.h"
@end

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
#define VAR_NAME_LENGTHS(IDX) (data_type.variables[IDX].size - 1)

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
   c_type_option_nogen_init       = 0x100,
   c_type_option_nogen_clear      = 0x100 << 1,
   c_type_option_nogen_swap       = 0x100 << 2,
   c_type_option_nogen_copy       = 0x100 << 3,

   c_type_option_strict_dynamic   = 0x100 << 4,
   c_type_option_fixed_buffer     = 0x100 << 5,

   c_type_option_safe             = 0x100 << 6,
   c_type_option_rehash           = 0x100 << 7,
   c_type_option_print_dot_code   = 0x100 << 8,
   c_type_option_check_properties = 0x100 << 9,

   c_type_option_to_json          = 0x100 << 10,
   c_type_option_to_json_nice     = 0x100 << 11,
   c_type_option_from_var         = 0x100 << 12,
   c_type_option_from_json        = 0x100 << 13,
};

// - names of basic data types -
enum {
   c_bt_char = 0,
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

const unsigned c_basic_type_cnt = 14;
extern const char *c_basic_types[c_basic_type_cnt];

extern unsigned c_basic_type_types[c_basic_type_cnt];

// - abbreviations of basic data types -
const unsigned c_basic_abbreviation_cnt = 35;
extern const char *c_basic_abbreviations[c_basic_abbreviation_cnt];

extern const int c_basic_abbreviation_types[c_basic_abbreviation_cnt];

// - constant describing containers -
const unsigned c_cont_cnt = 7;

enum {
   c_cont_array = 0,
   c_cont_queue,
   c_cont_list,
   c_cont_struct,
   c_cont_rb_tree,
   c_cont_safe_list,
   c_cont_safe_rb_tree,
};

extern const char *c_cont_names[c_cont_cnt];
extern const char *c_cont_postfixes[c_cont_cnt];

/*
 * definitions of generated structures
 */

// -- data_type_s --
@begin
   struct
   <
   unsigned:cont_idx
   string_s:name
   string_s:real_name
   unsigned:properties
   string_array_s:types
   string_array_s:variables
   >
   data_type_s;
@end

// -- data_type_array_s --
@begin
   array<data_type_s> 
   
   additions {

   unsigned get_idx_by_real_name(unsigned n_length,char *n_data);

   }
   
   data_type_array_s;
@end

// -- abbreviation_s --
@begin
   struct
   <
   string_s:name
   unsigned:data_type_idx
   >
   abbreviation_s;
@end

// -- abbreviation_array_s --
@begin
   array<abbreviation_s> 

   additions {

   unsigned get_idx_by_name(unsigned a_length,const char *a_data);

   }
   
   abbreviation_array_s;
@end

// -- container_parameters_s --
@begin
   struct
   <
   string_array_s:types
   string_array_s:variables
   string_array_s:functions
   string_array_s:names
   >

   additions {
      inline void clean_out();
   }

   container_parameters_s;
@end

// -- processor_s --
@begin
   struct
   <
   FILE_ptr:out_file
   unsigned:gen_options
   unsigned:include_level
   string_array_s:include_dirs
   string_array_s:include_names
   data_type_array_s:data_types
   abbreviation_array_s:abbreviations
   unsigned:type_settings
   container_parameters_s:cont_params
   >

   additions {

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

   void generate_type_inlines(unsigned a_length,char *a_data);
   void generate_type_methods(unsigned a_length,char *a_data);
   void generate_container_def(string_s &a_cont_name);

   bool find_include_file(const char *a_file, string_s &a_file_path);

   void initialize_data_types();
   bool run(const char *a_file_name, string_array_s &a_include_dirs, 
            FILE *a_file,unsigned a_gen_options);

   }

   processor_s;
@end

// - processor_s_ptr definition -
typedef processor_s * processor_s_ptr;
@begin
   define processor_s_ptr basic
@end

/*
 * inline methods of generated structures
 */

// -- data_type_s --
@begin
   inlines data_type_s
@end

// -- data_type_array_s --
@begin
   inlines data_type_array_s
@end

// -- abbreviation_s --
@begin
   inlines abbreviation_s
@end

// -- abbreviation_array_s --
@begin
   inlines abbreviation_array_s
@end

// -- container_parameters_s --
@begin
   inlines container_parameters_s
@end

inline void container_parameters_s::clean_out()
{/*{{{*/
   types.used = 0;
   variables.used = 0;
   functions.used = 0;
   names.used = 0;
}/*}}}*/

// -- processor_s --
@begin
   inlines processor_s
@end

#endif


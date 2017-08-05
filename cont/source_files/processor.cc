
@begin
   include "processor.h"
   include "proc.h"
@end


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
};

const char *c_cont_postfixes[c_cont_cnt] = {
   "_a",
   "_q",
   "_l",
   "_s",
   "_rbt",
   "_sl",
   "_srbt",
};

/*
 * methods of generated structures
 */

// -- data_type_s --
@begin
   methods data_type_s
@end

// -- data_type_array_s --
@begin
   methods data_type_array_s
@end

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
@begin
   methods abbreviation_s
@end

// -- abbreviation_array_s --
@begin
   methods abbreviation_array_s
@end

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
@begin
   methods container_parameters_s
@end

// -- processor_s --
@begin
   methods processor_s
@end

@begin
   include "gen_array.cc"
   include "gen_queue.cc"
   include "gen_list.cc"
   include "gen_struct.cc"
   include "gen_rb_tree.cc"
   include "gen_safe_list.cc"
   include "gen_safe_rb_tree.cc"
@end

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
      generate_safe_list_inlines(abb_idx,data_type_idx);
      break;
   case c_cont_safe_rb_tree:
      generate_safe_rb_tree_inlines(abb_idx,data_type_idx);
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
      generate_safe_list_methods(abb_idx,data_type_idx);
      break;
   case c_cont_safe_rb_tree:
      generate_safe_rb_tree_methods(abb_idx,data_type_idx);
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
      generate_safe_list_type();
      break;
   case c_cont_safe_rb_tree:
      generate_safe_rb_tree_type();
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
      // - create comlete file path -
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

bool processor_s::run(const char *a_file_name,string_array_s &a_include_dirs,FILE *a_file)
{/*{{{*/
   out_file = a_file;
   type_settings = 0;

   include_dirs.swap(a_include_dirs);
   include_dirs.push_blank();
   include_dirs.last().set(0,"");

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


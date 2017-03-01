
#define ARRAY_GEN_PARAMS abbreviation_array_s &abbreviations,unsigned abb_idx,unsigned type_abb_idx,data_type_s &type
#define ARRAY_GEN_VALUES abbreviations,abb_idx,type_abb_idx,type

void ARRAY_INIT(ARRAY_GEN_PARAMS)
{/*{{{*/
printf(
"inline void %s::init()\n"
"{/*{{{*/\n"
"   size = 0;\n"
"   used = 0;\n"
"   data = NULL;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void ARRAY_INIT_SIZE(ARRAY_GEN_PARAMS)
{/*{{{*/
printf(
"inline void %s::init_size(unsigned a_size)\n"
"{/*{{{*/\n"
"   init();\n"
"   copy_resize(a_size);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void ARRAY_CLEAR(ARRAY_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_dynamic)) {
printf(
"inline void %s::clear()\n"
,IM_STRUCT_NAME);
   }
   else {
printf(
"void %s::clear()\n"
,IM_STRUCT_NAME);
   }
printf(
"{/*{{{*/\n"
"   if (data != NULL) {\n"
);
   if (TYPE_NUMBER & c_type_dynamic) {
printf(
"      %s *ptr = data;\n"
"      %s *ptr_end = ptr + size;\n"
"\n"
"      do {\n"
"         ptr->clear();\n"
"      } while(++ptr < ptr_end);\n"
"\n"
,TYPE_NAME,TYPE_NAME);
   }
printf(
"      cfree(data);\n"
"   }\n"
"\n"
"   init();\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_SET(ARRAY_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_dynamic)) {
printf(
"inline void %s::set(unsigned a_used,%s *a_data)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
printf(
"void %s::set(unsigned a_used,%s *a_data)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
printf(
"{/*{{{*/\n"
"   clear();\n"
"   if (a_used == 0) return;\n"
"   \n"
"   debug_assert(a_data != NULL);\n"
"   copy_resize(a_used);\n"
"\n"
);
   if (!(TYPE_NUMBER & c_type_dynamic)) {
printf(
"   memcpy(data,a_data,a_used*sizeof(%s));\n"
,TYPE_NAME);
   }
   else {
printf(
"   %s *ptr = data;\n"
"   %s *ptr_end = ptr + a_used;\n"
"   %s *a_ptr = a_data;\n"
"\n"
"   do {\n"
"      *ptr = *a_ptr;\n"
"   } while(++a_ptr,++ptr < ptr_end);\n"
"\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   }
printf(
"   used = a_used;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_FLUSH(ARRAY_GEN_PARAMS)
{/*{{{*/
printf(
"inline void %s::flush()\n"
"{/*{{{*/\n"
"   copy_resize(used);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void ARRAY_FLUSH_ALL(ARRAY_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_flushable)) {
printf(
"inline void %s::flush_all()\n"
,IM_STRUCT_NAME);
   }
   else {
printf(
"void %s::flush_all()\n"
,IM_STRUCT_NAME);
   }
printf(
"{/*{{{*/\n"
);
   if (TYPE_NUMBER & c_type_flushable) {
printf(
"   %s *ptr = data;\n"
"   %s *ptr_end = ptr + used;\n"
"\n"
"   do {\n"
"      ptr->flush_all();\n"
"   } while(++ptr < ptr_end);\n"
"\n"
,TYPE_NAME,TYPE_NAME);
   }
printf(
"   copy_resize(used);\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_SWAP(ARRAY_GEN_PARAMS)
{/*{{{*/
printf(
"inline void %s::swap(%s &a_second)\n"
"{/*{{{*/\n"
"   unsigned tmp_unsigned = size;\n"
"   size = a_second.size;\n"
"   a_second.size = tmp_unsigned;\n"
"\n"
"   tmp_unsigned = used;\n"
"   used = a_second.used;\n"
"   a_second.used = tmp_unsigned;\n"
"\n"
"   %s *tmp_data = data;\n"
"   data = a_second.data;\n"
"   a_second.data = tmp_data;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
}/*}}}*/

void ARRAY_OPERATOR_LE_BR_RE_BR(ARRAY_GEN_PARAMS)
{/*{{{*/
printf(
"inline %s &%s::operator[](unsigned a_idx)\n"
"{/*{{{*/\n"
"   debug_assert(a_idx < used);\n"
"   return data[a_idx];\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME,IM_STRUCT_NAME);
}/*}}}*/

void ARRAY_PUSH(ARRAY_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
printf(
"inline void %s::push(%s a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
printf(
"inline void %s::push(%s &a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
printf(
"{/*{{{*/\n"
"   if (used >= size) {\n"
"      copy_resize((size << 1) + c_array_add);\n"
"   }\n"
"\n"
"   data[used++] = a_value;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_PUSH_BLANK(ARRAY_GEN_PARAMS)
{/*{{{*/
printf(
"inline void %s::push_blank()\n"
"{/*{{{*/\n"
"   if (used >= size) {\n"
"      copy_resize((size << 1) + c_array_add);\n"
"   }\n"
"\n"
"   used++;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void ARRAY_RESERVE(ARRAY_GEN_PARAMS)
{/*{{{*/
printf(
"void %s::reserve(unsigned a_cnt)\n"
"{/*{{{*/\n"
"   unsigned required_cnt = used + a_cnt;\n"
"   if (required_cnt > size) {\n"
"      unsigned r_size = size;\n"
"      do {\n"
"         r_size = (r_size << 1) + c_array_add;\n"
"      } while(r_size < required_cnt);\n"
"\n"
"      copy_resize(r_size);\n"
"   }\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void ARRAY_PUSH_BLANKS(ARRAY_GEN_PARAMS)
{/*{{{*/
printf(
"void %s::push_blanks(unsigned a_cnt)\n"
"{/*{{{*/\n"
"   unsigned required_cnt = used + a_cnt;\n"
"   if (required_cnt > size) {\n"
"      unsigned r_size = size;\n"
"      do {\n"
"         r_size = (r_size << 1) + c_array_add;\n"
"      } while(r_size < required_cnt);\n"
"\n"
"      copy_resize(r_size);\n"
"   }\n"
"\n"
"   used += a_cnt;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void ARRAY_PUSH_CLEAR(ARRAY_GEN_PARAMS)
{/*{{{*/
printf(
"inline void %s::push_clear()\n"
"{/*{{{*/\n"
"   if (used >= size) {\n"
"      copy_resize((size << 1) + c_array_add);\n"
"   }\n"
"\n"
,IM_STRUCT_NAME);
   if (!(TYPE_NUMBER & c_type_dynamic)) {
printf(
"   used++;\n"
);
   }
   else {
printf(
"   data[used++].clear();\n"
);
   }
printf(
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_POP(ARRAY_GEN_PARAMS)
{/*{{{*/
printf(
"inline %s &%s::pop()\n"
"{/*{{{*/\n"
"   debug_assert(used > 0);\n"
"   return data[--used];\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME,IM_STRUCT_NAME);
}/*}}}*/

void ARRAY_LAST(ARRAY_GEN_PARAMS)
{/*{{{*/
printf(
"inline %s &%s::last()\n"
"{/*{{{*/\n"
"   debug_assert(used > 0);\n"
"   return data[used - 1];\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME,IM_STRUCT_NAME);
}/*}}}*/

void ARRAY_COPY_RESIZE(ARRAY_GEN_PARAMS)
{/*{{{*/
if (TYPE_NUMBER & c_type_option_strict_dynamic)
{/*{{{*/
printf(
"void %s::copy_resize(unsigned a_size)\n"
"{/*{{{*/\n"
"   debug_assert(a_size >= used);\n"
"\n"
"   %s *n_data;\n"
"\n"
"   if (a_size == 0) {\n"
"      n_data = NULL;\n"
"   }\n"
"   else {\n"
"      n_data = (%s *)cmalloc(a_size*sizeof(%s));\n"
,IM_STRUCT_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);
printf(
"\n"
"      %s *ptr = n_data;\n"
"      %s *ptr_end = n_data + a_size;\n"
"\n"
"      do {\n"
"         ptr->init();\n"
"      } while(++ptr < ptr_end);\n"
"   }\n"
"\n"
,TYPE_NAME,TYPE_NAME);
printf(
"   if (used > 0) {\n"
"      %s *ptr = data;\n"
"      %s *ptr_end = ptr + used;\n"
"      %s *n_ptr = n_data;\n"
"\n"
"      do {\n"
"         n_ptr->swap(*ptr);\n"
"      } while(++n_ptr,++ptr < ptr_end);\n"
"   }\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME);
printf(
"\n"
"   if (size > used) {\n"
"      %s *ptr = data + used;\n"
"      %s *ptr_end = data + size;\n"
"\n"
"      do {\n"
"         ptr->clear();\n"
"      } while(++ptr < ptr_end);\n"
"   }\n"
"\n"
"   if (size != 0) {\n"
"      cfree(data);\n"
"   }\n"
"\n"
"   data = n_data;\n"
"   size = a_size;\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME,TYPE_NAME);
}/*}}}*/
else
{/*{{{*/
printf(
"void %s::copy_resize(unsigned a_size)\n"
"{/*{{{*/\n"
"   debug_assert(a_size >= used);\n"
,IM_STRUCT_NAME);
   if (TYPE_NUMBER & c_type_dynamic) {
printf(
"\n"
"   if (size > a_size) {\n"
"      %s *ptr = data + a_size;\n"
"      %s *ptr_end = data + size;\n"
"\n"
"      do {\n"
"         ptr->clear();\n"
"      } while(++ptr < ptr_end);\n"
"   }\n"
,TYPE_NAME,TYPE_NAME);
   }
printf(
"\n"
"   if (a_size == 0) {\n"
"      if (data != NULL) {\n"
"         cfree(data);\n"
"      }\n"
"      data = NULL;\n"
"   }\n"
"   else {\n"
"      data = (%s *)crealloc(data,a_size*sizeof(%s));\n"
"   }\n"
,TYPE_NAME,TYPE_NAME);
   if (TYPE_NUMBER & c_type_dynamic) {
printf(
"\n"
"   if (a_size > size) {\n"
"      %s *ptr = data + size;\n"
"      %s *ptr_end = data + a_size;\n"
"\n"
"      do {\n"
"         ptr->init();\n"
"      } while(++ptr < ptr_end);\n"
"   }\n"
,TYPE_NAME,TYPE_NAME);
   }
printf(
"\n"
"   size = a_size;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/
}/*}}}*/

void ARRAY_FILL(ARRAY_GEN_PARAMS,unsigned type_idx)
{/*{{{*/
   if (type_idx == c_bt_bool || type_idx == c_bt_char || type_idx == c_bt_unsigned_char){
printf(
"inline void %s::fill(%s a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
      if (TYPE_NUMBER & c_type_basic) {
printf(
"void %s::fill(%s a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
      }
      else {
printf(
"void %s::fill(%s &a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
      }
   }
printf(
"{/*{{{*/\n"
"   if (size == 0) return;\n"
"\n"
);
   if (type_idx == c_bt_bool || type_idx == c_bt_char || type_idx == c_bt_unsigned_char) {
printf(
"   memset(data,a_value,size);\n"
);
   }
   else {
printf(
"   %s *ptr = data;\n"
"   %s *ptr_end = data + size;\n"
"\n"
"   do {\n"
"      *ptr = a_value;\n"
"   } while(++ptr < ptr_end);\n"
,TYPE_NAME,TYPE_NAME);
   }
printf(
"\n"
"   used = size;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_GET_IDX(ARRAY_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
printf(
"unsigned %s::get_idx(%s a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
printf(
"unsigned %s::get_idx(%s &a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
printf(
"{/*{{{*/\n"
"   if (used == 0) return c_idx_not_exist;\n"
"\n"
"   %s *ptr = data;\n"
"   %s *ptr_end = data + used;\n"
"\n"
"   do {\n"
"      if (*ptr == a_value) {\n"
"         return ptr - data;\n"
"      }\n"
"   } while(++ptr < ptr_end);\n"
"\n"
"   return c_idx_not_exist;\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME,TYPE_NAME);
}/*}}}*/

void ARRAY_OPERATOR_EQUAL(ARRAY_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_dynamic)) {
printf(
"inline %s &%s::operator=(%s &a_src)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
   else {
printf(
"%s &%s::operator=(%s &a_src)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
printf(
"{/*{{{*/\n"
"   clear();\n"
"\n"
"   if (a_src.used == 0) return *this;\n"
"\n"
"   copy_resize(a_src.used);\n"
);
   if (!(TYPE_NUMBER & c_type_dynamic)) {
printf(
"   memcpy(data,a_src.data,a_src.used*sizeof(%s));\n"
,TYPE_NAME);
   }
   else {
printf(
"\n"
"   %s *ptr = data;\n"
"   %s *s_ptr = a_src.data;\n"
"   %s *s_ptr_end = s_ptr + a_src.used;\n"
"\n"
"   do {\n"
"      *ptr = *s_ptr;\n"
"   } while(++ptr,++s_ptr < s_ptr_end);\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   }
printf(
"\n"
"   used = a_src.used;\n"
"   return *this;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_OPERATOR_DOUBLE_EQUAL(ARRAY_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_dynamic)) {
printf(
"inline bool %s::operator==(%s &a_second)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
   else {
printf(
"bool %s::operator==(%s &a_second)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
printf(
"{/*{{{*/\n"
"   if (used != a_second.used) return false;\n"
"   if (used == 0) return true;\n"
);
   if (!(TYPE_NUMBER & c_type_dynamic)) {
printf(
"\n"
"   return (memcmp(data,a_second.data,used*sizeof(%s)) == 0);\n"
,TYPE_NAME);
   }
   else {
printf(
"\n"
"   %s *ptr = data;\n"
"   %s *ptr_end = ptr + used;\n"
"   %s *s_ptr = a_second.data;\n"
"\n"
"   do {\n"
"      if (!(*ptr == *s_ptr)) {\n"
"         return false;\n"
"      }\n"
"   } while(++s_ptr,++ptr < ptr_end);\n"
"\n"
"   return true;\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   }
printf(
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void processor_s::generate_array_type()
{/*{{{*/
   string_array_s &type_names = cont_params.types;
   string_array_s &fun_defs = cont_params.functions;
   string_array_s &abbs = cont_params.names;

   if (type_names.used != 1) {
      fprintf(stderr,"array: not given name (or too many names) of contained type\n");
      cassert(0);
   }

   if (abbs.used < 1) {
      fprintf(stderr,"array: not given name of generated structure\n");
      cassert(0);
   }

   unsigned type_abb_idx = abbreviations.get_idx_by_name(type_names[0].size - 1,type_names[0].data);
   if (type_abb_idx == c_idx_not_exist) {
      fprintf(stderr,"array: contained type \"%s\" does not exist\n",type_names[0].data);
      cassert(0);
   }

   unsigned type_idx = abbreviations[type_abb_idx].data_type_idx;
   data_type_s &type = data_types[type_idx];

   // - test type options -
   if (type.properties & c_type_option_strict_dynamic) {
      cassert(type.properties & c_type_dynamic);
   }

   string_s real_name;
   real_name.init();
   real_name.conc_set(type.name.size - 1,type.name.data,strlen(c_cont_postfixes[c_cont_array]),(char *)c_cont_postfixes[c_cont_array]);

   string_s &data_type_name = abbs[0];

   unsigned data_type_idx;

   if ((data_type_idx = abbreviations.get_idx_by_name(data_type_name.size - 1,data_type_name.data)) == c_idx_not_exist) {

      unsigned d_idx = data_types.get_idx_by_real_name(real_name.size - 1,real_name.data);
      if (d_idx != c_idx_not_exist) {
         fprintf(stderr,"DUPLICATE STRUCTURES: %s <-> %s\n",data_type_name.data,data_types[d_idx].name.data);
      }

      data_types.push_blank();
      data_type_s &data_type = data_types.last();

      data_type.cont_idx = c_cont_array;
      data_type.name.set(data_type_name.size - 1,data_type_name.data);
      data_type.real_name.swap(real_name);

      data_type.properties = c_type_dynamic | c_type_flushable | (type_settings & c_type_option_mask);

      data_type.types.push(abbreviations[type_abb_idx].name);

      data_type_idx = data_types.used - 1;
   }
   else {
      fprintf(stderr,"array: name of generated structure \"%s\" is already used\n",data_type_name.data);
      cassert(0);
   }

   real_name.clear();

   // - check and write abbreviations -
   if (abbs.used != 0) {
      unsigned idx = 0;
      do {
         string_s &abb = abbs[idx];

         if (abbreviations.get_idx_by_name(abb.size - 1,abb.data) != c_idx_not_exist) {
            fprintf(stderr,"array: abreviated name \"%s\" for generated structure is already used\n",abb.data);
            cassert(0);
         }

         abbreviations.push_blank();
         abbreviations.last().set(abb,data_type_idx);
      } while(++idx < abbs.used);
   }

   data_type_s &data_type = data_types[data_type_idx];

   // --- definition of structure array ---

printf(
"// --- struct %s definition --- \n"
"\n"
,STRUCT_NAME);

   if (abbs.used > 1) {
      unsigned idx = 1;
      do {
printf(
"typedef struct %s %s;\n"
,abbs[0].data,abbs[idx].data);
      } while(++idx < abbs.used);
printf(
"\n"
);
   }

printf(
"/*!\n"
" * \\brief __GEN array of type %s\n"
" */\n"
"struct %s\n"
"{\n"
"   unsigned size; //!< actual size of allocated space in array\n"
"   unsigned used; //!< count of used space in array\n"
"   %s *data; //!< pointer to array elements\n"
"\n"
,TYPE_NAME,STRUCT_NAME,TYPE_NAME);
   if (!(data_type.properties & c_type_option_nogen_init)) {
printf(
"   /*!\n"
"    * \\brief __GEN initialize array\n"
"    */\n"
"   inline void init();\n"
"\n"
);
   }
printf(
"   /*!\n"
"    * \\brief __GEN initialize array of requested size\n"
"    * \\param a_size - requested size of array\n"
"    */\n"
"   inline void init_size(unsigned a_size);\n"
"\n"
);
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(data_type.properties & c_type_option_nogen_clear)) {
printf(
"   /*!\n"
"    * \\brief __GEN release memory used by array\n"
"    */\n"
"   inline void clear();\n"
"\n"
);
      }
printf(
"   /*!\n"
"    * \\brief __GEN set array content from element pointer\n"
"    * \\param a_used - number of elements stored at pointed location\n"
"    * \\param a_data - pointer to elements\n"
"    */\n"
"   inline void set(unsigned a_used,%s *a_data);\n"
"\n"
,TYPE_NAME);
   }
   else {
      if (!(data_type.properties & c_type_option_nogen_clear)) {
printf(
"   /*!\n"
"    * \\brief __GEN release memory used by array\n"
"    */\n"
"   void clear();\n"
"\n"
);
      }
printf(
"   /*!\n"
"    * \\brief __GEN set array content from element pointer\n"
"    * \\param a_used - number of elements stored at pointed location\n"
"    * \\param a_data - pointer to elements\n"
"    */\n"
"   void set(unsigned a_used,%s *a_data);\n"
"\n"
,TYPE_NAME);
   }
printf(
"   /*!\n"
"    * \\brief __GEN flush array memory usage\n"
"    */\n"
"   inline void flush();\n"
"\n"
);
   if (!(TYPE_NUMBER & c_type_flushable)) {
printf(
"   /*!\n"
"    * \\brief __GEN flush array memory usage, recursive on elemenets\n"
"    */\n"
"   inline void flush_all();\n"
"\n"
);
   }
   else {
printf(
"   /*!\n"
"    * \\brief __GEN flush array memory usage, recursive on elemenets\n"
"    */\n"
"   void flush_all();\n"
"\n"
);
   }
   if (!(data_type.properties & c_type_option_nogen_swap)) {
printf(
"   /*!\n"
"    * \\brief __GEN swap array members with another array\n"
"    * \\param a_second - reference to another array\n"
"    */\n"
"   inline void swap(%s &a_second);\n"
"\n"
,STRUCT_NAME);
   }
printf(
"   /*!\n"
"    * \\brief __GEN select element of array\n"
"    * \\param a_idx - index of element in array\n"
"    * \\return reference to element of array\n"
"    */\n"
"   inline %s &operator[](unsigned a_idx);\n"
"\n"
,TYPE_NAME);
   if (TYPE_NUMBER & c_type_basic) {
printf(
"   /*!\n"
"    * \\brief __GEN insert element to end of array\n"
"    * \\param a_value - value of inserted element\n"
"    */\n"
"   inline void push(%s a_value);\n"
"\n"
,TYPE_NAME);
   }
   else {
printf(
"   /*!\n"
"    * \\brief __GEN insert element to end of array\n"
"    * \\param a_value - reference to inserted value\n"
"    */\n"
"   inline void push(%s &a_value);\n"
"\n"
,TYPE_NAME);
   }
printf(
"   /*!\n"
"    * \\brief __GEN insert blank element to end of array\n"
"    */\n"
"   inline void push_blank();\n"
"\n"
"   /*!\n"
"    * \\brief __GEN reserve requested count of elements at end of array\n"
"    * \\param a_cnt - count of elements to be reserved\n"
"    */\n"
"   void reserve(unsigned a_cnt);\n"
"\n"
"   /*!\n"
"    * \\brief __GEN insert blank elements to end of array\n"
"    * \\param a_cnt - count of elements inserted to array\n"
"    */\n"
"   void push_blanks(unsigned a_cnt);\n"
"\n"
"   /*!\n"
"    * \\brief __GEN insert and clear element to end of array\n"
"    */\n"
"   inline void push_clear();\n"
"\n"
"   /*!\n"
"    * \\brief __GEN return value of last element in array, and remove it\n"
"    * \\return reference to last element\n"
"    */\n"
"   inline %s &pop();\n"
"\n"
"   /*!\n"
"    * \\brief __GEN return value of last element in array\n"
"    * \\return reference to last element\n"
"    */\n"
"   inline %s &last();\n"
"\n"
"   /*!\n"
"    * \\brief __GEN change array capacity\n"
"    * \\param a_size - requested array capacity\n"
"    */\n"
"   void copy_resize(unsigned a_size);\n"
"\n"
,TYPE_NAME,TYPE_NAME);
   if (type_idx == c_bt_bool || type_idx == c_bt_char || type_idx == c_bt_unsigned_char) {
printf(
"   /*!\n"
"    * \\brief __GEN set all elements of array to given value\n"
"    * \\param a_value - new value of all elements\n"
"    */\n"
"   inline void fill(%s a_value);\n"
"\n"
,TYPE_NAME);
   }
   else {
      if (TYPE_NUMBER & c_type_basic) {
printf(
"   /*!\n"
"    * \\brief __GEN set all elements of array to given value\n"
"    * \\param a_value - new value of all elements\n"
"    */\n"
"   void fill(%s a_value);\n"
"\n"
,TYPE_NAME);
      }
      else {
printf(
"   /*!\n"
"    * \\brief __GEN set all elements of array to given value\n"
"    * \\param a_value - new value of all elements\n"
"    */\n"
"   void fill(%s &a_value);\n"
"\n"
,TYPE_NAME);
      }
   }
   if (TYPE_NUMBER & c_type_basic) {
printf(
"   /*!\n"
"    * \\brief __GEN search for index of element\n"
"    * \\param a_value - value which index is searched\n"
"    */\n"
"   unsigned get_idx(%s a_value);\n"
"\n"
,TYPE_NAME);
   }
   else {
printf(
"   /*!\n"
"    * \\brief __GEN search for index of element\n"
"    * \\param a_value - value which index is searched\n"
"    */\n"
"   unsigned get_idx(%s &a_value);\n"
"\n"
,TYPE_NAME);
   }
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(data_type.properties & c_type_option_nogen_copy)) {
printf(
"   /*!\n"
"    * \\brief __GEN copy array from another array\n"
"    * \\param a_src - reference to another array\n"
"    * \\return reference to this array\n"
"    */\n"
"   inline %s &operator=(%s &a_src);\n"
"\n"
,STRUCT_NAME,STRUCT_NAME);
      }
printf(
"   /*!\n"
"    * \\brief __GEN comparison of array with another array\n"
"    * \\param a_second - reference to another array\n"
"    * \\return result of comparison\n"
"    */\n"
"   inline bool operator==(%s &a_second);\n"
"\n"
,STRUCT_NAME);
   }
   else {
      if (!(data_type.properties & c_type_option_nogen_copy)) {
printf(
"   /*!\n"
"    * \\brief __GEN copy array from another array\n"
"    * \\param a_src - reference to another array\n"
"    */\n"
"   %s &operator=(%s &a_src);\n"
"\n"
,STRUCT_NAME,STRUCT_NAME);
      }
printf(
"   /*!\n"
"    * \\brief __GEN comparison of array with another array\n"
"    * \\param a_second - reference to another array\n"
"    */\n"
"   bool operator==(%s &a_second);\n"
"\n"
,STRUCT_NAME);
   }
   if (fun_defs.used != 0) {
      unsigned f_idx = 0;
      do {
printf(
"   %s\n"
,fun_defs[f_idx].data);
      } while(++f_idx < fun_defs.used);
   }
printf(
"};\n"
"\n"
);
}/*}}}*/

void processor_s::generate_array_inlines(unsigned abb_idx,unsigned a_dt_idx)
{/*{{{*/
   data_type_s &data_type = data_types[a_dt_idx];

   string_s &type_abb_string = data_type.types[0];
   unsigned type_abb_idx = abbreviations.get_idx_by_name(type_abb_string.size - 1,type_abb_string.data);

   if (type_abb_idx == c_idx_not_exist) {
      fprintf(stderr,"array: inlines: abbreviated type name \"%s\" does not exist\n",type_abb_string.data);
      cassert(0);
   }

   unsigned type_idx = abbreviations[type_abb_idx].data_type_idx;
   data_type_s &type = data_types[type_idx];

   // --- definition of inline methods ---

printf(
"// --- struct %s inline method definition ---\n"
"\n"
,IM_STRUCT_NAME);

   // - array init method -
   if (!(data_type.properties & c_type_option_nogen_init)) {
ARRAY_INIT(ARRAY_GEN_VALUES);
   }

   // - array init_size method -
ARRAY_INIT_SIZE(ARRAY_GEN_VALUES);

   // - array clear method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(data_type.properties & c_type_option_nogen_clear)) {
ARRAY_CLEAR(ARRAY_GEN_VALUES);
      }
   }

   // - array set method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
ARRAY_SET(ARRAY_GEN_VALUES);
   }

   // - array_flush_method -
ARRAY_FLUSH(ARRAY_GEN_VALUES);

   // - array flush_all method -
   if (!(TYPE_NUMBER & c_type_flushable)) {
ARRAY_FLUSH_ALL(ARRAY_GEN_VALUES);
   }

   // - array swap method -
   if (!(data_type.properties & c_type_option_nogen_swap)) {
ARRAY_SWAP(ARRAY_GEN_VALUES);
   }

   // - array operator[] method -
ARRAY_OPERATOR_LE_BR_RE_BR(ARRAY_GEN_VALUES);

   // - array push method -
ARRAY_PUSH(ARRAY_GEN_VALUES);

   // - array push_blank method -
ARRAY_PUSH_BLANK(ARRAY_GEN_VALUES);

   // - array reserve method -

   // - array push_blanks method -

   // - array push_clear method -
ARRAY_PUSH_CLEAR(ARRAY_GEN_VALUES);

   // - array pop method -
ARRAY_POP(ARRAY_GEN_VALUES);

   // - array last method -
ARRAY_LAST(ARRAY_GEN_VALUES);

   // - array copy_resize method -

   // - array fill method -
   if (type_idx == c_bt_bool || type_idx == c_bt_char || type_idx == c_bt_unsigned_char) {
ARRAY_FILL(ARRAY_GEN_VALUES,type_idx);
   }

   // - array get_idx method -

   // - array operator= method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(data_type.properties & c_type_option_nogen_copy)) {
ARRAY_OPERATOR_EQUAL(ARRAY_GEN_VALUES);
      }
   }

   // - array operator== method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
ARRAY_OPERATOR_DOUBLE_EQUAL(ARRAY_GEN_VALUES);
   }
}/*}}}*/

void processor_s::generate_array_methods(unsigned abb_idx,unsigned a_dt_idx)
{/*{{{*/
   data_type_s &data_type = data_types[a_dt_idx];

   string_s &type_abb_string = data_type.types[0];
   unsigned type_abb_idx = abbreviations.get_idx_by_name(type_abb_string.size - 1,type_abb_string.data);

   if (type_abb_idx == c_idx_not_exist) {
      fprintf(stderr,"array: methods: abreviated type name \"%s\" does not exist\n",type_abb_string.data);
      cassert(0);
   }

   unsigned type_idx = abbreviations[type_abb_idx].data_type_idx;
   data_type_s &type = data_types[type_idx];

   // --- definition of methods ---

printf(
"// --- struct %s method definition ---\n"
"\n"
,IM_STRUCT_NAME);

   // - array init method -

   // - array init_size method -

   // - array clear method -
   if (TYPE_NUMBER & c_type_dynamic) {
      if (!(data_type.properties & c_type_option_nogen_clear)) {
ARRAY_CLEAR(ARRAY_GEN_VALUES);
      }
   }

   // - array set method -
   if (TYPE_NUMBER & c_type_dynamic) {
ARRAY_SET(ARRAY_GEN_VALUES);
   }

   // - array_flush_method -

   // - array flush_all method -
   if (TYPE_NUMBER & c_type_flushable) {
ARRAY_FLUSH_ALL(ARRAY_GEN_VALUES);
   }

   // - array swap method -

   // - array operator[] method -

   // - array push method -

   // - array push_blank method -

   // - array reserve method -
ARRAY_RESERVE(ARRAY_GEN_VALUES);

   // - array push_blanks method -
ARRAY_PUSH_BLANKS(ARRAY_GEN_VALUES);

   // - array push_clear method -

   // - array pop method -

   // - array last method -

   // - array copy_resize method -
ARRAY_COPY_RESIZE(ARRAY_GEN_VALUES);

   // - array fill method -
   if (type_idx != c_bt_bool && type_idx != c_bt_char && type_idx != c_bt_unsigned_char) {
ARRAY_FILL(ARRAY_GEN_VALUES,type_idx);
   }

   // - array get_idx method -
ARRAY_GET_IDX(ARRAY_GEN_VALUES);

   // - array operator= method -
   if (TYPE_NUMBER & c_type_dynamic) {
      if (!(data_type.properties & c_type_option_nogen_copy)) {
ARRAY_OPERATOR_EQUAL(ARRAY_GEN_VALUES);
      }
   }

   // - array operator== method -
   if (TYPE_NUMBER & c_type_dynamic) {
ARRAY_OPERATOR_DOUBLE_EQUAL(ARRAY_GEN_VALUES);
   }
}/*}}}*/



#define ARRAY_INIT() \
{\
printf(\
"inline void %s_init(%s *this)\n"\
"{/*{{{*/\n"\
"   this->size = 0;\n"\
"   this->used = 0;\n"\
"   this->data = NULL;\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define ARRAY_INIT_SIZE() \
{\
printf(\
"inline void %s_init_size(%s *this,unsigned a_size)\n"\
"{/*{{{*/\n"\
"   %s_init(this);\n"\
"   %s_copy_resize(this,a_size);\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define ARRAY_CLEAR() \
{\
   if (!(TYPE_NUMBER & c_type_dynamic)) {\
printf(\
"inline void %s_clear(%s *this)\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   }\
   else {\
printf(\
"void %s_clear(%s *this)\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   }\
printf(\
"{/*{{{*/\n"\
"   if (this->data != NULL) {\n"\
);\
   if (TYPE_NUMBER & c_type_dynamic) {\
printf(\
"      %s *ptr = this->data;\n"\
"      %s *ptr_end = ptr + this->size;\n"\
"\n"\
"      do {\n"\
"         %s_clear(ptr);\n"\
"      } while(++ptr < ptr_end);\n"\
"\n"\
,TYPE_NAME,TYPE_NAME,TYPE_NAME);\
   }\
printf(\
"      cfree(this->data);\n"\
"   }\n"\
"\n"\
"   %s_init(this);\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME);\
}

#define ARRAY_SET() \
{\
   if (!(TYPE_NUMBER & c_type_dynamic)) {\
printf(\
"inline void %s_set(%s *this,unsigned a_used,%s *a_data)\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);\
   }\
   else {\
printf(\
"void %s_set(%s *this,unsigned a_used,%s *a_data)\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);\
   }\
printf(\
"{/*{{{*/\n"\
"   %s_clear(this);\n"\
"   if (a_used == 0) return;\n"\
"   \n"\
"   debug_assert(a_data != NULL);\n"\
"   %s_copy_resize(this,a_used);\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   if (!(TYPE_NUMBER & c_type_dynamic)) {\
printf(\
"   memcpy(this->data,a_data,a_used*sizeof(%s));\n"\
,TYPE_NAME);\
   }\
   else {\
printf(\
"   %s *ptr = this->data;\n"\
"   %s *ptr_end = ptr + a_used;\n"\
"   %s *a_ptr = a_data;\n"\
"\n"\
"   do {\n"\
"      *ptr = *a_ptr;\n"\
"   } while(++a_ptr,++ptr < ptr_end);\n"\
"\n"\
,TYPE_NAME,TYPE_NAME,TYPE_NAME);\
   }\
printf(\
"   this->used = a_used;\n"\
"}/*}}}*/\n"\
"\n"\
);\
}

#define ARRAY_FLUSH() \
{\
printf(\
"inline void %s_flush(%s *this)\n"\
"{/*{{{*/\n"\
"   %s_copy_resize(this,this->used);\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define ARRAY_FLUSH_ALL() \
{\
   if (!(TYPE_NUMBER & c_type_flushable)) {\
printf(\
"inline void %s_flush_all(%s *this)\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   }\
   else {\
printf(\
"void %s_flush_all(%s *this)\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   }\
printf(\
"{/*{{{*/\n"\
);\
   if (TYPE_NUMBER & c_type_flushable) {\
printf(\
"   %s *ptr = this->data;\n"\
"   %s *ptr_end = ptr + this->used;\n"\
"\n"\
"   do {\n"\
"      %s_flush_all(ptr);\n"\
"   } while(++ptr < ptr_end);\n"\
"\n"\
,TYPE_NAME,TYPE_NAME,TYPE_NAME);\
   }\
printf(\
"   %s_copy_resize(this,this->used);\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME);\
}

#define ARRAY_SWAP() \
{\
printf(\
"inline void %s_swap(%s *this,%s *a_second)\n"\
"{/*{{{*/\n"\
"   unsigned tmp_unsigned = this->size;\n"\
"   this->size = a_second->size;\n"\
"   a_second->size = tmp_unsigned;\n"\
"\n"\
"   tmp_unsigned = this->used;\n"\
"   this->used = a_second->used;\n"\
"   a_second->used = tmp_unsigned;\n"\
"\n"\
"   %s *tmp_data = this->data;\n"\
"   this->data = a_second->data;\n"\
"   a_second->data = tmp_data;\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);\
}

#define ARRAY_OPERATOR_LE_BR_RE_BR() \
{\
printf(\
"inline %s *%s_at(%s *this,unsigned a_idx)\n"\
"{/*{{{*/\n"\
"   debug_assert(a_idx < this->used);\n"\
"   return this->data + a_idx;\n"\
"}/*}}}*/\n"\
"\n"\
,TYPE_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define ARRAY_PUSH() \
{\
   if (TYPE_NUMBER & c_type_basic) {\
printf(\
"inline void %s_push(%s *this,%s a_value)\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);\
   }\
   else {\
printf(\
"inline void %s_push(%s *this,%s *a_value)\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);\
   }\
printf(\
"{/*{{{*/\n"\
"   if (this->used >= this->size) {\n"\
"      %s_copy_resize(this,(this->size << 1) + c_array_add);\n"\
"   }\n"\
"\n"\
,IM_STRUCT_NAME);\
   if (TYPE_NUMBER & c_type_basic) {\
printf(\
"   this->data[this->used++] = a_value;\n"\
);\
   }\
   else {\
printf(\
"   %s_copy(this->data + this->used++,a_value);\n"\
,TYPE_NAME);\
   }\
printf(\
"}/*}}}*/\n"\
"\n"\
);\
}

#define ARRAY_PUSH_BLANK() \
{\
printf(\
"inline void %s_push_blank(%s *this)\n"\
"{/*{{{*/\n"\
"   if (this->used >= this->size) {\n"\
"      %s_copy_resize(this,(this->size << 1) + c_array_add);\n"\
"   }\n"\
"\n"\
"   this->used++;\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define ARRAY_RESERVE() \
{\
printf(\
"void %s_reserve(%s *this,unsigned a_cnt)\n"\
"{/*{{{*/\n"\
"   unsigned required_cnt = this->used + a_cnt;\n"\
"   if (required_cnt > this->size) {\n"\
"      unsigned r_size = this->size;\n"\
"      do {\n"\
"         r_size = (r_size << 1) + c_array_add;\n"\
"      } while(r_size < required_cnt);\n"\
"\n"\
"      %s_copy_resize(this,r_size);\n"\
"   }\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define ARRAY_PUSH_BLANKS() \
{\
printf(\
"void %s_push_blanks(%s *this,unsigned a_cnt)\n"\
"{/*{{{*/\n"\
"   unsigned required_cnt = this->used + a_cnt;\n"\
"   if (required_cnt > this->size) {\n"\
"      unsigned r_size = this->size;\n"\
"      do {\n"\
"         r_size = (r_size << 1) + c_array_add;\n"\
"      } while(r_size < required_cnt);\n"\
"\n"\
"      %s_copy_resize(this,r_size);\n"\
"   }\n"\
"\n"\
"   this->used += a_cnt;\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define ARRAY_PUSH_CLEAR() \
{\
printf(\
"inline void %s_push_clear(%s *this)\n"\
"{/*{{{*/\n"\
"   if (this->used >= this->size) {\n"\
"      %s_copy_resize(this,(this->size << 1) + c_array_add);\n"\
"   }\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   if (!(TYPE_NUMBER & c_type_dynamic)) {\
printf(\
"   this->used++;\n"\
);\
   }\
   else {\
printf(\
"   %s_clear(this->data + this->used++);\n"\
,TYPE_NAME);\
   }\
printf(\
"}/*}}}*/\n"\
"\n"\
);\
}

#define ARRAY_POP() \
{\
   if (TYPE_NUMBER & c_type_basic) {\
printf(\
"inline %s %s_pop(%s *this)\n"\
,TYPE_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   }\
   else {\
printf(\
"inline %s *%s_pop(%s *this)\n"\
,TYPE_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   }\
printf(\
"{/*{{{*/\n"\
"   debug_assert(this->used > 0);\n"\
);\
   if (TYPE_NUMBER & c_type_basic) {\
printf(\
"   return this->data[--this->used];\n"\
);\
   }\
   else {\
printf(\
"   return this->data + --this->used;\n"\
);\
   }\
printf(\
"}/*}}}*/\n"\
"\n"\
);\
}

#define ARRAY_LAST() \
{\
printf(\
"inline %s *%s_last(%s *this)\n"\
"{/*{{{*/\n"\
"   debug_assert(this->used > 0);\n"\
"   return this->data + this->used - 1;\n"\
"}/*}}}*/\n"\
"\n"\
,TYPE_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define ARRAY_COPY_RESIZE() \
{\
printf(\
"void %s_copy_resize(%s *this,unsigned a_size)\n"\
"{/*{{{*/\n"\
"   debug_assert(a_size >= this->used);\n"\
"\n"\
"   %s *n_data;\n"\
"\n"\
"   if (a_size == 0) {\n"\
"      n_data = NULL;\n"\
"   }\n"\
"   else {\n"\
"      n_data = (%s *)cmalloc(a_size*sizeof(%s));\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);\
   if (TYPE_NUMBER & c_type_dynamic) {\
      if (TYPE_NUMBER & c_type_setting_strict_dynamic) {\
printf(\
"\n"\
"      %s *ptr = n_data;\n"\
"      %s *ptr_end = n_data + a_size;\n"\
"\n"\
"      do {\n"\
"         %s_init(ptr);\n"\
"      } while(++ptr < ptr_end);\n"\
,TYPE_NAME,TYPE_NAME,TYPE_NAME);\
      }\
      else {\
printf(\
"\n"\
"      if (a_size > this->used) {\n"\
"         %s *ptr = n_data + this->used;\n"\
"         %s *ptr_end = n_data + a_size;\n"\
"\n"\
"         do {\n"\
"            %s_init(ptr);\n"\
"         } while(++ptr < ptr_end);\n"\
"      }\n"\
,TYPE_NAME,TYPE_NAME,TYPE_NAME);\
      }\
   }\
printf(\
"   }\n"\
"\n"\
);\
   if (TYPE_NUMBER & c_type_setting_strict_dynamic) {\
printf(\
"   if (this->used > 0) {\n"\
"      %s *ptr = this->data;\n"\
"      %s *ptr_end = ptr + this->used;\n"\
"      %s *n_ptr = n_data;\n"\
"\n"\
"      do {\n"\
"         %s_swap(n_ptr,ptr);\n"\
"      } while(++n_ptr,++ptr < ptr_end);\n"\
"   }\n"\
,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);\
   }\
   else {\
printf(\
"   if (this->used != 0) {\n"\
"      memcpy(n_data,this->data,this->used*sizeof(%s));\n"\
"   }\n"\
,TYPE_NAME);\
   }\
   if (TYPE_NUMBER & c_type_dynamic) {\
printf(\
"\n"\
"   if (this->size > this->used) {\n"\
"      %s *ptr = this->data + this->used;\n"\
"      %s *ptr_end = this->data + this->size;\n"\
"\n"\
"      do {\n"\
"         %s_clear(ptr);\n"\
"      } while(++ptr < ptr_end);\n"\
"   }\n"\
,TYPE_NAME,TYPE_NAME,TYPE_NAME);\
   }\
printf(\
"\n"\
"   if (this->size != 0) {\n"\
"      cfree(this->data);\n"\
"   }\n"\
"\n"\
"   this->data = n_data;\n"\
"   this->size = a_size;\n"\
"}/*}}}*/\n"\
"\n"\
);\
}

#define ARRAY_FILL() \
{\
   if (type_idx == c_bt_bool || type_idx == c_bt_char || type_idx == c_bt_unsigned_char){\
printf(\
"inline void %s_fill(%s *this,%s a_value)\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);\
   }\
   else {\
      if (TYPE_NUMBER & c_type_basic) {\
printf(\
"void %s_fill(%s *this,%s a_value)\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);\
      }\
      else {\
printf(\
"void %s_fill(%s *this,%s *a_value)\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);\
      }\
   }\
printf(\
"{/*{{{*/\n"\
"   if (this->size == 0) return;\n"\
"\n"\
);\
   if (type_idx == c_bt_bool || type_idx == c_bt_char || type_idx == c_bt_unsigned_char) {\
printf(\
"   memset(this->data,a_value,this->size);\n"\
);\
   }\
   else {\
printf(\
"   %s *ptr = this->data;\n"\
"   %s *ptr_end = this->data + this->size;\n"\
"\n"\
"   do {\n"\
,TYPE_NAME,TYPE_NAME);\
      if (TYPE_NUMBER & c_type_basic) {\
printf(\
"      *ptr = a_value;\n"\
);\
      }\
      else {\
printf(\
"      %s_copy(ptr,a_value);\n"\
,TYPE_NAME);\
      }\
printf(\
"   } while(++ptr < ptr_end);\n"\
);\
   }\
printf(\
"\n"\
"   this->used = this->size;\n"\
"}/*}}}*/\n"\
"\n"\
);\
}

#define ARRAY_GET_IDX() \
{\
   if (TYPE_NUMBER & c_type_basic) {\
printf(\
"unsigned %s_get_idx(%s *this,%s a_value)\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);\
   }\
   else {\
printf(\
"unsigned %s_get_idx(%s *this,%s *a_value)\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);\
   }\
printf(\
"{/*{{{*/\n"\
"   if (this->used == 0) return c_idx_not_exist;\n"\
"\n"\
"   %s *ptr = this->data;\n"\
"   %s *ptr_end = this->data + this->used;\n"\
"\n"\
"   do {\n"\
,TYPE_NAME,TYPE_NAME);\
   if (TYPE_NUMBER & c_type_basic) {\
printf(\
"      if (*ptr == a_value) {\n"\
);\
   }\
   else {\
printf(\
"      if (%s_compare(ptr,a_value)) {\n"\
,TYPE_NAME);\
   }\
printf(\
"         return ptr - this->data;\n"\
"      }\n"\
"   } while(++ptr < ptr_end);\n"\
"\n"\
"   return c_idx_not_exist;\n"\
"}/*}}}*/\n"\
"\n"\
);\
}

#define ARRAY_OPERATOR_EQUAL() \
{\
   if (!(TYPE_NUMBER & c_type_dynamic)) {\
printf(\
"inline void %s_copy(%s *this,%s *a_src)\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   }\
   else {\
printf(\
"void %s_copy(%s *this,%s *a_src)\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   }\
printf(\
"{/*{{{*/\n"\
"   %s_clear(this);\n"\
"\n"\
"   if (a_src->used == 0) return;\n"\
"\n"\
"   %s_copy_resize(this,a_src->used);\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   if (!(TYPE_NUMBER & c_type_dynamic)) {\
printf(\
"   memcpy(this->data,a_src->data,a_src->used*sizeof(%s));\n"\
,TYPE_NAME);\
   }\
   else {\
printf(\
"\n"\
"   %s *ptr = this->data;\n"\
"   %s *s_ptr = a_src->data;\n"\
"   %s *s_ptr_end = s_ptr + a_src->used;\n"\
"\n"\
"   do {\n"\
"      %s_copy(ptr,s_ptr);\n"\
"   } while(++ptr,++s_ptr < s_ptr_end);\n"\
,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);\
   }\
printf(\
"\n"\
"   this->used = a_src->used;\n"\
"}/*}}}*/\n"\
"\n"\
);\
}

#define ARRAY_OPERATOR_DOUBLE_EQUAL() \
{\
   if (!(TYPE_NUMBER & c_type_dynamic)) {\
printf(\
"inline int %s_compare(%s *this,%s *a_second)\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   }\
   else {\
printf(\
"int %s_compare(%s *this,%s *a_second)\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   }\
printf(\
"{/*{{{*/\n"\
"   if (this->used != a_second->used) return 0;\n"\
"   if (this->used == 0) return 1;\n"\
);\
   if (!(TYPE_NUMBER & c_type_dynamic)) {\
printf(\
"\n"\
"   return (memcmp(this->data,a_second->data,this->used*sizeof(%s)) == 0);\n"\
,TYPE_NAME);\
   }\
   else {\
printf(\
"\n"\
"   %s *ptr = this->data;\n"\
"   %s *ptr_end = ptr + this->used;\n"\
"   %s *s_ptr = a_second->data;\n"\
"\n"\
"   do {\n"\
"      if (!%s_compare(ptr,s_ptr)) {\n"\
"         return 0;\n"\
"      }\n"\
"   } while(++s_ptr,++ptr < ptr_end);\n"\
"\n"\
"   return 1;\n"\
,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);\
   }\
printf(\
"}/*}}}*/\n"\
"\n"\
);\
}

void processor_s::generate_array_type()
{
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
   if (type.properties & c_type_setting_strict_dynamic) {
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

      data_type.properties = c_type_dynamic | c_type_flushable | (type_settings & c_type_setting_mask);

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
"typedef struct %s\n"
"{\n"
"   unsigned size; //!< actual size of allocated space in array\n"
"   unsigned used; //!< count of used space in array\n"
"   %s *data; //!< pointer to array elements\n"
"} %s;\n"
"\n"
,TYPE_NAME,STRUCT_NAME,TYPE_NAME,STRUCT_NAME);
   if (!(data_type.properties & c_type_setting_not_generate_init)) {
printf(
"inline void %s_init(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
printf(
"inline void %s_init_size(%s *this,unsigned a_size);\n"
,STRUCT_NAME,STRUCT_NAME);
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(data_type.properties & c_type_setting_not_generate_clear)) {
printf(
"inline void %s_clear(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
      }
printf(
"inline void %s_set(%s *this,unsigned a_used,%s *a_data);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
   }
   else {
      if (!(data_type.properties & c_type_setting_not_generate_clear)) {
printf(
"void %s_clear(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
      }
printf(
"void %s_set(%s *this,unsigned a_used,%s *a_data);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
   }
printf(
"inline void %s_flush(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   if (!(TYPE_NUMBER & c_type_flushable)) {
printf(
"inline void %s_flush_all(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
   else {
printf(
"void %s_flush_all(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
   if (!(data_type.properties & c_type_setting_not_generate_swap)) {
printf(
"inline void %s_swap(%s *this,%s *a_second);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   }
printf(
"inline %s *%s_at(%s *this,unsigned a_idx);\n"
,TYPE_NAME,STRUCT_NAME,STRUCT_NAME);
   if (TYPE_NUMBER & c_type_basic) {
printf(
"inline void %s_push(%s *this,%s a_value);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
   }
   else {
printf(
"inline void %s_push(%s *this,%s *a_value);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
   }
printf(
"inline void %s_push_blank(%s *this);\n"
"void %s_reserve(%s *this,unsigned a_cnt);\n"
"void %s_push_blanks(%s *this,unsigned a_cnt);\n"
"inline void %s_push_clear(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   if (TYPE_NUMBER & c_type_basic) {
printf(
"inline %s %s_pop(%s *this);\n"
,TYPE_NAME,STRUCT_NAME,STRUCT_NAME);
   }
   else {
printf(
"inline %s *%s_pop(%s *this);\n"
,TYPE_NAME,STRUCT_NAME,STRUCT_NAME);
   }
printf(
"inline %s *%s_last(%s *this);\n"
"void %s_copy_resize(%s *this,unsigned a_size);\n"
,TYPE_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   if (type_idx == c_bt_char) {
printf(
"inline void %s_fill(%s *this,%s a_value);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
   }
   else {
      if (TYPE_NUMBER & c_type_basic) {
printf(
"void %s_fill(%s *this,%s a_value);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
      }
      else {
printf(
"void %s_fill(%s *this,%s *a_value);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
      }
   }
   if (TYPE_NUMBER & c_type_basic) {
printf(
"unsigned %s_get_idx(%s *this,%s a_value);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
   }
   else {
printf(
"unsigned %s_get_idx(%s *this,%s *a_value);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
   }
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(data_type.properties & c_type_setting_not_generate_operator_equal)) {
printf(
"inline void %s_copy(%s *this,%s *a_src);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
      }
printf(
"inline int %s_compare(%s *this,%s *a_second);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   }
   else {
      if (!(data_type.properties & c_type_setting_not_generate_operator_equal)) {
printf(
"void %s_copy(%s *this,%s *a_src);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
      }
printf(
"int %s_compare(%s *this,%s *a_second);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   }
   if (fun_defs.used != 0) {
      unsigned f_idx = 0;
      do {
printf(
"   %s\n"
,fun_defs[f_idx].data);
      } while(++f_idx < fun_defs.used);
   }
};

void processor_s::generate_array_inlines(unsigned abb_idx,unsigned a_dt_idx)
{
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
"// --- struct %s inline function definition ---\n"
"\n"
,IM_STRUCT_NAME);

   // - array init method -
   if (!(data_type.properties & c_type_setting_not_generate_init)) {
ARRAY_INIT();
   }

   // - array init_size method -
ARRAY_INIT_SIZE();

   // - array clear method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(data_type.properties & c_type_setting_not_generate_clear)) {
ARRAY_CLEAR();
      }
   }

   // - array set method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
ARRAY_SET();
   }

   // - array_flush_method -
ARRAY_FLUSH();

   // - array flush_all method -
   if (!(TYPE_NUMBER & c_type_flushable)) {
ARRAY_FLUSH_ALL();
   }

   // - array swap method -
   if (!(data_type.properties & c_type_setting_not_generate_swap)) {
ARRAY_SWAP();
   }

   // - array operator[] method -
ARRAY_OPERATOR_LE_BR_RE_BR();

   // - array push method -
ARRAY_PUSH();

   // - array push_blank method -
ARRAY_PUSH_BLANK();

   // - array reserve method -

   // - array push_blanks method -

   // - array push_clear method -
ARRAY_PUSH_CLEAR();

   // - array pop method -
ARRAY_POP();

   // - array last method -
ARRAY_LAST();

   // - array copy_resize method -

   // - array fill method -
   if (type_idx == c_bt_bool || type_idx == c_bt_char || type_idx == c_bt_unsigned_char) {
ARRAY_FILL();   
   }

   // - array get_idx method -

   // - array get_pc_idx -

   // - array operator= method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(data_type.properties & c_type_setting_not_generate_operator_equal)) {
ARRAY_OPERATOR_EQUAL();
      }
   }

   // - array operator== method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
ARRAY_OPERATOR_DOUBLE_EQUAL();
   }
}

void processor_s::generate_array_methods(unsigned abb_idx,unsigned a_dt_idx)
{
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
"// --- struct %s function definition ---\n"
"\n"
,IM_STRUCT_NAME);

   // - array init method -

   // - array init_size method -

   // - array clear method -
   if (TYPE_NUMBER & c_type_dynamic) {
      if (!(data_type.properties & c_type_setting_not_generate_clear)) {
ARRAY_CLEAR();
      }
   }

   // - array set method -
   if (TYPE_NUMBER & c_type_dynamic) {
ARRAY_SET();
   }

   // - array_flush_method -

   // - array flush_all method -
   if (TYPE_NUMBER & c_type_flushable) {
ARRAY_FLUSH_ALL();
   }

   // - array swap method -

   // - array operator[] method -

   // - array push method -

   // - array push_blank method -

   // - array reserve method -
ARRAY_RESERVE();

   // - array push_blanks method -
ARRAY_PUSH_BLANKS();

   // - array push_clear method -

   // - array pop method -

   // - array last method -

   // - array copy_resize method -
ARRAY_COPY_RESIZE();

   // - array fill method -
   if (type_idx != c_bt_bool && type_idx != c_bt_char && type_idx != c_bt_unsigned_char) {
ARRAY_FILL();   
   }

   // - array get_idx method -
ARRAY_GET_IDX();

   // - array operator= method -
   if (TYPE_NUMBER & c_type_dynamic) {
      if (!(data_type.properties & c_type_setting_not_generate_operator_equal)) {
ARRAY_OPERATOR_EQUAL();
      }
   }

   // - array operator== method -
   if (TYPE_NUMBER & c_type_dynamic) {
ARRAY_OPERATOR_DOUBLE_EQUAL();
   }
}


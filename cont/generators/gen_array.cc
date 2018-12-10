
#define ARRAY_GEN_PARAMS FILE *out_file,abbreviation_array_s &abbreviations,unsigned abb_idx,unsigned type_abb_idx,data_type_s &type,data_type_s &data_type
#define ARRAY_GEN_VALUES out_file,abbreviations,abb_idx,type_abb_idx,type,data_type

void ARRAY_INIT(ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline void %s_init(%s *this)\n"
"{/*{{{*/\n"
"  this->size = 0;\n"
"  this->used = 0;\n"
"  this->data = NULL;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void ARRAY_INIT_SIZE(ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline void %s_init_size(%s *this,unsigned a_size)\n"
"{/*{{{*/\n"
"  %s_init(this);\n"
"  %s_copy_resize(this,a_size);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void ARRAY_INIT_BUFFER(ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline void %s_init_buffer(%s *this,unsigned a_size,%s *a_data)\n"
"{/*{{{*/\n"
"  %s_init(this);\n"
"  %s_set_buffer(this,a_size,a_data);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void ARRAY_CLEAR(ARRAY_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"static inline void %s_clear(%s *this)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"void %s_clear(%s *this)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
);
   if (TYPE_NUMBER & c_type_dynamic || !(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  if (this->data != NULL)\n"
"  {\n"
);
      if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"    %s *ptr = this->data;\n"
"    %s *ptr_end = ptr + this->size;\n"
"\n"
"    do {\n"
"      %s_clear(ptr);\n"
"    } while(++ptr < ptr_end);\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME);
      }
      if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
         if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"\n"
);
         }
fprintf(out_file,
"    cfree(this->data);\n"
);
      }
fprintf(out_file,
"  }\n"
"\n"
);
   }
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  %s_init(this);\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"  this->used = 0;\n"
);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_SET_BUFFER(ARRAY_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"static inline void %s_set_buffer(%s *this,unsigned a_size,%s *a_data)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"void %s_set_buffer(%s *this,unsigned a_size,%s *a_data)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
"  debug_assert(a_size != 0 && a_data != NULL);\n"
"\n"
"  %s_clear(this);\n"
,IM_STRUCT_NAME);
   if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"\n"
"  %s *ptr = a_data;\n"
"  %s *ptr_end = a_data + a_size;\n"
"\n"
"  do {\n"
"    %s_init(ptr);\n"
"  } while(++ptr < ptr_end);\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   }
fprintf(out_file,
"\n"
"  this->size = a_size;\n"
"  this->data = a_data;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_SET(ARRAY_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"static inline void %s_set(%s *this,unsigned a_used,%s *a_data)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"void %s_set(%s *this,unsigned a_used,%s *a_data)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
);
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
fprintf(out_file,
"  debug_assert(a_used <= this->size);\n"
);
   }
fprintf(out_file,
"  debug_assert(a_data != NULL);\n"
"\n"
"  %s_clear(this);\n"
"\n"
"  if (a_used == 0)\n"
"  {\n"
"    return;\n"
"  }\n"
"\n"
,IM_STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  %s_copy_resize(this,a_used);\n"
"\n"
,IM_STRUCT_NAME);
   }
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"  memcpy(this->data,a_data,a_used*sizeof(%s));\n"
,TYPE_NAME);
   }
   else {
fprintf(out_file,
"  %s *ptr = this->data;\n"
"  %s *ptr_end = ptr + a_used;\n"
"  %s *a_ptr = a_data;\n"
"\n"
"  do {\n"
"    %s_copy(ptr,a_ptr);\n"
"  } while(++a_ptr,++ptr < ptr_end);\n"
"\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   }
fprintf(out_file,
"  this->used = a_used;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_FLUSH(ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline void %s_flush(%s *this)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  %s_copy_resize(this,this->used);\n"
,IM_STRUCT_NAME);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_FLUSH_ALL(ARRAY_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_flushable)) {
fprintf(out_file,
"static inline void %s_flush_all(%s *this)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"void %s_flush_all(%s *this)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  %s_copy_resize(this,this->used);\n"
,IM_STRUCT_NAME);
   }
   if (TYPE_NUMBER & c_type_flushable) {
      if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"\n"
);
      }
fprintf(out_file,
"  if (this->used == 0)\n"
"  {\n"
"    return;\n"
"  }\n"
"\n"
"  %s *ptr = this->data;\n"
"  %s *ptr_end = ptr + this->used;\n"
"\n"
"  do {\n"
"    %s_flush_all(ptr);\n"
"  } while(++ptr < ptr_end);\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_SWAP(ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline void %s_swap(%s *this,%s *a_second)\n"
"{/*{{{*/\n"
"  unsigned tmp_unsigned = this->size;\n"
"  this->size = a_second->size;\n"
"  a_second->size = tmp_unsigned;\n"
"\n"
"  tmp_unsigned = this->used;\n"
"  this->used = a_second->used;\n"
"  a_second->used = tmp_unsigned;\n"
"\n"
"  %s *tmp_data = this->data;\n"
"  this->data = a_second->data;\n"
"  a_second->data = tmp_data;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
}/*}}}*/

void ARRAY_OPERATOR_LE_BR_RE_BR(ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline %s *%s_at(%s *this,unsigned a_idx)\n"
"{/*{{{*/\n"
"  debug_assert(a_idx < this->used);\n"
"  return this->data + a_idx;\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void ARRAY_PUSH(ARRAY_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"static inline void %s_push(%s *this,%s a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"static inline void %s_push(%s *this,%s *a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  if (this->used >= this->size)\n"
"  {\n"
"    %s_copy_resize(this,(this->size << 1) + c_array_add);\n"
"  }\n"
"\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"  debug_assert(this->used < this->size);\n"
);
   }
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"  this->data[this->used++] = a_value;\n"
);
   }
   else {
fprintf(out_file,
"  %s_copy(this->data + this->used++,a_value);\n"
,TYPE_NAME);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_PUSH_BLANK(ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline void %s_push_blank(%s *this)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  if (this->used >= this->size)\n"
"  {\n"
"    %s_copy_resize(this,(this->size << 1) + c_array_add);\n"
"  }\n"
"\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"  debug_assert(this->used < this->size);\n"
);
   }
fprintf(out_file,
"  this->used++;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_RESERVE(ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"void %s_reserve(%s *this,unsigned a_cnt)\n"
"{/*{{{*/\n"
"  unsigned required_cnt = this->used + a_cnt;\n"
"  if (required_cnt > this->size)\n"
"  {\n"
"    unsigned r_size = this->size;\n"
"    do {\n"
"      r_size = (r_size << 1) + c_array_add;\n"
"    } while(r_size < required_cnt);\n"
"\n"
"    %s_copy_resize(this,r_size);\n"
"  }\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void ARRAY_PUSH_BLANKS(ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"void %s_push_blanks(%s *this,unsigned a_cnt)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  unsigned required_cnt = this->used + a_cnt;\n"
"  if (required_cnt > this->size)\n"
"  {\n"
"    unsigned r_size = this->size;\n"
"    do {\n"
"      r_size = (r_size << 1) + c_array_add;\n"
"    } while(r_size < required_cnt);\n"
"\n"
"    %s_copy_resize(this,r_size);\n"
"  }\n"
"\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"  debug_assert(this->used + a_cnt <= this->size);\n"
);
   }
fprintf(out_file,
"  this->used += a_cnt;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_PUSH_CLEAR(ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline void %s_push_clear(%s *this)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  if (this->used >= this->size)\n"
"  {\n"
"    %s_copy_resize(this,(this->size << 1) + c_array_add);\n"
"  }\n"
"\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"  debug_assert(this->used < this->size);\n"
);
   }
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"  this->used++;\n"
);
   }
   else {
fprintf(out_file,
"  %s_clear(this->data + this->used++);\n"
,TYPE_NAME);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_POP(ARRAY_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"static inline %s %s_pop(%s *this)\n"
,TYPE_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"static inline %s *%s_pop(%s *this)\n"
,TYPE_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
"  debug_assert(this->used > 0);\n"
);
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"  return this->data[--this->used];\n"
);
   }
   else {
fprintf(out_file,
"  return this->data + --this->used;\n"
);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_LAST(ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline %s *%s_last(%s *this)\n"
"{/*{{{*/\n"
"  debug_assert(this->used > 0);\n"
"  return this->data + this->used - 1;\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void ARRAY_COPY_RESIZE(ARRAY_GEN_PARAMS)
{/*{{{*/
if (TYPE_NUMBER & c_type_option_strict_dynamic)
{/*{{{*/
fprintf(out_file,
"void %s_copy_resize(%s *this,unsigned a_size)\n"
"{/*{{{*/\n"
"  debug_assert(a_size >= this->used);\n"
"\n"
"  %s *n_data;\n"
"\n"
"  if (a_size == 0)\n"
"  {\n"
"    n_data = NULL;\n"
"  }\n"
"  else\n"
"  {\n"
"    n_data = (%s *)cmalloc(a_size*sizeof(%s));\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);
fprintf(out_file,
"\n"
"    %s *ptr = n_data;\n"
"    %s *ptr_end = n_data + a_size;\n"
"\n"
"    do {\n"
"      %s_init(ptr);\n"
"    } while(++ptr < ptr_end);\n"
"  }\n"
"\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME);
fprintf(out_file,
"  if (this->used > 0)\n"
"  {\n"
"    %s *ptr = this->data;\n"
"    %s *ptr_end = ptr + this->used;\n"
"    %s *n_ptr = n_data;\n"
"\n"
"    do {\n"
"      %s_swap(n_ptr,ptr);\n"
"    } while(++n_ptr,++ptr < ptr_end);\n"
"  }\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);
fprintf(out_file,
"\n"
"  if (this->size > this->used)\n"
"  {\n"
"    %s *ptr = this->data + this->used;\n"
"    %s *ptr_end = this->data + this->size;\n"
"\n"
"    do {\n"
"      %s_clear(ptr);\n"
"    } while(++ptr < ptr_end);\n"
"  }\n"
"\n"
"  if (this->size != 0)\n"
"  {\n"
"    cfree(this->data);\n"
"  }\n"
"\n"
"  this->data = n_data;\n"
"  this->size = a_size;\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME);
}/*}}}*/
else
{/*{{{*/
fprintf(out_file,
"void %s_copy_resize(%s *this,unsigned a_size)\n"
"{/*{{{*/\n"
"  debug_assert(a_size >= this->used);\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"\n"
"  if (this->size > a_size)\n"
"  {\n"
"    %s *ptr = this->data + a_size;\n"
"    %s *ptr_end = this->data + this->size;\n"
"\n"
"    do {\n"
"      %s_clear(ptr);\n"
"    } while(++ptr < ptr_end);\n"
"  }\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   }
fprintf(out_file,
"\n"
"  if (a_size == 0)\n"
"  {\n"
"    if (this->data != NULL)\n"
"    {\n"
"      cfree(this->data);\n"
"    }\n"
"    this->data = NULL;\n"
"  }\n"
"  else\n"
"  {\n"
"    this->data = (%s *)crealloc(this->data,a_size*sizeof(%s));\n"
"  }\n"
,TYPE_NAME,TYPE_NAME);
   if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"\n"
"  if (a_size > this->size)\n"
"  {\n"
"    %s *ptr = this->data + this->size;\n"
"    %s *ptr_end = this->data + a_size;\n"
"\n"
"    do {\n"
"      %s_init(ptr);\n"
"    } while(++ptr < ptr_end);\n"
"  }\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   }
fprintf(out_file,
"\n"
"  this->size = a_size;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/
}/*}}}*/

void ARRAY_FILL(ARRAY_GEN_PARAMS,unsigned type_idx)
{/*{{{*/
   if (type_idx == c_bt_char || type_idx == c_bt_unsigned_char){
fprintf(out_file,
"static inline void %s_fill(%s *this,%s a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
      if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"void %s_fill(%s *this,%s a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
      }
      else {
fprintf(out_file,
"void %s_fill(%s *this,%s *a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
      }
   }
fprintf(out_file,
"{/*{{{*/\n"
"  if (this->size == 0)\n"
"  {\n"
"    return;\n"
"  }\n"
"\n"
);
   if (type_idx == c_bt_char || type_idx == c_bt_unsigned_char) {
fprintf(out_file,
"  memset(this->data,a_value,this->size);\n"
);
   }
   else {
fprintf(out_file,
"  %s *ptr = this->data;\n"
"  %s *ptr_end = this->data + this->size;\n"
"\n"
"  do {\n"
,TYPE_NAME,TYPE_NAME);
      if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"    *ptr = a_value;\n"
);
      }
      else {
fprintf(out_file,
"    %s_copy(ptr,a_value);\n"
,TYPE_NAME);
      }
fprintf(out_file,
"  } while(++ptr < ptr_end);\n"
);
   }
fprintf(out_file,
"\n"
"  this->used = this->size;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_GET_IDX(ARRAY_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"unsigned %s_get_idx(%s *this,%s a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"unsigned %s_get_idx(%s *this,%s *a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
"  if (this->used == 0)\n"
"  {\n"
"    return c_idx_not_exist;\n"
"  }\n"
"\n"
"  %s *ptr = this->data;\n"
"  %s *ptr_end = this->data + this->used;\n"
"\n"
"  do {\n"
,TYPE_NAME,TYPE_NAME);
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"    if (*ptr == a_value)\n"
"    {\n"
);
   }
   else {
fprintf(out_file,
"    if (%s_compare(ptr,a_value))\n"
"    {\n"
,TYPE_NAME);
   }
fprintf(out_file,
"      return ptr - this->data;\n"
"    }\n"
"  } while(++ptr < ptr_end);\n"
"\n"
"  return c_idx_not_exist;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_OPERATOR_EQUAL(ARRAY_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"static inline void %s_copy(%s *this,%s *a_src)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"void %s_copy(%s *this,%s *a_src)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
);
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
fprintf(out_file,
"  debug_assert(a_src->used <= this->size);\n"
"\n"
);
   }
fprintf(out_file,
"  %s_clear(this);\n"
"\n"
"  if (a_src->used == 0)\n"
"  {\n"
"    return;\n"
"  }\n"
,IM_STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"\n"
"  %s_copy_resize(this,a_src->used);\n"
,IM_STRUCT_NAME);
   }
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"\n"
"  memcpy(this->data,a_src->data,a_src->used*sizeof(%s));\n"
,TYPE_NAME);
   }
   else {
fprintf(out_file,
"\n"
"  %s *ptr = this->data;\n"
"  %s *s_ptr = a_src->data;\n"
"  %s *s_ptr_end = s_ptr + a_src->used;\n"
"\n"
"  do {\n"
"    %s_copy(ptr,s_ptr);\n"
"  } while(++ptr,++s_ptr < s_ptr_end);\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   }
fprintf(out_file,
"\n"
"  this->used = a_src->used;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_OPERATOR_DOUBLE_EQUAL(ARRAY_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"static inline int %s_compare(%s *this,%s *a_second)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"int %s_compare(%s *this,%s *a_second)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
"  if (this->used != a_second->used)\n"
"  {\n"
"    return 0;\n"
"  }\n"
"\n"
"  if (this->used == 0)\n"
"  {\n"
"    return 1;\n"
"  }\n"
);
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"\n"
"  return (memcmp(this->data,a_second->data,this->used*sizeof(%s)) == 0);\n"
,TYPE_NAME);
   }
   else {
fprintf(out_file,
"\n"
"  %s *ptr = this->data;\n"
"  %s *ptr_end = ptr + this->used;\n"
"  %s *s_ptr = a_second->data;\n"
"\n"
"  do {\n"
"    if (!%s_compare(ptr,s_ptr))\n"
"    {\n"
"      return 0;\n"
"    }\n"
"  } while(++s_ptr,++ptr < ptr_end);\n"
"\n"
"  return 1;\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void ARRAY_TO_STRING(ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#if OPTION_TO_STRING == ENABLED\n"
"void %s_to_string(%s *this,bc_array_s *a_trg)\n"
"{/*{{{*/\n"
"  bc_array_s_push(a_trg,'[');\n"
"\n"
"  if (this->used != 0)\n"
"  {\n"
"    %s *ptr = this->data;\n"
"    %s *ptr_end = this->data + this->used;\n"
"\n"
"    do {\n"
"      %s_to_string(ptr,a_trg);\n"
"\n"
"      if (++ptr >= ptr_end)\n"
"      {\n"
"        break;\n"
"      }\n"
"\n"
"      bc_array_s_push(a_trg,',');\n"
"    } while(1);\n"
"  }\n"
"\n"
"  bc_array_s_push(a_trg,']');\n"
"}/*}}}*/\n"
"#endif\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);
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

fprintf(out_file,
"// --- struct %s definition --- \n"
"\n"
,STRUCT_NAME);

    unsigned idx = 0;
    do {
fprintf(out_file,
"typedef struct %s %s;\n"
,abbs[0].data,abbs[idx].data);
    } while(++idx < abbs.used);
fprintf(out_file,
"\n"
);

fprintf(out_file,
"struct %s\n"
"{\n"
"  unsigned size; //!< actual size of allocated space in array\n"
"  unsigned used; //!< count of used space in array\n"
"  %s *data; //!< pointer to array elements\n"
"};\n"
"\n"
,STRUCT_NAME,TYPE_NAME);
   if (!(STRUCT_NUMBER & c_type_option_nogen_init)) {
fprintf(out_file,
"static inline void %s_init(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"static inline void %s_init_size(%s *this,unsigned a_size);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
fprintf(out_file,
"static inline void %s_init_buffer(%s *this,unsigned a_size,%s *a_data);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
   }
   if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
      if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"static inline void %s_clear(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
      }
      else {
fprintf(out_file,
"void %s_clear(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
      }
   }
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
     if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"static inline void %s_set_buffer(%s *this,unsigned a_size,%s *a_data);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
      }
      else {
fprintf(out_file,
"void %s_set_buffer(%s *this,unsigned a_size,%s *a_data);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
      }
   }
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"static inline void %s_set(%s *this,unsigned a_used,%s *a_data);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"void %s_set(%s *this,unsigned a_used,%s *a_data);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"static inline void %s_flush(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   if (!(TYPE_NUMBER & c_type_flushable)) {
fprintf(out_file,
"static inline void %s_flush_all(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
   else {
fprintf(out_file,
"void %s_flush_all(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
   if (!(STRUCT_NUMBER & c_type_option_nogen_swap)) {
fprintf(out_file,
"static inline void %s_swap(%s *this,%s *a_second);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   }
fprintf(out_file,
"static inline %s *%s_at(%s *this,unsigned a_idx);\n"
,TYPE_NAME,STRUCT_NAME,STRUCT_NAME);
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"static inline void %s_push(%s *this,%s a_value);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"static inline void %s_push(%s *this,%s *a_value);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"static inline void %s_push_blank(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"void %s_reserve(%s *this,unsigned a_cnt);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
fprintf(out_file,
"void %s_push_blanks(%s *this,unsigned a_cnt);\n"
"static inline void %s_push_clear(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"static inline %s %s_pop(%s *this);\n"
,TYPE_NAME,STRUCT_NAME,STRUCT_NAME);
   }
   else {
fprintf(out_file,
"static inline %s *%s_pop(%s *this);\n"
,TYPE_NAME,STRUCT_NAME,STRUCT_NAME);
   }
fprintf(out_file,
"static inline %s *%s_last(%s *this);\n"
,TYPE_NAME,STRUCT_NAME,STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"void %s_copy_resize(%s *this,unsigned a_size);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
   if (type_idx == c_bt_char) {
fprintf(out_file,
"static inline void %s_fill(%s *this,%s a_value);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
   }
   else {
      if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"void %s_fill(%s *this,%s a_value);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
      }
      else {
fprintf(out_file,
"void %s_fill(%s *this,%s *a_value);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
      }
   }
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"unsigned %s_get_idx(%s *this,%s a_value);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"unsigned %s_get_idx(%s *this,%s *a_value);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
   }
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
fprintf(out_file,
"static inline void %s_copy(%s *this,%s *a_src);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
      }
fprintf(out_file,
"static inline int %s_compare(%s *this,%s *a_second);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   }
   else {
      if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
fprintf(out_file,
"void %s_copy(%s *this,%s *a_src);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
      }
fprintf(out_file,
"int %s_compare(%s *this,%s *a_second);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   }
fprintf(out_file,
"#if OPTION_TO_STRING == ENABLED\n"
"void %s_to_string(%s *this,bc_array_s *a_trg);\n"
"#endif\n"
,STRUCT_NAME,STRUCT_NAME);
   if (fun_defs.used != 0) {
      unsigned f_idx = 0;
      do {
fprintf(out_file,
"%s\n"
,fun_defs[f_idx].data);
      } while(++f_idx < fun_defs.used);
   }
fprintf(out_file,
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

fprintf(out_file,
"// --- struct %s inline method definition ---\n"
"\n"
,IM_STRUCT_NAME);

   // - array init method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_init)) {
ARRAY_INIT(ARRAY_GEN_VALUES);
   }

   // - array init_size method -
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
ARRAY_INIT_SIZE(ARRAY_GEN_VALUES);
   }

   // - array init_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
ARRAY_INIT_BUFFER(ARRAY_GEN_VALUES);
   }

   // - array clear method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
ARRAY_CLEAR(ARRAY_GEN_VALUES);
      }
   }

   // - array set_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer && !(TYPE_NUMBER & c_type_dynamic)) {
ARRAY_SET_BUFFER(ARRAY_GEN_VALUES);
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
   if (!(STRUCT_NUMBER & c_type_option_nogen_swap)) {
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
   if (type_idx == c_bt_char || type_idx == c_bt_unsigned_char) {
ARRAY_FILL(ARRAY_GEN_VALUES,type_idx);
   }

   // - array get_idx method -

   // - array operator= method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
ARRAY_OPERATOR_EQUAL(ARRAY_GEN_VALUES);
      }
   }

   // - array operator== method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
ARRAY_OPERATOR_DOUBLE_EQUAL(ARRAY_GEN_VALUES);
   }

   // - array to_string method -

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

fprintf(out_file,
"// --- struct %s method definition ---\n"
"\n"
,IM_STRUCT_NAME);

   // - array init method -

   // - array init_size method -

   // - array init_buffer method -

   // - array clear method -
   if (TYPE_NUMBER & c_type_dynamic) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
ARRAY_CLEAR(ARRAY_GEN_VALUES);
      }
   }

   // - array set_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer && TYPE_NUMBER & c_type_dynamic) {
ARRAY_SET_BUFFER(ARRAY_GEN_VALUES);
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
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
ARRAY_RESERVE(ARRAY_GEN_VALUES);
   }

   // - array push_blanks method -
ARRAY_PUSH_BLANKS(ARRAY_GEN_VALUES);

   // - array push_clear method -

   // - array pop method -

   // - array last method -

   // - array copy_resize method -
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
ARRAY_COPY_RESIZE(ARRAY_GEN_VALUES);
   }

   // - array fill method -
   if (type_idx != c_bt_char && type_idx != c_bt_unsigned_char) {
ARRAY_FILL(ARRAY_GEN_VALUES,type_idx);
   }

   // - array get_idx method -
ARRAY_GET_IDX(ARRAY_GEN_VALUES);

   // - array operator= method -
   if (TYPE_NUMBER & c_type_dynamic) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
ARRAY_OPERATOR_EQUAL(ARRAY_GEN_VALUES);
      }
   }

   // - array operator== method -
   if (TYPE_NUMBER & c_type_dynamic) {
ARRAY_OPERATOR_DOUBLE_EQUAL(ARRAY_GEN_VALUES);
   }

   // - array to_string method -
ARRAY_TO_STRING(ARRAY_GEN_VALUES);

}/*}}}*/


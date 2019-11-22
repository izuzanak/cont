
#define QUEUE_GEN_PARAMS FILE *out_file,abbreviation_array_s &abbreviations,unsigned abb_idx,unsigned type_abb_idx,data_type_s &type,data_type_s &data_type
#define QUEUE_GEN_VALUES out_file,abbreviations,abb_idx,type_abb_idx,type,data_type

void QUEUE_INIT(QUEUE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline void %s_init(%s *this)\n"
"{/*{{{*/\n"
"  this->size = 0;\n"
"  this->used = 0;\n"
"  this->begin = 0;\n"
"  this->data = NULL;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void QUEUE_INIT_SIZE(QUEUE_GEN_PARAMS)
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

void QUEUE_INIT_BUFFER(QUEUE_GEN_PARAMS)
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

void QUEUE_CLEAR(QUEUE_GEN_PARAMS)
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
"  this->begin = 0;\n"
);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void QUEUE_SET_BUFFER(QUEUE_GEN_PARAMS)
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

void QUEUE_FLUSH(QUEUE_GEN_PARAMS)
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

void QUEUE_FLUSH_ALL(QUEUE_GEN_PARAMS)
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

void QUEUE_SWAP(QUEUE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline void %s_swap(%s *this,%s *a_second)\n"
"{/*{{{*/\n"
"  %s tmp = *this;\n"
"  *this = *a_second;\n"
"  *a_second = tmp;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void QUEUE_OPERATOR_LE_BR_RE_BR(QUEUE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline %s *%s_at(const %s *this,unsigned a_idx)\n"
"{/*{{{*/\n"
"  debug_assert(a_idx < this->used);\n"
"\n"
"  unsigned real_idx = this->begin + a_idx;\n"
"  if (real_idx >= this->size)\n"
"  {\n"
"    return this->data + real_idx - this->size;\n"
"  }\n"
"\n"
"  return this->data + real_idx;\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void QUEUE_INSERT(QUEUE_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"static inline void %s_insert(%s *this,%s a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"static inline void %s_insert(%s *this,const %s *a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  if (this->used >= this->size)\n"
"  {\n"
"    unsigned new_size = (this->size << 1) + c_array_add;\n"
"    debug_assert(new_size != 0);\n"
"\n"
"    %s_copy_resize(this,new_size);\n"
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
"  unsigned inserted_idx = this->begin + this->used++;\n"
"\n"
"  if (inserted_idx >= this->size)\n"
"  {\n"
"    inserted_idx -= this->size;\n"
"  }\n"
"\n"
);
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"  this->data[inserted_idx] = a_value;\n"
);
   }
   else if (TYPE_NUMBER & c_type_static) {
fprintf(out_file,
"  this->data[inserted_idx] = *a_value;\n"
);
   }
   else {
fprintf(out_file,
"  %s_copy(this->data + inserted_idx,a_value);\n"
,TYPE_NAME);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void QUEUE_INSERT_BLANK(QUEUE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline void %s_insert_blank(%s *this)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  if (this->used >= this->size)\n"
"  {\n"
"    unsigned new_size = (this->size << 1) + c_array_add;\n"
"    debug_assert(new_size != 0);\n"
"\n"
"    %s_copy_resize(this,new_size);\n"
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
"  ++this->used;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void QUEUE_NEXT(QUEUE_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"static inline %s %s_next(%s *this)\n"
,TYPE_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"static inline %s *%s_next(%s *this)\n"
,TYPE_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
"  debug_assert(this->used > 0);\n"
"\n"
"  unsigned ret_idx = this->begin;\n"
"\n"
"  if (++this->begin >= this->size)\n"
"  {\n"
"    this->begin = 0;\n"
"  }\n"
"\n"
"  this->used--;\n"
"\n"
);
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"  return this->data[ret_idx];\n"
);
   }
   else {
fprintf(out_file,
"  return this->data + ret_idx;\n"
);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void QUEUE_FIRST(QUEUE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline %s *%s_first(const %s *this)\n"
"{/*{{{*/\n"
"  debug_assert(this->used > 0);\n"
"\n"
"  return this->data + this->begin;\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void QUEUE_LAST(QUEUE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline %s *%s_last(const %s *this)\n"
"{/*{{{*/\n"
"  debug_assert(this->used > 0);\n"
"\n"
"  unsigned last_idx = this->begin + (this->used - 1);\n"
"  if (last_idx >= this->size)\n"
"  {\n"
"    return this->data + last_idx - this->size;\n"
"  }\n"
"\n"
"  return this->data + last_idx;\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void QUEUE_COPY_RESIZE(QUEUE_GEN_PARAMS)
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
   if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"\n"
"    if (a_size > this->used)\n"
"    {\n"
"      %s *ptr = n_data + this->used;\n"
"      %s *ptr_end = n_data + a_size;\n"
"\n"
"      do {\n"
"        %s_init(ptr);\n"
"      } while(++ptr < ptr_end);\n"
"    }\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   }
fprintf(out_file,
"  }\n"
"\n"
"  if (this->used != 0)\n"
"  {\n"
"    unsigned fir_cnt;\n"
"    unsigned sec_cnt;\n"
"\n"
"    if (this->begin + this->used > this->size)\n"
"    {\n"
"      sec_cnt = this->begin + this->used - this->size;\n"
"      fir_cnt = this->used - sec_cnt;\n"
"    }\n"
"    else\n"
"    {\n"
"      fir_cnt = this->used;\n"
"      sec_cnt = 0;\n"
"    }\n"
"\n"
"    memcpy(n_data,this->data + this->begin,fir_cnt*sizeof(%s));\n"
"\n"
"    if (sec_cnt != 0)\n"
"    {\n"
"      memcpy(n_data + fir_cnt,this->data,sec_cnt*sizeof(%s));\n"
"    }\n"
"  }\n"
"\n"
,TYPE_NAME,TYPE_NAME);
   if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"  if (this->size > this->used)\n"
"  {\n"
"    %s *ptr;\n"
"    %s *ptr_end;\n"
"    %s *s_ptr;\n"
"\n"
"    if (this->begin + this->used >= this->size)\n"
"    {\n"
"      ptr = this->data + (this->begin + this->used - this->size);\n"
"      ptr_end = this->data + this->begin;\n"
"      s_ptr = NULL;\n"
"    }\n"
"    else\n"
"    {\n"
"      ptr = this->data;\n"
"      ptr_end = this->data + this->begin;\n"
"      s_ptr = ptr_end + this->used;\n"
"    }\n"
"\n"
"    if (ptr < ptr_end)\n"
"    {\n"
"      do {\n"
"        %s_clear(ptr);\n"
"      } while(++ptr < ptr_end);\n"
"    }\n"
"\n"
"    if (s_ptr != NULL)\n"
"    {\n"
"      %s *s_ptr_end = this->data + this->size;\n"
"      do {\n"
"        %s_clear(s_ptr);\n"
"      } while(++s_ptr < s_ptr_end);\n"
"    }\n"
"  }\n"
"\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   }
fprintf(out_file,
"  if (this->size != 0)\n"
"  {\n"
"    cfree(this->data);\n"
"  }\n"
"\n"
"  this->data = n_data;\n"
"  this->size = a_size;\n"
"  this->begin = 0;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void QUEUE_OPERATOR_EQUAL(QUEUE_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"static inline void %s_copy(%s *this,const %s *a_src)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"void %s_copy(%s *this,const %s *a_src)\n"
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
"  unsigned fir_cnt;\n"
"  unsigned sec_cnt;\n"
"\n"
"  if (a_src->begin + a_src->used > a_src->size)\n"
"  {\n"
"    sec_cnt = a_src->begin + a_src->used - a_src->size;\n"
"    fir_cnt = a_src->used - sec_cnt;\n"
"  }\n"
"  else\n"
"  {\n"
"    fir_cnt = a_src->used;\n"
"    sec_cnt = 0;\n"
"  }\n"
"\n"
"  memcpy(this->data,a_src->data + a_src->begin,fir_cnt*sizeof(%s));\n"
"\n"
"  if (sec_cnt != 0)\n"
"  {\n"
"    memcpy(this->data + fir_cnt,a_src->data,sec_cnt*sizeof(%s));\n"
"  }\n"
"\n"
,TYPE_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"\n"
"  unsigned sec_cnt;\n"
"  %s *ptr = this->data;\n"
"  %s *s_ptr = a_src->data + a_src->begin;\n"
"  %s *s_ptr_end;\n"
"\n"
"  if (a_src->begin + a_src->used > a_src->size)\n"
"  {\n"
"    s_ptr_end = a_src->data + a_src->size;\n"
"    sec_cnt = a_src->begin + a_src->used - a_src->size;\n"
"  }\n"
"  else\n"
"  {\n"
"    s_ptr_end = s_ptr + a_src->used;\n"
"    sec_cnt = 0;\n"
"  }\n"
"\n"
"  do {\n"
"    %s_copy(ptr,s_ptr); \n"
"  } while(++ptr,++s_ptr < s_ptr_end);\n"
"\n"
"  if (sec_cnt != 0)\n"
"  {\n"
"    s_ptr = a_src->data;\n"
"    s_ptr_end = s_ptr + sec_cnt;\n"
"\n"
"    do {\n"
"      %s_copy(ptr,s_ptr);\n"
"    } while(++ptr,++s_ptr < s_ptr_end);\n"
"  }\n"
"\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   }
fprintf(out_file,
"  this->used = a_src->used;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void QUEUE_OPERATOR_DOUBLE_EQUAL(QUEUE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"int %s_compare(const %s *this,const %s *a_second)\n"
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
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"  int _break;\n"
"  int s_break;\n"
"  unsigned pos;\n"
"  unsigned pos_end;\n"
"  unsigned s_pos;\n"
"\n"
"  _break = (this->begin + this->used > this->size);\n"
"  s_break = (a_second->begin + a_second->used > a_second->size);\n"
"  pos = this->begin;\n"
"  s_pos = a_second->begin;\n"
"\n"
"  if (_break)\n"
"  {\n"
"    pos_end = this->begin + this->used - this->size;\n"
"  }\n"
"  else\n"
"  {\n"
"    pos_end = this->begin + this->used;\n"
"  }\n"
"\n"
"  do {\n"
"    if (_break)\n"
"    {\n"
"      unsigned offset = this->size - pos;\n"
"\n"
"      if (s_break)\n"
"      {\n"
"        unsigned s_offset = a_second->size - s_pos;\n"
"\n"
"        if (offset < s_offset)\n"
"        {\n"
"          if (memcmp(this->data + pos,a_second->data + s_pos,offset*sizeof(%s)) != 0)\n"
"          {\n"
"            return 0;\n"
"          }\n"
"\n"
"          s_pos += offset;\n"
"          pos = 0;\n"
"          _break = 0;\n"
"        }\n"
"        else\n"
"        {\n"
"          if (memcmp(this->data + pos,a_second->data + s_pos,s_offset*sizeof(%s)) != 0)\n"
"          {\n"
"            return 0;\n"
"          }\n"
"\n"
"          if (pos += s_offset >= this->size)\n"
"          {\n"
"            pos = 0;\n"
"            _break = 0;\n"
"          }\n"
"          s_pos = 0;\n"
"          s_break = 0;\n"
"        }\n"
"      }\n"
"      else\n"
"      {\n"
"        if (memcmp(this->data + pos,a_second->data + s_pos,offset*sizeof(%s)) != 0)\n"
"        {\n"
"          return 0;\n"
"        }\n"
"        s_pos += offset;\n"
"        pos = 0;\n"
"        _break = 0;\n"
"      }\n"
"    }\n"
"    else\n"
"    {\n"
"      if (s_break)\n"
"      {\n"
"        unsigned s_offset = a_second->size - s_pos;\n"
"\n"
"        if (memcmp(this->data + pos,a_second->data + s_pos,s_offset*sizeof(%s)) != 0)\n"
"        {\n"
"          return 0;\n"
"        }\n"
"        pos += s_offset;\n"
"        s_pos = 0;\n"
"        s_break = 0;\n"
"      }\n"
"      else\n"
"      {\n"
"        return memcmp(this->data + pos,a_second->data + s_pos,(pos_end - pos)*sizeof(%s)) == 0;\n"
"      }\n"
"    }\n"
"  } while(1);\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"  %s *ptr = this->data + this->begin;\n"
"  %s *ptr_break = this->data + this->size;\n"
"  %s *ptr_end;\n"
"  %s *s_ptr = a_second->data + a_second->begin;\n"
"  %s *s_ptr_break = a_second->data + a_second->size;\n"
"\n"
"  if (this->begin + this->used > this->size)\n"
"  {\n"
"    ptr_end = this->data + (this->begin + this->used - this->size);\n"
"  }\n"
"  else\n"
"  {\n"
"    ptr_end = ptr + this->used;\n"
"  }\n"
"\n"
"  do {\n"
"    if (!%s_compare(ptr,s_ptr))\n"
"    {\n"
"      return 0;\n"
"    }\n"
"\n"
"    if (++ptr >= ptr_break)\n"
"    {\n"
"      ptr = this->data;\n"
"    }\n"
"\n"
"    if (++s_ptr >= s_ptr_break)\n"
"    {\n"
"      s_ptr = a_second->data;\n"
"    }\n"
"\n"
"  } while(ptr != ptr_end);\n"
"\n"
"  return 1;\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void QUEUE_TO_STRING(QUEUE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#if OPTION_TO_STRING == ENABLED\n"
"void %s___to_string(const %s *this,bc_array_s *a_trg)\n"
"{/*{{{*/\n"
"  bc_array_s_push(a_trg,'[');\n"
"\n"
"  if (this->used != 0)\n"
"  {\n"
"    unsigned sec_cnt;\n"
"    %s *ptr = this->data + this->begin;\n"
"    %s *ptr_end;\n"
"\n"
"    if (this->begin + this->used > this->size)\n"
"    {\n"
"      ptr_end = this->data + this->size;\n"
"      sec_cnt = this->begin + this->used - this->size;\n"
"    }\n"
"    else\n"
"    {\n"
"      ptr_end = ptr + this->used;\n"
"      sec_cnt = 0;\n"
"    }\n"
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
"\n"
"    if (sec_cnt != 0)\n"
"    {\n"
"      ptr = this->data;\n"
"      ptr_end = ptr + sec_cnt;\n"
"\n"
"      do {\n"
"        bc_array_s_push(a_trg,',');\n"
"        %s_to_string(ptr,a_trg);\n"
"      } while(++ptr < ptr_end);\n"
"    }\n"
"  }\n"
"\n"
"  bc_array_s_push(a_trg,']');\n"
"}/*}}}*/\n"
"#endif\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);
}/*}}}*/

void QUEUE_TO_STRING_SEPARATOR(QUEUE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#if OPTION_TO_STRING == ENABLED\n"
"void %s_to_string_separator(const %s *this,bc_array_s *a_trg,unsigned a_count,const char *a_data)\n"
"{/*{{{*/\n"
"  if (this->used != 0)\n"
"  {\n"
"    unsigned sec_cnt;\n"
"    %s *ptr = this->data + this->begin;\n"
"    %s *ptr_end;\n"
"\n"
"    if (this->begin + this->used > this->size)\n"
"    {\n"
"      ptr_end = this->data + this->size;\n"
"      sec_cnt = this->begin + this->used - this->size;\n"
"    }\n"
"    else\n"
"    {\n"
"      ptr_end = ptr + this->used;\n"
"      sec_cnt = 0;\n"
"    }\n"
"\n"
"    do {\n"
"      %s_to_string(ptr,a_trg);\n"
"\n"
"      if (++ptr >= ptr_end)\n"
"      {\n"
"        break;\n"
"      }\n"
"\n"
"      bc_array_s_append(a_trg,a_count,a_data);\n"
"    } while(1);\n"
"\n"
"    if (sec_cnt != 0)\n"
"    {\n"
"      ptr = this->data;\n"
"      ptr_end = ptr + sec_cnt;\n"
"\n"
"      do {\n"
"        bc_array_s_append(a_trg,a_count,a_data);\n"
"        %s_to_string(ptr,a_trg);\n"
"      } while(++ptr < ptr_end);\n"
"    }\n"
"  }\n"
"}/*}}}*/\n"
"#endif\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);
}/*}}}*/

void QUEUE_TO_JSON(QUEUE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#if OPTION_TO_JSON == ENABLED\n"
"void %s_to_json(const %s *this,bc_array_s *a_trg)\n"
"{/*{{{*/\n"
"  if (this->used != 0)\n"
"  {\n"
"    bc_array_s_push(a_trg,'[');\n"
"\n"
"    unsigned sec_cnt;\n"
"    %s *ptr = this->data + this->begin;\n"
"    %s *ptr_end;\n"
"\n"
"    if (this->begin + this->used > this->size)\n"
"    {\n"
"      ptr_end = this->data + this->size;\n"
"      sec_cnt = this->begin + this->used - this->size;\n"
"    }\n"
"    else\n"
"    {\n"
"      ptr_end = ptr + this->used;\n"
"      sec_cnt = 0;\n"
"    }\n"
"\n"
"    do {\n"
"      %s_to_json(ptr,a_trg);\n"
"\n"
"      if (++ptr >= ptr_end)\n"
"      {\n"
"        break;\n"
"      }\n"
"\n"
"      bc_array_s_push(a_trg,',');\n"
"    } while(1);\n"
"\n"
"    if (sec_cnt != 0)\n"
"    {\n"
"      ptr = this->data;\n"
"      ptr_end = ptr + sec_cnt;\n"
"\n"
"      do {\n"
"        bc_array_s_push(a_trg,',');\n"
"        %s_to_json(ptr,a_trg);\n"
"      } while(++ptr < ptr_end);\n"
"    }\n"
"\n"
"    bc_array_s_push(a_trg,']');\n"
"  }\n"
"  else\n"
"  {\n"
"    bc_array_s_append(a_trg,2,\"[]\");\n"
"  }\n"
"}/*}}}*/\n"
"#endif\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);
}/*}}}*/

void QUEUE_TO_JSON_NICE(QUEUE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#if OPTION_TO_JSON == ENABLED\n"
"void %s_to_json_nice(const %s *this,json_nice_s *a_json_nice,bc_array_s *a_trg)\n"
"{/*{{{*/\n"
"  if (this->used != 0)\n"
"  {\n"
"    bc_array_s_push(a_trg,'[');\n"
"    json_nice_s_push_indent(a_json_nice,a_trg);\n"
"\n"
"    unsigned sec_cnt;\n"
"    %s *ptr = this->data + this->begin;\n"
"    %s *ptr_end;\n"
"\n"
"    if (this->begin + this->used > this->size)\n"
"    {\n"
"      ptr_end = this->data + this->size;\n"
"      sec_cnt = this->begin + this->used - this->size;\n"
"    }\n"
"    else\n"
"    {\n"
"      ptr_end = ptr + this->used;\n"
"      sec_cnt = 0;\n"
"    }\n"
"\n"
"    do {\n"
"      %s_to_json_nice(ptr,a_json_nice,a_trg);\n"
"\n"
"      if (++ptr >= ptr_end)\n"
"      {\n"
"        break;\n"
"      }\n"
"\n"
"      bc_array_s_push(a_trg,',');\n"
"      json_nice_s_indent(a_json_nice,a_trg);\n"
"    } while(1);\n"
"\n"
"    if (sec_cnt != 0)\n"
"    {\n"
"      ptr = this->data;\n"
"      ptr_end = ptr + sec_cnt;\n"
"\n"
"      do {\n"
"        bc_array_s_push(a_trg,',');\n"
"        json_nice_s_indent(a_json_nice,a_trg);\n"
"        %s_to_json_nice(ptr,a_json_nice,a_trg);\n"
"      } while(++ptr < ptr_end);\n"
"    }\n"
"\n"
"    json_nice_s_pop_indent(a_json_nice,a_trg);\n"
"    bc_array_s_push(a_trg,']');\n"
"  }\n"
"  else\n"
"  {\n"
"    bc_array_s_append(a_trg,2,\"[]\");\n"
"  }\n"
"}/*}}}*/\n"
"#endif\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);
}/*}}}*/

void QUEUE_FROM_VAR(QUEUE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#if OPTION_FROM_VAR == ENABLED\n"
"int %s_from_var(%s *this,var_s a_var)\n"
"{/*{{{*/\n"
"  %s_clear(this);\n"
"\n"
"  if (a_var == NULL || a_var->v_type != c_bi_type_array)\n"
"  {\n"
"    throw_error(FROM_VAR_ERROR);\n"
"  }\n"
"\n"
"  var_array_s *array = loc_s_array_value(a_var);\n"
"  if (array->used != 0)\n"
"  {\n"
"    %s_copy_resize(this,array->used);\n"
"    this->used = array->used;\n"
"\n"
"    var_s *v_ptr = array->data;\n"
"    var_s *v_ptr_end = v_ptr + array->used;\n"
"    %s *ptr = this->data;\n"
"    do {\n"
"      if (%s_from_var(ptr,*v_ptr))\n"
"      {\n"
"        throw_error(FROM_VAR_ERROR);\n"
"      }\n"
"    } while(++ptr,++v_ptr < v_ptr_end);\n"
"  }\n"
"\n"
"  return 0;\n"
"}/*}}}*/\n"
"#endif\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME,TYPE_NAME);
}/*}}}*/

void QUEUE_FROM_JSON(QUEUE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#if OPTION_FROM_JSON == ENABLED\n"
"int %s_from_json(%s *this,const bc_array_s *a_src,from_json_s *a_from_json)\n"
"{/*{{{*/\n"
"  %s_clear(this);\n"
"\n"
"  if (from_json_s_get_terminal(a_from_json,a_src,c_json_terminal_le_br))\n"
"  {\n"
"    throw_error(FROM_JSON_ERROR);\n"
"  }\n"
"\n"
"  unsigned input_idx = a_from_json->input_idx;\n"
"  if (from_json_s_get_terminal(a_from_json,a_src,c_json_terminal_re_br))\n"
"  {\n"
"    a_from_json->input_idx = input_idx;\n"
"\n"
"    do {\n"
"      %s_insert_blank(this);\n"
"\n"
"      if (%s_from_json(%s_last(this),a_src,a_from_json))\n"
"      {\n"
"        throw_error(FROM_JSON_ERROR);\n"
"      }\n"
"\n"
"      if (from_json_s_get_terminal(a_from_json,a_src,c_json_terminal_comma))\n"
"      {\n"
"        if (a_from_json->terminal == c_json_terminal_re_br)\n"
"        {\n"
"          break;\n"
"        }\n"
"\n"
"        throw_error(FROM_JSON_ERROR);\n"
"      }\n"
"    } while(1);\n"
"  }\n"
"\n"
"  return 0;\n"
"}/*}}}*/\n"
"#endif\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME,IM_STRUCT_NAME);
}/*}}}*/

void processor_s::generate_queue_type()
{/*{{{*/
   string_array_s &type_names = cont_params.types;
   string_array_s &fun_defs = cont_params.functions;
   string_array_s &abbs = cont_params.names;

   if (type_names.used != 1) {
      fprintf(stderr,"queue: not given name (or too many names) of contained type\n");
      cassert(0);
   }

   if (abbs.used < 1) {
      fprintf(stderr,"queue: not given name of generated structures\n");
      cassert(0);
   }

   unsigned type_abb_idx = abbreviations.get_idx_by_name(type_names[0].size - 1,type_names[0].data);
   if (type_abb_idx == c_idx_not_exist) {
      fprintf(stderr,"queue: contained type \"%s\" does not exist\n",type_names[0].data);
      cassert(0);
   }

   unsigned type_idx = abbreviations[type_abb_idx].data_type_idx;
   data_type_s &type = data_types[type_idx];

   // - test type options -
   if (type.properties & c_type_option_strict_dynamic) {
      fprintf(stderr,"queue: option strict_dynamic not supported\n");
      cassert(0);
   }

   string_s real_name;
   real_name.init();
   real_name.conc_set(type.name.size - 1,type.name.data,strlen(c_cont_postfixes[c_cont_queue]),(char *)c_cont_postfixes[c_cont_queue]);

   string_s &data_type_name = abbs[0];

   unsigned data_type_idx;

   if ((data_type_idx = abbreviations.get_idx_by_name(data_type_name.size - 1,data_type_name.data)) == c_idx_not_exist) {

      // - do not report duplicate structures -
      //unsigned d_idx = data_types.get_idx_by_real_name(real_name.size - 1,real_name.data);
      //if (d_idx != c_idx_not_exist) {
      //   fprintf(stderr,"DUPLICATE STRUCTURES: %s <-> %s\n",data_type_name.data,data_types[d_idx].name.data);
      //}

      data_types.push_blank();
      data_type_s &data_type = data_types.last();

      data_type.cont_idx = c_cont_queue;
      data_type.name.set(data_type_name.size - 1,data_type_name.data);
      data_type.real_name.swap(real_name);

      data_type.properties = c_type_dynamic | c_type_flushable | (type_settings & c_type_option_mask);
      data_type.types.push(abbreviations[type_abb_idx].name);

      data_type_idx = data_types.used - 1;
   }
   else {
      fprintf(stderr,"queue: name of generated structure \"%s\" already exist\n",data_type_name.data);
      cassert(0);
   }

   real_name.clear();

   // - check and write abbreviations -
   if (abbs.used != 0) {
      unsigned idx = 0;
      do {
         string_s &abb = abbs[idx];

         if (abbreviations.get_idx_by_name(abb.size - 1,abb.data) != c_idx_not_exist) {
            fprintf(stderr,"queue: abreaviated name \"%s\" for generated structure is already used\n",abb.data);
            cassert(0);
         }

         abbreviations.push_blank();
         abbreviations.last().set(abb,data_type_idx);
      } while(++idx < abbs.used);
   }

   data_type_s &data_type = data_types[data_type_idx];

   if (gen_options & c_option_gen_code &&
      (include_level == 0 || gen_options & c_option_gen_includes))
   {
   // - definition of structure queue -

fprintf(out_file,
"// struct %s definition\n"
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
"  unsigned size; //!< actual size of allocated space (element count)\n"
"  unsigned used; //!< count of stored elements\n"
"  unsigned begin; //!< position of first element\n"
"  %s *data; //!< pointer to queue elements\n"
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
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
fprintf(out_file,
"static inline void %s_clear(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
      }
   }
   else {
      if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
fprintf(out_file,
"EXPORT void %s_clear(%s *this);\n"
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
"EXPORT void %s_set_buffer(%s *this,unsigned a_size,%s *a_data);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
      }
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
"EXPORT void %s_flush_all(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
   if (!(STRUCT_NUMBER & c_type_option_nogen_swap)) {
fprintf(out_file,
"static inline void %s_swap(%s *this,%s *a_second);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   }
fprintf(out_file,
"static inline %s *%s_at(const %s *this,unsigned a_idx);\n"
,TYPE_NAME,STRUCT_NAME,STRUCT_NAME);
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"static inline void %s_insert(%s *this,%s a_value);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"static inline void %s_insert(%s *this,const %s *a_value);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"static inline void %s_insert_blank(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"static inline %s %s_next(%s *this);\n"
,TYPE_NAME,STRUCT_NAME,STRUCT_NAME);
   }
   else {
fprintf(out_file,
"static inline %s *%s_next(%s *this);\n"
,TYPE_NAME,STRUCT_NAME,STRUCT_NAME);
   }
fprintf(out_file,
"static inline %s *%s_first(const %s *this);\n"
"static inline %s *%s_last(const %s *this);\n"
,TYPE_NAME,STRUCT_NAME,STRUCT_NAME,TYPE_NAME,STRUCT_NAME,STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"EXPORT void %s_copy_resize(%s *this,unsigned a_size);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
   if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
      if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"static inline void %s_copy(%s *this,const %s *a_src);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
      }
      else {
fprintf(out_file,
"EXPORT void %s_copy(%s *this,const %s *a_src);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
      }
   }
fprintf(out_file,
"EXPORT int %s_compare(const %s *this,const %s *a_second);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
fprintf(out_file,
"#if OPTION_TO_STRING == ENABLED\n"
"EXPORT void %s___to_string(const %s *this,bc_array_s *a_trg);\n"
"#define %s_to_string %s___to_string\n"
"EXPORT void %s_to_string_separator(const %s *this,bc_array_s *a_trg,unsigned a_count,const char *a_data);\n"
"#endif\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   if (STRUCT_NUMBER & (c_type_option_to_json | c_type_option_to_json_nice)) {
fprintf(out_file,
"#if OPTION_TO_JSON == ENABLED\n"
);
      if (STRUCT_NUMBER & c_type_option_to_json) {
fprintf(out_file,
"EXPORT void %s_to_json(const %s *this,bc_array_s *a_trg);\n"
,STRUCT_NAME,STRUCT_NAME);
      }
      if (STRUCT_NUMBER & c_type_option_to_json_nice) {
fprintf(out_file,
"EXPORT void %s_to_json_nice(const %s *this,json_nice_s *a_json_nice,bc_array_s *a_trg);\n"
,STRUCT_NAME,STRUCT_NAME);
      }
fprintf(out_file,
"#endif\n"
);
   }
   if (STRUCT_NUMBER & c_type_option_from_var) {
fprintf(out_file,
"#if OPTION_FROM_VAR == ENABLED\n"
"WUR EXPORT int %s_from_var(%s *this,var_s a_var);\n"
"#endif\n"
,STRUCT_NAME,STRUCT_NAME);
   }
   if (STRUCT_NUMBER & c_type_option_from_json) {
fprintf(out_file,
"#if OPTION_FROM_JSON == ENABLED\n"
"WUR EXPORT int %s_from_json(%s *this,const bc_array_s *a_src,from_json_s *a_from_json);\n"
"#endif\n"
,STRUCT_NAME,STRUCT_NAME);
   }
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
   }
}/*}}}*/

void processor_s::generate_queue_inlines(unsigned abb_idx,unsigned a_dt_idx)
{/*{{{*/
   data_type_s &data_type = data_types[a_dt_idx];

   string_s &type_abb_string = data_type.types[0];
   unsigned type_abb_idx = abbreviations.get_idx_by_name(type_abb_string.size - 1,type_abb_string.data);

   if (type_abb_idx == c_idx_not_exist) {
      fprintf(stderr,"queue: inlines: abbeviated type name \"%s\" does not exist\n",type_abb_string.data);
      cassert(0);
   }

   unsigned type_idx = abbreviations[type_abb_idx].data_type_idx;
   data_type_s &type = data_types[type_idx];

   if (gen_options & c_option_gen_code &&
      (include_level == 0 || gen_options & c_option_gen_includes))
   {
   // - definition of inline methods -

fprintf(out_file,
"// --- struct %s inline method definition ---\n"
"\n"
,IM_STRUCT_NAME);

   // - queue init method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_init)) {
QUEUE_INIT(QUEUE_GEN_VALUES);
   }

   // - queue init_size method -
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
QUEUE_INIT_SIZE(QUEUE_GEN_VALUES);
   }

   // - queue init_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
QUEUE_INIT_BUFFER(QUEUE_GEN_VALUES);
   }

   // - queue clear method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
QUEUE_CLEAR(QUEUE_GEN_VALUES);
      }
   }

   // - queue set_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer && !(TYPE_NUMBER & c_type_dynamic)) {
QUEUE_SET_BUFFER(QUEUE_GEN_VALUES);
   }

   // - queue flush method -
QUEUE_FLUSH(QUEUE_GEN_VALUES);

   // - queue flush_all method -
   if (!(TYPE_NUMBER & c_type_flushable)) {
QUEUE_FLUSH_ALL(QUEUE_GEN_VALUES);
   }

   // - queue swap method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_swap)) {
QUEUE_SWAP(QUEUE_GEN_VALUES);
   }

   // - queue operator[] method -
QUEUE_OPERATOR_LE_BR_RE_BR(QUEUE_GEN_VALUES);

   // - queue insert method -
QUEUE_INSERT(QUEUE_GEN_VALUES);

   // - queue insert_blank method -
QUEUE_INSERT_BLANK(QUEUE_GEN_VALUES);

   // - queue next method -
QUEUE_NEXT(QUEUE_GEN_VALUES);

   // - queue first method -
QUEUE_FIRST(QUEUE_GEN_VALUES);

   // - queue last method -
QUEUE_LAST(QUEUE_GEN_VALUES);

   // - queue copy_resize method -

   // - queue operator= method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
QUEUE_OPERATOR_EQUAL(QUEUE_GEN_VALUES);
      }
   }

   // - queue operator== method -

   // - queue to_string method -

   // - queue to_string_separator method -

   // - queue to_json method -

   // - queue to_json_nice method -

   // - queue from_var method -

   // - queue from_json method -
   }
}/*}}}*/

void processor_s::generate_queue_methods(unsigned abb_idx,unsigned a_dt_idx)
{/*{{{*/
   data_type_s &data_type = data_types[a_dt_idx];

   string_s &type_abb_string = data_type.types[0];
   unsigned type_abb_idx = abbreviations.get_idx_by_name(type_abb_string.size - 1,type_abb_string.data);

   if (type_abb_idx == c_idx_not_exist) {
      fprintf(stderr,"queue: methods: abreviated type name \"%s\" does not exist\n",type_abb_string.data);
      cassert(0);
   }

   unsigned type_idx = abbreviations[type_abb_idx].data_type_idx;
   data_type_s &type = data_types[type_idx];

   if (gen_options & c_option_gen_code &&
      (include_level == 0 || gen_options & c_option_gen_includes))
   {
   // - definition of methods -

fprintf(out_file,
"// --- struct %s method definition ---\n"
"\n"
,IM_STRUCT_NAME);

   // - queue init method -

   // - queue init_size method -

   // - queue init_buffer method -

   // - queue clear method -
   if (TYPE_NUMBER & c_type_dynamic) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
QUEUE_CLEAR(QUEUE_GEN_VALUES);
      }
   }

   // - queue set_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer && TYPE_NUMBER & c_type_dynamic) {
QUEUE_SET_BUFFER(QUEUE_GEN_VALUES);
   }

   // - queue flush method -

   // - queue flush_all method -
   if (TYPE_NUMBER & c_type_flushable) {
QUEUE_FLUSH_ALL(QUEUE_GEN_VALUES);
   }

   // - queue swap method -

   // - queue operator[] method -

   // - queue insert method -

   // - queue insert_blank method -

   // - queue next method -

   // - queue first method -

   // - queue last method -

   // - queue copy_resize method -
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
QUEUE_COPY_RESIZE(QUEUE_GEN_VALUES);
   }

   // - queue operator= method -
   if (TYPE_NUMBER & c_type_dynamic) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
QUEUE_OPERATOR_EQUAL(QUEUE_GEN_VALUES);
      }
   }

   // - queue operator== method -
QUEUE_OPERATOR_DOUBLE_EQUAL(QUEUE_GEN_VALUES);

   // - queue to_string method -
QUEUE_TO_STRING(QUEUE_GEN_VALUES);

   // - queue to_string_separator method -
QUEUE_TO_STRING_SEPARATOR(QUEUE_GEN_VALUES);

   // - queue to_json method -
   if (STRUCT_NUMBER & c_type_option_to_json) {
QUEUE_TO_JSON(QUEUE_GEN_VALUES);
   }

   // - queue to_json_nice method -
   if (STRUCT_NUMBER & c_type_option_to_json_nice) {
QUEUE_TO_JSON_NICE(QUEUE_GEN_VALUES);
   }

   // - queue from_var method -
   if (STRUCT_NUMBER & c_type_option_from_var) {
QUEUE_FROM_VAR(QUEUE_GEN_VALUES);
   }

   // - queue from_json method -
   if (STRUCT_NUMBER & c_type_option_from_json) {
QUEUE_FROM_JSON(QUEUE_GEN_VALUES);
   }

   }
}/*}}}*/


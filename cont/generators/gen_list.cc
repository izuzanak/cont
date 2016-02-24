
#define LIST_GEN_PARAMS abbreviation_array_s &abbreviations,unsigned abb_idx,unsigned type_abb_idx,data_type_s &type
#define LIST_GEN_VALUES abbreviations,abb_idx,type_abb_idx,type

void LIST_INIT(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"static inline void %s_init(%s *this)\n"
"{/*{{{*/\n"
"   this->size = 0;\n"
"   this->used = 0;\n"
"   this->data = NULL;\n"
"   this->free_idx = c_idx_not_exist;\n"
"   this->first_idx = c_idx_not_exist;\n"
"   this->last_idx = c_idx_not_exist;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void LIST_INIT_SIZE(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"static inline void %s_init_size(%s *this,unsigned a_size)\n"
"{/*{{{*/\n"
"   %s_init(this);\n"
"   %s_copy_resize(this,a_size);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void LIST_CLEAR(LIST_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_dynamic)) {
printf(
"static inline void %s_clear(%s *this)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
   else {
printf(
"void %s_clear(%s *this)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
printf(
"{/*{{{*/\n"
"   if (this->data != NULL) {\n"
);
   if (TYPE_NUMBER & c_type_dynamic) {
printf(
"      %s_element *ptr = this->data;\n"
"      %s_element *ptr_end = ptr + this->size;\n"
"\n"
"      do {\n"
"         %s_clear(&ptr->object);\n"
"      } while(++ptr < ptr_end);\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
printf(
"      cfree(this->data);\n"
"   }\n"
"\n"
"   %s_init(this);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void LIST_FLUSH(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"static inline void %s_flush(%s *this)\n"
"{/*{{{*/\n"
"   %s_copy_resize(this,this->used);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void LIST_FLUSH_ALL(LIST_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_flushable)) {
printf(
"static inline void %s_flush_all(%s *this)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
   else {
printf(
"void %s_flush_all(%s *this)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
printf(
"{/*{{{*/\n"
);
   if (TYPE_NUMBER & c_type_flushable) {
printf(
"   %s_element *ptr = this->data;\n"
"   %s_element *ptr_end = ptr + this->used;\n"
"\n"
"   do {\n"
"      %s_flush_all(&ptr->object);\n"
"   } while(++ptr < ptr_end);\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
printf(
"   %s_copy_resize(this,this->used);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void LIST_SWAP(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"static inline void %s_swap(%s *this,%s *a_second)\n"
"{/*{{{*/\n"
"   unsigned tmp_unsigned = this->size;\n"
"   this->size = a_second->size;\n"
"   a_second->size = tmp_unsigned;\n"
"\n"
"   tmp_unsigned = this->used;\n"
"   this->used = a_second->used;\n"
"   a_second->used = tmp_unsigned;\n"
"\n"
"   %s_element *tmp_data = this->data;\n"
"   this->data = a_second->data;\n"
"   a_second->data = tmp_data;\n"
"\n"
"   tmp_unsigned = this->free_idx;\n"
"   this->free_idx = a_second->free_idx;\n"
"   a_second->free_idx = tmp_unsigned;\n"
"\n"
"   tmp_unsigned = this->first_idx;\n"
"   this->first_idx = a_second->first_idx;\n"
"   a_second->first_idx = tmp_unsigned;\n"
"\n"
"   tmp_unsigned = this->last_idx;\n"
"   this->last_idx = a_second->last_idx;\n"
"   a_second->last_idx = tmp_unsigned;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void LIST_OPERATOR_LE_BR_RE_BR(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"static inline %s *%s_at(%s *this,unsigned a_idx)\n"
"{/*{{{*/\n"
"   debug_assert(a_idx < this->used);\n"
"   return &this->data[a_idx].object;\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void LIST_PREPEND(LIST_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
printf(
"static inline unsigned %s_prepend(%s *this,%s a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
printf(
"static inline unsigned %s_prepend(%s *this,%s *a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
printf(
"{/*{{{*/\n"
"   unsigned new_idx;\n"
"\n"
"   if (this->free_idx != c_idx_not_exist) {\n"
"      new_idx = this->free_idx;\n"
"      this->free_idx = this->data[new_idx].next_idx;\n"
"   }\n"
"   else {\n"
"      if (this->used >= this->size) {\n"
"         %s_copy_resize(this,(this->size << 1) + c_array_add);\n"
"      }\n"
"\n"
"      new_idx = this->used++;\n"
"   }\n"
"\n"
"   %s_element *new_element = this->data + new_idx;\n"
"\n"
"   new_element->next_idx = this->first_idx;\n"
"   new_element->prev_idx = c_idx_not_exist;\n"
"\n"
"   if (this->first_idx != c_idx_not_exist) {\n"
"      this->data[this->first_idx].prev_idx = new_idx;\n"
"   }\n"
"   else {\n"
"      this->last_idx = new_idx;\n"
"   }\n"
"\n"
"   this->first_idx = new_idx;\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (TYPE_NUMBER & c_type_basic) {
printf(
"   new_element->object = a_value;\n"
);
   }
   else {
printf(
"   %s_copy(&new_element->object,a_value);\n"
,TYPE_NAME);
   }
printf(
"\n"
"   return new_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_APPEND(LIST_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
printf(
"static inline unsigned %s_append(%s *this,%s a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
printf(
"static inline unsigned %s_append(%s *this,%s *a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
printf(
"{/*{{{*/\n"
"   unsigned new_idx;\n"
"\n"
"   if (this->free_idx != c_idx_not_exist) {\n"
"      new_idx = this->free_idx;\n"
"      this->free_idx = this->data[new_idx].next_idx;\n"
"   }\n"
"   else {\n"
"      if (this->used >= this->size) {\n"
"         %s_copy_resize(this,(this->size << 1) + c_array_add);\n"
"      }\n"
"\n"
"      new_idx = this->used++;\n"
"   }\n"
"\n"
"   %s_element *new_element = this->data + new_idx;\n"
"\n"
"   new_element->next_idx = c_idx_not_exist;\n"
"   new_element->prev_idx = this->last_idx;\n"
"\n"
"   if (this->last_idx != c_idx_not_exist) {\n"
"      this->data[this->last_idx].next_idx = new_idx;\n"
"   }\n"
"   else {\n"
"      this->first_idx = new_idx;\n"
"   }\n"
"\n"
"   this->last_idx = new_idx;\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (TYPE_NUMBER & c_type_basic) {
printf(
"   new_element->object = a_value;\n"
);
   }
   else {
printf(
"   %s_copy(&new_element->object,a_value);\n"
,TYPE_NAME);
   }
printf(
"\n"
"   return new_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_INSERT_BEFORE(LIST_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
printf(
"static inline unsigned %s_insert_before(%s *this,unsigned a_idx,%s a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
printf(
"static inline unsigned %s_insert_before(%s *this,unsigned a_idx,%s *a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
printf(
"{/*{{{*/\n"
"   debug_assert(a_idx < this->used);\n"
"\n"
"   unsigned new_idx;\n"
"\n"
"   if (this->free_idx != c_idx_not_exist) {\n"
"      new_idx = this->free_idx;\n"
"      this->free_idx = this->data[new_idx].next_idx;\n"
"   }\n"
"   else {\n"
"      if (this->used >= this->size) {\n"
"         %s_copy_resize(this,(this->size << 1) + c_array_add);\n"
"      }\n"
"\n"
"      new_idx = this->used++;\n"
"   }\n"
"\n"
"   %s_element *idx_element = this->data + a_idx;\n"
"   %s_element *new_element = this->data + new_idx;\n"
"\n"
"   new_element->next_idx = a_idx;\n"
"   new_element->prev_idx = idx_element->prev_idx;\n"
"\n"
"   if (idx_element->prev_idx != c_idx_not_exist) {\n"
"      this->data[idx_element->prev_idx].next_idx = new_idx;\n"
"   }\n"
"   else {\n"
"      this->first_idx = new_idx;\n"
"   }\n"
"\n"
"   idx_element->prev_idx = new_idx;\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (TYPE_NUMBER & c_type_basic) {
printf(
"   new_element->object = a_value;\n"
);
   }
   else {
printf(
"   %s_copy(&new_element->object,a_value);\n"
,TYPE_NAME);
   }
printf(
"\n"
"   return new_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_INSERT_AFTER(LIST_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
printf(
"static inline unsigned %s_insert_after(%s *this,unsigned a_idx,%s a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
printf(
"static inline unsigned %s_insert_after(%s *this,unsigned a_idx,%s *a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
printf(
"{/*{{{*/\n"
"   debug_assert(a_idx < this->used);\n"
"\n"
"   unsigned new_idx;\n"
"\n"
"   if (this->free_idx != c_idx_not_exist) {\n"
"      new_idx = this->free_idx;\n"
"      this->free_idx = this->data[new_idx].next_idx;\n"
"   }\n"
"   else {\n"
"      if (this->used >= this->size) {\n"
"         %s_copy_resize(this,(this->size << 1) + c_array_add);\n"
"      }\n"
"\n"
"      new_idx = this->used++;\n"
"   }\n"
"\n"
"   %s_element *idx_element = this->data + a_idx;\n"
"   %s_element *new_element = this->data + new_idx;\n"
"\n"
"   new_element->next_idx = idx_element->next_idx;\n"
"   new_element->prev_idx = a_idx;\n"
"\n"
"   if (idx_element->next_idx != c_idx_not_exist) {\n"
"      this->data[idx_element->next_idx].prev_idx = new_idx;\n"
"   }\n"
"   else {\n"
"      this->last_idx = new_idx;\n"
"   }\n"
"\n"
"   idx_element->next_idx = new_idx;\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (TYPE_NUMBER & c_type_basic) {
printf(
"   new_element->object = a_value;\n"
);
   }
   else {
printf(
"   %s_copy(&new_element->object,a_value);\n"
,TYPE_NAME);
   }
printf(
"\n"
"   return new_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_PREPEND_BLANK(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"static inline unsigned %s_prepend_blank(%s *this)\n"
"{/*{{{*/\n"
"   unsigned new_idx;\n"
"\n"
"   if (this->free_idx != c_idx_not_exist) {\n"
"      new_idx = this->free_idx;\n"
"      this->free_idx = this->data[new_idx].next_idx;\n"
"   }\n"
"   else {\n"
"      if (this->used >= this->size) {\n"
"         %s_copy_resize(this,(this->size << 1) + c_array_add);\n"
"      }\n"
"\n"
"      new_idx = this->used++;\n"
"   }\n"
"\n"
"   %s_element *new_element = this->data + new_idx;\n"
"\n"
"   new_element->next_idx = this->first_idx;\n"
"   new_element->prev_idx = c_idx_not_exist;\n"
"\n"
"   if (this->first_idx != c_idx_not_exist) {\n"
"      this->data[this->first_idx].prev_idx = new_idx;\n"
"   }\n"
"   else {\n"
"      this->last_idx = new_idx;\n"
"   }\n"
"\n"
"   this->first_idx = new_idx;\n"
"\n"
"   return new_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void LIST_APPEND_BLANK(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"static inline unsigned %s_append_blank(%s *this)\n"
"{/*{{{*/\n"
"   unsigned new_idx;\n"
"\n"
"   if (this->free_idx != c_idx_not_exist) {\n"
"      new_idx = this->free_idx;\n"
"      this->free_idx = this->data[new_idx].next_idx;\n"
"   }\n"
"   else {\n"
"      if (this->used >= this->size) {\n"
"         %s_copy_resize(this,(this->size << 1) + c_array_add);\n"
"      }\n"
"\n"
"      new_idx = this->used++;\n"
"   }\n"
"\n"
"   %s_element *new_element = this->data + new_idx;\n"
"\n"
"   new_element->next_idx = c_idx_not_exist;\n"
"   new_element->prev_idx = this->last_idx;\n"
"\n"
"   if (this->last_idx != c_idx_not_exist) {\n"
"      this->data[this->last_idx].next_idx = new_idx;\n"
"   }\n"
"   else {\n"
"      this->first_idx = new_idx;\n"
"   }\n"
"\n"
"   this->last_idx = new_idx;\n"
"\n"
"   return new_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void LIST_INSERT_BLANK_BEFORE(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"static inline unsigned %s_insert_blank_before(%s *this,unsigned a_idx)\n"
"{/*{{{*/\n"
"   debug_assert(a_idx < this->used);\n"
"\n"
"   unsigned new_idx;\n"
"\n"
"   if (this->free_idx != c_idx_not_exist) {\n"
"      new_idx = this->free_idx;\n"
"      this->free_idx = this->data[new_idx].next_idx;\n"
"   }\n"
"   else {\n"
"      if (this->used >= this->size) {\n"
"         %s_copy_resize(this,(this->size << 1) + c_array_add);\n"
"      }\n"
"\n"
"      new_idx = this->used++;\n"
"   }\n"
"\n"
"   %s_element *idx_element = this->data + a_idx;\n"
"   %s_element *new_element = this->data + new_idx;\n"
"\n"
"   new_element->next_idx = a_idx;\n"
"   new_element->prev_idx = idx_element->prev_idx;\n"
"\n"
"   if (idx_element->prev_idx != c_idx_not_exist) {\n"
"      this->data[idx_element->prev_idx].next_idx = new_idx;\n"
"   }\n"
"   else {\n"
"      this->first_idx = new_idx;\n"
"   }\n"
"\n"
"   idx_element->prev_idx = new_idx;\n"
"\n"
"   return new_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void LIST_INSERT_BLANK_AFTER(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"static inline unsigned %s_insert_blank_after(%s *this,unsigned a_idx)\n"
"{/*{{{*/\n"
"   debug_assert(a_idx < this->used);\n"
"\n"
"   unsigned new_idx;\n"
"\n"
"   if (this->free_idx != c_idx_not_exist) {\n"
"      new_idx = this->free_idx;\n"
"      this->free_idx = this->data[new_idx].next_idx;\n"
"   }\n"
"   else {\n"
"      if (this->used >= this->size) {\n"
"         %s_copy_resize(this,(this->size << 1) + c_array_add);\n"
"      }\n"
"\n"
"      new_idx = this->used++;\n"
"   }\n"
"\n"
"   %s_element *idx_element = this->data + a_idx;\n"
"   %s_element *new_element = this->data + new_idx;\n"
"\n"
"   new_element->next_idx = idx_element->next_idx;\n"
"   new_element->prev_idx = a_idx;\n"
"\n"
"   if (idx_element->next_idx != c_idx_not_exist) {\n"
"      this->data[idx_element->next_idx].prev_idx = new_idx;\n"
"   }\n"
"   else {\n"
"      this->last_idx = new_idx;\n"
"   }\n"
"\n"
"   idx_element->next_idx = new_idx;\n"
"\n"
"   return new_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void LIST_REMOVE(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"static inline void %s_remove(%s *this,unsigned a_idx)\n"
"{/*{{{*/\n"
"   debug_assert(a_idx < this->used);\n"
"\n"
"   %s_element *rm_element = this->data + a_idx;\n"
"\n"
"   if (rm_element->next_idx != c_idx_not_exist) {\n"
"      this->data[rm_element->next_idx].prev_idx = rm_element->prev_idx;\n"
"   }\n"
"   else {\n"
"      this->last_idx = rm_element->prev_idx;\n"
"   }\n"
"\n"
"   if (rm_element->prev_idx != c_idx_not_exist) {\n"
"      this->data[rm_element->prev_idx].next_idx = rm_element->next_idx;\n"
"   }\n"
"   else {\n"
"      this->first_idx = rm_element->next_idx;\n"
"   }\n"
"\n"
"   rm_element->next_idx = this->free_idx;\n"
"   this->free_idx = a_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void LIST_NEXT_IDX(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"static inline unsigned %s_next_idx(%s *this,unsigned a_idx)\n"
"{/*{{{*/\n"
"   return this->data[a_idx].next_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void LIST_PREV_IDX(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"static inline unsigned %s_prev_idx(%s *this,unsigned a_idx)\n"
"{/*{{{*/\n"
"   return this->data[a_idx].prev_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void LIST_COPY_RESIZE(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"void %s_copy_resize(%s *this,unsigned a_size)\n"
"{/*{{{*/\n"
"   debug_assert(a_size >= this->used);\n"
"\n"
"   %s_element *n_data;\n"
"\n"
"   if (a_size == 0) {\n"
"      n_data = NULL;\n"
"   }\n"
"   else {\n"
"      n_data = (%s_element *)cmalloc(a_size*sizeof(%s_element));\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (TYPE_NUMBER & c_type_dynamic) {
printf(
"\n"
"      if (a_size > this->used) {\n"
"         %s_element *ptr = n_data + this->used;\n"
"         %s_element *ptr_end = n_data + a_size;\n"
"\n"
"         do {\n"
"            %s_init(&ptr->object);\n"
"         } while(++ptr < ptr_end);\n"
"      }\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
printf(
"   }\n"
"\n"
"   if (this->used != 0) {\n"
"      memcpy(n_data,this->data,this->used*sizeof(%s_element));\n"
"   }\n"
,IM_STRUCT_NAME);
   if (TYPE_NUMBER & c_type_dynamic) {
printf(
"\n"
"   if (this->size > this->used) {\n"
"      %s_element *ptr = this->data + this->used;\n"
"      %s_element *ptr_end = this->data + this->size;\n"
"\n"
"      do {\n"
"         %s_clear(&ptr->object);\n"
"      } while(++ptr < ptr_end);\n"
"   }\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
printf(
"\n"
"   if (this->size != 0) {\n"
"      cfree(this->data);\n"
"   }\n"
"\n"
"   this->data = n_data;\n"
"   this->size = a_size;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_GET_IDX(LIST_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
printf(
"unsigned %s_get_idx(%s *this,%s a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
printf(
"unsigned %s_get_idx(%s *this,%s *a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
printf(
"{/*{{{*/\n"
"   if (this->first_idx == c_idx_not_exist) return c_idx_not_exist;\n"
"\n"
"   unsigned idx = this->first_idx;\n"
"   do {\n"
"      %s_element *element = this->data + idx;\n"
"\n"
,IM_STRUCT_NAME);
   if (TYPE_NUMBER & c_type_basic) {
printf(
"      if (element->object == a_value) {\n"
);
   }
   else {
printf(
"      if (%s_compare(&element->object,a_value)) {\n"
,TYPE_NAME);
   }
printf(
"         return idx;\n"
"      }\n"
"\n"
"      idx = element->next_idx;\n"
"   } while(idx != c_idx_not_exist);\n"
"\n"
"   return c_idx_not_exist;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_OPERATOR_EQUAL(LIST_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_dynamic)) {
printf(
"static inline void %s_copy(%s *this,%s *a_src)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
   else {
printf(
"void %s_copy(%s *this,%s *a_src)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
printf(
"{/*{{{*/\n"
"   %s_clear(this);\n"
"\n"
"   if (a_src->used == 0) return;\n"
"\n"
"   %s_copy_resize(this,a_src->used);\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (!(TYPE_NUMBER & c_type_dynamic)) {
printf(
"   memcpy(this->data,a_src->data,a_src->used*sizeof(%s_element));\n"
,IM_STRUCT_NAME);
   }
   else {
printf(
"\n"
"   %s_element *ptr = this->data;\n"
"   %s_element *s_ptr = a_src->data;\n"
"   %s_element *s_ptr_end = s_ptr + a_src->used;\n"
"\n"
"   do {\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (TYPE_NUMBER & c_type_basic) {
printf(
"      ptr->object = s_ptr->object;\n"
);
   }
   else {
printf(
"      %s_copy(&ptr->object,&s_ptr->object);\n"
,TYPE_NAME);
   }
printf(
"      ptr->next_idx = s_ptr->next_idx;\n"
"      ptr->prev_idx = s_ptr->prev_idx;\n"
"   } while(++ptr,++s_ptr < s_ptr_end);\n"
);
   }
printf(
"\n"
"   this->used = a_src->used;\n"
"   this->free_idx = a_src->free_idx;\n"
"   this->first_idx = a_src->first_idx;\n"
"   this->last_idx = a_src->last_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_OPERATOR_DOUBLE_EQUAL(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"int %s_compare(%s *this,%s *a_second)\n"
"{/*{{{*/\n"
"   if (this->first_idx == c_idx_not_exist) {\n"
"      return a_second->first_idx == c_idx_not_exist;\n"
"   }\n"
"\n"
"   if (a_second->first_idx == c_idx_not_exist) {\n"
"      return 0;\n"
"   }\n"
"\n"
"   unsigned idx = this->first_idx;\n"
"   unsigned s_idx = a_second->first_idx;\n"
"\n"
"   do {\n"
"      %s_element *element = this->data + idx;\n"
"      %s_element *s_element = a_second->data + s_idx;\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (TYPE_NUMBER & c_type_basic) {
printf(
"      if (element->object != s_element->object) {\n"
);
   }
   else {
printf(
"      if (!%s_compare(&element->object,&s_element->object)) {\n"
,TYPE_NAME);
   }
printf(
"         return 0;\n"
"      }\n"
"\n"
"      idx = element->next_idx;\n"
"      s_idx = s_element->next_idx;\n"
"\n"
"   } while(idx != c_idx_not_exist || s_idx != c_idx_not_exist);\n"
"\n"
"   return idx == s_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_TO_STRING(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"#if OPTION_TO_STRING == ENABLED\n"
"void %s_to_string(%s *this,bc_array_s *a_trg)\n"
"{/*{{{*/\n"
"   bc_array_s_push(a_trg,'[');\n"
"\n"
"   if (this->first_idx != c_idx_not_exist) {\n"
"      unsigned idx = this->first_idx;\n"
"\n"
"      do {\n"
"         %s_element *element = this->data + idx;\n"
"         %s_to_string(&element->object,a_trg);\n"
"\n"
"         if ((idx = element->next_idx) == c_idx_not_exist)\n"
"            break;\n"
"\n"
"         bc_array_s_push(a_trg,',');\n"
"      } while(1);\n"
"   }\n"
"\n"
"   bc_array_s_push(a_trg,']');\n"
"}/*}}}*/\n"
"#endif\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
}/*}}}*/

void processor_s::generate_list_type()
{/*{{{*/
   string_array_s &type_names = cont_params.types;
   string_array_s &fun_defs = cont_params.functions;
   string_array_s &abbs = cont_params.names;

   if (type_names.used != 1) {
      fprintf(stderr,"list: not given name (or too many names) of contained type\n");
      cassert(0);
   }

   if (abbs.used < 1) {
      fprintf(stderr,"list: not given name of generated structure\n");
      cassert(0);
   }

   unsigned type_abb_idx = abbreviations.get_idx_by_name(type_names[0].size - 1,type_names[0].data);
   if (type_abb_idx == c_idx_not_exist) {
      fprintf(stderr,"list: contained type \"%s\" does not exist\n",type_names[0].data);
      cassert(0);
   }

   unsigned type_idx = abbreviations[type_abb_idx].data_type_idx;
   data_type_s &type = data_types[type_idx];

   // - test type options -
   if (type.properties & c_type_option_strict_dynamic) {
      fprintf(stderr,"list: container have not implemented processing of types with option strict_dynamic\n");
      cassert(0);
   }

   string_s real_name;
   real_name.init();
   real_name.conc_set(type.name.size - 1,type.name.data,strlen(c_cont_postfixes[c_cont_list]),(char *)c_cont_postfixes[c_cont_list]);

   string_s &data_type_name = abbs[0];

   unsigned data_type_idx;

   if ((data_type_idx = abbreviations.get_idx_by_name(data_type_name.size - 1,data_type_name.data)) == c_idx_not_exist) {

      unsigned d_idx = data_types.get_idx_by_real_name(real_name.size - 1,real_name.data);
      if (d_idx != c_idx_not_exist) {
         fprintf(stderr,"DUPLICATE STRUCTURES: %s <-> %s\n",data_type_name.data,data_types[d_idx].name.data);
      }

      data_types.push_blank();
      data_type_s &data_type = data_types.last();

      data_type.cont_idx = c_cont_list;
      data_type.name.set(data_type_name.size - 1,data_type_name.data);
      data_type.real_name.swap(real_name);

      data_type.properties = c_type_dynamic | c_type_flushable  | (type_settings & c_type_option_mask);
      data_type.types.push(abbreviations[type_abb_idx].name);

      data_type_idx = data_types.used - 1;
   }
   else {
      fprintf(stderr,"list: name of generated structure \"%s\" is already used\n",data_type_name.data);
      cassert(0);
   }

   real_name.clear();

   // - check and write abbreviations -
   if (abbs.used != 0) {
      unsigned idx = 0;
      do {
         string_s &abb = abbs[idx];

         if (abbreviations.get_idx_by_name(abb.size - 1,abb.data) != c_idx_not_exist) {
            fprintf(stderr,"list: abreviated name \"%s\" for generated structure is already used\n",abb.data);
            cassert(0);
         }

         abbreviations.push_blank();
         abbreviations.last().set(abb,data_type_idx);
      } while(++idx < abbs.used);
   }

   data_type_s &data_type = data_types[data_type_idx];

   // - definition of structure list -

printf(
"// struct %s definition\n"
"\n"
"typedef struct %s_element %s_element;\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);

    unsigned idx = 0;
    do {
printf(
"typedef struct %s %s;\n"
,abbs[0].data,abbs[idx].data);
    } while(++idx < abbs.used);
printf(
"\n"
);

printf(
"struct %s_element\n"
"{\n"
"   %s object;\n"
"   unsigned next_idx;\n"
"   unsigned prev_idx;\n"
"};\n"
"\n"
"struct %s\n"
"{\n"
"   unsigned size; //!< actual size of allocated space (element count)\n"
"   unsigned used; //!< used part of allocated space\n"
"   %s_element *data; //!< pointer to list elements\n"
"   unsigned free_idx; //!< index of first free element\n"
"   unsigned first_idx; //!< index of first element\n"
"   unsigned last_idx; //!< index of last element\n"
"};\n"
"\n"
,STRUCT_NAME,TYPE_NAME,STRUCT_NAME,STRUCT_NAME);
   if (!(data_type.properties & c_type_option_nogen_init)) {
printf(
"static inline void %s_init(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
printf(
"static inline void %s_init_size(%s *this,unsigned a_size);\n"
,STRUCT_NAME,STRUCT_NAME);
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(data_type.properties & c_type_option_nogen_clear)) {
printf(
"static inline void %s_clear(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
      }
   }
   else {
      if (!(data_type.properties & c_type_option_nogen_clear)) {
printf(
"void %s_clear(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
      }
   }
printf(
"static inline void %s_flush(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   if (!(TYPE_NUMBER & c_type_flushable)) {
printf(
"static inline void %s_flush_all(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
   else {
printf(
"void %s_flush_all(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
   if (!(data_type.properties & c_type_option_nogen_swap)) {
printf(
"static inline void %s_swap(%s *this,%s *a_second);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   }
printf(
"static inline %s *%s_at(%s *this,unsigned a_idx);\n"
,TYPE_NAME,STRUCT_NAME,STRUCT_NAME);
   if (TYPE_NUMBER & c_type_basic) {
printf(
"static inline unsigned %s_prepend(%s *this,%s a_value);\n"
"static inline unsigned %s_append(%s *this,%s a_value);\n"
"static inline unsigned %s_insert_before(%s *this,unsigned a_idx,%s a_value);\n"
"static inline unsigned %s_insert_after(%s *this,unsigned a_idx,%s a_value);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
   }
   else {
printf(
"static inline unsigned %s_prepend(%s *this,%s *a_value);\n"
"static inline unsigned %s_append(%s *this,%s *a_value);\n"
"static inline unsigned %s_insert_before(%s *this,unsigned a_idx,%s *a_value);\n"
"static inline unsigned %s_insert_after(%s *this,unsigned a_idx,%s *a_value);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
   }
printf(
"static inline unsigned %s_prepend_blank(%s *this);\n"
"static inline unsigned %s_append_blank(%s *this);\n"
"static inline unsigned %s_insert_blank_before(%s *this,unsigned a_idx);\n"
"static inline unsigned %s_insert_blank_after(%s *this,unsigned a_idx);\n"
,STRUCT_NAME,STRUCT_NAME
,STRUCT_NAME,STRUCT_NAME
,STRUCT_NAME,STRUCT_NAME
,STRUCT_NAME,STRUCT_NAME);
printf(
"static inline void %s_remove(%s *this,unsigned a_idx);\n"
"static inline unsigned %s_next_idx(%s *this,unsigned a_idx);\n"
"static inline unsigned %s_prev_idx(%s *this,unsigned a_idx);\n"
"void %s_copy_resize(%s *this,unsigned a_size);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
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
   if (!(data_type.properties & c_type_option_nogen_copy)) {
      if (!(TYPE_NUMBER & c_type_dynamic)) {
printf(
"static inline void %s_copy(%s *this,%s *a_src);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
      }
      else {
printf(
"void %s_copy(%s *this,%s *a_src);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
      }
   }
printf(
"int %s_compare(%s *this,%s *a_second);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
printf(
"#if OPTION_TO_STRING == ENABLED\n"
"void %s_to_string(%s *this,bc_array_s *a_trg);\n"
"#endif\n"
,STRUCT_NAME,STRUCT_NAME);
   if (fun_defs.used != 0) {
      unsigned f_idx = 0;
      do {
printf(
"%s\n"
,fun_defs[f_idx].data);
      } while(++f_idx < fun_defs.used);
   }
printf(
"\n"
);
}/*}}}*/

void processor_s::generate_list_inlines(unsigned abb_idx,unsigned a_dt_idx)
{/*{{{*/
   data_type_s &data_type = data_types[a_dt_idx];

   string_s &type_abb_string = data_type.types[0];
   unsigned type_abb_idx = abbreviations.get_idx_by_name(type_abb_string.size - 1,type_abb_string.data);

   if (type_abb_idx == c_idx_not_exist) {
      fprintf(stderr,"list: inlines: abbreviated type name \"%s\" does not exist\n",type_abb_string.data);
      cassert(0);
   }

   unsigned type_idx = abbreviations[type_abb_idx].data_type_idx;
   data_type_s &type = data_types[type_idx];

   // --- definition of inline methods ---

printf(
"// --- struct %s inline method definition ---\n"
"\n"
,IM_STRUCT_NAME);

   // - list init method -
   if (!(data_type.properties & c_type_option_nogen_init)) {
LIST_INIT(LIST_GEN_VALUES);
   }

   // - list init_size method -
LIST_INIT_SIZE(LIST_GEN_VALUES);

   // - list clear method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(data_type.properties & c_type_option_nogen_clear)) {
LIST_CLEAR(LIST_GEN_VALUES);
      }
   }

   // - list flush method -
LIST_FLUSH(LIST_GEN_VALUES);

   // - list flush_all method -
   if (!(TYPE_NUMBER & c_type_flushable)) {
LIST_FLUSH_ALL(LIST_GEN_VALUES);
   }

   // - list swap method -
   if (!(data_type.properties & c_type_option_nogen_swap)) {
LIST_SWAP(LIST_GEN_VALUES);
   }

   // - list operator[] method -
LIST_OPERATOR_LE_BR_RE_BR(LIST_GEN_VALUES);

   // - list prepend method -
LIST_PREPEND(LIST_GEN_VALUES);

   // - list append method -
LIST_APPEND(LIST_GEN_VALUES);

   // - list insert_before method -
LIST_INSERT_BEFORE(LIST_GEN_VALUES);

   // - list insert_after method -
LIST_INSERT_AFTER(LIST_GEN_VALUES);

   // - list prepend_blank method -
LIST_PREPEND_BLANK(LIST_GEN_VALUES);

   // - list append_blank method -
LIST_APPEND_BLANK(LIST_GEN_VALUES);

   // - list insert_blank_before method -
LIST_INSERT_BLANK_BEFORE(LIST_GEN_VALUES);

   // - list insert_blank_after method -
LIST_INSERT_BLANK_AFTER(LIST_GEN_VALUES);

   // - list remove method -
LIST_REMOVE(LIST_GEN_VALUES);

   // - list next_idx method -
LIST_NEXT_IDX(LIST_GEN_VALUES);

   // - list prev_idx method -
LIST_PREV_IDX(LIST_GEN_VALUES);

   // - list copy_resize method -

   // - list get_idx method -

   // - list operator= method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(data_type.properties & c_type_option_nogen_copy)) {
LIST_OPERATOR_EQUAL(LIST_GEN_VALUES);
      }
   }

   // - list operator== method -

   // - list to_string method -

}/*}}}*/

void processor_s::generate_list_methods(unsigned abb_idx,unsigned a_dt_idx)
{/*{{{*/
   data_type_s &data_type = data_types[a_dt_idx];

   string_s &type_abb_string = data_type.types[0];
   unsigned type_abb_idx = abbreviations.get_idx_by_name(type_abb_string.size - 1,type_abb_string.data);

   if (type_abb_idx == c_idx_not_exist) {
      fprintf(stderr,"list: methods: abreviated type name \"%s\" does not exist\n",type_abb_string.data);
      cassert(0);
   }

   unsigned type_idx = abbreviations[type_abb_idx].data_type_idx;
   data_type_s &type = data_types[type_idx];

   // --- definition of methods ---

printf(
"// --- struct %s method definition ---\n"
"\n"
,IM_STRUCT_NAME);

   // - list init method -

   // - list init_size method -

   // - list clear method -
   if (TYPE_NUMBER & c_type_dynamic) {
      if (!(data_type.properties & c_type_option_nogen_clear)) {
LIST_CLEAR(LIST_GEN_VALUES);
      }
   }

   // - list flush method -

   // - list flush_all method -
   if (TYPE_NUMBER & c_type_flushable) {
LIST_FLUSH_ALL(LIST_GEN_VALUES);
   }

   // - list swap method -

   // - list operator[] method -

   // - list prepend method -

   // - list append method -

   // - list insert_before method -

   // - list insert_after method -

   // - list prepend_blank method -

   // - list append_blank method -

   // - list insert_blank_before method -

   // - list insert_blank_after method -

   // - list remove method -

   // - list next_idx method -

   // - list prev_idx method -

   // - list copy_resize method -
LIST_COPY_RESIZE(LIST_GEN_VALUES);

   // - list get_idx method -
LIST_GET_IDX(LIST_GEN_VALUES);

   // - list operator= method -
   if (TYPE_NUMBER & c_type_dynamic) {
      if (!(data_type.properties & c_type_option_nogen_copy)) {
LIST_OPERATOR_EQUAL(LIST_GEN_VALUES);
      }
   }

   // - list operator== method -
LIST_OPERATOR_DOUBLE_EQUAL(LIST_GEN_VALUES);

   // - list to_string method -
LIST_TO_STRING(LIST_GEN_VALUES);

}/*}}}*/


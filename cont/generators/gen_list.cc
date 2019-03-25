
#define LIST_GEN_PARAMS FILE *out_file,abbreviation_array_s &abbreviations,unsigned abb_idx,unsigned type_abb_idx,data_type_s &type,data_type_s &data_type
#define LIST_GEN_VALUES out_file,abbreviations,abb_idx,type_abb_idx,type,data_type

void LIST_INIT(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline void %s_init(%s *this)\n"
"{/*{{{*/\n"
"  this->size = 0;\n"
"  this->used = 0;\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  this->count = 0;\n"
);
   }
fprintf(out_file,
"  this->data = NULL;\n"
"  this->free_idx = c_idx_not_exist;\n"
"  this->first_idx = c_idx_not_exist;\n"
"  this->last_idx = c_idx_not_exist;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_INIT_SIZE(LIST_GEN_PARAMS)
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

void LIST_INIT_BUFFER(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline void %s_init_buffer(%s *this,unsigned a_size,%s_element *a_data)\n"
"{/*{{{*/\n"
"  %s_init(this);\n"
"  %s_set_buffer(this,a_size,a_data);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void LIST_CLEAR(LIST_GEN_PARAMS)
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
"    %s_element *ptr = this->data;\n"
"    %s_element *ptr_end = ptr + this->size;\n"
"\n"
"    do {\n"
"      %s_clear(&ptr->object);\n"
"    } while(++ptr < ptr_end);\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
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
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  this->count = 0;\n"
);
   }
fprintf(out_file,
"  this->free_idx = c_idx_not_exist;\n"
"  this->first_idx = c_idx_not_exist;\n"
"  this->last_idx = c_idx_not_exist;\n"
);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_SET_BUFFER(LIST_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"static inline void %s_set_buffer(%s *this,unsigned a_size,%s_element *a_data)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"void %s_set_buffer(%s *this,unsigned a_size,%s_element *a_data)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
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
"  %s_element *ptr = this->data + this->size;\n"
"  %s_element *ptr_end = this->data + a_size;\n"
"\n"
"  do {\n"
"    %s_init(&ptr->object);\n"
"  } while(++ptr < ptr_end);\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"\n"
"  this->size = a_size;\n"
"  this->data = a_data;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_FLUSH(LIST_GEN_PARAMS)
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

void LIST_FLUSH_ALL(LIST_GEN_PARAMS)
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
"  %s_element *ptr = this->data;\n"
"  %s_element *ptr_end = ptr + this->used;\n"
"\n"
"  do {\n"
"    %s_flush_all(&ptr->object);\n"
"  } while(++ptr < ptr_end);\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_SWAP(LIST_GEN_PARAMS)
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

void LIST_OPERATOR_LE_BR_RE_BR(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline %s *%s_at(const %s *this,unsigned a_idx)\n"
"{/*{{{*/\n"
,TYPE_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  debug_assert(a_idx < this->used && this->data[a_idx].valid);\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert(a_idx < this->used);\n"
);
   }
fprintf(out_file,
"  return &this->data[a_idx].object;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_PREPEND(LIST_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"static inline unsigned %s_prepend(%s *this,%s a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"static inline unsigned %s_prepend(%s *this,const %s *a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
"  unsigned new_idx;\n"
"\n"
"  if (this->free_idx != c_idx_not_exist)\n"
"  {\n"
"    new_idx = this->free_idx;\n"
"    this->free_idx = this->data[new_idx].next_idx;\n"
"  }\n"
"  else\n"
"  {\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"    if (this->used >= this->size)\n"
"    {\n"
"      unsigned new_size = (this->size << 1) + c_array_add;\n"
"      debug_assert(new_size != 0);\n"
"\n"
"      %s_copy_resize(this,new_size);\n"
"    }\n"
"\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"    debug_assert(this->used < this->size);\n"
);
   }
fprintf(out_file,
"    new_idx = this->used++;\n"
"  }\n"
"\n"
"  %s_element *new_element = this->data + new_idx;\n"
"\n"
,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  new_element->valid = 1;\n"
);
   }
fprintf(out_file,
"  new_element->next_idx = this->first_idx;\n"
"  new_element->prev_idx = c_idx_not_exist;\n"
"\n"
"  if (this->first_idx != c_idx_not_exist)\n"
"  {\n"
"    this->data[this->first_idx].prev_idx = new_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    this->last_idx = new_idx;\n"
"  }\n"
"\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  this->count++;\n"
);
   }
fprintf(out_file,
"  this->first_idx = new_idx;\n"
"\n"
);
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"  new_element->object = a_value;\n"
);
   }
   else if (TYPE_NUMBER & c_type_static) {
fprintf(out_file,
"  new_element->object = *a_value;\n"
);
   }
   else {
fprintf(out_file,
"  %s_copy(&new_element->object,a_value);\n"
,TYPE_NAME);
   }
fprintf(out_file,
"\n"
"  return new_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_APPEND(LIST_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"static inline unsigned %s_append(%s *this,%s a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"static inline unsigned %s_append(%s *this,const %s *a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
"  unsigned new_idx;\n"
"\n"
"  if (this->free_idx != c_idx_not_exist)\n"
"  {\n"
"    new_idx = this->free_idx;\n"
"    this->free_idx = this->data[new_idx].next_idx;\n"
"  }\n"
"  else\n"
"  {\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"    if (this->used >= this->size)\n"
"    {\n"
"      unsigned new_size = (this->size << 1) + c_array_add;\n"
"      debug_assert(new_size != 0);\n"
"\n"
"      %s_copy_resize(this,new_size);\n"
"    }\n"
"\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"    debug_assert(this->used < this->size);\n"
);
   }
fprintf(out_file,
"    new_idx = this->used++;\n"
"  }\n"
"\n"
"  %s_element *new_element = this->data + new_idx;\n"
"\n"
,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  new_element->valid = 1;\n"
);
   }
fprintf(out_file,
"  new_element->next_idx = c_idx_not_exist;\n"
"  new_element->prev_idx = this->last_idx;\n"
"\n"
"  if (this->last_idx != c_idx_not_exist)\n"
"  {\n"
"    this->data[this->last_idx].next_idx = new_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    this->first_idx = new_idx;\n"
"  }\n"
"\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  this->count++;\n"
);
   }
fprintf(out_file,
"  this->last_idx = new_idx;\n"
"\n"
);
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"  new_element->object = a_value;\n"
);
   }
   else if (TYPE_NUMBER & c_type_static) {
fprintf(out_file,
"  new_element->object = *a_value;\n"
);
   }
   else {
fprintf(out_file,
"  %s_copy(&new_element->object,a_value);\n"
,TYPE_NAME);
   }
fprintf(out_file,
"\n"
"  return new_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_INSERT_BEFORE(LIST_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"static inline unsigned %s_insert_before(%s *this,unsigned a_idx,%s a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"static inline unsigned %s_insert_before(%s *this,unsigned a_idx,const %s *a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  debug_assert(a_idx < this->used && this->data[a_idx].valid);\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert(a_idx < this->used);\n"
);
   }
fprintf(out_file,
"\n"
"  unsigned new_idx;\n"
"\n"
"  if (this->free_idx != c_idx_not_exist)\n"
"  {\n"
"    new_idx = this->free_idx;\n"
"    this->free_idx = this->data[new_idx].next_idx;\n"
"  }\n"
"  else\n"
"  {\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"    if (this->used >= this->size)\n"
"    {\n"
"      unsigned new_size = (this->size << 1) + c_array_add;\n"
"      debug_assert(new_size != 0);\n"
"\n"
"      %s_copy_resize(this,new_size);\n"
"    }\n"
"\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"    debug_assert(this->used < this->size);\n"
);
   }
fprintf(out_file,
"    new_idx = this->used++;\n"
"  }\n"
"\n"
"  %s_element *idx_element = this->data + a_idx;\n"
"  %s_element *new_element = this->data + new_idx;\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  new_element->valid = 1;\n"
);
   }
fprintf(out_file,
"  new_element->next_idx = a_idx;\n"
"  new_element->prev_idx = idx_element->prev_idx;\n"
"\n"
"  if (idx_element->prev_idx != c_idx_not_exist)\n"
"  {\n"
"    this->data[idx_element->prev_idx].next_idx = new_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    this->first_idx = new_idx;\n"
"  }\n"
"\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  this->count++;\n"
);
   }
fprintf(out_file,
"  idx_element->prev_idx = new_idx;\n"
"\n"
);
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"  new_element->object = a_value;\n"
);
   }
   else if (TYPE_NUMBER & c_type_static) {
fprintf(out_file,
"  new_element->object = *a_value;\n"
);
   }
   else {
fprintf(out_file,
"  %s_copy(&new_element->object,a_value);\n"
,TYPE_NAME);
   }
fprintf(out_file,
"\n"
"  return new_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_INSERT_AFTER(LIST_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"static inline unsigned %s_insert_after(%s *this,unsigned a_idx,%s a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"static inline unsigned %s_insert_after(%s *this,unsigned a_idx,const %s *a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  debug_assert(a_idx < this->used && this->data[a_idx].valid);\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert(a_idx < this->used);\n"
);
   }
fprintf(out_file,
"\n"
"  unsigned new_idx;\n"
"\n"
"  if (this->free_idx != c_idx_not_exist)\n"
"  {\n"
"    new_idx = this->free_idx;\n"
"    this->free_idx = this->data[new_idx].next_idx;\n"
"  }\n"
"  else\n"
"  {\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"    if (this->used >= this->size)\n"
"    {\n"
"      unsigned new_size = (this->size << 1) + c_array_add;\n"
"      debug_assert(new_size != 0);\n"
"\n"
"      %s_copy_resize(this,new_size);\n"
"    }\n"
"\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"    debug_assert(this->used < this->size);\n"
);
   }
fprintf(out_file,
"    new_idx = this->used++;\n"
"  }\n"
"\n"
"  %s_element *idx_element = this->data + a_idx;\n"
"  %s_element *new_element = this->data + new_idx;\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  new_element->valid = 1;\n"
);
   }
fprintf(out_file,
"  new_element->next_idx = idx_element->next_idx;\n"
"  new_element->prev_idx = a_idx;\n"
"\n"
"  if (idx_element->next_idx != c_idx_not_exist)\n"
"  {\n"
"    this->data[idx_element->next_idx].prev_idx = new_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    this->last_idx = new_idx;\n"
"  }\n"
"\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  this->count++;\n"
);
   }
fprintf(out_file,
"  idx_element->next_idx = new_idx;\n"
"\n"
);
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"  new_element->object = a_value;\n"
);
   }
   else if (TYPE_NUMBER & c_type_static) {
fprintf(out_file,
"  new_element->object = *a_value;\n"
);
   }
   else {
fprintf(out_file,
"  %s_copy(&new_element->object,a_value);\n"
,TYPE_NAME);
   }
fprintf(out_file,
"\n"
"  return new_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_PREPEND_BLANK(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline unsigned %s_prepend_blank(%s *this)\n"
"{/*{{{*/\n"
"  unsigned new_idx;\n"
"\n"
"  if (this->free_idx != c_idx_not_exist)\n"
"  {\n"
"    new_idx = this->free_idx;\n"
"    this->free_idx = this->data[new_idx].next_idx;\n"
"  }\n"
"  else\n"
"  {\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"    if (this->used >= this->size)\n"
"    {\n"
"      unsigned new_size = (this->size << 1) + c_array_add;\n"
"      debug_assert(new_size != 0);\n"
"\n"
"      %s_copy_resize(this,new_size);\n"
"    }\n"
"\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"    debug_assert(this->used < this->size);\n"
);
   }
fprintf(out_file,
"    new_idx = this->used++;\n"
"  }\n"
"\n"
"  %s_element *new_element = this->data + new_idx;\n"
"\n"
,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  new_element->valid = 1;\n"
);
   }
fprintf(out_file,
"  new_element->next_idx = this->first_idx;\n"
"  new_element->prev_idx = c_idx_not_exist;\n"
"\n"
"  if (this->first_idx != c_idx_not_exist)\n"
"  {\n"
"    this->data[this->first_idx].prev_idx = new_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    this->last_idx = new_idx;\n"
"  }\n"
"\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  this->count++;\n"
);
   }
fprintf(out_file,
"  this->first_idx = new_idx;\n"
"\n"
"  return new_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_APPEND_BLANK(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline unsigned %s_append_blank(%s *this)\n"
"{/*{{{*/\n"
"  unsigned new_idx;\n"
"\n"
"  if (this->free_idx != c_idx_not_exist)\n"
"  {\n"
"    new_idx = this->free_idx;\n"
"    this->free_idx = this->data[new_idx].next_idx;\n"
"  }\n"
"  else\n"
"  {\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"    if (this->used >= this->size)\n"
"    {\n"
"      unsigned new_size = (this->size << 1) + c_array_add;\n"
"      debug_assert(new_size != 0);\n"
"\n"
"      %s_copy_resize(this,new_size);\n"
"    }\n"
"\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"    debug_assert(this->used < this->size);\n"
);
   }
fprintf(out_file,
"    new_idx = this->used++;\n"
"  }\n"
"\n"
"  %s_element *new_element = this->data + new_idx;\n"
"\n"
,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  new_element->valid = 1;\n"
);
   }
fprintf(out_file,
"  new_element->next_idx = c_idx_not_exist;\n"
"  new_element->prev_idx = this->last_idx;\n"
"\n"
"  if (this->last_idx != c_idx_not_exist)\n"
"  {\n"
"    this->data[this->last_idx].next_idx = new_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    this->first_idx = new_idx;\n"
"  }\n"
"\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  this->count++;\n"
);
   }
fprintf(out_file,
"  this->last_idx = new_idx;\n"
"\n"
"  return new_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_INSERT_BLANK_BEFORE(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline unsigned %s_insert_blank_before(%s *this,unsigned a_idx)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  debug_assert(a_idx < this->used && this->data[a_idx].valid);\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert(a_idx < this->used);\n"
);
   }
fprintf(out_file,
"\n"
"  unsigned new_idx;\n"
"\n"
"  if (this->free_idx != c_idx_not_exist)\n"
"  {\n"
"    new_idx = this->free_idx;\n"
"    this->free_idx = this->data[new_idx].next_idx;\n"
"  }\n"
"  else\n"
"  {\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"    if (this->used >= this->size)\n"
"    {\n"
"      unsigned new_size = (this->size << 1) + c_array_add;\n"
"      debug_assert(new_size != 0);\n"
"\n"
"      %s_copy_resize(this,new_size);\n"
"    }\n"
"\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"    debug_assert(this->used < this->size);\n"
);
   }
fprintf(out_file,
"    new_idx = this->used++;\n"
"  }\n"
"\n"
"  %s_element *idx_element = this->data + a_idx;\n"
"  %s_element *new_element = this->data + new_idx;\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  new_element->valid = 1;\n"
);
   }
fprintf(out_file,
"  new_element->next_idx = a_idx;\n"
"  new_element->prev_idx = idx_element->prev_idx;\n"
"\n"
"  if (idx_element->prev_idx != c_idx_not_exist)\n"
"  {\n"
"    this->data[idx_element->prev_idx].next_idx = new_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    this->first_idx = new_idx;\n"
"  }\n"
"\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  this->count++;\n"
);
   }
fprintf(out_file,
"  idx_element->prev_idx = new_idx;\n"
"\n"
"  return new_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_INSERT_BLANK_AFTER(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline unsigned %s_insert_blank_after(%s *this,unsigned a_idx)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  debug_assert(a_idx < this->used && this->data[a_idx].valid);\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert(a_idx < this->used);\n"
);
   }
fprintf(out_file,
"\n"
"  unsigned new_idx;\n"
"\n"
"  if (this->free_idx != c_idx_not_exist)\n"
"  {\n"
"    new_idx = this->free_idx;\n"
"    this->free_idx = this->data[new_idx].next_idx;\n"
"  }\n"
"  else\n"
"  {\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"    if (this->used >= this->size)\n"
"    {\n"
"      unsigned new_size = (this->size << 1) + c_array_add;\n"
"      debug_assert(new_size != 0);\n"
"\n"
"      %s_copy_resize(this,new_size);\n"
"    }\n"
"\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"    debug_assert(this->used < this->size);\n"
);
   }
fprintf(out_file,
"    new_idx = this->used++;\n"
"  }\n"
"\n"
"  %s_element *idx_element = this->data + a_idx;\n"
"  %s_element *new_element = this->data + new_idx;\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  new_element->valid = 1;\n"
);
   }
fprintf(out_file,
"  new_element->next_idx = idx_element->next_idx;\n"
"  new_element->prev_idx = a_idx;\n"
"\n"
"  if (idx_element->next_idx != c_idx_not_exist)\n"
"  {\n"
"    this->data[idx_element->next_idx].prev_idx = new_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    this->last_idx = new_idx;\n"
"  }\n"
"\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  this->count++;\n"
);
   }
fprintf(out_file,
"  idx_element->next_idx = new_idx;\n"
"\n"
"  return new_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_REMOVE(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline void %s_remove(%s *this,unsigned a_idx)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  debug_assert(a_idx < this->used && this->data[a_idx].valid);\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert(a_idx < this->used);\n"
);
   }
fprintf(out_file,
"\n"
"  %s_element *rm_element = this->data + a_idx;\n"
"\n"
"  if (rm_element->next_idx != c_idx_not_exist)\n"
"  {\n"
"    this->data[rm_element->next_idx].prev_idx = rm_element->prev_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    this->last_idx = rm_element->prev_idx;\n"
"  }\n"
"\n"
"  if (rm_element->prev_idx != c_idx_not_exist)\n"
"  {\n"
"    this->data[rm_element->prev_idx].next_idx = rm_element->next_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    this->first_idx = rm_element->next_idx;\n"
"  }\n"
"\n"
,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  rm_element->valid = 0;\n"
"  rm_element->next_idx = this->free_idx;\n"
"\n"
"  this->count--;\n"
);
   }
   else {
fprintf(out_file,
"  rm_element->next_idx = this->free_idx;\n"
);
   }
fprintf(out_file,
"  this->free_idx = a_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_NEXT_IDX(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline unsigned %s_next_idx(const %s *this,unsigned a_idx)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  debug_assert(this->data[a_idx].valid);\n"
);
   }
fprintf(out_file,
"  return this->data[a_idx].next_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_PREV_IDX(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline unsigned %s_prev_idx(const %s *this,unsigned a_idx)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  debug_assert(this->data[a_idx].valid);\n"
);
   }
fprintf(out_file,
"  return this->data[a_idx].prev_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_COPY_RESIZE(LIST_GEN_PARAMS)
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
"    %s_element *ptr = this->data + a_size;\n"
"    %s_element *ptr_end = this->data + this->size;\n"
"\n"
"    do {\n"
"      %s_clear(&ptr->object);\n"
"    } while(++ptr < ptr_end);\n"
"  }\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
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
"    this->data = (%s_element *)crealloc(this->data,a_size*sizeof(%s_element));\n"
"  }\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"\n"
"  if (a_size > this->size)\n"
"  {\n"
"    %s_element *ptr = this->data + this->size;\n"
"    %s_element *ptr_end = this->data + a_size;\n"
"\n"
"    do {\n"
"      %s_init(&ptr->object);\n"
"    } while(++ptr < ptr_end);\n"
"  }\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"\n"
"  this->size = a_size;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_GET_IDX(LIST_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"unsigned %s_get_idx(const %s *this,%s a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"unsigned %s_get_idx(const %s *this,const %s *a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
"  if (this->first_idx == c_idx_not_exist)\n"
"  {\n"
"    return c_idx_not_exist;\n"
"  }\n"
"\n"
"  unsigned idx = this->first_idx;\n"
"  do {\n"
"    %s_element *element = this->data + idx;\n"
"\n"
,IM_STRUCT_NAME);
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"    if (element->object == a_value)\n"
"    {\n"
);
   }
   else {
fprintf(out_file,
"    if (%s_compare(&element->object,a_value))\n"
"    {\n"
,TYPE_NAME);
   }
fprintf(out_file,
"      return idx;\n"
"    }\n"
"\n"
"    idx = element->next_idx;\n"
"  } while(idx != c_idx_not_exist);\n"
"\n"
"  return c_idx_not_exist;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_OPERATOR_EQUAL(LIST_GEN_PARAMS)
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
"  memcpy(this->data,a_src->data,a_src->used*sizeof(%s_element));\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"\n"
"  %s_element *ptr = this->data;\n"
"  %s_element *s_ptr = a_src->data;\n"
"  %s_element *s_ptr_end = s_ptr + a_src->used;\n"
"\n"
"  do {\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"    ptr->object = s_ptr->object;\n"
);
   }
   else {
fprintf(out_file,
"    %s_copy(&ptr->object,&s_ptr->object);\n"
,TYPE_NAME);
   }
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"    ptr->valid = s_ptr->valid;\n"
);
   }
fprintf(out_file,
"    ptr->next_idx = s_ptr->next_idx;\n"
"    ptr->prev_idx = s_ptr->prev_idx;\n"
"  } while(++ptr,++s_ptr < s_ptr_end);\n"
);
   }
fprintf(out_file,
"\n"
"  this->used = a_src->used;\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  this->count = a_src->count;\n"
);
   }
fprintf(out_file,
"  this->free_idx = a_src->free_idx;\n"
"  this->first_idx = a_src->first_idx;\n"
"  this->last_idx = a_src->last_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_OPERATOR_DOUBLE_EQUAL(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"int %s_compare(const %s *this,const %s *a_second)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  if (this->count != a_second->count)\n"
"  {\n"
"    return 0;\n"
"  }\n"
"\n"
);
   }
fprintf(out_file,
"  if (this->first_idx == c_idx_not_exist)\n"
"  {\n"
"    return a_second->first_idx == c_idx_not_exist;\n"
"  }\n"
"\n"
"  if (a_second->first_idx == c_idx_not_exist)\n"
"  {\n"
"    return 0;\n"
"  }\n"
"\n"
"  unsigned idx = this->first_idx;\n"
"  unsigned s_idx = a_second->first_idx;\n"
"\n"
"  do {\n"
"    %s_element *element = this->data + idx;\n"
"    %s_element *s_element = a_second->data + s_idx;\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"    if (element->object != s_element->object)\n"
"    {\n"
);
   }
   else {
fprintf(out_file,
"    if (!%s_compare(&element->object,&s_element->object))\n"
"    {\n"
,TYPE_NAME);
   }
fprintf(out_file,
"      return 0;\n"
"    }\n"
"\n"
"    idx = element->next_idx;\n"
"    s_idx = s_element->next_idx;\n"
"\n"
"  } while(idx != c_idx_not_exist || s_idx != c_idx_not_exist);\n"
"\n"
"  return idx == s_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_TO_STRING(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#if OPTION_TO_STRING == ENABLED\n"
"void %s___to_string(const %s *this,bc_array_s *a_trg)\n"
"{/*{{{*/\n"
"  bc_array_s_push(a_trg,'[');\n"
"\n"
"  if (this->first_idx != c_idx_not_exist)\n"
"  {\n"
"    unsigned idx = this->first_idx;\n"
"\n"
"    do {\n"
"      %s_element *element = this->data + idx;\n"
"      %s_to_string(&element->object,a_trg);\n"
"\n"
"      if ((idx = element->next_idx) == c_idx_not_exist)\n"
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
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
}/*}}}*/

void LIST_TO_STRING_SEPARATOR(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#if OPTION_TO_STRING == ENABLED\n"
"void %s_to_string_separator(const %s *this,bc_array_s *a_trg,unsigned a_count,const char *a_data)\n"
"{/*{{{*/\n"
"  if (this->first_idx != c_idx_not_exist)\n"
"  {\n"
"    unsigned idx = this->first_idx;\n"
"\n"
"    do {\n"
"      %s_element *element = this->data + idx;\n"
"      %s_to_string(&element->object,a_trg);\n"
"\n"
"      if ((idx = element->next_idx) == c_idx_not_exist)\n"
"      {\n"
"        break;\n"
"      }\n"
"\n"
"      bc_array_s_append(a_trg,a_count,a_data);\n"
"    } while(1);\n"
"  }\n"
"}/*}}}*/\n"
"#endif\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
}/*}}}*/

void LIST_TO_JSON(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#if OPTION_TO_JSON == ENABLED\n"
"void %s_to_json(const %s *this,bc_array_s *a_trg)\n"
"{/*{{{*/\n"
"  if (this->first_idx != c_idx_not_exist)\n"
"  {\n"
"    bc_array_s_push(a_trg,'[');\n"
"\n"
"    unsigned idx = this->first_idx;\n"
"\n"
"    do {\n"
"      %s_element *element = this->data + idx;\n"
"      %s_to_json(&element->object,a_trg);\n"
"\n"
"      if ((idx = element->next_idx) == c_idx_not_exist)\n"
"      {\n"
"        break;\n"
"      }\n"
"\n"
"      bc_array_s_push(a_trg,',');\n"
"    } while(1);\n"
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
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,TYPE_NAME);
}/*}}}*/

void LIST_TO_JSON_NICE(LIST_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#if OPTION_TO_JSON == ENABLED\n"
"void %s_to_json_nice(const %s *this,json_nice_s *a_json_nice,bc_array_s *a_trg)\n"
"{/*{{{*/\n"
"  if (this->first_idx != c_idx_not_exist)\n"
"  {\n"
"    bc_array_s_push(a_trg,'[');\n"
"    json_nice_s_push_indent(a_json_nice,a_trg);\n"
"\n"
"    unsigned idx = this->first_idx;\n"
"\n"
"    do {\n"
"      %s_element *element = this->data + idx;\n"
"      %s_to_json_nice(&element->object,a_json_nice,a_trg);\n"
"\n"
"      if ((idx = element->next_idx) == c_idx_not_exist)\n"
"      {\n"
"        break;\n"
"      }\n"
"\n"
"      bc_array_s_push(a_trg,',');\n"
"      json_nice_s_indent(a_json_nice,a_trg);\n"
"    } while(1);\n"
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
      fprintf(stderr,"list: option strict_dynamic not supported\n");
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

   if (gen_options & c_option_gen_code) {
   // - definition of structure list -

fprintf(out_file,
"// struct %s definition\n"
"\n"
"typedef struct %s_element %s_element;\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);

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
"struct %s_element\n"
"{\n"
"  %s object;\n"
,STRUCT_NAME,TYPE_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  char valid;\n"
);
   }
fprintf(out_file,
"  unsigned next_idx;\n"
"  unsigned prev_idx;\n"
"};\n"
"\n"
"struct %s\n"
"{\n"
"  unsigned size; //!< actual size of allocated space (element count)\n"
"  unsigned used; //!< used part of allocated space\n"
,STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  unsigned count; //!< count of stored elements\n"
);
   }
fprintf(out_file,
"  %s_element *data; //!< pointer to list elements\n"
"  unsigned free_idx; //!< index of first free element\n"
"  unsigned first_idx; //!< index of first element\n"
"  unsigned last_idx; //!< index of last element\n"
"};\n"
"\n"
,STRUCT_NAME);
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
"static inline void %s_init_buffer(%s *this,unsigned a_size,%s_element *a_data);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
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
"static inline void %s_set_buffer(%s *this,unsigned a_size,%s_element *a_data);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
      }
      else {
fprintf(out_file,
"EXPORT void %s_set_buffer(%s *this,unsigned a_size,%s_element *a_data);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
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
fprintf(out_file,
"static inline unsigned %s_prepend(%s *this,const %s *a_value);\n"
"static inline unsigned %s_append(%s *this,const %s *a_value);\n"
"static inline unsigned %s_insert_before(%s *this,unsigned a_idx,const %s *a_value);\n"
"static inline unsigned %s_insert_after(%s *this,unsigned a_idx,const %s *a_value);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
   }
fprintf(out_file,
"static inline unsigned %s_prepend_blank(%s *this);\n"
"static inline unsigned %s_append_blank(%s *this);\n"
"static inline unsigned %s_insert_blank_before(%s *this,unsigned a_idx);\n"
"static inline unsigned %s_insert_blank_after(%s *this,unsigned a_idx);\n"
,STRUCT_NAME,STRUCT_NAME
,STRUCT_NAME,STRUCT_NAME
,STRUCT_NAME,STRUCT_NAME
,STRUCT_NAME,STRUCT_NAME);
fprintf(out_file,
"static inline void %s_remove(%s *this,unsigned a_idx);\n"
"static inline unsigned %s_next_idx(const %s *this,unsigned a_idx);\n"
"static inline unsigned %s_prev_idx(const %s *this,unsigned a_idx);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"EXPORT void %s_copy_resize(%s *this,unsigned a_size);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"EXPORT unsigned %s_get_idx(const %s *this,%s a_value);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"EXPORT unsigned %s_get_idx(const %s *this,const %s *a_value);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
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

   if (gen_options & c_option_gen_code) {
   // --- definition of inline methods ---

fprintf(out_file,
"// --- struct %s inline method definition ---\n"
"\n"
,IM_STRUCT_NAME);

   // - list init method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_init)) {
LIST_INIT(LIST_GEN_VALUES);
   }

   // - list init_size method -
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
LIST_INIT_SIZE(LIST_GEN_VALUES);
   }

   // - list init_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
LIST_INIT_BUFFER(LIST_GEN_VALUES);
   }

   // - list clear method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
LIST_CLEAR(LIST_GEN_VALUES);
      }
   }

   // - list set_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer && !(TYPE_NUMBER & c_type_dynamic)) {
LIST_SET_BUFFER(LIST_GEN_VALUES);
   }

   // - list flush method -
LIST_FLUSH(LIST_GEN_VALUES);

   // - list flush_all method -
   if (!(TYPE_NUMBER & c_type_flushable)) {
LIST_FLUSH_ALL(LIST_GEN_VALUES);
   }

   // - list swap method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_swap)) {
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
      if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
LIST_OPERATOR_EQUAL(LIST_GEN_VALUES);
      }
   }

   // - list operator== method -

   // - list to_string method -

   // - list to_string_separator method -

   // - list to_json method -

   // - list to_json_nice method -
   }
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

   if (gen_options & c_option_gen_code) {
   // --- definition of methods ---

fprintf(out_file,
"// --- struct %s method definition ---\n"
"\n"
,IM_STRUCT_NAME);

   // - list init method -

   // - list init_size method -

   // - list init_buffer method -

   // - list clear method -
   if (TYPE_NUMBER & c_type_dynamic) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
LIST_CLEAR(LIST_GEN_VALUES);
      }
   }

   // - list set_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer && TYPE_NUMBER & c_type_dynamic) {
LIST_SET_BUFFER(LIST_GEN_VALUES);
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
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
LIST_COPY_RESIZE(LIST_GEN_VALUES);
   }

   // - list get_idx method -
LIST_GET_IDX(LIST_GEN_VALUES);

   // - list operator= method -
   if (TYPE_NUMBER & c_type_dynamic) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
LIST_OPERATOR_EQUAL(LIST_GEN_VALUES);
      }
   }

   // - list operator== method -
LIST_OPERATOR_DOUBLE_EQUAL(LIST_GEN_VALUES);

   // - list to_string method -
LIST_TO_STRING(LIST_GEN_VALUES);

   // - list to_string_separator method -
LIST_TO_STRING_SEPARATOR(LIST_GEN_VALUES);

   // - list to_json method -
   if (STRUCT_NUMBER & c_type_option_to_json) {
LIST_TO_JSON(LIST_GEN_VALUES);
   }

   // - list to_json_nice method -
   if (STRUCT_NUMBER & c_type_option_to_json_nice) {
LIST_TO_JSON_NICE(LIST_GEN_VALUES);
   }

   }
}/*}}}*/


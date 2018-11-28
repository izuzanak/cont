
#define LIST_GEN_PARAMS abbreviation_array_s &abbreviations,unsigned abb_idx,unsigned type_abb_idx,data_type_s &type,data_type_s &data_type
#define LIST_GEN_VALUES abbreviations,abb_idx,type_abb_idx,type,data_type

void LIST_INIT(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"inline void %s::init()\n"
"{/*{{{*/\n"
"  size = 0;\n"
"  used = 0;\n"
"  data = nullptr;\n"
"  free_idx = c_idx_not_exist;\n"
"  first_idx = c_idx_not_exist;\n"
"  last_idx = c_idx_not_exist;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void LIST_INIT_SIZE(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"inline void %s::init_size(unsigned a_size)\n"
"{/*{{{*/\n"
"  init();\n"
"  copy_resize(a_size);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void LIST_INIT_BUFFER(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"inline void %s::init_buffer(unsigned a_size,%s_element *a_data)\n"
"{/*{{{*/\n"
"  init();\n"
"  set_buffer(a_size,a_data);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void LIST_CLEAR(LIST_GEN_PARAMS)
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
);
   if (TYPE_NUMBER & c_type_dynamic || !(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
printf(
"  if (data != nullptr)\n"
"  {\n"
);
      if (TYPE_NUMBER & c_type_dynamic) {
printf(
"    %s_element *ptr = data;\n"
"    %s_element *ptr_end = ptr + size;\n"
"\n"
"    do {\n"
"      ptr->object.clear();\n"
"    } while(++ptr < ptr_end);\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
      }
      if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
         if (TYPE_NUMBER & c_type_dynamic) {
printf(
"\n"
);
         }
printf(
"    cfree(data);\n"
);
      }
printf(
"  }\n"
"\n"
);
   }
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
printf(
"  init();\n"
);
   }
   else {
printf(
"  used = 0;\n"
"  free_idx = c_idx_not_exist;\n"
"  first_idx = c_idx_not_exist;\n"
"  last_idx = c_idx_not_exist;\n"
);
   }
printf(
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_SET_BUFFER(LIST_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_dynamic)) {
printf(
"inline void %s::set_buffer(unsigned a_size,%s_element *a_data)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
   else {
printf(
"void %s::set_buffer(unsigned a_size,%s_element *a_data)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
printf(
"{/*{{{*/\n"
"  debug_assert(a_size != 0 && a_data != NULL);\n"
"\n"
"  clear();\n"
);
   if (TYPE_NUMBER & c_type_dynamic) {
printf(
"\n"
"  %s_element *ptr = data + size;\n"
"  %s_element *ptr_end = data + a_size;\n"
"\n"
"  do {\n"
"    init();\n"
"  } while(++ptr < ptr_end);\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
printf(
"\n"
"  size = a_size;\n"
"  data = a_data;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_FLUSH(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"inline void %s::flush()\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
printf(
"  copy_resize(used);\n"
);
   }
printf(
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_FLUSH_ALL(LIST_GEN_PARAMS)
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
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
printf(
"  copy_resize(used);\n"
);
   }
   if (TYPE_NUMBER & c_type_flushable) {
      if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
printf(
"\n"
);
      }
printf(
"  if (used == 0)\n"
"  {\n"
"    return;\n"
"  }\n"
"\n"
"  %s_element *ptr = data;\n"
"  %s_element *ptr_end = ptr + used;\n"
"\n"
"  do {\n"
"    ptr->object.flush_all();\n"
"  } while(++ptr < ptr_end);\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
printf(
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_SWAP(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"inline void %s::swap(%s &a_second)\n"
"{/*{{{*/\n"
"  unsigned tmp_unsigned = size;\n"
"  size = a_second.size;\n"
"  a_second.size = tmp_unsigned;\n"
"\n"
"  tmp_unsigned = used;\n"
"  used = a_second.used;\n"
"  a_second.used = tmp_unsigned;\n"
"\n"
"  %s_element *tmp_data = data;\n"
"  data = a_second.data;\n"
"  a_second.data = tmp_data;\n"
"\n"
"  tmp_unsigned = free_idx;\n"
"  free_idx = a_second.free_idx;\n"
"  a_second.free_idx = tmp_unsigned;\n"
"\n"
"  tmp_unsigned = first_idx;\n"
"  first_idx = a_second.first_idx;\n"
"  a_second.first_idx = tmp_unsigned;\n"
"\n"
"  tmp_unsigned = last_idx;\n"
"  last_idx = a_second.last_idx;\n"
"  a_second.last_idx = tmp_unsigned;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void LIST_OPERATOR_LE_BR_RE_BR(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"inline %s &%s::operator[](unsigned a_idx)\n"
"{/*{{{*/\n"
"  debug_assert(a_idx < used);\n"
"  return data[a_idx].object;\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME,IM_STRUCT_NAME);
}/*}}}*/

void LIST_PREPEND(LIST_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
printf(
"inline unsigned %s::prepend(%s a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
printf(
"inline unsigned %s::prepend(%s &a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
printf(
"{/*{{{*/\n"
"  unsigned new_idx;\n"
"\n"
"  if (free_idx != c_idx_not_exist)\n"
"  {\n"
"    new_idx = free_idx;\n"
"    free_idx = data[new_idx].next_idx;\n"
"  }\n"
"  else\n"
"  {\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
printf(
"    if (used >= size)\n"
"    {\n"
"      copy_resize((size << 1) + c_array_add);\n"
"    }\n"
"\n"
);
   }
   else {
printf(
"    debug_assert(used < size);\n"
);
   }
printf(
"    new_idx = used++;\n"
"  }\n"
"\n"
"  %s_element &new_element = data[new_idx];\n"
"\n"
"  new_element.next_idx = first_idx;\n"
"  new_element.prev_idx = c_idx_not_exist;\n"
"\n"
"  if (first_idx != c_idx_not_exist)\n"
"  {\n"
"    data[first_idx].prev_idx = new_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    last_idx = new_idx;\n"
"  }\n"
"\n"
"  first_idx = new_idx;\n"
"\n"
"  new_element.object = a_value;\n"
"\n"
"  return new_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void LIST_APPEND(LIST_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
printf(
"inline unsigned %s::append(%s a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
printf(
"inline unsigned %s::append(%s &a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
printf(
"{/*{{{*/\n"
"  unsigned new_idx;\n"
"\n"
"  if (free_idx != c_idx_not_exist)\n"
"  {\n"
"    new_idx = free_idx;\n"
"    free_idx = data[new_idx].next_idx;\n"
"  }\n"
"  else\n"
"  {\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
printf(
"    if (used >= size)\n"
"    {\n"
"      copy_resize((size << 1) + c_array_add);\n"
"    }\n"
"\n"
);
   }
   else {
printf(
"    debug_assert(used < size);\n"
);
   }
printf(
"    new_idx = used++;\n"
"  }\n"
"\n"
"  %s_element &new_element = data[new_idx];\n"
"\n"
"  new_element.next_idx = c_idx_not_exist;\n"
"  new_element.prev_idx = last_idx;\n"
"\n"
"  if (last_idx != c_idx_not_exist)\n"
"  {\n"
"    data[last_idx].next_idx = new_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    first_idx = new_idx;\n"
"  }\n"
"\n"
"  last_idx = new_idx;\n"
"\n"
"  new_element.object = a_value;\n"
"\n"
"  return new_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void LIST_INSERT_BEFORE(LIST_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
printf(
"inline unsigned %s::insert_before(unsigned a_idx,%s a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
printf(
"inline unsigned %s::insert_before(unsigned a_idx,%s &a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
printf(
"{/*{{{*/\n"
"  debug_assert(a_idx < used);\n"
"\n"
"  unsigned new_idx;\n"
"\n"
"  if (free_idx != c_idx_not_exist)\n"
"  {\n"
"    new_idx = free_idx;\n"
"    free_idx = data[new_idx].next_idx;\n"
"  }\n"
"  else\n"
"  {\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
printf(
"    if (used >= size)\n"
"    {\n"
"      copy_resize((size << 1) + c_array_add);\n"
"    }\n"
"\n"
);
   }
   else {
printf(
"    debug_assert(used < size);\n"
);
   }
printf(
"    new_idx = used++;\n"
"  }\n"
"\n"
"  %s_element &idx_element = data[a_idx];\n"
"  %s_element &new_element = data[new_idx];\n"
"\n"
"  new_element.next_idx = a_idx;\n"
"  new_element.prev_idx = idx_element.prev_idx;\n"
"\n"
"  if (idx_element.prev_idx != c_idx_not_exist)\n"
"  {\n"
"    data[idx_element.prev_idx].next_idx = new_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    first_idx = new_idx;\n"
"  }\n"
"\n"
"  idx_element.prev_idx = new_idx;\n"
"\n"
"  new_element.object = a_value;\n"
"\n"
"  return new_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void LIST_INSERT_AFTER(LIST_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
printf(
"inline unsigned %s::insert_after(unsigned a_idx,%s a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
   else {
printf(
"inline unsigned %s::insert_after(unsigned a_idx,%s &a_value)\n"
,IM_STRUCT_NAME,TYPE_NAME);
   }
printf(
"{/*{{{*/\n"
"  debug_assert(a_idx < used);\n"
"\n"
"  unsigned new_idx;\n"
"\n"
"  if (free_idx != c_idx_not_exist)\n"
"  {\n"
"    new_idx = free_idx;\n"
"    free_idx = data[new_idx].next_idx;\n"
"  }\n"
"  else\n"
"  {\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
printf(
"    if (used >= size)\n"
"    {\n"
"      copy_resize((size << 1) + c_array_add);\n"
"    }\n"
"\n"
);
   }
   else {
printf(
"    debug_assert(used < size);\n"
);
   }
printf(
"    new_idx = used++;\n"
"  }\n"
"\n"
"  %s_element &idx_element = data[a_idx];\n"
"  %s_element &new_element = data[new_idx];\n"
"\n"
"  new_element.next_idx = idx_element.next_idx;\n"
"  new_element.prev_idx = a_idx;\n"
"\n"
"  if (idx_element.next_idx != c_idx_not_exist)\n"
"  {\n"
"    data[idx_element.next_idx].prev_idx = new_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    last_idx = new_idx;\n"
"  }\n"
"\n"
"  idx_element.next_idx = new_idx;\n"
"\n"
"  new_element.object = a_value;\n"
"\n"
"  return new_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void LIST_PREPEND_BLANK(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"inline unsigned %s::prepend_blank()\n"
"{/*{{{*/\n"
"  unsigned new_idx;\n"
"\n"
"  if (free_idx != c_idx_not_exist)\n"
"  {\n"
"    new_idx = free_idx;\n"
"    free_idx = data[new_idx].next_idx;\n"
"  }\n"
"  else\n"
"  {\n"
,IM_STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
printf(
"    if (used >= size)\n"
"    {\n"
"      copy_resize((size << 1) + c_array_add);\n"
"    }\n"
"\n"
);
   }
   else {
printf(
"    debug_assert(used < size);\n"
);
   }
printf(
"    new_idx = used++;\n"
"  }\n"
"\n"
"  %s_element &new_element = data[new_idx];\n"
"\n"
"  new_element.next_idx = first_idx;\n"
"  new_element.prev_idx = c_idx_not_exist;\n"
"\n"
"  if (first_idx != c_idx_not_exist)\n"
"  {\n"
"    data[first_idx].prev_idx = new_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    last_idx = new_idx;\n"
"  }\n"
"\n"
"  first_idx = new_idx;\n"
"\n"
"  return new_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void LIST_APPEND_BLANK(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"inline unsigned %s::append_blank()\n"
"{/*{{{*/\n"
"  unsigned new_idx;\n"
"\n"
"  if (free_idx != c_idx_not_exist)\n"
"  {\n"
"    new_idx = free_idx;\n"
"    free_idx = data[new_idx].next_idx;\n"
"  }\n"
"  else\n"
"  {\n"
,IM_STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
printf(
"    if (used >= size)\n"
"    {\n"
"      copy_resize((size << 1) + c_array_add);\n"
"    }\n"
"\n"
);
   }
   else {
printf(
"    debug_assert(used < size);\n"
);
   }
printf(
"    new_idx = used++;\n"
"  }\n"
"\n"
"  %s_element &new_element = data[new_idx];\n"
"\n"
"  new_element.next_idx = c_idx_not_exist;\n"
"  new_element.prev_idx = last_idx;\n"
"\n"
"  if (last_idx != c_idx_not_exist)\n"
"  {\n"
"    data[last_idx].next_idx = new_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    first_idx = new_idx;\n"
"  }\n"
"\n"
"  last_idx = new_idx;\n"
"\n"
"  return new_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void LIST_INSERT_BLANK_BEFORE(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"inline unsigned %s::insert_blank_before(unsigned a_idx)\n"
"{/*{{{*/\n"
"  debug_assert(a_idx < used);\n"
"\n"
"  unsigned new_idx;\n"
"\n"
"  if (free_idx != c_idx_not_exist)\n"
"  {\n"
"    new_idx = free_idx;\n"
"    free_idx = data[new_idx].next_idx;\n"
"  }\n"
"  else\n"
"  {\n"
,IM_STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
printf(
"    if (used >= size)\n"
"    {\n"
"      copy_resize((size << 1) + c_array_add);\n"
"    }\n"
"\n"
);
   }
   else {
printf(
"    debug_assert(used < size);\n"
);
   }
printf(
"    new_idx = used++;\n"
"  }\n"
"\n"
"  %s_element &idx_element = data[a_idx];\n"
"  %s_element &new_element = data[new_idx];\n"
"\n"
"  new_element.next_idx = a_idx;\n"
"  new_element.prev_idx = idx_element.prev_idx;\n"
"\n"
"  if (idx_element.prev_idx != c_idx_not_exist)\n"
"  {\n"
"    data[idx_element.prev_idx].next_idx = new_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    first_idx = new_idx;\n"
"  }\n"
"\n"
"  idx_element.prev_idx = new_idx;\n"
"\n"
"  return new_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void LIST_INSERT_BLANK_AFTER(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"inline unsigned %s::insert_blank_after(unsigned a_idx)\n"
"{/*{{{*/\n"
"  debug_assert(a_idx < used);\n"
"\n"
"  unsigned new_idx;\n"
"\n"
"  if (free_idx != c_idx_not_exist)\n"
"  {\n"
"    new_idx = free_idx;\n"
"    free_idx = data[new_idx].next_idx;\n"
"  }\n"
"  else\n"
"  {\n"
,IM_STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
printf(
"    if (used >= size)\n"
"    {\n"
"      copy_resize((size << 1) + c_array_add);\n"
"    }\n"
"\n"
);
   }
   else {
printf(
"    debug_assert(used < size);\n"
);
   }
printf(
"    new_idx = used++;\n"
"  }\n"
"\n"
"  %s_element &idx_element = data[a_idx];\n"
"  %s_element &new_element = data[new_idx];\n"
"\n"
"  new_element.next_idx = idx_element.next_idx;\n"
"  new_element.prev_idx = a_idx;\n"
"\n"
"  if (idx_element.next_idx != c_idx_not_exist)\n"
"  {\n"
"    data[idx_element.next_idx].prev_idx = new_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    last_idx = new_idx;\n"
"  }\n"
"\n"
"  idx_element.next_idx = new_idx;\n"
"\n"
"  return new_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void LIST_REMOVE(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"inline void %s::remove(unsigned a_idx)\n"
"{/*{{{*/\n"
"  debug_assert(a_idx < used);\n"
"\n"
"  %s_element &rm_element = data[a_idx];\n"
"\n"
"  if (rm_element.next_idx != c_idx_not_exist)\n"
"  {\n"
"    data[rm_element.next_idx].prev_idx = rm_element.prev_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    last_idx = rm_element.prev_idx;\n"
"  }\n"
"\n"
"  if (rm_element.prev_idx != c_idx_not_exist)\n"
"  {\n"
"    data[rm_element.prev_idx].next_idx = rm_element.next_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    first_idx = rm_element.next_idx;\n"
"  }\n"
"\n"
"  rm_element.next_idx = free_idx;\n"
"  free_idx = a_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void LIST_NEXT_IDX(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"inline unsigned %s::next_idx(unsigned a_idx)\n"
"{/*{{{*/\n"
"  return data[a_idx].next_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void LIST_PREV_IDX(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"inline unsigned %s::prev_idx(unsigned a_idx)\n"
"{/*{{{*/\n"
"  return data[a_idx].prev_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void LIST_COPY_RESIZE(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"void %s::copy_resize(unsigned a_size)\n"
"{/*{{{*/\n"
"  debug_assert(a_size >= used);\n"
,IM_STRUCT_NAME);
   if (TYPE_NUMBER & c_type_dynamic) {
printf(
"\n"
"  if (size > a_size)\n"
"  {\n"
"    %s_element *ptr = data + a_size;\n"
"    %s_element *ptr_end = data + size;\n"
"\n"
"    do {\n"
"      ptr->object.clear();\n"
"    } while(++ptr < ptr_end);\n"
"  }\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
printf(
"\n"
"  if (a_size == 0)\n"
"  {\n"
"    if (data != nullptr)\n"
"    {\n"
"      cfree(data);\n"
"    }\n"
"    data = nullptr;\n"
"  }\n"
"  else\n"
"  {\n"
"    data = (%s_element *)crealloc(data,a_size*sizeof(%s_element));\n"
"  }\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (TYPE_NUMBER & c_type_dynamic) {
printf(
"\n"
"  if (a_size > size)\n"
"  {\n"
"    %s_element *ptr = data + size;\n"
"    %s_element *ptr_end = data + a_size;\n"
"\n"
"    do {\n"
"      ptr->object.init();\n"
"    } while(++ptr < ptr_end);\n"
"  }\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
printf(
"\n"
"  size = a_size;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_GET_IDX(LIST_GEN_PARAMS)
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
"  if (first_idx == c_idx_not_exist)\n"
"  {\n"
"    return c_idx_not_exist;\n"
"  }\n"
"\n"
"  unsigned idx = first_idx;\n"
"  do {\n"
"    %s_element &element = data[idx];\n"
"\n"
"    if (element.object == a_value)\n"
"    {\n"
"      return idx;\n"
"    }\n"
"\n"
"    idx = element.next_idx;\n"
"  } while(idx != c_idx_not_exist);\n"
"\n"
"  return c_idx_not_exist;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void LIST_OPERATOR_EQUAL(LIST_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_dynamic) {
printf(
"%s &%s::operator=(%s &a_src)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
   else {
printf(
"inline %s &%s::operator=(%s &a_src)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
printf(
"{/*{{{*/\n"
);
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
printf(
"  debug_assert(a_src.used <= size);\n"
"\n"
);
   }
printf(
"  clear();\n"
"\n"
"  if (a_src.used == 0)\n"
"  {\n"
"    return *this;\n"
"  }\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
printf(
"\n"
"  copy_resize(a_src.used);\n"
);
   }
   if (!(TYPE_NUMBER & c_type_dynamic)) {
printf(
"\n"
"  memcpy(data,a_src.data,a_src.used*sizeof(%s_element));\n"
,IM_STRUCT_NAME);
   }
   else {
printf(
"\n"
"  %s_element *ptr = data;\n"
"  %s_element *s_ptr = a_src.data;\n"
"  %s_element *s_ptr_end = s_ptr + a_src.used;\n"
"\n"
"  do {\n"
"    ptr->object = s_ptr->object;\n"
"    ptr->next_idx = s_ptr->next_idx;\n"
"    ptr->prev_idx = s_ptr->prev_idx;\n"
"  } while(++ptr,++s_ptr < s_ptr_end);\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
printf(
"\n"
"  used = a_src.used;\n"
"  free_idx = a_src.free_idx;\n"
"  first_idx = a_src.first_idx;\n"
"  last_idx = a_src.last_idx;\n"
"\n"
"  return *this;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void LIST_OPERATOR_DOUBLE_EQUAL(LIST_GEN_PARAMS)
{/*{{{*/
printf(
"bool %s::operator==(%s &a_second)\n"
"{/*{{{*/\n"
"  if (first_idx == c_idx_not_exist)\n"
"  {\n"
"    return a_second.first_idx == c_idx_not_exist;\n"
"  }\n"
"\n"
"  if (a_second.first_idx == c_idx_not_exist)\n"
"  {\n"
"    return false;\n"
"  }\n"
"\n"
"  unsigned idx = first_idx;\n"
"  unsigned s_idx = a_second.first_idx;\n"
"\n"
"  do {\n"
"    %s_element &element = data[idx];\n"
"    %s_element &s_element = a_second.data[s_idx];\n"
"\n"
"    if (!(element.object == s_element.object))\n"
"    {\n"
"      return false;\n"
"    }\n"
"\n"
"    idx = element.next_idx;\n"
"    s_idx = s_element.next_idx;\n"
"\n"
"  } while(idx != c_idx_not_exist || s_idx != c_idx_not_exist);\n"
"\n"
"  return idx == s_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
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
" * \\brief __GEN element of list of type %s\n"
" */\n"
"\n"
"struct %s_element\n"
"{\n"
"  %s object;\n"
"  unsigned next_idx;\n"
"  unsigned prev_idx;\n"
"};\n"
"\n"
"/*!\n"
" * \\brief __GEN list of type %s\n"
" */\n"
"struct %s\n"
"{\n"
"  unsigned size; //!< actual size of allocated space (element count)\n"
"  unsigned used; //!< used part of allocated space\n"
"  %s_element *data; //!< pointer to list elements\n"
"  unsigned free_idx; //!< index of first free element\n"
"  unsigned first_idx; //!< index of first element\n"
"  unsigned last_idx; //!< index of last element\n"
"\n"
,TYPE_NAME,STRUCT_NAME,TYPE_NAME,TYPE_NAME,STRUCT_NAME,STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_nogen_init)) {
printf(
"  /*!\n"
"    * \\brief __GEN initialize list\n"
"    */\n"
"  inline void init();\n"
"\n"
);
   }
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
printf(
"  /*!\n"
"    * \\brief __GEN initialize list of requested size\n"
"    * \\param a_size - requested size of list\n"
"    */\n"
"  inline void init_size(unsigned a_size);\n"
"\n"
);
   }
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
printf(
"  /*!\n"
"    * \\brief __GEN initialize/set underlaying data buffer\n"
"    * \\param a_size - size of data buffer\n"
"    * \\param a_data - pointer to data buffer\n"
"    */\n"
"  inline void init_buffer(unsigned a_size,%s_element *a_data);\n"
"\n"
,STRUCT_NAME);
   }
   if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
      if (!(TYPE_NUMBER & c_type_dynamic)) {
printf(
"  /*!\n"
"    * \\brief __GEN release memory used by list\n"
"    */\n"
"  inline void clear();\n"
"\n"
);
      }
      else {
printf(
"  /*!\n"
"    * \\brief __GEN release memory used by list\n"
"    */\n"
"  void clear();\n"
"\n"
);
      }
   }
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
     if (!(TYPE_NUMBER & c_type_dynamic)) {
printf(
"  /*!\n"
"    * \\brief __GEN set underlaying data buffer\n"
"    * \\param a_size - size of data buffer\n"
"    * \\param a_data - pointer to data buffer\n"
"    */\n"
"  inline void set_buffer(unsigned a_size,%s_element *a_data);\n"
"\n"
,STRUCT_NAME);
      }
      else {
printf(
"  /*!\n"
"    * \\brief __GEN set underlaying data buffer\n"
"    * \\param a_size - size of data buffer\n"
"    * \\param a_data - pointer to data buffer\n"
"    */\n"
"  void set_buffer(unsigned a_size,%s_element *a_data);\n"
"\n"
,STRUCT_NAME);
      }
   }
printf(
"  /*!\n"
"    * \\brief __GEN flush list memory usage\n"
"    */\n"
"  inline void flush();\n"
"\n"
);
   if (!(TYPE_NUMBER & c_type_flushable)) {
printf(
"  /*!\n"
"    * \\brief __GEN flush list memory usage, recursive on elements\n"
"    */\n"
"  inline void flush_all();\n"
"\n"
);
   }
   else {
printf(
"  /*!\n"
"    * \\brief __GEN flush list memory usage, recursive on elements\n"
"    */\n"
"  void flush_all();\n"
"\n"
);
   }
   if (!(STRUCT_NUMBER & c_type_option_nogen_swap)) {
printf(
"  /*!\n"
"    * \\brief __GEN swap members of list with another list\n"
"    * \\param a_second - reference to another list\n"
"    */\n"
"  inline void swap(%s &a_second);\n"
"\n"
,STRUCT_NAME);
   }
printf(
"  /*!\n"
"    * \\brief __GEN select element of list\n"
"    * \\param a_idx - index of element in list\n"
"    * \\return reference to element of list\n"
"    */\n"
"  inline %s &operator[](unsigned a_idx);\n"
"\n"
,TYPE_NAME);
   if (TYPE_NUMBER & c_type_basic) {
printf(
"  /*!\n"
"    * \\brief __GEN prepend element to list\n"
"    * \\param a_value - value prepended to list\n"
"    * \\return - position of element in list\n"
"    */\n"
"  inline unsigned prepend(%s a_value);\n"
"\n"
"  /*!\n"
"    * \\brief __GEN append element to list\n"
"    * \\param a_value - value appended to list\n"
"    * \\return - position of element in list\n"
"    */\n"
"  inline unsigned append(%s a_value);\n"
"\n"
"  /*!\n"
"    * \\brief __GEN insert before element to list\n"
"    * \\param a_value - value inserted to list\n"
"    * \\return - position of element in list\n"
"    */\n"
"  inline unsigned insert_before(unsigned a_idx,%s a_value);\n"
"\n"
"  /*!\n"
"    * \\brief __GEN insert after element to list\n"
"    * \\param a_value - value inserted to list\n"
"    * \\return - position of element in list\n"
"    */\n"
"  inline unsigned insert_after(unsigned a_idx,%s a_value);\n"
"\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   }
   else {
printf(
"  /*!\n"
"    * \\brief __GEN prepend element to list\n"
"    * \\param a_value - reference to value prepended to list\n"
"    * \\return - position of element in list\n"
"    */\n"
"  inline unsigned prepend(%s &a_value);\n"
"\n"
"  /*!\n"
"    * \\brief __GEN append element to list\n"
"    * \\param a_value - reference to value append to list\n"
"    * \\return - position of element in list\n"
"    */\n"
"  inline unsigned append(%s &a_value);\n"
"\n"
"  /*!\n"
"    * \\brief __GEN insert before element to list\n"
"    * \\param a_value - value inserted to list\n"
"    * \\return - position of element in list\n"
"    */\n"
"  inline unsigned insert_before(unsigned a_idx,%s &a_value);\n"
"\n"
"  /*!\n"
"    * \\brief __GEN insert after element to list\n"
"    * \\param a_value - value inserted to list\n"
"    * \\return - position of element in list\n"
"    */\n"
"  inline unsigned insert_after(unsigned a_idx,%s &a_value);\n"
"\n"
,TYPE_NAME,TYPE_NAME,TYPE_NAME,TYPE_NAME);
   }
printf(
"  inline unsigned prepend_blank();\n"
"  inline unsigned append_blank();\n"
"  inline unsigned insert_blank_before(unsigned a_idx);\n"
"  inline unsigned insert_blank_after(unsigned a_idx);\n"
"\n"
);
printf(
"  /*!\n"
"    * \\brief __GEN remove element at index from list\n"
"    * \\param a_idx - index of element to remove\n"
"    */\n"
"  inline void remove(unsigned a_idx);\n"
"\n"
"  /*!\n"
"    * \\brief __GEN return index of next element in list\n"
"    * \\param a_idx - index of element\n"
"    */\n"
"  inline unsigned next_idx(unsigned a_idx);\n"
"\n"
"  /*!\n"
"    * \\brief __GEN return index of previous element in list\n"
"    * \\param a_idx - index of element\n"
"    */\n"
"  inline unsigned prev_idx(unsigned a_idx);\n"
"\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
printf(
"  /*!\n"
"    * \\brief __GEN resize list capacity\n"
"    * \\param a_size - requested list capacity\n"
"    */\n"
"  void copy_resize(unsigned a_size);\n"
"\n"
);
   }
   if (TYPE_NUMBER & c_type_basic) {
printf(
"  /*!\n"
"    * \\brief __GEN search for index of element\n"
"    * \\param a_value - value which index is searched\n"
"    */\n"
"  unsigned get_idx(%s a_value);\n"
,TYPE_NAME);
   }
   else {
printf(
"  /*!\n"
"    * \\brief __GEN search for index of element\n"
"    * \\param a_value - value which index is searched\n"
"    */\n"
"  unsigned get_idx(%s &a_value);\n"
,TYPE_NAME);
   }
   if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
      if (!(TYPE_NUMBER & c_type_dynamic)) {
printf(
"  /*!\n"
"    * \\brief __GEN copy list from another list\n"
"    * \\param a_src - reference to another list\n"
"    * \\return reference to this list\n"
"    */\n"
"  inline %s &operator=(%s &a_src);\n"
"\n"
,STRUCT_NAME,STRUCT_NAME);
      }
      else {
printf(
"  /*!\n"
"    * \\brief __GEN copy list from another list\n"
"    * \\param a_src - reference to another list\n"
"    * \\return reference to this list\n"
"    */\n"
"  %s &operator=(%s &a_src);\n"
"\n"
,STRUCT_NAME,STRUCT_NAME);
      }
   }
printf(
"  /*!\n"
"    * \\brief __GEN compare list with another list\n"
"    * \\param a_second - reference to another list\n"
"    * \\return result of comparision\n"
"    */\n"
"  bool operator==(%s &a_second);\n"
"\n"
,STRUCT_NAME);
   if (fun_defs.used != 0) {
      unsigned f_idx = 0;
      do {
printf(
"  %s\n"
,fun_defs[f_idx].data);
      } while(++f_idx < fun_defs.used);
   }
printf(
"};\n"
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

}/*}}}*/


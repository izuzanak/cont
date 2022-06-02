
#define RUST_ARRAY_GEN_PARAMS FILE *out_file,abbreviation_array_s &abbreviations,unsigned abb_idx,unsigned type_abb_idx,data_type_s &type,data_type_s &data_type
#define RUST_ARRAY_GEN_VALUES out_file,abbreviations,abb_idx,type_abb_idx,type,data_type

void RUST_ARRAY_INIT(RUST_ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn init(&mut self)\n"
"{/*{{{*/\n"
"  self.size = 0;\n"
"  self.used = 0;\n"
"  self.data = std::ptr::null_mut();\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_ARRAY_INIT_SIZE(RUST_ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn init_size(&mut self,a_size:u32)\n"
"{/*{{{*/\n"
"  self.init();\n"
"  self.copy_resize(a_size);\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_ARRAY_INIT_BUFFER(RUST_ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn init_buffer(&mut self,a_size:u32,a_data:*mut %s)\n"
"{/*{{{*/\n"
"  self.init();\n"
"  self.set_buffer(a_size,a_data);\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME);
}/*}}}*/

void RUST_ARRAY_CLEAR(RUST_ARRAY_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"fn clear(&mut self)\n"
);
fprintf(out_file,
"{/*{{{*/\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  if !self.data.is_null()\n"
"  {\n"
);
      if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"    unsafe { free(self.data as *mut c_void); }\n"
);
      }
fprintf(out_file,
"  }\n"
"\n"
);
   }
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  self.init();\n"
);
   }
   else {
fprintf(out_file,
"  self.used = 0;\n"
);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
   }
   else {
fprintf(out_file,
"fn clear(&mut self)\n"
"{/*{{{*/\n"
"  unsafe { %s_clear(self as *mut Self); }\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
   }
}/*}}}*/

void RUST_ARRAY_SET_BUFFER(RUST_ARRAY_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"fn set_buffer(&mut self,a_size:u32,a_data:*mut %s)\n"
,TYPE_NAME);
fprintf(out_file,
"{/*{{{*/\n"
"  debug_assert!(a_size != 0 && !a_data.is_null());\n"
"\n"
"  self.clear();\n"
"\n"
"  self.size = a_size;\n"
"  self.data = a_data;\n"
"}/*}}}*/\n"
"\n"
);
   }
   else {
fprintf(out_file,
"fn set_buffer(&mut self,a_size:u32,a_data:*mut %s)\n"
"{/*{{{*/\n"
"  unsafe { %s_set_buffer(self as *mut Self,a_size as c_uint,a_data); }\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME,STRUCT_NAME);
   }
}/*}}}*/

void RUST_ARRAY_SET(RUST_ARRAY_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"fn set(&mut self,a_used:u32,a_data:*const %s)\n"
,TYPE_NAME);
fprintf(out_file,
"{/*{{{*/\n"
);
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
fprintf(out_file,
"  debug_assert!(a_used <= self.size);\n"
);
   }
fprintf(out_file,
"  self.clear();\n"
"\n"
"  if a_used == 0\n"
"  {\n"
"    return;\n"
"  }\n"
"\n"
"  debug_assert!(!a_data.is_null());\n"
"\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  self.copy_resize(a_used);\n"
"\n"
);
   }
fprintf(out_file,
"  unsafe { std::ptr::copy_nonoverlapping(a_data,self.data,a_used as usize); }\n"
);
fprintf(out_file,
"  self.used = a_used;\n"
"}/*}}}*/\n"
"\n"
);
   }
   else {
fprintf(out_file,
"fn set(&mut self,a_used:u32,a_data:*const %s)\n"
"{/*{{{*/\n"
"  unsafe { %s_set(self as *mut Self,a_used as c_uint,a_data); }\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME,STRUCT_NAME);
   }
}/*}}}*/

void RUST_ARRAY_FLUSH(RUST_ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn flush(&mut self)\n"
"{/*{{{*/\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  self.copy_resize(self.used);\n"
);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_ARRAY_FLUSH_ALL(RUST_ARRAY_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_flushable)) {
fprintf(out_file,
"fn flush_all(&mut self)\n"
);
fprintf(out_file,
"{/*{{{*/\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  self.copy_resize(self.used);\n"
);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
   }
   else {
fprintf(out_file,
"fn flush_all(&mut self)\n"
"{/*{{{*/\n"
"  unsafe { %s_flush_all(self as *mut Self); }\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
   }
}/*}}}*/

void RUST_ARRAY_SWAP(RUST_ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn swap(&mut self,a_second:&mut Self)\n"
"{/*{{{*/\n"
"  std::mem::swap(self,a_second);\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_ARRAY_OPERATOR_LE_BR_RE_BR(RUST_ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn at(&mut self,a_idx:u32) -> &mut %s\n"
"{/*{{{*/\n"
"  debug_assert!(a_idx < self.used);\n"
"  unsafe { &mut *self.data.offset(a_idx as isize) }\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME);
}/*}}}*/

void RUST_ARRAY_PUSH(RUST_ARRAY_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"fn push(&mut self,a_value:%s)\n"
,TYPE_NAME);
   }
   else {
fprintf(out_file,
"fn push(&mut self,a_value:&%s)\n"
,TYPE_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  if self.used >= self.size\n"
"  {\n"
"    let new_size = (self.size << 1) + c_array_add;\n"
"    debug_assert!(new_size != 0);\n"
"\n"
"    self.copy_resize(new_size);\n"
"  }\n"
"\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert!(self.used < self.size);\n"
);
   }
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"  unsafe { *self.data.offset(self.used as isize) = a_value; }\n"
"  self.used += 1;\n"
);
   }
   else if (TYPE_NUMBER & c_type_static) {
fprintf(out_file,
"  unsafe { *self.data.offset(self.used as isize) = *a_value; }\n"
"  self.used += 1;\n"
);
   }
   else {
fprintf(out_file,
"  unsafe { (*self.data.offset(self.used as isize)).copy(a_value); }\n"
"  self.used += 1;\n"
);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_ARRAY_PUSH_BLANK(RUST_ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn push_blank(&mut self)\n"
"{/*{{{*/\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  if self.used >= self.size\n"
"  {\n"
"    let new_size = (self.size << 1) + c_array_add;\n"
"    debug_assert!(new_size != 0);\n"
"\n"
"    self.copy_resize(new_size);\n"
"  }\n"
"\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert!(self.used < self.size);\n"
);
   }
fprintf(out_file,
"  self.used += 1;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_ARRAY_RESERVE(RUST_ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn reserve(&mut self,a_cnt:u32)\n"
"{/*{{{*/\n"
"  let required_cnt = self.used + a_cnt;\n"
"  if required_cnt > self.size\n"
"  {\n"
"    let mut r_size = self.size;\n"
"    loop {\n"
"      r_size = (r_size << 1) + c_array_add;\n"
"      if r_size >= required_cnt { break; }\n"
"    }\n"
"\n"
"    debug_assert!(r_size != 0);\n"
"    self.copy_resize(r_size);\n"
"  }\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_ARRAY_PUSH_BLANKS(RUST_ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn push_blanks(&mut self,a_cnt:u32)\n"
"{/*{{{*/\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  let required_cnt = self.used + a_cnt;\n"
"  if required_cnt > self.size\n"
"  {\n"
"    let mut r_size = self.size;\n"
"    loop {\n"
"      r_size = (r_size << 1) + c_array_add;\n"
"      if r_size >= required_cnt { break; }\n"
"    }\n"
"\n"
"    debug_assert!(r_size != 0);\n"
"    self.copy_resize(r_size);\n"
"  }\n"
"\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert!(self.used + a_cnt <= self.size);\n"
);
   }
fprintf(out_file,
"  self.used += a_cnt;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_ARRAY_PUSH_CLEAR(RUST_ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn push_clear(&mut self)\n"
"{/*{{{*/\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  if self.used >= self.size\n"
"  {\n"
"    let new_size = (self.size << 1) + c_array_add;\n"
"    debug_assert!(new_size != 0);\n"
"\n"
"    self.copy_resize(new_size);\n"
"  }\n"
"\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert!(self.used < self.size);\n"
);
   }
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"  self.used += 1;\n"
);
   }
   else {
fprintf(out_file,
"  unsafe { (*self.data.offset(self.used as isize)).clear(); }\n"
"  self.used += 1;\n"
);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_ARRAY_POP(RUST_ARRAY_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"fn pop(&mut self) -> %s\n"
,TYPE_NAME);
   }
   else {
fprintf(out_file,
"fn pop(&mut self) -> &mut %s\n"
,TYPE_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
"  debug_assert!(self.used > 0);\n"
);
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"  self.used -= 1;\n"
"  unsafe { *self.data.offset(self.used as isize) }\n"
);
   }
   else {
fprintf(out_file,
"  self.used -= 1;\n"
"  unsafe { &mut *self.data.offset(self.used as isize) }\n"
);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_ARRAY_LAST(RUST_ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn last(&self) -> &mut %s\n"
"{/*{{{*/\n"
"  debug_assert!(self.used > 0);\n"
"  unsafe { &mut *self.data.offset(self.used as isize - 1) }\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME);
}/*}}}*/

void RUST_ARRAY_COPY_RESIZE(RUST_ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn copy_resize(&mut self,a_size:u32)\n"
"{/*{{{*/\n"
"  unsafe { %s_copy_resize(self as *mut Self,a_size as c_uint); }\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
}/*}}}*/

void RUST_ARRAY_FILL(RUST_ARRAY_GEN_PARAMS,unsigned type_idx)
{/*{{{*/
   if (type_idx == c_bt_char || type_idx == c_bt_unsigned_char){
fprintf(out_file,
"fn fill(&mut self,a_value:%s)\n"
,TYPE_NAME);
fprintf(out_file,
"{/*{{{*/\n"
"  if self.size == 0\n"
"  {\n"
"    return;\n"
"  }\n"
"\n"
);
fprintf(out_file,
"  unsafe { self.data.write_bytes(a_value as u8,self.size as usize); }\n"
);
fprintf(out_file,
"\n"
"  self.used = self.size;\n"
"}/*}}}*/\n"
"\n"
);
   }
   else {
      if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"fn fill(&mut self,a_value:%s)\n"
"{/*{{{{*/\n"
"  unsafe { %s_fill(self as *mut Self,a_value); }\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME,STRUCT_NAME);
      }
      else {
fprintf(out_file,
"fn fill(&mut self,a_value:&%s)\n"
"{/*{{{{*/\n"
"  unsafe { %s_fill(self as *mut Self,a_value as *const %s); }\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME,STRUCT_NAME,TYPE_NAME);
      }
   }
}/*}}}*/

void RUST_ARRAY_GET_IDX(RUST_ARRAY_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"fn get_idx(&self,a_value:%s) -> u32\n"
"{/*{{{*/\n"
"  unsafe { %s_get_idx(self as *const Self,a_value) }\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME,STRUCT_NAME);
   }
   else {
fprintf(out_file,
"fn get_idx(&self,a_value:&%s) -> u32\n"
"{/*{{{*/\n"
"  unsafe { %s_get_idx(self as *const Self,a_value as *const %s) }\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAME,STRUCT_NAME,TYPE_NAME);
   }
}/*}}}*/

void RUST_ARRAY_OPERATOR_EQUAL(RUST_ARRAY_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBER & c_type_dynamic)) {
fprintf(out_file,
"fn copy(&mut self,a_src:&Self)\n"
);
fprintf(out_file,
"{/*{{{*/\n"
);
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
fprintf(out_file,
"  debug_assert!(a_src.used <= self.size);\n"
"\n"
);
   }
fprintf(out_file,
"  self.clear();\n"
"\n"
"  if a_src.used == 0\n"
"  {\n"
"    return;\n"
"  }\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"\n"
"  self.copy_resize(a_src.used);\n"
);
   }
fprintf(out_file,
"\n"
"  unsafe { std::ptr::copy_nonoverlapping(a_src.data,self.data,a_src.used as usize); }\n"
);
fprintf(out_file,
"\n"
"  self.used = a_src.used;\n"
"}/*}}}*/\n"
"\n"
);
   }
   else {
fprintf(out_file,
"fn copy(&mut self,a_src:&Self)\n"
"{/*{{{*/\n"
"  unsafe { %s_copy(self as *mut Self,a_src as *const Self); }\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
   }
}/*}}}*/

void RUST_ARRAY_OPERATOR_DOUBLE_EQUAL(RUST_ARRAY_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"fn compare(&self,a_second:&Self) -> bool\n"
);
fprintf(out_file,
"{/*{{{*/\n"
"  if self.used != a_second.used\n"
"  {\n"
"    return false;\n"
"  }\n"
"\n"
"  if self.used == 0\n"
"  {\n"
"    return true;\n"
"  }\n"
);
fprintf(out_file,
"\n"
"  unsafe { memcmp(self.data as *const c_void,a_second.data as *const c_void,self.used as usize*std::mem::size_of::<%s>()) == 0 }\n"
,TYPE_NAME);
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
   }
   else {
fprintf(out_file,
"fn compare(&self,a_second:&Self) -> bool\n"
"{/*{{{*/\n"
"  unsafe { %s_compare(self as *const Self,a_second as *const Self) != 0 }\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
   }
}/*}}}*/

void RUST_ARRAY_TO_STRING(RUST_ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#[cfg(OPTION_TO_STRING = \"ENABLED\")]\n"
"fn to_string(&self,a_trg:&mut bc_array_s)\n"
"{/*{{{*/\n"
"  unsafe { %s___to_string(self as *const Self,a_trg as *mut bc_array_s); }\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
}/*}}}*/

void RUST_ARRAY_TO_STRING_SEPARATOR(RUST_ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#[cfg(OPTION_TO_STRING = \"ENABLED\")]\n"
"fn to_string_separator(&self,a_trg:&mut bc_array_s,a_sep:&str)\n"
"{/*{{{*/\n"
"  unsafe { %s_to_string_separator(self as *const Self,a_trg as *mut bc_array_s,a_sep.len() as c_uint,a_sep.as_ptr() as *const c_char); }\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
}/*}}}*/

void RUST_ARRAY_TO_JSON(RUST_ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#[cfg(OPTION_TO_JSON = \"ENABLED\")]\n"
"fn to_json(&self,a_trg:&mut bc_array_s)\n"
"{/*{{{*/\n"
"  unsafe { %s_to_json(self as *const Self,a_trg as *mut bc_array_s); }\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
}/*}}}*/

void RUST_ARRAY_TO_JSON_NICE(RUST_ARRAY_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#[cfg(OPTION_TO_JSON = \"ENABLED\")]\n"
"fn to_json_nice(&self,a_json:&mut json_nice_s,a_trg:&mut bc_array_s)\n"
"{/*{{{*/\n"
"  unsafe { %s_to_json_nice(self as *const Self,a_json_nice as *mut json_nice_s,a_trg as *mut bc_array_s); }\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
}/*}}}*/

void RUST_ARRAY_FROM_VAR(RUST_ARRAY_GEN_PARAMS)
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
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,TYPE_NAME,TYPE_NAME);
}/*}}}*/

void RUST_ARRAY_FROM_JSON(RUST_ARRAY_GEN_PARAMS)
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
"      %s_push_blank(this);\n"
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
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,TYPE_NAME,STRUCT_NAME);
}/*}}}*/

void processor_s::generate_rust_array_type()
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
   string_s real_name;
   real_name.init();

   {
      data_type_s &type = data_types[type_idx];

      // - test type options -
      if (type.properties & c_type_option_strict_dynamic) {
         fprintf(stderr,"array: option strict_dynamic not supported\n");
         cassert(0);
      }

      real_name.conc_set(type.name.size - 1,type.name.data,strlen(c_cont_postfixes[c_cont_array]),(char *)c_cont_postfixes[c_cont_array]);
   }

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

      data_type.cont_idx = c_cont_rust_array;
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

   data_type_s &type = data_types[type_idx];
   data_type_s &data_type = data_types[data_type_idx];

   if (gen_options & c_option_gen_code &&
      (include_level == 0 || gen_options & c_option_gen_includes))
   {
   // --- definition of structure array ---

fprintf(out_file,
"// --- struct %s definition --- \n"
"\n"
,STRUCT_NAME);

    unsigned idx = 0;
    while(++idx < abbs.used) {
fprintf(out_file,
"type %s = %s;\n"
,abbs[idx].data,abbs[0].data);
    }
fprintf(out_file,
"\n"
);

fprintf(out_file,
"#[repr(C)] struct %s\n"
"{\n"
"  size:u32,\n"
"  used:u32,\n"
"  data:*mut %s,\n"
"}\n"
"\n"
"extern {\n"
,STRUCT_NAME,TYPE_NAME);
   if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
      if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"fn %s_clear(this:*mut %s);\n"
,STRUCT_NAME,STRUCT_NAME);
      }
   }
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
      if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"fn %s_set_buffer(this:*mut %s,a_size:c_uint,a_data:*mut %s);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
      }
   }
   if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"fn %s_set(this:*mut %s,a_used:c_uint,a_data:*const %s);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
   }
   if (TYPE_NUMBER & c_type_flushable) {
fprintf(out_file,
"fn %s_flush_all(this:*mut %s);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"fn %s_copy_resize(this:*mut %s,a_size:c_uint);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
   if (type_idx != c_bt_char) {
      if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"fn %s_fill(this:*mut %s,a_value:%s);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
      }
      else {
fprintf(out_file,
"fn %s_fill(this:*mut %s,a_value:*const %s);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
      }
   }
   if (TYPE_NUMBER & c_type_basic) {
fprintf(out_file,
"fn %s_get_idx(this:*const %s,a_value:%s) -> c_uint;\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
   }
   else {
fprintf(out_file,
"fn %s_get_idx(this:*const %s,a_value:*const %s) -> c_uint;\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAME);
   }
   if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
     if (TYPE_NUMBER & c_type_dynamic) {
fprintf(out_file,
"fn %s_copy(this:*mut %s,a_src:*const %s);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
     }
   }
   if (!(TYPE_NUMBER & c_type_basic)) {
fprintf(out_file,
"fn %s_compare(this:*const %s,a_second:*const %s) -> c_int;\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   }
fprintf(out_file,
"fn %s___to_string(this:*const %s,a_trg:*mut bc_array_s);\n"
"fn %s_to_string_separator(this:*const %s,a_trg:*mut bc_array_s,a_count:c_uint,a_data:*const c_char);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   if (STRUCT_NUMBER & (c_type_option_to_json | c_type_option_to_json_nice)) {
      if (STRUCT_NUMBER & c_type_option_to_json) {
fprintf(out_file,
"fn %s_to_json(this:*const %s,a_trg:*mut bc_array_s);\n"
,STRUCT_NAME,STRUCT_NAME);
      }
      if (STRUCT_NUMBER & c_type_option_to_json_nice) {
fprintf(out_file,
"fn %s_to_json_nice(this:*const %s,a_json_nice:*mut json_nice_s,a_trg:*mut bc_array_s);\n"
,STRUCT_NAME,STRUCT_NAME);
      }
   }
//   if (STRUCT_NUMBER & c_type_option_from_var) {
//fprintf(out_file,
//"#if OPTION_FROM_VAR == ENABLED\n"
//"WUR EXPORT int %s_from_var(%s *this,var_s a_var);\n"
//"#endif\n"
//,STRUCT_NAME,STRUCT_NAME);
//   }
//   if (STRUCT_NUMBER & c_type_option_from_json) {
//fprintf(out_file,
//"#if OPTION_FROM_JSON == ENABLED\n"
//"WUR EXPORT int %s_from_json(%s *this,const bc_array_s *a_src,from_json_s *a_from_json);\n"
//"#endif\n"
//,STRUCT_NAME,STRUCT_NAME);
//   }
fprintf(out_file,
"}\n"
);
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

void processor_s::generate_rust_array_inlines(unsigned abb_idx,unsigned a_dt_idx)
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

   if (gen_options & c_option_gen_code &&
      (include_level == 0 || gen_options & c_option_gen_includes))
   {
   // --- definition of inline methods ---

fprintf(out_file,
"// --- struct %s inline method definition ---\n"
"\n"
"impl %s {\n"
"\n"
"fn new() -> Self\n"
"{/*{{{*/\n"
"  %s{\n"
"    size:0,\n"
"    used:0,\n"
"    data:std::ptr::null_mut(),\n"
"  }\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);

   // - array init method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_init)) {
RUST_ARRAY_INIT(RUST_ARRAY_GEN_VALUES);
   }

   // - array init_size method -
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
RUST_ARRAY_INIT_SIZE(RUST_ARRAY_GEN_VALUES);
   }

   // - array init_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
RUST_ARRAY_INIT_BUFFER(RUST_ARRAY_GEN_VALUES);
   }

   // - array clear method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
RUST_ARRAY_CLEAR(RUST_ARRAY_GEN_VALUES);
      }
   }

   // - array set_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer && !(TYPE_NUMBER & c_type_dynamic)) {
RUST_ARRAY_SET_BUFFER(RUST_ARRAY_GEN_VALUES);
   }

   // - array set method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
RUST_ARRAY_SET(RUST_ARRAY_GEN_VALUES);
   }

   // - array_flush_method -
RUST_ARRAY_FLUSH(RUST_ARRAY_GEN_VALUES);

   // - array flush_all method -
   if (!(TYPE_NUMBER & c_type_flushable)) {
RUST_ARRAY_FLUSH_ALL(RUST_ARRAY_GEN_VALUES);
   }

   // - array swap method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_swap)) {
RUST_ARRAY_SWAP(RUST_ARRAY_GEN_VALUES);
   }

   // - array operator[] method -
RUST_ARRAY_OPERATOR_LE_BR_RE_BR(RUST_ARRAY_GEN_VALUES);

   // - array push method -
RUST_ARRAY_PUSH(RUST_ARRAY_GEN_VALUES);

   // - array push_blank method -
RUST_ARRAY_PUSH_BLANK(RUST_ARRAY_GEN_VALUES);

   // - array reserve method -
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
RUST_ARRAY_RESERVE(RUST_ARRAY_GEN_VALUES);
   }

   // - array push_blanks method -
RUST_ARRAY_PUSH_BLANKS(RUST_ARRAY_GEN_VALUES);

   // - array push_clear method -
RUST_ARRAY_PUSH_CLEAR(RUST_ARRAY_GEN_VALUES);

   // - array pop method -
RUST_ARRAY_POP(RUST_ARRAY_GEN_VALUES);

   // - array last method -
RUST_ARRAY_LAST(RUST_ARRAY_GEN_VALUES);

   // - array copy_resize method -

   // - array fill method -
   if (type_idx == c_bt_char || type_idx == c_bt_unsigned_char) {
RUST_ARRAY_FILL(RUST_ARRAY_GEN_VALUES,type_idx);
   }

   // - array get_idx method -

   // - array operator= method -
   if (!(TYPE_NUMBER & c_type_dynamic)) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
RUST_ARRAY_OPERATOR_EQUAL(RUST_ARRAY_GEN_VALUES);
      }
   }

   // - array operator== method -
   if (TYPE_NUMBER & c_type_basic) {
RUST_ARRAY_OPERATOR_DOUBLE_EQUAL(RUST_ARRAY_GEN_VALUES);
   }

   // - array to_string method -

   // - array to_string_separator method -

   // - array to_json method -

   // - array to_json_nice method -

   // - array from_var method -

   // - array from_json method -

fprintf(out_file,
"}\n"
"\n");
   }
}/*}}}*/

void processor_s::generate_rust_array_methods(unsigned abb_idx,unsigned a_dt_idx)
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

   if (gen_options & c_option_gen_code &&
      (include_level == 0 || gen_options & c_option_gen_includes))
   {
   // --- definition of methods ---

fprintf(out_file,
"// --- struct %s method definition ---\n"
"\n"
"impl %s {\n"
"\n"
,STRUCT_NAME,STRUCT_NAME);

   // - array init method -

   // - array init_size method -

   // - array init_buffer method -

   // - array clear method -
   if (TYPE_NUMBER & c_type_dynamic) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
RUST_ARRAY_CLEAR(RUST_ARRAY_GEN_VALUES);
      }
   }

   // - array set_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer && TYPE_NUMBER & c_type_dynamic) {
RUST_ARRAY_SET_BUFFER(RUST_ARRAY_GEN_VALUES);
   }

   // - array set method -
   if (TYPE_NUMBER & c_type_dynamic) {
RUST_ARRAY_SET(RUST_ARRAY_GEN_VALUES);
   }

   // - array_flush_method -

   // - array flush_all method -
   if (TYPE_NUMBER & c_type_flushable) {
RUST_ARRAY_FLUSH_ALL(RUST_ARRAY_GEN_VALUES);
   }

   // - array swap method -

   // - array operator[] method -

   // - array push method -

   // - array push_blank method -

   // - array reserve method -

   // - array push_blanks method -

   // - array push_clear method -

   // - array pop method -

   // - array last method -

   // - array copy_resize method -
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
RUST_ARRAY_COPY_RESIZE(RUST_ARRAY_GEN_VALUES);
   }

   // - array fill method -
   if (type_idx != c_bt_char && type_idx != c_bt_unsigned_char) {
RUST_ARRAY_FILL(RUST_ARRAY_GEN_VALUES,type_idx);
   }

   // - array get_idx method -
RUST_ARRAY_GET_IDX(RUST_ARRAY_GEN_VALUES);

   // - array operator= method -
   if (TYPE_NUMBER & c_type_dynamic) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
RUST_ARRAY_OPERATOR_EQUAL(RUST_ARRAY_GEN_VALUES);
      }
   }

   // - array operator== method -
   if (!(TYPE_NUMBER & c_type_basic)) {
RUST_ARRAY_OPERATOR_DOUBLE_EQUAL(RUST_ARRAY_GEN_VALUES);
   }

   // - array to_string method -
RUST_ARRAY_TO_STRING(RUST_ARRAY_GEN_VALUES);

   // - array to_string_separator method -
RUST_ARRAY_TO_STRING_SEPARATOR(RUST_ARRAY_GEN_VALUES);

   // - array to_json method -
   if (STRUCT_NUMBER & c_type_option_to_json) {
RUST_ARRAY_TO_JSON(RUST_ARRAY_GEN_VALUES);
   }

   // - array to_json_nice method -
   if (STRUCT_NUMBER & c_type_option_to_json_nice) {
RUST_ARRAY_TO_JSON_NICE(RUST_ARRAY_GEN_VALUES);
   }

//   // - array from_var method -
//   if (STRUCT_NUMBER & c_type_option_from_var) {
//RUST_ARRAY_FROM_VAR(RUST_ARRAY_GEN_VALUES);
//   }
//
//   // - array from_json method -
//   if (STRUCT_NUMBER & c_type_option_from_json) {
//RUST_ARRAY_FROM_JSON(RUST_ARRAY_GEN_VALUES);
//   }

fprintf(out_file,
"}\n"
"\n"
"impl Drop for %s\n"
"{\n"
"    fn drop(&mut self) {\n"
"        self.clear();\n"
"    }\n"
"}\n"
"\n"
,STRUCT_NAME);
   }
}/*}}}*/


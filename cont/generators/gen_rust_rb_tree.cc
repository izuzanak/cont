
#define RUST_RB_TREE_GEN_PARAMS FILE *out_file,abbreviation_array_s &abbreviations,unsigned abb_idx,data_type_s &data_type,data_type_s **types
#define RUST_RB_TREE_GEN_VALUES out_file,abbreviations,abb_idx,data_type,types

void RUST_RB_TREE___GET_GRANDPARENT_IDX(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn __get_grandparent_idx(&self,a_idx:u32) -> u32\n"
"{/*{{{*/\n"
"  let node = unsafe{&*self.data.offset(a_idx as isize)};\n"
"\n"
"  if node.parent_idx != c_idx_not_exist\n"
"  {\n"
"    unsafe{&*self.data.offset(node.parent_idx as isize)}.parent_idx\n"
"  }\n"
"  else\n"
"  {\n"
"    c_idx_not_exist\n"
"  }\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_RB_TREE___GET_UNCLE_IDX(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn __get_uncle_idx(&self,a_idx:u32) -> u32\n"
"{/*{{{*/\n"
"  let gp_idx = self.__get_grandparent_idx(a_idx);\n"
"\n"
"  if gp_idx != c_idx_not_exist\n"
"  {\n"
"    let gp = unsafe{&*self.data.offset(gp_idx as isize)};\n"
"    if gp.left_idx == unsafe{&*self.data.offset(a_idx as isize)}.parent_idx\n"
"    {\n"
"      gp.right_idx\n"
"    }\n"
"    else\n"
"    {\n"
"      gp.left_idx\n"
"    }\n"
"  }\n"
"  else\n"
"  {\n"
"    c_idx_not_exist\n"
"  }\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_RB_TREE___GET_SIBLING_IDX(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn __get_sibling_idx(&self,a_idx:u32) -> u32\n"
"{/*{{{*/\n"
"  let p = unsafe{&*self.data.offset((*self.data.offset(a_idx as isize)).parent_idx as isize)};\n"
"  if p.left_idx == a_idx { p.right_idx } else { p.left_idx }\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_RB_TREE_GET_DESCENT_STACK_SIZE(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn get_descent_stack_size(&self) -> u32\n"
"{/*{{{*/\n"
"  (((self.used as f32).ln()/c_log_of_2) as u32) << 1\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_RB_TREE_GET_STACK_MIN_VALUE_IDX(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn get_stack_min_value_idx(&self,a_idx:u32,a_s_ptr:*mut *mut u32) -> u32\n"
"{/*{{{*/\n"
"  unsafe{ %s_get_stack_min_value_idx(self as *const Self,a_idx,a_s_ptr) }\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
}/*}}}*/

void RUST_RB_TREE_GET_STACK_NEXT_IDX(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn get_stack_next_idx(&self,a_idx:u32,a_s_ptr:*mut *mut u32,a_stack_base:*const u32) -> u32\n"
"{/*{{{*/\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  debug_assert!(a_idx < self.used && unsafe{&*self.data.offset(a_idx as isize)}.valid != 0);\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert!(a_idx < self.used);\n"
);
   }
fprintf(out_file,
"\n"
"  let node = unsafe{&*self.data.offset(a_idx as isize)};\n"
"\n"
"  if node.right_idx != self.leaf_idx\n"
"  {\n"
"    self.get_stack_min_value_idx(node.right_idx,a_s_ptr)\n"
"  }\n"
"  else\n"
"  {\n"
"    if unsafe{*a_s_ptr} > a_stack_base as *mut u32\n"
"    {\n"
"      unsafe{\n"
"        (*a_s_ptr) = (*a_s_ptr).offset(-1);\n"
"        *(*a_s_ptr)\n"
"      }\n"
"    }\n"
"    else\n"
"    {\n"
"      c_idx_not_exist\n"
"    }\n"
"  }\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_RB_TREE_GET_MIN_VALUE_IDX(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn get_min_value_idx(&self,a_idx:u32) -> u32\n"
"{/*{{{*/\n"
"  unsafe{%s_get_min_value_idx(self as *const Self,a_idx)}\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
}/*}}}*/

void RUST_RB_TREE_GET_MAX_VALUE_IDX(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn get_max_value_idx(&self,a_idx:u32) -> u32\n"
"{/*{{{*/\n"
"  unsafe{%s_get_max_value_idx(self as *const Self,a_idx)}\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
}/*}}}*/

void RUST_RB_TREE_GET_NEXT_IDX(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn get_next_idx(&self,a_idx:u32) -> u32\n"
"{/*{{{*/\n"
"  unsafe{%s_get_next_idx(self as *const Self,a_idx)}\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
}/*}}}*/

void RUST_RB_TREE_GET_PREV_IDX(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn get_prev_idx(&self,a_idx:u32) -> u32\n"
"{/*{{{*/\n"
"  unsafe{%s_get_prev_idx(self as *const Self,a_idx)}\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
}/*}}}*/

void RUST_RB_TREE___ROTATE_LEFT(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn __rotate_left(&mut self,a_idx:u32)\n"
"{/*{{{*/\n"
"  let root = unsafe{&mut *self.data.offset(a_idx as isize)};\n"
"  let pivot = unsafe{&mut *self.data.offset(root.right_idx as isize)};\n"
"\n"
"  if a_idx == self.root_idx\n"
"  {\n"
"    self.root_idx = root.right_idx;\n"
"    pivot.parent_idx = c_idx_not_exist;\n"
"  }\n"
"  else\n"
"  {\n"
"    let rp = unsafe{&mut *self.data.offset(root.parent_idx as isize)};\n"
"\n"
"    if rp.right_idx == a_idx\n"
"    {\n"
"      rp.right_idx = root.right_idx;\n"
"    }\n"
"    else\n"
"    {\n"
"      rp.left_idx = root.right_idx;\n"
"    }\n"
"\n"
"    pivot.parent_idx = root.parent_idx;\n"
"  }\n"
"\n"
"  root.parent_idx = root.right_idx;\n"
"\n"
"  root.right_idx = pivot.left_idx;\n"
"  unsafe{&mut *self.data.offset(root.right_idx as isize)}.parent_idx = a_idx;\n"
"\n"
"  pivot.left_idx = a_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_RB_TREE___ROTATE_RIGHT(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn __rotate_right(&mut self,a_idx:u32)\n"
"{/*{{{*/\n"
"  let root = unsafe{&mut *self.data.offset(a_idx as isize)};\n"
"  let pivot = unsafe{&mut *self.data.offset(root.left_idx as isize)};\n"
"\n"
"  if a_idx == self.root_idx\n"
"  {\n"
"    self.root_idx = root.left_idx;\n"
"    pivot.parent_idx = c_idx_not_exist;\n"
"  }\n"
"  else\n"
"  {\n"
"    let rp = unsafe{&mut *self.data.offset(root.parent_idx as isize)};\n"
"\n"
"    if rp.right_idx == a_idx\n"
"    {\n"
"      rp.right_idx = root.left_idx;\n"
"    }\n"
"    else\n"
"    {\n"
"      rp.left_idx = root.left_idx;\n"
"    }\n"
"\n"
"    pivot.parent_idx = root.parent_idx;\n"
"  }\n"
"\n"
"  root.parent_idx = root.left_idx;\n"
"\n"
"  root.left_idx = pivot.right_idx;\n"
"  unsafe{&mut *self.data.offset(root.left_idx as isize)}.parent_idx = a_idx;\n"
"\n"
"  pivot.right_idx = a_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_RB_TREE___GET_NEW_INDEX(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn __get_new_index(&mut self) -> u32\n"
"{/*{{{*/\n"
"  let new_idx;\n"
"\n"
"  if self.free_idx != c_idx_not_exist\n"
"  {\n"
"    new_idx = self.free_idx;\n"
"    self.free_idx = unsafe{&*self.data.offset(new_idx as isize)}.parent_idx;\n"
"  }\n"
"  else\n"
"  {\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"    if self.used >= self.size\n"
"    {\n"
"      let new_size = (self.size << 1) + c_array_add;\n"
"      debug_assert!(new_size != 0);\n"
"\n"
"      unsafe{%s_copy_resize(self as *mut Self,new_size)};\n"
,STRUCT_NAME);
fprintf(out_file,
"    }\n"
"\n"
);
   }
   else {
fprintf(out_file,
"    debug_assert!(self.used < self.size);\n"
"\n"
);
   }

fprintf(out_file,
"    if self.leaf_idx == c_idx_not_exist\n"
"    {\n"
"      self.leaf_idx = self.used;\n"
"      self.used += 1;\n"
"      let leaf = unsafe{&mut *self.data.offset(self.leaf_idx as isize)};\n"
"\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"      leaf.valid = 0;\n"
"      leaf.color = 1;\n"
);
   }
   else {
fprintf(out_file,
"      leaf.color = 1;\n"
);
   }
   if (STRUCT_NUMBER & c_type_option_check_properties) {
fprintf(out_file,
"\n"
"      leaf.left_idx = c_idx_not_exist;\n"
"      leaf.right_idx = c_idx_not_exist;\n"
);
   }
fprintf(out_file,
"    }\n"
"\n"
);

fprintf(out_file,
"    new_idx = self.used;\n"
"    self.used += 1;\n"
"  }\n"
"\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  unsafe{&mut *self.data.offset(new_idx as isize)}.valid = 1;\n"
"  self.count += 1;\n"
"\n"
);
   }
fprintf(out_file,
"  new_idx\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_RB_TREE___BINARY_TREE_INSERT(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn __binary_tree_insert(&mut self,a_new_idx:u32,a_value:&%s,a_unique:bool) -> u32\n"
"{/*{{{*/\n"
"  unsafe{%s___binary_tree_insert(self as *mut Self,a_new_idx,a_value as *const %s,a_unique as i32)}\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAMES(0),STRUCT_NAME,TYPE_NAMES(0));
}/*}}}*/

void RUST_RB_TREE___REPLACE_DELETE_NODE_BY_CHILD(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn __replace_delete_node_by_child(&mut self,a_idx:u32,a_ch_idx:u32)\n"
"{/*{{{*/\n"
"  let node = unsafe{&*self.data.offset(a_idx as isize)};\n"
"\n"
"  if node.parent_idx != c_idx_not_exist\n"
"  {\n"
"    let parent = unsafe{&mut *self.data.offset(node.parent_idx as isize)};\n"
"\n"
"    if parent.left_idx == a_idx\n"
"    {\n"
"      parent.left_idx = a_ch_idx;\n"
"    }\n"
"    else\n"
"    {\n"
"      parent.right_idx = a_ch_idx;\n"
"    }\n"
"\n"
"    unsafe{&mut *self.data.offset(a_ch_idx as isize)}.parent_idx = node.parent_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    self.root_idx = if a_ch_idx == self.leaf_idx { c_idx_not_exist } else { a_ch_idx };\n"
"    unsafe{&mut *self.data.offset(a_ch_idx as isize)}.parent_idx = c_idx_not_exist;\n"
"  }\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_RB_TREE___REMOVE_BLACK_BLACK(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn __remove_black_black(&mut self,a_idx:u32)\n"
"{/*{{{*/\n"
"  unsafe{%s___remove_black_black(self as *mut Self,a_idx)}\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
}/*}}}*/

void RUST_RB_TREE___REMOVE_ONE_CHILD(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn __remove_one_child(&mut self,a_idx:u32,a_ch_idx:u32)\n"
"{/*{{{*/\n"
"  let node = unsafe{&mut *self.data.offset(a_idx as isize)};\n"
"  self.__replace_delete_node_by_child(a_idx,a_ch_idx);\n"
"\n"
"  node.parent_idx = self.free_idx;\n"
"  self.free_idx = a_idx;\n"
"\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  node.valid = 0;\n"
"  self.count -= 1;\n"
"\n"
);
   }
fprintf(out_file,
"  if node.color != 0\n"
"  {\n"
"    let child_node = unsafe{&mut *self.data.offset(a_ch_idx as isize)};\n"
"\n"
"    if child_node.color == 0\n"
"    {\n"
"      child_node.color = 1;\n"
"    }\n"
"    else\n"
"    {\n"
"      self.__remove_black_black(a_ch_idx);\n"
"    }\n"
"  }\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_RB_TREE___INSERT_OPERATION(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn __insert_operation(&mut self,a_idx:u32)\n"
"{/*{{{*/\n"
"  unsafe{%s___insert_operation(self as *mut Self,a_idx)}\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
}/*}}}*/

void RUST_RB_TREE_INIT(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn init(&mut self)\n"
"{/*{{{*/\n"
"  self.size = 0;\n"
"  self.used = 0;\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  self.count = 0;\n"
);
   }
fprintf(out_file,
"  self.data = std::ptr::null_mut();\n"
"  self.free_idx = c_idx_not_exist;\n"
"  self.root_idx = c_idx_not_exist;\n"
"  self.leaf_idx = c_idx_not_exist;\n"
);
   if (VAR_NAMES_CNT > 0) {
fprintf(out_file,
"\n"
);
      unsigned t_idx = 0;
      do {
         if (TYPE_NUMBERS(t_idx + 1) & (c_type_dynamic | c_type_option_force_init)) {
fprintf(out_file,
"  self.%s.init();\n"
,VAR_NAMES(t_idx));
         }
      } while(++t_idx < VAR_NAMES_CNT);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_RB_TREE_INIT_BUFFER(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn init_buffer(&mut self,a_size:u32,a_data:*const %s_node)\n"
"{/*{{{*/\n"
"  self.init();\n"
"  self.set_buffer(a_size,a_data);\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
}/*}}}*/

void RUST_RB_TREE_CLEAR(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
fprintf(out_file,
"fn clear(&mut self)\n"
);
fprintf(out_file,
"{/*{{{*/\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  if self.data != std::ptr::null_mut()\n"
"  {\n"
);
      if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"    unsafe{free(self.data as *mut c_void);}\n"
);
      }
fprintf(out_file,
"  }\n"
"\n"
);
   }
   if (VAR_NAMES_CNT > 0) {
      unsigned t_idx = 0;
      do {
         if (TYPE_NUMBERS(t_idx + 1) & c_type_dynamic) {
fprintf(out_file,
"  self.%s.clear();\n"
,VAR_NAMES(t_idx));
         }
      } while(++t_idx < VAR_NAMES_CNT);
fprintf(out_file,
"\n"
);
   }
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  self.size = 0;\n"
);
   }
fprintf(out_file,
"  self.used = 0;\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  self.count = 0;\n"
);
   }
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  self.data = std::ptr::null_mut();\n"
);
   }
fprintf(out_file,
"  self.free_idx = c_idx_not_exist;\n"
"  self.root_idx = c_idx_not_exist;\n"
"  self.leaf_idx = c_idx_not_exist;\n"
);
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
   }
   else {
fprintf(out_file,
"fn clear(&mut self)\n"
"{/*{{{*/\n"
"  unsafe{%s_clear(self as *mut Self);}\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
   }
}/*}}}*/

void RUST_RB_TREE_SET_BUFFER(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
fprintf(out_file,
"fn set_buffer(&mut self,a_size:u32,a_data:*mut %s_node)\n"
,STRUCT_NAME);
fprintf(out_file,
"{/*{{{*/\n"
"  debug_assert!(a_size > 1 && a_data != std::ptr::null_mut());\n"
"\n"
"  self.clear();\n"
);
   if (TYPE_NUMBERS(0) & (c_type_dynamic | c_type_option_force_init)) {
fprintf(out_file,
"\n"
"  let mut idx:u32 = 0;\n"
"  while idx < a_size\n"
"  {\n"
"    unsafe{&mut *self.data.offset(idx as isize)}.object.init();\n"
"    idx += 1;\n"
"  }\n"
);
   }
fprintf(out_file,
"\n"
"  self.size = a_size;\n"
"  self.data = a_data;\n"
"}/*}}}*/\n"
"\n"
);
   }
   else {
fprintf(out_file,
"fn set_buffer(&mut self,a_size:u32,a_data:*mut a_data)\n"
"{/*{{{*/\n"
"  unsafe{%s_set_buffer(self as *mut Self,a_size,a_data:*mut %s_node)}\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME,STRUCT_NAME);
   }
}/*}}}*/

void RUST_RB_TREE_FLUSH(RUST_RB_TREE_GEN_PARAMS)
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

void RUST_RB_TREE_FLUSH_ALL(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBERS(0) & c_type_flushable)) {
fprintf(out_file,
"fn flush_all(&mut self)\n"
"{/*{{{*/\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  self.copy_resize(self.used);\n"
);
   }
   if (VAR_NAMES_CNT > 0) {
      if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"\n"
);
      }
      unsigned t_idx = 0;
      do {
         if (TYPE_NUMBERS(t_idx + 1) & c_type_flushable) {
fprintf(out_file,
"  self.%s.flush_all();\n"
,VAR_NAMES(t_idx));
         }
      } while(++t_idx < VAR_NAMES_CNT);
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
"  unsafe{%s_flush_all(self as *mut Self)}\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
   }
}/*}}}*/

void RUST_RB_TREE_SWAP(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn swap(&mut self,a_second:&mut Self)\n"
"{/*{{{*/\n"
"  std::mem::swap(self,a_second);\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RUST_RB_TREE_OPERATOR_LE_BR_RE_BR(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn at(&self,a_idx:u32) -> &mut %s\n"
"{/*{{{*/\n"
,TYPE_NAMES(0));
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  debug_assert!(a_idx < self.used && unsafe{(*self.data.offset(a_idx as isize)).valid} != 0);\n"
);
   }
   else {
fprintf(out_file,
"  debug_assert!(a_idx < self.used);\n"
);
   }
fprintf(out_file,
"  unsafe{&mut (*self.data.offset(a_idx as isize)).object}\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

#define TEMPLATE_RUST_RB_TREE_INSERT(FUN_NAME,VALUE_CONST,VALUE_SET_CODE) \
{/*{{{*/\
   if (TYPE_NUMBERS(0) & c_type_basic) {\
fprintf(out_file,\
"fn %s(&mut self,a_value:%s) -> u32\n"\
,#FUN_NAME,TYPE_NAMES(0));\
   }\
   else {\
fprintf(out_file,\
"fn %s(&mut self,a_value:&%s%s) -> u32\n"\
,#FUN_NAME,VALUE_CONST ? "" : "mut ",TYPE_NAMES(0));\
   }\
fprintf(out_file,\
"{/*{{{*/\n"\
"  let new_node_idx = self.__get_new_index();\n"\
"\n"\
);\
   if (TYPE_NUMBERS(0) & c_type_basic) {\
fprintf(out_file,\
"  self.__binary_tree_insert(new_node_idx,&a_value,false);\n"\
);\
   }\
   else {\
fprintf(out_file,\
"  self.__binary_tree_insert(new_node_idx,a_value,false);\n"\
);\
   }\
fprintf(out_file,\
"  self.__insert_operation(new_node_idx);\n"\
"\n"\
);\
   VALUE_SET_CODE;\
fprintf(out_file,\
"\n"\
"  new_node_idx\n"\
"}/*}}}*/\n"\
"\n"\
);\
}/*}}}*/

void RUST_RB_TREE_INSERT(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
TEMPLATE_RUST_RB_TREE_INSERT(insert,true,
   if (TYPE_NUMBERS(0) & (c_type_basic | c_type_static)) {
fprintf(out_file,
"  unsafe{(*self.data.offset(new_node_idx as isize)).object = a_value};\n"
);
   }
   else {
fprintf(out_file,
"  unsafe{(*self.data.offset(new_node_idx as isize)).object.copy(a_value)};\n"
);
   }
);
}/*}}}*/

void RUST_RB_TREE_SWAP_INSERT(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBERS(0) & c_type_dynamic) {
TEMPLATE_RUST_RB_TREE_INSERT(swap_insert,false,
fprintf(out_file,
"  unsafe{(*self.data.offset(new_node_idx as isize)).object.swap(a_value)};\n"
);
);
   }
}/*}}}*/

#define TEMPLATE_RUST_RB_TREE_UNIQUE_INSERT(FUN_NAME,VALUE_CONST,VALUE_SET_CODE) \
{/*{{{*/\
   if (TYPE_NUMBERS(0) & c_type_basic) {\
fprintf(out_file,\
"fn %s(&mut self,a_value:%s) -> u32\n"\
,#FUN_NAME,TYPE_NAMES(0));\
   }\
   else {\
fprintf(out_file,\
"fn %s(&mut self,a_value:&%s%s) -> u32\n"\
,#FUN_NAME,VALUE_CONST ? "" : "mut ",TYPE_NAMES(0));\
   }\
fprintf(out_file,\
"{/*{{{*/\n"\
"  let new_node_idx = self.__get_new_index();\n"\
);\
   if (TYPE_NUMBERS(0) & c_type_basic) {\
fprintf(out_file,\
"  let old_node_idx = self.__binary_tree_insert(new_node_idx,&a_value,true);\n"\
);\
   }\
   else {\
fprintf(out_file,\
"  let old_node_idx = self.__binary_tree_insert(new_node_idx,a_value,true);\n"\
);\
   }\
fprintf(out_file,\
"\n"\
"  if old_node_idx != c_idx_not_exist\n"\
"  {\n"\
"    let new_node = unsafe {&mut *self.data.offset(new_node_idx as isize)};\n"\
"\n"\
"    new_node.parent_idx = self.free_idx;\n"\
"    self.free_idx = new_node_idx;\n"\
"\n"\
);\
   if (STRUCT_NUMBER & c_type_option_safe) {\
fprintf(out_file,\
"    new_node.valid = 0;\n"\
"    self.count -= 1;\n"\
"\n"\
);\
   }\
fprintf(out_file,\
"    return old_node_idx;\n"\
"  }\n"\
"\n"\
"  self.__insert_operation(new_node_idx);\n"\
"\n"\
);\
   VALUE_SET_CODE;\
fprintf(out_file,\
"\n"\
"  new_node_idx\n"\
"}/*}}}*/\n"\
"\n"\
);\
}/*}}}*/

void RUST_RB_TREE_UNIQUE_INSERT(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
TEMPLATE_RUST_RB_TREE_UNIQUE_INSERT(unique_insert,true,
   if (TYPE_NUMBERS(0) & (c_type_basic | c_type_static)) {
fprintf(out_file,
"  unsafe{(*self.data.offset(new_node_idx as isize)).object = a_value};\n"
);
   }
   else {
fprintf(out_file,
"  unsafe{(*self.data.offset(new_node_idx as isize)).object.copy(a_value)};\n"
);
   }
);
}/*}}}*/

void RUST_RB_TREE_UNIQUE_SWAP_INSERT(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBERS(0) & c_type_dynamic) {
TEMPLATE_RUST_RB_TREE_UNIQUE_INSERT(unique_swap_insert,false,
fprintf(out_file,
"  unsafe{(*self.data.offset(new_node_idx as isize)).object.swap(a_value)};\n"
);
);
   }
}/*}}}*/

void RUST_RB_TREE_REMOVE(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn remove(&mut self,a_idx:u32)\n"
"{/*{{{*/\n"
"  unsafe{%s_remove(self as *mut Self,a_idx)}\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
}/*}}}*/

void RUST_RB_TREE_COPY_RESIZE(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn copy_resize(&mut self,a_size:u32)\n"
"{/*{{{*/\n"
"  unsafe{%s_copy_resize(self as *mut Self,a_size)}\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
}/*}}}*/

void RUST_RB_TREE_GET_IDX(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"fn get_idx(&self,a_value:%s) -> u32\n"
"{/*{{{*/\n"
"  unsafe{%s_get_idx(self as *const Self,a_value)}\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAMES(0),STRUCT_NAME);
   }
   else {
fprintf(out_file,
"fn get_idx(&self,a_value:&%s) -> u32\n"
"{/*{{{*/\n"
"  unsafe{%s_get_idx(self as *const Self,a_value as *const %s)}\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAMES(0),STRUCT_NAME,TYPE_NAMES(0));
   }
}/*}}}*/

void RUST_RB_TREE_GET_IDX_LEFT(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"fn get_idx_left(&self,a_value:%s) -> u32\n"
"{/*{{{*/\n"
"  unsafe{%s_get_idx_left(self as *const Self,a_value)}\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAMES(0),STRUCT_NAME);
   }
   else {
fprintf(out_file,
"fn get_idx_left(&self,a_value:&%s) -> u32\n"
"{/*{{{*/\n"
"  unsafe{%s_get_idx_left(self as *const Self,a_value as *const %s)}\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAMES(0),STRUCT_NAME,TYPE_NAMES(0));
   }
}/*}}}*/

void RUST_RB_TREE_GET_GRE_IDX(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"fn get_gre_idx(&self,a_value:%s) -> u32\n"
"{/*{{{*/\n"
"  unsafe{%s_get_gre_idx(self as *const Self,a_value)}\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAMES(0),STRUCT_NAME);
   }
   else {
fprintf(out_file,
"fn get_gre_idx(&self,a_value:&%s) -> u32\n"
"{/*{{{*/\n"
"  unsafe{%s_get_gre_idx(self as *const Self,a_value as *const %s)}\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAMES(0),STRUCT_NAME,TYPE_NAMES(0));
   }
}/*}}}*/

void RUST_RB_TREE_GET_LEE_IDX(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"fn get_lee_idx(&self,a_value:%s) -> u32\n"
"{/*{{{*/\n"
"  unsafe{%s_get_lee_idx(self as *const Self,a_value)}\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAMES(0),STRUCT_NAME);
   }
   else {
fprintf(out_file,
"fn get_lee_idx(&self,a_value:&%s) -> u32\n"
"{/*{{{*/\n"
"  unsafe{%s_get_lee_idx(self as *const Self,a_value as *const %s)}\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAMES(0),STRUCT_NAME,TYPE_NAMES(0));
   }
}/*}}}*/

void RUST_RB_TREE_GET_IDXS(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"fn get_idxs(&self,a_value:%s,a_idxs_array:&mut ui_array_s)\n"
"{/*{{{*/\n"
"  unsafe{%s_get_idxs(self as *const Self,a_value,a_idxs_array as *mut ui_array_s)}\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAMES(0),STRUCT_NAME);
   }
   else {
fprintf(out_file,
"fn get_idxs(&self,a_value:*const %s,a_idxs_array:&mut ui_array_s)\n"
"{/*{{{*/\n"
"  unsafe{%s_get_idxs(self as *const Self,a_value,a_idxs_array as *mut ui_array_s)}\n"
"}/*}}}*/\n"
"\n"
,TYPE_NAMES(0),STRUCT_NAME);
   }
}/*}}}*/

void RUST_RB_TREE_OPERATOR_EQUAL(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
fprintf(out_file,
"fn copy(&mut self,a_src:&Self)\n"
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
"  if self.root_idx == c_idx_not_exist\n"
"  {\n"
"    return;\n"
"  }\n"
);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"\n"
"  debug_assert!(a_src.used != 0);\n"
"  self.copy_resize(a_src.used);\n"
);
   }
   if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
fprintf(out_file,
"\n"
"  unsafe{std::ptr::copy_nonoverlapping(a_src.data,self.data,a_src.used as usize);}\n"
);
   }
fprintf(out_file,
"\n"
"  self.used = a_src.used;\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  self.count = a_src.count;\n"
);
   }
fprintf(out_file,
"  self.free_idx = a_src.free_idx;\n"
"  self.root_idx = a_src.root_idx;\n"
"  self.leaf_idx = a_src.leaf_idx;\n"
);
   if (VAR_NAMES_CNT > 0) {
fprintf(out_file,
"\n"
);
      unsigned t_idx = 0;
      do {
         if (!(TYPE_NUMBERS(t_idx + 1) & c_type_dynamic)) {
fprintf(out_file,
"  self.%s = a_src.%s;\n"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
         }
         else {
fprintf(out_file,
"  self.%s.copy(&a_src.%s);\n"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
         }
      } while(++t_idx < VAR_NAMES_CNT);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
   }
   else {
fprintf(out_file,
"fn copy(&mut self,a_src:&Self)\n"
"{/*{{{*/\n"
"  unsafe{%s_copy(self as *mut Self,a_src as *const Self);}\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
   }
}/*}}}*/

void RUST_RB_TREE_OPERATOR_DOUBLE_EQUAL(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn compare(&self,a_second:&%s) -> bool\n"
"{/*{{{*/\n"
"  unsafe{%s_compare(self as *const Self,a_second as *const Self) != 0}\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME,STRUCT_NAME);
}/*}}}*/

void RUST_RB_TREE_TO_STRING(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#[cfg(OPTION_TO_STRING = \"ENABLED\")]\n"
"fn __to_string(&self,a_trg:&mut bc_array_s)\n"
"{/*{{{*/\n"
"  unsafe{%s___to_string(self as *const Self,a_trg as *mut bc_array_s);}\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
}/*}}}*/

void RUST_RB_TREE_TO_STRING_SEPARATOR(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#[cfg(OPTION_TO_STRING = \"ENABLED\")]\n"
"fn to_string_separator(&self,a_trg:&mut bc_array_s,a_sep:&str)\n"
"{/*{{{*/\n"
"  unsafe{%s_to_string_separator(self as *const Self,a_trg as *mut bc_array_s,a_sep.len() as c_uint,a_sep.as_ptr() as *const c_char);}\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
}/*}}}*/

void RUST_RB_TREE_TO_JSON(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#[cfg(OPTION_TO_JSON = \"ENABLED\")]\n"
"void fn to_json(&self,a_trg:&mut bc_array_s)\n"
"{/*{{{*/\n"
"  unsafe{%s_to_json(self as *const Self,a_trg as *mut bc_array_s);}\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
}/*}}}*/

void RUST_RB_TREE_TO_JSON_NICE(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#[cfg(OPTION_TO_JSON = \"ENABLED\")]\n"
"fn to_json_nice(&self,a_json_nice:&mut json_nice_s,a_trg:&mut bc_array_s)\n"
"{/*{{{*/\n"
"  unsafe{%s_to_json_nice(self as *const Self,a_json_nice as *mut json_nice_s,a_trg as *mut bc_array_s);}\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
}/*}}}*/

void RUST_RB_TREE_FROM_VAR(RUST_RB_TREE_GEN_PARAMS)
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
"    %s_copy_resize(this,array->used + 1);\n"
"\n"
"    var_s *v_ptr = array->data;\n"
"    var_s *v_ptr_end = v_ptr + array->used;\n"
"    do {\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
fprintf(out_file,
"      %s value;\n"
,TYPE_NAMES(0));
      if (TYPE_NUMBERS(0) & c_type_option_force_init) {
fprintf(out_file,
"      %s_init(&value);\n"
,TYPE_NAMES(0));
      }
fprintf(out_file,
"\n"
"      if (%s_from_var(&value,*v_ptr))\n"
"      {\n"
"        throw_error(FROM_VAR_ERROR);\n"
"      }\n"
"\n"
,TYPE_NAMES(0));
      if (TYPE_NUMBERS(0) & c_type_basic)
      {
fprintf(out_file,
"      %s_insert(this,value);\n"
,STRUCT_NAME);
      }
      else
      {
fprintf(out_file,
"      %s_insert(this,&value);\n"
,STRUCT_NAME);
      }
   }
   else {
fprintf(out_file,
"      %s value;\n"
"      %s_init(&value);\n"
"\n"
"      if (%s_from_var(&value,*v_ptr))\n"
"      {\n"
"        %s_clear(&value);\n"
"\n"
"        throw_error(FROM_VAR_ERROR);\n"
"      }\n"
"\n"
"      %s_swap_insert(this,&value);\n"
"      %s_clear(&value);\n"
,TYPE_NAMES(0),TYPE_NAMES(0),TYPE_NAMES(0),TYPE_NAMES(0)
,STRUCT_NAME,TYPE_NAMES(0));
   }
fprintf(out_file,
"    } while(++v_ptr < v_ptr_end);\n"
"  }\n"
"\n"
"  return 0;\n"
"}/*}}}*/\n"
"#endif\n"
"\n"
);
}/*}}}*/

void RUST_RB_TREE_FROM_JSON(RUST_RB_TREE_GEN_PARAMS)
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
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
fprintf(out_file,
"      %s value;\n"
,TYPE_NAMES(0));
      if (TYPE_NUMBERS(0) & c_type_option_force_init) {
fprintf(out_file,
"      %s_init(&value);\n"
,TYPE_NAMES(0));
      }
fprintf(out_file,
"\n"
"      if (%s_from_json(&value,a_src,a_from_json))\n"
"      {\n"
"        throw_error(FROM_JSON_ERROR);\n"
"      }\n"
"\n"
,TYPE_NAMES(0));
      if (TYPE_NUMBERS(0) & c_type_basic)
      {
fprintf(out_file,
"      %s_insert(this,value);\n"
,STRUCT_NAME);
      }
      else
      {
fprintf(out_file,
"      %s_insert(this,&value);\n"
,STRUCT_NAME);
      }
   }
   else {
fprintf(out_file,
"      %s value;\n"
"      %s_init(&value);\n"
"\n"
"      if (%s_from_json(&value,a_src,a_from_json))\n"
"      {\n"
"        %s_clear(&value);\n"
"\n"
"        throw_error(FROM_JSON_ERROR);\n"
"      }\n"
"\n"
"      %s_swap_insert(this,&value);\n"
"      %s_clear(&value);\n"
,TYPE_NAMES(0),TYPE_NAMES(0),TYPE_NAMES(0),TYPE_NAMES(0)
,STRUCT_NAME,TYPE_NAMES(0));
   }
fprintf(out_file,
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
);
}/*}}}*/

void RUST_RB_TREE_REHASH_TREE(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn rehash_tree(&mut self)\n"
"{/*{{{*/\n"
"  unsafe{%s_rehash_tree(self as *mut Self);}\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
}/*}}}*/

void RUST_RB_TREE_PRINT_DOT_CODE(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"void %s_print_dot_code(const %s *this,FILE *a_file)\n"
"{/*{{{*/\n"
"  fprintf(a_file,\n"
"\"digraph G {\\n\"\n"
"\"   rankdir = TD\\n\"\n"
"\"   node [ shape = circle margin = 0.0 fixedsize = true width = 0.7 height = 0.7]\\n\"\n"
"\"\\n\"\n"
"  );\n"
"\n"
"  const char *node_colors[] = {\n"
"    \"red\",\n"
"    \"black\",\n"
"  };\n"
"\n"
"  fprintf(a_file,\n"
"\"   root_idx [label = \\\"R\\\" ]\\n\"\n"
"\"   root_idx -> node_%%u\\n\"\n"
"  ,this->root_idx);\n"
"\n"
"  if (this->root_idx != c_idx_not_exist)\n"
"  {\n"
"    ui_array_s stack;\n"
"    ui_array_s_init(&stack);\n"
"\n"
"    ui_array_s_push(&stack,this->root_idx);\n"
"    do {\n"
"      unsigned node_idx = ui_array_s_pop(&stack);\n"
"      %s_node *node = this->data + node_idx;\n"
"\n"
"      /* - print node - */\n"
"      fprintf(a_file,\n"
"\"   node_%%u [ color = \\\"%%s\\\" label = \\\"%%u\\\" ]\\n\"\n"
"      ,node_idx,node_colors[(int)node->color],node_idx);\n"
"\n"
"      if (node->parent_idx != c_idx_not_exist)\n"
"      {\n"
"        fprintf(a_file,\n"
"\"   node_%%u -> node_%%u [ color = green ] \\n\"\n"
"        ,node_idx,node->parent_idx);\n"
"      }\n"
"\n"
"      if (node->left_idx != this->leaf_idx)\n"
"      {\n"
"        fprintf(a_file,\n"
"\"   node_%%u -> node_%%u [ label = \\\"L\\\" ]\\n\"\n"
"        ,node_idx,node->left_idx);\n"
"\n"
"        ui_array_s_push(&stack,node->left_idx);\n"
"      }\n"
"\n"
"      if (node->right_idx != this->leaf_idx)\n"
"      {\n"
"        fprintf(a_file,\n"
"\"   node_%%u -> node_%%u [ label = \\\"R\\\" ]\\n\"\n"
"        ,node_idx,node->right_idx);\n"
"\n"
"        ui_array_s_push(&stack,node->right_idx);\n"
"      }\n"
"    } while(stack.used > 0);\n"
"\n"
"    ui_array_s_clear(&stack);\n"
"  }\n"
"\n"
"  fprintf(a_file,\n"
"\"}\\n\"\n"
"\"\\n\");\n"
"\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
}/*}}}*/

void RUST_RB_TREE_CHECK_PROPERTIES(RUST_RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"fn check_properties(&self) -> bool\n"
"{/*{{{*/\n"
"  unsafe{%s_check_properties(self as *const Self) != 0}\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME);
}/*}}}*/

void processor_s::generate_rust_rb_tree_type()
{/*{{{*/
   string_array_s &type_names = cont_params.types;
   string_array_s &variables = cont_params.variables;
   string_array_s &fun_defs = cont_params.functions;
   string_array_s &abbs = cont_params.names;

   if (type_names.used < 1) {
      fprintf(stderr,"rb_tree: not given name of contained type\n");
      cassert(0);
   }

   if (variables.used != (type_names.used - 1)) {
      fprintf(stderr,"rb_tree: not enought names for variables\n");
      cassert(0);
   }

   if (abbs.used < 1) {
      fprintf(stderr,"rb_tree: not given name of generated structure\n");
      cassert(0);
   }

   unsigned type_cnt = type_names.used;

#ifdef _MSC_VER
   unsigned type_idxs[256];
   data_type_s *types[256];

   if (type_cnt > 256) {
      fprintf(stderr,"rb_tree: too many contained types, max 256 supported\n");
      cassert(0);
   }
#else
   unsigned type_idxs[type_cnt];
   data_type_s *types[type_cnt];
#endif

   {
      unsigned tn_idx = 0;
      do {
         unsigned type_abb_idx = abbreviations.get_idx_by_name(type_names[tn_idx].size - 1,type_names[tn_idx].data);
         if (type_abb_idx == c_idx_not_exist) {
            fprintf(stderr,"rb_tree: contained type \"%s\" does not exist\n",type_names[tn_idx].data);
            cassert(0);
         }

         unsigned type_idx = abbreviations[type_abb_idx].data_type_idx;
         type_idxs[tn_idx] = type_idx;

         // - test type options -
         if (data_types[type_idx].properties & c_type_option_strict_dynamic) {
            fprintf(stderr,"rb_tree: option strict_dynamic not supported\n");
            cassert(0);
         }

      } while(++tn_idx < type_cnt);
   }

   // - compute length of type name -
   unsigned data_type_name_len = 0;
   {
      unsigned t_idx = 0;
      do {
         data_type_name_len += data_types[type_idxs[t_idx]].name.size;
      } while(++t_idx < type_cnt);

      data_type_name_len += strlen(c_cont_postfixes[c_cont_rust_rb_tree]) - 1;
   }

   // - compose name of type -
   string_s real_name;
   real_name.init();
   real_name.create(data_type_name_len);

   {
      unsigned t_idx = 0;
      char *dtn_ptr = real_name.data;
      do {
         data_type_s &type = data_types[type_idxs[t_idx]];
         memcpy(dtn_ptr,type.name.data,type.name.size - 1);
         dtn_ptr += type.name.size - 1;
         *dtn_ptr++ = '_';
      } while(++t_idx < type_cnt);

      memcpy(--dtn_ptr,c_cont_postfixes[c_cont_rust_rb_tree],strlen(c_cont_postfixes[c_cont_rust_rb_tree]));
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

      data_type.cont_idx = c_cont_rust_rb_tree;
      data_type.name.set(data_type_name.size - 1,data_type_name.data);
      data_type.real_name.swap(real_name);

      // - retrieve of types pointers -
      {
         unsigned tn_idx = 0;
         do {
            types[tn_idx] = &data_types[type_idxs[tn_idx]];
         } while(++tn_idx < type_cnt);
      }

      data_type.properties = c_type_dynamic | c_type_flushable | (type_settings & c_type_option_mask);

      {
         string_array_s &dt_type_names = data_type.types;
         string_s *tn_ptr = type_names.data;
         string_s *tn_ptr_end = type_names.data + type_cnt;

         do {
            dt_type_names.push(*tn_ptr);
         } while(++tn_ptr < tn_ptr_end);
      }

      data_type.variables.swap(variables);

      data_type_idx = data_types.used - 1;
   }
   else {
      fprintf(stderr,"rb_tree: name of generated structure \"%s\" is already used\n",data_type_name.data);
      cassert(0);
   }

   real_name.clear();

   // - check and write abbreviations -
   if (abbs.used != 0) {
      unsigned idx = 0;
      do {
         string_s &abb = abbs[idx];

         if (abbreviations.get_idx_by_name(abb.size - 1,abb.data) != c_idx_not_exist) {
            fprintf(stderr,"rb_tree: abreviated name \"%s\" for generated structure is already used\n",abb.data);
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
   // - definition of structure rb_tree -

fprintf(out_file,
"// struct %s definition\n"
"\n"
,STRUCT_NAME);

    unsigned idx = 0;
    while (++idx < abbs.used) {
fprintf(out_file,
"type %s = %s;\n"
,abbs[idx].data,abbs[0].data);
    }
fprintf(out_file,
"\n"
);

fprintf(out_file,
"#[repr(C)] pub struct %s_node\n"
"{\n"
"  parent_idx:u32,\n"
"  left_idx:u32,\n"
"  right_idx:u32,\n"
"  color:u8,\n"
,STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  valid:u8,\n"
);
   }
fprintf(out_file,
"  object:%s,\n"
"}\n"
"\n"
"#[repr(C)] pub struct %s\n"
"{\n"
"  size:u32,\n"
"  used:u32,\n"
,TYPE_NAMES(0),STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  count:u32,\n"
);
   }
fprintf(out_file,
"  data:*mut %s_node,\n"
"  free_idx:u32,\n"
"  root_idx:u32,\n"
"  leaf_idx:u32,\n"
,STRUCT_NAME);
   if (VAR_NAMES_CNT > 0) {
      unsigned t_idx = 0;
      do {
fprintf(out_file,
"  %s:%s,\n"
,VAR_NAMES(t_idx),TYPE_NAMES(t_idx + 1));
      } while(++t_idx < VAR_NAMES_CNT);
   }
fprintf(out_file,
"}\n"
"\n"
"extern {\n"
);
fprintf(out_file,
"fn %s_get_stack_min_value_idx(this:*const %s,a_idx:c_uint,a_s_ptr:*mut *mut c_uint) -> c_uint;\n"
,STRUCT_NAME,STRUCT_NAME);
fprintf(out_file,
"fn %s_get_min_value_idx(this:*const %s,a_idx:c_uint) -> c_uint;\n"
"fn %s_get_max_value_idx(this:*const %s,a_idx:c_uint) -> c_uint;\n"
"fn %s_get_next_idx(this:*const %s,a_idx:c_uint) -> c_uint;\n"
"fn %s_get_prev_idx(this:*const %s,a_idx:c_uint) -> c_uint;\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
fprintf(out_file,
"fn %s___binary_tree_insert(this:*mut %s,a_new_idx:c_uint,a_value:*const %s,a_unique:c_int) -> c_uint;\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAMES(0));
fprintf(out_file,
"fn %s___remove_black_black(this:*mut %s,a_idx:c_uint);\n"
"fn %s___insert_operation(this:*mut %s,a_idx:c_uint);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
      if (TYPE_NUMBERS(0) & c_type_dynamic) {
fprintf(out_file,
"fn %s_clear(this:*mut %s);\n"
,STRUCT_NAME,STRUCT_NAME);
      }
   }
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
      if (TYPE_NUMBERS(0) & c_type_dynamic) {
fprintf(out_file,
"fn %s_set_buffer(this:*mut %s,a_size:c_uint,a_data:*const %s_node);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
      }
   }
   if (TYPE_NUMBERS(0) & c_type_flushable) {
fprintf(out_file,
"fn %s_flush_all(this:*mut %s);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
fprintf(out_file,
"fn %s_remove(this:*mut %s,a_idx:c_uint);\n"
,STRUCT_NAME,STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"fn %s_copy_resize(this:*mut %s,a_size:c_uint);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"fn %s_get_idx(this:*const %s,a_value:%s) -> c_uint;\n"
"fn %s_get_idx_left(this:*const %s,a_value:%s) -> c_uint;\n"
"fn %s_get_gre_idx(this:*const %s,a_value:%s) -> c_uint;\n"
"fn %s_get_lee_idx(this:*const %s,a_value:%s) -> c_uint;\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAMES(0)
,STRUCT_NAME,STRUCT_NAME,TYPE_NAMES(0)
,STRUCT_NAME,STRUCT_NAME,TYPE_NAMES(0)
,STRUCT_NAME,STRUCT_NAME,TYPE_NAMES(0)
);
   }
   else {
fprintf(out_file,
"fn %s_get_idx(this:*const %s,a_value:*const %s) -> c_uint;\n"
"fn %s_get_idx_left(this:*const %s,a_value:*const %s) -> c_uint;\n"
"fn %s_get_gre_idx(this:*const %s,a_value:*const %s) -> c_uint;\n"
"fn %s_get_lee_idx(this:*const %s,a_value:*const %s) -> c_uint;\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAMES(0)
,STRUCT_NAME,STRUCT_NAME,TYPE_NAMES(0)
,STRUCT_NAME,STRUCT_NAME,TYPE_NAMES(0)
,STRUCT_NAME,STRUCT_NAME,TYPE_NAMES(0)
);
   }
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"fn %s_get_idxs(this:*const %s,a_value:%s,a_idxs_array:*mut ui_array_s);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAMES(0));
   }
   else {
fprintf(out_file,
"fn %s_get_idxs(this:*const %s,a_value:*const %s,a_idxs_array:*mut ui_array_s);\n"
,STRUCT_NAME,STRUCT_NAME,TYPE_NAMES(0));
   }
   if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
      if (TYPE_NUMBERS(0) & c_type_dynamic) {
fprintf(out_file,
"fn %s_copy(this:*mut %s,a_src:*const %s);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
      }
   }
fprintf(out_file,
"fn %s_compare(this:*const %s,a_second:*const %s) -> c_int;\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
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
   if (STRUCT_NUMBER & c_type_option_rehash) {
fprintf(out_file,
"fn %s_rehash_tree(this:*mut %s);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
//   if (STRUCT_NUMBER & c_type_option_print_dot_code) {
//fprintf(out_file,
//"EXPORT void %s_print_dot_code(const %s *this,FILE *a_file);\n"
//,STRUCT_NAME,STRUCT_NAME);
//   }
   if (STRUCT_NUMBER & c_type_option_check_properties) {
fprintf(out_file,
"fn %s_check_properties(this:*const %s) -> c_int;\n"
,STRUCT_NAME,STRUCT_NAME);
   }
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

void processor_s::generate_rust_rb_tree_inlines(unsigned abb_idx,unsigned a_dt_idx)
{/*{{{*/
   data_type_s &data_type = data_types[a_dt_idx];

   unsigned type_cnt = data_type.types.used;

#ifdef _MSC_VER
   unsigned type_idxs[256];
   data_type_s *types[256];

   if (type_cnt > 256) {
      fprintf(stderr,"rb_tree: inlines: too many contained types, max 256 supported\n");
      cassert(0);
   }
#else
   unsigned type_idxs[type_cnt];
   data_type_s *types[type_cnt];
#endif

   {
      unsigned tn_idx = 0;
      do {
         string_s &type_abb_string = data_type.types[tn_idx];
         unsigned type_abb_idx = abbreviations.get_idx_by_name(type_abb_string.size - 1,type_abb_string.data);

         if (type_abb_idx == c_idx_not_exist) {
            fprintf(stderr,"rb_tree: inlines: abbreviated type name \"%s\" does not exist\n",type_abb_string.data);
            cassert(0);
         }

         type_idxs[tn_idx] = abbreviations[type_abb_idx].data_type_idx;
         types[tn_idx] = &data_types[type_idxs[tn_idx]];

      } while(++tn_idx < type_cnt);
   }

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
"  <Self as Cont>::default()\n"
"}/*}}}*/\n"
"\n"
,STRUCT_NAME,STRUCT_NAME);

   // - rb_tree __get_grandparent_idx method -
RUST_RB_TREE___GET_GRANDPARENT_IDX(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree __get_uncle_idx method -
RUST_RB_TREE___GET_UNCLE_IDX(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree __get_sibling_idx method -
RUST_RB_TREE___GET_SIBLING_IDX(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree get_descent_stack_size -
RUST_RB_TREE_GET_DESCENT_STACK_SIZE(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree get_stack_min_value_idx method -

   // - rb_tree get_stack_next_idx method -
RUST_RB_TREE_GET_STACK_NEXT_IDX(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree get_min_value_idx method -

   // - rb_tree get_max_value_idx method -

   // - rb_tree get_next_idx method -

   // - rb_tree get_prev_idx method -

   // - rb_tree __rotate_left method -
RUST_RB_TREE___ROTATE_LEFT(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree __rotate_right method -
RUST_RB_TREE___ROTATE_RIGHT(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree __get_new_index method -
RUST_RB_TREE___GET_NEW_INDEX(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree __binary_tree_insert method -

   // - rb_tree __replace_delete_node_by_child method -
RUST_RB_TREE___REPLACE_DELETE_NODE_BY_CHILD(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree __remove_black_black method -

   // - rb_tree __remove_one_child method -
RUST_RB_TREE___REMOVE_ONE_CHILD(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree __insert_operation method -

   // - rb_tree init method -
RUST_RB_TREE_INIT(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree init_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
RUST_RB_TREE_INIT_BUFFER(RUST_RB_TREE_GEN_VALUES);
   }

   // - rb_tree clear method -
   if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
RUST_RB_TREE_CLEAR(RUST_RB_TREE_GEN_VALUES);
      }
   }

   // - rb_tree set_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer && !(TYPE_NUMBERS(0) & c_type_dynamic)) {
RUST_RB_TREE_SET_BUFFER(RUST_RB_TREE_GEN_VALUES);
   }

   // - rb_tree flush method -
RUST_RB_TREE_FLUSH(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree flush_all method -
   if (!(TYPE_NUMBERS(0) & c_type_flushable)) {
RUST_RB_TREE_FLUSH_ALL(RUST_RB_TREE_GEN_VALUES);
   }

   // - rb_tree swap method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_swap)) {
RUST_RB_TREE_SWAP(RUST_RB_TREE_GEN_VALUES);
   }

   // - rb_tree operator[] method -
RUST_RB_TREE_OPERATOR_LE_BR_RE_BR(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree insert method -
RUST_RB_TREE_INSERT(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree swap_insert method -
RUST_RB_TREE_SWAP_INSERT(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree unique_insert method -
RUST_RB_TREE_UNIQUE_INSERT(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree unique_swap_insert method -
RUST_RB_TREE_UNIQUE_SWAP_INSERT(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree remove method -

   // - rb_tree copy_resize method -

   // - rb_tree get_idx method -

   // - rb_tree get_idx_left method -

   // - rb_tree get_gre_idx method -

   // - rb_tree get_lee_idx method -

   // - rb_tree get_idxs method -

   // - rb_tree operator= method -
   if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
RUST_RB_TREE_OPERATOR_EQUAL(RUST_RB_TREE_GEN_VALUES);
      }
   }

   // - rb_tree operator== method -

   // - rb_tree to_string method -

   // - rb_tree to_string_separator method -

   // - rb_tree rehash_tree -

   // - rb_tree print_dot_code -

   // - rb_tree check_properties -

   // - rb_tree to_json method -

   // - rb_tree to_json_nice method -

   // - rb_tree from_var method -

   // - rb_tree from_json method -

fprintf(out_file,
"}\n"
"\n");
   }
}/*}}}*/

void processor_s::generate_rust_rb_tree_methods(unsigned abb_idx,unsigned a_dt_idx)
{/*{{{*/
   data_type_s &data_type = data_types[a_dt_idx];

   unsigned type_cnt = data_type.types.used;

#ifdef _MSC_VER
   unsigned type_idxs[256];
   data_type_s *types[256];

   if (type_cnt > 256) {
      fprintf(stderr,"rb_tree: methods: too many contained types, max 256 supported\n");
      cassert(0);
   }
#else
   unsigned type_idxs[type_cnt];
   data_type_s *types[type_cnt];
#endif

   {
      unsigned tn_idx = 0;
      do {
         string_s &type_abb_string = data_type.types[tn_idx];
         unsigned type_abb_idx = abbreviations.get_idx_by_name(type_abb_string.size - 1,type_abb_string.data);

         if (type_abb_idx == c_idx_not_exist) {
            fprintf(stderr,"rb_tree: methods: abreviated type name \"%s\" does not exist\n",type_abb_string.data);
            cassert(0);
         }

         type_idxs[tn_idx] = abbreviations[type_abb_idx].data_type_idx;
         types[tn_idx] = &data_types[type_idxs[tn_idx]];

      } while(++tn_idx < type_cnt);
   }

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

   // - rb_tree __get_grandparent_idx method -

   // - rb_tree __get_uncle_idx method -

   // - rb_tree __get_sibling_idx method -

   // - rb_tree get_descent_stack_size -

   // - rb_tree get_stack_min_value_idx method -
RUST_RB_TREE_GET_STACK_MIN_VALUE_IDX(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree get_stack_next_idx method -

   // - rb_tree get_min_value_idx method -
RUST_RB_TREE_GET_MIN_VALUE_IDX(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree get_max_value_idx method -
RUST_RB_TREE_GET_MAX_VALUE_IDX(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree get_next_idx method -
RUST_RB_TREE_GET_NEXT_IDX(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree get_prev_idx method -
RUST_RB_TREE_GET_PREV_IDX(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree __rotate_left method -

   // - rb_tree __rotate_right method -

   // - rb_tree __get_new_index method -

   // - rb_tree __binary_tree_insert method -
RUST_RB_TREE___BINARY_TREE_INSERT(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree __replace_delete_node_by_child method -

   // - rb_tree __remove_black_black method -
RUST_RB_TREE___REMOVE_BLACK_BLACK(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree __remove_one_child method -

   // - rb_tree __insert_operation method -
RUST_RB_TREE___INSERT_OPERATION(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree init method -

   // - rb_tree init_buffer method -

   // - rb_tree clear method -
   if (TYPE_NUMBERS(0) & c_type_dynamic) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
RUST_RB_TREE_CLEAR(RUST_RB_TREE_GEN_VALUES);
      }
   }

   // - rb_tree set_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer && TYPE_NUMBERS(0) & c_type_dynamic) {
RUST_RB_TREE_SET_BUFFER(RUST_RB_TREE_GEN_VALUES);
   }

   // - rb_tree flush method -

   // - rb_tree flush_all method -
   if (TYPE_NUMBERS(0) & c_type_flushable) {
RUST_RB_TREE_FLUSH_ALL(RUST_RB_TREE_GEN_VALUES);
   }

//   // - rb_tree swap method -
//
//   // - rb_tree operator[] method -
//
//   // - rb_tree insert method -
//
//   // - rb_tree swap_insert method -
//
//   // - rb_tree unique_insert method -
//
//   // - rb_tree unique_swap_insert method -

   // - rb_tree remove method -
RUST_RB_TREE_REMOVE(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree copy_resize method -
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
RUST_RB_TREE_COPY_RESIZE(RUST_RB_TREE_GEN_VALUES);
   }

   // - rb_tree get_idx method -
RUST_RB_TREE_GET_IDX(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree get_idx_left method -
RUST_RB_TREE_GET_IDX_LEFT(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree get_gre_idx method -
RUST_RB_TREE_GET_GRE_IDX(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree get_lee_idx method -
RUST_RB_TREE_GET_LEE_IDX(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree get_idxs method -
RUST_RB_TREE_GET_IDXS(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree operator= method -
   if (TYPE_NUMBERS(0) & c_type_dynamic) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
RUST_RB_TREE_OPERATOR_EQUAL(RUST_RB_TREE_GEN_VALUES);
      }
   }

   // - rb_tree operator== method -
RUST_RB_TREE_OPERATOR_DOUBLE_EQUAL(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree to_string method -
RUST_RB_TREE_TO_STRING(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree to_string_separator method -
RUST_RB_TREE_TO_STRING_SEPARATOR(RUST_RB_TREE_GEN_VALUES);

   // - rb_tree to_json method -
   if (STRUCT_NUMBER & c_type_option_to_json) {
RUST_RB_TREE_TO_JSON(RUST_RB_TREE_GEN_VALUES);
   }

   // - rb_tree to_json_nice method -
   if (STRUCT_NUMBER & c_type_option_to_json_nice) {
RUST_RB_TREE_TO_JSON_NICE(RUST_RB_TREE_GEN_VALUES);
   }

//   // - rb_tree from_var method -
//   if (STRUCT_NUMBER & c_type_option_from_var) {
//RUST_RB_TREE_FROM_VAR(RUST_RB_TREE_GEN_VALUES);
//   }
//
//   // - rb_tree from_json method -
//   if (STRUCT_NUMBER & c_type_option_from_json) {
//RUST_RB_TREE_FROM_JSON(RUST_RB_TREE_GEN_VALUES);
//   }

   // - rb_tree rehash_tree -
   if (STRUCT_NUMBER & c_type_option_rehash) {
RUST_RB_TREE_REHASH_TREE(RUST_RB_TREE_GEN_VALUES);
   }

//   // - rb_tree print_dot_code -
//   if (STRUCT_NUMBER & c_type_option_print_dot_code) {
//RUST_RB_TREE_PRINT_DOT_CODE(RUST_RB_TREE_GEN_VALUES);
//   }

   // - rb_tree check_properties -
   if (STRUCT_NUMBER & c_type_option_check_properties) {
RUST_RB_TREE_CHECK_PROPERTIES(RUST_RB_TREE_GEN_VALUES);
   }

fprintf(out_file,
"}\n"
"\n"
"impl Cont for %s\n"
"{\n"
"\n"
"fn default() -> Self\n"
"{/*{{{*/\n"
"  %s{\n"
"    size:0,\n"
"    used:0,\n"
,STRUCT_NAME,STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"    count:0,\n"
);
   }
fprintf(out_file,
"    data:std::ptr::null_mut(),\n"
"    free_idx:c_idx_not_exist,\n"
"    root_idx:c_idx_not_exist,\n"
"    leaf_idx:c_idx_not_exist,\n"
);
   if (VAR_NAMES_CNT > 0) {
fprintf(out_file,
"\n"
);
      unsigned t_idx = 0;
      do {
fprintf(out_file,
"    %s:<%s as Cont>::default(),\n"
,VAR_NAMES(t_idx),TYPE_NAMES(t_idx + 1));
      } while(++t_idx < VAR_NAMES_CNT);
   }
fprintf(out_file,
"  }\n"
"}/*}}}*/\n"
"\n"
);

fprintf(out_file,
"}\n"
"\n"
"impl Drop for %s\n"
"{\n"
"  fn drop(&mut self) {\n"
"    self.clear();\n"
"  }\n"
"}\n"
"\n"
,STRUCT_NAME);
   }
}/*}}}*/


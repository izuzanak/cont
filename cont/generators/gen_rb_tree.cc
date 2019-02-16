
#define RB_TREE_GEN_PARAMS FILE *out_file,abbreviation_array_s &abbreviations,unsigned abb_idx,data_type_s &data_type,data_type_s **types
#define RB_TREE_GEN_VALUES out_file,abbreviations,abb_idx,data_type,types

void RB_TREE___GET_GRANDPARENT_IDX(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline unsigned %s___get_grandparent_idx(const %s *this,unsigned a_idx)\n"
"{/*{{{*/\n"
"  %s_node *node = this->data + a_idx;\n"
"\n"
"  if (node->parent_idx != c_idx_not_exist)\n"
"  {\n"
"    return this->data[node->parent_idx].parent_idx;\n"
"  }\n"
"\n"
"  return c_idx_not_exist;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE___GET_UNCLE_IDX(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline unsigned %s___get_uncle_idx(const %s *this,unsigned a_idx)\n"
"{/*{{{*/\n"
"  unsigned gp_idx = %s___get_grandparent_idx(this,a_idx);\n"
"\n"
"  if (gp_idx != c_idx_not_exist)\n"
"  {\n"
"    %s_node *gp = this->data + gp_idx;\n"
"    return gp->left_idx == this->data[a_idx].parent_idx?gp->right_idx:gp->left_idx;\n"
"  }\n"
"\n"
"  return c_idx_not_exist;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE___GET_SIBLING_IDX(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline unsigned %s___get_sibling_idx(const %s *this,unsigned a_idx)\n"
"{/*{{{*/\n"
"  %s_node *p = this->data + this->data[a_idx].parent_idx;\n"
"  return p->left_idx == a_idx?p->right_idx:p->left_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_GET_DESCENT_STACK_SIZE(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline unsigned %s_get_descent_stack_size(const %s *this)\n"
"{/*{{{*/\n"
"  return (unsigned)(logf(this->used)/c_log_of_2) << 1;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_GET_STACK_MIN_VALUE_IDX(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"unsigned %s_get_stack_min_value_idx(const %s *this,unsigned a_idx,unsigned **a_s_ptr)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  debug_assert(a_idx < this->used && this->data[a_idx].valid);\n"
);
   }
   else
   {
fprintf(out_file,
"  debug_assert(a_idx < this->used);\n"
);
   }
fprintf(out_file,
"\n"
"  unsigned node_idx = a_idx;\n"
"  do {\n"
"    %s_node *node = this->data + node_idx;\n"
"\n"
"    if (node->left_idx == this->leaf_idx)\n"
"    {\n"
"      return node_idx;\n"
"    }\n"
"\n"
"    *((*a_s_ptr)++) = node_idx;\n"
"    node_idx = node->left_idx;\n"
"  } while(1);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_GET_STACK_NEXT_IDX(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline unsigned %s_get_stack_next_idx(const %s *this,unsigned a_idx,unsigned **a_s_ptr,const unsigned *a_stack_base)\n"
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
"  %s_node *node = this->data + a_idx;\n"
"\n"
"  if (node->right_idx != this->leaf_idx)\n"
"  {\n"
"    return %s_get_stack_min_value_idx(this,node->right_idx,a_s_ptr);\n"
"  }\n"
"\n"
"  if (*a_s_ptr > a_stack_base)\n"
"  {\n"
"    return *(--(*a_s_ptr));\n"
"  }\n"
"\n"
"  return c_idx_not_exist;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_GET_MIN_VALUE_IDX(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"unsigned %s_get_min_value_idx(const %s *this,unsigned a_idx)\n"
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
"  unsigned node_idx = a_idx;\n"
"  do {\n"
"    %s_node *node = this->data + node_idx;\n"
"\n"
"    if (node->left_idx == this->leaf_idx)\n"
"    {\n"
"      return node_idx;\n"
"    }\n"
"\n"
"    node_idx = node->left_idx;\n"
"  } while(1);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_GET_MAX_VALUE_IDX(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"unsigned %s_get_max_value_idx(const %s *this,unsigned a_idx)\n"
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
"  unsigned node_idx = a_idx;\n"
"  do {\n"
"    %s_node *node = this->data + node_idx;\n"
"\n"
"    if (node->right_idx == this->leaf_idx)\n"
"    {\n"
"      return node_idx;\n"
"    }\n"
"\n"
"    node_idx = node->right_idx;\n"
"  } while(1);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_GET_NEXT_IDX(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"unsigned %s_get_next_idx(const %s *this,unsigned a_idx)\n"
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
"  %s_node *node = this->data + a_idx;\n"
"\n"
"  if (node->right_idx != this->leaf_idx)\n"
"  {\n"
"    return %s_get_min_value_idx(this,node->right_idx);\n"
"  }\n"
"\n"
"  unsigned node_idx = a_idx;\n"
"  do {\n"
"    %s_node *node = this->data + node_idx;\n"
"\n"
"    if (node->parent_idx == c_idx_not_exist)\n"
"    {\n"
"      return c_idx_not_exist;\n"
"    }\n"
"\n"
"    if (this->data[node->parent_idx].right_idx != node_idx)\n"
"    {\n"
"      return node->parent_idx;\n"
"    }\n"
"\n"
"    node_idx = node->parent_idx;\n"
"  } while(1);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_GET_PREV_IDX(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"unsigned %s_get_prev_idx(const %s *this,unsigned a_idx)\n"
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
"  %s_node *node = this->data + a_idx;\n"
"\n"
"  if (node->left_idx != this->leaf_idx)\n"
"  {\n"
"    return %s_get_max_value_idx(this,node->left_idx);\n"
"  }\n"
"\n"
"  unsigned node_idx = a_idx;\n"
"  do {\n"
"    %s_node *node = this->data + node_idx;\n"
"\n"
"    if (node->parent_idx == c_idx_not_exist)\n"
"    {\n"
"      return c_idx_not_exist;\n"
"    }\n"
"\n"
"    if (this->data[node->parent_idx].left_idx != node_idx)\n"
"    {\n"
"      return node->parent_idx;\n"
"    }\n"
"\n"
"    node_idx = node->parent_idx;\n"
"  } while(1);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE___ROTATE_LEFT(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline void %s___rotate_left(%s *this,unsigned a_idx)\n"
"{/*{{{*/\n"
"  %s_node *root = this->data + a_idx;\n"
"  %s_node *pivot = this->data + root->right_idx;\n"
"\n"
"  if (a_idx == this->root_idx)\n"
"  {\n"
"    this->root_idx = root->right_idx;\n"
"    pivot->parent_idx = c_idx_not_exist;\n"
"  }\n"
"  else\n"
"  {\n"
"    %s_node *rp = this->data + root->parent_idx;\n"
"\n"
"    if (rp->right_idx == a_idx)\n"
"    {\n"
"      rp->right_idx = root->right_idx;\n"
"    }\n"
"    else\n"
"    {\n"
"      rp->left_idx = root->right_idx;\n"
"    }\n"
"\n"
"    pivot->parent_idx = root->parent_idx;\n"
"  }\n"
"\n"
"  root->parent_idx = root->right_idx;\n"
"\n"
"  root->right_idx = pivot->left_idx;\n"
"  this->data[root->right_idx].parent_idx = a_idx;\n"
"\n"
"  pivot->left_idx = a_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE___ROTATE_RIGHT(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline void %s___rotate_right(%s *this,unsigned a_idx)\n"
"{/*{{{*/\n"
"  %s_node *root = this->data + a_idx;\n"
"  %s_node *pivot = this->data + root->left_idx;\n"
"\n"
"  if (a_idx == this->root_idx)\n"
"  {\n"
"    this->root_idx = root->left_idx;\n"
"    pivot->parent_idx = c_idx_not_exist;\n"
"  }\n"
"  else\n"
"  {\n"
"    %s_node *rp = this->data + root->parent_idx;\n"
"\n"
"    if (rp->right_idx == a_idx)\n"
"    {\n"
"      rp->right_idx = root->left_idx;\n"
"    }\n"
"    else\n"
"    {\n"
"      rp->left_idx = root->left_idx;\n"
"    }\n"
"\n"
"    pivot->parent_idx = root->parent_idx;\n"
"  }\n"
"\n"
"  root->parent_idx = root->left_idx;\n"
"\n"
"  root->left_idx = pivot->right_idx;\n"
"  this->data[root->left_idx].parent_idx = a_idx;\n"
"\n"
"  pivot->right_idx = a_idx;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE___GET_NEW_INDEX(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline unsigned %s___get_new_index(%s *this)\n"
"{/*{{{*/\n"
"  unsigned new_idx;\n"
"\n"
"  if (this->free_idx != c_idx_not_exist)\n"
"  {\n"
"    new_idx = this->free_idx;\n"
"    this->free_idx = this->data[new_idx].parent_idx;\n"
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
"\n"
"      if (this->leaf_idx == c_idx_not_exist)\n"
"      {\n"
"        this->leaf_idx = this->used++;\n"
"        %s_node *leaf = this->data + this->leaf_idx;\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"        leaf->valid = 0;\n"
"        leaf->color = 1;\n"
);
   }
   else {
fprintf(out_file,
"        leaf->color = 1;\n"
);
   }
   if (STRUCT_NUMBER & c_type_option_check_properties) {
fprintf(out_file,
"\n"
"        leaf->left_idx = c_idx_not_exist;\n"
"        leaf->right_idx = c_idx_not_exist;\n"
);
   }
fprintf(out_file,
"      }\n"
"    }\n"
"\n"
);
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
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  this->data[new_idx].valid = 1;\n"
"  this->count++;\n"
"\n"
);
   }
fprintf(out_file,
"  return new_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RB_TREE___BINARY_TREE_INSERT(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"unsigned %s___binary_tree_insert(%s *this,unsigned a_new_idx,const %s *a_value,int a_unique)\n"
"{/*{{{*/\n"
"  if (this->root_idx == c_idx_not_exist)\n"
"  {\n"
"    this->data[a_new_idx].parent_idx = c_idx_not_exist;\n"
"    this->root_idx = a_new_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    unsigned node_idx = this->root_idx;\n"
"    do {\n"
"      %s_node *node = this->data + node_idx;\n"
"\n"
"      int comp_result = %s___compare_value(this,a_value,&node->object);\n"
"      if (comp_result < 0)\n"
"      {\n"
"        if (node->left_idx == this->leaf_idx)\n"
"        {\n"
"          node->left_idx = a_new_idx;\n"
"          break;\n"
"        }\n"
"        node_idx = node->left_idx;\n"
"      }\n"
"      else\n"
"      {\n"
"        if (a_unique && comp_result == 0)\n"
"        {\n"
"          return node_idx;\n"
"        }\n"
"\n"
"        if (node->right_idx == this->leaf_idx)\n"
"        {\n"
"          node->right_idx = a_new_idx;\n"
"          break;\n"
"        }\n"
"        node_idx = node->right_idx;\n"
"      }\n"
"    } while(1);\n"
"\n"
"    this->data[a_new_idx].parent_idx = node_idx;\n"
"  }\n"
"\n"
"  %s_node *new_node = this->data + a_new_idx;\n"
"  new_node->left_idx = this->leaf_idx;\n"
"  new_node->right_idx = this->leaf_idx;\n"
"  new_node->color = 0;\n"
"\n"
"  return c_idx_not_exist;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_TYPE_NAMES(0),IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE___REPLACE_DELETE_NODE_BY_CHILD(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline void %s___replace_delete_node_by_child(%s *this,unsigned a_idx,unsigned a_ch_idx)\n"
"{/*{{{*/\n"
"  %s_node *node = this->data + a_idx;\n"
"\n"
"  if (node->parent_idx != c_idx_not_exist)\n"
"  {\n"
"    %s_node *parent = this->data + node->parent_idx;\n"
"\n"
"    if (parent->left_idx == a_idx)\n"
"    {\n"
"      parent->left_idx = a_ch_idx;\n"
"    }\n"
"    else\n"
"    {\n"
"      parent->right_idx = a_ch_idx;\n"
"    }\n"
"\n"
"    this->data[a_ch_idx].parent_idx = node->parent_idx;\n"
"  }\n"
"  else\n"
"  {\n"
"    this->root_idx = a_ch_idx == this->leaf_idx?c_idx_not_exist:a_ch_idx;\n"
"    this->data[a_ch_idx].parent_idx = c_idx_not_exist;\n"
"  }\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE___REMOVE_BLACK_BLACK(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"void %s___remove_black_black(%s *this,unsigned a_idx)\n"
"{/*{{{*/\n"
"  unsigned node_idx = a_idx;\n"
"  do {\n"
"    %s_node *node = this->data + node_idx;\n"
"\n"
"    if (node->parent_idx == c_idx_not_exist)\n"
"    {\n"
"      return;\n"
"    }\n"
"\n"
"    unsigned parent_idx = node->parent_idx;\n"
"    %s_node *parent = this->data + parent_idx;\n"
"\n"
"    {\n"
"      unsigned sibling_idx = parent->left_idx == node_idx?parent->right_idx:parent->left_idx;\n"
"      %s_node *sibling = this->data + sibling_idx;\n"
"\n"
"      if (!sibling->color)\n"
"      {\n"
"        parent->color = 0;\n"
"        sibling->color = 1;\n"
"\n"
"        if (node_idx == parent->left_idx)\n"
"        {\n"
"          %s___rotate_left(this,parent_idx);\n"
"        }\n"
"        else\n"
"        {\n"
"          %s___rotate_right(this,parent_idx);\n"
"        }\n"
"      }\n"
"    }\n"
"\n"
"    {\n"
"      unsigned sibling_idx = parent->left_idx == node_idx?parent->right_idx:parent->left_idx;\n"
"      %s_node* sibling = this->data + sibling_idx;\n"
"\n"
"      if (parent->color && sibling->color && this->data[sibling->left_idx].color && this->data[sibling->right_idx].color)\n"
"      {\n"
"        sibling->color = 0;\n"
"        node_idx = parent_idx;\n"
"        continue;\n"
"      }\n"
"\n"
"      if (!parent->color && sibling->color && this->data[sibling->left_idx].color && this->data[sibling->right_idx].color)\n"
"      {\n"
"        sibling->color = 0;\n"
"        parent->color = 1;\n"
"        return;\n"
"      }\n"
"\n"
"      if (sibling->color)\n"
"      {\n"
"        if (node_idx == parent->left_idx && this->data[sibling->right_idx].color && !this->data[sibling->left_idx].color)\n"
"        {\n"
"          sibling->color = 0;\n"
"          this->data[sibling->left_idx].color = 1;\n"
"          %s___rotate_right(this,sibling_idx);\n"
"        }\n"
"        else if (node_idx == parent->right_idx && this->data[sibling->left_idx].color && !this->data[sibling->right_idx].color)\n"
"        {\n"
"          sibling->color = 0;\n"
"          this->data[sibling->right_idx].color = 1;\n"
"          %s___rotate_left(this,sibling_idx);\n"
"        }\n"
"      }\n"
"\n"
"      {\n"
"        unsigned sibling_idx = parent->left_idx == node_idx?parent->right_idx:parent->left_idx;\n"
"        %s_node *sibling = this->data + sibling_idx;\n"
"\n"
"        sibling->color = parent->color;\n"
"        parent->color = 1;\n"
"\n"
"        if (node_idx == parent->left_idx)\n"
"        {\n"
"          this->data[sibling->right_idx].color = 1;\n"
"          %s___rotate_left(this,parent_idx);\n"
"        }\n"
"        else\n"
"        {\n"
"          this->data[sibling->left_idx].color = 1;\n"
"          %s___rotate_right(this,parent_idx);\n"
"        }\n"
"      }\n"
"\n"
"      return;\n"
"    }\n"
"\n"
"  } while(1);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE___REMOVE_ONE_CHILD(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline void %s___remove_one_child(%s *this,unsigned a_idx,unsigned a_ch_idx)\n"
"{/*{{{*/\n"
"  %s_node *node = this->data + a_idx;\n"
"  %s___replace_delete_node_by_child(this,a_idx,a_ch_idx);\n"
"\n"
"  node->parent_idx = this->free_idx;\n"
"  this->free_idx = a_idx;\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  node->valid = 0;\n"
"  this->count--;\n"
"\n"
);
   }
fprintf(out_file,
"  if (node->color)\n"
"  {\n"
"    %s_node *child_node = this->data + a_ch_idx;\n"
"\n"
"    if (!child_node->color)\n"
"    {\n"
"      child_node->color = 1;\n"
"    }\n"
"    else\n"
"    {\n"
"      %s___remove_black_black(this,a_ch_idx);\n"
"    }\n"
"  }\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE___INSERT_OPERATION(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"void %s___insert_operation(%s *this,unsigned a_idx)\n"
"{/*{{{*/\n"
"  unsigned node_idx = a_idx;\n"
"  do {\n"
"    %s_node *node = this->data + node_idx;\n"
"\n"
"    if (node->parent_idx == c_idx_not_exist)\n"
"    {\n"
"      node->color = 1;\n"
"      return;\n"
"    }\n"
"\n"
"    if (this->data[node->parent_idx].color)\n"
"    {\n"
"      return;\n"
"    }\n"
"\n"
"    unsigned uncle_idx = %s___get_uncle_idx(this,node_idx);\n"
"    if (uncle_idx != c_idx_not_exist && !this->data[uncle_idx].color)\n"
"    {\n"
"      this->data[node->parent_idx].color = 1;\n"
"      this->data[uncle_idx].color = 1;\n"
"\n"
"      node_idx = %s___get_grandparent_idx(this,node_idx);\n"
"      this->data[node_idx].color = 0;\n"
"\n"
"      continue;\n"
"    }\n"
"\n"
"    unsigned grandparent_idx = %s___get_grandparent_idx(this,node_idx);\n"
"\n"
"    if (node_idx == this->data[node->parent_idx].right_idx && node->parent_idx == this->data[grandparent_idx].left_idx)\n"
"    {\n"
"      %s___rotate_left(this,node->parent_idx);\n"
"      node_idx = node->left_idx;\n"
"    }\n"
"    else if (node_idx == this->data[node->parent_idx].left_idx && node->parent_idx == this->data[grandparent_idx].right_idx)\n"
"    {\n"
"      %s___rotate_right(this,node->parent_idx);\n"
"      node_idx = node->right_idx;\n"
"    }\n"
"\n"
"    {\n"
"      unsigned grandparent_idx = %s___get_grandparent_idx(this,node_idx);\n"
"      %s_node *node = this->data + node_idx;\n"
"\n"
"      this->data[node->parent_idx].color = 1;\n"
"      this->data[grandparent_idx].color = 0;\n"
"\n"
"      if (node_idx == this->data[node->parent_idx].left_idx && node->parent_idx == this->data[grandparent_idx].left_idx)\n"
"      {\n"
"        %s___rotate_right(this,grandparent_idx);\n"
"      }\n"
"      else\n"
"      {\n"
"        %s___rotate_left(this,grandparent_idx);\n"
"      }\n"
"\n"
"      return;\n"
"    }\n"
"  } while(1);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_INIT(RB_TREE_GEN_PARAMS)
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
"  this->root_idx = c_idx_not_exist;\n"
"  this->leaf_idx = c_idx_not_exist;\n"
);
   if (VAR_NAMES_CNT > 0) {
fprintf(out_file,
"\n"
);
      unsigned t_idx = 0;
      do {
         if (TYPE_NUMBERS(t_idx + 1) & c_type_dynamic) {
fprintf(out_file,
"  %s_init(&this->%s);\n"
,IM_TYPE_NAMES(t_idx + 1),VAR_NAMES(t_idx));
         }
      } while(++t_idx < VAR_NAMES_CNT);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RB_TREE_INIT_BUFFER(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline void %s_init_buffer(%s *this,unsigned a_size,%s_node *a_data)\n"
"{/*{{{*/\n"
"  %s_init(this);\n"
"  %s_set_buffer(this,a_size,a_data);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_CLEAR(RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
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
   if (TYPE_NUMBERS(0) & c_type_dynamic || !(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  if (this->data != NULL)\n"
"  {\n"
);
      if (TYPE_NUMBERS(0) & c_type_dynamic) {
fprintf(out_file,
"    %s_node *ptr = this->data;\n"
"    %s_node *ptr_end = ptr + this->size;\n"
"\n"
"    do {\n"
"      %s_clear(&ptr->object);\n"
"    } while(++ptr < ptr_end);\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_TYPE_NAMES(0));
      }
      if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
         if (TYPE_NUMBERS(0) & c_type_dynamic) {
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
   if (VAR_NAMES_CNT > 0) {
      unsigned t_idx = 0;
      do {
         if (TYPE_NUMBERS(t_idx + 1) & c_type_dynamic) {
fprintf(out_file,
"  %s_clear(&this->%s);\n"
,IM_TYPE_NAMES(t_idx + 1),VAR_NAMES(t_idx));
         }
      } while(++t_idx < VAR_NAMES_CNT);
fprintf(out_file,
"\n"
);
   }
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  this->size = 0;\n"
);
   }
fprintf(out_file,
"  this->used = 0;\n"
);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  this->count = 0;\n"
);
   }
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"  this->data = NULL;\n"
);
   }
fprintf(out_file,
"  this->free_idx = c_idx_not_exist;\n"
"  this->root_idx = c_idx_not_exist;\n"
"  this->leaf_idx = c_idx_not_exist;\n"
);
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RB_TREE_SET_BUFFER(RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
fprintf(out_file,
"static inline void %s_set_buffer(%s *this,unsigned a_size,%s_node *a_data)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"void %s_set_buffer(%s *this,unsigned a_size,%s_node *a_data)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   }
fprintf(out_file,
"{/*{{{*/\n"
"  debug_assert(a_size != 0 && a_data != NULL);\n"
"\n"
"  %s_clear(this);\n"
,IM_STRUCT_NAME);
   if (TYPE_NUMBERS(0) & c_type_dynamic) {
fprintf(out_file,
"\n"
"  %s_node *ptr = a_data;\n"
"  %s_node *ptr_end = a_data + a_size;\n"
"\n"
"  do {\n"
"    %s_init(&ptr->object);\n"
"  } while(++ptr < ptr_end);\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_TYPE_NAMES(0));
   }
fprintf(out_file,
"\n"
"  this->size = a_size;\n"
"  this->data = a_data;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RB_TREE_FLUSH(RB_TREE_GEN_PARAMS)
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

void RB_TREE_FLUSH_ALL(RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBERS(0) & c_type_flushable)) {
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
"  %s_flush_all(&this->%s);\n"
,IM_TYPE_NAMES(t_idx + 1),VAR_NAMES(t_idx));
         }
      } while(++t_idx < VAR_NAMES_CNT);
   }
   if (TYPE_NUMBERS(0) & c_type_flushable) {
      if (!(STRUCT_NUMBER & c_type_option_fixed_buffer) || VAR_NAMES_CNT > 0) {
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
"  %s_node *ptr = this->data;\n"
"  %s_node *ptr_end = ptr + this->used;\n"
"\n"
"  do {\n"
"    %s_flush_all(&ptr->object);\n"
"  } while(++ptr < ptr_end);\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_TYPE_NAMES(0));
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RB_TREE_SWAP(RB_TREE_GEN_PARAMS)
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

void RB_TREE_OPERATOR_LE_BR_RE_BR(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"static inline %s *%s_at(const %s *this,unsigned a_idx)\n"
"{/*{{{*/\n"
,IM_TYPE_NAMES(0),IM_STRUCT_NAME,IM_STRUCT_NAME);
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

#define TEMPLATE_RB_TREE_INSERT(FUN_NAME,VALUE_CONST,VALUE_SET_CODE) \
{/*{{{*/\
   if (TYPE_NUMBERS(0) & c_type_basic) {\
fprintf(out_file,\
"static inline unsigned %s_%s(%s *this,%s a_value)\n"\
,IM_STRUCT_NAME,#FUN_NAME,IM_STRUCT_NAME,IM_TYPE_NAMES(0));\
   }\
   else {\
fprintf(out_file,\
"static inline unsigned %s_%s(%s *this,%s%s *a_value)\n"\
,IM_STRUCT_NAME,#FUN_NAME,IM_STRUCT_NAME,VALUE_CONST ? "const " : "",IM_TYPE_NAMES(0));\
   }\
fprintf(out_file,\
"{/*{{{*/\n"\
"  unsigned new_node_idx = %s___get_new_index(this);\n"\
"\n"\
,IM_STRUCT_NAME);\
   if (TYPE_NUMBERS(0) & c_type_basic) {\
fprintf(out_file,\
"  %s___binary_tree_insert(this,new_node_idx,&a_value,0);\n"\
,IM_STRUCT_NAME);\
   }\
   else {\
fprintf(out_file,\
"  %s___binary_tree_insert(this,new_node_idx,a_value,0);\n"\
,IM_STRUCT_NAME);\
   }\
fprintf(out_file,\
"  %s___insert_operation(this,new_node_idx);\n"\
"\n"\
,IM_STRUCT_NAME);\
   VALUE_SET_CODE;\
fprintf(out_file,\
"\n"\
"  return new_node_idx;\n"\
"}/*}}}*/\n"\
"\n"\
);\
}/*}}}*/

void RB_TREE_INSERT(RB_TREE_GEN_PARAMS)
{/*{{{*/
TEMPLATE_RB_TREE_INSERT(insert,true,
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"  this->data[new_node_idx].object = a_value;\n"
);
   }
   else if (TYPE_NUMBERS(0) & c_type_static) {
fprintf(out_file,
"  this->data[new_node_idx].object = *a_value;\n"
);
   }
   else {
fprintf(out_file,
"  %s_copy(&this->data[new_node_idx].object,a_value);\n"
,IM_TYPE_NAMES(0));
   }
);
}/*}}}*/

void RB_TREE_SWAP_INSERT(RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBERS(0) & c_type_dynamic) {
TEMPLATE_RB_TREE_INSERT(swap_insert,false,
fprintf(out_file,
"  %s_swap(&this->data[new_node_idx].object,a_value);\n"
,IM_TYPE_NAMES(0));
);
   }
}/*}}}*/

#define TEMPLATE_RB_TREE_UNIQUE_INSERT(FUN_NAME,VALUE_CONST,VALUE_SET_CODE) \
{/*{{{*/\
   if (TYPE_NUMBERS(0) & c_type_basic) {\
fprintf(out_file,\
"static inline unsigned %s_%s(%s *this,%s a_value)\n"\
,IM_STRUCT_NAME,#FUN_NAME,IM_STRUCT_NAME,IM_TYPE_NAMES(0));\
   }\
   else {\
fprintf(out_file,\
"static inline unsigned %s_%s(%s *this,%s%s *a_value)\n"\
,IM_STRUCT_NAME,#FUN_NAME,IM_STRUCT_NAME,VALUE_CONST ? "const " : "",IM_TYPE_NAMES(0));\
   }\
fprintf(out_file,\
"{/*{{{*/\n"\
"  unsigned new_node_idx = %s___get_new_index(this);\n"\
,IM_STRUCT_NAME);\
   if (TYPE_NUMBERS(0) & c_type_basic) {\
fprintf(out_file,\
"  unsigned old_node_idx = %s___binary_tree_insert(this,new_node_idx,&a_value,1);\n"\
,IM_STRUCT_NAME);\
   }\
   else {\
fprintf(out_file,\
"  unsigned old_node_idx = %s___binary_tree_insert(this,new_node_idx,a_value,1);\n"\
,IM_STRUCT_NAME);\
   }\
fprintf(out_file,\
"\n"\
"  if (old_node_idx != c_idx_not_exist)\n"\
"  {\n"\
"    %s_node *new_node = this->data + new_node_idx;\n"\
"\n"\
"    new_node->parent_idx = this->free_idx;\n"\
"    this->free_idx = new_node_idx;\n"\
"\n"\
,IM_STRUCT_NAME);\
   if (STRUCT_NUMBER & c_type_option_safe) {\
fprintf(out_file,\
"    new_node->valid = 0;\n"\
"    this->count--;\n"\
"\n"\
);\
   }\
fprintf(out_file,\
"    return old_node_idx;\n"\
"  }\n"\
"\n"\
"  %s___insert_operation(this,new_node_idx);\n"\
"\n"\
,IM_STRUCT_NAME);\
   VALUE_SET_CODE;\
fprintf(out_file,\
"\n"\
"  return new_node_idx;\n"\
"}/*}}}*/\n"\
"\n"\
);\
}/*}}}*/

void RB_TREE_UNIQUE_INSERT(RB_TREE_GEN_PARAMS)
{/*{{{*/
TEMPLATE_RB_TREE_UNIQUE_INSERT(unique_insert,true,
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"  this->data[new_node_idx].object = a_value;\n"
);
   }
   else if (TYPE_NUMBERS(0) & c_type_static) {
fprintf(out_file,
"  this->data[new_node_idx].object = *a_value;\n"
);
   }
   else {
fprintf(out_file,
"  %s_copy(&this->data[new_node_idx].object,a_value);\n"
,IM_TYPE_NAMES(0));
   }
);
}/*}}}*/

void RB_TREE_UNIQUE_SWAP_INSERT(RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBERS(0) & c_type_dynamic) {
TEMPLATE_RB_TREE_UNIQUE_INSERT(unique_swap_insert,false,
fprintf(out_file,
"  %s_swap(&this->data[new_node_idx].object,a_value);\n"
,IM_TYPE_NAMES(0));
);
   }
}/*}}}*/

void RB_TREE_REMOVE(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"void %s_remove(%s *this,unsigned a_idx)\n"
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
"  %s_node *del_node = this->data + a_idx;\n"
"\n"
"  if (del_node->left_idx != this->leaf_idx)\n"
"  {\n"
"    if (del_node->right_idx != this->leaf_idx)\n"
"    {\n"
"      unsigned found_idx = del_node->right_idx;\n"
"      do {\n"
"        %s_node *node = this->data + found_idx;\n"
"\n"
"        if (node->left_idx == this->leaf_idx)\n"
"        {\n"
"          break;\n"
"        }\n"
"\n"
"        found_idx = node->left_idx;\n"
"      } while(1);\n"
"\n"
"      %s_node *found_node = this->data + found_idx;\n"
"\n"
"      /* - process del_node parent_idx - */\n"
"      if (del_node->parent_idx != c_idx_not_exist)\n"
"      {\n"
"        %s_node *del_node_parent = this->data + del_node->parent_idx;\n"
"\n"
"        if (del_node_parent->left_idx == a_idx)\n"
"        {\n"
"          del_node_parent->left_idx = found_idx;\n"
"        }\n"
"        else\n"
"        {\n"
"          del_node_parent->right_idx = found_idx;\n"
"        }\n"
"      }\n"
"      else\n"
"      {\n"
"        this->root_idx = found_idx;\n"
"      }\n"
"\n"
"      /* - process del_node left_idx - */\n"
"      this->data[del_node->left_idx].parent_idx = found_idx;\n"
"\n"
"      /* - process found_node right_idx - */\n"
"      if (found_node->right_idx != this->leaf_idx)\n"
"      {\n"
"        this->data[found_node->right_idx].parent_idx = a_idx;\n"
"      }\n"
"\n"
"      if (del_node->right_idx == found_idx)\n"
"      {\n"
"        /* - found node is right child of deleted node - */\n"
"        del_node->right_idx = found_node->right_idx;\n"
"        found_node->right_idx = a_idx;\n"
"\n"
"        found_node->parent_idx = del_node->parent_idx;\n"
"        del_node->parent_idx = found_idx;\n"
"\n"
"        found_node->left_idx = del_node->left_idx;\n"
"        del_node->left_idx = this->leaf_idx;\n"
"\n"
"        char tmp_char = found_node->color;\n"
"        found_node->color = del_node->color;\n"
"        del_node->color = tmp_char;\n"
"      }\n"
"      else\n"
"      {\n"
"        /* - process found_node parent - */\n"
"        %s_node *found_node_parent = this->data + found_node->parent_idx;\n"
"\n"
"        if (found_node_parent->left_idx == found_idx)\n"
"        {\n"
"          found_node_parent->left_idx = a_idx;\n"
"        }\n"
"        else\n"
"        {\n"
"          found_node_parent->right_idx = a_idx;\n"
"        }\n"
"\n"
"        /* - process del_node right_idx - */\n"
"        this->data[del_node->right_idx].parent_idx = found_idx;\n"
"\n"
"        /* - swap index pointers between nodes - */\n"
"        unsigned tmp_unsigned = found_node->parent_idx;\n"
"        found_node->parent_idx = del_node->parent_idx;\n"
"        del_node->parent_idx = tmp_unsigned;\n"
"\n"
"        found_node->left_idx = del_node->left_idx;\n"
"        del_node->left_idx = this->leaf_idx;\n"
"\n"
"        tmp_unsigned = found_node->right_idx;\n"
"        found_node->right_idx = del_node->right_idx;\n"
"        del_node->right_idx = tmp_unsigned;\n"
"\n"
"        char tmp_char = found_node->color;\n"
"        found_node->color = del_node->color;\n"
"        del_node->color = tmp_char;\n"
"      }\n"
"\n"
"      %s___remove_one_child(this,a_idx,del_node->right_idx);\n"
"    }\n"
"    else\n"
"    {\n"
"      %s___remove_one_child(this,a_idx,del_node->left_idx);\n"
"    }\n"
"  }\n"
"  else\n"
"  {\n"
"    %s___remove_one_child(this,a_idx,del_node->right_idx);\n"
"  }\n"
"\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_COPY_RESIZE(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"void %s_copy_resize(%s *this,unsigned a_size)\n"
"{/*{{{*/\n"
"  debug_assert(a_size >= this->used);\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (TYPE_NUMBERS(0) & c_type_dynamic) {
fprintf(out_file,
"\n"
"  if (this->size > a_size)\n"
"  {\n"
"    %s_node *ptr = this->data + a_size;\n"
"    %s_node *ptr_end = this->data + this->size;\n"
"\n"
"    do {\n"
"      %s_clear(&ptr->object);\n"
"    } while(++ptr < ptr_end);\n"
"  }\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_TYPE_NAMES(0));
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
"    this->data = (%s_node *)crealloc(this->data,a_size*sizeof(%s_node));\n"
"  }\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (TYPE_NUMBERS(0) & c_type_dynamic) {
fprintf(out_file,
"\n"
"  if (a_size > this->size)\n"
"  {\n"
"    %s_node *ptr = this->data + this->size;\n"
"    %s_node *ptr_end = this->data + a_size;\n"
"\n"
"    do {\n"
"      %s_init(&ptr->object);\n"
"    } while(++ptr < ptr_end);\n"
"  }\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_TYPE_NAMES(0));
   }
fprintf(out_file,
"\n"
"  this->size = a_size;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RB_TREE_GET_IDX(RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"unsigned %s_get_idx(const %s *this,%s a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_TYPE_NAMES(0));
   }
   else {
fprintf(out_file,
"unsigned %s_get_idx(const %s *this,const %s *a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_TYPE_NAMES(0));
   }
fprintf(out_file,
"{/*{{{*/\n"
"  if (this->root_idx == c_idx_not_exist)\n"
"  {\n"
"    return c_idx_not_exist;\n"
"  }\n"
"\n"
"  unsigned node_idx = this->root_idx;\n"
"  do {\n"
"    %s_node *node = this->data + node_idx;\n"
"\n"
,IM_STRUCT_NAME);
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"    int comp_result = %s___compare_value(this,&a_value,&node->object);\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"    int comp_result = %s___compare_value(this,a_value,&node->object);\n"
,IM_STRUCT_NAME);
   }
fprintf(out_file,
"    if (comp_result < 0)\n"
"    {\n"
"      node_idx = node->left_idx;\n"
"    }\n"
"    else\n"
"    {\n"
"      if (comp_result == 0)\n"
"      {\n"
"        return node_idx;\n"
"      }\n"
"\n"
"      node_idx = node->right_idx;\n"
"    }\n"
"  } while(node_idx != this->leaf_idx);\n"
"\n"
"  return c_idx_not_exist;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RB_TREE_GET_IDX_LEFT(RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"unsigned %s_get_idx_left(const %s *this,%s a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_TYPE_NAMES(0));
   }
   else {
fprintf(out_file,
"unsigned %s_get_idx_left(const %s *this,const %s *a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_TYPE_NAMES(0));
   }
fprintf(out_file,
"{/*{{{*/\n"
"  if (this->root_idx == c_idx_not_exist)\n"
"  {\n"
"    return c_idx_not_exist;\n"
"  }\n"
"\n"
"  unsigned good_idx = c_idx_not_exist;\n"
"  unsigned node_idx = this->root_idx;\n"
"  do {\n"
"    %s_node *node = this->data + node_idx;\n"
"\n"
,IM_STRUCT_NAME);
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"    int comp_result = %s___compare_value(this,&a_value,&node->object);\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"    int comp_result = %s___compare_value(this,a_value,&node->object);\n"
,IM_STRUCT_NAME);
   }
fprintf(out_file,
"    if (comp_result < 0)\n"
"    {\n"
"      node_idx = node->left_idx;\n"
"    }\n"
"    else\n"
"    {\n"
"      if (comp_result == 0)\n"
"      {\n"
"        good_idx = node_idx;\n"
"        node_idx = node->left_idx;\n"
"      }\n"
"      else\n"
"      {\n"
"        node_idx = node->right_idx;\n"
"      }\n"
"    }\n"
"  } while(node_idx != this->leaf_idx);\n"
"\n"
"  return good_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RB_TREE_GET_GRE_IDX(RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"unsigned %s_get_gre_idx(const %s *this,%s a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_TYPE_NAMES(0));
   }
   else {
fprintf(out_file,
"unsigned %s_get_gre_idx(const %s *this,const %s *a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_TYPE_NAMES(0));
   }
fprintf(out_file,
"{/*{{{*/\n"
"  if (this->root_idx == c_idx_not_exist)\n"
"  {\n"
"    return c_idx_not_exist;\n"
"  }\n"
"\n"
"  unsigned good_idx = c_idx_not_exist;\n"
"  unsigned node_idx = this->root_idx;\n"
"  do {\n"
"    %s_node *node = this->data + node_idx;\n"
"\n"
,IM_STRUCT_NAME);
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"    int comp_result = %s___compare_value(this,&a_value,&node->object);\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"    int comp_result = %s___compare_value(this,a_value,&node->object);\n"
,IM_STRUCT_NAME);
   }
fprintf(out_file,
"    if (comp_result < 0)\n"
"    {\n"
"      good_idx = node_idx;\n"
"      node_idx = node->left_idx;\n"
"    }\n"
"    else\n"
"    {\n"
"      if (comp_result == 0)\n"
"      {\n"
"        return node_idx;\n"
"      }\n"
"\n"
"      node_idx = node->right_idx;\n"
"    }\n"
"  } while(node_idx != this->leaf_idx);\n"
"\n"
"  return good_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RB_TREE_GET_LEE_IDX(RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"unsigned %s_get_lee_idx(const %s *this,%s a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_TYPE_NAMES(0));
   }
   else {
fprintf(out_file,
"unsigned %s_get_lee_idx(const %s *this,const %s *a_value)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_TYPE_NAMES(0));
   }
fprintf(out_file,
"{/*{{{*/\n"
"  if (this->root_idx == c_idx_not_exist)\n"
"  {\n"
"    return c_idx_not_exist;\n"
"  }\n"
"\n"
"  unsigned good_idx = c_idx_not_exist;\n"
"  unsigned node_idx = this->root_idx;\n"
"  do {\n"
"    %s_node *node = this->data + node_idx;\n"
"\n"
,IM_STRUCT_NAME);
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"    int comp_result = %s___compare_value(this,&a_value,&node->object);\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"    int comp_result = %s___compare_value(this,a_value,&node->object);\n"
,IM_STRUCT_NAME);
   }
fprintf(out_file,
"    if (comp_result < 0)\n"
"    {\n"
"      node_idx = node->left_idx;\n"
"    }\n"
"    else\n"
"    {\n"
"      if (comp_result == 0)\n"
"      {\n"
"        return node_idx;\n"
"      }\n"
"\n"
"      good_idx = node_idx;\n"
"      node_idx = node->right_idx;\n"
"    }\n"
"  } while(node_idx != this->leaf_idx);\n"
"\n"
"  return good_idx;\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RB_TREE_GET_IDXS(RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"void %s_get_idxs(const %s *this,%s a_value,ui_array_s *a_idxs_array)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_TYPE_NAMES(0));
   }
   else {
fprintf(out_file,
"void %s_get_idxs(const %s *this,const %s *a_value,ui_array_s *a_idxs_array)\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_TYPE_NAMES(0));
   }
fprintf(out_file,
"{/*{{{*/\n"
"  a_idxs_array->used = 0;\n"
"\n"
"  if (this->root_idx == c_idx_not_exist)\n"
"  {\n"
"    return;\n"
"  }\n"
"\n"
"  unsigned stack[RB_TREE_STACK_SIZE(%s,this)];\n"
"  unsigned *stack_ptr = stack;\n"
"\n"
"  *(stack_ptr++) = this->root_idx;\n"
"  do {\n"
"    unsigned node_idx = *(--stack_ptr);\n"
"    %s_node *node = this->data + node_idx;\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"    int comp_result = %s___compare_value(this,&a_value,&node->object);\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"    int comp_result = %s___compare_value(this,a_value,&node->object);\n"
,IM_STRUCT_NAME);
   }
fprintf(out_file,
"    if (comp_result < 0)\n"
"    {\n"
"      if (node->left_idx != this->leaf_idx)\n"
"      {\n"
"        *(stack_ptr++) = node->left_idx;\n"
"      }\n"
"    }\n"
"    else\n"
"    {\n"
"      if (comp_result == 0)\n"
"      {\n"
"        ui_array_s_push(a_idxs_array,node_idx);\n"
"\n"
"        if (node->left_idx != this->leaf_idx)\n"
"        {\n"
"          *(stack_ptr++) = node->left_idx;\n"
"        }\n"
"      }\n"
"\n"
"      if (node->right_idx != this->leaf_idx)\n"
"      {\n"
"        *(stack_ptr++) = node->right_idx;\n"
"      }\n"
"    }\n"
"  } while(stack_ptr > stack);\n"
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RB_TREE_OPERATOR_EQUAL(RB_TREE_GEN_PARAMS)
{/*{{{*/
   if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
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
"  if (a_src->root_idx == c_idx_not_exist)\n"
"  {\n"
"    return;\n"
"  }\n"
,IM_STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"\n"
"  debug_assert(a_src->used != 0);\n"
"  %s_copy_resize(this,a_src->used);\n"
,IM_STRUCT_NAME);
   }
   if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
fprintf(out_file,
"\n"
"  memcpy(this->data,a_src->data,a_src->used*sizeof(%s_node));\n"
,IM_STRUCT_NAME);
   }
   else {
fprintf(out_file,
"\n"
"  %s_node *ptr = this->data;\n"
"  %s_node *s_ptr = a_src->data;\n"
"  %s_node *s_ptr_end = s_ptr + a_src->used;\n"
"\n"
"  do {\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
fprintf(out_file,
"    ptr->object = s_ptr->object;\n"
);
   }
   else {
fprintf(out_file,
"    %s_copy(&ptr->object,&s_ptr->object);\n"
,IM_TYPE_NAMES(0));
   }
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"    ptr->valid = s_ptr->valid;\n"
);
   }
fprintf(out_file,
"    ptr->parent_idx = s_ptr->parent_idx;\n"
"    ptr->left_idx = s_ptr->left_idx;\n"
"    ptr->right_idx = s_ptr->right_idx;\n"
"    ptr->color = s_ptr->color;\n"
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
"  this->root_idx = a_src->root_idx;\n"
"  this->leaf_idx = a_src->leaf_idx;\n"
);
   if (VAR_NAMES_CNT > 0) {
fprintf(out_file,
"\n"
);
      unsigned t_idx = 0;
      do {
         if (!(TYPE_NUMBERS(t_idx + 1) & c_type_dynamic)) {
fprintf(out_file,
"  this->%s = a_src->%s;\n"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
         }
         else {
fprintf(out_file,
"  %s_copy(&this->%s,&a_src->%s);\n"
,IM_TYPE_NAMES(t_idx + 1),VAR_NAMES(t_idx),VAR_NAMES(t_idx));
         }
      } while(++t_idx < VAR_NAMES_CNT);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RB_TREE_OPERATOR_DOUBLE_EQUAL(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"int %s_compare(const %s *this,const %s *a_second)\n"
"{/*{{{*/\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  if (this->count != a_second->count)\n"
"  {\n"
"     return 0;\n"
"  }\n"
"\n"
);
   }
fprintf(out_file,
"  if (this->root_idx == c_idx_not_exist)\n"
"  {\n"
"    if (a_second->root_idx != c_idx_not_exist)\n"
"    {\n"
"      return 0;\n"
"    }\n"
"  }\n"
"  else\n"
"  {\n"
"    if (a_second->root_idx == c_idx_not_exist)\n"
"    {\n"
"      return 0;\n"
"    }\n"
"\n"
"    unsigned stack[RB_TREE_STACK_SIZE(%s,this)];\n"
"    unsigned s_stack[RB_TREE_STACK_SIZE(%s,a_second)];\n"
"\n"
"    unsigned *stack_ptr = stack;\n"
"    unsigned *s_stack_ptr = s_stack;\n"
"\n"
"    unsigned node_idx = %s_get_stack_min_value_idx(this,this->root_idx,&stack_ptr);\n"
"    unsigned s_node_idx = %s_get_stack_min_value_idx(a_second,a_second->root_idx,&s_stack_ptr);\n"
"    do {\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"      if (this->data[node_idx].object != a_second->data[s_node_idx].object)\n"
"      {\n"
);
   }
   else {
fprintf(out_file,
"      if (!%s_compare(&this->data[node_idx].object,&a_second->data[s_node_idx].object))\n"
"      {\n"
,IM_TYPE_NAMES(0));
   }
fprintf(out_file,
"        return 0;\n"
"      }\n"
"\n"
"      node_idx = %s_get_stack_next_idx(this,node_idx,&stack_ptr,stack);\n"
"      s_node_idx = %s_get_stack_next_idx(a_second,s_node_idx,&s_stack_ptr,s_stack);\n"
"    } while(node_idx != c_idx_not_exist && s_node_idx != c_idx_not_exist);\n"
"\n"
"    if (node_idx != s_node_idx)\n"
"    {\n"
"      return 0;\n"
"    }\n"
"  }\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME);
   if (VAR_NAMES_CNT > 0) {
      if (TYPE_NUMBERS(1) & c_type_basic) {
fprintf(out_file,
"  return (this->%s == a_second->%s"
,VAR_NAMES(0),VAR_NAMES(0));
      }
      else {
fprintf(out_file,
"  return (%s_compare(&this->%s,&a_second->%s)"
,IM_TYPE_NAMES(1),VAR_NAMES(0),VAR_NAMES(0));
      }
      if (VAR_NAMES_CNT > 1) {
         unsigned t_idx = 1;
         do {
            if (TYPE_NUMBERS(t_idx + 1) & c_type_basic) {
fprintf(out_file,
" && this->%s == a_second->%s"
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));
            }
            else {
fprintf(out_file,
" && %s_compare(&this->%s,&a_second->%s)"
,IM_TYPE_NAMES(t_idx + 1),VAR_NAMES(t_idx),VAR_NAMES(t_idx));
            }
         } while(++t_idx < VAR_NAMES_CNT);
      }
fprintf(out_file,
");\n"
);
   }
   else {
fprintf(out_file,
"  return 1;\n"
);
   }
fprintf(out_file,
"}/*}}}*/\n"
"\n"
);
}/*}}}*/

void RB_TREE_TO_STRING(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"#if OPTION_TO_STRING == ENABLED\n"
"void %s___to_string(const %s *this,bc_array_s *a_trg)\n"
"{/*{{{*/\n"
"  bc_array_s_push(a_trg,'[');\n"
"\n"
"  if (this->root_idx != c_idx_not_exist)\n"
"  {\n"
"    unsigned stack[RB_TREE_STACK_SIZE(%s,this)];\n"
"    unsigned *stack_ptr = stack;\n"
"\n"
"    unsigned idx = %s_get_stack_min_value_idx(this,this->root_idx,&stack_ptr);\n"
"    do {\n"
"      %s_to_string(&(this->data + idx)->object,a_trg);\n"
"\n"
"      idx = %s_get_stack_next_idx(this,idx,&stack_ptr,stack);\n"
"      if (idx == c_idx_not_exist)\n"
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
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME
,IM_TYPE_NAMES(0),IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_REHASH_TREE(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"void %s_rehash_tree(%s *this)\n"
"{/*{{{*/\n"
"  if (this->root_idx == c_idx_not_exist)\n"
"  {\n"
"    return;\n"
"  }\n"
"\n"
"  ui_array_s indexes;\n"
"  ui_array_s_init(&indexes);\n"
"\n"
"  {\n"
"    unsigned stack[RB_TREE_STACK_SIZE(%s,this)];\n"
"    unsigned *stack_ptr = stack;\n"
"\n"
"    unsigned idx = %s_get_stack_min_value_idx(this,this->root_idx,&stack_ptr);\n"
"    do {\n"
"      ui_array_s_push(&indexes,idx);\n"
"\n"
"      idx = %s_get_stack_next_idx(this,idx,&stack_ptr,stack);\n"
"    } while(idx != c_idx_not_exist);\n"
"  }\n"
"\n"
"  this->root_idx = c_idx_not_exist;\n"
"\n"
"  char *processed = (char *)cmalloc(indexes.used);\n"
"  memset(processed,0,indexes.used*sizeof(char));\n"
"\n"
"  unsigned step = indexes.used >> 1;\n"
"  if (step > 0)\n"
"  {\n"
"    do {\n"
"      unsigned idx = step;\n"
"      do {\n"
"        if (!processed[idx])\n"
"        {\n"
"          unsigned node_idx = indexes.data[idx];\n"
"\n"
"          %s___binary_tree_insert(this,node_idx,&this->data[node_idx].object,0);\n"
"          %s___insert_operation(this,node_idx);\n"
"\n"
"          processed[idx] = 1;\n"
"        }\n"
"      } while((idx += step) < indexes.used);\n"
"    } while((step >>= 1) > 0);\n"
"  }\n"
"\n"
"  unsigned node_idx = indexes.data[0];\n"
"  %s___binary_tree_insert(this,node_idx,&this->data[node_idx].object,0);\n"
"  %s___insert_operation(this,node_idx);\n"
"\n"
"  cfree(processed);\n"
"  ui_array_s_clear(&indexes);\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME
,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_PRINT_DOT_CODE(RB_TREE_GEN_PARAMS)
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
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void RB_TREE_CHECK_PROPERTIES(RB_TREE_GEN_PARAMS)
{/*{{{*/
fprintf(out_file,
"int %s_check_properties(const %s *this)\n"
"{/*{{{*/\n"
"  %s_node *leaf = this->data + this->leaf_idx;\n"
"  if (!leaf->color)\n"
"  {\n"
"    fprintf(stderr,\"ERROR: leaf_node color\\n\");\n"
"    return 0;\n"
"  }\n"
"\n"
"  if (leaf->left_idx != c_idx_not_exist || leaf->right_idx != c_idx_not_exist)\n"
"  {\n"
"    fprintf(stderr,\"ERROR: leaf_node indexes (INFO: is allowed setting in mt_automaton code?)\\n\");\n"
"    return 0;\n"
"  }\n"
"\n"
"  if (this->root_idx != c_idx_not_exist)\n"
"  {\n"
"    /* - check if root node is black - */\n"
"    %s_node *r_node = this->data + this->root_idx;\n"
"    if (!r_node->color)\n"
"    {\n"
"      fprintf(stderr,\"ERROR: root node is not black\\n\");\n"
"      return 0;\n"
"    }\n"
"\n"
"    /* - create node index and path length stacks - */\n"
"    ui_array_s ni_stack;\n"
"    ui_array_s pl_stack;\n"
"\n"
"    ui_array_s_init(&ni_stack);\n"
"    ui_array_s_init(&pl_stack);\n"
"\n"
"    /* - insert root on stack - */\n"
"    ui_array_s_push(&ni_stack,this->root_idx);\n"
"    ui_array_s_push(&pl_stack,0);\n"
"\n"
"    unsigned r_path_length = c_idx_not_exist;\n"
"    do {\n"
"      unsigned node_idx = ui_array_s_pop(&ni_stack);\n"
"      unsigned path_length = ui_array_s_pop(&pl_stack);\n"
"      unsigned stack_depth = ni_stack.used;\n"
"\n"
"      %s_node *node = this->data + node_idx;\n"
"\n"
"      if (node->color)\n"
"      {\n"
"        path_length++;\n"
"      }\n"
"      else\n"
"      {\n"
"        if (node->left_idx == c_idx_not_exist || node->right_idx == c_idx_not_exist)\n"
"        {\n"
"          fprintf(stderr,\"ERROR: red node has not two childs!\\n\");\n"
"          ui_array_s_clear(&ni_stack);\n"
"          ui_array_s_clear(&pl_stack);\n"
"          return 0;\n"
"        }\n"
"\n"
"        if (!this->data[node->left_idx].color || !this->data[node->right_idx].color)\n"
"        {\n"
"          fprintf(stderr,\"ERROR: child of red node is not black!\\n\");\n"
"          ui_array_s_clear(&ni_stack);\n"
"          ui_array_s_clear(&pl_stack);\n"
"          return 0;\n"
"        }\n"
"      }\n"
"\n"
"      if (node->left_idx != c_idx_not_exist)\n"
"      {\n"
"        ui_array_s_push(&ni_stack,node->left_idx);\n"
"        ui_array_s_push(&pl_stack,path_length);\n"
"      }\n"
"\n"
"      if (node->right_idx != c_idx_not_exist)\n"
"      {\n"
"        ui_array_s_push(&ni_stack,node->right_idx);\n"
"        ui_array_s_push(&pl_stack,path_length);\n"
"      }\n"
"\n"
"      /* - if node is leaf node - */\n"
"      if (stack_depth == ni_stack.used)\n"
"      {\n"
"        if (r_path_length != c_idx_not_exist)\n"
"        {\n"
"          if (r_path_length != path_length)\n"
"          {\n"
"            fprintf(stderr,\"ERROR: all path have no same length!\\n\");\n"
"            ui_array_s_clear(&ni_stack);\n"
"            ui_array_s_clear(&pl_stack);\n"
"            return 0;\n"
"          }\n"
"        }\n"
"        else\n"
"        {\n"
"          r_path_length = path_length;\n"
"        }\n"
"      }\n"
"\n"
"    } while(ni_stack.used > 0);\n"
"\n"
"    ui_array_s_clear(&ni_stack);\n"
"    ui_array_s_clear(&pl_stack);\n"
"  }\n"
"\n"
"  /* - test if are node values sorted - */\n"
"  if (this->root_idx != c_idx_not_exist)\n"
"  {\n"
"    unsigned stack[RB_TREE_STACK_SIZE(%s,this)];\n"
"    unsigned *stack_ptr = stack;\n"
"\n"
"    unsigned idx = %s_get_stack_min_value_idx(this,this->root_idx,&stack_ptr);\n"
"    do {\n"
"      unsigned l_idx = idx;\n"
"      idx = %s_get_stack_next_idx(this,idx,&stack_ptr,stack);\n"
"      if (idx == c_idx_not_exist)\n"
"      {\n"
"        break;\n"
"      }\n"
"\n"
"      if (%s___compare_value(this,&this->data[l_idx].object,&this->data[idx].object) == 1)\n"
"      {\n"
"        fprintf(stderr,\"ERROR: values in rb_tree are not sorted\\n\");\n"
"        return 0;\n"
"      }\n"
"    } while(1);\n"
"  }\n"
"\n"
"  return 1;\n"
"}/*}}}*/\n"
"\n"
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);
}/*}}}*/

void processor_s::generate_rb_tree_type()
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

      data_type_name_len += strlen(c_cont_postfixes[c_cont_rb_tree]) - 1;
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

      memcpy(--dtn_ptr,c_cont_postfixes[c_cont_rb_tree],strlen(c_cont_postfixes[c_cont_rb_tree]));
   }

   string_s &data_type_name = abbs[0];

   unsigned data_type_idx;

   if ((data_type_idx = abbreviations.get_idx_by_name(data_type_name.size - 1,data_type_name.data)) == c_idx_not_exist) {

      unsigned d_idx = data_types.get_idx_by_real_name(real_name.size - 1,real_name.data);
      if (d_idx != c_idx_not_exist) {
         fprintf(stderr,"DUPLICATE STRUCTURES: %s <-> %s\n",data_type_name.data,data_types[d_idx].name.data);
      }

      data_types.push_blank();
      data_type_s &data_type = data_types.last();

      data_type.cont_idx = c_cont_rb_tree;
      data_type.name.set(data_type_name.size - 1,data_type_name.data);
      data_type.real_name.swap(real_name);

      // - retrieve of types pointers -
      {
         unsigned tn_idx = 0;
         do {
            types[tn_idx] = &data_types[type_idxs[tn_idx]];
         } while(++tn_idx < type_cnt);
      }

      data_type.properties = c_type_dynamic | c_type_flushable  | (type_settings & c_type_option_mask);

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

   if (gen_options & c_option_gen_code) {
   // - definition of structure rb_tree -

fprintf(out_file,
"// struct %s definition\n"
"\n"
"#if c_array_add < 2\n"
"#error Container grow constant 'c_array_add' must be at least 2\n"
"#endif\n"
"\n"
"typedef struct %s_node %s_node;\n"
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
"struct %s_node\n"
"{\n"
"  %s object;\n"
,STRUCT_NAME,IM_TYPE_NAMES(0));
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  char valid;\n"
);
   }
fprintf(out_file,
"  unsigned parent_idx;\n"
"  unsigned left_idx;\n"
"  unsigned right_idx;\n"
"  char color;\n"
"};\n"
"\n"
"struct %s\n"
"{\n"
"  unsigned size;\n"
"  unsigned used;\n"
,STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_safe) {
fprintf(out_file,
"  unsigned count;\n"
);
   }
fprintf(out_file,
"  %s_node *data;\n"
"  unsigned free_idx;\n"
"  unsigned root_idx;\n"
"  unsigned leaf_idx;\n"
,STRUCT_NAME);
   if (VAR_NAMES_CNT > 0) {
      unsigned t_idx = 0;
      do {
fprintf(out_file,
"  %s %s; //!< member - %u\n"
,TYPE_NAMES(t_idx + 1),VAR_NAMES(t_idx),t_idx);
      } while(++t_idx < VAR_NAMES_CNT);
   }
fprintf(out_file,
"};\n"
"\n"
"static inline unsigned %s___get_grandparent_idx(const %s *this,unsigned a_idx);\n"
"static inline unsigned %s___get_uncle_idx(const %s *this,unsigned a_idx);\n"
"static inline unsigned %s___get_sibling_idx(const %s *this,unsigned a_idx);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
fprintf(out_file,
"static inline unsigned %s_get_descent_stack_size(const %s *this);\n"
"EXPORT unsigned %s_get_stack_min_value_idx(const %s *this,unsigned a_idx,unsigned **a_s_ptr);\n"
"static inline unsigned %s_get_stack_next_idx(const %s *this,unsigned a_idx,unsigned **a_s_ptr,const unsigned *a_stack_base);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
fprintf(out_file,
"EXPORT unsigned %s_get_min_value_idx(const %s *this,unsigned a_idx);\n"
"EXPORT unsigned %s_get_max_value_idx(const %s *this,unsigned a_idx);\n"
"EXPORT unsigned %s_get_next_idx(const %s *this,unsigned a_idx);\n"
"EXPORT unsigned %s_get_prev_idx(const %s *this,unsigned a_idx);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
fprintf(out_file,
"static inline void %s___rotate_left(%s *this,unsigned a_idx);\n"
"static inline void %s___rotate_right(%s *this,unsigned a_idx);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
fprintf(out_file,
"static inline unsigned %s___get_new_index(%s *this);\n"
"EXPORT unsigned %s___binary_tree_insert(%s *this,unsigned a_new_idx,const %s *a_value,int a_unique);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,IM_TYPE_NAMES(0));
fprintf(out_file,
"static inline void %s___replace_delete_node_by_child(%s *this,unsigned a_idx,unsigned a_ch_idx);\n"
"void %s___remove_black_black(%s *this,unsigned a_idx);\n"
"static inline void %s___remove_one_child(%s *this,unsigned a_idx,unsigned a_ch_idx);\n"
"EXPORT void %s___insert_operation(%s *this,unsigned a_idx);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
fprintf(out_file,
"static inline int %s___compare_value(const %s *this,const %s *a_first,const %s *a_second);\n"
,STRUCT_NAME,STRUCT_NAME,IM_TYPE_NAMES(0),IM_TYPE_NAMES(0));
   if (!(STRUCT_NUMBER & c_type_option_nogen_init)) {
fprintf(out_file,
"static inline void %s_init(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
fprintf(out_file,
"static inline void %s_init_buffer(%s *this,unsigned a_size,%s_node *a_data);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   }
   if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
      if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
fprintf(out_file,
"static inline void %s_clear(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
      }
      else {
fprintf(out_file,
"EXPORT void %s_clear(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
      }
   }
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
     if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
fprintf(out_file,
"static inline void %s_set_buffer(%s *this,unsigned a_size,%s_node *a_data);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
      }
      else {
fprintf(out_file,
"EXPORT void %s_set_buffer(%s *this,unsigned a_size,%s_node *a_data);\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
      }
   }
fprintf(out_file,
"static inline void %s_flush(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   if (!(TYPE_NUMBERS(0) & c_type_flushable)) {
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
,IM_TYPE_NAMES(0),STRUCT_NAME,STRUCT_NAME);
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"static inline unsigned %s_insert(%s *this,%s a_value);\n"
"static inline unsigned %s_unique_insert(%s *this,%s a_value);\n"
,STRUCT_NAME,STRUCT_NAME,IM_TYPE_NAMES(0),STRUCT_NAME,STRUCT_NAME,IM_TYPE_NAMES(0));
   }
   else {
fprintf(out_file,
"static inline unsigned %s_insert(%s *this,const %s *a_value);\n"
"static inline unsigned %s_unique_insert(%s *this,const %s *a_value);\n"
,STRUCT_NAME,STRUCT_NAME,IM_TYPE_NAMES(0),STRUCT_NAME,STRUCT_NAME,IM_TYPE_NAMES(0));
   }
   if (TYPE_NUMBERS(0) & c_type_dynamic) {
fprintf(out_file,
"static inline unsigned %s_swap_insert(%s *this,%s *a_value);\n"
"static inline unsigned %s_unique_swap_insert(%s *this,%s *a_value);\n"
,STRUCT_NAME,STRUCT_NAME,IM_TYPE_NAMES(0),STRUCT_NAME,STRUCT_NAME,IM_TYPE_NAMES(0));
   }
fprintf(out_file,
"EXPORT void %s_remove(%s *this,unsigned a_idx);\n"
,STRUCT_NAME,STRUCT_NAME);
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
fprintf(out_file,
"EXPORT void %s_copy_resize(%s *this,unsigned a_size);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"EXPORT unsigned %s_get_idx(const %s *this,%s a_value);\n"
"EXPORT unsigned %s_get_idx_left(const %s *this,%s a_value);\n"
"EXPORT unsigned %s_get_gre_idx(const %s *this,%s a_value);\n"
"EXPORT unsigned %s_get_lee_idx(const %s *this,%s a_value);\n"
,STRUCT_NAME,STRUCT_NAME,IM_TYPE_NAMES(0)
,STRUCT_NAME,STRUCT_NAME,IM_TYPE_NAMES(0)
,STRUCT_NAME,STRUCT_NAME,IM_TYPE_NAMES(0)
,STRUCT_NAME,STRUCT_NAME,IM_TYPE_NAMES(0));
   }
   else {
fprintf(out_file,
"EXPORT unsigned %s_get_idx(const %s *this,const %s *a_value);\n"
"EXPORT unsigned %s_get_idx_left(const %s *this,const %s *a_value);\n"
"EXPORT unsigned %s_get_gre_idx(const %s *this,const %s *a_value);\n"
"EXPORT unsigned %s_get_lee_idx(const %s *this,const %s *a_value);\n"
,STRUCT_NAME,STRUCT_NAME,IM_TYPE_NAMES(0)
,STRUCT_NAME,STRUCT_NAME,IM_TYPE_NAMES(0)
,STRUCT_NAME,STRUCT_NAME,IM_TYPE_NAMES(0)
,STRUCT_NAME,STRUCT_NAME,IM_TYPE_NAMES(0));
   }
   if (TYPE_NUMBERS(0) & c_type_basic) {
fprintf(out_file,
"EXPORT void %s_get_idxs(const %s *this,%s a_value,ui_array_s *a_idxs_array);\n"
,STRUCT_NAME,STRUCT_NAME,IM_TYPE_NAMES(0));
   }
   else {
fprintf(out_file,
"EXPORT void %s_get_idxs(const %s *this,const %s *a_value,ui_array_s *a_idxs_array);\n"
,STRUCT_NAME,STRUCT_NAME,IM_TYPE_NAMES(0));
   }
   if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
      if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
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
"#endif\n"
,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME,STRUCT_NAME);
   if (STRUCT_NUMBER & c_type_option_rehash) {
fprintf(out_file,
"EXPORT void %s_rehash_tree(%s *this);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
   if (STRUCT_NUMBER & c_type_option_print_dot_code) {
fprintf(out_file,
"EXPORT void %s_print_dot_code(const %s *this,FILE *a_file);\n"
,STRUCT_NAME,STRUCT_NAME);
   }
   if (STRUCT_NUMBER & c_type_option_check_properties) {
fprintf(out_file,
"EXPORT int %s_check_properties(const %s *this);\n"
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

void processor_s::generate_rb_tree_inlines(unsigned abb_idx,unsigned a_dt_idx)
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

   if (gen_options & c_option_gen_code) {
   // --- definition of inline methods ---

fprintf(out_file,
"// --- struct %s inline method definition ---\n"
"\n"
,IM_STRUCT_NAME);

   // - rb_tree __get_grandparent_idx method -
RB_TREE___GET_GRANDPARENT_IDX(RB_TREE_GEN_VALUES);

   // - rb_tree __get_uncle_idx method -
RB_TREE___GET_UNCLE_IDX(RB_TREE_GEN_VALUES);

   // - rb_tree __get_sibling_idx method -
RB_TREE___GET_SIBLING_IDX(RB_TREE_GEN_VALUES);

   // - rb_tree get_descent_stack_size -
RB_TREE_GET_DESCENT_STACK_SIZE(RB_TREE_GEN_VALUES);

   // - rb_tree get_stack_min_value_idx method -

   // - rb_tree get_stack_next_idx method -
RB_TREE_GET_STACK_NEXT_IDX(RB_TREE_GEN_VALUES);

   // - rb_tree get_min_value_idx method -

   // - rb_tree get_max_value_idx method -

   // - rb_tree get_next_idx method -

   // - rb_tree get_prev_idx method -

   // - rb_tree __rotate_left method -
RB_TREE___ROTATE_LEFT(RB_TREE_GEN_VALUES);

   // - rb_tree __rotate_right method -
RB_TREE___ROTATE_RIGHT(RB_TREE_GEN_VALUES);

   // - rb_tree __get_new_index method -
RB_TREE___GET_NEW_INDEX(RB_TREE_GEN_VALUES);

   // - rb_tree __binary_tree_insert method -

   // - rb_tree __replace_delete_node_by_child method -
RB_TREE___REPLACE_DELETE_NODE_BY_CHILD(RB_TREE_GEN_VALUES);

   // - rb_tree __remove_black_black method -

   // - rb_tree __remove_one_child method -
RB_TREE___REMOVE_ONE_CHILD(RB_TREE_GEN_VALUES);

   // - rb_tree __insert_operation method -

   // - rb_tree init method -
RB_TREE_INIT(RB_TREE_GEN_VALUES);

   // - rb_tree init_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer) {
RB_TREE_INIT_BUFFER(RB_TREE_GEN_VALUES);
   }

   // - rb_tree clear method -
   if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
RB_TREE_CLEAR(RB_TREE_GEN_VALUES);
      }
   }

   // - rb_tree set_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer && !(TYPE_NUMBERS(0) & c_type_dynamic)) {
RB_TREE_SET_BUFFER(RB_TREE_GEN_VALUES);
   }

   // - rb_tree flush method -
RB_TREE_FLUSH(RB_TREE_GEN_VALUES);

   // - rb_tree flush_all method -
   if (!(TYPE_NUMBERS(0) & c_type_flushable)) {
RB_TREE_FLUSH_ALL(RB_TREE_GEN_VALUES);
   }

   // - rb_tree swap method -
   if (!(STRUCT_NUMBER & c_type_option_nogen_swap)) {
RB_TREE_SWAP(RB_TREE_GEN_VALUES);
   }

   // - rb_tree operator[] method -
RB_TREE_OPERATOR_LE_BR_RE_BR(RB_TREE_GEN_VALUES);

   // - rb_tree insert method -
RB_TREE_INSERT(RB_TREE_GEN_VALUES);

   // - rb_tree swap_insert method -
RB_TREE_SWAP_INSERT(RB_TREE_GEN_VALUES);

   // - rb_tree unique_insert method -
RB_TREE_UNIQUE_INSERT(RB_TREE_GEN_VALUES);

   // - rb_tree unique_swap_insert method -
RB_TREE_UNIQUE_SWAP_INSERT(RB_TREE_GEN_VALUES);

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
RB_TREE_OPERATOR_EQUAL(RB_TREE_GEN_VALUES);
      }
   }

   // - rb_tree operator== method -

   // - rb_tree to_string method -

   // - rb_tree rehash_tree -

   // - rb_tree print_dot_code -

   // - rb_tree check_properties -
   }
}/*}}}*/

void processor_s::generate_rb_tree_methods(unsigned abb_idx,unsigned a_dt_idx)
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

   if (gen_options & c_option_gen_code) {
   // --- definition of methods ---

fprintf(out_file,
"// --- struct %s method definition ---\n"
"\n"
,IM_STRUCT_NAME);

   // - rb_tree __get_grandparent_idx method -

   // - rb_tree __get_uncle_idx method -

   // - rb_tree __get_sibling_idx method -

   // - rb_tree get_descent_stack_size -

   // - rb_tree get_stack_min_value_idx method -
RB_TREE_GET_STACK_MIN_VALUE_IDX(RB_TREE_GEN_VALUES);

   // - rb_tree get_stack_next_idx method -

   // - rb_tree get_min_value_idx method -
RB_TREE_GET_MIN_VALUE_IDX(RB_TREE_GEN_VALUES);

   // - rb_tree get_max_value_idx method -
RB_TREE_GET_MAX_VALUE_IDX(RB_TREE_GEN_VALUES);

   // - rb_tree get_next_idx method -
RB_TREE_GET_NEXT_IDX(RB_TREE_GEN_VALUES);

   // - rb_tree get_prev_idx method -
RB_TREE_GET_PREV_IDX(RB_TREE_GEN_VALUES);

   // - rb_tree __rotate_left method -

   // - rb_tree __rotate_right method -

   // - rb_tree __get_new_index method -

   // - rb_tree __binary_tree_insert method -
RB_TREE___BINARY_TREE_INSERT(RB_TREE_GEN_VALUES);

   // - rb_tree __replace_delete_node_by_child method -

   // - rb_tree __remove_black_black method -
RB_TREE___REMOVE_BLACK_BLACK(RB_TREE_GEN_VALUES);

   // - rb_tree __remove_one_child method -

   // - rb_tree __insert_operation method -
RB_TREE___INSERT_OPERATION(RB_TREE_GEN_VALUES);

   // - rb_tree init method -

   // - rb_tree init_buffer method -

   // - rb_tree clear method -
   if (TYPE_NUMBERS(0) & c_type_dynamic) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_clear)) {
RB_TREE_CLEAR(RB_TREE_GEN_VALUES);
      }
   }

   // - rb_tree set_buffer method -
   if (STRUCT_NUMBER & c_type_option_fixed_buffer && TYPE_NUMBERS(0) & c_type_dynamic) {
RB_TREE_SET_BUFFER(RB_TREE_GEN_VALUES);
   }

   // - rb_tree flush method -

   // - rb_tree flush_all method -
   if (TYPE_NUMBERS(0) & c_type_flushable) {
RB_TREE_FLUSH_ALL(RB_TREE_GEN_VALUES);
   }

   // - rb_tree swap method -

   // - rb_tree operator[] method -

   // - rb_tree insert method -

   // - rb_tree swap_insert method -

   // - rb_tree unique_insert method -

   // - rb_tree unique_swap_insert method -

   // - rb_tree remove method -
RB_TREE_REMOVE(RB_TREE_GEN_VALUES);

   // - rb_tree copy_resize method -
   if (!(STRUCT_NUMBER & c_type_option_fixed_buffer)) {
RB_TREE_COPY_RESIZE(RB_TREE_GEN_VALUES);
   }

   // - rb_tree get_idx method -
RB_TREE_GET_IDX(RB_TREE_GEN_VALUES);

   // - rb_tree get_idx_left method -
RB_TREE_GET_IDX_LEFT(RB_TREE_GEN_VALUES);

   // - rb_tree get_gre_idx method -
RB_TREE_GET_GRE_IDX(RB_TREE_GEN_VALUES);

   // - rb_tree get_lee_idx method -
RB_TREE_GET_LEE_IDX(RB_TREE_GEN_VALUES);

   // - rb_tree get_idxs method -
RB_TREE_GET_IDXS(RB_TREE_GEN_VALUES);

   // - rb_tree operator= method -
   if (TYPE_NUMBERS(0) & c_type_dynamic) {
      if (!(STRUCT_NUMBER & c_type_option_nogen_copy)) {
RB_TREE_OPERATOR_EQUAL(RB_TREE_GEN_VALUES);
      }
   }

   // - rb_tree operator== method -
RB_TREE_OPERATOR_DOUBLE_EQUAL(RB_TREE_GEN_VALUES);

   // - rb_tree to_string method -
RB_TREE_TO_STRING(RB_TREE_GEN_VALUES);

   // - rb_tree rehash_tree -
   if (STRUCT_NUMBER & c_type_option_rehash) {
RB_TREE_REHASH_TREE(RB_TREE_GEN_VALUES);
   }

   // - rb_tree print_dot_code -
   if (STRUCT_NUMBER & c_type_option_print_dot_code) {
RB_TREE_PRINT_DOT_CODE(RB_TREE_GEN_VALUES);
   }

   // - rb_tree check_properties -
   if (STRUCT_NUMBER & c_type_option_check_properties) {
RB_TREE_CHECK_PROPERTIES(RB_TREE_GEN_VALUES);
   }
   }
}/*}}}*/


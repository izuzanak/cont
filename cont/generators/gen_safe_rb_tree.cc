
//#define SAFE_RB_TREE_GENERATE_PRINT_DOT_CODE
//#define SAFE_RB_TREE_GENERATE_CHECK_RB_TREE_PROPERTIES

#define SAFE_RB_TREE___GET_GRANDPARENT_IDX() \
{\
printf(\
"inline unsigned %s::__get_grandparent_idx(unsigned a_idx)\n"\
"{/*{{{*/\n"\
"   %s_node &node = data[a_idx];\n"\
"\n"\
"   if (node.parent_idx != c_idx_not_exist) {\n"\
"      return data[node.parent_idx].parent_idx;\n"\
"   }\n"\
"   else {\n"\
"      return c_idx_not_exist;\n"\
"   }\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE___GET_UNCLE_IDX() \
{\
printf(\
"inline unsigned %s::__get_uncle_idx(unsigned a_idx)\n"\
"{/*{{{*/\n"\
"   unsigned gp_idx = __get_grandparent_idx(a_idx);\n"\
"\n"\
"   if (gp_idx == c_idx_not_exist) {\n"\
"      return c_idx_not_exist;\n"\
"   }\n"\
"   else {\n"\
"      %s_node &gp = data[gp_idx];\n"\
"      return gp.left_idx == data[a_idx].parent_idx?gp.right_idx:gp.left_idx;\n"\
"   }\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE___GET_SIBLING_IDX() \
{\
printf(\
"inline unsigned %s::__get_sibling_idx(unsigned a_idx)\n"\
"{/*{{{*/\n"\
"   %s_node &p = data[data[a_idx].parent_idx];\n"\
"   return p.left_idx == a_idx?p.right_idx:p.left_idx;\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE_GET_DESCENT_STACK_SIZE() \
{\
printf(\
"inline unsigned %s::get_descent_stack_size()\n"\
"{/*{{{*/\n"\
"   return (unsigned)(logf(used)/c_log_of_2) << 1;\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE_GET_STACK_MIN_VALUE_IDX() \
{\
printf(\
"unsigned %s::get_stack_min_value_idx(unsigned a_idx,unsigned **a_s_ptr)\n"\
"{/*{{{*/\n"\
"   debug_assert(a_idx < used && data[a_idx].valid);\n"\
"\n"\
"   unsigned node_idx = a_idx;\n"\
"   do {\n"\
"      %s_node &node = data[node_idx];\n"\
"\n"\
"      if (node.left_idx == leaf_idx) {\n"\
"         return node_idx;\n"\
"      }\n"\
"\n"\
"      *((*a_s_ptr)++) = node_idx;\n"\
"      node_idx = node.left_idx;\n"\
"   } while(1);\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE_GET_STACK_NEXT_IDX() \
{\
printf(\
"inline unsigned %s::get_stack_next_idx(unsigned a_idx,unsigned **a_s_ptr,unsigned *a_stack_base)\n"\
"{/*{{{*/\n"\
"   debug_assert(a_idx < used && data[a_idx].valid);\n"\
"\n"\
"   %s_node &node = data[a_idx];\n"\
"\n"\
"   if (node.right_idx != leaf_idx) {\n"\
"      return get_stack_min_value_idx(node.right_idx,a_s_ptr);\n"\
"   }\n"\
"\n"\
"   if (*a_s_ptr > a_stack_base) {\n"\
"      return *(--(*a_s_ptr));\n"\
"   }\n"\
"   \n"\
"   return c_idx_not_exist;\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE_GET_MIN_VALUE_IDX() \
{\
printf(\
"unsigned %s::get_min_value_idx(unsigned a_idx)\n"\
"{/*{{{*/\n"\
"   debug_assert(a_idx < used && data[a_idx].valid);\n"\
"\n"\
"   unsigned node_idx = a_idx;\n"\
"   do {\n"\
"      %s_node &node = data[node_idx];\n"\
"\n"\
"      if (node.left_idx == leaf_idx) {\n"\
"         return node_idx;\n"\
"      }\n"\
"\n"\
"      node_idx = node.left_idx;\n"\
"   } while(1);\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE_GET_MAX_VALUE_IDX() \
{\
printf(\
"unsigned %s::get_max_value_idx(unsigned a_idx)\n"\
"{/*{{{*/\n"\
"   debug_assert(a_idx < used && data[a_idx].valid);\n"\
"\n"\
"   unsigned node_idx = a_idx;\n"\
"   do {\n"\
"      %s_node &node = data[node_idx];\n"\
"\n"\
"      if (node.right_idx == leaf_idx) {\n"\
"         return node_idx;\n"\
"      }\n"\
"\n"\
"      node_idx = node.right_idx;\n"\
"   } while(1);\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE_GET_NEXT_IDX() \
{\
printf(\
"unsigned %s::get_next_idx(unsigned a_idx)\n"\
"{/*{{{*/\n"\
"   debug_assert(a_idx < used && data[a_idx].valid);\n"\
"\n"\
"   %s_node &node = data[a_idx];\n"\
"\n"\
"   if (node.right_idx != leaf_idx) {\n"\
"      return get_min_value_idx(node.right_idx);\n"\
"   }\n"\
"   else {\n"\
"\n"\
"      unsigned node_idx = a_idx;\n"\
"      do {\n"\
"         %s_node &node = data[node_idx];\n"\
"\n"\
"         if (node.parent_idx == c_idx_not_exist) {\n"\
"            return c_idx_not_exist;\n"\
"         }\n"\
"         \n"\
"         if (data[node.parent_idx].right_idx != node_idx) {\n"\
"            return node.parent_idx;\n"\
"         }\n"\
"\n"\
"         node_idx = node.parent_idx;\n"\
"      } while(1);\n"\
"   }\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE_GET_PREV_IDX() \
{\
printf(\
"unsigned %s::get_prev_idx(unsigned a_idx)\n"\
"{/*{{{*/\n"\
"   debug_assert(a_idx < used && data[a_idx].valid);\n"\
"\n"\
"   %s_node &node = data[a_idx];\n"\
"\n"\
"   if (node.left_idx != leaf_idx) {\n"\
"      return get_max_value_idx(node.left_idx);\n"\
"   }\n"\
"   else {\n"\
"\n"\
"      unsigned node_idx = a_idx;\n"\
"      do {\n"\
"         %s_node &node = data[node_idx];\n"\
"\n"\
"         if (node.parent_idx == c_idx_not_exist) {\n"\
"            return c_idx_not_exist;\n"\
"         }\n"\
"         \n"\
"         if (data[node.parent_idx].left_idx != node_idx) {\n"\
"            return node.parent_idx;\n"\
"         }\n"\
"\n"\
"         node_idx = node.parent_idx;\n"\
"      } while(1);\n"\
"   }\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE___ROTATE_LEFT() \
{\
printf(\
"inline void %s::__rotate_left(unsigned a_idx)\n"\
"{/*{{{*/\n"\
"   %s_node &root = data[a_idx];\n"\
"   %s_node &pivot = data[root.right_idx];\n"\
"\n"\
"   if (a_idx == root_idx) {\n"\
"      root_idx = root.right_idx;\n"\
"      pivot.parent_idx = c_idx_not_exist;\n"\
"   }\n"\
"   else {\n"\
"      %s_node &rp = data[root.parent_idx];\n"\
"      (rp.right_idx == a_idx?rp.right_idx:rp.left_idx) = root.right_idx;\n"\
"\n"\
"      pivot.parent_idx = root.parent_idx;\n"\
"   }\n"\
"\n"\
"   root.parent_idx = root.right_idx;\n"\
"\n"\
"   root.right_idx = pivot.left_idx;\n"\
"   data[root.right_idx].parent_idx = a_idx;\n"\
"\n"\
"   pivot.left_idx = a_idx;\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE___ROTATE_RIGHT() \
{\
printf(\
"inline void %s::__rotate_right(unsigned a_idx)\n"\
"{/*{{{*/\n"\
"   %s_node &root = data[a_idx];\n"\
"   %s_node &pivot = data[root.left_idx];\n"\
"\n"\
"   if (a_idx == root_idx) {\n"\
"      root_idx = root.left_idx;\n"\
"      pivot.parent_idx = c_idx_not_exist;\n"\
"   }\n"\
"   else {\n"\
"      %s_node &rp = data[root.parent_idx];\n"\
"      (rp.right_idx == a_idx?rp.right_idx:rp.left_idx) = root.left_idx;\n"\
"\n"\
"      pivot.parent_idx = root.parent_idx;\n"\
"   }\n"\
"\n"\
"   root.parent_idx = root.left_idx;\n"\
"\n"\
"   root.left_idx = pivot.right_idx;\n"\
"   data[root.left_idx].parent_idx = a_idx;\n"\
"\n"\
"   pivot.right_idx = a_idx;\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE___GET_NEW_INDEX() \
{\
printf(\
"inline unsigned %s::__get_new_index()\n"\
"{/*{{{*/\n"\
"   unsigned new_idx;\n"\
"\n"\
"   if (free_idx != c_idx_not_exist) {\n"\
"      new_idx = free_idx;\n"\
"      free_idx = data[new_idx].parent_idx;\n"\
"   }\n"\
"   else {\n"\
"      if (used >= size) {\n"\
"         copy_resize((size << 1) + c_array_add);\n"\
"      }\n"\
"\n"\
"      new_idx = used++;\n"\
"   }\n"\
"\n" \
"   data[new_idx].valid = true;\n" \
"   count++;\n" \
"\n" \
"   return new_idx;\n" \
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE___BINARY_TREE_INSERT() \
{\
printf(\
"bool %s::__binary_tree_insert(unsigned a_new_idx,%s &a_value,bool a_unique)\n"\
"{/*{{{*/\n"\
"   if (root_idx == c_idx_not_exist) {\n"\
"      if (leaf_idx == c_idx_not_exist) {\n"\
"         leaf_idx = __get_new_index();\n"\
"         %s_node &leaf = data[leaf_idx];\n"\
"\n"\
"         leaf.valid = false;\n"\
"         leaf.color = true;\n"\
"         count--;\n"\
"\n"\
"#ifdef SAFE_RB_TREE_SET_LEAF_CHILDS\n"\
"         leaf.left_idx = c_idx_not_exist;\n"\
"         leaf.right_idx = c_idx_not_exist;\n"\
"#endif\n"\
"      }\n"\
"\n"\
"      data[a_new_idx].parent_idx = c_idx_not_exist;\n"\
"      root_idx = a_new_idx;\n"\
"   }\n"\
"   else  {\n"\
"      unsigned node_idx = root_idx;\n"\
"      do {\n"\
"         %s_node &node = data[node_idx];\n"\
"\n"\
"         int comp_result = __compare_value(a_value,node.object);\n"\
"         if (comp_result < 0) {\n"\
"            if (node.left_idx == leaf_idx) {\n"\
"               node.left_idx = a_new_idx;\n"\
"               break;\n"\
"            }\n"\
"            node_idx = node.left_idx;\n"\
"         }\n"\
"         else {\n"\
"            if (a_unique && comp_result == 0) {\n"\
"               return false;\n"\
"            }\n"\
"\n"\
"            if (node.right_idx == leaf_idx) {\n"\
"               node.right_idx = a_new_idx;\n"\
"               break;\n"\
"            }\n"\
"            node_idx = node.right_idx;\n"\
"         }\n"\
"      } while(1);\n"\
"\n"\
"      data[a_new_idx].parent_idx = node_idx;\n"\
"   }\n"\
"\n"\
"   %s_node &new_node = data[a_new_idx];\n"\
"   new_node.left_idx = leaf_idx;\n"\
"   new_node.right_idx = leaf_idx;\n"\
"   new_node.color = false;\n"\
"\n"\
"   return true;\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_TYPE_NAMES(0),IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE___REPLACE_DELETE_NODE_BY_CHILD() \
{\
printf(\
"inline void %s::__replace_delete_node_by_child(unsigned a_idx,unsigned a_ch_idx)\n"\
"{/*{{{*/\n"\
"   %s_node &node = data[a_idx];\n"\
"\n"\
"   if (node.parent_idx != c_idx_not_exist) {\n"\
"      %s_node &parent = data[node.parent_idx];\n"\
"      (parent.left_idx == a_idx?parent.left_idx:parent.right_idx) = a_ch_idx;\n"\
"\n"\
"      data[a_ch_idx].parent_idx = node.parent_idx;\n"\
"   }\n"\
"   else {\n"\
"      root_idx = a_ch_idx == leaf_idx?c_idx_not_exist:a_ch_idx;\n"\
"      data[a_ch_idx].parent_idx = c_idx_not_exist;\n"\
"   }\n"\
"}/*}}}*/\n"\
"\n" \
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE___REMOVE_BLACK_BLACK()  \
{\
printf(\
"void %s::__remove_black_black(unsigned a_idx)\n"\
"{/*{{{*/\n"\
"   unsigned node_idx = a_idx;\n"\
"   do {\n"\
"      %s_node &node = data[node_idx];\n"\
"      \n"\
"      if (node.parent_idx == c_idx_not_exist) {\n"\
"         return;\n"\
"      }\n"\
"\n"\
"      unsigned parent_idx = node.parent_idx;\n"\
"      %s_node &parent = data[parent_idx];\n"\
"\n"\
"      {\n"\
"         unsigned sibling_idx = parent.left_idx == node_idx?parent.right_idx:parent.left_idx;\n"\
"         %s_node &sibling = data[sibling_idx];\n"\
"\n"\
"         if (!sibling.color) {\n"\
"            parent.color = false;\n"\
"            sibling.color = true;\n"\
"\n"\
"            if (node_idx == parent.left_idx) {\n"\
"               __rotate_left(parent_idx);\n"\
"            }\n"\
"            else {\n"\
"               __rotate_right(parent_idx);\n"\
"            }\n"\
"         }\n"\
"      }\n"\
"\n"\
"      {\n"\
"         unsigned sibling_idx = parent.left_idx == node_idx?parent.right_idx:parent.left_idx;\n"\
"         %s_node& sibling = data[sibling_idx];\n"\
"\n"\
"         if (parent.color && sibling.color && data[sibling.left_idx].color && data[sibling.right_idx].color) {\n"\
"            sibling.color = false;\n"\
"            node_idx = parent_idx;\n"\
"            continue;\n"\
"         }\n"\
"         else if (!parent.color && sibling.color && data[sibling.left_idx].color && data[sibling.right_idx].color) {\n"\
"            sibling.color = false;\n"\
"            parent.color = true;\n"\
"            return;\n"\
"         }\n"\
"         else if (sibling.color) {\n"\
"            if (node_idx == parent.left_idx && data[sibling.right_idx].color && !data[sibling.left_idx].color) {\n"\
"               sibling.color = false;\n"\
"               data[sibling.left_idx].color = true;\n"\
"               __rotate_right(sibling_idx);\n"\
"            }\n"\
"            else if (node_idx == parent.right_idx && data[sibling.left_idx].color && !data[sibling.right_idx].color) {\n"\
"               sibling.color = false;\n"\
"               data[sibling.right_idx].color = true;\n"\
"               __rotate_left(sibling_idx);\n"\
"            }\n"\
"         }\n"\
"\n"\
"         {\n"\
"            unsigned sibling_idx = parent.left_idx == node_idx?parent.right_idx:parent.left_idx;\n"\
"            %s_node &sibling = data[sibling_idx];\n"\
"\n"\
"            sibling.color = parent.color;\n"\
"            parent.color = true;\n"\
"\n"\
"            if (node_idx == parent.left_idx) {\n"\
"               data[sibling.right_idx].color = true;\n"\
"               __rotate_left(parent_idx);\n"\
"            }\n"\
"            else {\n"\
"               data[sibling.left_idx].color = true;\n"\
"               __rotate_right(parent_idx);\n"\
"            }\n"\
"         }\n"\
"\n"\
"         return;\n"\
"      }\n"\
"\n"\
"   } while(1);\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE___REMOVE_ONE_CHILD()  \
{\
printf(\
"inline void %s::__remove_one_child(unsigned a_idx,unsigned a_ch_idx)\n"\
"{/*{{{*/\n"\
"   %s_node &node = data[a_idx];\n"\
"   __replace_delete_node_by_child(a_idx,a_ch_idx);\n"\
"\n"\
"   node.parent_idx = free_idx;\n"\
"   free_idx = a_idx;\n"\
"\n"\
"   node.valid = false;\n"\
"   count--;\n"\
"\n"\
"   if (node.color) {\n"\
"      %s_node &child_node = data[a_ch_idx];\n"\
"\n"\
"      if (!child_node.color) {\n"\
"         child_node.color = true;\n"\
"      }\n"\
"      else {\n"\
"         __remove_black_black(a_ch_idx);\n"\
"      }\n"\
"   }\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE___INSERT_OPERATION() \
{\
printf(\
"void %s::__insert_operation(unsigned a_idx)\n"\
"{/*{{{*/\n"\
"   unsigned node_idx = a_idx;\n"\
"   do {\n"\
"      %s_node &node = data[node_idx];\n"\
"\n"\
"      if (node.parent_idx == c_idx_not_exist) {\n"\
"         node.color = true;\n"\
"         return;\n"\
"      }\n"\
"      else {\n"\
"         if (data[node.parent_idx].color) {\n"\
"            return;\n"\
"         }\n"\
"         else {\n"\
"            unsigned uncle_idx = __get_uncle_idx(node_idx);\n"\
"            if (uncle_idx != c_idx_not_exist && !data[uncle_idx].color) {\n"\
"               data[node.parent_idx].color = true;\n"\
"               data[uncle_idx].color = true;\n"\
"\n"\
"               node_idx = __get_grandparent_idx(node_idx);\n"\
"               data[node_idx].color = false;\n"\
"\n"\
"               continue;\n"\
"            }\n"\
"            else {\n"\
"               unsigned grandparent_idx = __get_grandparent_idx(node_idx);\n"\
"\n"\
"               if (node_idx == data[node.parent_idx].right_idx && node.parent_idx == data[grandparent_idx].left_idx) {\n"\
"                  __rotate_left(node.parent_idx);\n"\
"                  node_idx = node.left_idx;\n"\
"               }\n"\
"               else if (node_idx == data[node.parent_idx].left_idx && node.parent_idx == data[grandparent_idx].right_idx) {\n"\
"                  __rotate_right(node.parent_idx);\n"\
"                  node_idx = node.right_idx;\n"\
"               }\n"\
"\n"\
"               {\n"\
"                  unsigned grandparent_idx = __get_grandparent_idx(node_idx);\n"\
"                  %s_node &node = data[node_idx];\n"\
"\n"\
"                  data[node.parent_idx].color = true;\n"\
"                  data[grandparent_idx].color = false;\n"\
"\n"\
"                  if (node_idx == data[node.parent_idx].left_idx && node.parent_idx == data[grandparent_idx].left_idx) {\n"\
"                     __rotate_right(grandparent_idx);\n"\
"                  }\n"\
"                  else {\n"\
"                     __rotate_left(grandparent_idx);\n"\
"                  }\n"\
"               }\n"\
"\n"\
"               return;\n"\
"            }\n"\
"         }\n"\
"      }\n"\
"   } while(1);\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE_INIT() \
{\
printf(\
"inline void %s::init()\n"\
"{/*{{{*/\n"\
"   size = 0;\n"\
"   used = 0;\n"\
"   count = 0;\n"\
"   data = NULL;\n"\
"   free_idx = c_idx_not_exist;\n"\
"   root_idx = c_idx_not_exist;\n"\
"   leaf_idx = c_idx_not_exist;\n"\
,IM_STRUCT_NAME);\
   if (VAR_NAMES_CNT > 0) {\
      t_idx = 0;\
      do {\
         if (TYPE_NUMBERS(t_idx + 1) & c_type_dynamic) {\
printf(\
"   %s.init();\n"\
,VAR_NAMES(t_idx));\
         }\
      } while(++t_idx < VAR_NAMES_CNT);\
   }\
printf(\
"}/*}}}*/\n"\
"\n"\
);\
}

#define SAFE_RB_TREE_CLEAR() \
{\
   if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {\
printf(\
"inline void %s::clear()\n"\
,IM_STRUCT_NAME);\
   }\
   else {\
printf(\
"void %s::clear()\n"\
,IM_STRUCT_NAME);\
   }\
printf(\
"{/*{{{*/\n"\
"   if (data != NULL) {\n"\
);\
   if (TYPE_NUMBERS(0) & c_type_dynamic) {\
printf(\
"      %s_node *ptr = data;\n"\
"      %s_node *ptr_end = ptr + size;\n"\
"\n"\
"      do {\n"\
"         ptr->object.clear();\n"\
"      } while(++ptr < ptr_end);\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   }\
printf(\
"      cfree(data);\n"\
"   }\n"\
);\
   if (VAR_NAMES_CNT > 0) {\
printf(\
"\n"\
);\
      t_idx = 0;\
      do {\
         if (TYPE_NUMBERS(t_idx + 1) & c_type_dynamic) {\
printf(\
"   %s.clear();\n"\
,VAR_NAMES(t_idx));\
         }\
      } while(++t_idx < VAR_NAMES_CNT);\
   }\
printf(\
"\n"\
"   init();\n"\
"}/*}}}*/\n"\
"\n"\
);\
}

#define SAFE_RB_TREE_FLUSH() \
{\
printf(\
"inline void %s::flush()\n"\
"{/*{{{*/\n"\
"   copy_resize(used);\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE_FLUSH_ALL() \
{\
   if (!(TYPE_NUMBERS(0) & c_type_flushable)) {\
printf(\
"inline void %s::flush_all()\n"\
,IM_STRUCT_NAME);\
   }\
   else {\
printf(\
"void %s::flush_all()\n"\
,IM_STRUCT_NAME);\
   }\
printf(\
"{/*{{{*/\n"\
);\
   if (TYPE_NUMBERS(0) & c_type_flushable) {\
printf(\
"   %s_node *ptr = data;\n"\
"   %s_node *ptr_end = ptr + used;\n"\
"\n"\
"   do {\n"\
"      ptr->object.flush_all();\n"\
"   } while(++ptr < ptr_end);\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   }\
printf(\
"   copy_resize(used);\n"\
);\
   if (VAR_NAMES_CNT > 0) {\
printf(\
"\n"\
);\
      t_idx = 0;\
      do {\
         if (TYPE_NUMBERS(t_idx + 1) & c_type_flushable) {\
printf(\
"   %s.flush_all();\n"\
,VAR_NAMES(t_idx));\
         }\
      } while(++t_idx < VAR_NAMES_CNT);\
   }\
printf(\
"}/*}}}*/\n"\
"\n"\
);\
}

#define SAFE_RB_TREE_SWAP() \
{\
printf(\
"inline void %s::swap(%s &a_second)\n"\
"{/*{{{*/\n"\
"   unsigned tmp_unsigned = size;\n"\
"   size = a_second.size;\n"\
"   a_second.size = tmp_unsigned;\n"\
"\n"\
"   tmp_unsigned = used;\n"\
"   used = a_second.used;\n"\
"   a_second.used = tmp_unsigned;\n"\
"\n"\
"   tmp_unsigned = count;\n"\
"   count = a_second.count;\n"\
"   a_second.count = tmp_unsigned;\n"\
"\n"\
"   %s_node *tmp_data = data;\n"\
"   data = a_second.data;\n"\
"   a_second.data = tmp_data;\n"\
"\n"\
"   tmp_unsigned = free_idx;\n"\
"   free_idx = a_second.free_idx;\n"\
"   a_second.free_idx = tmp_unsigned;\n"\
"\n"\
"   tmp_unsigned = root_idx;\n"\
"   root_idx = a_second.root_idx;\n"\
"   a_second.root_idx = tmp_unsigned;\n"\
"\n"\
"   tmp_unsigned = leaf_idx;\n"\
"   leaf_idx = a_second.leaf_idx;\n"\
"   a_second.leaf_idx = tmp_unsigned;\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   if (VAR_NAMES_CNT > 0) {\
      t_idx = 0;\
      do {\
printf(\
"\n"\
);\
         if (TYPE_NUMBERS(t_idx + 1) & c_type_basic) {\
printf(\
"   %s tmp_%s = %s;\n"\
"   %s = a_second.%s;\n"\
"   a_second.%s = tmp_%s;\n"\
,IM_TYPE_NAMES(t_idx + 1),VAR_NAMES(t_idx),VAR_NAMES(t_idx),VAR_NAMES(t_idx),VAR_NAMES(t_idx),VAR_NAMES(t_idx),VAR_NAMES(t_idx));\
         }\
         else {\
printf(\
"   %s.swap(a_second.%s);\n"\
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));\
         }\
      } while(++t_idx < VAR_NAMES_CNT);\
   }\
printf(\
"}/*}}}*/\n"\
"\n"\
);\
}

#define SAFE_RB_TREE_OPERATOR_LE_BR_RE_BR() \
{\
printf(\
"inline %s &%s::operator[](unsigned a_idx)\n"\
"{/*{{{*/\n"\
"   debug_assert(a_idx < used && data[a_idx].valid);\n"\
"   return data[a_idx].object;\n"\
"}/*}}}*/\n"\
"\n"\
,IM_TYPE_NAMES(0),IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE_INSERT() \
{\
   if (TYPE_NUMBERS(0) & c_type_basic) {\
printf(\
"inline unsigned %s::insert(%s a_value)\n"\
,IM_STRUCT_NAME,IM_TYPE_NAMES(0));\
   }\
   else {\
printf(\
"inline unsigned %s::insert(%s &a_value)\n"\
,IM_STRUCT_NAME,IM_TYPE_NAMES(0));\
   }\
printf(\
"{/*{{{*/\n"\
"   unsigned new_node_idx = __get_new_index();\n"\
"\n"\
"   __binary_tree_insert(new_node_idx,a_value,false);\n"\
"   __insert_operation(new_node_idx);\n"\
"\n"\
"   data[new_node_idx].object = a_value;\n"\
"\n"\
"   return new_node_idx;\n"\
"}/*}}}*/\n"\
"\n"\
);\
}

#define SAFE_RB_TREE_SWAP_INSERT() \
{\
   if (!(TYPE_NUMBERS(0) & c_type_basic)) {\
printf(\
"inline unsigned %s::swap_insert(%s &a_value)\n"\
"{/*{{{*/\n"\
"   unsigned new_node_idx = __get_new_index();\n"\
"\n"\
"   __binary_tree_insert(new_node_idx,a_value,false);\n"\
"   __insert_operation(new_node_idx);\n"\
"\n"\
"   data[new_node_idx].object.swap(a_value);\n"\
"\n"\
"   return new_node_idx;\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_TYPE_NAMES(0));\
   }\
}

#define SAFE_RB_TREE_REMOVE()  \
{\
printf(\
"void %s::remove(unsigned a_idx)\n"\
"{/*{{{*/\n"\
"   debug_assert(a_idx < used && data[a_idx].valid);\n"\
"\n"\
"   %s_node &del_node = data[a_idx];\n"\
"\n"\
"   if (del_node.left_idx != leaf_idx) {\n"\
"      if (del_node.right_idx != leaf_idx) {\n"\
"         \n"\
"         unsigned found_idx = del_node.right_idx;\n"\
"         do {\n"\
"            %s_node &node = data[found_idx];\n"\
"\n"\
"            if (node.left_idx == leaf_idx) {\n"\
"               break;\n"\
"            }\n"\
"\n"\
"            found_idx = node.left_idx;\n"\
"         } while(1);\n"\
"\n"\
"         %s_node &found_node = data[found_idx];\n"\
"\n"\
"         /* - process del_node parent_idx - */\n"\
"         if (del_node.parent_idx != c_idx_not_exist) {\n"\
"            %s_node &del_node_parent = data[del_node.parent_idx];\n"\
"            (del_node_parent.left_idx == a_idx?del_node_parent.left_idx:del_node_parent.right_idx) = found_idx;\n"\
"         }\n"\
"         else {\n"\
"            root_idx = found_idx;\n"\
"         }\n"\
"\n"\
"         /* - process del_node left_idx - */\n"\
"         data[del_node.left_idx].parent_idx = found_idx;\n"\
"\n"\
"         /* - process found_node right_idx - */\n"\
"         if (found_node.right_idx != leaf_idx) {\n"\
"            data[found_node.right_idx].parent_idx = a_idx;\n"\
"         }\n"\
"\n"\
"         if (del_node.right_idx == found_idx) {\n"\
"            \n"\
"            /* - found node is right child of deleted node - */\n"\
"            del_node.right_idx = found_node.right_idx;\n"\
"            found_node.right_idx = a_idx;\n"\
"\n"\
"            found_node.parent_idx = del_node.parent_idx;\n"\
"            del_node.parent_idx = found_idx;\n"\
"\n"\
"            found_node.left_idx = del_node.left_idx;\n"\
"            del_node.left_idx = leaf_idx;\n"\
"\n"\
"            bool tmp_bool = found_node.color;\n"\
"            found_node.color = del_node.color;\n"\
"            del_node.color = tmp_bool;\n"\
"         }\n"\
"         else {\n"\
"            \n"\
"            /* - process found_node parent - */\n"\
"            %s_node &found_node_parent = data[found_node.parent_idx];\n"\
"            (found_node_parent.left_idx == found_idx?found_node_parent.left_idx:found_node_parent.right_idx) = a_idx;\n"\
"\n"\
"            /* - process del_node right_idx - */\n"\
"            data[del_node.right_idx].parent_idx = found_idx;\n"\
"\n"\
"            /* - swap index pointers between nodes - */\n"\
"            unsigned tmp_unsigned = found_node.parent_idx;\n"\
"            found_node.parent_idx = del_node.parent_idx;\n"\
"            del_node.parent_idx = tmp_unsigned;\n"\
"\n"\
"            found_node.left_idx = del_node.left_idx;\n"\
"            del_node.left_idx = leaf_idx;\n"\
"\n"\
"            tmp_unsigned = found_node.right_idx;\n"\
"            found_node.right_idx = del_node.right_idx;\n"\
"            del_node.right_idx = tmp_unsigned;\n"\
"\n"\
"            bool tmp_bool = found_node.color;\n"\
"            found_node.color = del_node.color;\n"\
"            del_node.color = tmp_bool;\n"\
"         }\n"\
"\n"\
"         __remove_one_child(a_idx,del_node.right_idx);\n"\
"      }\n"\
"      else {\n"\
"         __remove_one_child(a_idx,del_node.left_idx);\n"\
"      }\n"\
"   }\n"\
"   else {\n"\
"      __remove_one_child(a_idx,del_node.right_idx);\n"\
"   }\n"\
"\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE_COPY_RESIZE() \
{\
printf(\
"void %s::copy_resize(unsigned a_size)\n"\
"{/*{{{*/\n"\
"   debug_assert(a_size >= used);\n"\
"\n"\
"   %s_node *n_data;\n"\
"\n"\
"   if (a_size == 0) {\n"\
"      n_data = NULL;\n"\
"   }\n"\
"   else {\n"\
"      n_data = (%s_node *)cmalloc(a_size*sizeof(%s_node));\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   if (TYPE_NUMBERS(0) & c_type_dynamic) {\
printf(\
"\n"\
"      if (a_size > used) {\n"\
"         %s_node *ptr = n_data + used;\n"\
"         %s_node *ptr_end = n_data + a_size;\n"\
"\n"\
"         do {\n"\
"            ptr->object.init();\n"\
"         } while(++ptr < ptr_end);\n"\
"      }\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   }\
printf(\
"   }\n"\
"\n"\
"   if (used != 0) {\n"\
"      memcpy(n_data,data,used*sizeof(%s_node));\n"\
"   }\n"\
,IM_STRUCT_NAME);\
   if (TYPE_NUMBERS(0) & c_type_dynamic) {\
printf(\
"\n"\
"   if (size > used) {\n"\
"      %s_node *ptr = data + used;\n"\
"      %s_node *ptr_end = data + size;\n"\
"\n"\
"      do {\n"\
"         ptr->object.clear();\n"\
"      } while(++ptr < ptr_end);\n"\
"   }\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   }\
printf(\
"\n"\
"   if (size != 0) {\n"\
"      cfree(data);\n"\
"   }\n"\
"\n"\
"   data = n_data;\n"\
"   size = a_size;\n"\
"}/*}}}*/\n"\
"\n"\
);\
}

#define SAFE_RB_TREE_GET_IDX() \
{\
   if (TYPE_NUMBERS(0) & c_type_basic) {\
printf(\
"unsigned %s::get_idx(%s a_value)\n"\
,IM_STRUCT_NAME,IM_TYPE_NAMES(0));\
   }\
   else {\
printf(\
"unsigned %s::get_idx(%s &a_value)\n"\
,IM_STRUCT_NAME,IM_TYPE_NAMES(0));\
   }\
printf(\
"{/*{{{*/\n"\
"   if (root_idx == c_idx_not_exist) {\n"\
"      return c_idx_not_exist;\n"\
"   }\n"\
"\n"\
"   unsigned node_idx = root_idx;\n"\
"   do {\n"\
"      %s_node &node = data[node_idx];\n"\
"\n"\
"      int comp_result = __compare_value(a_value,node.object);\n"\
"      if (comp_result < 0) {\n"\
"         node_idx = node.left_idx;\n"\
"      }\n"\
"      else {\n"\
"         if (comp_result == 0) {\n"\
"            return node_idx;\n"\
"         }\n"\
"\n"\
"         node_idx = node.right_idx;\n"\
"      }\n"\
"   } while(node_idx != leaf_idx);\n"\
"\n"\
"   return c_idx_not_exist;\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE_GET_IDX_LEFT() \
{\
   if (TYPE_NUMBERS(0) & c_type_basic) {\
printf(\
"unsigned %s::get_idx_left(%s a_value)\n"\
,IM_STRUCT_NAME,IM_TYPE_NAMES(0));\
   }\
   else {\
printf(\
"unsigned %s::get_idx_left(%s &a_value)\n"\
,IM_STRUCT_NAME,IM_TYPE_NAMES(0));\
   }\
printf(\
"{/*{{{*/\n"\
"   if (root_idx == c_idx_not_exist) {\n"\
"      return c_idx_not_exist;\n"\
"   }\n"\
"\n"\
"   unsigned good_idx = c_idx_not_exist;\n"\
"   unsigned node_idx = root_idx;\n"\
"   do {\n"\
"      %s_node &node = data[node_idx];\n"\
"\n"\
"      int comp_result = __compare_value(a_value,node.object);\n"\
"      if (comp_result < 0) {\n"\
"         node_idx = node.left_idx;\n"\
"      }\n"\
"      else {\n"\
"         if (comp_result == 0) {\n"\
"            good_idx = node_idx;\n"\
"            node_idx = node.left_idx;\n"\
"         }\n"\
"         else {\n"\
"            node_idx = node.right_idx;\n"\
"         }\n"\
"      }\n"\
"   } while(node_idx != leaf_idx);\n"\
"\n"\
"   return good_idx;\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE_GET_GRE_IDX() \
{\
   if (TYPE_NUMBERS(0) & c_type_basic) {\
printf(\
"unsigned %s::get_gre_idx(%s a_value)\n"\
,IM_STRUCT_NAME,IM_TYPE_NAMES(0));\
   }\
   else {\
printf(\
"unsigned %s::get_gre_idx(%s &a_value)\n"\
,IM_STRUCT_NAME,IM_TYPE_NAMES(0));\
   }\
printf(\
"{/*{{{*/\n"\
"   if (root_idx == c_idx_not_exist) {\n"\
"      return c_idx_not_exist;\n"\
"   }\n"\
"\n"\
"   unsigned good_idx = c_idx_not_exist;\n"\
"   unsigned node_idx = root_idx;\n"\
"   do {\n"\
"      %s_node &node = data[node_idx];\n"\
"\n"\
"      int comp_result = __compare_value(a_value,node.object);\n"\
"      if (comp_result < 0) {\n"\
"         good_idx = node_idx;\n"\
"         node_idx = node.left_idx;\n"\
"      }\n"\
"      else {\n"\
"         if (comp_result == 0) {\n"\
"            return node_idx;\n"\
"         }\n"\
"\n"\
"         node_idx = node.right_idx;\n"\
"      }\n"\
"   } while(node_idx != leaf_idx);\n"\
"\n"\
"   return good_idx;\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE_GET_LEE_IDX() \
{\
   if (TYPE_NUMBERS(0) & c_type_basic) {\
printf(\
"unsigned %s::get_lee_idx(%s a_value)\n"\
,IM_STRUCT_NAME,IM_TYPE_NAMES(0));\
   }\
   else {\
printf(\
"unsigned %s::get_lee_idx(%s &a_value)\n"\
,IM_STRUCT_NAME,IM_TYPE_NAMES(0));\
   }\
printf(\
"{/*{{{*/\n"\
"   if (root_idx == c_idx_not_exist) {\n"\
"      return c_idx_not_exist;\n"\
"   }\n"\
"\n"\
"   unsigned good_idx = c_idx_not_exist;\n"\
"   unsigned node_idx = root_idx;\n"\
"   do {\n"\
"      %s_node &node = data[node_idx];\n"\
"\n"\
"      int comp_result = __compare_value(a_value,node.object);\n"\
"      if (comp_result < 0) {\n"\
"         node_idx = node.left_idx;\n"\
"      }\n"\
"      else {\n"\
"         if (comp_result == 0) {\n"\
"            return node_idx;\n"\
"         }\n"\
"\n"\
"         good_idx = node_idx;\n"\
"         node_idx = node.right_idx;\n"\
"      }\n"\
"   } while(node_idx != leaf_idx);\n"\
"\n"\
"   return good_idx;\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE_GET_IDXS() \
{\
   if (TYPE_NUMBERS(0) & c_type_basic) {\
printf(\
"void %s::get_idxs(%s a_value,ui_array_s &a_idxs_array)\n"\
,IM_STRUCT_NAME,IM_TYPE_NAMES(0));\
   }\
   else {\
printf(\
"void %s::get_idxs(%s &a_value,ui_array_s &a_idxs_array)\n"\
,IM_STRUCT_NAME,IM_TYPE_NAMES(0));\
   }\
printf(\
"{/*{{{*/\n"\
"   a_idxs_array.used = 0;\n"\
"\n"\
"   if (root_idx == c_idx_not_exist) {\n"\
"      return;\n"\
"   }\n"\
"\n"\
"   unsigned stack[get_descent_stack_size()];\n"\
"   unsigned *stack_ptr = stack;\n"\
"\n"\
"   *(stack_ptr++) = root_idx;\n"\
"   do {\n"\
"      unsigned node_idx = *(--stack_ptr);\n"\
"      %s_node &node = data[node_idx];\n"\
"\n"\
"      int comp_result = __compare_value(a_value,node.object);\n"\
"      if (comp_result < 0) {\n"\
"         if (node.left_idx != leaf_idx) {\n"\
"            *(stack_ptr++) = node.left_idx;\n"\
"         }\n"\
"      }\n"\
"      else {\n"\
"         if (comp_result == 0) {\n"\
"            a_idxs_array.push(node_idx);\n"\
"\n"\
"            if (node.left_idx != leaf_idx) {\n"\
"               *(stack_ptr++) = node.left_idx;\n"\
"            }\n"\
"         }\n"\
"\n"\
"         if (node.right_idx != leaf_idx) {\n"\
"            *(stack_ptr++) = node.right_idx;\n"\
"         }\n"\
"      }\n"\
"   } while(stack_ptr > stack);\n"\
"\n"\
"   return;\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE_OPERATOR_EQUAL() \
{\
   if (TYPE_NUMBERS(0) & c_type_dynamic) {\
printf(\
"%s &%s::operator=(%s &a_src)\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   }\
   else {\
printf(\
"inline %s &%s::operator=(%s &a_src)\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   }\
printf(\
"{/*{{{*/\n"\
"   clear();\n"\
"\n"\
"   if (a_src.root_idx == c_idx_not_exist) return *this;\n"\
"\n"\
"   copy_resize(a_src.used);\n"\
);\
   if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {\
printf(\
"   memcpy(data,a_src.data,a_src.used*sizeof(%s_node));\n"\
,IM_STRUCT_NAME);\
   }\
   else \
   {\
printf(\
"\n"\
"   %s_node *ptr = data;\n"\
"   %s_node *s_ptr = a_src.data;\n"\
"   %s_node *s_ptr_end = s_ptr + a_src.used;\n"\
"\n"\
"   do {\n"\
"      ptr->object = s_ptr->object;\n"\
"      ptr->valid = s_ptr->valid;\n"\
"      ptr->parent_idx = s_ptr->parent_idx;\n"\
"      ptr->left_idx = s_ptr->left_idx;\n"\
"      ptr->right_idx = s_ptr->right_idx;\n"\
"      ptr->color = s_ptr->color;\n"\
"   } while(++ptr,++s_ptr < s_ptr_end);\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   }\
printf(\
"\n"\
"   used = a_src.used;\n"\
"   count = a_src.count;\n"\
"   free_idx = a_src.free_idx;\n"\
"   root_idx = a_src.root_idx;\n"\
"   leaf_idx = a_src.leaf_idx;\n"\
);\
   if (VAR_NAMES_CNT > 0) {\
printf(\
"\n"\
);\
      t_idx = 0;\
      do {\
printf(\
"   %s = a_src.%s;\n"\
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));\
      } while(++t_idx < VAR_NAMES_CNT);\
   }\
printf(\
"\n"\
"   return *this;\n"\
"}/*}}}*/\n"\
"\n"\
);\
}

#define SAFE_RB_TREE_OPERATOR_DOUBLE_EQUAL() \
{\
printf(\
"bool %s::operator==(%s &a_second)\n"\
"{/*{{{*/\n"\
"   if (count != a_second.count) {\n"\
"     return false;\n"\
"   }\n"\
"\n"\
"   if (root_idx == c_idx_not_exist) {\n"\
"      if (a_second.root_idx != c_idx_not_exist) {\n"\
"         return false;\n"\
"      }\n"\
"   }\n"\
"   else {\n"\
"      if (a_second.root_idx == c_idx_not_exist) {\n"\
"         return false;\n"\
"      }\n"\
"\n"\
"      unsigned stack[get_descent_stack_size()];\n"\
"      unsigned s_stack[a_second.get_descent_stack_size()];\n"\
"\n"\
"      unsigned *stack_ptr = stack;\n"\
"      unsigned *s_stack_ptr = s_stack;\n"\
"\n"\
"      unsigned node_idx = get_stack_min_value_idx(root_idx,&stack_ptr);\n"\
"      unsigned s_node_idx = a_second.get_stack_min_value_idx(a_second.root_idx,&s_stack_ptr);\n"\
"      do {\n"\
"         if (!(data[node_idx].object == a_second.data[s_node_idx].object)) {\n"\
"            return false;\n"\
"         }\n"\
"\n"\
"         node_idx = get_stack_next_idx(node_idx,&stack_ptr,stack);\n"\
"         s_node_idx = a_second.get_stack_next_idx(s_node_idx,&s_stack_ptr,s_stack);\n"\
"      } while(node_idx != c_idx_not_exist && s_node_idx != c_idx_not_exist);\n"\
"\n"\
"      if (node_idx != s_node_idx) {\n"\
"         return false;\n"\
"      }\n"\
"   }\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME);\
   if (VAR_NAMES_CNT > 0) {\
printf(\
"   return (%s == a_second.%s"\
,VAR_NAMES(0),VAR_NAMES(0));\
      if (VAR_NAMES_CNT > 1) {\
         t_idx = 1;\
         do {\
printf(\
" && %s == a_second.%s"\
,VAR_NAMES(t_idx),VAR_NAMES(t_idx));\
         } while(++t_idx < VAR_NAMES_CNT);\
      }\
printf(\
");\n"\
);\
   }\
   else {\
printf(\
"   return true;\n"\
);\
   }\
printf(\
"}/*}}}*/\n"\
"\n"\
);\
}

#define SAFE_RB_TREE_REHASH_TREE() \
{\
printf(\
"void %s::rehash_tree()\n"\
"{/*{{{*/\n"\
"   if (root_idx == c_idx_not_exist) return;\n"\
"\n"\
"   ui_array_s indexes;\n"\
"   indexes.init();\n"\
"\n"\
"   {\n"\
"      unsigned stack[get_descent_stack_size()];\n"\
"      unsigned *stack_ptr = stack;\n"\
"\n"\
"      unsigned idx = get_stack_min_value_idx(root_idx,&stack_ptr);\n"\
"      do {\n"\
"         indexes.push(idx);\n"\
"\n"\
"         idx = get_stack_next_idx(idx,&stack_ptr,stack);\n"\
"      } while(idx != c_idx_not_exist);\n"\
"   }\n"\
"\n"\
"   root_idx = c_idx_not_exist;\n"\
"\n"\
"   bool *processed = (bool *)cmalloc(indexes.used*sizeof(bool));\n"\
"   memset(processed,false,indexes.used*sizeof(bool));\n"\
"\n"\
"   unsigned step = indexes.used >> 1;\n"\
"   if (step > 0) {\n"\
"      do {\n"\
"         unsigned idx = step;\n"\
"         do {\n"\
"            if (!processed[idx]) {\n"\
"               unsigned node_idx = indexes[idx];\n"\
"\n"\
"               __binary_tree_insert(node_idx,data[node_idx].object,false);\n"\
"               __insert_operation(node_idx);\n"\
"\n"\
"               processed[idx] = true;\n"\
"            }\n"\
"         } while((idx += step) < indexes.used);\n"\
"      } while((step >>= 1) > 0);\n"\
"   }\n"\
"\n"\
"   unsigned node_idx = indexes[0];\n"\
"   __binary_tree_insert(node_idx,data[node_idx].object,false);\n"\
"   __insert_operation(node_idx);\n"\
"\n"\
"   cfree(processed);\n"\
"   indexes.clear();\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE_PRINT_DOT_CODE() \
{\
printf(\
"void %s::print_dot_code(FILE *a_file)\n"\
"{/*{{{*/\n"\
"   fprintf(a_file,\n"\
"\"digraph G {\\n\"\n"\
"\"   rankdir = TD\\n\"\n"\
"\"   node [ shape = circle margin = 0.0 fixedsize = true width = 0.7 height = 0.7]\\n\"\n"\
"\"\\n\"\n"\
"   );\n"\
"\n"\
"   const char *node_colors[] = {\n"\
"      \"red\",\n"\
"      \"black\",\n"\
"   };\n"\
"\n"\
"   fprintf(a_file,\n"\
"\"   root_idx [label = \\\"R\\\" ]\\n\"\n"\
"\"   root_idx -> node_%%u\\n\"\n"\
"   ,root_idx);\n"\
"\n"\
"   if (root_idx != c_idx_not_exist) {\n"\
"      ui_array_s stack;\n"\
"      stack.init();\n"\
"\n"\
"      stack.push(root_idx);\n"\
"      do {\n"\
"         unsigned node_idx = stack.pop();\n"\
"         %s_node &node = data[node_idx];\n"\
"\n"\
"         /* - print node - */\n"\
"         fprintf(a_file,\n"\
"\"   node_%%u [ color = \\\"%%s\\\" label = \\\"%%u\\\" ]\\n\"\n"\
"         ,node_idx,node_colors[node.color],node_idx);\n"\
"\n"\
"         if (node.parent_idx != c_idx_not_exist) {\n"\
"            fprintf(a_file,\n"\
"\"   node_%%u -> node_%%u [ color = green ] \\n\"\n"\
"            ,node_idx,node.parent_idx);\n"\
"         }\n"\
"\n"\
"         if (node.left_idx != leaf_idx) {\n"\
"            fprintf(a_file,\n"\
"\"   node_%%u -> node_%%u [ label = \\\"L\\\" ]\\n\"\n"\
"            ,node_idx,node.left_idx);\n"\
"\n"\
"            stack.push(node.left_idx);\n"\
"         }\n"\
"\n"\
"         if (node.right_idx != leaf_idx) {\n"\
"            fprintf(a_file,\n"\
"\"   node_%%u -> node_%%u [ label = \\\"R\\\" ]\\n\"\n"\
"            ,node_idx,node.right_idx);\n"\
"\n"\
"            stack.push(node.right_idx);\n"\
"         }\n"\
"      } while(stack.used > 0);\n"\
"\n"\
"      stack.clear();\n"\
"   }\n"\
"\n"\
"   fprintf(a_file,\n"\
"\"}\\n\"\n"\
"\"\\n\");\n"\
"\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

#define SAFE_RB_TREE_CHECK_RB_TREE_PROPERTIES() \
{\
printf(\
"bool %s::check_rb_tree_properties()\n"\
"{/*{{{*/\n"\
"   %s_node &leaf = data[leaf_idx];\n"\
"   if (!leaf.color) {\n"\
"      fprintf(stderr,\"ERROR: leaf_node color\\n\");\n"\
"      return false;\n"\
"   }\n"\
"\n"\
"   if (leaf.left_idx != c_idx_not_exist || leaf.right_idx != c_idx_not_exist) {\n"\
"      fprintf(stderr,\"ERROR: leaf_node indexes (INFO: is allowed setting in mt_automaton code?)\\n\");\n"\
"      return false;\n"\
"   }\n"\
"\n"\
"   if (root_idx != c_idx_not_exist) {\n"\
"      \n"\
"      /* - check if root node is black - */\n"\
"      %s_node &r_node = data[root_idx];\n"\
"      if (!r_node.color) {\n"\
"         fprintf(stderr,\"ERROR: root node is not black\\n\");\n"\
"         return false;\n"\
"      }\n"\
"\n"\
"      /* - create node index and path length stacks - */\n"\
"      ui_array_s ni_stack;\n"\
"      ui_array_s pl_stack;\n"\
"\n"\
"      ni_stack.init();\n"\
"      pl_stack.init();\n"\
"\n"\
"      /* - insert root on stack - */\n"\
"      ni_stack.push(root_idx);\n"\
"      pl_stack.push(0);\n"\
"\n"\
"      unsigned r_path_length = c_idx_not_exist;\n"\
"      do {\n"\
"         unsigned node_idx = ni_stack.pop();\n"\
"         unsigned path_length = pl_stack.pop();\n"\
"         unsigned stack_depth = ni_stack.used;\n"\
"\n"\
"         %s_node &node = data[node_idx];\n"\
"\n"\
"         if (node.color) {\n"\
"            path_length++;\n"\
"         }\n"\
"         else {\n"\
"            if (node.left_idx == c_idx_not_exist || node.right_idx == c_idx_not_exist) {\n"\
"               fprintf(stderr,\"ERROR: red node has not two childs!\\n\");\n"\
"               ni_stack.clear();\n"\
"               pl_stack.clear();\n"\
"               return false;\n"\
"            }\n"\
"\n"\
"            if (!data[node.left_idx].color || !data[node.right_idx].color) {\n"\
"               fprintf(stderr,\"ERROR: child of red node is not black!\\n\");\n"\
"               ni_stack.clear();\n"\
"               pl_stack.clear();\n"\
"               return false;\n"\
"            }\n"\
"         }\n"\
"\n"\
"         if (node.left_idx != c_idx_not_exist) {\n"\
"            ni_stack.push(node.left_idx);\n"\
"            pl_stack.push(path_length);\n"\
"         }\n"\
"\n"\
"         if (node.right_idx != c_idx_not_exist) {\n"\
"            ni_stack.push(node.right_idx);\n"\
"            pl_stack.push(path_length);\n"\
"         }\n"\
"\n"\
"         /* - if node is leaf node - */\n"\
"         if (stack_depth == ni_stack.used) {\n"\
"            if (r_path_length != c_idx_not_exist) {\n"\
"               if (r_path_length != path_length) {\n"\
"                  fprintf(stderr,\"ERROR: all path have no same length!\\n\");\n"\
"                  ni_stack.clear();\n"\
"                  pl_stack.clear();\n"\
"                  return false;\n"\
"               }\n"\
"            }\n"\
"            else {\n"\
"               r_path_length = path_length;\n"\
"            }\n"\
"         }\n"\
"\n"\
"      } while(ni_stack.used > 0);\n"\
"\n"\
"      ni_stack.clear();\n"\
"      pl_stack.clear();\n"\
"   }\n"\
"\n"\
"   /* - test if are node values sorted - */\n"\
"   if (root_idx != c_idx_not_exist) {\n"\
"      unsigned stack[get_descent_stack_size()];\n"\
"      unsigned *stack_ptr = stack;\n"\
"\n"\
"      unsigned idx = get_stack_min_value_idx(root_idx,&stack_ptr);\n"\
"      do {\n"\
"         unsigned l_idx = idx;\n"\
"         idx = get_stack_next_idx(idx,&stack_ptr,stack);\n"\
"         if (idx == c_idx_not_exist) {\n"\
"            break;\n"\
"         }\n"\
"         if (__compare_value(data[l_idx].object,data[idx].object) == 1) {\n"\
"            fprintf(stderr,\"ERROR: values in rb_tree are not sorted\\n\");\n"\
"            return false;\n"\
"         }\n"\
"      } while(1);\n"\
"   }\n"\
"\n"\
"   return true;\n"\
"}/*}}}*/\n"\
"\n"\
,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME,IM_STRUCT_NAME);\
}

void processor_s::generate_safe_rb_tree_type()
{
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
   unsigned type_idxs[type_cnt];
   data_type_s *types[type_cnt];

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
         if (data_types[type_idx].properties & c_type_setting_strict_dynamic) {
            fprintf(stderr,"rb_tree: container have not implemented processing of types with option strict_dynamic\n");
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

      data_type_name_len += strlen(c_cont_postfixes[c_cont_safe_rb_tree]) - 1;
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

      memcpy(--dtn_ptr,c_cont_postfixes[c_cont_safe_rb_tree],strlen(c_cont_postfixes[c_cont_safe_rb_tree]));
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

      data_type.cont_idx = c_cont_safe_rb_tree;
      data_type.name.set(data_type_name.size - 1,data_type_name.data);
      data_type.real_name.swap(real_name);

      // - retrieve of types pointers -
      {
         unsigned tn_idx = 0;
         do {
            types[tn_idx] = &data_types[type_idxs[tn_idx]];
         } while(++tn_idx < type_cnt);
      }

      data_type.properties = c_type_dynamic | c_type_flushable  | (type_settings & c_type_setting_mask);

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

   // - definition of structure rb_tree -

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
#ifdef SAFE_RB_TREE_GENERATE_CHECK_RB_TREE_PROPERTIES
"#ifndef SAFE_RB_TREE_SET_LEAF_CHILDS\n"
"#define SAFE_RB_TREE_SET_LEAF_CHILDS\n"
"#endif\n"
"\n"
#endif
"/*!\n"
" * \\brief __GEN node of rb_tree of type %s\n"
" */\n"
"\n"
"struct %s_node\n"
"{\n"
"   %s object;\n"
"   bool valid;\n"
"   unsigned parent_idx;\n"
"   unsigned left_idx;\n"
"   unsigned right_idx;\n"
"   bool color;\n"
"};\n"
"\n"
"/*!\n"
" * \\brief __GEN rb_tree of type %s\n"
" */\n"
"struct %s\n"
"{\n"
"   unsigned size;\n"
"   unsigned used;\n"
"   unsigned count;\n"
"   %s_node *data;\n"
"   unsigned free_idx;\n"
"   unsigned root_idx;\n"
"   unsigned leaf_idx;\n"
,IM_TYPE_NAMES(0),STRUCT_NAME,IM_TYPE_NAMES(0),IM_TYPE_NAMES(0),STRUCT_NAME,STRUCT_NAME);
   if (VAR_NAMES_CNT > 0) {
      unsigned t_idx = 0;
      do {
printf(
"   %s %s; //!< member - %u\n"
,TYPE_NAMES(t_idx + 1),VAR_NAMES(t_idx),t_idx);
      } while(++t_idx < VAR_NAMES_CNT);
   }
printf(
"\n"
"   // - internal support methods -\n"
"   inline unsigned __get_grandparent_idx(unsigned a_idx);\n"
"   inline unsigned __get_uncle_idx(unsigned a_idx);\n"
"   inline unsigned __get_sibling_idx(unsigned a_idx);\n"
"\n"
"   inline unsigned get_descent_stack_size();\n"
"   unsigned get_stack_min_value_idx(unsigned a_idx,unsigned **a_s_ptr);\n"
"   inline unsigned get_stack_next_idx(unsigned a_idx,unsigned **a_s_ptr,unsigned *a_stack_base);\n"
"\n"
"   unsigned get_min_value_idx(unsigned a_idx);\n"
"   unsigned get_max_value_idx(unsigned a_idx);\n"
"   unsigned get_next_idx(unsigned a_idx);\n"
"   unsigned get_prev_idx(unsigned a_idx);\n"
"\n"
"   inline void __rotate_left(unsigned a_idx);\n"
"   inline void __rotate_right(unsigned a_idx);\n"
"\n"
"   inline unsigned __get_new_index();\n"
"   bool __binary_tree_insert(unsigned a_new_idx,%s &a_value,bool a_unique);\n"
"\n"
"   inline void __replace_delete_node_by_child(unsigned a_idx,unsigned a_ch_idx);\n"
"   void __remove_black_black(unsigned a_idx);\n"
"\n"
"   inline void __remove_one_child(unsigned a_idx,unsigned a_ch_idx);\n"
"\n"
"   void __insert_operation(unsigned a_idx);\n"
"\n"
"   inline int __compare_value(%s &a_first,%s &a_second);\n"
"\n"
,IM_TYPE_NAMES(0),IM_TYPE_NAMES(0),IM_TYPE_NAMES(0));
   if (!(data_type.properties & c_type_setting_not_generate_init)) {
printf(
"   /*!\n"
"    * \\brief __GEN initialize rb_tree\n"
"    */\n"
"   inline void init();\n"
"\n"
);
   }
   if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
      if (!(data_type.properties & c_type_setting_not_generate_clear)) {
printf(
"   /*!\n"
"    * \\brief __GEN release memory used by rb_tree\n"
"    */\n"
"   inline void clear();\n"
"\n"
);
      }
   }
   else {
      if (!(data_type.properties & c_type_setting_not_generate_clear)) {
printf(
"   /*!\n"
"    * \\brief __GEN release memory used by rb_tree\n"
"    */\n"
"   void clear();\n"
"\n"
);
      }
   }
printf(
"   /*!\n"
"    * \\brief __GEN flush rb_tree memory usage\n"
"    */\n"
"   inline void flush();\n"
"\n"
);
   if (!(TYPE_NUMBERS(0) & c_type_flushable)) {
printf(
"   /*!\n"
"    * \\brief __GEN flush rb_tree memory usage, recursive on nodes\n"
"    */\n"
"   inline void flush_all();\n"
"\n"
);
   }
   else {
printf(
"   /*!\n"
"    * \\brief __GEN flush rb_tree memory usage, recursive on nodes\n"
"    */\n"
"   void flush_all();\n"
"\n"
);
   }
   if (!(data_type.properties & c_type_setting_not_generate_swap)) {
printf(
"   /*!\n"
"    * \\brief __GEN swap members of rb_tree with another rb_tree\n"
"    * \\param a_second - reference to another rb_tree\n"
"    */\n"
"   inline void swap(%s &a_second);\n"
"\n"
,STRUCT_NAME);
   }
printf(
"   /*!\n"
"    * \\brief __GEN select ode of rb_tree\n"
"    * \\param a_idx - index of node in rb_tree\n"
"    * \\return reference to node of rb_tree\n"
"    */\n"
"   inline %s &operator[](unsigned a_idx);\n"
"\n"
,IM_TYPE_NAMES(0));
   if (TYPE_NUMBERS(0) & c_type_basic) {
printf(
"   /*!\n"
"    * \\brief __GEN insert node to rb_tree\n"
"    * \\param a_value - value inserted to rb_tree\n"
"    * \\return - position of node in rb_tree\n"
"    */\n"
"   inline unsigned insert(%s a_value);\n"
"\n"
,IM_TYPE_NAMES(0));
   }
   else {
printf(
"   /*!\n"
"    * \\brief __GEN insert node to rb_tree\n"
"    * \\param a_value - reference to value inserted to rb_tree\n"
"    * \\return - position of node in rb_tree\n"
"    */\n"
"   inline unsigned insert(%s &a_value);\n"
"\n"
,IM_TYPE_NAMES(0));
   }
   if (!(TYPE_NUMBERS(0) & c_type_basic)) {
printf(
"   /*!\n"
"    * \\brief __GEN insert node to rb_tree by swapping\n"
"    * \\param a_value - reference to value inserted to rb_tree\n"
"    * \\return - position of node in rb_tree\n"
"    */\n"
"   inline unsigned swap_insert(%s &a_value);\n"
,IM_TYPE_NAMES(0));
   }
printf(
"   /*!\n"
"    * \\brief __GEN remove node at index from rb_tree\n"
"    * \\param a_idx - index of node to remove\n"
"    */\n"
"   void remove(unsigned a_idx);\n"
"\n"
"   /*!\n"
"    * \\brief __GEN resize rb_tree capacity\n"
"    * \\param a_size - desired rb_tree capacity\n"
"    */\n"
"   void copy_resize(unsigned a_size);\n"
"\n"
);
   if (TYPE_NUMBERS(0) & c_type_basic) {
printf(
"   /*!\n"
"    * \\brief __GEN search for index of node\n"
"    * \\param a_value - value which index is searched\n"
"    */\n"
"   unsigned get_idx(%s a_value);\n"
"\n"
"   /*!\n"
"    * \\brief __GEN search for leftmost index of node\n"
"    * \\param a_value - value which index is searched\n"
"    */\n"
"   unsigned get_idx_left(%s a_value);\n"
"\n"
"   /*!\n"
"    * \\brief __GEN search for index of node with greater or equal value\n"
"    * \\param a_value - value which index is searched\n"
"    */\n"
"   unsigned get_gre_idx(%s a_value);\n"
"\n"
"   /*!\n"
"    * \\brief __GEN search for index of node with less or equal value\n"
"    * \\param a_value - value which index is searched\n"
"    */\n"
"   unsigned get_lee_idx(%s a_value);\n"
"\n"
,IM_TYPE_NAMES(0),IM_TYPE_NAMES(0),IM_TYPE_NAMES(0),IM_TYPE_NAMES(0));
   }
   else {
printf(
"   /*!\n"
"    * \\brief __GEN search for index of node\n"
"    * \\param a_value - value which index is searched\n"
"    */\n"
"   unsigned get_idx(%s &a_value);\n"
"\n"
"   /*!\n"
"    * \\brief __GEN search for leftmost index of node\n"
"    * \\param a_value - value which index is searched\n"
"    */\n"
"   unsigned get_idx_left(%s &a_value);\n"
"\n"
"   /*!\n"
"    * \\brief __GEN search for index of node with greater or equal value\n"
"    * \\param a_value - value which index is searched\n"
"    */\n"
"   unsigned get_gre_idx(%s &a_value);\n"
"\n"
"   /*!\n"
"    * \\brief __GEN search for index of node with less or equal value\n"
"    * \\param a_value - value which index is searched\n"
"    */\n"
"   unsigned get_lee_idx(%s &a_value);\n"
"\n"
,IM_TYPE_NAMES(0),IM_TYPE_NAMES(0),IM_TYPE_NAMES(0),IM_TYPE_NAMES(0));
   }
   if (TYPE_NUMBERS(0) & c_type_basic) {
printf(
"   /*!\n"
"    * \\brief __GEN search for all indexes of node\n"
"    * \\param a_value - value of searched index\n"
"    */\n"
"   void get_idxs(%s a_value,ui_array_s &a_idxs_array);\n"
"\n"
,IM_TYPE_NAMES(0));
   }
   else {
printf(
"   /*!\n"
"    * \\brief __GEN search for all indexes of node\n"
"    * \\param a_value - value of searched index\n"
"    */\n"
"   void get_idxs(%s &a_value,ui_array_s &a_idxs_array);\n"
"\n"
,IM_TYPE_NAMES(0));
   }
   if (!(data_type.properties & c_type_setting_not_generate_operator_equal)) {
      if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
printf(
"   /*!\n"
"    * \\brief __GEN copy rb_tree from another rb_tree\n"
"    * \\param a_src - reference to another rb_tree\n"
"    * \\return reference to this rb_tree\n"
"    */\n"
"   inline %s &operator=(%s &a_src);\n"
"\n"
,STRUCT_NAME,STRUCT_NAME);
      }
      else {
printf(
"   /*!\n"
"    * \\brief __GEN copy rb_tree from another rb_tree\n"
"    * \\param a_src - reference to another rb_tree\n"
"    * \\return reference to this rb_tree\n"
"    */\n"
"   %s &operator=(%s &a_src);\n"
"\n"
,STRUCT_NAME,STRUCT_NAME);
      }
   }
printf(
"   /*!\n"
"    * \\brief __GEN compare rb_tree with another rb_tree\n"
"    * \\param a_second - reference to another rb_tree\n"
"    * \\return result of comparision\n"
"    */\n"
"   bool operator==(%s &a_second);\n"
"\n"
,STRUCT_NAME);
printf(
"   /*!\n"
"    * \\brief __GEN rehash tree (after invalidation by change of object value)\n"
"    */\n"
"    void rehash_tree();\n"
"\n"
);
#ifdef SAFE_RB_TREE_GENERATE_PRINT_DOT_CODE
printf(
"   /*\n"
"    * \\brief __GEN print dot code of rb_tree (for debugging)\n"
"    * \\param a_file - file to which is code writed\n"
"    */\n"
"    void print_dot_code(FILE *a_file);\n"
"\n"
);
#endif
#ifdef SAFE_RB_TREE_GENERATE_CHECK_RB_TREE_PROPERTIES
printf(
"   /*\n"
"    * \\brief __GEN test properties of red black tree\n"
"    * \\return true if all red black tree properties are valid\n"
"    */\n"
"    bool check_rb_tree_properties();\n"
"\n"
);
#endif
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
}

void processor_s::generate_safe_rb_tree_inlines(unsigned abb_idx,unsigned a_dt_idx)
{
   data_type_s &data_type = data_types[a_dt_idx];

   unsigned type_cnt = data_type.types.used;
   unsigned type_idxs[type_cnt];
   data_type_s *types[type_cnt];

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

   unsigned t_idx;

   // --- definition of inline methods ---

printf(
"// --- struct %s inline method definition ---\n"
"\n"
,IM_STRUCT_NAME);

   // - rb_tree __get_grandparent_idx method -
SAFE_RB_TREE___GET_GRANDPARENT_IDX();

   // - rb_tree __get_uncle_idx method -
SAFE_RB_TREE___GET_UNCLE_IDX();

   // - rb_tree __get_sibling_idx method -
SAFE_RB_TREE___GET_SIBLING_IDX();

   // - rb_tree get_descent_stack_size -
SAFE_RB_TREE_GET_DESCENT_STACK_SIZE();

   // - rb_tree get_stack_min_value_idx method -

   // - rb_tree get_stack_next_idx method -
SAFE_RB_TREE_GET_STACK_NEXT_IDX();

   // - rb_tree get_min_value_idx method -

   // - rb_tree get_max_value_idx method -

   // - rb_tree get_next_idx method -

   // - rb_tree get_prev_idx method -

   // - rb_tree __rotate_left method -
SAFE_RB_TREE___ROTATE_LEFT();

   // - rb_tree __rotate_right method -
SAFE_RB_TREE___ROTATE_RIGHT();

   // - rb_tree __get_new_index method -
SAFE_RB_TREE___GET_NEW_INDEX();

   // - rb_tree __binary_tree_insert method -

   // - rb_tree __replace_delete_node_by_child method -
SAFE_RB_TREE___REPLACE_DELETE_NODE_BY_CHILD();

   // - rb_tree __remove_black_black method -

   // - rb_tree __remove_one_child method -
SAFE_RB_TREE___REMOVE_ONE_CHILD();

   // - rb_tree __insert_operation method -

   // - rb_tree init method -
SAFE_RB_TREE_INIT();

   // - rb_tree clear method -
   if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
      if (!(data_type.properties & c_type_setting_not_generate_clear)) {
SAFE_RB_TREE_CLEAR();
      }
   }

   // - rb_tree flush method -
SAFE_RB_TREE_FLUSH();

   // - rb_tree flush_all method -
   if (!(TYPE_NUMBERS(0) & c_type_flushable)) {
SAFE_RB_TREE_FLUSH_ALL();
   }

   // - rb_tree swap method -
   if (!(data_type.properties & c_type_setting_not_generate_swap)) {
SAFE_RB_TREE_SWAP();
   }

   // - rb_tree operator[] method -
SAFE_RB_TREE_OPERATOR_LE_BR_RE_BR();

   // - rb_tree insert method -
SAFE_RB_TREE_INSERT();

   // - rb_tree swap_insert method -
SAFE_RB_TREE_SWAP_INSERT();

   // - rb_tree remove method -

   // - rb_tree copy_resize method -

   // - rb_tree get_idx method -

   // - rb_tree get_idx_left method -

   // - rb_tree get_gre_idx method -

   // - rb_tree get_lee_idx method -

   // - rb_tree get_idxs method -

   // - rb_tree operator= method -
   if (!(TYPE_NUMBERS(0) & c_type_dynamic)) {
      if (!(data_type.properties & c_type_setting_not_generate_operator_equal)) {
SAFE_RB_TREE_OPERATOR_EQUAL();
      }
   }

   // - rb_tree operator== method -

   // - rb_tree rehash_tree -

   // - rb_tree print_dot_code -

   // - rb_tree check_rb_tree_properties -

}

void processor_s::generate_safe_rb_tree_methods(unsigned abb_idx,unsigned a_dt_idx)
{
   data_type_s &data_type = data_types[a_dt_idx];

   unsigned type_cnt = data_type.types.used;
   unsigned type_idxs[type_cnt];
   data_type_s *types[type_cnt];

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

   unsigned t_idx;

   // --- definition of methods ---

printf(
"// --- struct %s method definition ---\n"
"\n"
,IM_STRUCT_NAME);

   // - rb_tree __get_grandparent_idx method -

   // - rb_tree __get_uncle_idx method -

   // - rb_tree __get_sibling_idx method -

   // - rb_tree get_descent_stack_size -

   // - rb_tree get_stack_min_value_idx method -
SAFE_RB_TREE_GET_STACK_MIN_VALUE_IDX();

   // - rb_tree get_stack_next_idx method -

   // - rb_tree get_min_value_idx method -
SAFE_RB_TREE_GET_MIN_VALUE_IDX();

   // - rb_tree get_max_value_idx method -
SAFE_RB_TREE_GET_MAX_VALUE_IDX();

   // - rb_tree get_next_idx method -
SAFE_RB_TREE_GET_NEXT_IDX();

   // - rb_tree get_prev_idx method -
SAFE_RB_TREE_GET_PREV_IDX();

   // - rb_tree __rotate_left method -

   // - rb_tree __rotate_right method -

   // - rb_tree __get_new_index method -

   // - rb_tree __binary_tree_insert method -
SAFE_RB_TREE___BINARY_TREE_INSERT();

   // - rb_tree __replace_delete_node_by_child method -

   // - rb_tree __remove_black_black method -
SAFE_RB_TREE___REMOVE_BLACK_BLACK();

   // - rb_tree __remove_one_child method -

   // - rb_tree __insert_operation method -
SAFE_RB_TREE___INSERT_OPERATION();

   // - rb_tree init method -

   // - rb_tree clear method -
   if (TYPE_NUMBERS(0) & c_type_dynamic) {
      if (!(data_type.properties & c_type_setting_not_generate_clear)) {
SAFE_RB_TREE_CLEAR();
      }
   }

   // - rb_tree flush method -

   // - rb_tree flush_all method -
   if (TYPE_NUMBERS(0) & c_type_flushable) {
SAFE_RB_TREE_FLUSH_ALL();
   }

   // - rb_tree swap method -

   // - rb_tree operator[] method -

   // - rb_tree insert method -

   // - rb_tree swap_insert method -

   // - rb_tree remove method -
SAFE_RB_TREE_REMOVE();

   // - rb_tree copy_resize method -
SAFE_RB_TREE_COPY_RESIZE();

   // - rb_tree get_idx method -
SAFE_RB_TREE_GET_IDX();

   // - rb_tree get_idx_left method -
SAFE_RB_TREE_GET_IDX_LEFT();

   // - rb_tree get_gre_idx method -
SAFE_RB_TREE_GET_GRE_IDX();

   // - rb_tree get_lee_idx method -
SAFE_RB_TREE_GET_LEE_IDX();

   // - rb_tree get_idxs method -
SAFE_RB_TREE_GET_IDXS();

   // - rb_tree operator= method -
   if (TYPE_NUMBERS(0) & c_type_dynamic) {
      if (!(data_type.properties & c_type_setting_not_generate_operator_equal)) {
SAFE_RB_TREE_OPERATOR_EQUAL();
      }
   }

   // - rb_tree operator== method -
SAFE_RB_TREE_OPERATOR_DOUBLE_EQUAL();

   // - rb_tree rehash_tree -
SAFE_RB_TREE_REHASH_TREE();

   // - rb_tree print_dot_code -
#ifdef SAFE_RB_TREE_GENERATE_PRINT_DOT_CODE
SAFE_RB_TREE_PRINT_DOT_CODE();
#endif

   // - rb_tree check_rb_tree_properties -
#ifdef SAFE_RB_TREE_GENERATE_CHECK_RB_TREE_PROPERTIES
SAFE_RB_TREE_CHECK_RB_TREE_PROPERTIES();
#endif

}


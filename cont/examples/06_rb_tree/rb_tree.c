
@begin
include "rb_tree.h"
@end

/*
 * methods of generated structures
 */

// -- ui_array_s --
@begin
   methods ui_array_s
@end

// -- rec_rb_tree_s --
@begin
   methods rec_rb_tree_s
@end

/*
 * global methods
 */

void print_tree(rec_rb_tree_s *rec_tree,const char *name)
{
  printf("%s.size:  %u\n",name,rec_tree->size);
  printf("%s.used:  %u\n",name,rec_tree->used);
  printf("%s.free_idx: %u\n",name,rec_tree->free_idx);
  printf("%s.root_idx: %u\n",name,rec_tree->root_idx);
  printf("%s.leaf_idx: %u\n",name,rec_tree->leaf_idx);
  printf("%s: ",name);

  if (rec_tree->root_idx != c_idx_not_exist)
  {
    unsigned stack[rec_rb_tree_s_get_descent_stack_size(rec_tree)];
    unsigned *stack_ptr = stack;

    unsigned idx = rec_rb_tree_s_get_stack_min_value_idx(rec_tree,rec_tree->root_idx,&stack_ptr);
    do
    {
      record_s *rec = &rec_tree->data[idx].object;
      printf("{%u,%u}",rec->index,rec->value);

      idx = rec_rb_tree_s_get_stack_next_idx(rec_tree,idx,&stack_ptr,stack);
    }
    while(idx != c_idx_not_exist);
  }

  printf("\n");
  printf("\n");
}

int main(int argc, char **argv)
{
  record_s rec;
  record_s_init(&rec);
  record_s_set(&rec,1,1);

  rec_rb_tree_s rb_tree0;
  rec_rb_tree_s_init(&rb_tree0);

  print_tree(&rb_tree0,"rb_tree0");

  printf("--- INSERT NEW RECORDS TO RB_TREE ---\n");
  
  unsigned idx = 0;
  do {
    rec.index = idx;
    rec_rb_tree_s_insert(&rb_tree0,&rec);
  } while(++idx < 7);

  print_tree(&rb_tree0,"rb_tree0");

  printf("--- REMOVE RECORDS FROM RB_TREE ---\n");
  
  idx = rec_rb_tree_s_get_min_value_idx(&rb_tree0,rb_tree0.root_idx);
  unsigned count = 0;
  do {
    unsigned next_idx = rec_rb_tree_s_get_next_idx(&rb_tree0,idx);
    rec_rb_tree_s_remove(&rb_tree0,idx);

    idx = next_idx;
  } while(++count < 3);

  print_tree(&rb_tree0,"rb_tree0");

  printf("--- INSERT NEW RECORDS TO RB_TREE ---\n");
  
  idx = 0;
  do {
    rec.index = idx + 4;
    rec_rb_tree_s_insert(&rb_tree0,&rec);
  } while(++idx < 4);

  print_tree(&rb_tree0,"rb_tree0");

  printf("--- CREATE NEW EMPTY RB_TREE ---\n");
  rec_rb_tree_s rb_tree1;
  rec_rb_tree_s_init(&rb_tree1);

  print_tree(&rb_tree0,"rb_tree0");
  print_tree(&rb_tree1,"rb_tree1");

  printf("--- COMPARE RB_TREE CONTENT ---\n");
  printf("rec_rb_tree_s_compare(&rb_tree0,&rb_tree1): %s\n",rec_rb_tree_s_compare(&rb_tree0,&rb_tree1) ? "TRUE" : "FALSE");
  printf("\n");

  printf("--- ASSIGN RB_TREE CONTENT ---\n");
  rec_rb_tree_s_copy(&rb_tree1,&rb_tree0);

  print_tree(&rb_tree0,"rb_tree0");
  print_tree(&rb_tree1,"rb_tree1");

  printf("--- COMPARE RB_TREE CONTENT ---\n");
  printf("rec_rb_tree_s_compare(&rb_tree0,&rb_tree1): %s\n",rec_rb_tree_s_compare(&rb_tree0,&rb_tree1) ? "TRUE" : "FALSE");
  printf("\n");

  rec_rb_tree_s_clear(&rb_tree1);
  rec_rb_tree_s_clear(&rb_tree0);
  record_s_clear(&rec);

  return 0;
}


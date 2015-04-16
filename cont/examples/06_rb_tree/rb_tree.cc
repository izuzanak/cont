
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

void print_tree(rec_rb_tree_s &rec_tree,const char *name)
{
  printf("%s.size:  %u\n",name,rec_tree.size);
  printf("%s.used:  %u\n",name,rec_tree.used);
  printf("%s.free_idx: %u\n",name,rec_tree.free_idx);
  printf("%s.root_idx: %u\n",name,rec_tree.root_idx);
  printf("%s.leaf_idx: %u\n",name,rec_tree.leaf_idx);
  printf("%s:",name);

  if (rec_tree.root_idx != c_idx_not_exist)
  {
    unsigned stack[rec_tree.get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned idx = rec_tree.get_stack_min_value_idx(rec_tree.root_idx,&stack_ptr);
    do
    {
      record_s &rec = rec_tree[idx];
      printf("{%u,%u}",rec.index,rec.value);

      idx = rec_tree.get_stack_next_idx(idx,&stack_ptr,stack);
    }
    while(idx != c_idx_not_exist);
  }

  printf("\n");
  printf("\n");
}

int main(int argc, char **argv)
{
  record_s rec;
  rec.init();
  rec.set(1,1);

  rec_rb_tree_s rb_tree0;
  rb_tree0.init();

  print_tree(rb_tree0,"rb_tree0");

  printf("--- INSERT NEW RECORDS TO RB_TREE ---\n");
  
  unsigned idx = 0;
  do {
    rec.index = idx;
    rb_tree0.insert(rec);
  } while(++idx < 7);

  print_tree(rb_tree0,"rb_tree0");

  printf("--- REMOVE RECORDS FROM RB_TREE ---\n");
  
  idx = rb_tree0.get_min_value_idx(rb_tree0.root_idx);
  unsigned count = 0;
  do {
    unsigned next_idx = rb_tree0.get_next_idx(idx);
    rb_tree0.remove(idx);

    idx = next_idx;
  } while(++count < 3);

  print_tree(rb_tree0,"rb_tree0");

  printf("--- INSERT NEW RECORDS TO RB_TREE ---\n");
  
  idx = 0;
  do {
    rec.index = idx + 4;
    rb_tree0.insert(rec);
  } while(++idx < 4);

  print_tree(rb_tree0,"rb_tree0");

  printf("--- CREATE NEW EMPTY RB_TREE ---\n");
  rec_rb_tree_s rb_tree1;
  rb_tree1.init();

  print_tree(rb_tree0,"rb_tree0");
  print_tree(rb_tree1,"rb_tree1");

  printf("--- COMPARE RB_TREE CONTENT ---\n");
  printf("rb_tree0 == rb_tree1: %s\n",rb_tree0 == rb_tree1 ? "TRUE" : "FALSE");
  printf("\n");

  printf("--- ASSIGN RB_TREE CONTENT ---\n");
  rb_tree1 = rb_tree0;

  print_tree(rb_tree0,"rb_tree0");
  print_tree(rb_tree1,"rb_tree1");

  printf("--- COMPARE RB_TREE CONTENT ---\n");
  printf("rb_tree0 == rb_tree1: %s\n",rb_tree0 == rb_tree1 ? "TRUE" : "FALSE");
  printf("\n");

  rb_tree1.clear();
  rb_tree0.clear();
  rec.clear();

  return 0;
}



@begin
include "int_str_map.h"
@end

/*
 * constants and definitions
 */

// - string terminating character -
const char c_string_terminating_char = '\0';

/*
 * methods of generated structures
 */

// -- ui_array_s --
@begin
   methods ui_array_s
@end

// -- int_string_s --
@begin
   methods int_string_s
@end

// -- int_string_map_s --
@begin
   methods int_string_map_s
@end

int main(int argc, char **argv)
{
  int_string_map_s map;
#ifdef FIXED_BUFFER
  int_string_map_s_init_buffer(&map,1001,alloca(1001*sizeof(int_string_map_s_node)));
#else
  int_string_map_s_init(&map);
#endif

  unsigned buff_size = 64;
  char buffer[buff_size];

  // ...
  {
    string_s str;
    string_s_init(&str);

    int_string_s pair;
    int_string_s_init(&pair);

    int idx = 0;
    do {
      int length = snprintf(buffer,buff_size,"string-%d",idx);

      pair.index = rand() % 1000;
      string_s_set(&pair.value,length,buffer);

      unsigned p_idx = int_string_map_s_get_idx(&map,&pair);
      if (p_idx != c_idx_not_exist)
      {
        string_s_swap(&int_string_map_s_at(&map,p_idx)->value,&pair.value);
      }
      else
      {
        int_string_map_s_swap_insert(&map,&pair);
      }
    } while(++idx < 1000000);

    int_string_s_clear(&pair);
    string_s_clear(&str);
  }

  // ...
  if (map.root_idx != c_idx_not_exist)
  {
    unsigned stack[int_string_map_s_get_descent_stack_size(&map)];
    unsigned *stack_ptr = stack;

    unsigned idx = int_string_map_s_get_stack_min_value_idx(&map,map.root_idx,&stack_ptr);
    do
    {
      int_string_s *pair = int_string_map_s_at(&map,idx);
      printf("%d -> %s\n",pair->index,pair->value.data);

      idx = int_string_map_s_get_stack_next_idx(&map,idx,&stack_ptr,stack);
    }
    while(idx != c_idx_not_exist);
  }

  int_string_map_s_clear(&map);

  return 0;
}


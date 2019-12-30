
@begin
include "int_str_map.h"
@end

/*
 * constants and definitions
 */

// - string terminating character -
const char c_string_terminating_char = '\0';

/*
 * methods of structure string_s
 */

void string_s::setf(const char *format,...)
{/*{{{*/
  clear();

  const int init_size = 256;
  int alloc_size = init_size;

  va_list ap;

  do
  {
    data = (char *)cmalloc(alloc_size*sizeof(char));

    va_start(ap,format);

#if SYSTEM_TYPE == SYSTEM_TYPE_DSP
    // DSP FIXME
    int cnt = vsprintf(data,format,ap);
#else
    int cnt = vsnprintf(data,alloc_size,format,ap);
#endif
    va_end(ap);

    if (cnt < alloc_size)
    {
      size = cnt + 1;
      break;
    }

    cfree(data);
    alloc_size <<= 1;

  }
  while(1);
}/*}}}*/

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
  map.init();

  // ...
  {
    string_s str;
    str.init();

    int_string_s pair;
    pair.init();

    int idx = 0;
    do {
      pair.index = rand() % 10;
      pair.value.setf("string-%d",idx);

      unsigned p_idx = map.get_idx(pair);
      if (p_idx != c_idx_not_exist)
      {
        map[p_idx].value.swap(pair.value);
      }
      else
      {
        map.swap_insert(pair);
      }
    } while(++idx < 1000);

    pair.clear();
    str.clear();
  }

  // ...
  if (map.root_idx != c_idx_not_exist)
  {
    unsigned stack[map.get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned idx = map.get_stack_min_value_idx(map.root_idx,&stack_ptr);
    do
    {
      int_string_s &pair = map[idx];
      printf("%d -> %s\n",pair.index,pair.value.data);

      idx = map.get_stack_next_idx(idx,&stack_ptr,stack);
    }
    while(idx != c_idx_not_exist);
  }

  map.clear();

  return 0;
}


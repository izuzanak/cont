
@begin
include "struct.h"
@end

/*
 * methods of generated structures
 */

// -- record_s --
@begin
methods record_s
@end

/*
 * global methods
 */

int main(int argc, char **argv)
{
  CONT_INIT_CLEAR(record_s,rec0);
  CONT_INIT_CLEAR(record_s,rec1);

  record_s_set(&rec0,1,2);
  record_s_set(&rec1,3,4);

  printf("rec0: {%u,%u}\n",rec0.index,rec0.value);
  printf("rec1: {%u,%u}\n",rec1.index,rec1.value);
  printf("record_s_compare(&rec0,&rec1): %s\n",record_s_compare(&rec0,&rec1) ? "TRUE" : "FALSE");
  printf("\n");

  record_s_swap(&rec1,&rec0);
  printf("rec0: {%u,%u}\n",rec0.index,rec0.value);
  printf("rec1: {%u,%u}\n",rec1.index,rec1.value);
  printf("record_s_compare(&rec0,&rec1): %s\n",record_s_compare(&rec0,&rec1) ? "TRUE" : "FALSE");
  printf("\n");

  record_s_copy(&rec1,&rec0);
  printf("rec0: {%u,%u}\n",rec0.index,rec0.value);
  printf("rec1: {%u,%u}\n",rec1.index,rec1.value);
  printf("record_s_compare(&rec0,&rec1): %s\n",record_s_compare(&rec0,&rec1) ? "TRUE" : "FALSE");
  printf("\n");

  printf("record_s_get_index(&rec0): %u\n",record_s_get_index(&rec0));
  printf("record_s_get_value(&rec0): %u\n",record_s_get_value(&rec0));

  return 0;
}


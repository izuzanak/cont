
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
  record_s rec0,rec1;

  rec0.init();
  rec1.init();

  rec0.set(1,2);
  rec1.set(3,4);

  printf("rec0: {%u,%u}\n",rec0.index,rec0.value);
  printf("rec1: {%u,%u}\n",rec1.index,rec1.value);
  printf("rec0 == rec1: %s\n",rec0 == rec1 ? "TRUE" : "FALSE");
  printf("\n");

  rec1.swap(rec0);
  printf("rec0: {%u,%u}\n",rec0.index,rec0.value);
  printf("rec1: {%u,%u}\n",rec1.index,rec1.value);
  printf("rec0 == rec1: %s\n",rec0 == rec1 ? "TRUE" : "FALSE");
  printf("\n");

  rec1 = rec0;
  printf("rec0: {%u,%u}\n",rec0.index,rec0.value);
  printf("rec1: {%u,%u}\n",rec1.index,rec1.value);
  printf("rec0 == rec1: %s\n",rec0 == rec1 ? "TRUE" : "FALSE");
  printf("\n");

  printf("rec0.get_index(): %u\n",rec0.get_index());
  printf("rec0.get_value(): %u\n",rec0.get_value());

  rec0.clear();
  rec1.clear();

  return 0;
}


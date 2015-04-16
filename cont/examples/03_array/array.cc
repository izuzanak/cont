
@begin
include "array.h"
@end

/*
 * methods of generated structures
 */

// -- rec_array_s --
@begin
   methods rec_array_s
@end

/*
 * global methods
 */

void print_array(rec_array_s &rec_array,const char *name)
{
  printf("%s.size: %u\n",name,rec_array.size);
  printf("%s.used: %u\n",name,rec_array.used);
  printf("%s: ",name);

  record_s *r_ptr = rec_array.data;
  record_s *r_ptr_end = r_ptr + rec_array.used;
  while (r_ptr < r_ptr_end)
  {
    printf("{%u,%u}",r_ptr->index,r_ptr->value);
    ++r_ptr;
  }
  printf("\n");
  printf("\n");
}

int main(int argc, char **argv)
{
  record_s rec;
  rec.init();
  rec.set(1,2);

  rec_array_s array0;

  printf("--- INITIALIZE AND FILL ARRAY ---\n");
  array0.init_size(5);
  array0.fill(rec);

  print_array(array0,"array0");

  printf("--- POP RECORDS FROM ARRAY ---\n");
  while (array0.used > 3)
  {
    array0.pop();
  }

  print_array(array0,"array0");

  rec.index = 3;
  rec.value = 4;

  printf("--- PUSH RECORDS TO ARRAY ---\n");
  array0.push(rec);
  array0.push(rec);
  array0.push(rec);

  print_array(array0,"array0");

  printf("--- MODIFY RECORDS OF ARRAY ---\n");
  unsigned idx = 3;
  do {
    array0[idx].value = 5;
  } while(++idx < array0.used);

  print_array(array0,"array0");

  printf("--- CREATE NEW EMPTY ARRAY ---\n");
  rec_array_s array1;
  array1.init();

  print_array(array0,"array0");
  print_array(array1,"array1");

  printf("--- SWAP CONTENT OF ARRAYS ---\n");
  array0.swap(array1);

  print_array(array0,"array0");
  print_array(array1,"array1");

  printf("--- COMPARE ARRAY CONTENT ---\n");
  printf("array0 == array1: %s\n",array0 == array1 ? "TRUE" : "FALSE");
  printf("\n");

  printf("--- ASSIGN ARRAY CONTENT ---\n");
  array0 = array1;

  printf("array0 == array1: %s\n",array0 == array1 ? "TRUE" : "FALSE");
  printf("\n");

  array1.clear();
  array0.clear();
  rec.clear();

  return 0;
}


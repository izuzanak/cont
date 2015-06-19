
@begin
include "dynamic.h"
@end

/*
 * constants and definitions
 */

// - string terminating character -
const char c_string_terminating_char = '\0';

/*
 * methods of generated structures
 */

// -- string_array_s --
@begin
   methods string_array_s
@end

/*
 * global methods
 */

void print_array(string_array_s &str_array,const char *name)
{
  printf("%s.size: %u\n",name,str_array.size);
  printf("%s.used: %u\n",name,str_array.used);
  printf("%s: ",name);

  string_s *s_ptr = str_array.data;
  string_s *s_ptr_end = s_ptr + str_array.used;
  while (s_ptr < s_ptr_end)
  {
    printf("%s ",s_ptr->data);
    ++s_ptr;
  }
  printf("\n");
  printf("\n");
}

int main(int argc, char **argv)
{
  string_s string;
  string.init();
  string.set(strlen("String"),"String");

  string_array_s array0;
  array0.init();

  printf("--- CREATE EMPTY ARRAY ---\n");
  print_array(array0,"array0");

  printf("--- FILL STRINGS TO ARRAY ---\n");
  unsigned idx = 0;
  do {
    array0.push(string);
  } while(++idx < 8);

  print_array(array0,"array0");

  printf("--- POP STRINGS FROM ARRAY ---\n");
  while (array0.used > 3)
  {
    array0.pop();
  }

  print_array(array0,"array0");

  printf("--- PUSH STRINGS TO ARRAY ---\n");
  string.set(strlen("Pushed"),"Pushed");
  array0.push(string);
  array0.push(string);
  array0.push(string);

  print_array(array0,"array0");

  printf("--- MODIFY ARRAY ELEMENT ---\n");
  string.set(strlen("Modified"),"Modified");
  array0[2] = string;

  print_array(array0,"array0");

  printf("--- CREATE NEW EMPTY ARRAY ---\n");
  string_array_s array1;
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
  string.clear();

  return 0;
}


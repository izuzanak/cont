
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

void print_array(string_array_s *str_array,const char *name)
{
  printf("%s.size: %u\n",name,str_array->size);
  printf("%s.used: %u\n",name,str_array->used);
  printf("%s: ",name);

  string_s *s_ptr = str_array->data;
  string_s *s_ptr_end = s_ptr + str_array->used;
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
  string_s_init(&string);
  string_s_set(&string,strlen("String"),"String");

  string_array_s array0;
  string_array_s_init(&array0);

  printf("--- CREATE EMPTY ARRAY ---\n");
  print_array(&array0,"array0");

  printf("--- FILL STRINGS TO ARRAY ---\n");
  unsigned idx = 0;
  do {
    string_array_s_push(&array0,&string);
  } while(++idx < 8);

  print_array(&array0,"array0");

  printf("--- POP STRINGS FROM ARRAY ---\n");
  while (array0.used > 3)
  {
    string_array_s_pop(&array0);
  }

  print_array(&array0,"array0");

  printf("--- PUSH STRINGS TO ARRAY ---\n");
  string_s_set(&string,strlen("Pushed"),"Pushed");
  string_array_s_push(&array0,&string);
  string_array_s_push(&array0,&string);
  string_array_s_push(&array0,&string);

  print_array(&array0,"array0");

  printf("--- MODIFY ARRAY ELEMENT ---\n");
  string_s_set(&string,strlen("Modified"),"Modified");
  string_s_copy(array0.data + 2,&string);

  print_array(&array0,"array0");

  printf("--- CREATE NEW EMPTY ARRAY ---\n");
  string_array_s array1;
  string_array_s_init(&array1);

  print_array(&array0,"array0");
  print_array(&array1,"array1");

  printf("--- SWAP CONTENT OF ARRAYS ---\n");
  string_array_s_swap(&array0,&array1);

  print_array(&array0,"array0");
  print_array(&array1,"array1");

  printf("--- COMPARE ARRAY CONTENT ---\n");
  printf("string_array_s_compare(&array0,&array1): %s\n",string_array_s_compare(&array0,&array1) ? "TRUE" : "FALSE");
  printf("\n");

  printf("--- ASSIGN ARRAY CONTENT ---\n");
  string_array_s_copy(&array1,&array0);

  printf("string_array_s_compare(&array0,&array1): %s\n",string_array_s_compare(&array0,&array1) ? "TRUE" : "FALSE");
  printf("\n");

  string_array_s_clear(&array1);
  string_array_s_clear(&array0);
  string_s_clear(&string);

  return 0;
}


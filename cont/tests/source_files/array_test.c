
@begin
include "array_test.h"
@end

/*
 * methods of generated structures
 */

// -- ui_array_s --
@begin
methods ui_array_s
@end

// -- ui_arrays_s --
@begin
methods ui_arrays_s
@end

// -- ui_fixed_array_s --
@begin
methods ui_fixed_array_s
@end

void test_array_init()
{/*{{{*/
  printf("test_array_init\n");

  CONT_INIT_CLEAR(bc_array_s,buffer);

  // - init -
  CONT_INIT_CLEAR(ui_array_s,array_0);

  buffer.used = 0;
  ui_array_s_to_string(&array_0,&buffer);
  cassert(strncmp(buffer.data,"[]",buffer.used) == 0);

  // - init_size -
  CONT_CLEAR(ui_array_s,array_1);
  ui_array_s_init_size(&array_1,10);
  ui_array_s_fill(&array_1,1);
  cassert(array_1.used == 10 && array_1.size == 10);

  buffer.used = 0;
  ui_array_s_to_string(&array_1,&buffer);
  cassert(strncmp(buffer.data,"[1,1,1,1,1,1,1,1,1,1]",buffer.used) == 0);

  // - reserve -
  ui_array_s_reserve(&array_1,100);
  cassert(array_1.used + 100 <= array_1.size);
}/*}}}*/

void test_array_clear()
{/*{{{*/
  printf("test_array_clear\n");

  CONT_INIT_CLEAR(bc_array_s,buffer);

  // - init_size -
  CONT_CLEAR(ui_array_s,array_0);
  ui_array_s_init_size(&array_0,10);
  ui_array_s_fill(&array_0,1);
  cassert(array_0.used == 10 && array_0.size == 10);

  // - clear -
  ui_array_s_clear(&array_0);
  cassert(array_0.used == 0 && array_0.size == 0);
}/*}}}*/

void test_array_push()
{/*{{{*/
  printf("test_array_push\n");

  CONT_INIT_CLEAR(bc_array_s,buffer);

  // - push -
  CONT_INIT_CLEAR(ui_array_s,array_0);

  unsigned idx = 0;
  do {
    ui_array_s_push(&array_0,idx);
  } while(++idx < 10);

  buffer.used = 0;
  ui_array_s_to_string(&array_0,&buffer);
  cassert(strncmp(buffer.data,"[0,1,2,3,4,5,6,7,8,9]",buffer.used) == 0);

  // - push, pop -
  CONT_INIT_CLEAR(ui_array_s,array_1);

  while (array_0.used > 5)
  {
    ui_array_s_push(&array_1,
      ui_array_s_pop(&array_0));
  }

  buffer.used = 0;
  ui_array_s_to_string(&array_0,&buffer);
  ui_array_s_to_string(&array_1,&buffer);
  cassert(strncmp(buffer.data,"[0,1,2,3,4][9,8,7,6,5]",buffer.used) == 0);

  // - push_blank, push_blanks, push_clear -
  ui_array_s_push_blank(&array_0);
  ui_array_s_push_blanks(&array_0,3);
  ui_array_s_push_clear(&array_0);

  buffer.used = 0;
  ui_array_s_to_string(&array_0,&buffer);
  cassert(strncmp(buffer.data,"[0,1,2,3,4,5,6,7,8,9]",buffer.used) == 0);
}/*}}}*/

void test_array_flush()
{/*{{{*/
  printf("test_array_flush\n");

  CONT_INIT_CLEAR(bc_array_s,buffer);

  // - flush -
  CONT_INIT_CLEAR(ui_array_s,array_0);

  unsigned idx = 0;
  do {
    ui_array_s_push(&array_0,idx);
  } while(++idx < 10);

  buffer.used = 0;
  ui_array_s_to_string(&array_0,&buffer);
  cassert(strncmp(buffer.data,"[0,1,2,3,4,5,6,7,8,9]",buffer.used) == 0);

  if (array_0.used == array_0.size)
  {
    ui_array_s_reserve(&array_0,1);
  }

  cassert(array_0.used < array_0.size);
  ui_array_s_flush(&array_0);
  cassert(array_0.used == array_0.size);

  buffer.used = 0;
  ui_array_s_to_string(&array_0,&buffer);
  cassert(strncmp(buffer.data,"[0,1,2,3,4,5,6,7,8,9]",buffer.used) == 0);
}/*}}}*/

void test_array_get_idx()
{/*{{{*/
  printf("test_array_get_idx\n");

  CONT_INIT_CLEAR(bc_array_s,buffer);

  // - get_idx -
  CONT_INIT_CLEAR(ui_array_s,array_0);

  unsigned idx = 0;
  do {
    ui_array_s_push(&array_0,100 - idx);
  } while(++idx < 100);

  cassert(ui_array_s_get_idx(&array_0,0) == c_idx_not_exist);
  cassert(ui_array_s_get_idx(&array_0,10) == (100 - 10));
  cassert(ui_array_s_get_idx(&array_0,60) == (100 - 60));
  cassert(ui_array_s_get_idx(&array_0,99) == (100 - 99));
}/*}}}*/

void test_array_compare()
{/*{{{*/
  printf("test_array_compare\n");

  CONT_INIT_CLEAR(bc_array_s,buffer);

  // - set, compare -
  CONT_INIT_CLEAR(ui_array_s,array_0);
  CONT_INIT_CLEAR(ui_array_s,array_1);

  unsigned idx = 0;
  do {
    ui_array_s_push(&array_0,idx);
  } while(++idx < 10);

  unsigned data[10] = {0,1,2,3,4,5,6,7,8,9};

  ui_array_s_set(&array_1,10,data);
  cassert(ui_array_s_compare(&array_0,&array_1));
  cassert(ui_array_s_pop(&array_0) == 9);
  cassert(!ui_array_s_compare(&array_0,&array_1));
}/*}}}*/

void test_array_dynamic_init()
{/*{{{*/
  printf("test_array_dynamic_init\n");

  CONT_INIT_CLEAR(bc_array_s,buffer);

  // - push -
  CONT_INIT_CLEAR(ui_array_s,array_0);

  unsigned idx = 0;
  do {
    ui_array_s_push(&array_0,idx);
  } while(++idx < 5);

  buffer.used = 0;
  ui_array_s_to_string(&array_0,&buffer);
  cassert(strncmp(buffer.data,"[0,1,2,3,4]",buffer.used) == 0);

  // - push -
  CONT_INIT_CLEAR(ui_arrays_s,arrays_0);

  ui_arrays_s_push(&arrays_0,&array_0);
  ui_arrays_s_push(&arrays_0,&array_0);

  buffer.used = 0;
  ui_arrays_s_to_string(&arrays_0,&buffer);
  cassert(strncmp(buffer.data,"[[0,1,2,3,4],[0,1,2,3,4]]",buffer.used) == 0);

  // - reserve -
  ui_arrays_s_reserve(&arrays_0,100);
  cassert(arrays_0.used + 100 <= arrays_0.size);
}/*}}}*/

void test_array_dynamic_set()
{/*{{{*/
  printf("test_array_dynamic_set\n");

  CONT_INIT_CLEAR(bc_array_s,buffer);

  // - push -
  unsigned data[5] = {0,1,2,3,4};
  CONT_INIT_CLEAR(ui_array_s,array_0);
  ui_array_s_set(&array_0,5,data);

  buffer.used = 0;
  ui_array_s_to_string(&array_0,&buffer);
  cassert(strncmp(buffer.data,"[0,1,2,3,4]",buffer.used) == 0);

  // - push -
  CONT_INIT_CLEAR(ui_arrays_s,arrays_0);
  CONT_INIT_CLEAR(ui_arrays_s,arrays_1);

  ui_arrays_s_init_size(&arrays_0,5);
  ui_arrays_s_fill(&arrays_0,&array_0);

  ui_arrays_s_set(&arrays_1,arrays_0.used,arrays_0.data);
  cassert(ui_arrays_s_compare(&arrays_0,&arrays_1));

  buffer.used = 0;
  ui_arrays_s_to_string(&arrays_1,&buffer);
  cassert(strncmp(buffer.data,"[[0,1,2,3,4],[0,1,2,3,4],[0,1,2,3,4],[0,1,2,3,4],[0,1,2,3,4]]",buffer.used) == 0);
}/*}}}*/

void test_array_dynamic_push()
{/*{{{*/
  printf("test_array_dynamic_push\n");

  CONT_INIT_CLEAR(bc_array_s,buffer);

  // - push -
  CONT_INIT_CLEAR(ui_array_s,array_0);

  unsigned idx = 0;
  do {
    ui_array_s_push(&array_0,idx);
  } while(++idx < 5);

  buffer.used = 0;
  ui_array_s_to_string(&array_0,&buffer);
  cassert(strncmp(buffer.data,"[0,1,2,3,4]",buffer.used) == 0);

  // - push -
  CONT_INIT_CLEAR(ui_arrays_s,arrays_0);

  ui_arrays_s_push(&arrays_0,&array_0);
  ui_arrays_s_push(&arrays_0,&array_0);
  ui_arrays_s_push(&arrays_0,&array_0);

  buffer.used = 0;
  ui_arrays_s_to_string(&arrays_0,&buffer);
  cassert(strncmp(buffer.data,"[[0,1,2,3,4],[0,1,2,3,4],[0,1,2,3,4]]",buffer.used) == 0);

  // - push_blank -
  --arrays_0.used;
  ui_arrays_s_push_blank(&arrays_0);
  ui_arrays_s_push_blank(&arrays_0);
  ui_arrays_s_push_blank(&arrays_0);

  buffer.used = 0;
  ui_arrays_s_to_string(&arrays_0,&buffer);
  cassert(strncmp(buffer.data,"[[0,1,2,3,4],[0,1,2,3,4],[0,1,2,3,4],[],[]]",buffer.used) == 0);

  // - push_clear -
  arrays_0.used -= 3;
  ui_arrays_s_push_clear(&arrays_0);
  ui_arrays_s_push_clear(&arrays_0);
  ui_arrays_s_push_clear(&arrays_0);

  buffer.used = 0;
  ui_arrays_s_to_string(&arrays_0,&buffer);
  cassert(strncmp(buffer.data,"[[0,1,2,3,4],[0,1,2,3,4],[],[],[]]",buffer.used) == 0);

  // - push_blanks -
  arrays_0.used -= 4;

  buffer.used = 0;
  ui_arrays_s_to_string(&arrays_0,&buffer);
  cassert(strncmp(buffer.data,"[[0,1,2,3,4]]]",buffer.used) == 0);

  ui_arrays_s_push_blanks(&arrays_0,3);
  buffer.used = 0;
  ui_arrays_s_to_string(&arrays_0,&buffer);
  cassert(strncmp(buffer.data,"[[0,1,2,3,4],[0,1,2,3,4],[],[]]",buffer.used) == 0);
}/*}}}*/

void test_array_dynamic_flush()
{/*{{{*/
  printf("test_array_dynamic_flush\n");

  CONT_INIT_CLEAR(bc_array_s,buffer);

  // - push -
  CONT_INIT_CLEAR(ui_array_s,array_0);

  unsigned idx = 0;
  do {
    ui_array_s_push(&array_0,idx);
  } while(++idx < 5);

  buffer.used = 0;
  ui_array_s_to_string(&array_0,&buffer);
  cassert(strncmp(buffer.data,"[0,1,2,3,4]",buffer.used) == 0);

  // - flush -
  CONT_INIT_CLEAR(ui_arrays_s,arrays_0);

  idx = 0;
  do {
    ui_arrays_s_push(&arrays_0,&array_0);
    ui_array_s_reserve(ui_arrays_s_last(&arrays_0),1);
  } while(++idx < 5);

  buffer.used = 0;
  ui_arrays_s_to_string(&arrays_0,&buffer);
  cassert(strncmp(buffer.data,"[[0,1,2,3,4],[0,1,2,3,4],[0,1,2,3,4],[0,1,2,3,4],[0,1,2,3,4]]",buffer.used) == 0);

  if (arrays_0.used == arrays_0.size)
  {
    ui_arrays_s_reserve(&arrays_0,1);
  }

  cassert(arrays_0.used < arrays_0.size);
  ui_arrays_s_flush(&arrays_0);
  cassert(arrays_0.used == arrays_0.size);

  buffer.used = 0;
  ui_arrays_s_to_string(&arrays_0,&buffer);
  cassert(strncmp(buffer.data,"[[0,1,2,3,4],[0,1,2,3,4],[0,1,2,3,4],[0,1,2,3,4],[0,1,2,3,4]]",buffer.used) == 0);

  ui_array_s *a_ptr,*a_ptr_end;

  // - check that arrays are not flushed -
  a_ptr = arrays_0.data;
  a_ptr_end = a_ptr + arrays_0.used;
  do {
    cassert(a_ptr->used < a_ptr->size);
  } while(++a_ptr < a_ptr_end);

  ui_arrays_s_flush_all(&arrays_0);

  // - check that arrays are flushed -
  a_ptr = arrays_0.data;
  a_ptr_end = a_ptr + arrays_0.used;
  do {
    cassert(a_ptr->used == a_ptr->size);
  } while(++a_ptr < a_ptr_end);

  buffer.used = 0;
  ui_arrays_s_to_string(&arrays_0,&buffer);
  cassert(strncmp(buffer.data,"[[0,1,2,3,4],[0,1,2,3,4],[0,1,2,3,4],[0,1,2,3,4],[0,1,2,3,4]]",buffer.used) == 0);
}/*}}}*/

void test_array_dynamic_get_idx()
{/*{{{*/
  printf("test_array_dynamic_get_idx\n");

  CONT_INIT_CLEAR(bc_array_s,buffer);

  // - push -
  CONT_INIT_CLEAR(ui_array_s,array_0);

  unsigned idx = 0;
  do {
    ui_array_s_push(&array_0,idx);
  } while(++idx < 4);

  buffer.used = 0;
  ui_array_s_to_string(&array_0,&buffer);
  cassert(strncmp(buffer.data,"[0,1,2,3]",buffer.used) == 0);

  // - get_idx -
  CONT_INIT_CLEAR(ui_arrays_s,arrays_0);

  idx = 0;
  do {
    ui_arrays_s_push(&arrays_0,&array_0);
    ui_array_s_push(ui_arrays_s_last(&arrays_0),idx);
  } while(++idx < 5);

  buffer.used = 0;
  ui_arrays_s_to_string(&arrays_0,&buffer);
  cassert(strncmp(buffer.data,"[[0,1,2,3,0],[0,1,2,3,1],[0,1,2,3,2],[0,1,2,3,3],[0,1,2,3,4]]",buffer.used) == 0);

  cassert(ui_arrays_s_get_idx(&arrays_0,&array_0) == c_idx_not_exist);
  ui_array_s_push(&array_0,3);
  cassert(ui_arrays_s_get_idx(&arrays_0,&array_0) == 3);
}/*}}}*/

void test_array_dynamic_fill()
{/*{{{*/
  printf("test_array_dynamic_fill\n");

  CONT_INIT_CLEAR(bc_array_s,buffer);

  // - push -
  CONT_INIT_CLEAR(ui_array_s,array_0);

  unsigned idx = 0;
  do {
    ui_array_s_push(&array_0,idx);
  } while(++idx < 5);

  buffer.used = 0;
  ui_array_s_to_string(&array_0,&buffer);
  cassert(strncmp(buffer.data,"[0,1,2,3,4]",buffer.used) == 0);

  // - push -
  CONT_INIT_CLEAR(ui_arrays_s,arrays_0);
  ui_arrays_s_init_size(&arrays_0,5);
  ui_arrays_s_fill(&arrays_0,&array_0);

  buffer.used = 0;
  ui_arrays_s_to_string(&arrays_0,&buffer);
  cassert(strncmp(buffer.data,"[[0,1,2,3,4],[0,1,2,3,4],[0,1,2,3,4],[0,1,2,3,4],[0,1,2,3,4]]",buffer.used) == 0);
}/*}}}*/

void test_array_dynamic_compare()
{/*{{{*/
  printf("test_array_dynamic_compare\n");

  CONT_INIT_CLEAR(bc_array_s,buffer);

  // - push -
  CONT_INIT_CLEAR(ui_array_s,array_0);

  unsigned idx = 0;
  do {
    ui_array_s_push(&array_0,idx);
  } while(++idx < 5);

  buffer.used = 0;
  ui_array_s_to_string(&array_0,&buffer);
  cassert(strncmp(buffer.data,"[0,1,2,3,4]",buffer.used) == 0);

  // - copy, compare -
  CONT_INIT_CLEAR(ui_arrays_s,arrays_0);
  CONT_INIT_CLEAR(ui_arrays_s,arrays_1);

  ui_arrays_s_init_size(&arrays_0,5);
  ui_arrays_s_fill(&arrays_0,&array_0);

  buffer.used = 0;
  ui_arrays_s_to_string(&arrays_0,&buffer);
  cassert(strncmp(buffer.data,"[[0,1,2,3,4],[0,1,2,3,4],[0,1,2,3,4],[0,1,2,3,4],[0,1,2,3,4]]",buffer.used) == 0);

  cassert(!ui_arrays_s_compare(&arrays_0,&arrays_1));

  ui_arrays_s_copy(&arrays_1,&arrays_0);
  cassert(ui_arrays_s_compare(&arrays_0,&arrays_1));

  buffer.used = 0;
  ui_arrays_s_to_string(&arrays_1,&buffer);
  cassert(strncmp(buffer.data,"[[0,1,2,3,4],[0,1,2,3,4],[0,1,2,3,4],[0,1,2,3,4],[0,1,2,3,4]]",buffer.used) == 0);

  arrays_1.data[1].data[1] = 0;

  buffer.used = 0;
  ui_arrays_s_to_string(&arrays_1,&buffer);
  cassert(strncmp(buffer.data,"[[0,1,2,3,4],[0,0,2,3,4],[0,1,2,3,4],[0,1,2,3,4],[0,1,2,3,4]]",buffer.used) == 0);

  cassert(!ui_arrays_s_compare(&arrays_0,&arrays_1));
}/*}}}*/

void test_array_fixed_init()
{/*{{{*/
  printf("test_array_fixed_init\n");

  CONT_INIT_CLEAR(bc_array_s,buffer);

  // - init_buffer -
  ui_fixed_array_s fixed_array_0;
  ui_fixed_array_s_init_buffer(&fixed_array_0,10,alloca(10*sizeof(ui)));

  buffer.used = 0;
  ui_fixed_array_s_to_string(&fixed_array_0,&buffer);
  cassert(strncmp(buffer.data,"[]",buffer.used) == 0);
}/*}}}*/

void test_array_fixed_clear()
{/*{{{*/
  printf("test_array_fixed_clear\n");

  CONT_INIT_CLEAR(bc_array_s,buffer);

  // - init_buffer -
  ui_fixed_array_s fixed_array_0;
  ui_fixed_array_s_init_buffer(&fixed_array_0,10,alloca(10*sizeof(ui)));

  // - push -
  unsigned idx = 0;
  do {
    ui_fixed_array_s_push(&fixed_array_0,idx);
  } while(++idx < 10);

  buffer.used = 0;
  ui_fixed_array_s_to_string(&fixed_array_0,&buffer);
  cassert(strncmp(buffer.data,"[0,1,2,3,4,5,6,7,8,9]",buffer.used) == 0);

  // - clear -
  ui_fixed_array_s_clear(&fixed_array_0);
  cassert(fixed_array_0.used == 0 && fixed_array_0.size == 10);
}/*}}}*/

void test_array_fixed_push()
{/*{{{*/
  printf("test_array_fixed_push\n");

  CONT_INIT_CLEAR(bc_array_s,buffer);

  // - init_buffer -
  ui_fixed_array_s fixed_array_0;
  ui_fixed_array_s_init_buffer(&fixed_array_0,10,alloca(10*sizeof(ui)));

  buffer.used = 0;
  ui_fixed_array_s_to_string(&fixed_array_0,&buffer);
  cassert(strncmp(buffer.data,"[]",buffer.used) == 0);

  // - push -
  unsigned idx = 0;
  do {
    ui_fixed_array_s_push(&fixed_array_0,idx);
  } while(++idx < 10);

  buffer.used = 0;
  ui_fixed_array_s_to_string(&fixed_array_0,&buffer);
  cassert(strncmp(buffer.data,"[0,1,2,3,4,5,6,7,8,9]",buffer.used) == 0);
}/*}}}*/

void test_array_all()
{/*{{{*/
  test_array_init();
  test_array_clear();
  test_array_push();
  test_array_flush();
  test_array_get_idx();
  test_array_compare();

  test_array_dynamic_init();
  test_array_dynamic_set();
  test_array_dynamic_push();
  test_array_dynamic_flush();
  test_array_dynamic_get_idx();
  test_array_dynamic_fill();
  test_array_dynamic_compare();

  test_array_fixed_init();
  test_array_fixed_clear();
  test_array_fixed_push();
}/*}}}*/

/*
 * global methods
 */

int main(int argc, char **argv)
{/*{{{*/
  if (argc > 1)
  {
    int arg_idx = 1;
    do {
      if (strcmp(argv[arg_idx],"init") == 0)
      {
        test_array_init();
      }
      else if (strcmp(argv[arg_idx],"clear") == 0)
      {
        test_array_clear();
      }
      else if (strcmp(argv[arg_idx],"push") == 0)
      {
        test_array_push();
      }
      else if (strcmp(argv[arg_idx],"flush") == 0)
      {
        test_array_flush();
      }
      else if (strcmp(argv[arg_idx],"compare") == 0)
      {
        test_array_get_idx();
      }
      else if (strcmp(argv[arg_idx],"compare") == 0)
      {
        test_array_compare();
      }
      else if (strcmp(argv[arg_idx],"dynamic_init") == 0)
      {
        test_array_dynamic_init();
      }
      else if (strcmp(argv[arg_idx],"dynamic_set") == 0)
      {
        test_array_dynamic_set();
      }
      else if (strcmp(argv[arg_idx],"dynamic_push") == 0)
      {
        test_array_dynamic_push();
      }
      else if (strcmp(argv[arg_idx],"dynamic_flush") == 0)
      {
        test_array_dynamic_flush();
      }
      else if (strcmp(argv[arg_idx],"dynamic_get_idx") == 0)
      {
        test_array_dynamic_get_idx();
      }
      else if (strcmp(argv[arg_idx],"dynamic_fill") == 0)
      {
        test_array_dynamic_fill();
      }
      else if (strcmp(argv[arg_idx],"dynamic_compare") == 0)
      {
        test_array_dynamic_compare();
      }
      else if (strcmp(argv[arg_idx],"all") == 0)
      {
        test_array_all();
      }
      else if (strcmp(argv[arg_idx],"fixed_init") == 0)
      {
        test_array_fixed_init();
      }
      else if (strcmp(argv[arg_idx],"fixed_clear") == 0)
      {
        test_array_fixed_clear();
      }
      else if (strcmp(argv[arg_idx],"fixed_push") == 0)
      {
        test_array_fixed_push();
      }
      else
      {
        // - ERROR -
        fprintf(stderr,"unrecognized test argument\n");
        return 1;
      }
    } while(++arg_idx < argc);
  }

  return 0;
}/*}}}*/


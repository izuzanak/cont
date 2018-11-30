
@begin
include "queue_test.h"
@end

/*
 * methods of generated structures
 */


// -- ui_queue_s --
@begin
methods ui_queue_s
@end

// -- ui_queues_s --
@begin
methods ui_queues_s
@end

// -- ui_fixed_queue_s --
@begin
methods ui_fixed_queue_s
@end

void test_queue_init()
{/*{{{*/
  printf("test_queue_init\n");

  CONT_INIT_CLEAR(bc_array_s,buffer);

  // - init -
  CONT_INIT_CLEAR(ui_queue_s,queue_0);

  buffer.used = 0;
  ui_queue_s_to_string(&queue_0,&buffer);
  cassert(strncmp(buffer.data,"[]",buffer.used) == 0);

  // - init_size -
  CONT_CLEAR(ui_queue_s,queue_1);
  ui_queue_s_init_size(&queue_1,10);
  cassert(queue_1.used == 0 && queue_1.size == 10);
}/*}}}*/

void test_queue_clear()
{/*{{{*/
  printf("test_queue_clear\n");

  CONT_INIT_CLEAR(bc_array_s,buffer);

  // - init_size -
  CONT_CLEAR(ui_queue_s,queue_0);
  ui_queue_s_init_size(&queue_0,10);

  // - insert -
  unsigned idx = 0;
  do {
    ui_queue_s_insert(&queue_0,idx);
  } while(++idx < 10);

  buffer.used = 0;
  ui_queue_s_to_string(&queue_0,&buffer);
  cassert(strncmp(buffer.data,"[0,1,2,3,4,5,6,7,8,9]",buffer.used) == 0);
  cassert(queue_0.used == 10 && queue_0.size == 10);

  // - clear -
  ui_queue_s_clear(&queue_0);
  cassert(queue_0.used == 0 && queue_0.size == 0);
}/*}}}*/

void test_queue_next()
{/*{{{*/
  printf("test_queue_next\n");

  CONT_INIT_CLEAR(bc_array_s,buffer);

  // - init_size -
  CONT_CLEAR(ui_queue_s,queue_0);
  ui_queue_s_init_size(&queue_0,10);

  // - insert -
  unsigned idx = 0;
  do {
    ui_queue_s_insert(&queue_0,idx);
  } while(++idx < 10);

  buffer.used = 0;
  ui_queue_s_to_string(&queue_0,&buffer);
  cassert(strncmp(buffer.data,"[0,1,2,3,4,5,6,7,8,9]",buffer.used) == 0);
  cassert(queue_0.begin == 0 && queue_0.used == 10 && queue_0.size == 10);

  // - insert -
  // - next -
  idx = 0;
  do {
    ui_queue_s_insert(&queue_0,
      ui_queue_s_next(&queue_0));
  } while(++idx < 5);

  buffer.used = 0;
  ui_queue_s_to_string(&queue_0,&buffer);
  cassert(strncmp(buffer.data,"[5,6,7,8,9,0,1,2,3,4]",buffer.used) == 0);
  cassert(queue_0.begin == 5 && queue_0.used == 10 && queue_0.size == 10);

  // - insert -
  idx = 0;
  do {
    ui_queue_s_insert(&queue_0,idx + 10);
  } while(++idx < 5);

  buffer.used = 0;
  ui_queue_s_to_string(&queue_0,&buffer);
  cassert(strncmp(buffer.data,"[5,6,7,8,9,0,1,2,3,4,10,11,12,13,14]",buffer.used) == 0);
  cassert(queue_0.begin == 0);
  cassert(queue_0.used == 15);
  cassert(queue_0.size >= 15);
}/*}}}*/

void test_queue_flush()
{/*{{{*/
  printf("test_queue_flush\n");

  CONT_INIT_CLEAR(bc_array_s,buffer);

  // - init_size -
  CONT_CLEAR(ui_queue_s,queue_0);
  ui_queue_s_init_size(&queue_0,25);

  // - insert -
  unsigned idx = 0;
  do {
    ui_queue_s_insert(&queue_0,idx);
  } while(++idx < 10);

  buffer.used = 0;
  ui_queue_s_to_string(&queue_0,&buffer);
  cassert(strncmp(buffer.data,"[0,1,2,3,4,5,6,7,8,9]",buffer.used) == 0);
  cassert(queue_0.begin == 0 && queue_0.used == 10 && queue_0.size == 25);

  // - insert -
  // - next -
  idx = 0;
  do {
    ui_queue_s_insert(&queue_0,
      ui_queue_s_next(&queue_0));
  } while(++idx < 5);

  buffer.used = 0;
  ui_queue_s_to_string(&queue_0,&buffer);
  cassert(strncmp(buffer.data,"[5,6,7,8,9,0,1,2,3,4]",buffer.used) == 0);
  cassert(queue_0.begin == 5 && queue_0.used == 10 && queue_0.size == 25);

  // - flush -
  ui_queue_s_flush(&queue_0);

  buffer.used = 0;
  ui_queue_s_to_string(&queue_0,&buffer);
  cassert(strncmp(buffer.data,"[5,6,7,8,9,0,1,2,3,4]",buffer.used) == 0);
  cassert(queue_0.begin == 0 && queue_0.used == 10 && queue_0.size == 10);
}/*}}}*/

void test_queue_swap()
{/*{{{*/
  printf("test_queue_swap\n");

  CONT_INIT_CLEAR(bc_array_s,buffer);

  // - init_size -
  CONT_INIT_CLEAR(ui_queue_s,queue_0);
  CONT_INIT_CLEAR(ui_queue_s,queue_1);
  CONT_INIT_CLEAR(ui_queue_s,queue_2);

  // - insert -
  unsigned idx = 0;
  do {
    ui_queue_s_insert(&queue_0,idx);
  } while(++idx < 10);

  // - copy -
  ui_queue_s_copy(&queue_1,&queue_0);
  ui_queue_s_copy(&queue_2,&queue_0);

  // - compare -
  cassert(ui_queue_s_compare(&queue_0,&queue_1));
  cassert(ui_queue_s_compare(&queue_0,&queue_2));

  buffer.used = 0;
  ui_queue_s_to_string(&queue_0,&buffer);
  ui_queue_s_to_string(&queue_1,&buffer);
  cassert(strncmp(buffer.data,"[0,1,2,3,4,5,6,7,8,9][0,1,2,3,4,5,6,7,8,9]",buffer.used) == 0);

  // - insert -
  // - next -
  idx = 0;
  do {
    ui_queue_s_insert(&queue_0,
      ui_queue_s_next(&queue_0));
  } while(++idx < 5);

  buffer.used = 0;
  ui_queue_s_to_string(&queue_0,&buffer);
  ui_queue_s_to_string(&queue_1,&buffer);
  cassert(strncmp(buffer.data,"[5,6,7,8,9,0,1,2,3,4][0,1,2,3,4,5,6,7,8,9]",buffer.used) == 0);
  cassert(ui_queue_s_compare(&queue_1,&queue_2));

  // - swap -
  ui_queue_s_swap(&queue_0,&queue_1);

  buffer.used = 0;
  ui_queue_s_to_string(&queue_0,&buffer);
  ui_queue_s_to_string(&queue_1,&buffer);
  cassert(strncmp(buffer.data,"[0,1,2,3,4,5,6,7,8,9][5,6,7,8,9,0,1,2,3,4]",buffer.used) == 0);
  cassert(ui_queue_s_compare(&queue_0,&queue_2));
}/*}}}*/

void test_queue_copy_resize()
{/*{{{*/
  printf("test_queue_copy_resize\n");

  CONT_INIT_CLEAR(bc_array_s,buffer);

  // - init_size -
  CONT_INIT_CLEAR(ui_queue_s,queue_0);
  CONT_INIT_CLEAR(ui_queue_s,queue_1);
  CONT_INIT_CLEAR(ui_queue_s,queue_2);

  // - insert -
  unsigned idx = 0;
  do {
    ui_queue_s_insert(&queue_0,idx);
  } while(++idx < 10);

  // - copy -
  ui_queue_s_copy(&queue_1,&queue_0);
  ui_queue_s_copy(&queue_2,&queue_0);

  // - next -
  idx = 0;
  do {
    cassert(ui_queue_s_next(&queue_0) == idx);
    cassert(ui_queue_s_next(&queue_1) == idx);
    cassert(ui_queue_s_next(&queue_2) == idx);
  } while(++idx < 5);

  buffer.used = 0;
  ui_queue_s_to_string(&queue_0,&buffer);
  ui_queue_s_to_string(&queue_1,&buffer);
  ui_queue_s_to_string(&queue_2,&buffer);
  cassert(strncmp(buffer.data,"[5,6,7,8,9][5,6,7,8,9][5,6,7,8,9]",buffer.used) == 0);

  // - copy_resize -
  ui_queue_s_copy_resize(&queue_0,100);
  ui_queue_s_copy_resize(&queue_1,queue_1.used + 3);
  ui_queue_s_copy_resize(&queue_2,queue_2.used);

  buffer.used = 0;
  ui_queue_s_to_string(&queue_0,&buffer);
  ui_queue_s_to_string(&queue_1,&buffer);
  ui_queue_s_to_string(&queue_2,&buffer);
  cassert(strncmp(buffer.data,"[5,6,7,8,9][5,6,7,8,9][5,6,7,8,9]",buffer.used) == 0);
  cassert(queue_0.size == 100);
  cassert(queue_1.size == queue_1.used + 3);
  cassert(queue_2.size == queue_2.used);

  // - insert -
  idx = 0;
  do {
    ui_queue_s_insert(&queue_0,idx);
    ui_queue_s_insert(&queue_1,idx);
    ui_queue_s_insert(&queue_2,idx);
  } while(++idx < 3);


  buffer.used = 0;
  ui_queue_s_to_string(&queue_0,&buffer);
  ui_queue_s_to_string(&queue_1,&buffer);
  ui_queue_s_to_string(&queue_2,&buffer);
  cassert(strncmp(buffer.data,"[5,6,7,8,9,0,1,2][5,6,7,8,9,0,1,2][5,6,7,8,9,0,1,2]",buffer.used) == 0);
  cassert(queue_0.size == 100);
  cassert(queue_1.size == queue_1.used);
  cassert(queue_2.size >= queue_2.used);
}/*}}}*/

void test_queue_compare()
{/*{{{*/
  printf("test_queue_compare\n");

  CONT_INIT_CLEAR(bc_array_s,buffer);

  // - init_size -
  CONT_INIT_CLEAR(ui_queue_s,queue_0);
  CONT_INIT_CLEAR(ui_queue_s,queue_1);
  CONT_INIT_CLEAR(ui_queue_s,queue_2);

  // - insert -
  unsigned idx = 0;
  do {
    ui_queue_s_insert(&queue_0,idx);
  } while(++idx < 5);

  // - copy -
  ui_queue_s_copy(&queue_1,&queue_0);
  ui_queue_s_copy(&queue_2,&queue_0);

  // - compare -
  cassert(ui_queue_s_compare(&queue_0,&queue_1));
  cassert(ui_queue_s_compare(&queue_0,&queue_2));

  // - next -
  cassert(ui_queue_s_next(&queue_1) == 0);
  cassert(!ui_queue_s_compare(&queue_0,&queue_1));

  // - insert -
  ui_queue_s_insert(&queue_2,5);
  cassert(!ui_queue_s_compare(&queue_0,&queue_2));

  buffer.used = 0;
  ui_queue_s_to_string(&queue_0,&buffer);
  ui_queue_s_to_string(&queue_1,&buffer);
  ui_queue_s_to_string(&queue_2,&buffer);
  cassert(strncmp(buffer.data,"[0,1,2,3,4][1,2,3,4][0,1,2,3,4,5]",buffer.used) == 0);
}/*}}}*/

void test_queue_dynamic_init()
{/*{{{*/
  printf("test_queue_dynamic_init\n");

  CONT_INIT_CLEAR(bc_array_s,buffer);

  // - init -
  CONT_INIT_CLEAR(ui_queues_s,queues_0);

  buffer.used = 0;
  ui_queues_s_to_string(&queues_0,&buffer);
  cassert(strncmp(buffer.data,"[]",buffer.used) == 0);

  // - init_size -
  CONT_CLEAR(ui_queues_s,queues_1);
  ui_queues_s_init_size(&queues_1,10);
  cassert(queues_1.used == 0 && queues_1.size == 10);
}/*}}}*/

void test_queue_dynamic_clear()
{/*{{{*/
  printf("test_queue_dynamic_clear\n");

  CONT_INIT_CLEAR(bc_array_s,buffer);

  // - init_size -
  CONT_INIT_CLEAR(ui_queue_s,queue_0);

  // - insert -
  unsigned idx = 0;
  do {
    ui_queue_s_insert(&queue_0,idx);
  } while(++idx < 5);

  CONT_INIT_CLEAR(ui_queues_s,queues_0);

  // - insert -
  idx = 0;
  do {
    ui_queues_s_insert(&queues_0,&queue_0);
  } while(++idx < 3);

  // - insert_blank -
  do {
    ui_queues_s_insert_blank(&queues_0);
  } while(++idx < 5);

  buffer.used = 0;
  ui_queues_s_to_string(&queues_0,&buffer);
  cassert(strncmp(buffer.data,"[[0,1,2,3,4],[0,1,2,3,4],[0,1,2,3,4],[],[]]",buffer.used) == 0);

  // - clear -
  ui_queues_s_clear(&queues_0);
  cassert(queues_0.used == 0 && queues_0.size == 0);
}/*}}}*/

void test_queue_dynamic_next()
{/*{{{*/
  printf("test_queue_dynamic_next\n");

  // FIXME TODO continue ...
}/*}}}*/

void test_queue_dynamic_flush()
{/*{{{*/
  printf("test_queue_dynamic_flush\n");

  // FIXME TODO continue ...
}/*}}}*/

void test_queue_dynamic_swap()
{/*{{{*/
  printf("test_queue_dynamic_swap\n");

  // FIXME TODO continue ...
}/*}}}*/

void test_queue_dynamic_copy_resize()
{/*{{{*/
  printf("test_queue_dynamic_copy_resize\n");

  // FIXME TODO continue ...
}/*}}}*/

void test_queue_dynamic_compare()
{/*{{{*/
  printf("test_queue_dynamic_compare\n");

  // FIXME TODO continue ...
}/*}}}*/

void test_queue_all()
{/*{{{*/
  test_queue_init();
  test_queue_clear();
  test_queue_next();
  test_queue_flush();
  test_queue_swap();
  test_queue_copy_resize();
  test_queue_compare();

  test_queue_dynamic_init();
  test_queue_dynamic_clear();
  test_queue_dynamic_next();
  test_queue_dynamic_flush();
  test_queue_dynamic_swap();
  test_queue_dynamic_copy_resize();
  test_queue_dynamic_compare();
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
        test_queue_init();
      }
      else if (strcmp(argv[arg_idx],"clear") == 0)
      {
        test_queue_clear();
      }
      else if (strcmp(argv[arg_idx],"next") == 0)
      {
        test_queue_next();
      }
      else if (strcmp(argv[arg_idx],"flush") == 0)
      {
        test_queue_flush();
      }
      else if (strcmp(argv[arg_idx],"swap") == 0)
      {
        test_queue_swap();
      }
      else if (strcmp(argv[arg_idx],"copy_resize") == 0)
      {
        test_queue_copy_resize();
      }
      else if (strcmp(argv[arg_idx],"compare") == 0)
      {
        test_queue_compare();
      }
      else if (strcmp(argv[arg_idx],"dynamic_init") == 0)
      {
        test_queue_dynamic_init();
      }
      else if (strcmp(argv[arg_idx],"dynamic_clear") == 0)
      {
        test_queue_dynamic_clear();
      }
      else if (strcmp(argv[arg_idx],"dynamic_next") == 0)
      {
        test_queue_dynamic_next();
      }
      else if (strcmp(argv[arg_idx],"dynamic_flush") == 0)
      {
        test_queue_dynamic_flush();
      }
      else if (strcmp(argv[arg_idx],"dynamic_swap") == 0)
      {
        test_queue_dynamic_swap();
      }
      else if (strcmp(argv[arg_idx],"dynamic_copy_resize") == 0)
      {
        test_queue_dynamic_copy_resize();
      }
      else if (strcmp(argv[arg_idx],"dynamic_compare") == 0)
      {
        test_queue_dynamic_compare();
      }
      else if (strcmp(argv[arg_idx],"all") == 0)
      {
        test_queue_all();
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


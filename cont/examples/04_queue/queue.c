
@begin
include "queue.h"
@end

/*
 * methods of generated structures
 */

// -- rec_queue_s --
@begin
   methods rec_queue_s
@end

/*
 * global methods
 */

void print_queue(rec_queue_s *rec_queue,const char *name)
{
  printf("%s.size:  %u\n",name,rec_queue->size);
  printf("%s.used:  %u\n",name,rec_queue->used);
  printf("%s.begin: %u\n",name,rec_queue->begin);
  printf("%s: ",name);

  if (rec_queue->used > 0)
  {
    unsigned idx = rec_queue->begin;
    unsigned idx_end = (idx + rec_queue->used) % rec_queue->size;
    do {
      record_s *rec = rec_queue->data + idx;
      printf("{%u,%u}",rec->index,rec->value);

      idx = (idx + 1) % rec_queue->size;
    } while(idx != idx_end); 
  }

  printf("\n");
  printf("\n");
}

int main(int argc, char **argv)
{
  record_s rec;
  record_s_init(&rec);
  record_s_set(&rec,1,1);

  printf("--- CREATE AND FILL RECORDS QUEUE ---\n");
  rec_queue_s queue0;
#ifdef FIXED_BUFFER
  rec_queue_s_init_buffer(&queue0,10,alloca(10*sizeof(record_s)));
#else
  rec_queue_s_init_size(&queue0,10);
#endif

  unsigned idx = 0;
  do {
    rec.value = idx;
    rec_queue_s_insert(&queue0,&rec);
  } while(++idx < 5);

  print_queue(&queue0,"queue0");

  printf("--- RETRIEVE RECORDS FROM QUEUE ---\n");
  idx = 0;
  do {
    rec_queue_s_next(&queue0);
  } while(++idx < 3);

  print_queue(&queue0,"queue0");

  printf("--- INSERT NEW RECORDS TO QUEUE ---\n");

  idx = 0;
  do {
    rec.value = idx;
    rec_queue_s_insert(&queue0,&rec);
  } while(++idx < 7);

  print_queue(&queue0,"queue0");

  printf("--- CREATE NEW EMPTY QUEUE ---\n");
  rec_queue_s queue1;
#ifdef FIXED_BUFFER
  rec_queue_s_init_buffer(&queue1,10,alloca(10*sizeof(record_s)));
#else
  rec_queue_s_init(&queue1);
#endif

  print_queue(&queue0,"queue0");
  print_queue(&queue1,"queue1");

  printf("--- COMPARE QUEUE CONTENT ---\n");
  printf("rec_queue_s_compare(&queue0,&queue1): %s\n",rec_queue_s_compare(&queue0,&queue1) ? "TRUE" : "FALSE");
  printf("\n");

  printf("--- ASSIGN QUEUE CONTENT ---\n");
  rec_queue_s_copy(&queue1,&queue0);

  print_queue(&queue0,"queue0");
  print_queue(&queue1,"queue1");

  printf("--- COMPARE QUEUE CONTENT ---\n");
  printf("rec_queue_s_compare(&queue0,&queue1): %s\n",rec_queue_s_compare(&queue0,&queue1) ? "TRUE" : "FALSE");
  printf("\n");

  printf("--- CLEAR QUEUE CONTENT ---\n");
  rec_queue_s_clear(&queue0);

  print_queue(&queue0,"queue0");

  rec_queue_s_clear(&queue1);
  rec_queue_s_clear(&queue0);
  record_s_clear(&rec);

  return 0;
}


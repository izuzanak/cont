
@begin
include "list.h"
@end

/*
 * methods of generated structures
 */

// -- rec_list_s --
@begin
   methods rec_list_s
@end

/*
 * global methods
 */

void print_list(rec_list_s *rec_list,const char *name)
{
  printf("%s.size:  %u\n",name,rec_list->size);
  printf("%s.used:  %u\n",name,rec_list->used);
  printf("%s.free_idx:  %u\n",name,rec_list->free_idx);
  printf("%s.first_idx: %u\n",name,rec_list->first_idx);
  printf("%s.last_idx:  %u\n",name,rec_list->last_idx);
  printf("%s: ",name);

  if (rec_list->first_idx != c_idx_not_exist)
  {
    unsigned idx = rec_list->first_idx;
    do {
      record_s *rec = rec_list_s_at(rec_list,idx);
      printf("{%u,%u}",rec->index,rec->value);

      idx = rec_list_s_next_idx(rec_list,idx);
    } while(idx != c_idx_not_exist);
  }

  printf("\n");
  printf("\n");
}

int main(int argc, char **argv)
{
  record_s rec;
  record_s_init(&rec);
  record_s_set(&rec,1,1);

  rec_list_s list0;
  rec_list_s_init(&list0);

  print_list(&list0,"list0");

  printf("--- APPEND NEW RECORDS TO LIST ---\n");

  unsigned idx = 0;
  do {
    rec.value = idx;
    rec_list_s_append(&list0,&rec);
  } while(++idx < 5);

  print_list(&list0,"list0");

  printf("--- PREPEND NEW RECORDS TO LIST ---\n");

  idx = 0;
  do {
    rec.value = idx;
    rec_list_s_prepend(&list0,&rec);
  } while(++idx < 5);

  print_list(&list0,"list0");

  printf("--- REMOVE RECORDS FROM LIST ---\n");

  unsigned count = 0;
  do {
    rec_list_s_remove(&list0,list0.first_idx);
  } while(++count < 5);

  print_list(&list0,"list0");

  printf("--- INSERT AFTER FIRST RECORD ---\n");

  idx = 0;
  do {
    rec.value = idx;
    rec_list_s_insert_after(&list0,list0.first_idx,&rec);
  } while(++idx < 2);

  print_list(&list0,"list0");

  printf("--- INSERT BEFORE LAST RECORD ---\n");

  idx = 0;
  do {
    rec.value = idx;
    rec_list_s_insert_before(&list0,list0.last_idx,&rec);
  } while(++idx < 2);

  print_list(&list0,"list0");

  printf("--- CREATE NEW EMPTY LIST ---\n");
  rec_list_s list1;
  rec_list_s_init(&list1);

  print_list(&list0,"list0");
  print_list(&list1,"list1");

  printf("--- COMPARE LIST CONTENT ---\n");
  printf("rec_list_s_compare(&list0,&list1): %s\n",rec_list_s_compare(&list0,&list1) ? "TRUE" : "FALSE");
  printf("\n");

  printf("--- ASSIGN LIST CONTENT ---\n");
  rec_list_s_copy(&list1,&list0);

  print_list(&list0,"list0");
  print_list(&list1,"list1");

  printf("--- COMPARE LIST CONTENT ---\n");
  printf("rec_list_s_compare(&list0,&list1): %s\n",rec_list_s_compare(&list0,&list1) ? "TRUE" : "FALSE");
  printf("\n");

  rec_list_s_clear(&list1);
  rec_list_s_clear(&list0);
  record_s_clear(&rec);

  return 0;
}


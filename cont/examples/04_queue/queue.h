
#ifndef __QUEUE_H
#define __QUEUE_H

@begin
include "struct.h"
@end

/*
 * definition of generated structures
 */

// -- rec_queue_s --
@begin
   queue<record_s> rec_queue_s;
@end

/*
 * inline methods of generated structures
 */

// -- rec_queue_s --
@begin
   inlines rec_queue_s
@end

/*
 * definition of global methods
 */

void print_queue(rec_queue_s *rec_queue,const char *name);

#endif


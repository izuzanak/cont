
#ifndef __QUEUE_TEST_H
#define __QUEUE_TEST_H

@begin
include "basic.h"
@end

/*
 * definition of generated structures
 */

// -- ui_queue_s --
@begin
queue<ui> ui_queue_s;
@end

// -- ui_queues_s --
@begin
queue<ui_queue_s> ui_queues_s;
@end

// -- ui_fixed_queue_s --
@begin
queue<ui> ui_fixed_queue_s;
@end

/*
 * inline methods of generated structures
 */

// -- ui_queue_s --
@begin
inlines ui_queue_s
@end

// -- ui_queues_s --
@begin
inlines ui_queues_s
@end

// -- ui_fixed_queue_s --
@begin
inlines ui_fixed_queue_s
@end

#endif


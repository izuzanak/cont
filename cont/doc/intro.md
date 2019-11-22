Introduction
============

This document describes tools and principles used for generating complex data
types in C programming language.

Container generator
===================

Data type classification
------------------------

Generated data types are classified to three basic classes:

-   `basic` - Basic data types. Simple basic data types of language C, that are
    not composed from other data types and do not manage any external
    resources. For example integer number, floating point number, single
    character etc.

-   `static` - Static data types. Static data types are composed from other
    basic or static data types. Objects of static data types do not manage any
    external resources.

-   `dynamic` - Dynamic data types. Objects of dynamic data types manage some
    external resource, that must be released after its usage.

### Basic data types - basic

Interface to basic data types is following:

        void <NAME>_to_string(const <NAME> *this,bc_array_s *a_trg);

Optional function, that writes string representation of object value
to character buffer `a_trg`. This function is used mainly for debugging
output.

        void <NAME>_to_json(const <NAME> *this,bc_array_s *a_trg);

Optional function, that writes string representation of object value
to character buffer `a_trg`. This function is used for generating of JSON
data representation.

        int <NAME>_from_var(<NAME> *this,var_s a_var);

Optional function, initializing content of object from dynamically typed
value `a_var`. Function returns `0` if object was successfully initialized.

### Static data types - static

Aside interface introduced for basic data types, static data types must
implement following:

        int <NAME>_compare(const <NAME> *this,const <NAME> *a_second);

Function compares two objects of same data type and returns following result:

-   `0` - if compared objects are different.

-   `1` - if compared objects are equal.

### Dynamic data types - dynamic

Aside interface introduced for basic and static data types, dynamic data
types must implement following:

        void <NAME>_init(<NAME> *this);

Function initializing object. This function transforms object from undefined
state to initialized (empty) state. Object in initialized state has no
allocated resources.

        void <NAME>_clear(<NAME> *this);

Function releasing resources managed by object, and transformation of object to
initial (empty) state. This function can be called on object in defined state.

        void <NAME>_swap(<NAME> *this,<NAME> *a_second);

Function swaps data of two objects of same type. Function can be used on
uninitialized objects (data are not important, memories of two objects are
swapped).

        void <NAME>_copy(const <NAME> *this,const <NAME> *a_src);

Function copies content of source object `a_src` to object `this`.
Copy is performed as deep copy, both object will contain same data.
Function `<NAME>_compare` called on these objects must return value `1`.

Data types generation principle
-------------------------------

Generator traverse source files of compilation unit in file include order, and
generates file on its output. Generator keeps in-memory description of all so
far defined or generated data types. Descriptions of already defined data types
are used for generation of new data types, that is based on marks found in
input source files.

Basic data types can be defined by keyword `define`, or predefined basic data
types can be used:

-   `bc`, `char`

-   `sc`, `signed_char`

-   `uc`, `unsigned_char`

-   `si`, `short`, `short_int`

-   `usi`, `unsigned_short`, `unsigned_short_int`

-   `bi`, `int`

-   `ui`, `unsigned`, `unsigned_int`

-   `li`, `long`, `long_int`

-   `uli`, `unsigned_long`, `unsigned_long_int`

-   `lli`, `long_long`, `long_long_int`

-   `ulli`, `unsigned_long_long`, `unsigned_long_long_int`

-   `bf`, `float`

-   `bd`, `double`

-   `ld`, `long_double`

Syntax of generator marks
-------------------------

Marks intended for code generator are enclosed between keywords `@begin` and
`@end`.

Example:

        @begin
          define uint16_t basic
          define uint32_t basic
        @end

Generator recognizes following basic keywords:

-   `include` - identifies file, that should be included to compilation unit.

-   `define` - defines existing data type for generator.

-   `inlines` - generates inline functions of data type.

-   `methods` - generates functions of data type.

### Inclusion of file - include

File that should be included to compilation unit is identified by keyword
`include`, that is followed by string containing file name. Generator
recursively traverses included files and produces source file on its output.

Syntax is following:

        "include" <STRING>

Example:

        @begin
          include "cl_linux.h"
          include "cl_var.h"
        @end

### Definition of existing data type - define

Keyword `define` defines existing data type and its basic parameters for
generator.

Syntax is following:

        "define" <NAME> <MODIFIERS>

, where:

-   `<NAME>` - is name of defined data type.

-   `<MODIFIERS>` - are modifiers describing defined data type. Modifiers can
    contain following values:

    -   `basic` - basic data type.

    -   `static` - static data type.

    -   `dynamic` - dynamic data type.

    -   `flushable` - data type allows flushing of used dynamically allocated
        memory to minimal size needed to keep actual object content.

Example of basic types definition:

        @begin
          define uint16_t basic
          define uint32_t basic
        @end

Example of dynamic data type definition (file descriptor):

        typedef int fd_s;
        @begin
          define fd_s dynamic
        @end

For dynamic data type `fd_s` following functions must be implemented:

        void fd_s_init(fd_s *this);
        void fd_s_clear(fd_s *this);
        void fd_s_swap(fd_s *this,fd_s *a_second);
        void fd_s_copy(const fd_s *this,const fd_s *a_src);
        int fd_s_compare(const fd_s *this,const fd_s *a_second);

### Generating of container definition

Syntax is following:

        <GENERATOR> <ATTRIBUTES> ";"
     
        <ATTRIBUTE> -> <NAME>
        <ATTRIBUTE> -> "<" <ELEMENTS> ">"
        <ATTRIBUTE> -> "options" "(" <OPTIONS> ")"
        <ATTRIBUTE> -> "additions" "{" <CODE> "}"
     
        <ELEMENT> -> <CONTAINED_TYPE>
        <ELEMENT> -> <MEMBER_TYPE> ":" <MEMBER_NAME>

, where:

-   `<GENERATOR>` - is name of generator used for generating od new data type.
    Following generators are recognized:

    -   `struct` - structure containing named members.

    -   `array` - dynamic array of elements of contained data type.

    -   `queue` - dynamic queue of members of contained data type.

    -   `list` - linked list of members of contained data type.

    -   `rb_tree` - balanced binary tree.

-   `<NAME>` - name of generated data type.

-   `<CONTAINED_TYPE>` - name of contained data type.

-   `<MEMBER_TYPE>` - name of structure member data type.

-   `<MEMBER_NAME>` - name of structure member.

Example:

        @begin
          array<char> char_array_s;
        @end

Example describes creation of new data type `char_array_s` representing dynamic
array of characters (`char`). Structure describing new data type is
simultaneously generated to output source file. New data type can be used for
definition of following data types:

        @begin
          queue<char_array_s> char_array_queue_s;
        @end

Example:

        @begin
          struct
          <
          unsigned:id
          string_s:name
          char_array_queue_s:queue
          >
          cs_dummy_s;
        @end

### Generating of data type inline functions - inline

Keyword `inlines` generates inline functions of data type to output source file.
Declarations of generated functions were generated by definition of data type.
Inline functions of data type should be emplaced in header file containing
definition of data type.

Syntax is following:

        "inlines" <NAME>

, where:

-   `<NAME>` - is name of defined data type.

Example:

        @begin
          inlines char_array_s
        @end

### Generating of data type functions - methods

Keyword `methods` generates functions of data type to output source file.
Declarations of generated functions were generated by definition of data type.
Functions of data type should be emplaced in source file including header file
containing definition of data type.

Syntax is following:

        "methods" <NAME>

, where:

-   `<NAME>` - is name of defined data type.

Example:

        @begin
          methods char_array_s
        @end

Generators
==========

In this chapter individual generators are described in detail.

  **Generator**  |**Description**                                          |**Reference**
  ---------------|---------------------------------------------------------|-----------------------------------------------------------------
  `struct`       |Structure of named members.                              |[struct](#structure---struct)
  `array`        |Dynamic array of objects.                                |[array](#dynamic-array---array)
  `queue`        |Dynamic queue of objects.                                |[queue](#dynamic-queue---queue)
  `list`         |Linked list of elements.                                 |[list](#linked-list---list)
  `rb_tree`      |Balanced binary tree.                                    |[rb_tree](#balanced-binary-tree---rb_tree)

Functions shared by generated data types
----------------------------------------

Description of functions performing identical actions for all generated data
types follows.

### Function ..._init

        void <NAME>_init(<NAME> *this);

Function transforms object from undefined state to initialized (empty) state.
This function should be called only with objects in undefined state.

### Function ..._init_size

        void <NAME>_init_size(<NAME> *this,unsigned a_size);

Function transforms object from undefined state to initialized state, and
allocates memory for `a_size` contained objects. This function should be called
only with objects in undefined state.

### Function ..._clear

        void <NAME>_clear(<NAME> *this);

Function release object resources, and transforms object to initialized (empty)
state.

### Function ..._flush

        void <NAME>_flush(<NAME> *this);

Function truncates size of allocated object memory to minimal size needed to
keep actual content of object.

### Function ..._flush_all

        void <NAME>_flush_all(<NAME> *this);

Function truncates size of allocated object memory to minimal size needed to
keep actual content of object. Function `flush_all` is called recursively on
contained objects if any.

### Function ..._swap

        void <NAME>_swap(<NAME> *this,<NAME> *a_second);

Function swaps data of two objects of same type. Function can be used on
uninitialized objects (data are not important, memories of two objects are
swapped).

### Function ..._at

        <TYPE> *<NAME>_at(const <NAME> *this,unsigned a_idx);

Function returns pointer to contained object at position `a_idx` in
generated container.

### Function ..._copy_resize

        void <NAME>_copy_resize(<NAME> *this,unsigned a_size);

Function adjusts size of memory allocated by object. Requested count of objects
`a_size` must be greater or equal as count of actually used objects.

### Function ..._get_idx

        unsigned <NAME>_get_idx(const <NAME> *this,<TYPE> a_value);
        unsigned <NAME>_get_idx(const <NAME> *this,const <TYPE> *a_value);

Function returns position of object with value `a_value`.

### Function ..._copy

        void <NAME>_copy(<NAME> *this,const <NAME> *a_src);

Function updates object data according to data of object `a_src`.

### Function ..._compare

        int <NAME>_compare(const <NAME> *this,const <NAME> *a_second);

Function compares two objects of same data type and returns following result:

-   `0` - if compared objects are different.

-   `1` - if compared objects are equal.

### Function ..._init_buffer

        void <NAME>_init_buffer(<NAME> *this,unsigned a_size,<TYPE> *a_data);

Function transforms object from undefined state to initialized (empty) state.
Function also sets buffer for container stored in fixed size memory.

### Function ..._set_buffer

        void <NAME>_set_buffer(<NAME> *this,unsigned a_size,<TYPE> *a_data);

Function sets buffer for container stored in fixed size memory.

Structure - struct
------------------

Generator of structured record of named member values in compact memory
block.

        struct <NAME>
        {
          <TYPE_0> <MEMBER_0>;
          ...
        };

List of function generated by `struct` follows:

  **Function**        |**Category**   |**Complexity** |**Description**
  --------------------|---------------|---------------|---------------------------------
  `struct_init`       |               |O(1)           |[struct_init](#function-_init)
  `struct_clear`      |               |O(1)           |[struct_clear](#function-_clear)
  `struct_set`        |`set`          |O(1)           |[struct_set](#function-struct_set)
  `struct_flush_all`  |               |O(1)           |[struct_flush_all](#function-_flush_all)
  `struct_swap`       |               |O(1)           |[struct_swap](#function-_swap)
  `struct_copy`       |               |O(1)           |[struct_copy](#function-_copy)
  `struct_compare`    |               |O(1)           |[struct_compare](#function-_compare)

### Example of definition and usage

        @begin
          struct < string_s:name string_s:surname ui:age > person_s;
          struct < ui:id person_s:person ui:wage > employee_s;
        @end

### Function struct_set

        void <NAME>_set(<NAME> *this,...);

Function updates content of structure members according to content of function
arguments.

Dynamic array - array
----------------------

Generator of dynamic array keeping objects in continuous memory block. Dynamic
array allocates memory block of `size` objects, from which `used` objects are
used in one point in time.

        struct <NAME>
        {
          unsigned size;
          unsigned used;
          <TYPE> *data;
        };

, where:

-   `size` - is count of objects, that is possible to store to allocated
    memory.

-   `used` - is count of objects stored in dynamic array (used part of
    allocated memory).

-   `data` - is pointer to first object stored in dynamic array.

List of functions generated by `array` follows:

  **Function**         |**Category**          |**Complexity** |**Description**
  ---------------------|----------------------|---------------|-------------------------------------
  `array_init`         |                      |O(1)           |[array_init](#function-_init)
  `array_init_size`    |                      |O(1), O(n)     |[array_init_size](#function-_init_size)
  `array_clear`        |                      |O(1), O(n)     |[array_clear](#function-_clear)
  `array_set`          |`set`                 |O(n)           |[array_set](#function-array_set)
  `array_flush`        |                      |O(1), O(n)     |[array_flush](#function-_flush)
  `array_flush_all`    |                      |O(1), O(n)     |[array_flush_all](#function-_clear)
  `array_swap`         |                      |O(1)           |[array_swap](#function-_swap)
  `array_at`           |`retrieve`            |O(1)           |[array_at](#function-_at)
  `array_reserve`      |                      |O(1), resize   |[array_reserve](#function-array_reserve)
  `array_push`         |`insert`              |O(1), resize   |[array_push](#function-array_push)
  `array_push_blank`   |`insert`              |O(1), resize   |[array_push_blank](#function-array_push_blank)
  `array_push_blanks`  |`insert`              |O(1), resize   |[array_push_blanks](#function-array_push_blanks)
  `array_push_clear`   |`insert`              |O(1), resize   |[array_push_clear](#function-array_push_clear)
  `array_pop`          |`retrieve`, `remove`  |O(1)           |[array_pop](#function-array_pop)
  `array_last`         |`retrieve`            |O(1)           |[array_last](#function-array_last)
  `array_copy_resize`  |                      |O(1), O(n)     |[array_copy_resize](#function-_copy_resize)
  `array_fill`         |`set`                 |O(n)           |[array_fill](#function-array_fill)
  `array_get_idx`      |`find`                |O(n)           |[array_get_idx](#function-_get_idx)
  `array_copy`         |                      |O(n)           |[array_copy](#function-_copy)
  `array_compare`      |                      |O(n)           |[array_compare](#function-_compare)
  `array_init_buffer`  |                      |O(1), O(n)     |[array_init_buffer](#function-_init_buffer)
  `array_set_buffer`   |                      |O(1), O(n)     |[array_set_buffer](#function-_set_buffer)

### Example of definition and usage

        @begin
          array<employee_s> employee_array_s;
        @end

### Function array_set

        void <NAME>_set(<NAME> *this,unsigned a_used,const <TYPE> *a_data);

Function sets content of dynamic array according to content of first `a_used`
objects pointed by pointer `a_data`.

### Function array_reserve

        void <NAME>_reserve(<NAME> *this,unsigned a_cnt);

Function reserves `a_cnt` objects in preallocated memory of dynamic array.

### Function array_push

        void <NAME>_push(<NAME> *this,<TYPE> a_value);
        void <NAME>_push(<NAME> *this,const <TYPE> *a_value);

Function pushes copy of object `a_value` to end of dynamic array.

### Function array_push_blank

        void <NAME>_push_blank(<NAME> *this);

Function pushes blank object to end of dynamic array. Object on last position
in dynamic array will be in defined state. There is no guarantee that object
will be empty.

### Function array_push_blanks

        void <NAME>_push_blanks(<NAME> *this,unsigned a_cnt);

Function pushes `a_cnt` blank objects to end of dynamic array. Properties of
pushed objects will be same as is described in function `array_push_blank`.

### Function array_push_clear

        void <NAME>_push_clear(<NAME> *this);

Function pushes empty (initialized) object to end of dynamic array.

### Function array_pop

        <TYPE> <NAME>_pop(<NAME> *this);
        <TYPE> *<NAME>_pop(<NAME> *this);

Function retrieves and removes last object from end of dynamic array.

### Function array_last

        <TYPE> *<NAME>_last(const <NAME> *this);

Function returns pointer to last object in dynamic array.

### Function array_fill

        void <NAME>_fill(<NAME> *this,<TYPE> a_value);
        void <NAME>_fill(<NAME> *this,const <TYPE> *a_value);

Function sets value of all objects presented in dynamic array to value of
object `a_value`.

Dynamic queue - queue
------------------------

Generator of dynamic queue keeping objects in continuous memory block.
Dynamic queue allocates memory block of `size` objects. First element of queue
is stored at position `begin`. After first element follows `used` count of objects,
sequence of objects is wrapped at position `size - 1`.

        struct <NAME>
        {
          unsigned size;
          unsigned used;
          unsigned begin;
          <TYPE> *data;
        };

, where:

-   `size` - is count of objects, that is possible to store to allocated memory.

-   `used` - is count of objects actually stored in dynamic queue.

-   `begin` - is index of first element in queue.

-   `data` - is pointer to first object in allocated memory.

List of functions generated by `queue` follows:

  **Function**          |**Category**          |**Complexity** |**Description**
  ----------------------|----------------------|---------------|-------------------------------------------------------------------------------------
  `queue_init`          |                      |O(1)           |[queue_init](#function-_init)
  `queue_init_size`     |                      |O(1), O(n)     |[queue_init_size](#function-_init_size)
  `queue_clear`         |                      |O(1), O(n)     |[queue_clear](#function-_clear)
  `queue_flush`         |                      |O(1), O(n)     |[queue_flush](#function-_flush)
  `queue_flush_all`     |                      |O(1), O(n)     |[queue_flush_all](#function-_clear)
  `queue_swap`          |                      |O(1)           |[queue_swap](#function-_swap)
  `queue_at`            |`retrieve`            |O(1)           |[queue_at](#function-_at)
  `queue_insert`        |`insert`              |O(1), resize   |[queue_insert](#function-queue_insert)
  `queue_insert_blank`  |`insert`              |O(1), resize   |[queue_insert_blank](#function-queue_insert_blank)
  `queue_next`          |`retrieve`, `remove`  |O(1)           |[queue_next](#function-queue_next)
  `queue_first`         |`retrieve`            |O(1)           |[queue_first](#function-queue_first)
  `queue_last`          |`retrieve`            |O(1)           |[queue_last](#function-queue_last)
  `queue_copy_resize`   |                      |O(1), O(n)     |[queue_copy_resize](#function-_copy_resize)
  `queue_copy`          |                      |O(n)           |[queue_copy](#function-_copy)
  `queue_compare`       |                      |O(n)           |[queue_compare](#function-_compare)
  `queue_init_buffer`   |                      |O(1), O(n)     |[queue_init_buffer](#function-_init_buffer)
  `queue_set_buffer`    |                      |O(1), O(n)     |[queue_set_buffer](#function-_set_buffer)

### Example of definition and usage

        @begin
          queue<employee_s> employee_queue_s;
        @end

### Function queue_insert

        void <NAME>_insert(<NAME> *this,<TYPE> a_value);
        void <NAME>_insert(<NAME> *this,const <TYPE> *a_value);

Function inserts copy of object `a_value` to end of dynamic queue.

### Function queue_insert_blank

        void <NAME>_insert_blank(<NAME> *this);

Function inserts blank object to end of dynamic queue. Object on last position
in dynamic queue will be in defined state. There is no guarantee that object
will be empty.

### Function queue_next

        <TYPE> <NAME>_next(<NAME> *this);
        <TYPE> *<NAME>_next(<NAME> *this);

Function retrieves and removes first object from begin of dynamic queue.

### Function queue_first

        <TYPE> *<NAME>_first(const <NAME> *this);

Function returns pointer to first object in dynamic queue.

### Function queue_last

        <TYPE> *<NAME>_last(const <NAME> *this);

Function returns pointer to last object in dynamic queue.

Linked list - list
------------------------------

Generator of linked list keeping objects in continuous memory block. Linked
list allocates memory block of `size` elements, from which `used` elements are
used in one point in time.

First free (unused) linked list element in allocated memory is at position
`free_idx`. Free elements of linked list are connected by index `next_idx` of
elements.

Linked list can be generated in so called `safe` variant, which adds validity
flag `valid` to each linked list element. Moreover `safe` variant of linked list
also counts elements stored in linked list. This count can be accessed by
variable `count`.

        struct <NAME>_element
        {
          unsigned next_idx;
          unsigned prev_idx;
          char valid; // safe
          <TYPE> object;
        };

, where:

-   `<NAME>_element` - is structure describing one element of linked list.

-   `next_idx` - is index of next element in linked list.

-   `prev_idx` - is index of previous element in linked list.

-   `valid` - is flag indicating that this element is part of linked list.
    Validity flag is defined in elements of `safe` variant of linked list.

-   `object` - is value of object stored in linked list.

<!-- -->

        struct <NAME>
        {
          unsigned size;
          unsigned used;
          unsigned count; // safe
          <NAME>_element *data;
          unsigned free_idx;
          unsigned first_idx;
          unsigned last_idx;
        };

, where:

-   `size` - is count of elements, that is possible to store to allocated
    memory.

-   `used` - is count of elements at begin of allocated memory, that is used by
    linked list.

-   `count` - is count of elements stored in linked list. Count of elements is
    defined for `safe` variant of linked list.

-   `data` - is pointer to first element in allocated memory.

-   `free_idx` - is index of first element that is free. Free elements are not
    part of actual content of linked list.

-   `first_idx` - is index of first element of linked list.

-   `last_idx` - is index of last element of linked list.

List of functions generated by `list` follows:

  **Function**                |**Category**   |**Complexity** |**Description**
  ----------------------------|---------------|---------------|----------------------------------------------------------------------------------------------
  `list_init`                 |               |O(1)           |[list_init](#function-_init)
  `list_init_size`            |               |O(1), O(n)     |[list_init_size](#function-_init_size)
  `list_clear`                |               |O(1), O(n)     |[list_clear](#function-_clear)
  `list_flush`                |               |O(1), O(n)     |[list_flush](#function-_flush)
  `list_flush_all`            |               |O(1), O(n)     |[list_flush_all](#function-_clear)
  `list_swap`                 |               |O(1)           |[list_swap](#function-_swap)
  `list_at`                   |`retrieve`     |O(1)           |[list_at](#function-_at)
  `list_prepend`              |`insert`       |O(1), resize   |[list_prepend](#function-list_prepend)
  `list_append`               |`insert`       |O(1), resize   |[list_append](#function-list_append)
  `list_insert_before`        |`insert`       |O(1), resize   |[list_insert_before](#function-list_insert_before)
  `list_insert_after`         |`insert`       |O(1), resize   |[list_insert_after](#function-list_insert_after)
  `list_prepend_blank`        |`insert`       |O(1), resize   |[list_prepend_blank](#function-list_prepend_blank)
  `list_append_blank`         |`insert`       |O(1), resize   |[list_append_blank](#function-list_append_blank)
  `list_insert_blank_before`  |`insert`       |O(1), resize   |[list_insert_blank_before](#function-list_insert_blank_before)
  `list_insert_blank_after`   |`insert`       |O(1), resize   |[list_insert_blank_after](#function-list_insert_blank_after)
  `list_remove`               |`remove`       |O(1)           |[list_remove](#function-list_remove)
  `list_next_idx`             |`iterate`      |O(1)           |[list_next_idx](#function-list_next_idx)
  `list_prev_idx`             |`iterate`      |O(1)           |[list_prev_idx](#function-list_prev_idx)
  `list_copy_resize`          |               |O(1), O(n)     |[list_copy_resize](#function-_copy_resize)
  `list_get_idx`              |`find`         |O(n)           |[list_get_idx](#function-_get_idx)
  `list_copy`                 |               |O(n)           |[list_copy](#function-_copy)
  `list_compare`              |               |O(n)           |[list_compare](#function-_compare)
  `list_init_buffer`          |               |O(1), O(n)     |[list_init_buffer](#function-_init_buffer)
  `list_set_buffer`           |               |O(1), O(n)     |[list_set_buffer](#function-_set_buffer)

### Example of definition and usage

        @begin
          list<employee_s> employee_list_s;
        @end

### Function list_prepend

        unsigned <NAME>_prepend(<NAME> *this,<TYPE> a_value);
        unsigned <NAME>_prepend(<NAME> *this,const <TYPE> *a_value);

Function prepends copy of object `a_value` to begin of linked list.
Function returns index of inserted element.

### Function list_append

        unsigned <NAME>_append(<NAME> *this,<TYPE> a_value);
        unsigned <NAME>_append(<NAME> *this,const <TYPE> *a_value);

Function appends copy of object `a_value` to end of linked list.
Function returns index of inserted element.

### Function list_insert_before

        unsigned <NAME>_insert_before(<NAME> *this,unsigned a_idx,<TYPE> a_value);
        unsigned <NAME>_insert_before(<NAME> *this,unsigned a_idx,const <TYPE> *a_value);

Function inserts copy of object `a_value` before element at position `a_idx` in
linked list. Function returns index of inserted element.

### Function list_insert_after

        unsigned <NAME>_insert_after(<NAME> *this,unsigned a_idx,<TYPE> a_value);
        unsigned <NAME>_insert_after(<NAME> *this,unsigned a_idx,const <TYPE> *a_value);

Function inserts copy of object `a_value` after element at position `a_idx` in
linked list. Function returns index of inserted element.

### Function list_prepend_blank

        unsigned <NAME>_prepend_blank(<NAME> *this);

Function prepends blank object to begin of linked list.
Inserted object will be in defined state. There is no guarantee that object
will be empty. Function returns index of inserted element.

### Function list_append_blank

        unsigned <NAME>_append_blank(<NAME> *this);

Function appends blank object to end of linked list.
Inserted object will be in defined state. There is no guarantee that object
will be empty. Function returns index of inserted element.

### Function list_insert_blank_before

        unsigned <NAME>_insert_blank_before(<NAME> *this,unsigned a_idx);

Function inserts blank object before element at position `a_idx` in linked
list. Inserted object will be in defined state. There is no guarantee that
object will be empty. Function returns index of inserted element.

### Function list_insert_blank_after

        unsigned <NAME>_insert_blank_after(<NAME> *this,unsigned a_idx);

Function inserts blank object after element at position `a_idx` in
linked list. Inserted object will be in defined state. There is no guarantee
that object will be empty. Function returns index of inserted element.

### Function list_remove

        void <NAME>_remove(<NAME> *this,unsigned a_idx);

Function removes element at position `a_idx` from linked list.

### Function list_next_idx

        unsigned <NAME>_next_idx(const <NAME> *this,unsigned a_idx);

Function returns position of element following element at position `a_idx`.

### Function list_prev_idx

        unsigned <NAME>_prev_idx(const <NAME> *this,unsigned a_idx);

Function returns position of element preceding element at position `a_idx`.

Balanced binary tree - rb_tree
-----------------------------------------------

Generator of balanced binary tree keeping objects in continuous memory block.
Balanced tree allocates memory block of `size` nodes, from which `used` nodes
are used in one point in time.

Root node of balanced tree is stored at position `root_idx`. Nodes of balanced
tree are interconnected by indexes to parent node `parent_idx`, left sub-tree
of node `left_idx` and right sub-tree of node `right_idx`.

First free (unused) node of balanced tree is stored at position `free_idx`.
Free elements of balanced tree are connected by index `parent_idx` of elements.

Balanced tree can be generated in so called `safe` variant, which adds validity
flag `valid` to each balanced tree node. Moreover `safe` variant of balanced tree
also counts nodes stored in balanced tree. This count can be accessed by
variable `count`.

        struct <NAME>_node
        {
          unsigned parent_idx;
          unsigned left_idx;
          unsigned right_idx;
          char color;
          char valid; // safe
          <TYPE> object;
        };

, where:

-   `<NAME>_node` - is structure describing one node of balanced tree.

-   `parent_idx` - is index of parent of node in balanced tree.

-   `left_idx` - is index of root node of left sub-tree of node in balanced tree.

-   `right_idx` - is index of root node of right sub-tree of node in balanced tree.

-   `color` - is color of node in red-black balanced tree.

-   `valid` - is flag indicating that this node is part of balanced tree.
    Validity flag is defined in nodes of `safe` variant of balanced tree.

-   `object` - is value of object stored in balanced tree.

<!-- -->

        struct <NAME>
        {
          unsigned size;
          unsigned used;
          unsigned count;
          <NAME>_node *data;
          unsigned free_idx;
          unsigned root_idx;
          unsigned leaf_idx;
        };

, where:

-   `size` - is count of nodes, that is possible to store to allocated memory.

-   `used` - is count of nodes at begin of allocated memory, that is used by
    balanced tree.

-   `count` - is count of nodes stored in balanced tree. Count of elements is
    defined for `safe` variant of balanced tree.

-   `data` - is pointer to first node in allocated memory.

-   `free_idx` - is index of first node that is free. Free nodes are not
    part of actual content of balanced tree.

-   `root_idx` - is index of root node of balanced tree.

-   `leaf_idx` - is index of red-black tree leaf node. There is one leaf node
    in every non-empty red-black tree.

List of functions generated by `rb_tree` follows:

  **Function**                    |**Category**      |**Complexity**     |**Description**
  --------------------------------|------------------|-------------------|-----------------------------------------------------------------------------------------------------------
  `tree_init`                     |                  |O(1)               |[tree_init](#function-_init)
  `tree_clear`                    |                  |O(1), O(n)         |[tree_clear](#function-_clear)
  `tree_flush`                    |                  |O(1), O(n)         |[tree_flush](#function-_flush)
  `tree_flush_all`                |                  |O(1), O(n)         |[tree_flush_all](#function-_clear)
  `tree_swap`                     |                  |O(1)               |[tree_swap](#function-_swap)
  `tree_at`                       |`retrieve`        |O(1)               |[tree_at](#function-_at)
  `tree_insert`                   |`insert`          |O(log(n)), resize  |[tree_insert](#function-tree_insert)
  `tree_unique_insert`            |`find`, `insert`  |O(log(n)), resize  |[tree_unique_insert](#function-tree_unique_insert)
  `tree_swap_insert`              |`insert`          |O(log(n)), resize  |[tree_swap_insert](#function-tree_swap_insert)
  `tree_unique_swap_insert`       |`find`, `insert`  |O(log(n)), resize  |[tree_unique_swap_insert](#function-tree_unique_swap_insert)
  `tree_remove`                   |`remove`          |O(1)               |[tree_remove](#function-tree_remove)
  `tree_copy_resize`              |                  |O(1), O(n)         |[tree_copy_resize](#function-_copy_resize)
  `tree_get_min_value_idx`        |`iterate`         |O(log(n))          |[tree_get_min_value_idx](#function-tree_get_min_value_idx)
  `tree_get_max_value_idx`        |`iterate`         |O(log(n))          |[tree_get_max_value_idx](#function-tree_get_max_value_idx)
  `tree_get_next_idx`             |`iterate`         |O(log(n))          |[tree_get_next_idx](#function-tree_get_next_idx)
  `tree_get_prev_idx`             |`iterate`         |O(log(n))          |[tree_get_prev_idx](#function-tree_get_prev_idx)
  `tree_get_descent_stack_size`   |`stack iterate`   |O(1)               |[tree_get_descent_stack_size](#function-tree_get_descent_stack_size)
  `tree_get_stack_min_value_idx`  |`stack iterate`   |O(log(n))          |[tree_get_stack_min_value_idx](#function-tree_get_stack_min_value_idx)
  `tree_get_stack_next_idx`       |`stack iterate`   |O(log(n))          |[tree_get_stack_next_idx](#function-tree_get_stack_next_idx)
  `tree_get_idx`                  |`find`            |O(log(n))          |[tree_get_idx](#function-_get_idx)
  `tree_get_idx_left`             |`find`            |O(log(n))          |[tree_get_idx_left](#function-tree_get_idx_left)
  `tree_get_gre_idx`              |`find`            |O(log(n))          |[tree_get_gre_idx](#function-tree_get_gre_idx)
  `tree_get_lee_idx`              |`find`            |O(log(n))          |[tree_get_lee_idx](#function-tree_get_lee_idx)
  `tree_get_idxs`                 |`find`            |O(log(n))          |[tree_get_idxs](#function-tree_get_idxs)
  `tree_copy`                     |                  |O(n)               |[tree_copy](#function-_copy)
  `tree_compare`                  |                  |O(n\*log(n))       |[tree_compare](#function-_compare)
  `tree_init_buffer`              |                  |O(1), O(n)         |[tree_init_buffer](#function-_init_buffer)
  `tree_set_buffer`               |                  |O(1), O(n)         |[tree_set_buffer](#function-_set_buffer)

### Balanced tree compare function

Balanced tree declares function for comparing content of two objects of
contained data type. This function must be implemented in order to use
generated balanced tree. Declaration of function comparing value of contained
objects follows:

        int <NAME>___compare_value(const <NAME> *this,
                const <TYPE> *a_first,const <TYPE> *a_second);

Return value of function must be following:

-   `-1` - if value of `a_first` is lower than value of `a_second`.

-   `0` - if values of objects `a_first` and `a_second` are equal.

-   `1` - if value of `a_first` is greater than value of `a_second`.

### Example of definition and usage

        @begin
          rb_tree<employee_s> employee_tree_s;
        @end
     
        static inline int employee_tree_s___compare_value(
            const employee_tree_s *this,
            const employee_s *a_first,
            const employee_s *a_second)
        {
          return a_first->id < a_second->id ? -1 : a_first->id > a_second->id ? 1 : 0;
        }

### Function tree_insert

        unsigned <NAME>_insert(<NAME> *this,<TYPE> a_value);
        unsigned <NAME>_insert(<NAME> *this,const <TYPE> *a_value);

Function inserts copy of object `a_value` to balanced tree.
Function returns index of inserted node.

### Function tree_unique_insert

        unsigned <NAME>_unique_insert(<NAME> *this,<TYPE> a_value);
        unsigned <NAME>_unique_insert(<NAME> *this,const <TYPE> *a_value);

In case that object with value `a_value` is not contained in balanced tree,
function will insert copy of object `a_value` to balanced tree and return index
of inserted node. Otherwise function will return index of node containing
object with value `a_value`.

### Function tree_swap_insert

        unsigned <NAME>_swap_insert(<NAME> *this,<TYPE> *a_value);

Function inserts blank object to balanced tree, and swaps values of
inserted blank object and object `a_value`.
Function returns index of inserted node.

### Function tree_unique_swap_insert

        unsigned <NAME>_unique_swap_insert(<NAME> *this,<TYPE> *a_value);

In case that object with value `a_value` is not contained in balanced tree,
function will insert blank object to balanced tree, swaps values of inserted
blank object and object `a_value`, and return index of inserted node. Otherwise
function will return index of node containing object with value `a_value`.

### Function tree_remove

        void <NAME>_remove(<NAME> *this,unsigned a_idx);

Function removes object at position `a_idx` from balanced tree.

### Function tree_get_min_value_idx

        unsigned <NAME>_get_min_value_idx(const <NAME> *this,unsigned a_idx);

Function retrieve position of node containing minimal value in sub-tree with
root node at position `a_idx`.

### Function tree_get_max_value_idx

        unsigned <NAME>_get_max_value_idx(const <NAME> *this,unsigned a_idx);

Function retrieve position of node containing maximal value in sub-tree with
root node at position `a_idx`.

### Function tree_get_next_idx

        unsigned <NAME>_get_next_idx(const <NAME> *this,unsigned a_idx);

Function retrieve position of node following node at position `a_idx` in tree
ordering.

### Function tree_get_prev_idx

        unsigned <NAME>_get_prev_idx(const <NAME> *this,unsigned a_idx);

Function retrieve position od node preceding node at position `a_idx` in tree
ordering.

### Function tree_get_descent_stack_size

        unsigned <NAME>_get_descent_stack_size(const <NAME> *this);

Function returns minimal depth of stack needed to traverse balanced tree by
stack method.

### Function tree_get_stack_min_value_idx

        unsigned <NAME>_get_stack_min_value_idx(const <NAME> *this,
            unsigned a_idx,unsigned **a_s_ptr);

Function retrieve position of node containing minimal value in sub-tree with
root node at position `a_idx`. Function uses provided stack to faster tree
traverse.

### Function tree_get_stack_next_idx

        unsigned <NAME>_get_stack_next_idx(const <NAME> *this,
            unsigned a_idx,unsigned **a_s_ptr,const unsigned *a_stack_base);

Function retrieve position of node following node at position `a_idx` in tree
ordering. Function uses provided stack to faster tree traverse.

### Function tree_get_idx_left

        unsigned <NAME>_get_idx_left(const <NAME> *this,<TYPE> a_value);
        unsigned <NAME>_get_idx_left(const <NAME> *this,const <TYPE> *a_value);

Function returns leftmost node containing object with value `a_value`. Balanced
trees can contain more than one node with same value.

### Function tree_get_gre_idx

        unsigned <NAME>_get_gre_idx(const <NAME> *this,<TYPE> a_value);
        unsigned <NAME>_get_gre_idx(const <NAME> *this,const <TYPE> *a_value);

Function returns position of node containing object of value equal or greater
(closest to given value) than value of object `a_value`.

### Function tree_get_lee_idx

        unsigned <NAME>_get_lee_idx(const <NAME> *this,<TYPE> a_value);
        unsigned <NAME>_get_lee_idx(const <NAME> *this,const <TYPE> *a_value);

Function returns position of node containing object of value equal or lesser
(closest to given value) than value of object `a_value`.

### Function tree_get_idxs

        void <NAME>_get_idxs(const <NAME> *this,<TYPE> a_value,
            ui_array_s *a_idxs_array);
        void <NAME>_get_idxs(const <NAME> *this,const <TYPE> *a_value,
            ui_array_s *a_idxs_array);

Functions pushes to array `a_idxs_array` positions of all nodes of balanced
tree, containing objects with value `a_value`.

Idiomatic notation of some algorithms
=====================================

Shared functions and macros
---------------------------

### Object initialization

Creation of object on stack, and its initialisation.

        {
          CONT_INIT(ui_array_s,array);
          ...
          ui_array_s_clear(&array);
        }

### Release of object resources

Creation of object on stack, and release of its resources on end of its
lifetime.

        {
          CONT_CLEAR(ui_array_s,array);
          ui_array_s_init(&array);
          ...
        }

### Initialization and release of object resources

Creation of object on stack, initialization of object and release of object
resources on end of its lifetime.

        {
          CONT_INIT_CLEAR(ui_array_s,array);
          ...
        }

Dynamic array - array
----------------------

### Count of items

Count of items in dynamic array.

        CONT_INIT_CLEAR(ui_array_s,array);
        ...
     
        unsigned used = array.used;

### Iteration

Iteration over items of dynamic array.

        CONT_INIT_CLEAR(ui_array_s,array);
        ...
     
        if (array.used != 0)
        {
          ui *a_ptr = array.data;
          ui *a_ptr_end = a_ptr + array.used;
          do {
            ...
          } while(++a_ptr < a_ptr_end);
        }

Dynamic queue - queue
------------------------

### Count of items

Count of items of dynamic queue.

        CONT_INIT_CLEAR(ui_queue_s,queue);
        ...
     
        unsigned used = queue.used;

### Next item in queue

Selection of all items from queue.

        CONT_INIT_CLEAR(ui_queue_s,queue);
        ...
     
        while (queue.used > 0)
        {
          ui value = ui_queue_s_next(&queue);
          ...
        }

### Iteration

Iteration over items of dynamic queue.

        CONT_INIT_CLEAR(ui_queue_s,queue);
        ...
     
        if (queue.used != 0)
        {
          unsigned idx;
          do {
            ui *value_ptr = ui_queue_s_at(&queue,idx);
            ...
          } while(++idx < queue.used);
        }

Linked list - list
------------------------------

### Elements count

Count of elements in linked list (only for save variant of linked list).

        CONT_INIT_CLEAR(ui_list_s,list);
        ...
     
        unsigned count = list.count;

### Iteration

Iteration over elements of linked list.

        CONT_INIT_CLEAR(ui_list_s,list);
        ...
     
        if (list.first_idx != c_idx_not_exist)
        {
          unsigned idx = list.first_idx;
          do {
            ui *value_ptr = ui_list_s_at(&list,idx);
            ...
     
            idx = ui_list_s_next_idx(&list,idx);
          } while(idx != c_idx_not_exist);
        }

Balanced binary tree - rb_tree
-----------------------------------------------

### Node count

Count of nodes in balanced tree (only for save variant of balanced tree).

        CONT_INIT_CLEAR(ui_tree_s,tree);
        ...
     
        unsigned count = tree.count;

### Iteration

Iteration over nodes of balanced tree in tree order (from smallest to biggest).

        CONT_INIT_CLEAR(ui_tree_s,tree);
        ...
     
        if (tree.root_idx != c_idx_not_exist)
        {
          unsigned idx = ui_tree_s_get_min_value_idx(&tree,tree.root_idx);
          do {
            ui *value_ptr = ui_tree_s_at(&tree,idx);
            ...
     
            idx = ui_tree_s_get_next_idx(&tree,idx);
          } while(idx != c_idx_not_exist);
        }

### Stack iteration

Iteration over nodes of balanced tree in tree order (from smallest to biggest).
Iteration uses stack provided to balanced tree function as temporary index
storage.

        CONT_INIT_CLEAR(ui_tree_s,tree);
        ...
     
        if (tree.root_idx != c_idx_not_exist)
        {
          unsigned stack[RB_TREE_STACK_SIZE(ui_tree_s,&tree)];
          unsigned *stack_ptr = stack;
     
          unsigned idx = ui_tree_s_get_stack_min_value_idx(
                  &tree,tree.root_idx,&stack_ptr);
          do {
            ui *value_ptr = ui_tree_s_at(&tree,idx);
            ...
     
            idx = ui_tree_s_get_stack_next_idx(&tree,idx,&stack_ptr,stack);
          } while(idx != c_idx_not_exist);
        }

### Fast iteration

Out of order iteration over nodes of balanced tree. Available only for `save`
variant of balanced tree.

        CONT_INIT_CLEAR(ui_tree_s,tree);
        ...
     
        if (tree.root_idx != c_idx_not_exist)
        {
          ui_tree_s_node *utn_ptr = tree.data;
          ui_tree_s_node *utn_ptr_end = utn_ptr + tree.used;
          do {
            if (utn_ptr->valid)
            {
              unsigned value = utn_ptr->object;
              ...
            }
          } while(++utn_ptr < utn_ptr_end);
        }

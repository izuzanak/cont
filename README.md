# cont - container generator

![CI](https://github.com/izuzanak/cont/workflows/CI/badge.svg?branch=cont_c)

C code preprocessor generating code of containers. Generated code is based on
marks found in processed code.

Following container types are supported:

* [`struct`](https://github.com/izuzanak/cont/blob/cont_c/cont/generators/gen_struct.cc) - Simple structure composed from contained elements.
* [`array`](https://github.com/izuzanak/cont/blob/cont_c/cont/generators/gen_array.cc) - Array of contained elements.
* [`queue`](https://github.com/izuzanak/cont/blob/cont_c/cont/generators/gen_queue.cc) - One direction queue of contained elements.
* [`list`](https://github.com/izuzanak/cont/blob/cont_c/cont/generators/gen_list.cc) - List of contained elements.
* [`rb_tree`](https://github.com/izuzanak/cont/blob/cont_c/cont/generators/gen_rb_tree.cc) - Red-black tree of contained elements.

## Motivation for container generator

### Every container is based on continuous memory block

Data of contained elements are stored in continuous block of memory. Memory block
is resized when its size is not sufficient for requested count of elements.
Copying of memory block while resizing is performed by realloc, no knowledge of
objects structure other than its size is required.

### Persistent unsigned indexes instead of iterators

Elements inside containers are identified by indexes (unsigned int) which are
persistent and cannot be invalidated by any operation other than removal of
this particular element.  This allows usage of element indexes as members
in other structures related to container, rather than pointers.

### Objects construction and destruction

Methods `<type>_init` and `<type>_clear` are used for object initialization and
clearing.

`<type>_init` - After creation of object (allocation on heap, or on stack) it
must be initialized by `<type>_init` or related methods (`<type>_init_size`).

`<type>_clear` - Clears object content, releases allocated resources and resets
object state to initialized state. Object is not invalidated by `<type>_clear`.

### Generated code is human readable and accessible

Containers code is generated to `.c` file. Generated code can be read, modified,
or copied and used in another projects.

## Build

Requires a C++11 compiler and CMake.

```sh
mkdir -p build && cd build
cmake ..
make -j$(nproc)
```

## Test

```sh
cd cont/
bash test.sh
```

Builds and runs all examples in `cont/examples/`.

## Documentation

Short introduction to container generator principles can be found in
[`cont/doc/intro.md`](https://github.com/izuzanak/cont/tree/cont_c/cont/doc/intro.md).

## Examples

Each example consists of a **header file** (`.h`) containing type definitions and
inline methods, and a **source file** (`.c`) containing non-inline methods and
usage code. The preprocessor `cont_c` expands `@begin`/`@end` blocks into
generated C code. Headers are included via `@begin include "header.h" @end`
blocks (omitted below for brevity).

### Struct

Define a record type with two unsigned fields. The generator produces
`init`, `clear`, `set`, `copy`, `swap`, and `compare` methods.

**struct.h** — type definition and inline methods:
```c
// -- record_s --
@begin
struct
<
unsigned:index
unsigned:value
>
record_s;
@end

@begin
inlines record_s
@end
```

**struct.c** — non-inline methods and usage:
```c
// -- record_s --
@begin
methods record_s
@end

// ...

CONT_INIT_CLEAR(record_s,rec0);
CONT_INIT_CLEAR(record_s,rec1);

record_s_set(&rec0,1,2);
record_s_set(&rec1,3,4);

printf("rec0: {%u,%u}\n",rec0.index,rec0.value);
printf("rec1: {%u,%u}\n",rec1.index,rec1.value);

record_s_swap(&rec1,&rec0);
record_s_copy(&rec1,&rec0);
printf("record_s_compare(&rec0,&rec1): %s\n",
  record_s_compare(&rec0,&rec1) ? "TRUE" : "FALSE");

// rec0 and rec1 are automatically cleared on scope exit
```

### Dynamic array

Declare a type-safe array of `record_s` and use push/pop, swap, copy, and compare.

**array.h** — container declaration and inline methods:
```c
// -- rec_array_s --
@begin
   array<record_s> rec_array_s;
@end

@begin
   inlines rec_array_s
@end
```

**array.c** — non-inline methods and usage:
```c
// -- rec_array_s --
@begin
   methods rec_array_s
@end

// ...

CONT_INIT_CLEAR(record_s,rec);
record_s_set(&rec,1,2);

CONT_CLEAR(rec_array_s,array0);
rec_array_s_init_size(&array0,5);
rec_array_s_fill(&array0,&rec);       // fill all 5 slots with rec

while (array0.used > 3)
  rec_array_s_pop(&array0);            // remove last element

rec.index = 3; rec.value = 4;
rec_array_s_push(&array0,&rec);        // append element

CONT_INIT_CLEAR(rec_array_s,array1);
rec_array_s_swap(&array0,&array1);     // O(1) swap
rec_array_s_copy(&array0,&array1);     // deep copy
printf("rec_array_s_compare(&array0,&array1): %s\n",
  rec_array_s_compare(&array0,&array1) ? "TRUE" : "FALSE");

// rec, array0, and array1 are automatically cleared on scope exit
```

More examples are available in [`cont/examples`](https://github.com/izuzanak/cont/tree/cont_c/cont/examples).

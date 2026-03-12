# cont - container generator

![CI](https://github.com/izuzanak/cont/workflows/CI/badge.svg)

C/C++ code preprocessor generating code of containers. Generated code is based on marks found
in processed code.

Following container types are supported:

* [`struct`](https://github.com/izuzanak/cont/blob/master/cont/generators/gen_struct.cc) - Simple structure composed from contained elements.
* [`array`](https://github.com/izuzanak/cont/blob/master/cont/generators/gen_array.cc) - Array of contained elements.
* [`queue`](https://github.com/izuzanak/cont/blob/master/cont/generators/gen_queue.cc) - One direction queue of contained elements.
* [`list`](https://github.com/izuzanak/cont/blob/master/cont/generators/gen_list.cc) - List of contained elements.
* [`rb_tree`](https://github.com/izuzanak/cont/blob/master/cont/generators/gen_rb_tree.cc) - Red-black tree of contained elements.

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

### Constructor/destructor not used at all

C++ Constructors and destructors are not used by generated structures.
Methods `init` and `clear` are instead used for object initialization and
clear.

`init` - After creation of object (allocation on heap, or on stack) it must be
initialized by method `init` or related metods (`init_size`).

`clear` - Clears object content, release allocated resources and reset object
state to initialized state. Object is not invalidated by `clear` method.

### Generated code is human readable and accessible

Containers code is generated to `.cc` file. Generated code can be read, modified,
or copied and used in another projects.

## Build

cont is self-hosting: it preprocesses its own source files.
A two-pass bootstrap is required on first build.

### Bootstrap (no cont installed yet)

```bash
# First pass — build cont without preprocessing
mkdir -p build && cd build
cmake ..
make
sudo make install

# Second pass — cont now preprocesses its own source
rm -rf *
cmake ..
make
sudo make install
```

### When cont is already installed

```bash
mkdir -p build && cd build
cmake ..
make
sudo make install
```

CMake finds `cont` in PATH automatically via `find_program`. Use `-DPROCESS_BIN=/path/to/cont` only to override with a specific binary.

## Quick examples

### Struct with custom methods

Declare a struct with typed fields inside `@begin`/`@end` markup, and add custom
inline methods via an `additions` block.

**struct.h**
```cpp
@begin
include "base.h"
@end

// -- record_s --
@begin
struct
<
unsigned:index
unsigned:value
>

additions
{
  inline unsigned get_index();
  inline unsigned get_value();
}

record_s;
@end

@begin
inlines record_s
@end

inline unsigned record_s::get_index()
{
  return index;
}

inline unsigned record_s::get_value()
{
  return value;
}
```

**struct.cc** (usage)
```cpp
record_s rec0, rec1;

rec0.init();
rec1.init();

rec0.set(1, 2);
rec1.set(3, 4);

printf("rec0: {%u,%u}\n", rec0.index, rec0.value);
printf("rec1: {%u,%u}\n", rec1.index, rec1.value);
printf("rec0 == rec1: %s\n", rec0 == rec1 ? "TRUE" : "FALSE");

rec1 = rec0;
printf("rec0 == rec1: %s\n", rec0 == rec1 ? "TRUE" : "FALSE");

rec0.clear();
rec1.clear();
```

### Array of structs

Wrap a user-defined struct in an array — supports `push`, `pop`, `operator[]`,
and iteration over contiguous memory.

**array.h**
```cpp
@begin
include "struct.h"
@end

// -- rec_array_s --
@begin
   array<record_s> rec_array_s;
@end

@begin
   inlines rec_array_s
@end
```

**array.cc** (usage)
```cpp
record_s rec;
rec.init();
rec.set(1, 2);

rec_array_s array0;
array0.init();

// push elements
array0.push(rec);
array0.push(rec);
array0.push(rec);

// modify via operator[]
array0[1].value = 42;

// iterate over contiguous data
record_s *r_ptr = array0.data;
record_s *r_ptr_end = r_ptr + array0.used;
while (r_ptr < r_ptr_end)
{
  printf("{%u,%u}", r_ptr->index, r_ptr->value);
  ++r_ptr;
}

array0.clear();
rec.clear();
```

### Red-black tree as ordered map

Compose `struct` + `rb_tree` to build a key-value map sorted by key.
Provide a custom `__compare_value` to define ordering.

**int_str_map.h**
```cpp
// -- int_string_s --
@begin
   struct
   <
   int:index
   string_s:value
   >
   int_string_s;
@end

// -- int_string_map_s --
@begin
   rb_tree<int_string_s> int_string_map_s;
@end

@begin
   inlines int_string_map_s
@end

inline int int_string_map_s::__compare_value(int_string_s &a_first,int_string_s &a_second)
{
  int &fi = a_first.index;
  int &si = a_second.index;

  return fi < si ? -1 : fi > si ? 1 : 0;
}
```

**int_str_map.cc** (usage)
```cpp
int_string_map_s map;
map.init();

// insert key-value pairs
int_string_s pair;
pair.init();

pair.index = 3;
pair.value.setf("hello");
map.swap_insert(pair);

pair.index = 1;
pair.value.setf("world");
map.swap_insert(pair);

// iterate in sorted order (1, 3)
unsigned stack[map.get_descent_stack_size()];
unsigned *stack_ptr = stack;

unsigned idx = map.get_stack_min_value_idx(map.root_idx, &stack_ptr);
do
{
  int_string_s &p = map[idx];
  printf("%d -> %s\n", p.index, p.value.data);

  idx = map.get_stack_next_idx(idx, &stack_ptr, stack);
}
while (idx != c_idx_not_exist);

pair.clear();
map.clear();
```

## More examples

Full working examples are in directory: [`cont/examples`](https://github.com/izuzanak/cont/tree/master/cont/examples).

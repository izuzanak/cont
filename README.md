# cont - container generator
C code preprocessor generating code of ADT containers. Generated code is based on marks found
in processed code.

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
Copying of memory block while resizing is performed by memcpy, no knowledge of
objects structure other than its size is needed.

### Persistent unsigned indexes instead of iterators

Elements inside containers are identified by indexes (unsigned int) which are
persistent and cannot be invalidated by any operation other than removal of
this particular element.  This allows usage of element indexes as members
in other structures related to container.

### Objects construction and desruction

Methods `init` and `clear` are used for object initialization and clearing.

`init` - After creation of object (allocation on heap, or on stack) it must be
initialized by method `init` or related metods (`init_size`).

`clear` - Clears object content, release allocated dynamic memory and reset
object state to initialized state. Object is not invalidated by `clear` method.

### Generated code is human readable and accessible

Containers code is generated to `.c` file. Generated code can be read, modified,
or copied and used in another projects.

## Build container processor

Container generator [`cont`](https://github.com/izuzanak/cont) is needed for
`cont_c` compilation. Compile it and place binary `process` to your `PATH`
directory.

Enter build directory [`cont_build`](https://github.com/izuzanak/cont/tree/cont_c/cont_build).
```
cd cont_build
```
Execute build script [`build.sh`](https://github.com/izuzanak/cont/blob/cont_c/cont_build/build.sh)
```
sh build.sh
```
## Examples

Examples of container generator usage are presented in directory: [`cont/examples`](https://github.com/izuzanak/cont/tree/cont_c/cont/examples).

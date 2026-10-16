### intro

> Variable declaration means allocating a block of memory and also specifying a name with which to refer to that memory.
> Because variables are typed, variable declaration implicitly specifies the size of the memory block to allocate

>Programming in C requires knowing where data is in memory
> memory in each of the four regions is managed differently
>The biggest source of bugs in C is from incorrect assumptions about memory

---
### Stack
> [!IMPORTANT]
> (same exact footnote as in an earlier section) Because parameters and return addresses are critical to function call and return, they are stored directly in the CPU where possible–on special hardware called registers (which we talk about later). Because there are only a limited number of such registers, additional parameters and return addresses are stored in memory on the stack until they are needed.


> [!IMPORTANT]
> Allocation and deallocation is incredibly fast on the stack thanks to the stack pointer.
> stack pointer is an internally tracked value
> that tells us the address of the “top of the stack”
> i.e., the start of the current frame, and thereby determines allocation and deallocation on the stack.

> stack frames like a stack data structure: Last In, First Out
> (LIFO).
  > “Grow” the stack by moving the stack pointer down to a lower address, thereby pushing on a “new stack frame” (i.e., a new block of memory). 
  > "Shrink” the stack by moving the stack pointer back up to a higher address, thereby popping off the current stack frame.

> [!NOTE]
> When a function returns and the stack pointer moves up, the system does not erase the memory. There is “no time” to zero it out; C is too busy.

[import link that explain the relation between function parameters and return address, and explain also what is return address(claude)](https://claude.ai/share/74769333-a757-4300-a1c2-7a8fc274f2bc) 
[deepseek](https://chat.deepseek.com/share/gkthr3wuxreuf0j1he)

> [!NOTE]
> in the top frame (top of stack memory) there `sp/rsp` register inside the CPU that holds the address of the top of the stack 

> [!NOTE]
> All stack frames currently on the stack correspond to function calls that have not finished executing.

> [!WARNING]
> It is catastrophic to return a pointer into the stack!

```c
char *make_buf(size_t len) {
    char buf[len];
    return buf;
}
void foo(char *ptr2, size_t len) { ... }
int main(){
   char *ptr = make_buf(BUFLEN); 
   foo(ptr, BUFLEN);
   ...
}
```

![result](https://notes.cs61c.org/build/c-stack-buf-bad-4c6ca25a021256f54d683cec6c61e55b.png) 

> from course
> The stack pointer itself must live somewhere. Instead of living in memory, it lives on the CPU in a special hardware register, so that it can be read and updated quickly
---
### Heap

> In C, we need to manually free space on the heap;

>Java has a background garbage collector which frees dynamically allocated objects when they are unused

> [!NOTE]
> Memory on the heap is managed with the help of standard C library functions in `stdlib.h`
  - `malloc`: memory allocation, i.e., allocate a memory block on the heap
  - `free`: free memory on the heap
  - `realloc`: reallocate previously allocated memory blocks to a larger or smaller memory block on the heap.

> [!NOTE]
> Dynamic memory (that is, storage in the heap) can be allocated (malloc-ed), resized (realloc-ed), and deallocated (free-d) during program runtime

> [!IMPORTANT]
> contrast this with the stack, where each local variable size must be determined first in order to determine the size of each stack frame.


> [!NOTE]
> The stack is a relatively small pool of memory, and memory blocks are allocated as stack frames, which are adjacent to one another.
> By contrast, the heap is typically huge–much larger than the stack—and memory blocks are not necessarily allocated in contiguous order.

> three requests in heap memory 
![img](https://notes.cs61c.org/build/c-heap-d130519f96f5c27bc0c921f3ae2d7643.png) 

> [!NOTE]
> back-to-back heap memory requests can result in blocks that are quite far apart.

#### `void *malloc(size_t n)`
- Parameter size_t n: An unsigned integer type big enough to “count” memory bytes.
- Return: void * pointer, i.e., a pointer to generic space 
- A return value NULL indicates there is no more memory available on the heap.

#### ` void free(void *ptr)`


#### `void *realloc(void *ptr, size_t size)`
- `realloc` is a function that resizes a previously allocated block at ptr to a new size. In doing so, it may need to copy all data to a new location.
- Parameter `void *ptr`: A pointer containing an address originally returned by `malloc/realloc`, OR the value `NULL`.
- Parameter size_t size: An unsigned integer type big enough to “count” memory bytes.
- Return: like `malloc`

#### ` void *calloc(size_t nelem, size_t elsize)1`;
- it initializes all bits in the allocated block to zero
- so it is ***Recommended*** rather than `malloc` 
`nelem`: The number of elements to allocate. 
`elsize`: The element size in bytes. 
`void *`: Returns a generic pointer to the lowest byte address of the allocated space. If the allocation fails, it returns NULL

> [!IMPORTANT]
>  to catch memory management errors, use tools like [Valgrind](https://valgrind.org/) 


# Compiling

`C` doesn’t really have a “read-evaluate-print” loop (`REPL`). Instead, the cycle is “edit file, compile, link, run, find error”, meaning that development may be much slower.
> But you can compile maltiable files in parallel using `make -j`  

>Even if you compile files in parallel , it still go to bottleneck  because there is also other part remain serial like linking stage  This “serial bottleneck” is an example of **Amdahl’s Law**

Use -save-temps option to `gcc` to see result of preprocessing  

> `gcc -std=c{version}` to compile

# C variable 
> it's recommended to use `uintN_t/intN_t` to ensure the number of allocated bits , `N` refer to number of bits 
___
# Pointer and Bugs

### bugs type:
  1. **Heisenbugs** : this bugs seems to random and hard to change while debug 
  2. **Bohbugs** : this bugs is repeatable and easy to debug  

> Note that address is non-negative number ,so it doesn't make sense to make pointer of type `signed int` , use 

> `int *p = &y` , `int z = *p` : `*` is called dereferencing operator 

```c++
int *p , x 
// initially both contain  garbage value 
```

> ***dereferencing*** : get value that pointed by pointer `p`

# using pointer effectively   

> > [!NOTE]
> that each byte(8 bits) in has it's own memory address
> pointer store the memory address of the ***least/first*** byte of object (.e.g `int`(4byte), `float`(6byte), `char`(1byte)) 


```cpp
typedef struct {
  int x;
  int y;
}Point;
Point p1;
Point p2;
Point *ppt;

ppt->x;
        // you can use both 
*ppt.x; 

/* this work too*/
p1 = p2 // there is no usage of pointer here 
```

> `sizeof(type/structtype)` return number of ***bytes*** that are allocated this type 

> Declaring the type of a pointer determines how the dereferencing operator (*) works, (i.e., how many bytes to read/write when we “follow” pointers).

> ==> [!IMPORTANT]
>  `void *` is a generic pointer that can point to anything
> it's recommended to use generic pointer sparingly in memory management 

# Pointer Arithmetic 
  - `ptr + n` adds ` n*sizeof(*ptr)` bytes to the memory address stored in `ptr`.

  - `ptr - n` subtracts `n*sizeof(*ptr)` bytes from the memory address stored in `ptr`.

---
# Array

> Declaration : A C array is really just a big block of consecutive things in memory with certain properties.


> [!IMPORTANT]
> The expression arr[i] is equivalent to the expression *(arr+i). The latter treats the array name arr as a pointer, increments it, then dereferences.

```
There is one difference between an array name [(such as a)] and a pointer [(such as pa)] that must be kept in mind. A pointer is a variable, so pa=a and pa++ are legal. But an array name is not a variable; constructions like a=pa and a++ are illegal.
```


> [!IMPORTANT]
> The name of an array is a synonym for the location of the initial element.

> [!IMPORTANT]
> definition `int arr[]` is syntactic sugar for the definition `int *arr`,****When used as formal parameters for function definitions****.

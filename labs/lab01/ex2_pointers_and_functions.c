#include "stdio.h"

int main() {
  int my_var = 2;
  int *my_var_p = &my_var;
  printf("Memory Address of my_var = %p\n", &my_var);
  printf("Memory Address of my_var = %p\n", my_var_p);
  printf("value fo my_var = %d\n", my_var);
  printf("value fo my_var = %d\n", *my_var_p);
  printf("memory address of my_var_p = %p\n\n", &my_var_p);

  int *tmp = my_var_p;
  my_var_p += 2; // each increasing we go through int object with size =
                 // sizeof(int)4 bits
  printf("Memory Address of my_var = %p\n", &my_var);
  printf("new Memory Address = %p\n", my_var_p);
  printf("value fo my_var = %d\n", my_var);
  printf("the new object that are pointed to it = %d\n", *my_var_p);
  printf("diff between new memory and oldest = %ld\n", -(tmp - my_var_p));
  printf("memory address of my_var_p = %p\n", &my_var_p);
}

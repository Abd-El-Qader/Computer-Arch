#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
long long sz(int arr[] /* int *arr */) {
  printf("%ld", sizeof(arr) / sizeof(int));
} // int arr [] in function parapeter int *arr

size_t Strlen(char s[]) {
  size_t n = 0;
  while (*(s++) != 0) {
    n++;
  }
  return n;
}

void prints(char *s) {
  while (*(s++) != 0) {
    printf("%c", *s);
  }
}
/*int main() {
  int *p, *q, x;
  int a[4];
  p = &x;
  q = a + 1;
  printf("%p\n", &p);
  printf("%p\n", &q);
  printf("%p\n", p);
  printf("%ld", sizeof(a) / sizeof(int));
}*/
// null terminator -> '\0' is equal 0

int main() {
  char str[] = {'a', 'b', 'c', 'd', 'e', 'f', '\0'};
  char *my_str = "example";
  // when we put `"`  in word it will be like str array , \0 it will be added
  // my_str
  printf("%ld\n", strlen(my_str));
  printf("%ld\n", strlen(str));
  char *s;
  strcpy(s, my_str);
  prints(s);

  //---
  char *my_immutable_str = "malik"; // this is immutable because it's stored in
                                    // the read-only data segment

  char my__str[] = "malik"; // it's mutable because it's stored in stack
}

/*
 * Arrays decay to pointers when used in functions IMPORTANT
 * */

#include <stdio.h>
void func(int arr[], size_t n) {
  printf("size of int pointer %ld\n", sizeof(arr));
  printf("size of array %ld\n", n);
}
int main() {
  int arr[] = {1, 2, 3, 4};
  int *p = arr;
  printf("%d\n", p[0]); // p[0] = *(p)
  printf("%d\n", p[1]); // p[1] = *(p+1)
  printf("%d\n\n", *(p + 2));
  func(arr, sizeof(arr) / 4); // sizeof(arr) will get sum of all object inside
                              // array (int = 4)
}

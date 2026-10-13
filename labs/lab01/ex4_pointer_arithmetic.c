#include <stdint.h>
#include <stdio.h>
// each byte has it's own memory address
int main() {
  int ints[8];
  int8_t byts[8];
  // (void*)ip , convert ip from pointer int type to void pointer
  // and also (char*) ip , it convert ip to char pointer
  int *ip = ints;
  // ip += 5 -> ip += 5*sizeof(int);
  // ip -= 5 -> ip -= 5*sizeof(int);

  int8_t *bp = byts;
  printf("int*:    %p -> %p (diff: %td bytes)\n", (void *)ip, (void *)(ip + 5),
         (void *)(ip + 5) - (void *)ip);
  printf("int8_t*: %p -> %p (diff: %td bytes)\n", (void *)bp, (void *)(bp + 5),
         (void *)(bp + 5) - (void *)bp);
}

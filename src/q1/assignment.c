#include <stdio.h>

int main(int arg, char* argc[]){
  printf("Int: %d\n", sizeof(int));
  printf("Int Pointer: %d\n", sizeof(int*));
  printf("Long: %d\n", sizeof(long));
  printf("Double Pointer: %d\n", sizeof(double*));
  printf("Char Double Pointer: %d\n", sizeof(char**));
  return 0;
}

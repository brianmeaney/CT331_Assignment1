#include <stdio.h>
#include "tests.h"
#include "genericLinkedList.h"

//create print functions for different data types
void printChar(void* data){
	printf("Char: %c\n", *(char*)data);
}

void printInt(void* data){
	printf("Int: %d\n", *(int*)data);
}

void printString(void* data){
	printf("String: %s\n", data);
}

void printLong(void* data){
	printf("Long: %ld\n", *(long*)data);
}
void printDouble(void* data){
	printf("Double: %f\n", *(double*)data);
}
void printFloat(void* data){
	printf("Float: %f\n", *(float*)data);
}

void runTests(){
  printf("Tests running...\n");

  //create empty
  genListElement *e = NULL;
  
  char c = 'C';
  push(&e, &c, 30, &printChar);
  
  int i = 10;
  push(&e, &i, sizeof(int), &printInt);
  
  long l  = 20;
  push(&e, &l, sizeof(long), &printLong);
  
  double d = 45.23;
  push(&e, &d, sizeof(double), &printDouble);
  
  float f = 85.3;
  push(&e, &f, sizeof(float), &printFloat);
  
  char s[] = "StringTest";
  push(&e, &s, sizeof(s), &printString);
  
  traverse(e);
  printf("Length: %d", length(e));

  printf("\nTests complete.\n");
}

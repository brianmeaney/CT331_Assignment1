#include <stdio.h>
#include "tests.h"
#include "linkedList.h"

void runTests(){
	//testing stack - push and pop
  printf("Tests running...\n");
  printf("TESTING STACK\n");
  listElement* k = NULL;   //create blank element
  push(&k, "HEY", 30);  //push values
  push(&k, "YOU", 30);
  push(&k, "THERE", 30);
  traverse(k);
  printf("Length: %d", length(k));
  printf("TESTING POP\n");
  *pop(&k); 
  traverse(k);
  printf("Length: %d", length(k));
  
  
  //tetsting queue - enqueue and dequeue
  printf("\n\nTESTING QUEUE\n");
  listElement* q = NULL;
  enqueue(&q, "FIRST", 30);
  enqueue(&q, "SECOND", 30);
  enqueue(&q, "THIRD", 30);
  traverse(q);
  printf("Length: %d", length(q));
  printf("\nTESTING DEQUEUE\n");
  dequeue(q);
  traverse(q);
  printf("Length: %d", length(q));

  printf("\nTests complete.\n");
}

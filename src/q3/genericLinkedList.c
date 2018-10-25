#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"


//Creates a new linked list element with given content of size
//Returns a pointer to the element
genListElement* createEl(void* data, size_t size, printFunc print){
  genListElement* e = malloc(sizeof(genListElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }
  void* dataPointer = malloc(size);
  if(dataPointer == NULL){
    //malloc has had an error
    free(e); //release the previously allocated memory
    return NULL; //return NULL to indicate an error.
  }
  memmove(dataPointer, data, size);
  e->data = dataPointer;
  e->size = size;
  e->print = print; 
  e->next = NULL;
  return e;
}

//Prints out each element in the list
void traverse(genListElement* start){
  genListElement* current = start;
  while(current != NULL){
    current-> print(current->data);  //calls print function for data type and passes in the data
    current = current->next;
  }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
genListElement* insertAfter(genListElement* el, void* data, size_t size, printFunc print){
  genListElement* newEl = createEl(data, size, print);
  genListElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}


//Delete the element after the given el
void deleteAfter(genListElement* after){
  genListElement* delete = after->next;
  genListElement* newNext = delete->next;
  after->next = newNext;
  //need to free the memory because we used malloc
  free(delete->data);
  free(delete);
}

int length(genListElement* list){
	int size = 0;
	genListElement* curr = list;
	while(curr != NULL){
		//increments size while list is not empty
		size++;
		curr = curr->next;
	}
	return size;
}


void push(genListElement** list, void* data, size_t size, printFunc print){
	genListElement *element = createEl(data, size, print);
    element->next = *list;  //makes *list equal list next to element
	*list = element;  //inserts new element as *list
}	

genListElement* pop(genListElement** list){
	genListElement *head = *list;
	if(head) {
		*list = head->next;
	}
	return head;
}

void enqueue(genListElement **list, void *data, size_t size, printFunc print){
	genListElement *element = createEl(data, size, print);
    element->next = *list;
	*list = element;
}

genListElement* dequeue(genListElement* list){
	genListElement *find = list;
	
	while((find->next)->next != NULL){
		find = find->next;
		//finds element before tail
	}
	genListElement *tail = find->next;
	find->next = NULL;
	return tail;
}	

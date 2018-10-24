#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

typedef struct listElementStruct{
  char* data;
  size_t size;
  struct listElementStruct* next;
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(char* data, size_t size){
  listElement* e = malloc(sizeof(listElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }
  char* dataPointer = malloc(sizeof(char)*size);
  if(dataPointer == NULL){
    //malloc has had an error
    free(e); //release the previously allocated memory
    return NULL; //return NULL to indicate an error.
  }
  strcpy(dataPointer, data);
  e->data = dataPointer;
  e->size = size;
  e->next = NULL;
  return e;
}

//Prints out each element in the list
void traverse(listElement* start){
  listElement* current = start;
  while(current != NULL){
    printf("%s\n", current->data);
    current = current->next;
  }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, char* data, size_t size){
  listElement* newEl = createEl(data, size);
  listElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after){
  listElement* delete = after->next;
  listElement* newNext = delete->next;
  after->next = newNext;
  //need to free the memory because we used malloc
  free(delete->data);
  free(delete);
}

int length(listElement* list){
	int size = 0;
	listElement* curr = list;
	while(curr != NULL){
		//increments size while list is not empty
		size++;
		curr = curr->next;
	}
	return size;
}


void push(listElement** list, char* data, size_t size){
	listElement *element = createEl(data, size);
    element->next = *list;  //makes *list equal list next to element
	*list = element;  //inserts new element as *list
}	

listElement* pop(listElement** list){
	listElement *head = *list;
	if(head) {
		*list = head->next;
	}
	return head;
}

void enqueue(listElement **list, char *data, size_t size){
	listElement *element = createEl(data, size);
    element->next = *list;
	*list = element;
}

listElement* dequeue(listElement* list){
	listElement *find = list;
	
	while((find->next)->next != NULL){
		find = find->next;
		//finds element before tail
	}
	listElement *tail = find->next;
	find->next = NULL;
	return tail;
}	

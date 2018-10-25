#ifndef CT331_ASSIGNMENT_GENERIC_LINKED_LIST
#define CT331_ASSIGNMENT_GENERIC_LINKED_LIST

//function pointer definition, takes in data
typedef void (*printFunc) (void *data);

typedef struct genListElementStruct{
  void* data;
  size_t size;
  printFunc print;  //print function def
  struct genListElementStruct* next;
} genListElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
genListElement* createEl(void* data, size_t size, printFunc);

//Prints out each element in the list
void traverse(genListElement* start);

//Inserts a new element after the given el
//Returns the pointer to the new element
genListElement* insertAfter(genListElement* after, void* data, size_t size, printFunc);

//Delete the element after the given el
void deleteAfter(genListElement* after);

int length(genListElement* list);

void push(genListElement** list,void* data, size_t size, printFunc);

genListElement* pop(genListElement** list);

void enqueue(genListElement **list, void *data, size_t size, printFunc);

genListElement* dequeue(genListElement* list);

#endif

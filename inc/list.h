#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include <stdbool.h>

typedef struct {
  String_View *name;
  unsigned int hfactor;

}List_Entry;

typedef struct {
  size_t size;
  List_Entry head;

}List;


// Creates an empty list. Returns NULL if allocation fails. 
List *list_create(void);

// Adds a name. Returns -1 if allocation fails. 
int list_add(List *list,List_Entry node);

// Returns the first node holding value, or NULL if it is not found. 
Node *list_find(List *list, String_View name);

// Removes the first node holding the name. Returns -1 if it is not found. 
int list_remove(List *list,  String_View name);

// Prints the list in the form [1 -> 2 -> 3]. 
void list_print( List *list);

// Frees every node and the list itself. The list must not be used afterward.
void list_destroy(List *list);

#endif

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  String_View *name;
  unsigned int hfactor;

}List_Entry;

typedef struct {
  size_t size;
  List_Entry head;

}List;

List *list_create() {
  List *list = malloc(sizeof(List));
  *list = { .size = 0, .head = NULL };
  return list;
}

int list_add(List *list,) {

}

int main() {
  
}

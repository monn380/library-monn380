#include <stdio.h>
#include <stdlib.h>

typedef struct {
  String_View *name;
  bool hfactor;
  struct List_Entry next;
}List_Entry;

typedef struct {
  size_t count;
  List_Entry *head;
}List;

List *list_create() {
  List *list = malloc(sizeof(List));
  *list = { .count = 0, .head = NULL };
  return list;
}

int list_add(List *list,String_View name, bool hfactor) {
  if(!list->head) {
    malloc(sizeof(List_Entry));
  }
}



int main() {
  
}

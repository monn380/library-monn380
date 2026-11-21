#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "string_view.c"

typedef struct {
  String_View *name;
  bool hfactor;
  struct List_Entry *next;
}List_Entry;

typedef struct {
  size_t count;
  List_Entry *head;
}List;

List_Entry *entry_alloc(){
  List_Entry *entry = malloc(sizeof(List_Entry));
  *entry = {0};
  if (!entry) { 
    fprintf(stderr, "fatal error: memory allocation failed\n exiting now\n"); 
    exit(EXIT_FAILURE);
  }
  return entry;
}

List *list_create() {
  List *list = malloc(sizeof(List));
  *list = { .count = 0, .head = NULL };
  return list;
}

int list_add(List *list,String_View name, bool hfactor) {
  if(!list->head){
    list->head = entry_alloc();
    list->head = { .name = sv_dup(name), .hfactor = hfactor};
    return 0;
  } else {
    List_Entry *i = list->head.next;
      while(!i) { i = i.next;}
      i.next = entry_alloc();
      i->next = { .name = sv_dup(name), .hfactor = hfactor};
      return 0;
  }
}  


int main() {
  List *prova = list_create();
  list_add(prova,sv("star knightess aura"), 1);
}

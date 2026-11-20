#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SV_Fmt "%.*s"
#define SV_Arg(sv) (int)(sv).len, (sv).data 

typedef struct{
  char *data;
  size_t len;
}String_View;

int sv_equal(String_View *a, String_View *b) {
  if (a->len != b->len) return 0;
  for (size_t i = 0; i< a->len;i++) { 
    if (a->data[i] != b->data[i]) return 0;
  }
  return 1;
}

void sv_chop_right(String_View *sv, size_t n) {
  if (sv->len < n) n = sv->len;
  sv->len -= n;
}

void sv_chop_left(String_View *sv, size_t n) { 
  if (n > sv->len) n = sv->len;
  sv->len -= n;
  sv->data += n;
}

String_View sv_take(String_View sv, size_t n) {
  sv_chop_right(&sv, sv.len - n);
  return sv;
}

String_View sv_take_last(String_View sv, size_t n) {
  sv_chop_left(&sv, sv.len - n);   
  return sv;
}
String_View sv(char *cstring) {
  return (String_View) {.data = cstring, .len = strlen(cstring)};
}

void sv_trim_left(String_View *sv) {
  while (sv->len > 0 && isspace((unsigned char)sv->data[0])) {
    sv_chop_left(sv, 1);
  }
}

void sv_trim_right(String_View *sv) {
  while (sv->len > 0 && isspace((unsigned char)sv->data[sv->len-1])) {
    sv_chop_right(sv, 1);
  }
}

void sv_trim(String_View *sv) {
  sv_trim_right(sv);
  sv_trim_left(sv);
}

String_View sv_chop_by_delim (String_View *sv, char delim) {
  size_t i = 0;
  while (i < sv->len && sv->data[i] != delim) {
    i++;
  }
  //found delimiter
  if (i < sv->len) {
    String_View result = sv_take(*sv, i);
    sv_chop_left(sv, i + 1);
    return result;
  }

  String_View result = *sv;
  sv_chop_left(sv, sv->len);
  return result;
}

String_View sv_chop_by_type (String_View *sv, int (*istype)(int c)) {
  size_t i = 0;
  while (i < sv->len && !istype((unsigned char)sv->data[i])) {
    i++;
  }
  //found by type
  if (i < sv->len) { 
    String_View result = sv_take(*sv, i);
    sv_chop_left(sv, i + 1);
    return result;
  }

  String_View result = *sv;
  sv_chop_left(sv, sv->len);
  return result;
}

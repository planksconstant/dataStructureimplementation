#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  size_t size;
  int *data;
} int_vector;

int_vector *create_vector(size_t n) {
  int_vector *p = malloc(sizeof(int_vector));
  if (p) {
    p->data = malloc(n * sizeof(int));
    p->size = n;
  }
  return p;
}

void delete_vector(int_vector *v) {
  if (v) {
    free(v->data);
    free(v);
  }
}
size_t resize_vector(int_vector *v, size_t n) {
  if (v) {
    int *p = realloc(v->data, n * sizeof(int));
    if (p) {
      v->data = p;
      v->size = n;
    }
    return v->size;
  }
  return 0;
}
int get_vector(int_vector *v, size_t n) {
  if (v && n < v->size) {
    return v->data[n];
  }
  return -1;
}
void set_vector(int_vector *v, size_t n, int x) {
  if (v) {
    if (n >= v->size) {
      resize_vector(v, n + 1);
    }
    v->data[n] = x;
  }
}
int main() {
  int_vector *v = create_vector(2);
  set_vector(v, 0, 10);
  set_vector(v, 1, 20);
  set_vector(v, 5, 50);
  printf("Value at 5: %d\n", get_vector(v, 5));
  printf("Current Size: %zu\n", v->size);
  printf("=========");
  for (int i = 0; i < 10; i++) {
    printf("Value at 5: %d\n", get_vector(v, i));
  }
  delete_vector(v);
  return 0;
}

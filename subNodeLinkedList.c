#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  struct Node *subnode;
  int data;
  struct Node *next;

} Node;

int main() {
  int n = 10;
  Node *Head = NULL;
  Node *Tail = NULL;
  Node *placeholder = NULL;
  for (int i = 0; i < n; i++) {
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = i * i + 4;
    new->subnode = NULL;
    new->next = NULL;

    if (i == 4) {
      placeholder = new;
    }
    if (i == 7) {
      new->subnode = placeholder;
    }
    if (Head == NULL) {
      Head = new;
      Tail = new;
    } else {
      Tail->next = new;
      Tail = new;
    }
  }
  Node *tmp = Head;

  while (tmp != NULL) {
    printf("%d -> ", tmp->data);
    if (tmp->subnode != NULL) {
      printf("CYCLE FOUND ");
      printf("The data is %d", tmp->subnode->data);
    }
    printf("-> ");
    tmp = tmp->next;
  }
  printf("NULL");
}

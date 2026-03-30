#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int elem;
  struct Node *next;
} Node;

int main() {
  Node *head = NULL;
  Node *temp = NULL;
  Node *newNode = NULL;

  printf("How many nodes? ");
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    newNode = (Node *)malloc(sizeof(Node));
    printf("Enter element %d: ", i + 1);
    scanf("%d", &newNode->elem);
    newNode->next = NULL;

    if (head == NULL) {
      head = newNode;
      temp = head;
    } else {
      temp->next = newNode;
      temp = newNode;
    }
  }

  printf("\nLinked List: ");
  temp = head;
  while (temp != NULL) {
    printf("%d -> ", temp->elem);
    temp = temp->next;
  }
  printf("NULL\n");

  return 0;
}

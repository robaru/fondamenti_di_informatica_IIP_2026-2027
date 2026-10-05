#include <stdio.h>
#include <stdlib.h>

// #define DEBUG

struct Node
{
  int value;
  struct Node *next;
};

void print_list(struct Node *head);
struct Node *new_node(int val);
struct Node *insert_head(struct Node *head, int val);
void insert_after(struct Node *prev, int val);

int main()
{
  struct Node *head = new_node(10);
  head = insert_head(head, 20);
  head = insert_head(head, 30);
  insert_after(head, 40);

  print_list(head);

  return 0;
}

void print_list(struct Node *head)
{
  while (head != NULL)
  {
#ifdef DEBUG
    printf("(value: %d, next: %p) -> ", head->value, head->next);
#else
    printf("%d -> ", head->value);
#endif
    head = head->next;
  }
  printf("NULL\n");
}

struct Node *new_node(int val)
{
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));

  if (node != NULL)
  {
    node->value = val;
    node->next = NULL;
  }

#ifdef DEBUG
  printf("Created new node at location: %p\n", node);
  printf("Node value: %d\n", node->value);
  printf("Node next: %p\n", node->next);
#endif

  return node;
}

struct Node *insert_head(struct Node *head, int val)
{
  struct Node *new_head = new_node(val);
  new_head->next = head;

  return new_head;
}

void insert_after(struct Node *prev, int val)
{
  if (prev == NULL)
  {
    return;
  }

  struct Node *node = new_node(val);
  node->next = prev->next;
  prev->next = node;
}

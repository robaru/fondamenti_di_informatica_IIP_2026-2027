#include <stdio.h>
#include <stdlib.h>

// #define DEBUG_PRINT
// #define DEBUG_CREATE
#define DEBUG_FREE

struct Node
{
  int value;
  struct Node *next;
};

void print_list(struct Node *head);
struct Node *new_node(int val);
void free_list(struct Node *head);

struct Node *insert_head(struct Node *head, int val);
void insert_after(struct Node *prev, int val);
struct Node *insert_tail(struct Node *head, int val);

struct Node *remove_head(struct Node *head);
void remove_after(struct Node *prev);
struct Node *remove_tail(struct Node *head);

struct Node *find_node(struct Node *head, int val);

int main()
{
  struct Node *head = new_node(10);
  print_list(head);
  printf("----\n");

  head = insert_head(head, 20);
  head = insert_head(head, 30);
  print_list(head);
  printf("----\n");

  insert_after(head, 40);
  print_list(head);
  printf("----\n");

  head = remove_head(head);
  print_list(head);
  printf("----\n");

  remove_after(head);
  print_list(head);
  printf("----\n");

  head = remove_tail(head);
  print_list(head);
  printf("----\n");

  head = insert_tail(head, 100);
  head = insert_tail(head, 110);
  head = insert_tail(head, 120);
  head = insert_tail(head, 130);
  head = insert_tail(head, 120);
  print_list(head);
  printf("----\n");

  struct Node *found_val = find_node(head, 120);
  if (found_val != NULL)
  {
    insert_after(found_val, 125);
  }
  else
  {
    printf("Error, node not found!\n");
  }
  print_list(head);
  printf("----\n");

  free_list(head);

  return 0;
}

void print_list(struct Node *head)
{
  while (head != NULL)
  {
#ifdef DEBUG_PRINT
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

#ifdef DEBUG_CREATE
  printf("Created new node at location: %p\n", node);
  printf("Node value: %d\n", node->value);
  printf("Node next: %p\n", node->next);
#endif

  return node;
}

void free_list(struct Node *head)
{
  struct Node *current = NULL;
  while (head != NULL)
  {
    current = head;
    head = head->next;

#ifdef DEBUG_FREE
    printf("Free node @ %p: (value: %d, next = %p)\n", current, current->value, current->next);
#endif

    free(current);
  }
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

struct Node *insert_tail(struct Node *head, int val)
{
  if (head == NULL)
  {
    return insert_head(head, val);
  }

  struct Node *last = head;
  while (last->next != NULL)
  {
    last = last->next;
  }

  insert_after(last, val);

  return head;
}

struct Node *remove_head(struct Node *head)
{
  if (head == NULL)
  {
    return NULL;
  }

  struct Node *old_head = head;
  head = head->next;

  free(old_head);

  return head;
}

void remove_after(struct Node *prev)
{
  if (prev == NULL || prev->next == NULL)
  {
    return;
  }

  struct Node *node_to_remove = prev->next;
  prev->next = node_to_remove->next;

  free(node_to_remove);
}

struct Node *remove_tail(struct Node *head)
{
  // empty list
  if (head == NULL)
  {
    return NULL;
  }

  // list with a single node
  if (head->next == NULL)
  {
    return remove_head(head);
  }

  // list with 2+ nodes
  struct Node *tail = head;
  struct Node *prev = NULL;
  while (tail->next != NULL)
  {
    prev = tail;
    tail = tail->next;
  }

  remove_after(prev);

  return head;
}

struct Node *find_node(struct Node *head, int val)
{
  while (head != NULL)
  {
    if (head->value == val)
    {
      return head;
    }
    head = head->next;
  }

  return NULL;
}

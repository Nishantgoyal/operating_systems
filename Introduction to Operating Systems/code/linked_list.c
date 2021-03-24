#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *Next;
};
int get_value();
struct Node *create_node();
struct Node *insert_into_list(struct Node *head);
struct Node *delete_from_list(struct Node *head);
void print_list(struct Node *head);

int main()
{
  struct Node *head;
  head = NULL;
  char choice = 'c';
  while (choice != 'x')
  {
    printf("\nPlease Choose an Option: [i:insert, p:print list, d:delete, x:exit] \t");
    scanf(" %c", &choice);
    if (choice == 'i')
    {
      head = insert_into_list(head);
    }
    else if (choice == 'p')
    {
      print_list(head);
    }
    else if (choice == 'd')
    {
      head = delete_from_list(head);
    }
  }
}

int get_value()
{
  int value;
  printf("Please Enter a Integer Value : ");
  scanf(" %d", &value);
  return value;
}

struct Node *create_node()
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = get_value();
  newNode->Next = NULL;
  return newNode;
}

struct Node *insert_into_list(struct Node *head)
{
  printf("Inserting a value in the LinkedList\n");
  if (head == NULL)
  {
    head = create_node();
  }
  else
  {
    struct Node *temp = head;
    while (temp->Next != NULL)
    {
      temp = temp->Next;
    }
    temp->Next = create_node();
  }
  return head;
}
struct Node *delete_from_list(struct Node *head)
{
  printf("Deleting an element from the list\n");
  if (head == NULL)
  {
    printf("Empty List");
  }
  else
  {
    int value_to_be_deleted = get_value();
    if (head->data == value_to_be_deleted)
    {
      head = head->Next;
      printf("Value Deleted");
    }
    else
    {
      struct Node *previous = head;
      struct Node *current = head->Next;
      while (current != NULL)
      {
        if (current->data == value_to_be_deleted)
        {
          previous->Next = current->Next;
          printf("Value Deleted");
          break;
        }
        else
        {
          previous = previous->Next;
          current = current->Next;
        }
      }
    }
  }
  return head;
}
void print_list(struct Node *head)
{
  if (head == NULL)
  {
    printf("Empty List...!");
    return;
  }
  printf("Printing the list...\n");
  struct Node *temp = head;
  while (temp != NULL)
  {
    printf("%d\t", temp->data);
    temp = temp->Next;
  }
}

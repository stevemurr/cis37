/*
12.9
Creating a linked list, then reversing its elements
Write a program that creates a linked list of 10 characters, then creates a copy
of the list in reverse order.

1) essentially we are going to insert into the new list as such
2) first elements is NULL
3) next element points to last element seen.
4) continue until length of list.

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

struct node {
  char letter;
  struct node* next;
};

typedef struct {
  unsigned int counter;
} Counter;

int CountLinkedList( struct node* list );
int Length( struct node* head );
void PrintLinkedList( struct node* head );
void AddElementToList( struct node* head, char value );
void BootStrapList(struct node* a);
void Concatenate( struct node* a, struct node* b);
int GenerateRandomNumber( int max );
void Push( struct node** headRef, char value );
void InsertElementInSortedOrder( struct node* list, int value ); // This is the
                                                                 // most amazing
                                                                 // function.

int main( void )
{
  struct node* list = malloc(sizeof(struct node));
  struct node* reversedList = malloc(sizeof(struct node));
  struct node* current = list;
  BootStrapList(list);
  PrintLinkedList(list);
  while ( current != NULL ) {
    Push( &reversedList, current->letter );
    current = current->next;
  }
  PrintLinkedList(reversedList);
}

void Push( struct node** headRef, char value )
{
  struct node* newNode = malloc(sizeof(struct node));

  newNode->letter = value;
  newNode->next = *headRef;
  *headRef = newNode;
}

void BootStrapList(struct node* a)
{
  AddElementToList(a, 'a');
  AddElementToList(a, 'b');
  AddElementToList(a, 'c');
  AddElementToList(a, 'd');
}
int CountLinkedList( struct node* list )
{
    struct node* current = list; // this is a pointer that get the pointer to
                                 // the head node.
    int count = 0; // counter variable

    while ( current != NULL ) // while current is not NULL run the loop
    {
      count = count + current->letter; // increment the count
      current = current->next; // current gets current->next
    }
    return count;
}

int GenerateRandomNumber( int max )
{
  int random_number;
  return rand() % max;
}

void Concatenate( struct node* a, struct node* b )
{
  struct node* current = a;
  struct node* second = b;

  while ( second->next != NULL ) { // loop over the second list
    AddElementToList(a, second->letter); // add the value from the second list
                                         // to the first list
    second = second->next; // second position moves up
  }
  AddElementToList(a, second->letter); // handles the final value in the second
                                      // list.
}

int Length( struct node* head )
{
  struct node* current = head; // this is a pointer that get the pointer to
                               // the head node.
  int count = 0; // counter variable

  while ( current != NULL ) // while current is not NULL run the loop
  {
    count++; // increment the count
    current = current->next; // current gets current->next
  }
  return count;
}

void PrintLinkedList( struct node* head )
{
  struct node* current = head;
  while ( current != NULL ) {
    printf("%c ", current->letter);
    current = current->next;
  }
  puts("");
}

void AddElementToList( struct node* head, char value )
{
  struct node* current = head;
  struct node* newNode = malloc(sizeof( struct node ));
  newNode->letter = value;
  newNode->next = NULL;
  if (Length(head) == 0) { // If the list is empty add this element.
    head = newNode;
  } else { // Else append the element to the back of the list.
    while ( current->next != NULL ) {
      current = current->next;
    }
    current->next = newNode;
  }
}

void InsertElementInSortedOrder( struct node* list, int value )
{
  struct node* newPtr;
  struct node* previousPtr;
  struct node* currentPtr;

  newPtr = malloc(sizeof(struct node));

  if ( newPtr != NULL ) {
    newPtr->letter = value;
    newPtr->next = NULL;

    previousPtr = NULL;
    currentPtr = list;

    while ( currentPtr != NULL && value > currentPtr->letter ) {
      previousPtr = currentPtr;
      currentPtr = currentPtr->next;
    }
    if ( previousPtr == NULL ) {
      newPtr->next = list;
      list = newPtr;
    }
    else {
      previousPtr->next = newPtr;
      newPtr->next = currentPtr;
    }
  }
  else {
    printf( "%c not inserted. no mem", value );
  }
}

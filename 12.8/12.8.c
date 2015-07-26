/*
12.8
Inserting into an ordered list

Write a program that inserts 25 random integers from 0 to 100 in order in a
linked list.  The program should calculate the sum of the elements and the
floating point average of the elements.

1. generate rand number from 0 to 100
2. insert into linked list
3. on insert ensure that new rand number is > then every other value in list.
4. calculate sum of values.

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

struct node {
  int letter;
  struct node* next;
};

typedef struct {
  unsigned int counter;
} Counter;

int CountLinkedList( struct node* list );
int Length( struct node* head );
void PrintLinkedList( struct node* head );
void AddElementToList( struct node* head, int value );
void BootStrapList(struct node* a);
void Concatenate( struct node* a, struct node* b);
int GenerateRandomNumber( int max );
void InsertElementInSortedOrder( struct node* list, int value ); // This is the
                                                                 // most amazing
                                                                 // function.

int main( void )
{
  time_t t;
  srand((unsigned) time(&t));
  struct node* listOne = malloc(sizeof(struct node));
  BootStrapList(listOne);
  PrintLinkedList(listOne);
  printf("The sum is: %d\n", CountLinkedList(listOne));
}

void BootStrapList(struct node* a)
{
  for (int i = 0; i < 25; i++) {
    InsertElementInSortedOrder(a, GenerateRandomNumber( 100 ));
  }
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
    printf("%d ", current->letter);
    current = current->next;
  }
  puts("");
}

void AddElementToList( struct node* head, int value )
{
  struct node* current = head;
  struct node* newNode = malloc(sizeof( struct node ));
  newNode->letter = value;
  newNode->next = NULL;
  if (head == NULL) { // If the list is empty add this element.
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

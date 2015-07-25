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

int Length( struct node* head );
void PrintLinkedList( struct node* head );
void AddElementToList( struct node* head, int value );
void BootStrapList(struct node* a);
void Concatenate( struct node* a, struct node* b);
int GenerateRandomNumber( int max );
void SortLinkedList( struct node* a );

int main( void )
{
  time_t t;
  srand((unsigned) time(&t));
  struct node* listOne = malloc(sizeof(struct node));
  BootStrapList(listOne);
  PrintLinkedList(listOne);
  SortLinkedList(listOne);
  PrintLinkedList(listOne);
}

void BootStrapList(struct node* a)
{
  for (int i = 0; i < 25; i++) {
    AddElementToList(a, GenerateRandomNumber( 100 ));
  }
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
  if (Length(head) == 0) { // If the list is empty add this element.
    head = newNode;
  } else { // Else append the element to the back of the list.
    while ( current->next != NULL ) {
      current = current->next;
    }
    current->next = newNode;
  }
}

void SortLinkedList( struct node* a )
{
  struct node* nextPtr = malloc(sizeof(struct node));
  struct node* previousPtr = malloc(sizeof(struct node));
  struct node* temp = malloc(sizeof(struct node));
  struct node* current = a;

  while ( current->next != NULL ) {
    if ( current->next->letter < current->letter ) {
      nextPtr = current->next->next;
      previousPtr = current->next;
      temp = current->next;
      current->next = current;
      current->next->next = nextPtr;
      current = previousPtr;
      current->next = previousPtr;
    }
  }
  //current->next = NULL;
}

/*
12.6
Concatenating Lists

Write a program that concatenates two linked lists of characters.  The
program should include function concatenate that takes pointers to both
lists as arguments and concatenates the second list to the first list

// Create linked lists of characters
// create function concatenate( *pointer to list, *pointer to list)
// append the second list to the first

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
  char letter;
  struct node* next;
};

int Length( struct node* head );
void PrintLinkedList( struct node* head );
void AddElementToList( struct node* head, char value );
void CreateLinkedList( struct node* initialHead, char value );
void BootStrapLists(struct node* a, struct node* b);
void Concatenate( struct node* a, struct node* b);

int main( void )
{

  struct node* listOne = malloc(sizeof(struct node));
  struct node* listTwo = malloc(sizeof(struct node));
  BootStrapLists(listOne, listTwo);
  Concatenate(listOne, listTwo);
  PrintLinkedList(listOne);

}

void CreateLinkedList( struct node* initialHead, char value )
{
  initialHead = malloc(sizeof( struct node ));
  initialHead->letter = value;
  initialHead->next = NULL;
}

void BootStrapLists(struct node* a, struct node* b)
{
  AddElementToList(a, 's');
  AddElementToList(a, 't');
  AddElementToList(a, 'e');
  AddElementToList(a, 'v');
  AddElementToList(a, 'e');

  AddElementToList(b, 'm');
  AddElementToList(b, 'u');
  AddElementToList(b, 'r');
  AddElementToList(b, 'r');

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
    printf("%c", current->letter);
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

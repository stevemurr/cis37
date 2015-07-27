/*
11.11
Write statements that accomplish each of the following.  Assume that the structure

struct person {
  char lastName[ 15 ];
  char firstNmae[ 15 ];
  char age[ 4 ];
};

has been defined and that the file is already open for writing.

a) Init the file "nameage.dat" with 100 records:
lastName = "unassigned", firstName="", age=""
b) input 10 records manually
c) update a record
d) delete a record
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char lastName[ 15 ];
  char firstName[ 15 ];
  char age[ 4 ];
} Person;

typedef struct Node {
  Person p;
  struct Node* next;
} Node;

FILE* OpenFile( FILE *FILE , char WriteFlag ); // Get a pointer to a file
void ReadFile( FILE *FILE , Node* Head ); // read records and return head
void BootStrapFile( FILE *FILE ); // creates basic file for assignment
void AddElementToList( Node* Head, Person p );
int Length( Node* Head );
void PrintLinkedList( Node* Head );
void FreeLinkedList( Node** Head );

int main( void )
{
  FILE *FilePointer = OpenFile(FilePointer, 'w');
  Node* Head = malloc(sizeof(struct Node));
  BootStrapFile(FilePointer);
  fclose(FilePointer);
  FilePointer = OpenFile(FilePointer, 'r');
  ReadFile( FilePointer, Head );
  fclose(FilePointer);
  FilePointer = OpenFile(FilePointer, 'r');
  ReadFile( FilePointer, Head );
  PrintLinkedList( Head );
}

void FreeLinkedList( Node** Head )
{
  Node* current = *Head;
  while ((current = *Head) != NULL ) {
    *Head = ;
    free(current);
  }
  *Head = NULL;
}

void PrintLinkedList( Node* Head )
{
  Node* current = Head;
  while ( current != NULL ) {
    printf("%s %s %s\n", current->p.lastName, current->p.firstName, current->p.age);
    current = current->next;
  }
}

int Length( Node* Head )
{
  Node* current = Head; // this is a pointer that get the pointer to
                               // the head node.
  int count = 0; // counter variable

  while ( current != NULL ) // while current is not NULL run the loop
  {
    count++; // increment the count
    current = current->next; // current gets current->next
  }
  return count;
}

void AddElementToList( Node* Head, Person p )
{
  Node* current = Head;
  Node* newNode = malloc(sizeof( Node ));
  strcpy(newNode->p.lastName, p.lastName);
  strcpy(newNode->p.firstName, p.firstName);
  strcpy(newNode->p.age, p.age);
  newNode->next = NULL;
  if ( current == NULL ) { // If the list is empty add this element.
    Head = newNode;
  } else { // Else append the element to the back of the list.
    while ( current->next != NULL ) {
      current = current->next;
    }
    current->next = newNode;
  }
}

void BootStrapFile( FILE *FILE )
{
   for ( int i = 0; i < 100; i++ )
   {
     Person p = {"unassigned", "na", "na" };
     fprintf( FILE, "%s %s %s\n", p.lastName, p.firstName, p.age );
   }
}

void ReadFile( FILE *FILE, Node* Head )
{
  char lastName[ 15 ];
  char firstName[ 15 ];
  char age[ 4 ];
  while (fscanf(FILE, "%s %s %s", lastName, firstName, age) != EOF) {
    Person p;
    strcpy( p.lastName, lastName );
    strcpy( p.firstName, firstName );
    strcpy( p.age, age );
    AddElementToList( Head, p );
  }
}

FILE* OpenFile( FILE *FILE , char WriteFlag )
{
  /*
  Write Flags:
  w - Open file for writing
  a - Append to the end of the file
  b - Write binary data to file - useful for writing structs
  r+ - Read and append
  */
  FILE = fopen("nameage.dat", &WriteFlag);
  return FILE;
}

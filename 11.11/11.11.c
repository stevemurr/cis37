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
  int record;
  Person p;
  struct Node* prev;
  struct Node* next;
} Node;

FILE* OpenFile( FILE *FILE , char WriteFlag ); // Get a pointer to a file
void ReadFile( FILE *FILE , Node* Head ); // read records and return head
void BootStrapFile( FILE *FILE ); // creates basic file for assignment
void AddElementToList( Node* Head, Person p );
int Length( Node* Head );
void PrintLinkedList( Node* Head );
void FreeLinkedList( Node** Head );
void WriteToFile( FILE* FILE, Node* Head );
void ManualEntry( Node* Head );
Node* SearchLinkedList( Node* Head, int record );
void UpdateRecord( Node* Head );
void DeleteRecord( Node* Head );

int main( void )
{
  FILE *FilePointer = OpenFile(FilePointer, 'w'); // Open file for writing
  Node* Head = malloc(sizeof(Node));

  BootStrapFile(FilePointer); // Create our base file
  fclose(FilePointer); // Close the file

  FilePointer = OpenFile(FilePointer, 'r'); // Reopen the file for reading
  ReadFile(FilePointer, Head); // Read file into linked lists
  PrintLinkedList( Head ); // Print the linked list
  fclose(FilePointer);
  FreeLinkedList(&Head);

  Head = (Node* )realloc(Head, sizeof(Node));
  FilePointer = OpenFile(FilePointer, 'r');
  ReadFile( FilePointer, Head );
  ManualEntry( Head );
  fclose(FilePointer);
  FilePointer = OpenFile(FilePointer, 'w'); // Reopen the file for reading

  WriteToFile( FilePointer, Head );
  fclose( FilePointer );
  FreeLinkedList( &Head );

  Head = (Node* )realloc(Head, sizeof(Node));
  FilePointer = OpenFile(FilePointer, 'r');
  ReadFile( FilePointer, Head );

  UpdateRecord( Head ); // Update record
  PrintLinkedList( Head );

  DeleteRecord( Head );
  PrintLinkedList( Head );

}

void UpdateRecord( Node* Head ) // found record from the search
{
  int record;
  printf("%s\n", "Which record do you want to update? ");
  scanf(" %d", &record );
  Node* SearchResult = SearchLinkedList( Head, record );
  char lastName[ 15 ];
  char firstName[ 15 ];
  char age[ 4 ];
  printf("%s", "Give me the updated values: lastname firstname age\n");
  scanf(" %s %s %s", lastName, firstName, age);
  strcpy( SearchResult->p.lastName, lastName );
  strcpy( SearchResult->p.firstName, firstName );
  strcpy( SearchResult->p.age, age );
}

void DeleteRecord( Node* Head ) // found record from the search
{
  int record;
  printf("%s\n", "Which record do you want to delete? ");
  scanf(" %d", &record );
  Node* SearchResult = SearchLinkedList( Head, record );
  SearchResult->prev->next = SearchResult->next;
}

Node* SearchLinkedList( Node* Head, int record )
{
  Node* current = Head;
  while ( current != NULL ) {
    if ( current->record == record ) {
      printf("%s\n", "Found it.");
      return current;
    } else {
      //printf("%s\n", "Didn't find it.");
    }
    current = current->next;
  }
  printf("%s\n", "No Info.");
  return Head;
}

void FreeLinkedList( Node** Head )
{
  Node* current = *Head;
  while (current != NULL ) {
    current = current->next;
    free(current);
  }
  *Head = NULL;
  free(*Head);
}

void ManualEntry( Node* Head )
{
  char lastName[ 15 ];
  char firstName[ 15 ];
  char age[ 4 ];
  Person p;
  printf("%s\n", "lastname firstname age");
  scanf(" %s %s %s", lastName, firstName, age);
  strcpy(p.lastName, lastName);
  strcpy(p.firstName, firstName);
  strcpy(p.age, age);
  AddElementToList(Head, p);
}

void PrintLinkedList( Node* Head )
{
  int record = 1;
  Node* current = Head;
  current = current->next;
  while ( current != NULL ) {
    current->record = record++;
    printf("%d %s %s %s\n", current->record, current->p.lastName, current->p.firstName, current->p.age);
    current = current->next;
  }
}

int Length( Node* Head )
{
  Node* current = Head; // this is a pointer that get the pointer to
                               // the head node.
  int count = 0; // counter variable

  while ( current != NULL ) { // while current is not NULL run the loop
    count++; // increment the count
    current = current->next; // current gets current->next
  }
  return count;
}

void AddElementToList( Node* Head, Person p )
{
  Node* current = Head;
  Node* newNode = malloc(sizeof( Node ));
  Node* previous;
  int record = 1;
  strcpy(newNode->p.lastName, p.lastName);
  strcpy(newNode->p.firstName, p.firstName);
  strcpy(newNode->p.age, p.age);
  newNode->next = NULL;
  if ( current == NULL ) { // If the list is empty add this element.
    Head = newNode;
    Head->record = record;
    Head->prev = NULL;
  } else { // Else append the element to the back of the list.
    while ( current->next != NULL ) {
      previous = current;
      current = current->next;
      record++;
    }
    current->prev = previous;
    current->next = newNode;
    current->next->record = record;
  }
}

void BootStrapFile( FILE *FILE )
{
   for ( int i = 0; i < 100; i++ )
   {
     Person p = {"unassigned", "na", "na"};
     fprintf( FILE, "%s %s %s\n", p.lastName, p.firstName, p.age );
   }
}

void WriteToFile( FILE *FILE, Node* Head )
{
  Node* current = Head;
  current = current->next;
  while ( current != NULL ) {
    fprintf(FILE, "%s %s %s\n", current->p.lastName, current->p.firstName, current->p.age);
    current = current->next;
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

/*
11.12
Hardware Inventory

You're the owner of a hardware store and need to keep an inventory that can tell
you what tools you have, how many you have and the cost of each one.  Write a
program that initalizes the file "hardware.dat" to 100 empty records, lets you
input the data concerning each tool, enables you to list all your tools, lets
delete a record for a tooll that you no longer have and lets you update any
information in the file.  The tool identification number should be the record
number.  Use the following information to start your file:

Record  Tool Name         Quantity  Cost
3       Electric Sander   7         57.98
17      Hammer            76        11.99
24      Jig saw           21        11.00
39      Lawn Mower        3         79.50
56      Power saw         18        99.99
68      Screwdriver       106       6.99
77      Sledge Hammer     11        21.50
83      Wrench            34        7.50

1) Create hardware.dat with 100 empty records.
2) Manual Entry
3) List tools
4) Delete a record
5) Update a record

*/
/*
11.11
Write statements that accomplish each of the following.  Assume that the structure

struct Tool {
  int record;
  char firstNmae[ 15 ];
  int quantity;
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
  char ToolName[ 30 ];
  int quantity;
  double cost;
} Tool;

typedef struct Node {
  int record;
  Tool p;
  struct Node* prev;
  struct Node* next;
} Node;

FILE* OpenFile( FILE *FILE , char WriteFlag ); // Get a pointer to a file
void ReadFile( FILE *FILE , Node* Head ); // read records and return head
void BootStrapFile( FILE *FILE ); // creates basic file for assignment
void AddElementToList( Node* Head, Tool p );
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
  char ToolName[ 30 ];
  int quantity;
  double cost;
  printf("%s", "Give me the updated values: toolname quantity cost\n");
  scanf(" %s %d %lf", ToolName, &quantity, &cost);
  strcpy( SearchResult->p.ToolName, ToolName );
  SearchResult->p.quantity = quantity;
  SearchResult->p.cost = cost;
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
  char ToolName[ 30 ];
  int quantity;
  double cost;
  Tool p;
  printf("%s\n", "toolname quantity cost");
  scanf(" %s %d %lf", ToolName, &quantity, &cost);
  strcpy(p.ToolName, ToolName);
  p.quantity = quantity;
  p.cost = cost;
  AddElementToList(Head, p);
}

void PrintLinkedList( Node* Head )
{
  int record = 1;
  Node* current = Head;
  current = current->next;
  while ( current != NULL ) {
    current->record = record++;
    printf("%d %s %d %f\n", current->record, current->p.ToolName, current->p.quantity, current->p.cost);
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

void AddElementToList( Node* Head, Tool p )
{
  Node* current = Head;
  Node* newNode = malloc(sizeof( Node ));
  Node* previous;
  int record = 1;
  strcpy(newNode->p.ToolName, p.ToolName);
  newNode->p.quantity = p.quantity;
  newNode->p.cost = p.cost;
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
     Tool p = {"unassigned", 0, 0.0};
     fprintf( FILE, "%s %d %lf\n", p.ToolName, p.quantity, p.cost );
   }
}

void WriteToFile( FILE *FILE, Node* Head )
{
  Node* current = Head;
  current = current->next;
  while ( current != NULL ) {
    fprintf(FILE, "%s %d %f\n", current->p.ToolName, current->p.quantity, current->p.cost);
    current = current->next;
  }
}

void ReadFile( FILE *FILE, Node* Head )
{

  char ToolName[ 30 ];
  int quantity;
  double cost;

  while (fscanf(FILE, "%s %d %lf", ToolName, &quantity, &cost) != EOF) {
    Tool p;
    strcpy( p.ToolName, ToolName );
    p.quantity = quantity;
    p.cost = cost;
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
  FILE = fopen("hardware.dat", &WriteFlag);
  return FILE;
}

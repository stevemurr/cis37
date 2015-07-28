

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char lastName[ 50 ];
  char firstName[ 50 ];
  char age[ 4 ];
} Person;

struct node {
  Person* p;
  struct node* next;
};

int main( void )
{
  Person p1 = {"Murr", "steve", "4"};
  struct node* PersonList = malloc(sizeof(struct node));
  struct node* PersonTwo = malloc(sizeof(struct node));
  PersonList->p = &p1;
  PersonList->next = NULL;
  Person p2 = {"Joe", "ann", "5"};
  PersonTwo->p = &p2;
  PersonTwo->next = NULL;
  PersonList->next = PersonTwo;

  struct node* iter = PersonList;
  while ( iter != NULL ) {
    printf("%s\n", iter->p->firstName);
    iter = iter->next;
  }
}

/*
8.23
Write a program that reads a series of strings and prints only those beginning
with the letter 'b'.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main( void )
{
  char str[80] = "This is by sentence with bees.";
  char *list_of_words;

  list_of_words = strtok(str, " ");
  while (list_of_words != NULL)
  {
    if (*list_of_words == 'b') {
      printf("%s\n", list_of_words);
    }
    //printf("%s\n", list_of_words);
    list_of_words = strtok(NULL, " ");
  }
}

/*
-- Application output --

[stevemurr@stevemurr-linux 8.23]$ ./8.23
by
bees.
/*

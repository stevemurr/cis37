/*
7.20
What does this program do?

*/

#include <stdio.h>
#define SIZE 80

int mystery2( const char *s );

int main( void )
{
  char string[ SIZE ];

  puts( "Enter a string: " );
  scanf("%79s", string);
  printf("%d\n", mystery2( string ) );
}

int mystery2( const char *s )
{
  int x;

  for ( x = 0; *s != '\0'; ++s) {
    ++x;
  }
  return x;
}

/*
This program begins by initializing an array of chars and prompting the user to
enter a string.  The mystery function then loops through the char array until
it reaches the null terminator.  Each time through the iteration we are
incrementing the value of x.  In essence we are finding the length of the string.

-- Application output --

Enter a string:
steven
6

*/

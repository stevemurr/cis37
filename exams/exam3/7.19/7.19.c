/*
7.19
What does this program do, assuming that the user enters two strings of the same length?
*/

#include <stdio.h>
#define SIZE 80

void mystery1(char *s1, const char *s2);

int main(void)
{
  char string1[ SIZE ];
  char string2[ SIZE ];
  puts( "Enter two strings: ");
  scanf("%79s%79s", string1, string2);
  mystery1(string1, string2);
  printf("%s\n", string1);
}

void mystery1( char *s1, const char *s2 )
{
  while( *s1 != '\0' ) {
    ++s1;
    //printf("%s\n", s1);
  }
  for ( ;(*s1 = *s2); ++s1, ++s2 ) {
    ;
  }
}

/*
For this to compile correctly on my machine I had to add parentheses around the
condition in the for loop.

The mystery function, when given two strings of equal length, concatenate the strings
together.  It does this by first interating over the first string until it reaches
the null terminator.  Then from this point the for loop will copy it's value
into the first array until the second array's null terminator is met.

For example:

-- Application output --

Enter two strings:
steven steven
stevensteven

*/

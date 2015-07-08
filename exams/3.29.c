#include <stdio.h>

// Print 10 rows of some character
// If the row is even (found by the modulo 2 operation)
// then print > while column is less than or equal to 10
// else print < while column is less than or equal to 10
// after finishing each column we decrement the row and
// print a new line.


int main(void) 
{
	unsigned int row = 10;
	unsigned int column;

	while (row >= 1) {
		column = 1;
		while (column <= 10) {
			printf("%s", row % 2 ? "<" : ">");
			++column;
		}
		--row;
		puts("");
	}
	return 0;
}
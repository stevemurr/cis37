#include <stdio.h>

// the following program is a loop in a loop in a loop for printing rows and
// columns of star characters

// the first loop controls how many blocks to make

// the second for loop controls the height of each block

// the third for loop controls the width of each block and also
// prints the * character

int main(void)
{
	for (int i = 1; i <= 5; ++i) {
		for (int j = 1; j <= 3; ++j) {
			for ( int k = 1; k <= 4; ++k) {
				printf("%s", "*");
			}
			puts("");
		}
		puts("");
	}	
}
#include <stdio.h>

// describe how you would in general remove a continue statement with a 
// structured equivalent

// use fig 4.12 as an example

// In figure 4.12 the continue block is used to catch 1
// specfic case.  The case of x being equal to 5.
// A cleaner way to write that same logical flow would
// be with an if else statement.
// In this case (as show below) we check if the case does
// not exist.  If it doesn't print out a number.  
// In our else block we catch the case in which x equals 5.
// We then can run any code in that block.  In this case I 
// run a printf.

int main(void)
{
	unsigned int x;

	for ( x = 1; x <= 10; ++x) {
		if ( x != 5){
			printf("%u ", x);
		} else {
			printf("");
		}
	}
	puts("");
	return 0;
}
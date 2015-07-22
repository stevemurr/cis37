// write a program with main
// include static local variable count initialized to 1
// posincrement and print the value of count
// run your program
// what happens?

#include <stdio.h>

int main(void)
{
	static int count = 1;
	count++;
	printf("%d\n", count);
	main();
}

// this creates an infinite loop!  We require a base case to
// avoid the inifinite loop.  The base case would be 
// some check that allows the program to exit.

// In this case, it could be 

/*
if (count == 1000) {
	return 0;
}
*/

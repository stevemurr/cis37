// write a recursive function printarray
// takes in array and size
// returns nothing
// function returns when size == 0

#include <stdio.h>

int main(void)
{
	void printArray(int *array, int size);
	int array[5] = {1,2,3,4,5};
	printArray(array, 5);
}

void printArray(int *array, int size)
{	
	if (size-1 == -1) {
		return;
	} else {
		printf("%d\n", array[size-1]);
		size--;
		printArray(array, size);
	}
}
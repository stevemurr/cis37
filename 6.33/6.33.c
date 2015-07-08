#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define NUMBER_OF_ROLLS 36000

/*
The previous solution for 6.19 was formatted in such a way to emulate a dictionary with key (subscript) and value pairs.
Since this exercise requires us to implement a binary search it would only make sense to just append new 
dice roll values to an array with no respect to the subscript used.  I will then sort it before using a binary search.
*/

void swap( unsigned int *element1Ptr, unsigned int *element2Ptr)
{
	int hold = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = hold;
}

void bubbleSort( unsigned int * a )
{
	void swap(unsigned int *element1Ptr, unsigned int *element2Ptr);
	unsigned int SIZE = NUMBER_OF_ROLLS;
	unsigned int pass;
	size_t j;

	for ( pass = 1; pass < SIZE; ++pass )
	{
		for ( j = 0; j < SIZE - 1; ++j )
		{
			if (a[j] > a[ j + 1 ] )
			{
				swap( &a[ j ], &a[ j+1 ]);
			}
		}
	}
}

int binary_search(unsigned int list[], int starting_subscript, int ending_subscript, unsigned int search_key)
{
	unsigned int middle;
	int error_code = -1;

	while (starting_subscript != ending_subscript)
	{
		middle = ending_subscript - floor(((ending_subscript - starting_subscript) / 2));
		printf("Start: %d\n", starting_subscript);
		printf("End: %d\n", ending_subscript);
		printf("Middle: %d\n", middle);
		if ( list[middle] == search_key){
			printf("The value %d was found at subscript %d\n", search_key, middle);
			return 0;
		} else if ( list[middle] < search_key ) {
			starting_subscript = middle;
		} else {
			ending_subscript = middle;
		}
	}
	printf("It wasn't found %d\n", error_code);
	return 0;
}



int main(void)
{
	time_t t;
	unsigned int dice_1;
	unsigned int dice_2;
	unsigned int sum;
	unsigned int sum_list[NUMBER_OF_ROLLS+1] = {0};
	srand((unsigned) time(&t));
	for (int i = 0; i <= NUMBER_OF_ROLLS; i++)
	{
		dice_1 = (rand() % 6) + 1;
		dice_2 = (rand() % 6) + 1;
		sum = dice_1 + dice_2;
		sum_list[i] = sum;
	}
	bubbleSort(sum_list);
	printf("Entering search\n");
	binary_search(sum_list, 1, 5000, 2);
}


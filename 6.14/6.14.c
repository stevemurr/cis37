#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define SIZE_OF_ARRAY(x) (sizeof(x) / sizeof(x[0]))

void mean( const unsigned int answer[] );
void median( unsigned int answer[], int size_of_array );
void mode( unsigned int freq[], unsigned const int answer[] );
void bubbleSort( unsigned int answer[] );
void printArray( unsigned const int a[] );

int main( void )
{
	time_t t;
	srand((unsigned) time(&t));
	unsigned int frequency[ 10 ] = { 0 }; // init array frequency of size 10 with all values 0.
	unsigned int response[ SIZE ];
	for ( int i = 0; i < SIZE; i++) // generate an array of random numbers
	{
		response[i] = (rand() % 9) + 1;
	}
	mean( response );
	median( response, SIZE_OF_ARRAY(response)); // I could just compare based on SIZE but i wanted to learn how get the number of elements from an array.
	mode( frequency, response );
}

void mean( const unsigned int answer[] )
{
	size_t j; // counter for totaling array elements
	double total_size;
	unsigned int total = 0;

	printf( "%s\n%s\n%s\n", "********", "Mean", "********");

	for (j = 0; j < SIZE; ++j) {
		total += answer[ j ];
	}
	total_size = total / SIZE;
	printf("Mean: %u / %u == %.4f\n\n", total, SIZE, total_size);
} // end mean function

void median( unsigned int answer[], int size_of_array )
{
	int median;
	if (size_of_array % 2 == 0)
	{
		median = (answer[size_of_array/2] + answer[(size_of_array/2)-1]) / 2;
	} else {
		median = answer[size_of_array / 2];
	}
	printf("\n%s\n%s\n%s\n%s",
			"********", "Median", "********",
			"The unsorted array of responses is");

	printArray( answer );
	bubbleSort( answer );

	printf( "%s", "\n\nThe sorted array is");
	printArray( answer );

	printf("\n\nFor this run the median is %u\n\n",
		   median);

	// if length of answer %2 == 0 : then middle value + middle value -1 / 2 = median
}
void mode(unsigned int freq[], const unsigned int answer[])
{
	size_t rating;
	size_t j;
	unsigned int possible_ties = 0;
	unsigned int h;
	unsigned int largest[10] = {0};
	unsigned int modeValue[10] = {0};

	printf( "\n%s\n%s\n%s\n",
		"********", "Mode", "********");

	for (j = 0; j < SIZE; ++j)
	{
		++freq[ answer[ j ] ];
	}
	printf( "%s\t%s\t%s\n",
		"Response", "Frequency", "Histrogram");
	for (rating = 1; rating <= 9; ++rating)
	{
		printf("%u\t\t%u\t\t", (int)rating, freq[ rating ] );
		
	if ( freq[ rating ] > largest[possible_ties]) {
		largest[possible_ties] = freq[ rating ]; // largest is the number of times
		modeValue[possible_ties] = rating; // modevalue is the number that appears most
	} else if ( freq[ rating ] == largest[possible_ties]){
		possible_ties++;
		largest[possible_ties] = freq[ rating ];
		modeValue[possible_ties] = rating;
	}

	for ( h = 1; h <= freq[ rating ]; ++h )
	{
		printf("%s", "*");
	}
	puts( "" );
}
	printf("\nThe mode is the most frequent value. \n"
		   "For this run the modes are: \n");
	for (int q = 0; q <= possible_ties; q++){
		printf("%d and %d\n", modeValue[q], largest[q]);
	}
}

void bubbleSort( unsigned int a[] )
{
	unsigned int pass;
	size_t j;
	unsigned int hold;

	for ( pass = 1; pass < SIZE; ++pass )
	{
		for ( j = 0; j < SIZE - 1; ++j )
		{
			if (a[j] > a[ j + 1 ] )
			{
				hold = a[j];
				a[j] = a[j+1];
				a[j+1] = hold;
			}
		}
	}
}
void printArray( const unsigned int a[] )
{
	size_t j;
	for (j = 0; j < SIZE; ++j) {
		if (j % 20 == 0){
			puts("");
		}
		printf("%2u", a[j]);
	}
}


// Modify the program of Fig. 6.16 so function mode is capable of handling a tie for the mode value. 
// Also modify function median so the two middle elements are averaged in an array with an even number of elements.





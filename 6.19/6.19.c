#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUMBER_OF_ROLLS 36000

int main(void)
{
	time_t t;
	unsigned int dice_1;
	unsigned int dice_2;
	unsigned int sum;
	unsigned int sum_list[13] = {0};
	srand((unsigned) time(&t));
	for (int i = 0; i <= NUMBER_OF_ROLLS; i++)
	{
		dice_1 = (rand() % 6) + 1;
		dice_2 = (rand() % 6) + 1;
		sum = dice_1 + dice_2;
		sum_list[sum] = sum_list[sum] + 1;
	}
	for (int j = 2; j <= 12; j++)
	{
		printf("%d: %d\n", j, sum_list[j]);
	}
}





// simulate rolling two dice
// rand 1-6 for two dice
// roll the dice 36,000 times
// calculate the sum and enter it into an array
// single subscripted array to tally numbers of times each possible sum appears.
// iterator 2 - 12 : if array[iterator] = iterator : then print out "for a sum of 2 there were X in array"
// print results in a table
// determine if the totals are reasonable - 7 is most likely to appear highest.
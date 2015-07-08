#include <stdio.h>

#define FACTORIAL_TIL 5

int calculate_factorial(int num)
{
	int factorial = num;
	for (int i = num-1; i >= 1; i--)
	{
		factorial = factorial * i;
	}
	return factorial;
}

int main(void)
{
	printf("Number");
	printf("\tFactorial\n");
	for (int i = 1; i <= FACTORIAL_TIL; i++)
	{
		printf("%d", i);
		printf("\t%d\n", calculate_factorial(i));
	}
}
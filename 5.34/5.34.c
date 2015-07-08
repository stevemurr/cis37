#include <stdio.h>


int power(int base, int exponent)
{
	int power = base;
	for (int i = 1; i < exponent; i++)
	{
		power = power * base;
	}
	return power;
}

int main(void)
{
	int base, exponent;
	puts("What is the base? ");
	scanf("%d", &base);
	puts("What is the exponent? ");
	scanf("%d", &exponent);
	puts("Your answer is: ");
	printf("%d\n", power(base, exponent));
	return 0;
}

// do power(base, exponent) function
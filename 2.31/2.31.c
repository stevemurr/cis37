#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SQUARED(x) (x*x)
#define CUBED(x) (x*x*x)
#define HOW_MANY 10

int main(void)
{
	printf("Number");
	printf("\tSquared");
	printf("\tCubed\n");
	for (int i = 0; i <= HOW_MANY; i++)
	{
		printf("%d", i);
		printf("\t%d", SQUARED(i));
		printf("\t%d\n", CUBED(i));
	}
}
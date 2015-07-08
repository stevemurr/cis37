#include <stdio.h>

#define COUNT_UNTIL 1000000001

int main(void)
{
	int iter = 1;
	while (iter < COUNT_UNTIL)
	{
		if (iter % 100000000 == 0)
		{
			printf("%d\n", iter);
		}
		iter = iter + 1;
	}
}
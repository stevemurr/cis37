
#include <stdio.h>

#define SIZE 8

int main(void)
{
	int i = 1;
	while (i <= SIZE)
	{
		if (i % 2 != 0)
		{
			for (int j = 0; j < 8; j++) {
				printf( "%s", "* " );
				printf( "%s", " " );
			}
			puts( "" ); 
		} else {
			for (int j = 0; j < 8; j++)
			{
				printf( "%s", " " );
				printf( "%s", "* " );
			}
			puts( "" ); 
		}
		i = i + 1;
	}
}
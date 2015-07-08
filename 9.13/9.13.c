// read the input of 437
// print using each scanf input conversion specifier

#include <stdio.h>

int main(void)
{
	int num;
	printf("Please enter a number: (i.e 427) ");
	scanf("%i", &num);
	printf("%d\n%o\n%u\n%x\n%i\n", num, num, num, num, num);
	return 0;
}
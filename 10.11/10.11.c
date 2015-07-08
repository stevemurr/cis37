#include <stdio.h>

// shifiting an unsigned int left by 1 is the same as 
// shift left 1 = multiply by 2

// write power2 func ( int a, int b)
// number *

int main(void)
{
	void power2( unsigned int value );
	int c;
	printf("Enter a value: ");
	scanf("%d", &c);
	power2(c);
}

void power2( unsigned int value)
{
	unsigned int c;
	unsigned int multiplied_by_two = value * 2;
	unsigned int displayMask = 1 << 31;
	value = value << 1;
	printf("%10u = ", value);

	// loop through bits
	for ( c = 1; c <= 32; ++c) {
		putchar( value & displayMask ? '1' : '0');
		value <<= 1;

		if ( c % 8 == 0) {
			putchar( ' ' );
		}
	}
	putchar( '\n');
	printf("The multiplied value was %d\n", multiplied_by_two);
}
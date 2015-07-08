// left shit 4 chars into an unsigned int
// packCharacters( char 1, 2, 3, 4)
// unsigned int variable = first char
// shift variable left by 8 and combine 
// variable with second character using
// bitwise inclusive OR
// repeat for third and fourth chars.
// program should output the characters
// in bit format before and after
// they're packed into the unsigned int

#include <stdio.h>

#define num_of_chars 4

void displayBits( unsigned int value );

union character {
	char c;
} character;

int main(void)
{	
	union character input; // used a union to reinforce the union concept to myself
	union character *input_pointer = &input; // the union is also slightly more optimal since we're just writing over the same area of memory rather than using a new  byte for each char.
	unsigned int q;
	unsigned int *q_pointer = &q;	
	void packCharacters(unsigned int *variable, union character *input);
	packCharacters(q_pointer, input_pointer);
	return 0;
}


void packCharacters(unsigned int *variable, union character *input)
{
	scanf(" %c", &input->c);
	*variable = input->c;
	displayBits(*variable);
	for (int i = 1; i < num_of_chars; ++i)
	{
		scanf(" %c", &input->c);
		*variable = *variable << 8;
		*variable = *variable | input->c;
		displayBits(*variable);
	}
}

void displayBits( unsigned int value)
{
	unsigned int c;
	unsigned int displayMask = 1 << 31;
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
}
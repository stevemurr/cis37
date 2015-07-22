#include <stdio.h>

// the greatest common divisor of integer x and y is
// the largest integer that divides both x and y

// recursive function gcd that returns the greatest common divisor
// of x and y
// the gcd of x and y is found by:
// if y is equal to 0 
// then gcd(x, y) is x
// otherwise gcd(x, y) is gcd(x, x%y) where modulo is remainder op

int main(void)
{
	int gcd(int x, int y);
	printf("%d\n", gcd(8, 16));
}

int gcd(int x, int y)
{
	int gcd_answer;
	if (y == 0) {
		return x;
	} else {
		gcd_answer = gcd(y, x%y);
	}
	return gcd_answer;
}
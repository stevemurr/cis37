// print the number 100.453627
// round it to:
// digit
// tenth
// hundreth
// thousandth
// ten thousandth

#include <stdio.h>
#include <math.h>

int main(void)
{
	float number = 100.453627;
	printf("The digit is: %f\n", number);
	printf("The tenth is: %.3g\n", number);
	printf("The hundreth is: %.4g\n", number);
	printf("The thousandth is: %.5g\n", number);
	printf("The ten thousandth is: %.6g\n", number);
	return 0;
}
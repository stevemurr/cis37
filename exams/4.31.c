// print a diamond
// printf either * or blank
// maximize the use of for loops
// max width = 9
// max height = 9


// width - number of stars = blank space

#include <stdio.h>

#define height 9

int main(void)
{
	int backwards = 0;
	int width = 9;
	int number_of_stars = 1;
	int number_of_spaces = (width - number_of_stars)/2;
	for (int i = 0; i < height; i++) {
		for (int k = 0; k < number_of_spaces; k++) {
			printf(" ");
		}
		for (int l = 0; l < number_of_stars; l++) {
			printf("*");
		}
		for (int k = 0; k < number_of_spaces; k++) {
			printf(" ");
		}
		puts("");
		if (number_of_stars == 9) {
			backwards = 1;
		}
		if (backwards == 0) {
			number_of_stars = number_of_stars + 2;
			number_of_spaces = (width - number_of_stars) / 2;
		} else if (backwards == 1) {
			number_of_stars = number_of_stars - 2;
			number_of_spaces = (width - number_of_stars) / 2;
		}
	}
	return 0;
}
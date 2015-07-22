// print a string back to front
// returns nothing

#include <stdio.h>
#define length_of_string(x)(sizeof(x)/sizeof(x[0]))

typedef struct {
	int counter;
} Counter;

int main(void)
{
	Counter c;
	Counter *cPtr = &c;
	void printStringBackwards(char *array, Counter *c);
	char my_string[10] = "Billy Bob";
	c.counter = length_of_string(my_string) - 1;
	printStringBackwards(my_string, cPtr);
	puts("");
	return 0;
}

void printStringBackwards(char *array, Counter *c)
{
	if (c->counter == -1){
		return;
	} else {
		printf("%c ", array[c->counter]);
		c->counter--;
		printStringBackwards(array, c);
	}
}
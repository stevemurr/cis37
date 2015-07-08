#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// input the values into the union
// print them out

union number { // unions share the same memory space - so one at a time.
	char c;
	short s;
	int i;
	long b;
}number;

typedef struct {
		int age;
		char firstName[25];
		int a[10];
	} employee;

int main(void)
{
	union number n;
	char c;
	short s;
	int i;
	long b;
	printf("Enter a char: ");
	scanf("%c", &c);
	n.c = c;
	printf("%c %hhd %d %d\n", n.c, n.c, n.c, n.c);
	printf("Enter a short: ");
	scanf("%hd", &s);
	n.s = s;
	printf("%c %hd %d %d\n", n.s, n.s, n.s, n.s);
	printf("Enter an int: ");
	scanf("%d", &i);
	n.i = i;
	printf("%c %d %d %d\n", n.i, n.i, n.i, n.i);
	printf("Enter a long: ");
	scanf("%ld", &b);
	n.b = b;
	printf("%ld %ld %ld %ld\n", n.b, n.b, n.b, n.b); // some of these wouldn't print with different conversion specifiers.
}

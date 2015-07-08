#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define default_char_array_size 200

int main(void)
{
	int number_of_words = 0;
	char *result, haystack[default_char_array_size];
	printf("Input a string: ");
	fgets(haystack, default_char_array_size, stdin);
	haystack[strlen(haystack) -1] = '\0'; // fgets appends a newline - we need to replace it with null terminator.
	result = strtok(haystack, " ");
	while (result != NULL) {
		number_of_words++;
		result = strtok(result+strlen(result)+1, " ");
	}
	printf("There were %d words.\n", number_of_words);
}
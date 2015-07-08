#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define default_char_array_size 200

int main(void)
{
	char *result, haystack[default_char_array_size], needle[default_char_array_size];
	printf("Input a string: ");
	fgets(haystack, default_char_array_size, stdin);
	haystack[strlen(haystack) -1] = '\0'; // fgets appends a newline - we need to replace it with null terminator.
	printf("Input search string: ");
	fgets(needle, default_char_array_size, stdin);
	needle[strlen(needle)-1] = '\0'; // fgets appends a newline - we need to replace it with null terminator.
	result = strstr(haystack, needle);
	while (result != NULL) {
		printf("%s\n", result);
		result = strstr(result+1, needle);
	}
}
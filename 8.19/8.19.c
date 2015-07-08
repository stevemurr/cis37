#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define text_size 200

int main(void)
{
	int search_library(char array[26][2], char search_character);
	char text[text_size]; 
	char library[26][2];
	printf("Enter the text to search: ");
	fgets(text, text_size, stdin);
	char *result = strchr(text, text[0]);
	printf("Letter\tFrequency\n");
	for (int i = 0; i < strlen(text)-1; i++) {
		while (isspace(text[i])) {
			i++;
		}
		if (search_library(library, text[i]) == 0) {
			//i++;
			break;
		} else {
			result = strchr(text, text[i]);
			library[i][0] = text[i];
			library[i][1] = 0;
			while (result != NULL) {
				library[i][1]++;
				result = strchr(result+1, text[i]);
			}
			//printf("%c\t%d\n", library[i][0], library[i][1]);
		}
	}
	for (int k = 0; k < strlen(text)-1; k++) {
		printf("%c\t%d\n", library[k][0],library[k][1]);
	}
}

int search_library(char array[26][2], char search_character)
{
	for (int j = 0; j < strlen(array[25]); j++) {
			if (strcmp(&array[j][0], "l")) { // we've already done this letter
				printf("Found on\n");
				return 0;
		}
	}
	//printf("EXITING WITH 1");
	return 1;
}
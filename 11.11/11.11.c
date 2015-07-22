
// a) open nameage.dat and write 100 records to it

// b) add 10 records manually

// c) update a record - if no record return "no info"

// d) delete a record

#include <stdio.h>
#define length_of_file 100
#define manual_entry_length 1

int main(void)
{
	// File pointer to the file

	FILE *file_pointer;

	// Struct holding the model for our data.

	struct person {
		char firstName [ 15 ];
		char lastName [ 15 ];
		char age [ 4 ];
	};

	// Creating a person object and adding 100 of them to nameage.dat
	struct person p = {"unanswered", "noinput", "0"};
	
	file_pointer = fopen("nameage.dat", "w");
	for (int i = 0; i < length_of_file; i++) {
		fprintf(file_pointer, "%s %s %s\n", p.firstName, p.lastName, p.age);
	}
	fclose(file_pointer);
	// Manual Entry - Set to 10 once update and delete have been implemented.
	puts("Prepare for manual entry - (firstname lastname age)\n");
	file_pointer = fopen("nameage.dat", "a");
	for (int j = 0; j < manual_entry_length; j++) {
		scanf("%s %s %s", p.firstName, p.lastName, p.age);
		fprintf(file_pointer, "%s %s %s\n", p.firstName, p.lastName, p.age);
	}
	fclose(file_pointer);

	file_pointer = fopen("nameage.dat", "r");
	printf("%s %20s %17s %15s\n", "#:","Firstname:", "Lastname:", "Age:");
	int x = 1;
	while (!feof(file_pointer)) {
		fscanf(file_pointer, "%s %s %s", p.firstName, p.lastName, p.age);
		printf("%d\t%15s\t%15s\t%15s\n", x, p.firstName, p.lastName, p.age);
		x++;

	
	}
	
}
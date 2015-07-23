
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define length_of_file 100
#define manual_entry_length 1

typedef struct {
	int account_number;
	char firstName [ 15 ];
	char lastName [ 15 ];
	char age [ 4 ];
} Person;

typedef struct {
Person *array;
size_t used;
size_t size;
} Array;

void initArray(Array *a, size_t initialSize) {
a->array = (Person *)malloc(initialSize * sizeof(Person));
a->used = 0;
a->size = initialSize;
}

void insertArray(Array *a, Person element) {
if (a->used == a->size) {
	a->size *= 2;
	a->array = (Person *)realloc(a->array, a->size * sizeof(Person));
}
a->array[a->used++] = element;
}

void removeElement(Array *a, int index) {
	//a->array = (Person *)realloc(a->array, a->size * sizeof(Person));
	a->used--;
	for (int i = index; i < a->used; i++) {
		memcpy(&a->array[index], &a->array[index+1], sizeof(Person));
	}
}

void freeArray(Array *a) {
free(a->array);
a->array = NULL;
a->used = a->size = 0;
}
void read_file_into_memory(FILE *FILE, Array *person_array);
void delete_entry(FILE *FILE, Array *person_array);
int main(void)
{
	// File pointer to the file
	void create_manual_entry(FILE *FILE);
	void update_entry(FILE *FILE, Array *person_array);
	void print_contents_of_file(FILE *FILE, Array *person_array);
	FILE *file_pointer;
	Person *person_pointer;
	Array person_array;
	initArray(&person_array, length_of_file);
	// Struct holding the model for our data.

	file_pointer = fopen("nameage.dat", "w");
	for (int i = 0; i < length_of_file; i++) {
		Person p = {i, "unanswered", "noinput", "0"};
		insertArray(&person_array, p);
		fprintf(file_pointer, "%d %s %s %s\n", p.account_number,p.firstName, p.lastName, p.age);
	}
	freeArray(&person_array);
	fclose(file_pointer);
	delete_entry(file_pointer, &person_array);
	//print_contents_of_file(file_pointer, &person_array);
	//create_manual_entry(file_pointer);
	//update_entry(file_pointer, &person_array);
	//print_contents_of_file(file_pointer, &person_array);
}
void write_to_file(FILE *FILE, Array *person_array, char write_flag)
{
		FILE = fopen("nameage.dat", &write_flag);
		read_file_into_memory(FILE, person_array);
		for (int i = 0; i < person_array->used; i++) {
			fprintf(FILE, "%d %s %s %s\n", person_array->array[i].account_number,
		                                 person_array->array[i].firstName,
																	   person_array->array[i].lastName,
																	   person_array->array[i].age);
		}
}
void print_contents_of_file(FILE *FILE, Array *person_array)
{
	//void read_file_into_memory(FILE *FILE, Array *person_array);
	read_file_into_memory(FILE, person_array);
	for (int i = 0; i < person_array->used; i++) {
		printf("%d %s %s %s\n", person_array->array[i].account_number, person_array->array[i].firstName,  person_array->array[i].lastName,  person_array->array[i].age);
	}
	fclose(FILE);
	freeArray(person_array);
}

void read_file_into_memory(FILE *FILE, Array *person_array)
{
	FILE = fopen("nameage.dat", "r+");
	int ac;
	char first_name[50];
	char last_name[50];
	char age[4];
	while (fscanf(FILE, "%d %s %s %s", &ac, first_name, last_name, age) != EOF) {
		Person temp_person;
		temp_person.account_number = ac;
		strcpy(temp_person.firstName, first_name);
		strcpy(temp_person.lastName, last_name);
		strcpy(temp_person.age, age);
		insertArray(person_array, temp_person);
	}
	fclose(FILE);
}
void delete_entry(FILE *FILE, Array *person_array)
{
	int record;
	read_file_into_memory(FILE, person_array);
	printf("%s", "Which record to update? ");
	scanf("%d", &record);
	removeElement(person_array, record);
	write_to_file(FILE, person_array, 'w');
}
// For appending only
void create_manual_entry(FILE *FILE)
{
	char firstName[ 50 ];
	char lastName[ 50 ];
	int age = 0;
	FILE = fopen("nameage.dat", "a");
	for (int i = 0; i < manual_entry_length; i++) {
		scanf("%s %s %d", firstName, lastName, &age);
		fprintf(FILE, "%s %s %d", firstName, lastName, age);
	}
	fclose(FILE);
}

void update_entry(FILE *FILE, Array *person_array)
{
	char firstName[ 50 ];
	char lastName[ 50 ];
	char age[ 4 ];
	int record;
	read_file_into_memory(FILE, person_array);
	printf("%s", "Which record to update? ");
	scanf("%d", &record);
	for (int i = 0; i < person_array->used; i++) {
		if (person_array->array[i].account_number == record) {
			printf("%s\n", "Record found - Insert new information");
			scanf(" %s %s %s", firstName, lastName, age);
			strcpy(person_array->array[i].firstName, firstName);
			strcpy(person_array->array[i].lastName, lastName);
			strcpy(person_array->array[i].age, age);
			fclose(FILE);
			write_to_file(FILE, person_array, 'w');
			return;
		}
	}
	printf("%s\n", "That index doesn't exist.");
}

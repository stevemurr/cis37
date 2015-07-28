// write a program that makes hardware.dat
// create 100 empty records
// make manual input function
// make update function
// make delete function
// make list function
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define manual_entry_length 1
#define INITIAL_LENGTH 100

typedef struct {
	int record_number;
	char tool_name [ 50 ];
	int quantity;
	double cost;
} Tool;

typedef struct {
Tool *array;
size_t used;
size_t size;
} Array;

void read_file_into_memory(FILE *FILE, Array *person_array);
void print_contents_of_file(FILE *FILE, Array *person_array);
void delete_entry(FILE *FILE, Array *person_array);
void create_manual_entry(FILE *FILE);
void update_entry(FILE *FILE, Array *person_array);
void write_to_file(FILE *FILE, Array *person_array, char write_flag);
void bootstrap_our_hardware_store(FILE *FILE, Array *tool_array);

void initArray(Array *a, size_t initialSize) {
a->array = (Tool *)malloc(initialSize * sizeof(Tool));
a->used = 0;
a->size = initialSize;
}

void insertArray(Array *a, Tool element) {
if (a->used == a->size) {
	a->size *= 2;
	a->array = (Tool *)realloc(a->array, a->size * sizeof(Tool));
}
a->array[a->used++] = element;
}

void removeElement(Array *a, int index) {
	a->used--;
	for (int i = index; i < a->used; i++) {
		memcpy(&a->array[index], &a->array[index+1], sizeof(Tool));
	}
}

void freeArray(Array *a) {
free(a->array);
a->array = NULL;
a->used = a->size = 0;
}

int main(void)
{
  char user_input;
  Array tool_array;
  FILE *file_pointer;
  initArray(&tool_array, 100);
  bootstrap_our_hardware_store(file_pointer, &tool_array);
  while (user_input != 'q') {
    printf("%s", "Which option?: ");
    scanf("%s", &user_input);
    if (user_input == '1') {
      print_contents_of_file(file_pointer, &tool_array);
    }
    if (user_input == '2') {
      delete_entry(file_pointer, &tool_array);
    }
  }
}

void bootstrap_our_hardware_store(FILE *FILE, Array *tool_array)
{
  FILE = fopen("hardware.dat", "w");
  for (int i = 0; i < INITIAL_LENGTH; i++) {
    Tool p = {i+1, "ToolName", 0, 0.00};
    insertArray(tool_array, p);
    fprintf(FILE, "%d %s %d %.2lf\n", p.record_number,p.tool_name, p.quantity, p.cost);
  }
  freeArray(tool_array);
  fclose(FILE);
}

void print_contents_of_file(FILE *FILE, Array *person_array)
{
	//void read_file_into_memory(FILE *FILE, Array *person_array);
	read_file_into_memory(FILE, person_array);
	for (int i = 0; i < person_array->used; i++) {
		printf("%d %s %d %lf\n", person_array->array[i].record_number,
                            person_array->array[i].tool_name,
                            person_array->array[i].quantity,
                            person_array->array[i].cost);
	}
	fclose(FILE);
	freeArray(person_array);
}

void read_file_into_memory(FILE *FILE, Array *person_array)
{
	FILE = fopen("hardware.dat", "r+");
	int record_number;
  char tool_name[ 50 ];
	int quantity;
	double cost;
	while (fscanf(FILE, "%d %s %d %lf", &record_number, tool_name, &quantity, &cost) != EOF) {
		Tool temp_person;
		temp_person.record_number = record_number;
	  strcpy(temp_person.tool_name, tool_name);
		temp_person.quantity = quantity;
		temp_person.cost = cost;
		insertArray(person_array, temp_person);
	}
	fclose(FILE);
}
void delete_entry(FILE *FILE, Array *person_array)
{
	int record;
	read_file_into_memory(FILE, person_array);
	printf("%s", "Which record to delete? ");
	scanf("%d", &record);
	removeElement(person_array, record);
	write_to_file(FILE, person_array, 'w');
}
// For appending only
void create_manual_entry(FILE *FILE)
{
	char tool_name[ 50 ];
	int quantity;
	double cost;
	FILE = fopen("hardware.dat", "a");
	for (int i = 0; i < manual_entry_length; i++) {
		scanf("%s %d %lf", tool_name, &quantity, &cost);
		fprintf(FILE, "%s %d %lf", tool_name, quantity, cost);
	}
	fclose(FILE);
}

void update_entry(FILE *FILE, Array *person_array)
{
	int record_number;
	char tool_name[ 50 ];
	int quantity;
	double cost;
  int record;
	read_file_into_memory(FILE, person_array);
	printf("%s", "Which record to update? ");
	scanf("%d", &record);
	for (int i = 0; i < person_array->used; i++) {
		if (person_array->array[i].record_number == record) {
			printf("%s\n", "Record found - Insert new information");
			scanf(" %s %d %lf", tool_name, &quantity, &cost);
			strcpy(person_array->array[i].tool_name, tool_name);
			person_array->array[i].quantity = quantity;
			person_array->array[i].cost = cost;
			fclose(FILE);
			write_to_file(FILE, person_array, 'w');
			return;
		}
	}
	printf("%s\n", "That index doesn't exist.");
}
void write_to_file(FILE *FILE, Array *person_array, char write_flag)
{
		FILE = fopen("hardware.dat", &write_flag);
		read_file_into_memory(FILE, person_array);
		for (int i = 0; i < person_array->used; i++) {
			fprintf(FILE, "%d %s %d %lf\n", person_array->array[i].record_number,
		                                 person_array->array[i].tool_name,
																	   person_array->array[i].quantity,
																	   person_array->array[i].cost);
		}
}

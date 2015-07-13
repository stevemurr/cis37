// 2 dollar fee 3 hours or less
// additional .50 cents per hour after 3 hours
// max charge - 24 hours - 10 dollars
// display car # - hours parked - charges accrued
// use a function called calculateCharges
// output to tabluar format

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define size_of_array(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int id;
	char model[50];
	char brand[50];
	double hours_parked;

} Car;

typedef struct {
	Car *array;
	size_t used;
	size_t size;
} Array;

void initArray(Array *a, size_t initialSize) {
	a->array = (Car *)malloc(initialSize * sizeof(Car));
	a->used = 0;
	a->size = initialSize;
}

void insertArray(Array *a, Car element) {
	if (a->used == a->size) {
		a->size *= 2;
		a->array = (Car *)realloc(a->array, a->size * sizeof(Car));
	}
	a->array[a->used++] = element;
}

void freeArray(Array *a) {
	free(a->array);
	a->array = NULL;
	a->used = a->size = 0;
}

int main(void)
{
	// declarations
	void initArray(Array *a, size_t initialSize);
	double calculateCharges(double hours);
	void print_car_info(Array* car_array, size_t elements);
	Car make_a_car(int id);
	//

	Array car_array;
	initArray(&car_array, 1);
	insertArray(&car_array, make_a_car(car_array.used));
	insertArray(&car_array, make_a_car(car_array.used));
	//printf("%s\n", car_array.array[0].brand);
	print_car_info(&car_array, car_array.used);

	return 0;
}

void print_car_info(Array *car_array, size_t elements) 
{
	for (int i = 0; i < elements; i++)
	{
		printf("%d %s %s %.2f\n", car_array->array[i].id, car_array->array[i].model, car_array->array[i].brand, car_array->array[i].hours_parked);
	}
}

Car make_a_car(int id) 
{	
	char model[50];
	char brand[50];
	double hours_parked;
	printf("We are going to make a car - Please enter the following \n");
	printf("Model: ");
	scanf(" %s", model);
	printf("Brand: ");
	scanf(" %s", brand);
	printf("Hours Parked: ");
	scanf(" %lf", &hours_parked);
	Car car;
	car.id = id+1;
	memcpy(car.model, model, sizeof(model));
	memcpy(car.brand, brand, sizeof(brand));
	car.hours_parked = hours_parked;
	return car;
}

double calculateCharges(double hours) 
{
	double price;
	while (hours != 0) 
	{
		if (hours >= 3) {
			price = price + 2;
			hours = hours - 3;
		}
		if (hours < 1) {
			return price;
		} else if (hours < 3) {
			price = price + 0.50;
			hours = hours - 1;
		}
	}
	printf("%f\n", hours);
	return price;
}
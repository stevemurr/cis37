#include <stdio.h>

#define FARENHEIT_CHART_MAX 100
#define CELSIUS_MIN 32
#define CELSIUS_MAX 212

float celsius_to_farenheit(float celsius)
{
	float farenheit;
	farenheit = celsius * 9/5 + 32;
	return farenheit;
}

float farenheit_to_celsius(float farenheit)
{
	float celsius;
	celsius = (farenheit-32) * 5/9;
	return celsius;
}

int main(void)
{
	printf("Farenheit");
	printf("\tCelsius\n");
	for (int i = 0; i <= FARENHEIT_CHART_MAX; i++)
	{
		printf("%d", i);
		printf("\t\t%.2f\n", farenheit_to_celsius(i));
	}
	printf("Celsius");
	printf("\t\tFarenheit\n");
	for (int i = CELSIUS_MIN; i <= CELSIUS_MAX; i++)
	{
		printf("%d", i);
		printf("\t\t%.2f\n", celsius_to_farenheit(i));	
	}
}


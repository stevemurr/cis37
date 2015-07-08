#include <stdio.h>
#include <math.h>

void area_of_circle(double radius);
void circumfrence_of_circle(double radius);
void volume_of_sphere(double radius);

void (*ptr[3]) (double radius);

void circumfrence_of_circle(double radius)
{	
	double result = 2 * 3.14 * radius;
	printf("Operation: Circumfrence of Circle\n" 
		    "Radius: %.2f\n" 
		    "Circumfrence: %.2f\n", radius, result);
}

void area_of_circle(double radius)
{
	double result = 3.14 * radius * radius;
	printf("Operation: Area of a Circle\n" 
		    "Radius: %.2f\n" 
		    "Area: %.2f\n", radius, result);
}
void volume_of_sphere(double radius)
{
	double result = (4/3)*3.14*radius*radius*radius;
	printf("Operation: Volume of a Sphere\n" 
		    "Radius: %.2f\n" 
		    "Volume: %.2f\n", radius, result);
}

int main(void)
{
	ptr[0] = circumfrence_of_circle;
	ptr[1] = area_of_circle;
	ptr[2] = volume_of_sphere;
	double menu_input, user_input;
	do {
		printf("Select an action: \n");
		printf("1: Circumfrence of a Cirlce\n"
			   "2: Area of a Circle\n"
			   "3: Volume of a Sphere\n"
			   "Input: ");
		scanf("%lf", &menu_input);
		if (menu_input == -1) {
			printf("Exiting\n");
			break;
		}
		printf("Radius: ");
		scanf("%lf", &user_input);
		if (menu_input == 1) {
			(ptr[0])(user_input);
		} else if (menu_input == 2) {
			(ptr[1])(user_input);
		} else if (menu_input == 3) {
			(ptr[2])(user_input);
		} 
	} while (menu_input != -1);
}
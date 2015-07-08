#include <stdio.h>

#define ENTER_SALES "Enter sales in dollars (-1 to end): "
#define SALARY_IS "Salary is:"

int main(void)
{
	float salary, sales;
	do {
		printf("%s\n", ENTER_SALES);
		scanf("%f", &sales);
		if (sales == -1){
			printf("Exiting \n");
			break;
		}
		salary = 200 + (sales*.09);
		printf("%s %.2f\n", SALARY_IS, salary);
	} while (sales != -1);
	return 0;
}
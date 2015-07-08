#include <stdio.h>

#define MANAGER 1
#define HOURLY 2
#define COMMISION 3
#define PIECEWORKERS 4
#define OVERTIME_MODIFIER 1.5
#define COMMISSION_SALES_MODIFIER .057

int main(void)
{
	int code, hours, overtime_hours, pieces_created;
	float hourly_rate, gross_sales, price_per_piece, salary;
	do{
		puts("Enter the type of salary to process: ");
		scanf("%d", &code);
		switch(code){
			case 1: // Manager
				printf("Enter the managers weekly salary: ");
				scanf("%f", &salary);
				printf("%.2f\n", salary);
				break;
			case 2: // hourly
				printf("Hourly worker \n");
				printf("How man hours did you work? ");
				scanf("%d", &hours);
				printf("What is your hourly wage? ");
				scanf("%f", &hourly_rate);
				if (hours <= 40)
				{
					salary = hours * hourly_rate;
					printf("%.2f\n", salary);
					break;
				} else if (hours > 40) {
					overtime_hours = hours - 40;
					salary = (40 * hourly_rate) + (overtime_hours * hourly_rate*OVERTIME_MODIFIER);
					printf("%.2f\n", salary);
					break;
				}
			case 3: // commission
				puts("Gross sales? ");
				scanf("%f", &gross_sales);
				salary = 250 + gross_sales*.057;
				printf("%.2f\n", salary);
				break;
			case 4: // pieceworkers
				puts("How many pieces did you create? ");
				scanf("%d", &pieces_created);
				puts("What's the price per piece? ");
				scanf("%f", &price_per_piece);
				salary = pieces_created * price_per_piece;
				printf("%.2f\n", salary);
				break;
		}
	} while (code != -1);

	return 0;
}
#include <stdio.h>

#define GET_WEIGHT_IN_POUNDS "What is your weight in pounds? "
#define GET_HEIGHT_IN_INCHES "What is your height in inches? "
#define YOUR_BMI_IS "Your BMI is"
#define UNDERWEIGHT "you are considered underweight according to your BMI."
#define NORMAL_WEIGHT "you have an acceptable height to weight ratio."
#define OVERWEIGHT "you are considered overweight."
#define OBESE "you are obese."

int bmi_calculator(int height, int weight)
{
	int bmi;
	bmi = (weight*703) / (height*height);
	printf("%s %d and ",YOUR_BMI_IS, bmi);
	if (bmi < 18.5)
	{
		printf("%s\n", UNDERWEIGHT);
	} else if (bmi >= 18.5 & bmi <= 24.9) { 
		printf("%s\n", NORMAL_WEIGHT);
	} else if(bmi >= 25 & bmi <= 29.9) {
		printf("%s\n", OVERWEIGHT);
	} else {
		printf("%s\n", OBESE);
	}
	return 0;
}

int main(void)
{
	int height, weight;
	printf("%s\n", GET_WEIGHT_IN_POUNDS);
	scanf("%d", &weight);
	printf("%s\n", GET_HEIGHT_IN_INCHES);
	scanf("%d", &height);
	bmi_calculator(height, weight);
	return 0;
}
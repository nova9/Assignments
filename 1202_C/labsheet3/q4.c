#include <stdio.h>

int main() {
	printf("What is your height in METERS: ");
	float height;
	scanf("%f", &height);

	printf("What is your weight in KILOGRAMS: ");
	float weight;
	scanf("%f", &weight);

	float bmi = weight / (height * height);

	if(bmi > 30)
		printf("Obese");
	else if(bmi > 25)
		printf("Overweight");
	else if(bmi > 18.5)
		printf("Normal Weight");
	else
		printf("Underweight");

    printf("\n");
}

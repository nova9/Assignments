#include <stdio.h>

int main() {
	printf("Unit price: ");
	float price;
	scanf("%f", &price);

	printf("Quantity: ");
	float quantity;
	scanf("%f", &quantity);

	float discount_percentage;
	if(quantity > 160)
		discount_percentage = 20;
	else if(quantity > 120)
		discount_percentage = 15;
	else
		discount_percentage = 0;

	printf("Revenue: %f\n", price * quantity * (100 - discount_percentage) / 100);
}

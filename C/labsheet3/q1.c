#include <stdio.h>

int main() {
	printf("Enter an operator (+, -, *, /): ");
	char operator;	
	scanf("%c", &operator);

	float operand[2];

	printf("Enter two operands: ");
	scanf("%f %f", &operand[0], &operand[1]);

	switch(operator) {
		case '+':
			printf("%f %c %f = %f", operand[0], operator, operand[1], operand[0] + operand[1]);
			break;
		case '-':
			printf("%f %c %f = %f", operand[0], operator, operand[1], operand[0] - operand[1]);
			break;
		case '*':
			printf("%f %c %f = %f", operand[0], operator, operand[1], operand[0] * operand[1]);
			break;
		case '/':
			printf("%f %c %f = %f", operand[0], operator, operand[1], operand[0] / operand[1]);
			break;
		default:
			printf("Operator incorrect");
	}

	printf("\n");
}

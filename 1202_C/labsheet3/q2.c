#include <stdio.h>

int main() {
	printf("Enter a letter: ");
	char letter;
	scanf("%c", &letter);

	if(97 <= letter && letter <= 122)
		printf("You have entered a LOWERCASE letter\n");
	else if(65 <= letter && letter <= 90)
		printf("You have entered an UPPERCASE letter\n");
	else
		printf("Not a alphabetic character\n");
}

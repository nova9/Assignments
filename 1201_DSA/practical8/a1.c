#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *isCircularTwin(char *string) {
	int string_length = strlen(string);

	char left_string[150];
	char right_string[150];

	for(int i = 0; i < string_length / 2; i++) {
		left_string[i] = string[i];
	}
	left_string[string_length / 2] = '\0';

	for(int i = 0; i < string_length / 2; i++) {
		right_string[i] = string[string_length / 2 + i];
	}
	right_string[string_length / 2] = '\0';

	bool isCircularTwin = true;
	for(int i = 0; i < string_length / 2; i++) {
		if (left_string[i] != right_string[i])
			isCircularTwin = false;
	}

	return isCircularTwin ? "Circular Twin" : "Not Circulat Twin";
}

int main() {
	printf("Enter a word, \n\t* No longer than 299 letters\n\t* No spaces \n: ");
	char string[300];
	scanf("%s", string);

	printf("%s\n", isCircularTwin(string));

}

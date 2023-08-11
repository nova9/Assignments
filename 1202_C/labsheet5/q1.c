#include <stdio.h>

int main() {
	printf("\t\t************* MULTIPLICATION TABLE *************\n\n");
	
	printf("   \t");
	for (int i = 1; i <= 10; i++) {
		printf("%d\t", i);
	}
	printf("\n");
	
	printf("   \t");
	for (int i = 1; i <= 10; i++) {
		printf("~\t");
	}
	printf("\n\n");


	for (int i = 1; i <= 10; i++) {
		printf("%d >\t", i);
		for (int j = 1; j <= 10; j++) {
			printf("%d\t", i * j);
		}
		printf("\n");
		printf("\t___________________________________________________________________________\n\n");
	}
}

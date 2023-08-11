#include <stdio.h>

int square_sum(int a, int b) {
	int answer = 0;
	for(int i = a; i <= b; i++) {
		answer += i * i;
	}
	return answer;
}

int main() {
	int a,b;
	printf("Enter a: ");
	scanf("%d", &a);
	printf("Enter b: ");
	scanf("%d", &b);
	printf("%d\n", square_sum(a, b));
}

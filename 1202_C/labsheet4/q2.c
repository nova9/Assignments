#include <stdio.h>

int increment() {
	static int count = 0;
	if (count % 9 == 0 && count != 0) {
		int temp_count = count;
		count = 0;
		return temp_count;
	}
	return count++;
}

int main() {
	printf("%d\n", increment());
	printf("%d\n", increment());

	printf("%d\n", increment());
	printf("%d\n", increment());
	printf("%d\n", increment());
	printf("%d\n", increment());
	printf("%d\n", increment());
	printf("%d\n", increment());
	printf("%d\n", increment());
	printf("%d\n", increment());
	printf("%d\n", increment());
	printf("%d\n", increment());
	printf("%d\n", increment());
	printf("%d\n", increment());
}

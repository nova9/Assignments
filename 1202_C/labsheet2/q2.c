#include <stdio.h>

int main() {
    int a = 1;

    printf("%d\n", a ); // 1 - Variable a is initialized to be 1
    printf("%d\n", a++ ); // 1 - Variable a is returned first then incremented by 1
    printf("%d\n", ++a ); // 3 - Variable a is incremented by 1 and then returned
    printf("%d\n", a-- ); // 3 - Variable a  is returned first then decremented by 1
    printf("%d\n", --a ); // 1 - Variable a is decremented by 1 and then returned
}
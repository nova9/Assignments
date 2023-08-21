#include <stdio.h>

int game(){
    int num;

    printf("Enter a number between 1 to 3: ");
    scanf("%d", &num);

    switch(num){
        case(1): printf("rock"); break;
        case(2): printf("paper"); break;
        case(3): printf ("scissors"); break;
        default: printf("Enter a number between 1 to 3");

    }
    return num;
}

int main (){

    int num;

    int game();

    if(num == 1){
        printf("rock breaks scissors");
    }
    else if (num == 2){
        printf("scissors cut paper");
    }

    else if (num == 3){
        printf("paper covers rock");
    }

    else{
        printf("Enter a number between 1 to 3");

    }

    return 0;
}


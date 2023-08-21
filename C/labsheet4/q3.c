#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

enum Choice {
    ROCK = 1,
    PAPER = 2,
    SCISSOR = 3
};

enum Choice get_random_choice() {
    return (rand() % 3) + 1;
}

void clear_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int main() {
    srand(time(NULL));

    while(1) {
        char input;

        printf("What is your choice? ( r = Rock, p = Paper, s = scissor ): ");
        scanf("%c", &input);
        clear_stdin();

        enum Choice user_choice;

        switch (input) {
            case 'r': user_choice = ROCK; break;
            case 'p': user_choice = PAPER; break;
            case 's': user_choice = SCISSOR; break;
            default:
                printf("Invalid choice\n");
                exit(1);
        }

        enum Choice computer_choice = get_random_choice();

        if (
                (user_choice == ROCK && computer_choice == PAPER) ||
                (user_choice == PAPER && computer_choice == SCISSOR) ||
                (user_choice == SCISSOR && computer_choice == ROCK)
                ) {
            printf(RED "Your loose\n" RESET);
        } else if(user_choice == computer_choice) {
            printf(BLU "Tie\n" RESET);
        } else {
            printf(GRN "You win\n" RESET);
        }
    }
}

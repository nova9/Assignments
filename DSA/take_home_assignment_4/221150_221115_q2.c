#include <stdio.h>
#include <stdbool.h>

int i; // Declaring variables
char l;
char Stack[5]; // Stack initialization
int Top = -1;

void push();

void pop();

bool isFull();

bool isEmpty();

int main() {
    char input[5] = {'a', 'b', 'c', 'd', 'e'};
    printf("\nString pushed to stack: ");
    for (i = 0; i < 5; i++) { // Pushing the elements into stack
        l = input[i];
        push();
        printf("%c", l);
    }
    printf("\n\n");
}


bool isFull() { // Program to check if stack is full
    if (Top >= 5 - 1) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty() { // Program to check if stack is full
    if (Top == -1) {
        return true;
    } else {
        return false;
    }
}

void push() { // Push function
    if (isFull()) {
        printf("Stack is already full\n");
    } else {
        Stack[++Top] = l;
    }
}

void pop() { // Pop function
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("%c", Stack[Top]);
        Top = Top - 1;
    }
}

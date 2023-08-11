#include <stdio.h>
#include <stdbool.h>

int i, j = 10; // Declaring variables
char Stack[5]; // Stack initialization
int Top = -1;

void push();

void pop();

bool isFull();

bool isEmpty();

int main() {
    printf("\n");
    for (i = 0; i < 5; i++) {
        push();
        j = j + 10;
    }
    printf("\n");
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
        Stack[++Top] = i;
        printf("%d has been pushed into stack\n", j);
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

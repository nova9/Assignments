#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Stack ########################################

struct Stack {
    int max_size;
    int top;
    char *data[];
};
typedef struct Stack Stack;


bool is_full(Stack *stack) {
    return stack->top == stack->max_size - 1;
}
bool is_empty(Stack *stack) {
    return stack->top == -1;
}
char *peek(Stack *stack) {
    return stack->data[stack->top];
}
void push(Stack *stack, char *value) {
    if(is_full(stack)) {
        printf("Stack Overflow\n");
        exit(1);
    }

    stack->data[++stack->top] = value;
}
char *pop(Stack *stack) {
    if(is_empty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

Stack *init_stack(int max_size) {
    Stack *stack = malloc(sizeof(int) * 2 + sizeof(char *) * max_size);
    stack->max_size = max_size;
    stack->top = -1;
    return stack;
}

void display_stack(Stack *stack) {
    for(int i = stack->top; i >= 0 ; i--) {
        printf("|%s|\n", stack->data[i]);
    }
    printf("\n");
}
// ############################################

// Dict #######################################

typedef struct DictItem {
    char *key;
    char *value;
} DictItem;

typedef struct Dict {
    int length;
    int max_length;
    DictItem *items[];
} Dict;

Dict *init_dict(int max_length) {
    Dict *dict = malloc(sizeof(DictItem *) * max_length + sizeof(int) * 2);
    dict->length = 0;
    dict->max_length = max_length;
    return dict;
}

void dict_push(Dict *dict, char *key, char *value) {
    DictItem *dict_item = malloc( sizeof(char *) * 2);
    dict_item->key = key;
    dict_item->value = value;
    dict->items[dict->length++] = dict_item;
}

char *dict_value_by_key(Dict *dict, char *key) {
    for(int i = 0; i < dict->length; i++) {
        if (dict->items[i]->key == key) {
            return dict->items[i]->value;
        }
    }
    return "Not Found";
}

// ############################################

char *get_string(){
    int size = 16;

    char *str = malloc(sizeof(char) * size);;
    int len = 0;

    int ch;
    while(EOF != (ch=getchar()) && ch != '\n'){
        str[len++] = ch;
        if(len == size){
            str = realloc(str, sizeof(char) * (size += size));
        }
    }
    str[len++] = '\0';

    return realloc(str, sizeof(char) * len);
}

int main() {
    Dict *dict = init_dict(5);

    dict_push(dict, "Sanduni", "68");
    dict_push(dict, "Kasun", "88");
    dict_push(dict, "Vihanga", "90");
    dict_push(dict, "Khushi", "50");
    dict_push(dict, "Ravindi", "95");

    Stack *st = init_stack(5);

    for (int i = 0; i < dict->length; ++i) {
        char *junk;
        int value_int = strtol(dict->items[i]->value, &junk, 10);
        if (value_int > 70) {
            push(st, dict->items[i]->key);
        }
    }

    printf("Content of the stack: ");
    while (!is_empty(st)) {
        printf("%s ", pop(st));
    }
    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

ListNode *__traverse(ListNode *node, int i, int index) {
    if (index == i) {
        return node;
    }
    return __traverse(node->next, i + 1, index);
}
ListNode *traverse(List *list, int index) {
    return __traverse(list->head, 0, index);
}

int __get_length(ListNode *node, int i) {
    if (node->next == NULL) {
        return i;
    }
    return __get_length(node->next, i + 1);
}
int get_length(List *list) {
    return __get_length(list->head, 1);
}

void insert(List *list, int value, int index) {
    if (index == 0) {
        ListNode *node_to_insert = malloc(sizeof(ListNode));
        node_to_insert->value = value;
        node_to_insert->prev = NULL;

        ListNode *next_node = list->head;
        next_node->prev = node_to_insert;
        node_to_insert->next = next_node;

        list->head = node_to_insert;
    } else if (index == get_length(list)) {
        ListNode *node_to_insert = malloc(sizeof(ListNode));
        node_to_insert->value = value;
        node_to_insert->next = NULL;

        ListNode *last_node = traverse(list, get_length(list) - 1);

        node_to_insert->prev = last_node;
        last_node->next = node_to_insert;
    } else {
        ListNode *node_to_insert = malloc(sizeof(ListNode));
        node_to_insert->value = value;

        ListNode *prev_node = traverse(list, index - 1);
        ListNode *next_node = traverse(list, index);

        prev_node->next = node_to_insert;

        node_to_insert->prev = prev_node;

        node_to_insert->next = next_node;

        next_node->prev = node_to_insert;
    }
}

void delete(List *list, int index) {
    if (index == 0) {
        ListNode *node_to_delete = list->head;
        ListNode *first_node = traverse(list, 1);

        first_node->prev = NULL;
        list->head = first_node;

        free(node_to_delete);
    } else if (index == get_length(list) - 1) {
        ListNode *node_to_delete = traverse(list, get_length(list) - 1);
        ListNode *last_node = traverse(list, get_length(list) - 2);

        last_node->next = NULL;

        free(node_to_delete);
    } else {
        ListNode *node_to_delete = traverse(list, index);
        ListNode *prev_node = traverse(list, index - 1);
        ListNode *next_node = traverse(list, index + 1);

        prev_node->next = next_node;
        next_node->prev = prev_node;

        free(node_to_delete);
    }
}

List *init_list(int values[], int length) {
    ListNode *first_node = malloc(sizeof(ListNode));
    first_node->prev = NULL;
    first_node->next = NULL;
    first_node->value = values[0];

    List *list = malloc(sizeof(List));
    list->head = first_node;

    for (int i = 1; i < length; i++) {
        insert(list, values[i], get_length(list));
    }
    return list;
}

void __display_list(ListNode *node) {
    printf("%d ", node->value);
    if (node->next == NULL) {
        printf("\n");
        return;
    }
    __display_list(node->next);
}

void display_list(List *list) {
    __display_list(list->head);
}
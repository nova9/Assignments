typedef struct ListNode ListNode;
struct ListNode {
    int value;
    ListNode *next;
    ListNode *prev;
};

typedef struct List {
    ListNode *head;
} List;

ListNode *__traverse(ListNode *node, int i, int index);
ListNode *traverse(List *list, int index);

int __get_length(ListNode *node, int i);
int get_length(List *list);

void insert(List *list, int value, int index);

void delete(List *list, int index);

List *init_list(int values[], int length);

void __display_list(ListNode *node);

void display_list(List *list);
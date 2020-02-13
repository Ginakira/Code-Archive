#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

typedef struct List {
    ListNode head;
    int length;
} List;

ListNode *get_newNode(int val) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = val;
    node->next = NULL;
    return node;
}

List *init_list() {
    List *l = (List *)malloc(sizeof(List));
    l->head.next = NULL;
    l->length = 0;
    return l;
}

int insert(List *l, int ind, int val) {
    if (!l) return -1;
    if (ind < 0 || ind > l->length) return -1;
    int ret = ind;
    ListNode *p = &(l->head), *node = get_newNode(val);
    while (ind--) p = p->next;
    node->next = p->next;
    p->next = node;
    l->length++;
    return ret;
}

int erase(List *l, int ind) {
    if (!l) return -1;
    if (ind < 0 || ind >= l->length) return -1;
    ListNode *p = &(l->head), *node;
    while (ind--) p = p->next;
    node = p->next;
    p->next = node->next;
    free(node);
    l->length--;
    return ind;
}

void output_search(List *l, int ind) {
    char str[100];
    int offset = 3;
    ListNode *p = l->head.next;
    while (ind != -1 && p) {
        offset += sprintf(str, "%d->", p->data);
        ind--;
        p = p->next;
    }
    for (int i = 0; i < offset; ++i) printf(" ");
    printf("^\n");
    for (int i = 0; i < offset; ++i) printf(" ");
    printf("|\n\n");
}

void output(List *l) {
    printf("head->");
    for (ListNode *p = l->head.next; p; p = p->next) {
        printf("%d->", p->data);
    }
    printf("NULL\n");
    return;
}

void clear_node(ListNode *node) {
    if (!node) return;
    free(node);
    return;
}

void clear_list(List *l) {
    if (!l) return;
    ListNode *p = l->head.next, *q;
    while (p) {
        q = p->next;
        clear_node(p);
        p = q;
    }
    free(l);
    return;
}

int main() {
#define max_op 20
    srand(time(0));
    List *l = init_list();
    int op, ind, val, flag;
    for (int i = 0; i < max_op; ++i) {
        op = rand() % 4;
        ind = rand() % (l->length + 3) - 1;
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                flag = insert(l, ind, val);
                printf("Insert %d at %d to list = %d\n", val, ind, flag);
            } break;
            case 3: {
                flag = erase(l, ind);
                printf("Erase item at %d from list = %d\n", ind, flag);
            } break;
        }
        output(l);
        output_search(l, flag);
        printf("\n");
    }
    clear_list(l);
    return 0;
}
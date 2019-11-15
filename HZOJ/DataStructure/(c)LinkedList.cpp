#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct List {
    Node head;
    int length;
} List;

void clear_node(Node *);

Node *init_node(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->val = val;
    p->next = NULL;
    return p;
}

List *init_list() {
    List *l = (List *)malloc(sizeof(List));
    l->head.next = NULL;
    l->length = 0;
    return l;
}

int insert(List *l, int index, int val) {
    if (index < 0 || index > l->length) return 0;
    if (l == NULL) return 0;
    Node *p = &(l->head), *node = init_node(val);
    while (index--) p = p->next;
    node->next = p->next;
    p->next = node;
    l->length += 1;
    return 1;
}

int erase(List *l, int index) {
    if (l == NULL) return 0;
    if (index < 0 || index >= l->length) return 0;
    Node *p = &(l->head), *q;
    while (index--) p = p->next;
    q = p->next;
    p->next = q->next;
    clear_node(q);
    l->length -= 1;
    return 1;
}

int reverse(List *l) {
    if (l == NULL) return 0;
    Node *p = l->head.next, *q;
    l->head.next = NULL;
    while (p) {
        q = p->next;
        p->next = l->head.next;
        l->head.next = p;
        p = q;
    }
    return 1;
}

void output(List *l) {
    if (l == NULL) return;
    printf("list (%d) = [", l->length);
    for (Node *p = l->head.next; p; p = p->next) {
        printf("%d-->", p->val);
    }
    printf("NULL]\n");
    return;
}

void clear_node(Node *node) {
    if (node == NULL) return;
    free(node);
    return;
}

void clear_list(List *l) {
    if (l == NULL) return;
    Node *p = l->head.next, *q;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    free(l);
    return;
}

int main() {
    srand(time(0));
    List *l = init_list();
#define max_op 20
    int op, index, val;
    for (int i = 0; i < max_op; i++) {
        op = rand() % 4;
        index = rand() % (l->length + 3) - 2;
        val = rand() % 100;
        switch (op) {
            case 0: {
                printf("reverse list = %d\n", reverse(l));
                output(l);
            } break;
            case 1:
            case 2: {
                printf("insert %d at %d to the List = %d\n", val, index,
                       insert(l, index, val));
                output(l);
            } break;
            case 3: {
                printf("erase itrems at %d from list = %d\n", index,
                       erase(l, index));
                output(l);
            } break;
        }
    }
    clear_list(l);
    return 0;
}
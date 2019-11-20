/************************************************************
    File Name : 链表复习-单链表的就地转置.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-20 20:06:00
************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *next;
} Node;

typedef struct List {
    Node head;
    int length;
} List;

Node *init_node(char value) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = value;
    p->next = NULL;
    return p;
}

List *init_list() {
    List *l = (List *)malloc(sizeof(List));
    l->length = 0;
    l->head.next = NULL;
    return l;
}

void insert(List *l, int index, char value) {
    Node *p = &(l->head), *q;
    while (index--) p = p->next;
    q = init_node(value);
    q->next = p->next;
    p->next = q;
    l->length++;
    return;
}

void reverse(List *l) {
    Node *p = l->head.next, *q;
    l->head.next = NULL;
    while (p) {
        q = p->next;
        p->next = l->head.next;
        l->head.next = p;
        p = q;
    }
    return;
}

void output(List *l) {
    int i = 0;
    for (Node *p = l->head.next; p; p = p->next, ++i) {
        if (i > 0) printf(" ");
        printf("%c", p->data);
    }
    printf("\n");
    return;
}

int main() {
    List *l = init_list();
    int n;
    char c;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i) {
        scanf("%c", &c);
        getchar();
        insert(l, i, c);
    }
    reverse(l);
    output(l);
    return 0;
}
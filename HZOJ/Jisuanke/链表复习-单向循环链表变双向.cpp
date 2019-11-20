/************************************************************
    File Name : 链表复习-单向循环链表变双向.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-20 20:07:42
************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prior, *next;
} Node, *LinkedList;

Node *init_node(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->prior = NULL;
    node->next = NULL;
    return node;
}

LinkedList insert(LinkedList head, int index, int value) {
    Node *node = init_node(value);
    if (head == NULL) {
        head = node;
        head->next = head;
        head->prior = head;
        return head;
    }
    Node *current_node = head;
    int count = 0;
    while (count < index - 1) {
        current_node = current_node->next;
        count++;
    }
    head->prior = node;
    node->next = current_node->next;
    node->prior = current_node;
    current_node->next = node;
    return head;
}

void output(LinkedList head, int m, int len) {
    Node *current_node = head;
    while (current_node->data != m) {
        current_node = current_node->next;
    }
    for (int i = 0; i < len; ++i) {
        if (i > 0) printf(" ");
        printf("%d", current_node->data);
        current_node = current_node->prior;
    }
}

int main() {
    LinkedList linkedlist = NULL;
    int n, a, m;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        linkedlist = insert(linkedlist, i, a);
    }
    scanf("%d", &m);
    output(linkedlist, m, n);
    return 0;
}
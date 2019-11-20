/************************************************************
    File Name : 树复习-根据三元组数列建立二叉链表.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-20 20:12:55
************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
} Node, *pNode;

typedef struct Queue {
    pNode *data;
    int head, tail, length;
} Queue;

void init_queue(Queue *q, int len) {
    q->data = (pNode *)malloc(sizeof(pNode) * len);
    q->length = len;
    q->head = 0;
    q->tail = -1;
}

Node *init_node(char e) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
}

int empty(Queue *q) { return q->tail < q->head; }

int push(Queue *q, pNode p) {
    if (q->tail + 1 >= q->length) return 0;
    q->data[++q->tail] = p;
    return 1;
}

int pop(Queue *q) {
    if (empty(q)) return 0;
    q->tail--;
    return 0;
}

pNode front(Queue *q) {
    if (empty(q)) return NULL;
    return q->data[q->head];
}

void destory_queue(Queue *q) {
    free(q->data);
    free(q);
}

void destory_tree(Node *p) {
    if (p->lchild) destory_tree(p->lchild);
    if (p->rchild) destory_tree(p->rchild);
    free(p);
}

Node *init(char e) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = e;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

Node *build_tree() {
    char f, c, lr;
    Node *root = NULL, *node = NULL;
    Queue *q = (Queue *)malloc(sizeof(Queue));
    init_queue(q, 200);
    while (scanf("%c%c%c", &f, &c, &lr)) {
        if (f == '^' && c == '^') break;
        if (f == '^') {
            root = init(c);
            push(q, root);
        } else {
            while (!empty(q) && front(q)->data != f) pop(q);
            node = init_node(c);
            if(front(q)->data == f) {
                if(lr == 'L') front(q)->lchild = node;
                else if(lr == 'R') front(q)->rchild = node;
                push(q, node);
            }
        }
    }
}

void output(Node *p) {}

int main() {
    Node *root = NULL;
    root = build_tree();
    return 0;
}
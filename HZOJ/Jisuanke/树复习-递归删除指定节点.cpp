/************************************************************
    File Name : 树复习-递归删除指定节点.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-20 20:00:31
************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
} Node, *pNode;

typedef struct Stack {
    pNode *data;
    int max_size, top_index;
} Stack;

void init_stack(Stack *s, int size) {
    s->data = (pNode *)malloc(sizeof(pNode) * size);
    s->max_size = size;
    s->top_index = -1;
}

int push(Stack *s, pNode node) {
    if (s->top_index + 1 >= s->max_size) return 0;
    s->data[++s->top_index] = node;
    return 1;
}

int pop(Stack *s) {
    if (s->top_index < 0) return 0;
    s->top_index--;
    return 1;
}

pNode top(Stack *s) {
    if (s->top_index < 0) return NULL;
    return s->data[s->top_index];
}

int empty(Stack *s) { return s->top_index == -1; }

void clear_stack(Stack *s) {
    free(s->data);
    free(s);
}

void clear_tree(pNode p) {
    if (!p) return;
    if (p->lchild) clear_tree(p->lchild);
    if (p->rchild) clear_tree(p->rchild);
    free(p);
}

pNode init_tree(char data) {
    pNode node = (pNode)malloc(sizeof(Node));
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

pNode build(char *str) {
    pNode p = NULL, last_p = NULL;
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    init_stack(stack, strlen(str));
    int k = 0;
    while (str[0]) {
        switch (str[0]) {
            case '(':
                k = 0;
                push(stack, p);
                p = NULL;
                break;
            case ',':
                k = 1;
                p = NULL;
                break;
            case ')':
                last_p = top(stack);
                pop(stack);
                break;
            case ' ':
                break;
            default:
                p = init_tree(str[0]);
                if (!empty(stack) && k == 0) {
                    top(stack)->lchild = p;
                } else if (!empty(stack) && k == 1) {
                    top(stack)->rchild = p;
                }
                break;
        }
        ++str;
    }
    if (p && !last_p) last_p = p;
    clear_stack(stack);
    return last_p;
}

void output(pNode p, char x) {
    if (p == NULL || p->data == x) return;
    printf("%c", p->data);
    if ((p->lchild == NULL || p->lchild->data == x) &&
        (p->rchild == NULL || p->rchild->data == x)) {
        return;
    }
    printf("(");
    if (p->lchild && p->lchild->data != x) output(p->lchild, x);
    if (p->rchild && p->rchild->data != x) {
        printf(",");
        output(p->rchild, x);
    }
    printf(")");
    return;
}

int main() {
    char *str = (char *)malloc(sizeof(char) * 40), c;
    int index = 0;
    while (scanf("%c", &c)) {
        if (c == '\n') break;
        str[index++] = c;
    }
    str[index] = 0;
    scanf("%c", &c);
    pNode p = build(str);
    output(p, c);
    clear_tree(p);
    return 0;
}
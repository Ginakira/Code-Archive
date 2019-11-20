/************************************************************
    File Name : 树的复习-层次遍历二叉树.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-20 19:58:36
************************************************************/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    int *data;
    int max_size, top_index;
} Stack;

void init(Stack *s, int len) {
    s->data = (int *)malloc(sizeof(int) * len);
    s->max_size = len;
    s->top_index = -1;
}

int empty(Stack *s) { return s->top_index == -1; }

void push(Stack *s, int e) {
    if (s->top_index + 1 >= s->max_size) return;
    s->data[++s->top_index] = e;
}

void pop(Stack *s) {
    if (empty(s)) return;
    s->top_index--;
}

int top(Stack *s) {
    if (empty(s))
        return 0;
    else
        return s->data[s->top_index];
}

int tree[2000], p = 0;

void build(char *str) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    init(s, 2000);
    char ch;
    int k;
    tree[0] = str[0];
    str++;
    while (str[0]) {
        switch (str[0]) {
            case '(':
                k = 0;
                push(s, p);
                p++;
                break;
            case ',':
                k = 1;
                break;
            case ')':
                pop(s);
                break;
            case ' ':
                break;
            default:
                ch = str[0];
                if (!empty(s) && k == 0) {
                    tree[top(s) * 2 + 1] = ch;
                } else if (!empty(s) && k == 1) {
                    tree[top(s) * 2 + 2] = ch;
                }
        }
        ++str;
    }
}

int main() {
    memset(tree, 0, sizeof(tree));
    char glist[200], ch;
    int ind = 0;
    while (scanf("%c", &ch)) {
        if (ch == '\n') break;
        glist[ind++] = ch;
    }
    if (ind == 0) return 0;
    glist[ind] = 0;
    build(glist);
    for (int i = 0; i < pow(2, p + 1) - 1; ++i) {
        if (tree[i] == 0)
            continue;
        else {
            if (i > 0) printf(" ");
            printf("%c", tree[i]);
        }
    }
    return 0;
}
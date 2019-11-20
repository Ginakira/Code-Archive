/************************************************************
    File Name : 栈复习-蒜头君的魔法机.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-20 20:09:49
************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *data;
    int max_size, top_index;
} Stack;

void init(Stack *s, int length) {
    s->data = (int *)malloc(sizeof(int) * length);
    s->max_size = length;
    s->top_index = -1;
}

int push(Stack *s, int num) {
    if (s->top_index >= s->max_size - 1) return 0;
    s->data[++s->top_index] = num;
    return 1;
}

int pop(Stack *s) {
    if (s->top_index < 0) return 0;
    s->top_index--;
    return 1;
}

int top(Stack *s) { return s->data[s->top_index]; }

int empty(Stack *s) {
    if (s->top_index < 0)
        return 1;
    else
        return 0;
}

void clear(Stack *s) {
    free(s->data);
    free(s);
}

int main() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    int n, ptr = 0, ans[110], push_cnt = 1;
    scanf("%d", &n);
    init(s, n + 5);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &ans[i]);
    }
    while (push_cnt <= n) {
        push(s, push_cnt++);
        while (!empty(s) && top(s) == ans[ptr]) {
            pop(s);
            ptr++;
        }
    }
    if (empty(s))
        printf("YES\n");
    else
        printf("NO\n");
    clear(s);
    return 0;
}
/************************************************************
    File Name : 栈复习-回文判断.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-20 20:11:47
************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    char *data;
    int max_size, top_index;
} Stack;

void init(Stack *s, int len) {
    s->data = (char *)malloc(sizeof(char) * len);
    s->max_size = len;
    s->top_index = -1;
}

int push(Stack *s, char c) {
    if (s->top_index + 1 >= s->max_size) return 0;
    s->data[++s->top_index] = c;
    return 1;
}

int pop(Stack *s) {
    if (s->top_index < 0) return 0;
    s->top_index--;
    return 1;
}

char top(Stack *s) { return s->data[s->top_index]; }

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
    char *str = (char *)malloc(sizeof(char) * 25);
    Stack *s = (Stack *)malloc(sizeof(Stack));
    init(s, 20);
    scanf("%s", str);
    str[strlen(str) - 1] = '\0';
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        push(s, str[i]);
    }
    for (int i = len / 2 + (len % 2); i < len; ++i) {
        if (!empty(s) && str[i] == top(s)) pop(s);
    }
    if (empty(s))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}
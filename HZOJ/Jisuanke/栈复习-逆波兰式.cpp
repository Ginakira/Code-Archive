/************************************************************
    File Name : 栈复习-逆波兰式.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-20 20:10:46
************************************************************/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    int *data;
    int max_size, top_index;
} Stack;

void init(Stack *s, int length) {
    s->data = (int *)malloc(sizeof(int) * length);
    s->max_size = length;
    s->top_index = -1;
}

int push(Stack *s, int data) {
    if (s->top_index + 1 >= s->max_size) return 0;
    s->data[++s->top_index] = data;
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

int precede(char a, char b) {
    if ((a == b) || (a == '+' && b == '-') || (a == '-' && b == '+') ||
        (a == '*' && b == '/') || (a == '/' && b == '*'))
        return 1;
    else if ((a == '*' || a == '/') && (b == '+' || b == '-'))
        return 1;
    else
        return 0;
}

int calc(char op, int a, int b) {
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == '*')
        return a * b;
    else
        return a / b;
}

int main() {
    char *mid = (char *)malloc(sizeof(char) * 20);
    Stack *op = (Stack *)malloc(sizeof(Stack));
    Stack *number = (Stack *)malloc(sizeof(Stack));
    init(op, 20);
    init(number, 20);
    scanf("%s", mid);
    // Transform to Reverse Poland Notation
    for (int i = 0; i < strlen(mid); ++i) {
        if (isdigit(mid[i]))
            push(number, mid[i]);
        else {
            while (!empty(op) && precede(top(op), mid[i])) {
                push(number, top(op));
                pop(op);
            }
            push(op, mid[i]);
        }
    }
    while (!empty(op)) {
        push(number, top(op));
        pop(op);
    }
    // Save to RPN-string in reverse order
    char rpn[20];
    for (int i = strlen(mid) - 1; i >= 0; --i) {
        char tmp = top(number);
        rpn[i] = tmp;
        pop(number);
    }
    // printf("%s\n", rpn);
    // Calculate RPN
    Stack *ans = (Stack *)malloc(sizeof(Stack));
    init(ans, 20);
    for (int i = 0; i < strlen(rpn); ++i) {
        if (isdigit(rpn[i]))
            push(ans, rpn[i] - '0');
        else {
            // printf("C-%c ", rpn[i]);
            int b = top(ans);
            pop(ans);
            int a = top(ans);
            pop(ans);
            // printf("a-%d b-%d\n", a, b);
            push(ans, calc(rpn[i], a, b));
        }
    }
    printf("%d\n", top(ans));
    return 0;
}
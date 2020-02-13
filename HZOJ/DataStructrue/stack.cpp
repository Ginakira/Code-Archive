#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Stack {
    int *data;
    int top, size;
} Stack;

Stack *init(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->top = -1;
    s->size = n;
    return s;
}

int empty(Stack *s) { return s->top == -1; }

int top(Stack *s) { return s->data[s->top]; }

int expand(Stack *s) {
    int extra_size = s->size;
    int *p;
    while (extra_size) {
        p = (int *)realloc(s->data, sizeof(int) * (s->size + extra_size));
        if (p) break;
        extra_size /= 2;
    }
    if (!p) return 0;
    s->size += extra_size;
    s->data = p;
    return 1;
}

int push(Stack *s, int val) {
    if (!s) return 0;
    if (s->top + 1 == s->size) {
        if (!expand(s)) return 0;
        printf("Expanded successfully! Size = %d\n", s->size);
    }
    s->data[++(s->top)] = val;
    return 1;
}

int pop(Stack *s) {
    if (!s) return 0;
    if (empty(s)) return 0;
    s->top--;
    return 1;
}

void output(Stack *s) {
    printf("Stack(%d) = [", s->top + 1);
    for (int i = 0; i <= s->top; ++i) {
        i &&printf(", ");
        printf("%d", s->data[i]);
    }
    printf("]\n");
    return;
}

void clear(Stack *s) {
    if (s == NULL) return;
    free(s->data);
    free(s);
    return;
}

int main() {
#define max_op 20
    srand(time(0));
    Stack *s = init(max_op);
    int op, val;
    for (int i = 0; i < max_op * 2; ++i) {
        op = rand() % 4;
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("Push %d to stack = %d\n", val, push(s, val));
            } break;
            case 3: {
                printf("Pop %d from stack = %d\n", top(s), pop(s));
            } break;
        }
        output(s);
    }
    clear(s);
    return 0;
}
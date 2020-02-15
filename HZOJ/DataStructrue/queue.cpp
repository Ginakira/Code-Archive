#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Queue {
    int *data;
    int head, tail, size, count;
} Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->head = q->tail = q->count = 0;
    q->size = n;
    return q;
}

int empty(Queue *q) { return !q->count; }

int front(Queue *q) { return q->data[q->head]; }

int expand(Queue *q) {
    int *new_data = (int *)malloc(sizeof(int) * (q->size * 2));
    if (!new_data) return 0;
    for (int i = q->head, j = 0; j < q->count; i = (i + 1) % q->size, j++) {
        new_data[j] = q->data[i];
    }
    q->head = 0, q->tail = q->count;
    free(q->data);
    q->data = new_data;
    q->size *= 2;
    return 1;
}

int push(Queue *q, int val) {
    if (!q) return 0;
    if (q->count == q->size) {
        if (!expand(q)) return 0;
        printf("Expanded successfully! Size = %d\n", q->size);
    }
    q->data[q->tail++] = val;
    if (q->tail == q->size) q->tail -= q->size;
    q->count++;
    return 1;
}

int pop(Queue *q) {
    if (!q) return 0;
    if (empty(q)) return 0;
    q->head++;
    if (q->head == q->size) q->head -= q->size;
    q->count--;
    return 1;
}

void output(Queue *q) {
    printf("Queue(%d) = [", q->count);
    for (int i = q->head, j = 0; j < q->count; ++j) {
        j &&printf(", ");
        printf("%d", q->data[(i + j) % (q->size)]);
    }
    printf("]\n");
    return;
}

void clear(Queue *q) {
    if (!q) return;
    free(q->data);
    free(q);
    return;
}

int main() {
#define max_op 20
    srand(time(0));
    Queue *q = init(max_op / 2);
    int op, val;
    for (int i = 0; i < max_op * 2; ++i) {
        op = rand() % 4;
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("Push %d to queue = %d\n", val, push(q, val));
            } break;
            case 3: {
                printf("Pop %d from queue = %d\n", front(q), pop(q));
            } break;
        }
        output(q);
        printf("\n");
    }
    clear(q);
    return 0;
}
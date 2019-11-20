/************************************************************
    File Name : 队列复习-通话记录.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-20 20:08:35
************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    long long *data;
    int head, tail, length;
} Queue;

void init(Queue *q, int len) {
    q->data = (long long *)malloc(sizeof(long long) * len);
    q->head = 0;
    q->tail = -1;
    q->length = len;
}

int push(Queue *q, long long number) {
    if (q->tail + 1 >= q->length) return 0;
    q->data[++q->tail] = number;
    return 1;
}

void pop(Queue *q) { q->head++; }

long long front(Queue *q) { return q->data[q->head]; }

int empty(Queue *q) {
    if (q->head > q->tail)
        return 1;
    else
        return 0;
}

void clear(Queue *q) {
    free(q->data);
    free(q);
}

int main() {
    int type;
    long long tmp;
    Queue *missed = (Queue *)malloc(sizeof(Queue));
    Queue *received = (Queue *)malloc(sizeof(Queue));
    Queue *incoming = (Queue *)malloc(sizeof(Queue));
    init(missed, 15);
    init(received, 15);
    init(incoming, 15);
    for (int i = 0; i < 10; ++i) {
        scanf("%d %lld", &type, &tmp);
        if (type == 0) {
            push(missed, tmp);
        } else if (type == 1) {
            push(received, tmp);
        } else {
            push(incoming, tmp);
        }
    }
    for (int i = 0; i < 10; ++i) {
        if (!empty(missed)) {
            printf("%lld ", front(missed));
            pop(missed);
        } else {
            printf("0 ");
        }
        if (!empty(received)) {
            printf("%lld ", front(received));
            pop(received);
        } else {
            printf("0 ");
        }
        if (!empty(incoming)) {
            printf("%lld\n", front(incoming));
            pop(incoming);
        } else {
            printf("0\n");
        }
    }
    clear(missed);
    clear(received);
    clear(incoming);
    return 0;
}
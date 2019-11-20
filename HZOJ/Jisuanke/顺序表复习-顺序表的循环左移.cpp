/************************************************************
    File Name : 链表复习-顺序表的循环左移.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-20 20:02:22
************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
    int *data;
    int size, length;
} Vector;

void init(Vector *vector, int size) {
    vector->size = size;
    vector->data = (int *)malloc(sizeof(int) * size);
    vector->length = 0;
    return;
}

void expand(Vector *vector) {
    vector->size *= 2;
    vector->data = (int *)realloc(vector->data, vector->size);
    return;
}

int insert(Vector *vector, int index, int value) {
    if (vector == NULL || index < 0 || index > vector->length) return 0;
    if (vector->length >= vector->size) expand(vector);
    vector->data[index] = value;
    vector->length++;
    return 1;
}

int delete_node(Vector *vector, int index) {
    if (index < 0 || index >= vector->length) return 0;
    for (int i = index; i < vector->length; ++i) {
        vector->data[i] = vector->data[i + 1];
    }
    vector->length--;
    return 1;
}

void cycle_move(Vector *vector, int num) {
    for (int i = 0; i < num; ++i) {
        insert(vector, vector->length, vector->data[0]);
        delete_node(vector, 0);
    }
    return;
}

void output(Vector *vector) {
    for (int i = 0; i < vector->length; ++i) {
        if (i > 0) printf(" ");
        printf("%d", vector->data[i]);
    }
    printf("\n");
}

int main() {
    Vector *vector = (Vector *)malloc(sizeof(Vector));
    int n, k, a;
    scanf("%d %d", &n, &k);
    init(vector, n + 5);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        insert(vector, i, a);
    }
    cycle_move(vector, k);
    output(vector);
    return 0;
}
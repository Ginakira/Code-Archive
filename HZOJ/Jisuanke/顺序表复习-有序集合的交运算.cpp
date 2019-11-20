/************************************************************
    File Name : 顺序表复习-有序集合的交运算.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-20 20:04:37
************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
    int size, length;
    int *data;
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

void insert(Vector *vector, int index, int value) {
    if (index < 0 || index > vector->length) return;
    if (vector->length >= vector->size) expand(vector);
    for (int i = vector->length; i > index; --i) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[index] = value;
    vector->length++;
    return;
}

int search(Vector *vector, int value) {
    for (int i = 0; i < vector->length; ++i) {
        if (vector->data[i] == value) {
            return 1;
        }
    }
    return 0;
}

void output(Vector *vector) {
    printf("%d\n", vector->length);
    for (int i = 0; i < vector->length; ++i) {
        if (i > 0) printf(" ");
        printf("%d", vector->data[i]);
    }
    printf("\n");
    return;
}

void mix(Vector *a, Vector *b, Vector *c) {
    for (int i = 0, j = 0; i < a->length; ++i) {
        if (search(b, a->data[i])) {
            insert(c, j++, a->data[i]);
        }
    }
    return;
}

int main() {
    Vector *va = (Vector *)malloc(sizeof(Vector));
    Vector *vb = (Vector *)malloc(sizeof(Vector));
    Vector *vc = (Vector *)malloc(sizeof(Vector));
    int na, aa, nb, ba;
    scanf("%d", &na);
    init(va, na + 5);
    for (int i = 0; i < na; ++i) {
        scanf("%d", &aa);
        insert(va, i, aa);
    }
    scanf("%d", &nb);
    init(vb, nb + 5);
    for (int i = 0; i < nb; ++i) {
        scanf("%d", &ba);
        insert(vb, i, ba);
    }
    init(vc, na + nb + 5);
    mix(va, vb, vc);
    output(vc);
    return 0;
}
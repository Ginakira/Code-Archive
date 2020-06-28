#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Vector {
    int *data;
    int size, length;
} Vector;

Vector *init(int n) {
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    vec->data = (int *)calloc(n, sizeof(int));
    vec->size = n;
    vec->length = 0;
    return vec;
}

int insert(Vector *vec, int ind, int val) {
    if (!vec) return 0;
    if (ind < 0 || ind > vec->length) return 0;
    if (vec->length == vec->size) return 0;
    for (int i = vec->length; i > ind; --i) {
        vec->data[i] = vec->data[i - 1];
    }
    vec->data[ind] = val;
    vec->length++;
    return 1;
}

int erase(Vector *vec, int ind) {
    if (!vec) return 0;
    if (ind < 0 || ind >= vec->length) return 0;
    for (int i = ind + 1; i < vec->length; ++i) {
        vec->data[i - 1] = vec->data[i];
    }
    vec->length--;
    return 1;
}

void output(Vector *vec) {
    printf("Vector(%d): [", vec->length);
    for (int i = 0; i < vec->length; ++i) {
        i &&printf(", ");
        printf("%d", vec->data[i]);
    }
    printf("]\n");
    return;
}

void clear(Vector *vec) {
    if (!vec) return;
    free(vec->data);
    free(vec);
    return;
}

int main() {
#define max_op 20
    srand(time(0));
    Vector *vec = init(max_op);
    int op, ind, val;
    for (int i = 0; i < max_op; ++i) {
        op = rand() % 4;
        ind = rand() % (vec->length + 3) - 1;
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("Insert %d at %d = %d\n", val, ind,
                       insert(vec, ind, val));
            } break;
            case 3: {
                printf("Erase %d index = %d\n", ind, erase(vec, ind));
            } break;
        }
        output(vec);
    }
    return 0;
}
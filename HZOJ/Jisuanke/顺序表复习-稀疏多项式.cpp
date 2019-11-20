/************************************************************
    File Name : 顺序表复习-稀疏多项式.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-20 20:03:58
************************************************************/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Data {
    int c, e;
} Data;

typedef struct Vector {
    Data *data;
    int size, length;
} Vector;

void init(Vector *vector, int size) {
    vector->data = (Data *)malloc(sizeof(Data));
    vector->size = size;
    vector->length = 0;
    return;
}

void insert(Vector *vector, int index, int c, int e) {
    if (index < 0 || index > vector->length) return;
    for (int i = vector->length; i > index; --i) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[index].c = c;
    vector->data[index].e = e;
    vector->length++;
    return;
}

long long solve(Vector *vector, int x) {
    long long ans = 0;
    for (int i = 0; i < vector->length; ++i) {
        ans += vector->data[i].c * pow(x, vector->data[i].e);
    }
    return ans;
}

int main() {
    Vector *vector = (Vector *)malloc(sizeof(Vector));
    int m, c, e, x;
    scanf("%d", &m);
    init(vector, m + 5);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &c, &e);
        insert(vector, i, c, e);
    }
    scanf("%d", &x);
    printf("%lld", solve(vector, x));
    return 0;
}
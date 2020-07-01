/************************************************************
    File Name : haffman.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/01 12:31:20
************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000
#define swap(a, b)              \
    {                           \
        __typeof(a) temp = (a); \
        (a) = (b), (b) = temp;  \
    }

typedef struct Node {
    char ch;
    double p;
    struct Node *next[2];
} Node;

typedef struct HaffmanTree {
    Node *root;
} HaffmanTree;

typedef struct Data {
    char ch;
    double p;
} Data;

Data arr[MAX_N + 5];

Node *getNewNode(Data *obj) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = obj->ch;
    p->p = obj->p;
    p->next[0] = p->next[1] = NULL;
    return p;
}

HaffmanTree *build(Data *arr, int n) {
    Node **nodes = (Node **)malloc(sizeof(Node *) * n);
    for (int i = 0; i < n; ++i) {
        nodes[i] = getNewNode(arr + i);
    }
    // INSERT SORT BY P
    for (int i = 1; i < n; ++i) {
        for (int j = i; j >= 1; --j) {
            if (arr[j].p > arr[j - 1].p) swap(arr[j], arr[j - 1]);
            break;
        }
    }
}

int main() {
    int n;
    char str[10];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s%lf", str, &arr[i].p);
        arr[i].ch = str[0];
    }
    HaffmanTree *tree = build(arr, n);

    return 0;
}

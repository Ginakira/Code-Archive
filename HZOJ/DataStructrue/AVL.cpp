/************************************************************
    File Name : AVL.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/23 18:16:32
************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define H(root) (root)->h
#define L(root) (root)->lchild
#define R(root) (root)->rchild
#define K(root) (root)->key

typedef struct Node {
    int key, h;
    struct Node *lchild, *rchild;
} Node;

Node __NIL;
#define NIL (&__NIL)

__attribute__((constructor)) void init_NIL() {
    NIL->key = NIL->h = 0;
    NIL->lchild = NIL->rchild = NIL;
    return;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->h = 1;
    p->lchild = p->rchild = NIL;
    return p;
}

void update_height(Node *root) {
    root->h = (H(L(root)) > H(R(root)) ? H(L(root)) : H(R(root))) + 1;
    return;
}

Node *left_rotate(Node *root) {
    Node *temp = root->rchild;  // Root after rotate
    root->rchild = temp->lchild;
    temp->lchild = root;
    update_height(root);
    update_height(temp);
    return temp;
}

Node *right_rotate(Node *root) {
    Node *temp = root->lchild;  // Roor after rotate
    root->lchild = root->rchild;
    temp->rchild = root;
    update_height(root);
    update_height(temp);
    return temp;
}

Node *maintain(Node *root) {
    if (abs(H(L(root)) - H(R(root))) <= 1) return root;
    if (H(L(root)) > H(R(root))) {            // L
        if (H(R(L(root))) > H(L(L(root)))) {  // LR
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {                                  // R
        if (H(L(R(root))) > H(R(R(root)))) {  // RL
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
    return root;
}

Node *insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key)
        root->lchild = insert(root->lchild, key);
    else
        root->rchild = insert(root->rchild, key);
    update_height(root);
    return maintain(root);
}

void clear(Node *root) {
    if (root == NIL) return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return;
}

void output(Node *root) {
    if (root == NIL) return;
    printf("(%d, %d, %d)\n", K(root), K(L(root)), K(R(root)));
    output(root->lchild);
    output(root->rchild);
}

int main() {
#define MAX_OP 30
    srand(time(0));
    Node *root = NIL;
    for (int i = 0; i < MAX_OP; ++i) {
        int val = rand() % 100;
        printf("Insert %d to AVL tree\n", val);
        root = insert(root, val);
        output(root);
    }
    return 0;
}
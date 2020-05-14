/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/14 17:09:09
************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define H(root) (root)->h
#define L(root) (root)->lchild
#define R(root) (root)->rchild

typedef struct Node {
    int key, h;
    struct Node *lchild, *rchild;
} Node;

Node __NIL;
#define NIL (&__NIL)

__attribute__((constructor)) void init_NIL() {
    NIL->key = 0;
    NIL->h = 0;
    NIL->lchild = NIL->rchild = NIL;
    return;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NIL;
    p->h = 1;
    return p;
}

void update_height(Node *root) {
    root->h = H(L(root)) > H(R(root)) ? H(L(root)) : H(R(root));
    return;
}

Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    
}

Node *right_rotate(Node *root) {}

Node *maintain(Node *root) {
    if (abs(H(L(root)) - H(R(root))) <= 1) return root;
    if (H(L(root)) > H(R(root))) {            // L
        if (H(R(L(root))) > H(L(L(root)))) {  // LR
            root = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {                                  // R
        if (H(L(R(root))) > H(R(R(root)))) {  // RL
            root = right_rotate(root->rchild);
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

int main() { return 0; }
/************************************************************
    File Name : rbt_v197.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/18 23:32:13
************************************************************/

#include <stdio.h>
#include <stdlib.h>

enum colors { RED, BLACK, DOUBLE_BLACK };

typedef struct Node {
    int key, color;  // 0 RED 1 BLACK 2 DOUBLE_BLACK
    struct Node *lchild, *rchild;
} Node;

Node __NIL, *const NIL = &__NIL;

__attribute__((constructor)) void init_NIL() {
    NIL->lchild = NIL->rchild = NIL;
    NIL->key = 0;
    NIL->color = BLACK;
    return;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NIL;
    p->color = RED;
    return p;
}

bool has_red_child(Node *root) {
    return root->lchild->color == RED || root->rchild->color == RED;
}

Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}

Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}

Node *insert_maintain(Node *root) {
    if (!has_red_child(root)) return root;
    if (root->lchild->color == RED && root->rchild->color == RED) {
        if (!has_red_child(root->lchild) && !has_red_child(root->rchild))
            return root;
        goto insert_end;
    }
    if (root->lchild->color == RED) {  // L
        if (!has_red_child(root->lchild)) return root;
        if (root->lchild->rchild->color == RED) {  // LR
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {  // R
        if (!has_red_child(root->rchild)) return root;
        if (root->rchild->lchild->color == RED) {  // RL
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
insert_end:
    root->color = RED;
    root->lchild->color = root->rchild->color = BLACK;
    return root;
}

Node *__insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) {
        root->lchild = __insert(root->lchild, key);
    } else {
        root->rchild = __insert(root->rchild, key);
    }
    return insert_maintain(root);
}

Node *insert(Node *root, int key) {
    root = __insert(root, key);
    root->color = BLACK;
    return root;
}

void clearNode(Node *root) {
    if (root == NIL) return;
    clearNode(root->lchild);
    clearNode(root->rchild);
    free(root);
    return;
}

void output(Node *root) {
    if (root == NIL) return;
    printf("%d [%d, %d] %s\n", root->key, root->lchild->key, root->rchild->key,
           root->color ? "BLACK" : "RED");
    output(root->lchild);
    output(root->rchild);
    return;
}

int main() {
    Node *root = NIL;
    int op, val;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 1: {
                root = insert(root, val);
            } break;
            case 2: {
            } break;
        }
        output(root);
    }
    return 0;
}
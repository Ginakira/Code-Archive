/*
    线索化二叉树 - 先序遍历
    与中序遍历不同：
     - 构建线索化时，使用根左右的顺序，同时要判断左右孩子是否已经线索化
       如果没被线索化，则向下走进行递归线索化
     - 输出时，先输出根，如果左孩子不是线索，则往左走，否则向右走
       因为是根左右，且构建完成后不存在空的孩子，要么原来存在要么已经变为线索
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NORMAL 0
#define THREAD 1

typedef struct Node {
    int data;
    Node *lchild, *rchild;
    int ltag, rtag;
} Node;

Node *get_new_node(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    p->ltag = NORMAL;
    p->rtag = NORMAL;
    return p;
}

Node *insert(Node *root, int val) {
    if (!root) return get_new_node(val);
    if (root->data == val) return root;
    if (val < root->data)
        root->lchild = insert(root->lchild, val);
    else
        root->rchild = insert(root->rchild, val);
    return root;
}

void build_thread_preorder(Node *root) {
    if (!root) return;
    static Node *pre = NULL;
    if (!root->lchild) {
        root->lchild = pre;
        root->ltag = THREAD;
    }
    if (pre && !pre->rchild) {
        pre->rchild = root;
        pre->rtag = THREAD;
    }
    pre = root;
    if (root->ltag == NORMAL) build_thread_preorder(root->lchild);
    if (root->rtag == NORMAL) build_thread_preorder(root->rchild);
    return;
}

void output_preorder(Node *root) {
    Node *p = root;
    while (p) {
        printf("%d ", p->data);
        if (p->ltag == NORMAL) {
            p = p->lchild;
        } else {
            p = p->rchild;
        }
    }
    return;
}

void pre_order(Node *root) {
    if (!root) return;
    printf("%d ", root->data);
    if (root->ltag == NORMAL) pre_order(root->lchild);
    if (root->rtag == NORMAL) pre_order(root->rchild);
}

void clear(Node *root) {
    if (!root) return;
    if (root->ltag == NORMAL) clear(root->lchild);
    if (root->rtag == NORMAL) clear(root->rchild);
    free(root);
}

int main() {
#define max_op 10
    srand(time(0));
    Node *root = NULL;
    printf("Insert values:\t  ");
    for (int i = 0; i < 5; ++i) {
        int val = rand() % 100;
        printf("%d ", val);
        root = insert(root, val);
    }
    build_thread_preorder(root);
    printf("\nPre-Order:\t  "), pre_order(root), printf("\n");
    printf("Thread-Pre-Order: "), output_preorder(root), printf("\n");
    clear(root);
    return 0;
}
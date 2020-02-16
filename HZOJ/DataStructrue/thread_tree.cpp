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

void build_thread_inorder(Node *root) {
    if (!root) return;
    static Node *pre = NULL;
    build_thread_inorder(root->lchild);
    if (!root->lchild) {
        root->lchild = pre;
        root->ltag = THREAD;
    }
    if (pre && !pre->rchild) {
        pre->rchild = root;
        pre->rtag = THREAD;
    }
    pre = root;
    build_thread_inorder(root->rchild);
    return;
}

void build_thread_postorder(Node *root) {
    if (!root) return;
    static Node *pre = NULL;
    build_thread_postorder(root->lchild);
    build_thread_postorder(root->rchild);
    if (!root->lchild) {
        root->lchild = pre;
        root->ltag = THREAD;
    }
    if (pre && !pre->rchild) {
        pre->rchild = root;
        pre->rtag = THREAD;
    }
    pre = root;
    return;
}

Node *most_left(Node *p) {
    while (p && p->ltag == NORMAL && p->lchild) p = p->lchild;
    return p;
}

void output_postorder(Node *root) {
    Node *p = root;
    while (p) {
        if (p->ltag == NORMAL && p->lchild)
            p = p->lchild;
        else if (p->rtag == NORMAL && p->rchild)
            p = p->rchild;
        else
            break;
    }
    while (p) {
        printf("%d ", p->data);
        if (p->rtag == THREAD) {
            p = p->rchild;
        } else {
            p = most_left(p->rchild);
        }
    }
    return;
}

void output_inorder(Node *root) {
    Node *p = most_left(root);
    while (p) {
        printf("%d ", p->data);
        if (p->rtag == THREAD) {
            p = p->rchild;
        } else {
            p = most_left(p->rchild);
        }
    }
}

void in_order(Node *root) {
    if (!root) return;
    if (root->ltag == NORMAL) in_order(root->lchild);
    printf("%d ", root->data);
    if (root->rtag == NORMAL) in_order(root->rchild);
    return;
}

void post_order(Node *root) {
    if (!root) return;
    if (root->ltag == NORMAL) post_order(root->lchild);
    if (root->rtag == NORMAL) post_order(root->rchild);
    printf("%d ", root->data);
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
    for (int i = 0; i < max_op; ++i) {
        int val = rand() % 100;
        printf("%d ", val);
        root = insert(root, val);
    }
    // build_thread_inorder(root);
    // printf("Thread-In-Order: "), output_inorder(root), printf("\n");
    // printf("In-Order:\t "), in_order(root), printf("\n");
    build_thread_postorder(root);
    printf("\nPost-Order:\t "), post_order(root), printf("\n");
    getchar();
    printf("Thread-Post-Order: "), output_postorder(root), printf("\n");
    clear(root);
    return 0;
}
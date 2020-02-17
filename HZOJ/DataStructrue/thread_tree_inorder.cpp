/*
    线索化二叉树 - 中序遍历
     - 构建线索化时，使用左根右的顺序，pre记录的是上一个走的节点，方便记录前驱
       在记录前驱时，同时将pre的后继指向当前的节点
     - 输出时，因为是中序遍历，所以执行输出要先走到树的最左叶节点
       所以，如果右孩子是线索，也就是后继的话，就走到后继，如果不是，就往下走到右子树的最左子节点
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

Node *most_left(Node *p) {
    while (p && p->ltag == NORMAL && p->lchild) p = p->lchild;
    return p;
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
    printf("Insert values:\t ");
    for (int i = 0; i < 5; ++i) {
        int val = rand() % 100;
        printf("%d ", val);
        root = insert(root, val);
    }
    build_thread_inorder(root);
    printf("\nThread-In-Order: "), output_inorder(root), printf("\n");
    printf("In-Order:\t "), in_order(root), printf("\n");

    clear(root);
    return 0;
}
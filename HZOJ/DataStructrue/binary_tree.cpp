#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
} Node;

typedef struct Tree {
    Node *root;
    int n;
} Tree;

Node *get_new_node(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    return p;
}

Tree *get_new_tree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}

Node *insert_node(Node *root, int val, int *ret) {
    if (!root) {
        *ret = 1;
        return get_new_node(val);
    }
    if (root->data == val) return root;
    if (val < root->data)
        root->lchild = insert_node(root->lchild, val, ret);
    else
        root->rchild = insert_node(root->rchild, val, ret);
    return root;
}

void insert(Tree *tree, int val) {
    int flag = 0;
    tree->root = insert_node(tree->root, val, &flag);
    tree->n += flag;
    return;
}

void output_node(Node *root) {
    if (!root) return;
    printf("%d", root->data);
    if (!root->lchild && !root->rchild) return;
    printf("("); 
    output_node(root->lchild);
    printf(",");
    output_node(root->rchild);
    printf(")");
    return;
}

void output(Tree *tree) {
    printf("Tree(%d) : ", tree->n);
    output_node(tree->root);
    printf("\n");
    return;
}

void pre_order_node(Node *root) {
    if (!root) return;
    printf("%d ", root->data);
    pre_order_node(root->lchild);
    pre_order_node(root->rchild);
    return;
}

void pre_order(Tree *tree) {
    printf("Pre-Order : ");
    pre_order_node(tree->root);
    printf("\n");
    return;
}

void in_order_node(Node *root) {
    if (!root) return;
    in_order_node(root->lchild);
    printf("%d ", root->data);
    in_order_node(root->rchild);
    return;
}

void in_order(Tree *tree) {
    printf("In-Order : ");
    in_order_node(tree->root);
    printf("\n");
    return;
}

void post_order_node(Node *root) {
    if (!root) return;
    post_order_node(root->lchild);
    post_order_node(root->rchild);
    printf("%d ", root->data);
    return;
}

void post_order(Tree *tree) {
    printf("Post-Order : ");
    post_order_node(tree->root);
    printf("\n");
    return;
}

void clear_node(Node *node) {
    if (!node) return;
    clear_node(node->lchild);
    clear_node(node->rchild);
    free(node);
    return;
}

void clear_tree(Tree *tree) {
    if (!tree) return;
    clear_node(tree->root);
    free(tree);
    return;
}

int main() {
#define max_op 10
    srand(time(0));
    Tree *tree = get_new_tree();
    for (int i = 0; i < max_op; ++i) {
        int val = rand() % 100;
        insert(tree, val);
        output(tree);
    }
    printf("\n");
    pre_order(tree);
    in_order(tree);
    post_order(tree);
    clear_tree(tree);
    return 0;
}
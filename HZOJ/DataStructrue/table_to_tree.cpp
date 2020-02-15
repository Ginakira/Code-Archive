#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
} Node;

typedef struct Tree {
    Node *root;
    int n;
} Tree;

Node *get_new_node(char val) {
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

typedef struct Stack {
    Node **data;
    int size, top;
} Stack;

Stack *init_stack(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (Node **)malloc(sizeof(Node *) * n);
    s->top = -1;
    s->size = n;
    return s;
}

int empty(Stack *s) { return s->top == -1; }

Node *top(Stack *s) { return s->data[s->top]; }

int push(Stack *s, Node *val) {
    if (!s) return 0;
    if (s->top == s->size - 1) return 0;
    s->data[++s->top] = val;
    return 1;
}

int pop(Stack *s) {
    if (empty(s)) return 0;
    s->top--;
    return 1;
}

void clear_stack(Stack *s);

Node *build(char *str, int *node_num) {
    Node *temp = NULL, *p = NULL;
    Stack *s = init_stack(strlen(str));
    int flag = 0;
    while (str[0]) {
        switch (str[0]) {
            case '(': {
                push(s, temp);
                flag = 0;
                temp = NULL;
            } break;
            case ')': {
                p = top(s);
                pop(s);
            } break;
            case ',': {
                flag = 1;
                temp = NULL;
            } break;
            case ' ':
                break;
            default: {
                temp = get_new_node(str[0]);
                if (!empty(s) && flag == 0)
                    top(s)->lchild = temp;
                else if (!empty(s) && flag == 1)
                    top(s)->rchild = temp;
                (*node_num)++;
            } break;
        }
        str++;
    }
    if (temp && !p) p = temp;
    clear_stack(s);
    return p;
}

void in_order_node(Node *node) {
    if (!node) return;
    in_order_node(node->lchild);
    printf("%c ", node->data);
    in_order_node(node->rchild);
}

void in_order(Tree *tree) {
    printf("In-Order : ");
    in_order_node(tree->root);
}

void pre_order_node(Node *node) {
    if (!node) return;
    printf("%c ", node->data);
    pre_order_node(node->lchild);
    pre_order_node(node->rchild);
}

void pre_order(Tree *tree) {
    printf("Pre-Order : ");
    pre_order_node(tree->root);
}

void post_order_node(Node *node) {
    if (!node) return;
    post_order_node(node->lchild);
    post_order_node(node->rchild);
    printf("%c ", node->data);
}

void post_order(Tree *tree) {
    printf("Post-Order : ");
    post_order_node(tree->root);
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

void clear_stack(Stack *s) {
    if (!s) return;
    free(s->data);
    free(s);
    return;
}

int main() {
    char str[100];
    scanf("%[^\n]s", str);
    int node_num = 0;
    Tree *tree = get_new_tree();
    tree->root = build(str, &node_num);
    tree->n = node_num;
    pre_order(tree), printf("\n");
    in_order(tree), printf("\n");
    post_order(tree), printf("\n");
    clear_tree(tree);
    return 0;
}
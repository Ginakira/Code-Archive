#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
} Node;

Node *get_new_node(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *insert(Node *root, int key) {
    if (!root) return get_new_node(key);
    if (root->key == key) return root;
    if (key < root->key)
        root->lchild = insert(root->lchild, key);
    else
        root->rchild = insert(root->rchild, key);
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int key) {
    if (!root) return root;
    if (key < root->key)
        root->lchild = erase(root->lchild, key);
    else if (key > root->key)
        root->rchild = erase(root->rchild, key);
    else {
        if (!root->lchild || !root->rchild) {
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    return root;
}

void __in_order(Node *root) {
    if (!root) return;
    __in_order(root->lchild);
    printf("%d ", root->key);
    __in_order(root->rchild);
    return;
}

void in_order(Node *root) {
    printf("In-order output : ");
    __in_order(root);
    printf("\n");
    return;
}

void clear(Node *root) {
    if (!root) return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return;
}

int main() {
    int op, val;
    Node *root = NULL;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 1:
                root = insert(root, val);
                break;
            case 2:
                root = erase(root, val);
                break;
        }
        in_order(root);
    }
    clear(root);
    return 0;
}
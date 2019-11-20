/************************************************************
    File Name : 树复习-神奇的二叉树.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-20 19:59:17
************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
} Node;

Node *init(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

void postorder(Node *node) {
    if (node->lchild) postorder(node->lchild);
    if (node->rchild) postorder(node->rchild);
    printf("%c", node->data);
}

void mirror_order(Node *node) {
    if (node->rchild) mirror_order(node->rchild);
    if (node->lchild) mirror_order(node->lchild);
    printf("%c", node->data);
}

Node *build(char pre_str[], char in_str[], int len) {
    Node *p = init(pre_str[0]);
    int pos = strchr(in_str, pre_str[0]) - in_str;
    if (pos > 0) {
        p->lchild = build(pre_str + 1, in_str, pos);
    }
    if (len - pos - 1 > 0) {
        p->rchild = build(pre_str + pos + 1, in_str + pos + 1, len - pos - 1);
    }
    return p;
}

int main() {
    char *pre_str = (char *)malloc(sizeof(char) * 55);
    char *in_str = (char *)malloc(sizeof(char) * 55);
    scanf("%s %s", pre_str, in_str);
    Node *root = build(pre_str, in_str, strlen(pre_str));
    postorder(root);
    printf("\n");
    mirror_order(root);
    return 0;
}
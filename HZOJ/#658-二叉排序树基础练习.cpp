/************************************************************
    File Name : #658-二叉排序树基础练习.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/31 23:22:27
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node *lchild, *rchild;
};

Node *get_new_node(int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->lchild = node->rchild = NULL;
    return node;
}

Node *insert(Node *root, int val) {
    if (root == NULL) return get_new_node(val);
    if (root->val == val) return root;
    if (root->val > val) {
        root->lchild = insert(root->lchild, val);
    } else {
        root->rchild = insert(root->rchild, val);
    }
    return root;
}

int find_predecessor(Node *root, int val) {
    if (!root) return -1;
    Node *node = root->lchild;
    while (node->rchild) {
        node = node->rchild;
    }
    return node->val;
}

int find_successor(Node *root, int val) {
    if (!root) return -1;
    Node *node = root->rchild;
    while (node->lchild) {
        node = node->lchild;
    }
    return node->val;
}

int main() {
    Node *root = NULL;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        switch (a) {
            case 1: {
                root = insert(root, b);
            } break;
            case 2: {
                cout << find_predecessor(root, b) << endl;
            } break;
            case 3: {
                cout << find_successor(root, b) << endl;
            }
        }
    }

    return 0;
}
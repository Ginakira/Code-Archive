#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(): left(NULL), right(NULL) {}
};

Node* root;

Node* newnode() {return new Node();}



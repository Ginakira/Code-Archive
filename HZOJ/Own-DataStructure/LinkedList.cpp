#include "LinkedList.h"
#include <iostream>
using namespace std;

Node::Node() {
    data = -1;
    next = nullptr;
}

Node::Node(int val) {
    data = val;
    next = nullptr;
}

LinkedList::LinkedList() {
    head = Node();
    length = 0;
}

bool LinkedList::insert(int index, int val) {
    int tmp = index;
    if (index < 0 || index > length) {
        cout << "Insert failed! (index)" << index << endl;
        return false;
    }
    Node *p = &head;
    while (index--) p = p->next;

    //可以运行
    Node *new_node = new Node(val);
    new_node->next = p->next;
    p->next = new_node;

    //  段错误
    /* Node new_node(val);
    new_node.next = p->next;
    p->next = &new_node; */
    /* Node *node = (Node *)malloc(sizeof(Node));
    node->data = val;
    node->next = nullptr;
    node->next = p->next;
    p->next = node; */

    length++;
    cout << "Insert successful! (index)" << tmp << " (val)" << val << endl;
    return true;
}

bool LinkedList::delete_node(int index) {
    if (index < 0 || index >= length) {
        cout << "Delete failed! (index)" << index << endl;
        return false;
    }
    Node *p = &head, *d_node;
    while (index--) p = p->next;
    d_node = p->next;
    p->next = d_node->next;
    delete d_node;
    length--;
    cout << "Delete successful! (index)" << index << endl;
    return true;
}

int LinkedList::search(int val) {
    int index = 0;
    Node *p = &head;
    while (p->next) {
        if (p->data == val) {
            cout << "Node founded. (val)" << val << " (index)" << index << endl;
            return index;
        }
        index++;
    }
    cout << "Not found..." << endl;
    return -1;
}

bool LinkedList::reverse() {
    Node *p = head.next, *q;
    head.next = nullptr;
    while (p) {
        q = p->next;
        p->next = head.next;
        head.next = p;
        p = q;
    }
    cout << "Reverse successful!\n";
    return true;
}

int LinkedList::get_len() { return length; }

void LinkedList::output() {
    Node *p = head.next;
    cout << "Output: [";
    for (int i = 0; p; ++i, p = p->next) {
        if (i > 0) cout << "->";
        cout << p->data;
    }
    cout << "]\n";
    return;
}

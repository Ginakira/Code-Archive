#include <iostream>
using namespace std;

template <class Type>
class Node {
   public:
    Type data;
    Node *next;
    Node();
    Node(Type val);
};

template <class Type>
class LinkedList {
   private:
    Node<Type> head;
    int length;

   public:
    LinkedList();
    bool insert(int index, Type val);
    bool delete_node(int index);
    int search(Type val);
    bool reverse();
    int get_len();
    void output();
};

template <class Type>
Node<Type>::Node() {
    data = -1;
    next = nullptr;
}

template <class Type>
Node<Type>::Node(Type val) {
    data = val;
    next = nullptr;
}

template <class Type>
LinkedList<Type>::LinkedList() {
    head = Node<Type>();
    length = 0;
}

template <class Type>
bool LinkedList<Type>::insert(int index, Type val) {
    int tmp = index;
    if (index < 0 || index > length) {
        cout << "Insert failed! (index)" << index << endl;
        return false;
    }
    Node<Type> *p = &head;
    while (index--) p = p->next;

    //可以运行
    Node<Type> *new_node = new Node(val);
    new_node->next = p->next;
    p->next = new_node;

    /*  段错误
        Node new_node(val);
        new_node.next = p->next;
        p->next = &new_node;
     */
    length++;
    cout << "Insert successful! (index)" << tmp << " (val)" << val << endl;
    return true;
}

template <class Type>
bool LinkedList<Type>::delete_node(int index) {
    if (index < 0 || index >= length) {
        cout << "Delete failed! (index)" << index << endl;
        return false;
    }
    Node<Type> *p = &head, *d_node;
    while (index--) p = p->next;
    d_node = p->next;
    p->next = d_node->next;
    delete d_node;
    length--;
    cout << "Delete successful! (index)" << index << endl;
    return true;
}

template <class Type>
int LinkedList<Type>::search(Type val) {
    int index = 0;
    Node<Type> *p = &head;
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

template <class Type>
bool LinkedList<Type>::reverse() {
    Node<Type> *p = head.next, *q;
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

template <class Type>
int LinkedList<Type>::get_len() {
    return length;
}

template <class Type>
void LinkedList<Type>::output() {
    Node<Type> *p = head.next;
    cout << "Output: [";
    for (int i = 0; p; ++i, p = p->next) {
        if (i > 0) cout << "->";
        cout << p->data;
    }
    cout << "]\n";
    return;
}

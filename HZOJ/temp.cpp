/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/12/21 21:13:55
************************************************************/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Node {
    Node() : id(0), name(""), rate(0), next(nullptr) {}
    Node(int id, string name, double rate)
        : id(id), name(name), rate(rate), next(nullptr) {}
    int id;
    string name;
    double rate;
    Node *next;
};

ifstream fin("data.in");

class LinkedList {
   public:
    LinkedList();
    ~LinkedList();
    Node *getHead();
    Node *getCurrent();
    int getCount();
    bool insert(Node *);

   private:
    Node *_head;
    Node *_current;
    int _count;
};

LinkedList::LinkedList() {
    this->_head = new Node();
    this->_current = this->_head;
    this->_count = 0;
}

LinkedList::~LinkedList() {
    Node *p = this->_head;
    while (p != nullptr) {
        Node *q = p->next;
        delete p;
        p = q;
    }
}

int LinkedList::getCount() { return this->_count; }

Node *LinkedList::getCurrent() { return this->_current; }

Node *LinkedList::getHead() { return this->_head->next; }

bool LinkedList::insert(Node *node) {
    this->_current->next = node;
    this->_current = this->_current->next;
    this->_count++;
    return true;
}

int main() {
    LinkedList l;
    int id;
    string name;
    double rate;
    while (fin >> id >> name >> rate) {
        l.insert(new Node(id, name, rate));
    }

    Node *p = l.getHead();
    while (p != nullptr) {
        cout << p->id << ' ' << p->name << ' ' << p->rate << endl;
        p = p->next;
    }
    return 0;
}
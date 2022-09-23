// LeetCode 707 设计链表

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class MyLinkedList {
   private:
    class LinkNode {
       public:
        LinkNode() : LinkNode(0, nullptr) {}
        LinkNode(int data) : LinkNode(data, nullptr) {}
        LinkNode(int data, LinkNode *next) : data(data), next(next) {}
        int data;
        LinkNode *next;
    };

    LinkNode *dummy_head_;
    LinkNode *tail_;
    int length_;

    LinkNode *get_node(int index) {
        LinkNode *p = dummy_head_;
        for (int i = 0; i <= index; ++i) {
            if (!p) {
                return nullptr;
            }
            p = p->next;
        }
        return p;
    }

   public:
    MyLinkedList() {
        dummy_head_ = new LinkNode();
        tail_ = dummy_head_;
        length_ = 0;
    }

    ~MyLinkedList() {
        LinkNode *p = dummy_head_;
        while (p != nullptr) {
            LinkNode *tmp = p->next;
            delete p;
            p = tmp;
        }
    }

    int get(int index) {
        LinkNode *node = get_node(index);
        return node ? node->data : -1;
    }

    void addAtHead(int val) { addAtIndex(0, val); }

    void addAtTail(int val) {
        LinkNode *node = new LinkNode(val);
        tail_->next = node;
        tail_ = node;
        ++length_;
    }

    void addAtIndex(int index, int val) {
        index = max(0, index);
        if (index > length_) {
            return;
        } else if (index == length_) {
            addAtTail(val);
            return;
        }
        LinkNode *p = get_node(index - 1);
        LinkNode *node = new LinkNode(val, p->next);
        p->next = node;
        ++length_;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= length_) {
            return;
        }
        LinkNode *p = get_node(index - 1);
        LinkNode *del_node = p->next;
        p->next = del_node->next;
        if (index == length_ - 1) {
            tail_ = p;
        }
        delete del_node;
        --length_;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
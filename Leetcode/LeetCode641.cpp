// LeetCode 641 设计循环双端队列
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class MyCircularDeque {
   private:
    vector<int> data_;
    int head_ = 0;
    int tail_ = 0;
    int cap_ = 0;

   public:
    MyCircularDeque(int k) : cap_(k + 1) {
        head_ = 0;
        tail_ = 0;
        data_.resize(k + 1);
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        head_ = (head_ - 1 + cap_) % cap_;
        data_[head_] = value;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        data_[tail_] = value;
        tail_ = (tail_ + 1) % cap_;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        head_ = (head_ + 1) % cap_;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        tail_ = (tail_ - 1 + cap_) % cap_;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return data_[head_];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return data_[(tail_ - 1 + cap_) % cap_];
    }

    bool isEmpty() { return head_ == tail_; }

    bool isFull() { return (tail_ + 1) % cap_ == head_; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
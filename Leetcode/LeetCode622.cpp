// LetCode 622 设计循环队列

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class MyCircularQueue {
   private:
    vector<int> data_;
    int len_;
    int head_;
    int tail_;
    int size_;

   public:
    MyCircularQueue(int k) : len_(k), head_(0), tail_(0), size_(0) {
        data_.resize(len_);
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        data_[tail_] = value;
        tail_ = (tail_ + 1) % len_;
        ++size_;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        head_ = (head_ + 1) % len_;
        --size_;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data_[head_];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        int ind = tail_ - 1;
        if (ind < 0) {
            ind = len_ - 1;
        }
        return data_[ind];
    }

    bool isEmpty() { return size_ == 0; }

    bool isFull() { return size_ == len_; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
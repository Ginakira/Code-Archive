// LeetCode 1670 设计前中后队列

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class FrontMiddleBackQueue {
   private:
    std::deque<int> first_half_;
    std::deque<int> second_half_;

    void balance() {
        if (first_half_.size() > second_half_.size()) {
            second_half_.push_front(first_half_.back());
            first_half_.pop_back();
        } else if (second_half_.size() > first_half_.size() + 1) {
            first_half_.push_back(second_half_.front());
            second_half_.pop_front();
        }
    }

   public:
    FrontMiddleBackQueue() {}

    void pushFront(int val) {
        first_half_.push_front(val);
        balance();
    }

    void pushMiddle(int val) {
        if (first_half_.size() < second_half_.size()) {
            first_half_.push_back(val);
        } else {
            second_half_.push_front(val);
        }
    }

    void pushBack(int val) {
        second_half_.push_back(val);
        balance();
    }

    int popFront() {
        if (second_half_.empty()) {
            return -1;
        }
        int ret = -1;
        if (first_half_.empty()) {
            ret = second_half_.front();
            second_half_.pop_front();
        } else {
            ret = first_half_.front();
            first_half_.pop_front();
        }
        balance();
        return ret;
    }

    int popMiddle() {
        if (second_half_.empty()) {
            return -1;
        }
        int ret = -1;
        if (first_half_.size() == second_half_.size()) {
            ret = first_half_.back();
            first_half_.pop_back();
        } else {
            ret = second_half_.front();
            second_half_.pop_front();
        }
        balance();
        return ret;
    }

    int popBack() {
        if (second_half_.empty()) {
            return -1;
        }
        int ret = second_half_.back();
        second_half_.pop_back();
        balance();
        return ret;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
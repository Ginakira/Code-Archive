// 剑指 Offer II 041. 滑动窗口的平均值

#include <algorithm>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class MovingAverage {
   private:
    int win_size_ = 0;
    int cur_sum_ = 0;
    vector<int> nums_;

   public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : win_size_(size), cur_sum_(0) {}

    double next(int val) {
        nums_.emplace_back(val);
        cur_sum_ += val;
        int n = nums_.size();
        if (win_size_ < n) {
            cur_sum_ -= nums_[n - win_size_ - 1];
        }
        return cur_sum_ * 1.0 / min(win_size_, n);
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

class MovingAverage2 {
   private:
    int win_size_ = 0;
    double cur_sum_ = 0;
    queue<int> nums_;

   public:
    /** Initialize your data structure here. */
    MovingAverage2(int size) : win_size_(size), cur_sum_(0) {}

    double next(int val) {
        if (nums_.size() == win_size_) {
            cur_sum_ -= nums_.front();
            nums_.pop();
        }
        cur_sum_ += val;
        nums_.emplace(val);
        return cur_sum_ / nums_.size();
    }
};
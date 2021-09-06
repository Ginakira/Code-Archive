// 剑指 Offer 41. 数据流中的中位数

#include <algorithm>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class MedianFinder {
   private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> big;

   public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        if (small.empty() || num <= small.top()) {
            small.push(num);
        } else {
            big.push(num);
        }

        if (small.size() + 2 == big.size()) {
            small.push(big.top());
            big.pop();
        }
        if (big.size() + 2 == small.size()) {
            big.push(small.top());
            small.pop();
        }
    }

    double findMedian() {
        double a = small.empty() ? 0 : small.top();
        double b = big.empty() ? 0 : big.top();
        if (small.size() == big.size()) {
            return (a + b) / 2.0;
        }
        return small.size() > big.size() ? a : b;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
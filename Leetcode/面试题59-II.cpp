// 队列的最大值
#include <deque>
using namespace std;

// 使用双端队列 144ms
class MaxQueue {
   private:
    deque<int> dq;

   public:
    MaxQueue() {}

    int max_value() {
        int max = -1;
        for (int i : dq) {
            max = i > max ? i : max;
        }
        return max;
    }

    void push_back(int value) { dq.push_back(value); }

    int pop_front() {
        if (dq.empty()) return -1;
        int ret = dq.front();
        dq.pop_front();
        return ret;
    }
};
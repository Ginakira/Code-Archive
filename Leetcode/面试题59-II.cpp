// 队列的最大值
#include <deque>
#include <queue>
using namespace std;

// 使用双端队列 最大值查询O(N) 144ms
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

// 队列+双端队列 与单调队列RMQ操作思想相仿 官方说均摊复杂度O(1)
// 但实际上没有第一种方法快 208ms
class MaxQueue2 {
   private:
    queue<int> q;
    deque<int> dq;

   public:
    MaxQueue2() {}

    int max_value() {
        if (dq.empty()) return -1;
        return dq.front();
    }

    void push_back(int value) {
        q.push(value);
        while (!dq.empty() && value >= dq.back()) dq.pop_back();
        dq.push_back(value);
        return;
    }

    int pop_front() {
        if (q.empty()) return -1;
        int ret = q.front();
        if (dq.front() == ret) dq.pop_front();
        q.pop();
        return ret;
    }
};
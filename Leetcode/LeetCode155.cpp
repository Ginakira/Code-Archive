// LeetCode 155 最小栈

#include <algorithm>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 辅助栈
// 辅助栈存储的是数据栈每个位置对应的当前的最小值
class MinStack {
   private:
    stack<int> stk;
    stack<int> min_stk;

   public:
    /** initialize your data structure here. */
    MinStack() { min_stk.push(INT_MAX); }

    void push(int val) {
        stk.push(val);
        min_stk.push(min(min_stk.top(), val));
    }

    void pop() {
        stk.pop();
        min_stk.pop();
    }

    int top() { return stk.top(); }

    int getMin() { return min_stk.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
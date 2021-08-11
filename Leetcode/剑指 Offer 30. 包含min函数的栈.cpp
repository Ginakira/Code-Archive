// 剑指 Offer 30. 包含min函数的栈

#include <algorithm>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class MinStack {
   private:
    stack<int> stk;
    stack<int> min_stk;

   public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        stk.push(x);
        if (min_stk.empty() || x <= min_stk.top()) {
            min_stk.push(x);
        }
    }

    void pop() {
        if (stk.top() == min_stk.top()) {
            min_stk.pop();
        }
        stk.pop();
    }

    int top() { return stk.top(); }

    int min() { return min_stk.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
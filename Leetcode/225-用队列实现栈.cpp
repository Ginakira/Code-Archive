#include <queue>
using namespace std;

//仅使用一个队列 在队列中使用栈的方式存储
//也就是队首始终是栈顶 插入一个元素就将其前面所有的元素全部移到后面
class MyStack {
   public:
    queue<int> q;
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
        return;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret = q.front();
        q.pop();
        return ret;
    }

    /** Get the top element. */
    int top() { return q.front(); }

    /** Returns whether the stack is empty. */
    bool empty() { return q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
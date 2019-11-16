#include <queue>
using namespace std;

class MyStack {
   public:
    queue<int> *q;
    /** Initialize your data structure here. */
    MyStack() { q = new queue<int>; }

    /** Push element x onto stack. */
    void push(int x) { q->push(x); }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> tmp;
        int cnt = q->size() - 1, val;
        for (int i = 0; i < cnt; ++i) {
            tmp.push(q->front());
            q->pop();
        }
        val = q->front();
        q->pop();
        while (!tmp.empty()) {
            q->push(tmp.front());
            tmp.pop();
        }
        return val;
    }

    /** Get the top element. */
    int top() {
        queue<int> tmp;
        int cnt = q->size() - 1, val;
        for (int i = 0; i < cnt; ++i) {
            tmp.push(q->front());
            q->pop();
        }
        val = q->front();
        tmp.push(q->front());
        q->pop();
        while (!tmp.empty()) {
            q->push(tmp.front());
            tmp.pop();
        }
        return val;
    }

    /** Returns whether the stack is empty. */
    bool empty() { return q->empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
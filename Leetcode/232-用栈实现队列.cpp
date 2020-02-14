#include <stack>
using namespace std;

//法1 O(n)复杂度 在栈中按照队列方式存储
class MyQueue {
   public:
    stack<int> s1, s2;
    int front;
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) {
        if (s1.empty()) front = x;
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return;
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        s1.pop();
        int ret = front;
        if (!s1.empty()) front = s1.top();
        return ret;
    }

    /** Get the front element. */
    int peek() { return front; }

    /** Returns whether the queue is empty. */
    bool empty() { return s1.empty(); }
};

//法2 摊还时间复杂度O(1) 两个栈分别存储
class MyQueue2 {
   public:
    stack<int> s1, s2;
    int front;
    /** Initialize your data structure here. */
    MyQueue2() {}

    /** Push element x to the back of queue. */
    void push(int x) {
        if (s1.empty()) front = x;
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int ret = s2.top();
        s2.pop();
        return ret;
    }

    /** Get the front element. */
    int peek() {
        if (s2.empty()) return front;
        return s2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() { return s1.empty() && s2.empty(); }
};
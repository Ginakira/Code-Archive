#include <stack>
using namespace std;

//法1 O(n)复杂度 在栈中按照队列方式存储
class MyQueue1 {
   public:
    stack<int> s1, s2;
    int front;
    /** Initialize your data structure here. */
    MyQueue1() {}

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

// C语言版
typedef struct MyStack {
    int *data;
    int top;
} MyStack;

MyStack *myStackCreate(int size) {
    MyStack *s = (MyStack *)malloc(sizeof(MyStack));
    s->data = (int *)malloc(sizeof(int) * size);
    s->top = -1;
    return s;
}

void myStackPush(MyStack *obj, int x) { obj->data[++(obj->top)] = x; }

int myStackPop(MyStack *obj) { return obj->data[(obj->top)--]; }

int myStackTop(MyStack *obj) { return obj->data[obj->top]; }

int myStackEmpty(MyStack *obj) { return obj->top == -1; }

void myStackFree(MyStack *obj) {
    if (!obj) return;
    free(obj->data);
    free(obj);
    return;
}

typedef struct {
    MyStack *s1, *s2;
} MyQueue;

/** Initialize your data structure here. */

MyQueue *myQueueCreate() {
    int size = 1024;
    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
    q->s1 = myStackCreate(size);
    q->s2 = myStackCreate(size);
    return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue *obj, int x) { myStackPush(obj->s1, x); }

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue *obj) {
    if (myStackEmpty(obj->s2)) {
        while (!myStackEmpty(obj->s1)) {
            myStackPush(obj->s2, myStackPop(obj->s1));
        }
    }
    return myStackPop(obj->s2);
}

/** Get the front element. */
int myQueuePeek(MyQueue *obj) {
    if (myStackEmpty(obj->s2)) {
        while (!myStackEmpty(obj->s1)) {
            myStackPush(obj->s2, myStackPop(obj->s1));
        }
    }
    return myStackTop(obj->s2);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue *obj) {
    return myStackEmpty(obj->s1) && myStackEmpty(obj->s2);
}

void myQueueFree(MyQueue *obj) {
    if (!obj) return;
    myStackFree(obj->s1);
    myStackFree(obj->s2);
    free(obj);
    return;
}
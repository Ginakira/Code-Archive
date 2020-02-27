#include <queue>
using namespace std;

//仅使用一个队列 在队列中使用栈的方式存储
//也就是队首始终是栈顶 插入一个元素就将其前面所有的元素全部移到后面
class MyStack1 {
   public:
    queue<int> q;
    /** Initialize your data structure here. */
    MyStack1() {}

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

// C语言版
typedef struct MyQueue {
    int *data;
    int head, tail, size, cnt;
} MyQueue;

MyQueue *myQueueCreate(int size) {
    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
    q->data = (int *)malloc(sizeof(int) * size);
    q->head = q->tail = q->cnt = 0;
    q->size = size;
    return q;
}

void myQueuePush(MyQueue *obj, int x) {
    if (!obj) return;
    if (obj->cnt == obj->size) return;
    obj->data[obj->tail++] = x;
    if (obj->tail == obj->size) obj->tail -= obj->size;
    obj->cnt++;
    return;
}

int myQueuePop(MyQueue *obj) {
    if (!obj) return 0;
    if (obj->cnt == 0) return 0;
    obj->head++;
    if (obj->head == obj->size) obj->head -= obj->size;
    obj->cnt--;
    return 1;
}

int myQueueFront(MyQueue *obj) { return obj->data[obj->head]; }

int myQueueEmpty(MyQueue *obj) { return obj->cnt == 0; }

void myQueueFree(MyQueue *obj) {
    if (!obj) return;
    free(obj->data);
    free(obj);
    return;
}

typedef struct {
    MyQueue *q1, *q2;
} MyStack;

/** Initialize your data structure here. */

MyStack *myStackCreate() {
    int size = 1024;
    MyStack *s = (MyStack *)malloc(sizeof(MyStack));
    s->q1 = myQueueCreate(size);
    s->q2 = myQueueCreate(size);
    return s;
}

/** Push element x onto stack. */
void myStackPush(MyStack *obj, int x) {
    if (!myQueueEmpty(obj->q1)) {
        myQueuePush(obj->q1, x);
    } else {
        myQueuePush(obj->q2, x);
    }
    return;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack *obj) {
    MyQueue *p = myQueueEmpty(obj->q1) ? obj->q2 : obj->q1;
    MyQueue *q = myQueueEmpty(obj->q1) ? obj->q1 : obj->q2;
    int element = myQueueFront(p);
    myQueuePop(p);
    while (!myQueueEmpty(p)) {
        myQueuePush(q, element);
        element = myQueueFront(p);
        myQueuePop(p);
    }
    return element;
}

/** Get the top element. */
int myStackTop(MyStack *obj) {
    MyQueue *p = myQueueEmpty(obj->q1) ? obj->q2 : obj->q1;
    MyQueue *q = myQueueEmpty(obj->q1) ? obj->q1 : obj->q2;
    int element;
    while (!myQueueEmpty(p)) {
        element = myQueueFront(p);
        myQueuePop(p);
        myQueuePush(q, element);
    }
    return element;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack *obj) {
    return myQueueEmpty(obj->q1) && myQueueEmpty(obj->q2);
}

void myStackFree(MyStack *obj) {
    if (!obj) return;
    myQueueFree(obj->q1);
    myQueueFree(obj->q2);
    free(obj);
    return;
}
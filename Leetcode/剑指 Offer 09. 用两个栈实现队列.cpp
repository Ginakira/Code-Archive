// 剑指Offer 09. 用两个栈实现队列
#include <stack>

class CQueue {
   private:
    std::stack<int> instk;
    std::stack<int> outstk;

   public:
    CQueue() {}

    void appendTail(int value) { instk.push(value); }

    int deleteHead() {
        if (outstk.empty()) {
            generate_outstk();
        }
        if (outstk.empty()) return -1;
        int ret = outstk.top();
        outstk.pop();
        return ret;
    }

    void generate_outstk() {
        while (!instk.empty()) {
            outstk.push(instk.top());
            instk.pop();
        }
        return;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
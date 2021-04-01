// LeetCode 1006 笨阶乘
#include <stack>
using namespace std;

class Solution {
   public:
    int clumsy(int N) {
        stack<int> stk;
        stk.push(N);

        int current = 0;
        for (int i = N - 1; i > 0; --i) {
            switch (current % 4) {
                case 0: {
                    stk.top() *= i;
                } break;
                case 1: {
                    stk.top() /= i;
                } break;
                case 2: {
                    stk.push(i);
                } break;
                case 3: {
                    stk.push(-i);
                } break;
            }
            ++current;
        }

        int ret = 0;
        while (!stk.empty()) {
            ret += stk.top();
            stk.pop();
        }
        return ret;
    }
};
// LeetCode 946 验证栈序列

#include <algorithm>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> stk;
        int pop_ind = 0;
        for (int num : pushed) {
            stk.push(num);
            while (!stk.empty() && stk.top() == popped[pop_ind] &&
                   pop_ind < n) {
                stk.pop();
                ++pop_ind;
            }
        }
        return pop_ind == n;
    }
};
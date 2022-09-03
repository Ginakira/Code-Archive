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
        stack<int> stk;
        int pop_ind = 0, pop_n = popped.size();
        for (int num : pushed) {
            stk.push(num);
            while (pop_ind < pop_n && !stk.empty() &&
                   stk.top() == popped[pop_ind]) {
                stk.pop();
                ++pop_ind;
            }
        }
        return pop_ind == pop_n;
    }
};
// 剑指 Offer 31. 栈的压入、弹出序列

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
        int ind = 0;
        for (int num : pushed) {
            stk.push(num);
            while (!stk.empty() && ind < n && popped[ind] == stk.top()) {
                stk.pop();
                ++ind;
            }
        }
        return ind == n;
    }
};
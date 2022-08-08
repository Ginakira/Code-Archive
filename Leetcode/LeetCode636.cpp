// LeetCOde 636 函数的独占时间

#include <algorithm>
#include <numeric>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<tuple<int, int>> stk;
        vector<int> ans(n, 0);
        for (auto& log : logs) {
            int function_id = 0, timestamp = 0;
            char type[6];
            sscanf(log.c_str(), "%d:%[^:]:%d", &function_id, type, &timestamp);
            if (type[0] == 's') {
                if (!stk.empty()) {
                    ans[get<0>(stk.top())] += timestamp - get<1>(stk.top());
                    get<1>(stk.top()) = timestamp;
                }
                stk.emplace(function_id, timestamp);
            } else {
                auto [last_func, last_stmp] = stk.top();
                stk.pop();
                ans[last_func] += timestamp - last_stmp + 1;
                if (!stk.empty()) {
                    get<1>(stk.top()) = timestamp + 1;
                }
            }
        }
        return ans;
    }
};
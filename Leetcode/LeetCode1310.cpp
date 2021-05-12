// LeetCode 1310 子数组异或查询
#include <vector>
using namespace std;

// 前缀和思路
class Solution {
   public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> pre(n + 1);
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] ^ arr[i - 1];
        }
        vector<int> result;
        for (auto& qurey : queries) {
            result.emplace_back(pre[qurey[1] + 1] ^ pre[qurey[0]]);
        }
        return result;
    }
};
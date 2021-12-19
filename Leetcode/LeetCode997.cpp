// LeetCode 997 找到小镇的法官

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in_deg(n), out_deg(n);
        for (auto t : trust) {
            ++in_deg[t[1] - 1];
            ++out_deg[t[0] - 1];
        }

        for (int i = 0; i < n; ++i) {
            if (in_deg[i] == n - 1 && out_deg[i] == 0) {
                return i + 1;
            }
        }
        return -1;
    }
};
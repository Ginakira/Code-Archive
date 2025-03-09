// LeetCode 2269 找到一个数字的K美丽值

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int divisorSubstrings(int num, int k) {
        int ans = 0;
        string s = to_string(num);
        int n = s.size();
        for (int i = 0; i <= n - k; ++i) {
            int cur = stoi(s.substr(i, k));
            if (cur && num % cur == 0) {
                ++ans;
            }
        }
        return ans;
    }
};
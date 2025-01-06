// LeetCode 3019 按键变更的次数

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
    int countKeyChanges(string s) {
        int n = s.size();
        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (tolower(s[i - 1]) != tolower(s[i])) {
                ++cnt;
            }
        }
        return cnt;
    }
};
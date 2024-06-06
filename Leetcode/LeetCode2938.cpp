// LeetCode 2938 区分黑球与白球

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
    long long minimumSteps(string s) {
        long long ans = 0;
        int zero_cnt = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                ++zero_cnt;
            } else {
                ans += zero_cnt;
            }
        }
        return ans;
    }
};
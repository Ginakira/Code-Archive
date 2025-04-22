// LeetCode 1399 统计最大组的数目

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
    int countLargestGroup(int n) {
        auto sum = [](int num) {
            int res = 0;
            while (num) {
                res += num % 10;
                num /= 10;
            }
            return res;
        };
        int max_cnt = 0, ans = 0;
        unordered_map<int, int> mark;
        for (int i = 1; i <= n; ++i) {
            int cnt = ++mark[sum(i)];
            if (cnt > max_cnt) {
                max_cnt = cnt;
                ans = 1;
            } else if (cnt == max_cnt) {
                ++ans;
            }
        }
        return ans;
    }
};
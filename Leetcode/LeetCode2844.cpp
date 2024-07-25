// LeetCode 2844 生成特殊数字的最少操作

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
    int minimumOperations(string num) {
        int n = num.size();
        int ans =
            ranges::any_of(num, [](int n) { return n == '0'; }) ? n - 1 : n;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int sum = 10 * (num[i] - '0') + num[j] - '0';
                if (sum == 0 || sum == 25 || sum == 50 || sum == 75) {
                    ans = min(ans, n - i - 2);
                }
            }
        }
        return ans;
    }
};

class Solution2 {
   public:
    int minimumOperations(string num) {
        int n = num.size();
        bool find0 = false, find5 = false;
        for (int i = n - 1; i >= 0; --i) {
            char ch = num[i];
            if (ch == '0' || ch == '5') {
                if (find0) {
                    return n - i - 2;
                }
                if (ch == '0') {
                    find0 = true;
                } else {
                    find5 = true;
                }
            } else if (ch == '2' || ch == '7') {
                if (find5) {
                    return n - i - 2;
                }
            }
        }
        return find0 ? n - 1 : n;
    }
};
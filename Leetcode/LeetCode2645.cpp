// LeetCOde 2645 构造有效字符串的最小插入数

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
    int addMinimum(string word) {
        int n = word.size();
        int cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (word[i] <= word[i - 1]) {
                ++cnt;
            }
        }
        return cnt * 3 - n;
    }
};
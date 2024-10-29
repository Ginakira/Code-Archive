// LeetCode 3216 交换后字典序最小的字符串

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
    string getSmallestString(string s) {
        int n = s.size();
        for (int i = 0, j = i + 1; j < n; ++i, ++j) {
            if (s[i] > s[j] && !((s[i] & 1) ^ (s[j] & 1))) {
                swap(s[i], s[j]);
                break;
            }
        }
        return s;
    }
};
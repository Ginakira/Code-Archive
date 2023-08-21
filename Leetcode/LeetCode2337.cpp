// LeetCode 2337 移动片段得到字符串

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
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;
        while (i < n && j < n) {
            while (i < n && start[i] == '_') {
                ++i;
            }
            while (j < n && target[j] == '_') {
                ++j;
            }
            if (i < n && j < n) {
                if (start[i] != target[j]) {
                    return false;
                }
                char ch = start[i];
                if ((ch == 'L' && i < j) || (ch == 'R' && i > j)) {
                    return false;
                }
                ++i;
                ++j;
            }
        }

        for (; i < n; ++i) {
            if (start[i] != '_') {
                return false;
            }
        }
        for (; j < n; ++j) {
            if (target[j] != '_') {
                return false;
            }
        }
        return true;
    }
};

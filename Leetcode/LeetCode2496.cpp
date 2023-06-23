// LeetCode 2496 数组种字符串的最大值

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
    int maximumValue(vector<string>& strs) {
        int ans = 0;
        for (const auto& str : strs) {
            bool is_number = true;
            for (char c : str) {
                if (isalpha(c)) {
                    is_number = false;
                    break;
                }
            }
            ans = max(ans, is_number ? stoi(str) : (int)str.size());
        }
        return ans;
    }
};
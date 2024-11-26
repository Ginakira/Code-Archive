// LeetCode 3206 交替组I

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
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int left = (i - 1 + n) % n;
            int right = (i + 1 + n) % n;
            if (colors[left] != colors[i] && colors[right] != colors[i]) {
                ++ans;
            }
        }
        return ans;
    }
};
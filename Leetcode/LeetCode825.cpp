// LeetCode 825 适龄的朋友

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
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        int ans = 0;
        ranges::sort(ages);
        for (int l = 0, r = 0; int age : ages) {
            if (age < 15) {
                continue;
            }
            while (ages[l] <= 0.5 * age + 7) {
                ++l;
            }
            while (r + 1 < n && ages[r + 1] <= age) {
                ++r;
            }
            ans += r - l;
        }
        return ans;
    }
};
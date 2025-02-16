// LeetCode 1287 有序数组中出现次数超过25%的元素

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
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int target = n / 4;
        unordered_map<int, int> cnt;
        for (int num : arr) {
            if (++cnt[num] > target) {
                return num;
            }
        }
        return -1;
    }
};

class Solution2 {
   public:
    int findSpecialInteger(vector<int>& arr) {
        int target = arr.size() / 4;
        int ans = arr[0], cnt = 0;
        for (int num : arr) {
            if (num == ans) {
                ++cnt;
                if (cnt > target) {
                    return ans;
                }
            } else {
                cnt = 1;
                ans = num;
            }
        }
        return ans;
    }
};
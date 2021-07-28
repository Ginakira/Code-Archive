// LeetCode 594 最长和谐子序列

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int findLHS(vector<int> &nums) {
        unordered_map<int, int> mp;
        for (const int &num : nums) {
            mp[num]++;
        }

        int max_len = 0;
        for (const int &num : nums) {
            if (mp.find(num + 1) != mp.end()) {
                max_len = max(mp[num] + mp[num + 1], max_len);
            }
        }
        return max_len;
    }
};

// 一趟遍历
class Solution2 {
   public:
    int findLHS(vector<int> &nums) {
        unordered_map<int, int> mp;

        int max_len = 0;
        for (const int &num : nums) {
            ++mp[num];
            if (mp.find(num - 1) != mp.end()) {
                max_len = max(mp[num] + mp[num - 1], max_len);
            }
            if (mp.find(num + 1) != mp.end()) {
                max_len = max(mp[num] + mp[num + 1], max_len);
            }
        }
        return max_len;
    }
};
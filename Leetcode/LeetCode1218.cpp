// LeetCode 1218  最长定差子序列

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> mp;
        int max_len = 0;
        ;
        for (int num : arr) {
            mp[num] = 1 + mp[num - difference];
            max_len = max(max_len, mp[num]);
        }
        return max_len;
    }
};
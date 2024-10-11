// LeetCode 3164 优质数对的总数 II

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
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0;
        unordered_map<int, int> cnt1, cnt2;
        int max1 = 0;
        for (int num : nums1) {
            ++cnt1[num];
            max1 = max(max1, num);
        }
        for (int num : nums2) {
            ++cnt2[num];
        }
        for (const auto& [num_j, cnt_j] : cnt2) {
            for (int j = num_j * k; j <= max1; j += num_j * k) {
                if (cnt1.count(j)) {
                    ans += 1L * cnt1[j] * cnt_j;
                }
            }
        }
        return ans;
    }
};
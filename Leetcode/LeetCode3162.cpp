// LeetCode 3162 优质数对的总数I

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
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int cnt = 0;
        for (int& num : nums2) {
            num *= k;
        }
        for (int num_i : nums1) {
            for (int num_j : nums2) {
                if (num_i % num_j == 0) {
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};

class Solution2 {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int ans = 0;
        unordered_map<int, int> cnt1, cnt2;
        int max1 = 0;
        for (int num : nums1) {
            ++cnt1[num];
            max1 = max(max1, num);
        }
        for (int num : nums2) {
            ++cnt2[num];
        }
        for (const auto &[num_j, cnt_j] : cnt2) {
            for (int j = num_j * k; j <= max1; j += num_j * k) {
                if (cnt1.count(j)) {
                    ans += cnt1[j] * cnt_j;  
                }
            }
        }
        return ans;
    }
};
// LeetCode 852 山脉数组的峰顶索引
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// O(n)方法 找最大值
class Solution {
   public:
    int peakIndexInMountainArray(vector<int>& arr) {
        return max_element(arr.begin(), arr.end()) - arr.begin();
    }
};

// O(log n) 二分
class Solution2 {
   public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1, mid, ans;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (arr[mid] > arr[mid + 1]) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
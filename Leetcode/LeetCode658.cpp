// LeetCode 658 找到K个最接近的元素

#include <algorithm>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int& num : arr) {
            int delta = num - x;
            if (pq.size() >= k && abs(pq.top()) > abs(delta)) {
                pq.pop();
                pq.push(delta);
            } else if (pq.size() < k) {
                pq.push(delta);
            }
        }
        vector<int> ans(k);
        for (int i = 0; i < k; ++i) {
            ans[i] = pq.top() + x;
            pq.pop();
        }
        return ans;
    }
};

class Solution2 {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [x](int a, int b) {
            return abs(a - x) < abs(b - x) ||
                   (abs(a - x) == abs(b - x) && a < b);
        });
        sort(arr.begin(), arr.begin() + k);
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};

class Solution3 {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = right - 1;
        while (k--) {
            if (left < 0) {
                ++right;
            } else if (right >= arr.size()) {
                --left;
            } else if (x - arr[left] > arr[right] - x) {
                ++right;
            } else {
                --left;
            }
        }
        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};
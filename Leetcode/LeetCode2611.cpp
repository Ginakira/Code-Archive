// LeetCode 2611 老鼠和奶酪

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
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; ++i) {
            ans += reward2[i];
            pq.emplace(reward1[i] - reward2[i]);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
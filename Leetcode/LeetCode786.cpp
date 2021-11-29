// LeetCode 786 第K个最小的素数分数

#include <algorithm>
#include <numeric>
#include <queue>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
        int n = arr.size();
        auto cmp = [&](const tuple<int, int> &a, const tuple<int, int> &b) {
            return arr[get<0>(a)] * arr[get<1>(b)] >
                   arr[get<1>(a)] * arr[get<0>(b)];
        };
        priority_queue<tuple<int, int>, vector<tuple<int, int>>, decltype(cmp)>
            pq(cmp);
        for (int j = 1; j < n; ++j) {
            pq.emplace(0, j);
        }
        for (int _ = 1; _ < k; ++_) {
            auto [a, b] = pq.top();
            pq.pop();
            pq.emplace(a + 1, b);
        }
        return {arr[get<0>(pq.top())], arr[get<1>(pq.top())]};
    }
};
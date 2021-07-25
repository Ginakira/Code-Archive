// LeetCode 347 前K个高频元素
#include <algorithm>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 排序
class Solution {
   public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> counter;
        for (const int &num : nums) {
            ++counter[num];
        }

        vector<pair<int, int>> counts;
        for (auto &[num, count] : counter) {
            counts.emplace_back(num, count);
        }
        sort(counts.begin(), counts.end(),
             [](auto &a, auto &b) { return a.second > b.second; });

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.emplace_back(counts[i].first);
        }
        return result;
    }
};

// 最小堆
class Solution2 {
   public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> counter;
        for (const int &num : nums) {
            ++counter[num];
        }

        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>
            pq(cmp);
        for (auto &[num, count] : counter) {
            if (pq.size() == k) {
                if (count > pq.top().second) {
                    pq.pop();
                    pq.emplace(num, count);
                }
            } else {
                pq.emplace(num, count);
            }
        }

        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};
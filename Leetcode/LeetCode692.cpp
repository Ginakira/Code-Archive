// LeetCode 692 前K个高频单词
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 哈希表 + 排序
class Solution {
   public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> freq;
        for (string &word : words) {
            ++freq[word];
        }

        vector<string> results;
        for (auto &[word, _] : freq) {
            results.emplace_back(word);
        }
        sort(results.begin(), results.end(), [&](auto &a, auto &b) {
            return freq[a] == freq[b] ? a < b : freq[a] > freq[b];
        });
        results.erase(results.begin() + k, results.end());
        return results;
    }
};

// 小根堆
class Solution2 {
   public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> freq;
        for (string &word : words) {
            ++freq[word];
        }
        auto cmp = [](const pair<string, int> &a, const pair<string, int> &b) {
            return a.second == b.second ? a.first < b.first
                                        : a.second > b.second;
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>,
                       decltype(cmp)>
            que(cmp);

        for (auto it : freq) {
            que.emplace(it);
            if (que.size() > k) {
                que.pop();
            }
        }
        vector<string> results(k);
        for (int i = k - 1; i >= 0; --i) {
            results[i] = que.top().first;
            que.pop();
        }
        return results;
    }
};
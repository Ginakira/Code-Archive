// LeetCode 692 前K个高频单词
#include <algorithm>
#include <map>
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
        vector<tuple<string, int>> items;
        vector<string> results;
        for (auto &[word, count] : freq) {
            items.emplace_back(word, count);
        }
        sort(items.begin(), items.end(), [](auto &a, auto &b) {
            return get<1>(a) == get<1>(b) ? get<0>(a) < get<0>(b)
                                          : get<1>(a) > get<1>(b);
        });
        for (int i = 0; i < k; ++i) {
            results.emplace_back(get<0>(items[i]));
        }
        return results;
    }
};
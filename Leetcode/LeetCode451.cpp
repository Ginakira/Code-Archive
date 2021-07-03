// LeetCode 451 根据字符出现频率排序
#include <algorithm>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 常规方法 哈希和排序
class Solution {
   public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            ++freq[c];
        }

        vector<tuple<char, int>> vec;
        for (auto &item : freq) {
            vec.emplace_back(item.first, item.second);
        }
        sort(vec.begin(), vec.end(),
             [](auto &a, auto &b) { return get<1>(a) > get<1>(b); });

        string result;
        for (auto &item : vec) {
            auto [c, count] = item;
            result += string(count, c);
        }

        return result;
    }
};
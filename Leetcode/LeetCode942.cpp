// LeetCode 942 增减字符串匹配

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> diStringMatch(string s) {
        size_t n = s.size();
        int left = 0, right = n;
        vector<int> results(n + 1, 0);
        for (size_t i = 0; i < n; ++i) {
            results[i] = (s[i] == 'I' ? left++ : right--);
        }
        results[n] = left;
        return results;
    }
};
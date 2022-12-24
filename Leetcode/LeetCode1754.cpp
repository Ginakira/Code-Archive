// LeetCode 1754 构造字典序最大的合并字符串

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string largestMerge(string word1, string word2) {
        string_view w1(word1), w2(word2);
        string ans;
        int n1 = word1.size(), n2 = word2.size();
        int p1 = 0, p2 = 0;
        ans.reserve(n1 + n2);
        while (p1 < n1 || p2 < n2) {
            if (w1.substr(p1) > w2.substr(p2)) {
                ans.push_back(w1[p1++]);
            } else {
                ans.push_back(w2[p2++]);
            }
        }
        return ans;
    }
};
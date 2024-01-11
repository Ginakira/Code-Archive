// LeetCode 2085 统计出现过一次的公共字符串

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
    int countWords(vector<string>& words1, vector<string>& words2) {
        auto make_mark = [](const vector<string>& words) {
            unordered_map<string, int> mark;
            for (auto& word : words) {
                ++mark[word];
            }
            return mark;
        };
        auto mark1 = make_mark(words1);
        auto mark2 = make_mark(words2);
        int ans = 0;
        for (auto& word : words1) {
            if (mark1[word] == 1 && mark2[word] == 1) {
                ++ans;
            }
        }
        return ans;
    }
};
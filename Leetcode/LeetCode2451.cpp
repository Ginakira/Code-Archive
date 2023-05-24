// LeetCode 2451 差值数组不同的字符串

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
   private:
    vector<int> GetWordDiff(const string& word) {
        int n = word.size();
        vector<int> diff(n - 1);
        for (int i = 1; i < n; ++i) {
            diff[i - 1] = word[i] - word[i - 1];
        }
        return diff;
    }

   public:
    string oddString(vector<string>& words) {
        int n = words.size();
        auto diff_0 = GetWordDiff(words[0]);
        auto diff_1 = GetWordDiff(words[1]);
        if (diff_0 == diff_1) {
            for (int i = 2; i < n; ++i) {
                auto diff = GetWordDiff(words[i]);
                if (diff != diff_0) {
                    return words[i];
                }
            }
        } else {
            auto diff_2 = GetWordDiff(words[2]);
            return diff_0 == diff_2 ? words[1] : words[0];
        }
        return "";
    }
};
// LeetCode 2586 统计范围内的元音字符串数

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
    constexpr bool is_vowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

   public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int cnt = 0;
        for (int i = left; i <= right; ++i) {
            const auto& word = words[i];
            if (is_vowel(word.front()) && is_vowel(word.back())) {
                ++cnt;
            }
        }
        return cnt;
    }
};
// LeetCode 2734 执行子串操作后的字典序最小字符串

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <ranges>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    string smallestString(string s) {
        int n = s.size();
        bool have_met = false;
        for (int start = -1; !have_met && start < n;) {
            int end = start + 1;
            while (end < n && s[end] != 'a') {
                have_met = true;
                --s[end++];
            }
            start = end;
        }
        if (!have_met) {
            s.back() = 'z';
        }
        return s;
    }
};

class Solution2 {
   public:
    string smallestString(string s) {
        if (ranges::all_of(s, [](char ch) { return ch == 'a'; })) {
            s.back() = 'z';
        } else {
            for (char& ch :
                 s | views::drop_while([](char ch) { return ch == 'a'; }) |
                     views::take_while([](char ch) { return ch != 'a'; })) {
                --ch;
            }
        }
        return s;
    }
};
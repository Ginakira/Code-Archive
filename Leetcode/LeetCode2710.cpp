// LeetCode 2710 移除字符串中的尾随零

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
    string removeTrailingZeros(string num) {
        auto res_view =
            num | ranges::views::reverse |
            ranges::views::drop_while([](char ch) { return ch == '0'; }) |
            ranges::views::reverse;
        return {res_view.begin(), res_view.end()};
    }
};

class Solution2 {
   public:
    string removeTrailingZeros(string num) {
        return num.substr(0, num.find_last_not_of('0') + 1);
    }
};
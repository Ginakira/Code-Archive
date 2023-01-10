// LeetCode 2283 判断一个数的数字计数是否等于数位的值

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <array>
using namespace std;

class Solution {
   public:
    bool digitCount(string num) {
        array<int, 10> cnt{0};
        std::for_each(num.begin(), num.end(),
                      [&](char ch) { ++cnt[ch - '0']; });
        int ind = 0;
        return std::all_of(num.begin(), num.end(), [&](int number) {
            return cnt[ind++] == number - '0';
        });
    }
};
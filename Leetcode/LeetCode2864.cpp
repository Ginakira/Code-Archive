// LeetCode 2864 最大二进制奇数

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
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int bit1_cnt = std::count(s.begin(), s.end(), '1');
        return string(bit1_cnt - 1, '1') + string(n - bit1_cnt, '0') + '1';
    }
};

// LeetCode 2566 替换一个数字后的最大差值

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
    int minMaxDifference(int num) {
        string big = std::to_string(num);
        string small = big;
        auto pos = big.find_first_not_of('9');
        if (pos != string::npos) {
            char c = big[pos];
            ranges::replace(big, c, '9');
        }
        char c = small[0];
        ranges::replace(small, c, '0');
        return stoi(big) - stoi(small);
    }
};
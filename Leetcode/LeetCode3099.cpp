// LeetCode 3099 哈沙德数

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
    int sumOfTheDigitsOfHarshadNumber(int x) {
        auto sx = std::to_string(x);
        int sum =
            std::accumulate(sx.begin(), sx.end(), 0,
                            [](int sum, char ch) { return sum + ch - '0'; });
        return x % sum == 0 ? sum : -1;
    }
};
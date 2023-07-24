// LeetCode 771 宝石与石头

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
    int numJewelsInStones(string jewels, string stones) {
        std::array<bool, 60> mark{{0}};
        for (auto ch : jewels) {
            mark[ch - 'A'] = true;
        }
        return count_if(stones.begin(), stones.end(),
                        [&mark](char ch) { return mark[ch - 'A']; });
    }
};
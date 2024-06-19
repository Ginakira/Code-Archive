// LeetCode 2748 美丽下标对的数目

#include <algorithm>
#include <array>
#include <cmath>
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
    int countBeautifulPairs(vector<int>& nums) {
        int res = 0;
        std::array<int, 10> cnt{{0}};
        for (int num : nums) {
            for (int j = 1; j <= 9; ++j) {
                if (gcd(num % 10, j) == 1) {
                    res += cnt[j];
                }
            }
            int first_dig =
                num / static_cast<int>(pow(10, static_cast<int>(log10(num))));
            ++cnt[first_dig];
        }
        return res;
    }
};
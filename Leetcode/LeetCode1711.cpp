// LeetCode 1711 大餐计数
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    static constexpr int MOD = 1e9 + 7;

   public:
    int countPairs(vector<int>& deliciousness) {
        int max_val =
            *max_element(deliciousness.begin(), deliciousness.end()) * 2;
        unordered_map<int, int> mp;
        int ans = 0;

        for (int& delicious : deliciousness) {
            for (int sum = 1; sum <= max_val; sum <<= 1) {
                if (mp.count(sum - delicious)) {
                    ans = (ans + mp[sum - delicious]) % MOD;
                }
            }
            ++mp[delicious];
        }

        return ans;
    }
};
// 每日一题 卡牌分组
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

// 使用ump计数去重 求所有次数最大公因数即可 途中如果小于2 则证明无效 28ms
class Solution {
   public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mp;
        for (int i : deck) {
            mp[i]++;
        }
        int num_x = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (!num_x) {
                num_x = it->second;
            }
            num_x = gcd(num_x, it->second);
            if (num_x < 2) return false;
        }
        return true;
    }
};
// LeetCode 1128 等价多米诺骨牌对的数量
#include <map>
#include <vector>
using namespace std;

// 哈希表版本 68ms 16.9MB
class Solution {
   private:
    typedef pair<int, int> PII;

   public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<PII, int> mp;
        int ans = 0;
        for (auto& domino : dominoes) {
            if (domino[0] > domino[1]) {
                swap(domino[0], domino[1]);
            }
            PII key(domino[0], domino[1]);
            if (mp.find(key) == mp.end()) {
                mp[key] = 1;
            } else {
                ans += mp[key];
                ++mp[key];
            }
        }
        return ans;
    }
};

// 数组 44ms 16.7MB
// 因为牌上的数都小于10，所以可以将其直接使用数字进行标记
// 标号为10x+y，x为较小数
class Solution2 {
   public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> mark(100);
        int ans = 0;
        for (const auto& domino : dominoes) {
            int key = domino[0] < domino[1] ? domino[0] * 10 + domino[1]
                                            : domino[1] * 10 + domino[0];
            ans += mark[key];
            ++mark[key];
        }
        return ans;
    }
};
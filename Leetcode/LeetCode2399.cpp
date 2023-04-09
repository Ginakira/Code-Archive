// LeetCode 2399 检查相同字母间的距离

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool checkDistances(string s, vector<int>& distance) {
        std::array<int, 26> mark{0};
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            int ch_ind = ch - 'a';
            if (mark[ch_ind] == 0) {
                mark[ch_ind] = i + 1;
            } else {
                int dis = i - mark[ch_ind];
                if (distance[ch_ind] != dis) {
                    return false;
                }
            }
        }
        return true;
    }
};
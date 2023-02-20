// LeetCode 2347 最好的扑克手牌

#include <algorithm>
#include <array>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        if (unordered_set<int>{suits.begin(), suits.end()}.size() == 1) {
            return "Flush";
        }
        array<int, 13> rank_mp{0};
        int max_same_rank = 0;
        for (auto& rank : ranks) {
            int& rank_cnt = rank_mp[rank - 1];
            ++rank_cnt;
            max_same_rank = max(max_same_rank, rank_cnt);
        }
        if (max_same_rank >= 3) {
            return "Three of a Kind";
        } else if (max_same_rank >= 2) {
            return "Pair";
        }
        return "High Card";
    }
};
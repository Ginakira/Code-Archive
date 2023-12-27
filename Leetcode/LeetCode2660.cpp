// LeetCode 2660 保龄球游戏的获胜者

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
    int isWinner(vector<int>& player1, vector<int>& player2) {
        auto cal_score = [](const vector<int>& player) {
            int score = 0;
            bool double_score = false;
            for (int i = 0; i < player.size(); ++i) {
                if ((i > 0 && player[i - 1] == 10) ||
                    (i > 1 && player[i - 2] == 10)) {
                    score += 2 * player[i];
                } else {
                    score += player[i];
                }
            }
            return score;
        };
        int score1 = cal_score(player1);
        int score2 = cal_score(player2);
        return score1 == score2 ? 0 : score1 > score2 ? 1 : 2;
    }
};
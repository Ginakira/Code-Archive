// LeetCode 1686 石子游戏VI

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <ranges>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<int> ids(n, 0);
        iota(ids.begin(), ids.end(), 0);
        ranges::sort(ids, [&](int i, int j) {
            return aliceValues[i] + bobValues[i] >
                   aliceValues[j] + bobValues[j];
        });
        int alice_score = 0, bob_score = 0;
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                bob_score += bobValues[ids[i]];
            } else {
                alice_score += aliceValues[ids[i]];
            }
        }
        if (alice_score == bob_score) {
            return 0;
        }
        return alice_score > bob_score ? 1 : -1;
    }
};
// LCP 40 心算挑战

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
    int maxmiumScore(vector<int>& cards, int cnt) {
        ranges::sort(cards, greater<int>());
        int score = 0;
        int odd = -1, even = -1;
        for (int i = 0; i < cnt; ++i) {
            score += cards[i];
            if (cards[i] & 1) {
                odd = cards[i];
            } else {
                even = cards[i];
            }
        }

        if (!(score & 1)) {
            return score;
        }

        int ans = 0;
        auto next_odd_it = find_if(cards.begin() + cnt, cards.end(),
                                   [](int num) { return num & 1; });
        auto next_even_it = find_if(cards.begin() + cnt, cards.end(),
                                    [](int num) { return !(num & 1); });
        int next_odd = next_odd_it != cards.end() ? *next_odd_it : -1;
        int next_even = next_even_it != cards.end() ? *next_even_it : -1;
        if (odd != -1 && next_even != -1) {
            ans = max(ans, score - odd + next_even);
        }
        if (even != -1 && next_odd != -1) {
            ans = max(ans, score - even + next_odd);
        }
        return ans;
    }
};
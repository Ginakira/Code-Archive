// LeetCode 433 最小基因变化

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> alternative(bank.begin(), bank.end());
        unordered_set<string> visited;
        array<char, 4> keys{'A', 'C', 'G', 'T'};
        queue<tuple<string, int>> q;

        if (start == end) {
            return 0;
        }
        if (alternative.count(end) == 0) {
            return -1;
        }

        q.emplace(start, 0);
        while (!q.empty()) {
            auto [cur, step] = q.front();
            q.pop();
            if (cur == end) {
                return step;
            }
            for (size_t i = 0; i < 8; ++i) {
                for (char c : keys) {
                    string next = cur;
                    next[i] = c;
                    if (!visited.count(next) && alternative.count(next)) {
                        q.emplace(next, step + 1);
                        visited.insert(next);
                    }
                }
            }
        }
        return -1;
    }
};
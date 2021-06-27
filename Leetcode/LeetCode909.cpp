// LeetCode 909 蛇梯棋
#include <algorithm>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

// BFS
class Solution {
   public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), target = n * n;

        auto id_to_index = [&](int id) -> tuple<int, int> {
            int x = (id - 1) / n, y = (id - 1) % n;
            if (x & 1) {
                y = n - y - 1;
            }
            return {n - 1 - x, y};
        };

        auto get_status = [&](int status) -> vector<int> {
            vector<int> ret;
            for (int i = 1; i <= 6; ++i) {
                int next = status + i;
                if (next > target) continue;
                auto [x, y] = id_to_index(next);
                if (board[x][y] != -1) {
                    ret.push_back(board[x][y]);
                } else {
                    ret.push_back(next);
                }
            }
            return ret;
        };

        unordered_set<int> seen;
        queue<tuple<int, int>> q;

        seen.insert(1);
        q.emplace(1, 0);

        while (!q.empty()) {
            auto [status, steps] = q.front();
            q.pop();

            for (auto&& new_status : get_status(status)) {
                if (seen.count(new_status)) {
                    continue;
                }
                if (new_status == target) {
                    return steps + 1;
                }
                q.emplace(new_status, steps + 1);
                seen.insert(new_status);
            }
        }

        return -1;
    }
};
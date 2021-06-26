// LeetCode 773 滑动谜题
#include <algorithm>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int slidingPuzzle(vector<vector<int>> &board) {
        // 对应位置相邻的位置
        vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5},
                                         {0, 4}, {1, 3, 5}, {2, 4}};
        // 获得可转移到的所有状态
        auto get_status = [&](string &status) -> vector<string> {
            vector<string> ret;
            int pos = status.find('0');
            for (auto neighbor : neighbors[pos]) {
                swap(status[pos], status[neighbor]);
                ret.emplace_back(status);
                swap(status[pos], status[neighbor]);
            }
            return ret;
        };

        // 将初始状态处理为字符串
        string initial;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                initial.push_back(char(board[i][j] + '0'));
            }
        }

        if (initial == "123450") {
            return 0;
        }

        unordered_set<string> seen{initial};
        queue<tuple<string, int>> q;
        q.emplace(initial, 0);

        while (!q.empty()) {
            auto [status, steps] = q.front();
            q.pop();
            for (auto &&new_status : get_status(status)) {
                if (seen.count(new_status)) {
                    continue;
                }
                if (new_status == "123450") {
                    return steps + 1;
                }
                q.emplace(new_status, steps + 1);
                seen.insert(new_status);
            }
        }
        return -1;
    }
};
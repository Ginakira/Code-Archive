// LeetCode 752 打开转盘锁
#include <algorithm>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

// 双向BFS
class Solution {
   public:
    int openLock(vector<string> &deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());

        if (target == "0000") {
            return 0;
        }

        if (dead.count("0000")) {
            return -1;
        }

        auto next_num = [](char x) { return x == '9' ? '0' : x + 1; };

        auto prev_num = [](char x) { return x == '0' ? '9' : x - 1; };

        auto get_status = [&](string &status) -> vector<string> {
            vector<string> ret;
            for (int i = 0; i < 4; ++i) {
                char x = status[i];
                status[i] = next_num(x);
                ret.emplace_back(status);
                status[i] = prev_num(x);
                ret.emplace_back(status);
                status[i] = x;
            }
            return ret;
        };

        queue<tuple<string, int>> q;
        unordered_set<string> seen;

        q.emplace("0000", 0);
        seen.insert("0000");

        while (!q.empty()) {
            auto [status, steps] = q.front();
            q.pop();
            for (const string &new_status : get_status(status)) {
                if (seen.count(new_status) || dead.count(new_status)) {
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
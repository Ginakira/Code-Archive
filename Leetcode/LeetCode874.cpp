// LeetCode 874 模拟行走机器人

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
   private:
    static constexpr int dirs[4][2]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    static constexpr int MAX_VAL = 60000;

    int CoordHash(int x, int y) { return x * MAX_VAL + y; }

   public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
        std::unordered_set<int> obstacle_st;
        for (auto &ob : obstacles) {
            obstacle_st.insert(CoordHash(ob[0], ob[1]));
        }

        int cur_dir = 0;
        int cur_x = 0, cur_y = 0;
        int ans = 0;
        for (auto &cmd : commands) {
            switch (cmd) {
                case -2: {
                    cur_dir = (cur_dir + 3) % 4;
                } break;
                case -1: {
                    cur_dir = (cur_dir + 1) % 4;
                } break;
                default: {
                    for (int i = 0; i < cmd; ++i) {
                        int next_x = cur_x + dirs[cur_dir][0];
                        int next_y = cur_y + dirs[cur_dir][1];
                        if (obstacle_st.count(CoordHash(next_x, next_y))) {
                            break;
                        }
                        cur_x = next_x, cur_y = next_y;
                    }
                    ans = max(ans, cur_x * cur_x + cur_y * cur_y);
                } break;
            }
        }

        return ans;
    }
};

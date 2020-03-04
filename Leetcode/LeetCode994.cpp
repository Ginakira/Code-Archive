// 腐烂的橘子
#include <queue>
#include <vector>
using namespace std;

// 使用BFS方法 每次将坏橘子入队 然后每次出队一个 使用方向数组使其周边橘子腐烂
// 如果在某个方向上存在新鲜橘子 则使其腐烂 然后入队 橘子代表的时间+1
// 最终遍历网格查看是否剩余新鲜橘子即可
class Solution {
   public:
    // 存储坏橘子队列中橘子的坐标以及发生腐烂的时间
    struct Orange {
        int i, j, time;
    };

    int orangesRotting(vector<vector<int>>& grid) {
        queue<Orange> q;
        int row = grid.size(), column = grid[0].size(), time = 0;
        int dir[4][2] = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}};  // 方向数组 上下左右探测
        for (int i = 0; i < row; ++i) {  // 先将最初的坏橘子入队
            for (int j = 0; j < column; ++j) {
                if (grid[i][j] == 2) q.push({i, j, time});
            }
        }
        Orange tmp;  // 存储每次取出的队首的坏橘子
        int cur_i, cur_j, di, dj;
        while (!q.empty()) {
            tmp = q.front(), q.pop();
            time = tmp.time, cur_i = tmp.i,
            cur_j = tmp.j;  // 取出的坏橘子的信息 time记录最后的坏橘子的对应时间
            for (int i = 0; i < 4; ++i) {  // 在四个方向上进行探测
                di = dir[i][0], dj = dir[i][1];  // 坐标变化量
                if (cur_i + di >= 0 && cur_i + di < row && cur_j + dj >= 0 &&
                    cur_j + dj < column && grid[cur_i + di][cur_j + dj] == 1) {
                    // 如果行走后的坐标合法且是新鲜橘子 则变坏
                    grid[cur_i + di][cur_j + dj] = 2;
                    q.push({cur_i + di, cur_j + dj, time + 1});
                }
            }
        }

        for (auto v : grid) {  // 最后遍历是否还存在新鲜橘子
            for (int i : v)
                if (i == 1) return -1;
        }

        return time;
    }
};
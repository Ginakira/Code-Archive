// LeetCode 733 图像渲染

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    const int dir[4][2]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> vis;

    void dfs(vector<vector<int>>& image, int x, int y, int old_color,
             int new_color) {
        if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size()) return;
        if (vis[x][y]) return;
        if (image[x][y] != old_color) return;

        image[x][y] = new_color;
        vis[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            dfs(image, x + dir[i][0], y + dir[i][1], old_color, new_color);
        }
    }

   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        vis.resize(image.size(), vector<int>(image[0].size(), false));
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};
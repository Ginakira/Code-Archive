// LeetCode 1138 字母板上的路径

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string alphabetBoardPath(string target) {
        string ans;
        int cur_x = 0, cur_y = 0;
        for (char ch : target) {
            int tar_x = (ch - 'a') / 5, tar_y = (ch - 'a') % 5;
            if (tar_x < cur_x) {
                ans.append(cur_x - tar_x, 'U');
            }
            if (tar_y < cur_y) {
                ans.append(cur_y - tar_y, 'L');
            }
            if (tar_x > cur_x) {
                ans.append(tar_x - cur_x, 'D');
            }
            if (tar_y > cur_y) {
                ans.append(tar_y - cur_y, 'R');
            }
            ans.append("!");
            cur_x = tar_x, cur_y = tar_y;
        }
        return ans;
    }
};
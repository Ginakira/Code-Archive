// LeetCode 75 颜色分类

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
    void sortColors(vector<int>& nums) {
        int red_cnt = 0, white_cnt = 0, blue_cnt = 0;
        for (int num : nums) {
            if (num == 0) {
                ++red_cnt;
            } else if (num == 1) {
                ++white_cnt;
            } else {
                ++blue_cnt;
            }
        }
        std::cout << red_cnt << ' ' << white_cnt << ' ' << blue_cnt
                  << std::endl;
        for (int& num : nums) {
            if (red_cnt-- > 0) {
                num = 0;
            } else if (white_cnt-- > 0) {
                num = 1;
            } else if (blue_cnt-- > 0) {
                num = 2;
            }
        }
    }
};
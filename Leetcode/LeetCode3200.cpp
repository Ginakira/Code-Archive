// LeetCode 3200 三角形的最大高度

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
    int maxHeightOfTriangle(int red, int blue) {
        auto try_build = [](int color_a, int color_b) {
            int height = 0;
            for (int i = 1;; ++i) {
                if (i & 1) {
                    if (color_a < i) {
                        break;
                    }
                    color_a -= i;
                } else {
                    if (color_b < i) {
                        break;
                    }
                    color_b -= i;
                }
                ++height;
            }
            return height;
        };
        return max(try_build(red, blue), try_build(blue, red));
    }
};
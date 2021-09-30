// LeetCode 223 矩形面积
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1,
                    int bx2, int by2) {
        int area_1 = (ax2 - ax1) * (ay2 - ay1),
            area_2 = (bx2 - bx1) * (by2 - by1);
        int cover_width = min(ax2, bx2) - max(ax1, bx1),
            cover_height = min(ay2, by2) - max(ay1, by1);
        int cover_area = max(0, cover_width) * max(0, cover_height);
        return area_1 + area_2 - cover_area;
    }
};
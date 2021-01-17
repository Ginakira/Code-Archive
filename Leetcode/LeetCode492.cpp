// LeetCode 492 构造矩形
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> constructRectangle(int area) {
        int w = floor(sqrt(area));
        while (w > 0) {
            if (area % w == 0) {
                return vector<int>{area / w, w};
            }
            --w;
        }
        return {};
    }
};
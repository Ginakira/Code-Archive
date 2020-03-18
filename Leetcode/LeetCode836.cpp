// 每日一题 矩形重叠
#include <vector>
using namespace std;

// 其中一个矩形的最左边肯定大于等于另一个的最右边
// 即为vec1[0] >= vec2[2] || vec2[0] >= vec1[2]
// 或其中一个矩形的最下边肯定大于等于另一个的最上边
// 即为vec1[1] >= vec2[3] || vec2[1] >= vec2[3]
// 结果为是否重叠 则
// !(vec1[0]>=vec2[2]||vec2[0]>=vec1[2]||vec1[1]>=vec2[3]||vec2[1]>=vec2[3])
// 德摩根律展开即可
class Solution {
   public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return (rec1[0] < rec2[2] && rec1[1] < rec2[3] && rec1[2] > rec2[0] &&
                rec1[3] > rec2[1]);
    }
};
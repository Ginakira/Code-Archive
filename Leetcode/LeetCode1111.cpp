// 每日一题 有效括号的嵌套深度
#include <string>
#include <vector>
using namespace std;

// 因为给出的一定合法，所以记录当前括号的深度即可，再平均分配到A、B中
class Solution {
   public:
    vector<int> maxDepthAfterSplit(string seq) {
        int depth = 0;
        vector<int> ans;
        for (char c : seq) {
            if (c == '(')
                ++depth, ans.push_back(depth & 1);
            else
                ans.push_back(depth & 1), --depth;
        }
        return ans;
    }
};
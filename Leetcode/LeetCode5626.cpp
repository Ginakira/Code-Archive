// LeetCode 5626 字节跳动 第219场周赛 十-二进制数的最少数目
#include <string>
using namespace std;

// 题目是障眼法 只需要找字符串中最大的数字即为答案
// 因为当最大的数字构造完成时，比其小的位一定已经完成了构造
class Solution {
   public:
    int minPartitions(string n) {
        char ans;
        for (const char &c : n) {
            ans = max(ans, c);
        }
        return ans - '0';
    }
};
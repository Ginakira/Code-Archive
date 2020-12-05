// LeetCode 621 任务调度器
#include <algorithm>
#include <vector>
using namespace std;

// Solution 1:
// 使用桶思想，我们可以把一个桶看做是一轮任务
// 那么桶的个数，一定是出现最多次字母的次数 C
// 桶的容量，就是冷却时间 n + 1
// 只有最后一个桶可能是没有满的，所以最后一桶应特殊计算
// 这种情况总排队时间 = (C - 1) * (n + 1) + 最后一桶的任务数
// 第二种情况是前C - 1桶都被占满，则任务应该尽量安排在每个满的桶之后
// 此时执行任务所需时间等同于任务数
// 所以最终结果应在两种情况的结果中取最大值
class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        vector<int> freq(26);
        for (char c : tasks) ++freq[c - 'A'];
        sort(freq.rbegin(), freq.rend());
        int count = 1;
        while (count < freq.size() && freq[count] == freq[0]) count++;
        return max(len, (freq[0] - 1) * (n + 1) + count);
    }
};
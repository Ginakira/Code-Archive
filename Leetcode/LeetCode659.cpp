// LeetCode 659 分隔数组为连续子序列
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// Solution1: 哈希表 + 最小堆 800ms
// mp存储的是以数字key为结尾的子序列的所有长度的堆（小根堆）
// 每遇到一个数字x，如果存在mp[x - 1]，则将其加入到
// 以x - 1为结尾的子序列长度中最小的那一个长度中（因为要尽量满足都至少长度为3）
// 如果不存在以x - 1为结尾的子序列，则新建一个以x为结尾的子序列，长度为1
// 最终遍历所有的子序列长度，如果出现长度小于3的则无法分割，不满足题意
class Solution1 {
   public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        for (const int& num : nums) {
            if (mp.find(num) == mp.end()) {
                mp[num] = priority_queue<int, vector<int>, greater<int>>();
            }
            if (mp.find(num - 1) != mp.end()) {
                int prev_len = mp[num - 1].top();
                mp[num - 1].pop();
                if (mp[num - 1].empty()) {
                    mp.erase(num - 1);
                }
                mp[num].push(prev_len + 1);
            } else {
                mp[num].push(1);
            }
        }

        for (const auto& it : mp) {
            if (it.second.top() < 3) {
                return false;
            }
        }
        return true;
    }
};
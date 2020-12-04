// LeetCode 659 分隔数组为连续子序列
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// Solution1: 哈希表 + 最小堆 800ms
// mp存储的是以数字key为结尾的子序列的所有长度的堆（小根堆）
// 每遇到一个数字x，如果存在mp[x - 1]，则将其加入到
// 以x - 1为结尾的子序列长度中最小的那一个长度中（因为要尽量满足都至少长度为3）
// 则此时以x - 1为结尾的子序列减少了一个，以x为结尾的子序列增加了一个
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

// Solution 2: 哈希 + 贪心 300ms
// 对于一个数x，将其加入以x - 1为结尾的子序列，一定比其单独新建一个子序列更优
// cnt[i]存储原数组中数字i出现的次数，tail[i]存储以i为结尾的【符合题意的】连续子序列个数
// 对于cnt[i] > 0的每一个数字 i 分为三种情况：
// 1. tail[i - 1] > 0，即为存在以i -
// 1为结尾的符合题意的连续子序列，则将i加入到这个子序列中，则此时tail[i -
// 1]减一，tail[i]加一
// 2. tail[i - 1] <= 0，即不存在以i -
// 1为结尾的符合题意的连续子序列，则以i为开头，构造一个长度为3的连续子序列（满足题目的最低要求所以是长度为3），如果能构造（也就是cnt[i
// + 1]、cnt[i + 2]均大于0)，则tail[i + 2]加一，cnt各项减一
// 3.
// 前两个条件均不满足，说明这个数字无法加入到其他子序列，也不能以它为开头构造新的子序列，返回false
class Solution2 {
   public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> cnt, tail;
        for (auto& num : nums) {
            cnt[num]++;
        }

        for (auto& num : nums) {
            if (cnt[num] <= 0) continue;
            if (tail[num - 1] > 0) {
                --cnt[num];
                --tail[num - 1];
                ++tail[num];
            } else if (cnt[num + 1] > 0 && cnt[num + 2] > 0) {
                --cnt[num], --cnt[num + 1], --cnt[num + 2];
                ++tail[num + 2];
            } else {
                return false;
            }
        }

        return true;
    }
};
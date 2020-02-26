#include <unordered_map>
#include <vector>
using namespace std;

// 使用unordered_map记录第一个数组数字出现次数 遍历第二个数组 4ms
class Solution {
   public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mark;
        vector<int> ans;
        for (auto i : nums1) mark[i]++;
        for (auto i : nums2) {
            if (mark.count(i) && mark[i] > 0) {
                mark[i]--;
                ans.push_back(i);
            }
        }
        return ans;
    }
};
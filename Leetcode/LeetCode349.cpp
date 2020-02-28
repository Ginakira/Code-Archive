// 两个数组的交集
#include <unordered_set>
#include <vector>
using namespace std;

// 使用unordered_set 标记第一个数组出现数字 然后遍历第二个数组 8ms
class Solution {
   public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> mark;
        vector<int> ans;
        for (auto i : nums1) mark.insert(i);
        for (auto i : nums2) {
            if (mark.count(i)) {
                ans.push_back(i);
                mark.erase(i);
            }
        }
        return ans;
    };
};
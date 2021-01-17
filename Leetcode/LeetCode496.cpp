// LeetCode 496 下一个更大元素I
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

// 普通法-双层遍历 32ms 8MB
class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> ret(n1);
        for (int i = 0; i < n1; ++i) {
            int ind = 0;
            while (ind < n2 && nums2[ind] != nums1[i]) ++ind;
            for (ind = ind + 1; ind < n2; ++ind) {
                if (nums2[ind] > nums1[i]) {
                    ret[i] = nums2[ind];
                    break;
                }
            }
            if (ind == n2) ret[i] = -1;
        }
        return ret;
    }
};

// 单调栈+哈希表 8ms 8.7MB
// 先使用单调栈，将nums2每个元素的下一个最大元素都求出来存到哈希表中，最后遍历nums1从哈希表中获取答案
class Solution2 {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret(nums1.size());
        stack<int> stk;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums2.size(); ++i) {
            while (!stk.empty() && nums2[i] > stk.top()) {
                mp[stk.top()] = nums2[i];
                stk.pop();
            }
            stk.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); ++i) {
            ret[i] = mp.find(nums1[i]) != mp.end() ? mp[nums1[i]] : -1;
        }

        return ret;
    }
};
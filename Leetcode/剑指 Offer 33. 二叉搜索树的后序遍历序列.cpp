// 剑指 Offer 33. 二叉搜索树的后序遍历序列

#include <vector>
using namespace std;

class Solution {
   public:
    bool helper(vector<int>& postorder, int start, int end) {
        if (start >= end) return true;
        int left_end = start;
        while (postorder[left_end] < postorder[end]) ++left_end;
        int right_end = left_end;
        while (postorder[right_end] > postorder[end]) ++right_end;
        return (right_end == end) && helper(postorder, start, left_end - 1) &&
               helper(postorder, left_end, right_end - 1);
    }
    bool verifyPostorder(vector<int>& postorder) {
        return helper(postorder, 0, postorder.size() - 1);
    }
};
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//解法1: 空间复杂度O(N) 或可以复制后使用双指针对比是否回文
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> nor, rev;
        for (auto p = head; p; p = p->next) {
            nor.push_back(p->val);
        }
        rev = nor;
        reverse(nor.begin(), nor.end());
        return nor == rev;
    }
};

//解法2: 递归 空间复杂度O(N)

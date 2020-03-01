// 回文链表
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 空间复杂度O(N)
class Solution {
   public:
    bool isPalindrome(ListNode *head) {
        vector<int> nor, rev;
        for (auto p = head; p; p = p->next) {
            nor.push_back(p->val);
        }
        rev = nor;
        reverse(nor.begin(), nor.end());
        return nor == rev;
    }
};
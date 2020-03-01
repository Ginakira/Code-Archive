// 二进制链表转整数

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 遍历的过程相当于二进制位不断左移并加上当前位
class Solution {
   public:
    int getDecimalValue(ListNode *head) {
        int ans = 0;
        ListNode *p = head;
        while (p) ans = (ans << 1) | p->val, p = p->next;
        return ans;
    }
};
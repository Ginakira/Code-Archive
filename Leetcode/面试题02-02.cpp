// 返回倒数第k个节点

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    int kthToLast(ListNode *head, int k) {
        ListNode *fast = head, *slow = head;
        while (k--) fast = fast->next;
        while (fast) slow = slow->next, fast = fast->next;
        return slow->val;
    }
};
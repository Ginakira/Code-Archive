// 链表中倒数第k个节点

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next() {}
};

// 经典快慢指针解法
class Solution {
   public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *slow = head, *fast = head;
        while (k--) fast = fast->next;
        while (fast) fast = fast->next, slow = slow->next;
        return slow;
    }
};
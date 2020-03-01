// 链表的中间节点

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next() {}
};

class Solution {
   public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
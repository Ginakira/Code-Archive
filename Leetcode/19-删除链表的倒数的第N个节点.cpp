struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0, length = 0;
        ListNode *p = head;
        while(p) {
            length++;
            p = p->next;
        }
        if(length == n) {
            ListNode *next_node = head->next, *delete_node = head;
            head = next_node;
            delete delete_node;
            return head;
        }
        p = head;
        while(count < length - n - 1) {
            p = p->next;
            count++;
        }
        ListNode *delete_node = p->next;
        p->next = delete_node->next;
        delete delete_node;
        return head;
    }
};
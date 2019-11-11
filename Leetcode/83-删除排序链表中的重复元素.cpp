struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        ListNode *pre = head, *current = head->next;
        while(current) {
            if(current->val == pre->val) {
                ListNode *delete_node = current;
                pre->next = current->next;
                current = pre->next;
                delete delete_node;
            } else {
                pre = current;
                current = current->next;
            }
        }
        return head;
    }
};
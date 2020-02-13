struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
   public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return nullptr;
        ListNode *pre = head, *current = head->next;
        while (current) {
            if (current->val == pre->val) {
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

// 2020-02-12 只使用一个指针 稍微简化
class Solution2 {
   public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *cur = head;
        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                ListNode *delete_node = cur->next;
                cur->next = delete_node->next;
                delete delete_node;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};
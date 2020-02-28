// 合并两个有序链表
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 双指针 12ms 17MB 使用新开链表的方式 边比较边生成新节点
class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(-1), *ans = head;
        ListNode *p = l1, *q = l2;
        while (p || q) {
            if (!q || (p && p->val < q->val)) {
                ans->next = new ListNode(p->val);
                p = p->next;
            } else {
                ans->next = new ListNode(q->val);
                q = q->next;
            }
            ans = ans->next;
        }
        return head->next;
    }
};

// 双指针 改变节点之间指向关系 8ms 16.8MB
class Solution2 {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode *pre = head, *p = l1, *q = l2;
        while (p || q) {
            if (!q || (p && p->val < q->val)) {
                pre->next = p;
                p = p->next;
            } else {
                pre->next = q;
                q = q->next;
            }
            pre = pre->next;
        }
        return head->next;
    }
};
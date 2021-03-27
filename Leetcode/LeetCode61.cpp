// LeetCode 61 旋转链表
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 成环断开法
class Solution {
   public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* iter = head;
        int len = 1;
        while (iter->next != nullptr) {
            iter = iter->next;
            ++len;
        }

        iter->next = head;
        for (int i = 0, n = len - (k % len); i < n; ++i) {
            iter = iter->next;
        }
        ListNode* ret = iter->next;
        iter->next = nullptr;
        return ret;
    }
};

// 快慢指针法
class Solution2 {
   public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        ListNode dummy(0, head);
        ListNode *d_head = &dummy, *p = d_head, *q = d_head;

        int len = 0;
        ListNode* tmp = head;
        while (tmp != nullptr) tmp = tmp->next, ++len;
        k %= len;

        while (k--) {
            q = q->next;
            if (q == nullptr) {
                q = head;
            }
        }
        while (q->next != nullptr) {
            p = p->next;
            q = q->next;
        }
        q->next = d_head->next;
        d_head->next = p->next;
        p->next = nullptr;
        return d_head->next;
    }
};
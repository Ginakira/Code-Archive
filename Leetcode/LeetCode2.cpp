// 两数相加
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 与大数加法同理 边加边构造新结点并记录进位 结束时判断是否有进位残余
class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(-1), *p = l1, *q = l2, *cur = &head;
        int carry = 0;
        while (p || q) {
            ListNode* node = new ListNode(carry);
            carry = 0;
            if (p) node->val += p->val, p = p->next;
            if (q) node->val += q->val, q = q->next;
            if (node->val >= 10) {
                carry = node->val / 10;
                node->val %= 10;
            }
            cur->next = node, cur = cur->next;
        }
        if (carry > 0) {
            cur->next = new ListNode(carry);
        }
        return head.next;
    }
};
class Solution2 {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;
        ListNode* p = new ListNode(0);
        ListNode* ans = p;
        while (p1 || p2) {
            if (p1) {
                p->val += p1->val;
            }
            if (p2) {
                p->val += p2->val;
            }
            int carry = p->val / 10;
            p->val %= 10;
            if (carry || (p1 && p1->next) || (p2 && p2->next)) {
                p->next = new ListNode(carry);
            }
            p1 = p1 ? p1->next : nullptr;
            p2 = p2 ? p2->next : nullptr;
            p = p->next;
        }
        return ans;
    }
};
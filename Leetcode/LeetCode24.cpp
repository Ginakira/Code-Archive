// 两两交换链表中的节点
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    ListNode *swapPairs(ListNode *head) {
        if (!head) return nullptr;
        int length = 0;
        ListNode *p = head;
        while (p) {
            length++;
            p = p->next;
        }
        p = head;
        ListNode *q = p->next, *k;
        for (int i = 0; i < length / 2; ++i) {
            p->next = q->next;
            q->next = p;
            if (i == 0)
                head = q;
            else
                k->next = q;
            k = p;
            p = p->next;
            if (p) q = p->next;
        }
        return head;
    }
};
// 2020-02-12 非递归解法 使用哑结点相对简短的做法
// 每次走到要交换的两个结点的前一个
class Solution2 {
   public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *dummy = new ListNode(0), *p = dummy;
        dummy->next = head;
        while (p->next && p->next->next) {
            ListNode *first = p->next, *second = first->next;
            first->next = second->next;
            second->next = first;
            p->next = second;
            if (p->next)
                p = p->next->next;
            else
                break;
        }
        return dummy->next;
    }
};

//递归解法 十分简洁 参数head为要交换结点的第一个结点
class Solution3 {
   public:
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *first = head, *second = head->next;
        first->next = swapPairs(second->next);
        second->next = first;
        return second;
    }
};
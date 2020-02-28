// 反转链表
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//解法1: 迭代 使用哑结点 & 头插法
class Solution1 {
   public:
    ListNode *reverseList(ListNode *head) {
        ListNode *yummy = new ListNode(0), *p = head;
        while (p) {
            ListNode *q = p->next;
            p->next = yummy->next;
            yummy->next = p;
            p = q;
        }
        return yummy->next;
    }
};

//解法2: 递归 将当前结点与后面已经反转好的整体进行反转
class Solution {
   public:
    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};
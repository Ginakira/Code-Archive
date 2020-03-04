// 反转链表 II

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 头插法的变形
class Solution {
   public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // front为插入的头 back为无需反转部分的头
        ListNode *dummy = new ListNode(-1), *front = dummy, *back = head;
        dummy->next = head;
        int times = n - m + 1;  // 要反转的节点个数
        while (--m) front = front->next;
        while (n--) back = back->next;
        ListNode *p = front->next, *q;
        front->next = back;  // 将无需反转的部分先连上
        while (times--) {    // 头插法
            q = p->next;
            p->next = front->next;
            front->next = p;
            p = q;
        }
        return dummy->next;
    }
};
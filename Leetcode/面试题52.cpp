// 两个链表的第一个公共节点

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next() {}
};

// 指针走到末尾后从另一个链表开始走 同160题
class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa = headA, *pb = headB;
        while (pa != pb) {
            pa = pa == nullptr ? headB : pa->next;
            pb = pb == nullptr ? headA : pb->next;
        }
        return pa;
    }
};
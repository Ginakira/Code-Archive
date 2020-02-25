struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next() {}
};

// 解法1:两趟遍历 先获取长度
class Solution1 {
   public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int count = 0, length = 0;
        ListNode *p = head;
        while (p) {
            length++;
            p = p->next;
        }
        if (length == n) {
            ListNode *next_node = head->next, *delete_node = head;
            head = next_node;
            delete delete_node;
            return head;
        }
        p = head;
        while (count < length - n - 1) {
            p = p->next;
            count++;
        }
        ListNode *delete_node = p->next;
        p->next = delete_node->next;
        delete delete_node;
        return head;
    }
};

//解法2:一趟遍历 双指针法 4ms
class Solution2 {
   public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *slow = dummy, *fast = dummy;
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *delNode = slow->next;
        slow->next = delNode->next;
        delete delNode;
        return dummy->next;
    }
};

// C语言版 0ms
#include <stdlib.h>
struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    struct ListNode ret(-1), *p, *q;
    ret.next = head;
    p = q = &ret;
    while (n--) q = q->next;
    q = q->next;
    while (q) p = p->next, q = q->next;
    q = p->next;
    p->next = q->next;
    free(q);
    return ret.next;
}
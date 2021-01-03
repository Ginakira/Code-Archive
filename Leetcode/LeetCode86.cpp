// LeetCode 86 分隔链表
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 找到第一个大于等于x的节点，然后后面比x小的节点都依次插入到该节点前
class Solution {
   public:
    ListNode *partition(ListNode *head, int x) {
        ListNode dummyNode{-1};
        dummyNode.next = head;
        ListNode *p = &dummyNode;
        while (p->next != nullptr && p->next->val < x) {
            p = p->next;
        }
        ListNode *q = p->next;
        while (q != nullptr && q->next != nullptr) {
            ListNode *temp;
            if (q->next->val < x) {
                temp = q->next->next;
                q->next->next = p->next;
                p->next = q->next;
                q->next = temp;
                p = p->next;
                continue;
            }
            q = q->next;
        }
        return dummyNode.next;
    }
};

// 分为两个链表，比x小的插入到小链表，大于等于x的插入到大链表
// 最后将两个链表合并起来，返回小链表头部即可
class Solution2 {
   public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *small = new ListNode(0), *large = new ListNode(0);
        ListNode *smallHead = small, *largeHead = large;
        while (head != nullptr) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        large->next = nullptr;
        small->next = largeHead->next;
        return smallHead->next;
    }
};
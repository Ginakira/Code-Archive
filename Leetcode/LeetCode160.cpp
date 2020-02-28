// 相交链表
#include <algorithm>
#include <set>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//解法1: 暴力法 遍历判等
class Solution1 {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        for (auto pa = headA; pa; pa = pa->next) {
            for (auto pb = headB; pb; pb = pb->next) {
                if (pa == pb) return pa;
            }
        }
        return nullptr;
    }
};

//解法2: 哈希表法 走一遍链表A记录进set，然后遍历表B查看是否有相同结点。
class Solution2 {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa = headA, *pb = headB;
        std::set<ListNode *> hash;
        while (pa) {
            hash.insert(pa);
            pa = pa->next;
        }
        while (pb) {
            if (hash.count(pb)) return pb;
            pb = pb->next;
        }
        return nullptr;
    }
};

//解法3: 双指针法 同时向后走 如果为空则重定位到另一个链表的头，如果相遇则相交
/*
A、B表长度可能不同，但A+B和B+A但长度一定是相同的，所以遍历A+B和遍历B+A一定是同时结束。
如果A,B相交的话A和B有一段尾巴是相同的，所以两个遍历的指针一定会同时到达交点。
如果A,B不相交的话两个指针就会同时到达A+B（B+A）的尾节点。
*/
class Solution3 {
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
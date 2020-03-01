// 移除重复节点
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 暴力 双重遍历判断 620ms
class Solution {
   public:
    ListNode *removeDuplicateNodes(ListNode *head) {
        if (!head) return nullptr;
        ListNode *p = head, *q;
        while (p->next) {
            q = p;
            while (q->next) {
                if (q->next->val == p->val) {
                    ListNode *dNode = q->next;
                    q->next = dNode->next;
                    delete dNode;
                } else {
                    q = q->next;
                }
            }
            if (p->next) p = p->next;
        }
        return head;
    }
};

// 使用哑结点 + 哈希去重
class Solution2 {
   public:
    ListNode *removeDuplicateNodes(ListNode *head) {
        if (!head) return nullptr;
        ListNode *p, *dummy = new ListNode(-1);
        dummy->next = head, p = dummy;
        unordered_set<int> s;
        while (p->next) {
            if (s.count(p->next->val)) {
                ListNode *dNode = p->next;
                p->next = dNode->next;
                delete dNode;
            } else {
                s.insert(p->next->val);
                p = p->next;
            }
        }
        return dummy->next;
    }
};
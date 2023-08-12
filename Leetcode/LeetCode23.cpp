// 合并K个排序链表
#include <queue>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

// 暴力法 使用优先队列遍历原链表同时入队 然后遍历队列生成新链表 32ms
class Solution {
   public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto head : lists) {
            ListNode *temp = head;
            while (temp) {
                q.push(temp->val);
                temp = temp->next;
            }
        }
        ListNode *ret = new ListNode(-1), *p = ret;
        while (!q.empty()) {
            ListNode *temp = new ListNode(q.top());
            p->next = temp;
            p = p->next;
            q.pop();
        }
        return ret->next;
    }
};

// 使用优先队列将节点入队 重载比较规则 所有头结点入队后构造链表 并将其next入队
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution2 {
   private:
    struct Status {
        int val;
        ListNode *ptr;
        bool operator<(const Status &rhs) const { return val > rhs.val; }
    };

   public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<Status> q;
        for (auto node : lists) {
            if (node != nullptr) {
                q.push({node->val, node});
            }
        }
        ListNode head, *current = &head;
        while (!q.empty()) {
            auto f = q.top();
            q.pop();
            current->next = f.ptr;
            current = current->next;
            if (f.ptr->next != nullptr) {
                q.push({f.ptr->next->val, f.ptr->next});
            }
        }
        return head.next;
    }
};

// 分治合并
class Solution3 {
   private:
    ListNode *mergeTwoList(ListNode *la, ListNode *lb) {
        ListNode node, *dummy = &node;
        ListNode *pa = la, *pb = lb, *p = dummy;
        while (pa || pb) {
            if (!pb || (pa && pa->val <= pb->val)) {
                p->next = pa;
                pa = pa->next;
            } else {
                p->next = pb;
                pb = pb->next;
            }
            p = p->next;
        }
        return dummy->next;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        if (start > end) {
            return nullptr;
        }
        int mid = start + (end - start) / 2;
        return mergeTwoList(mergeKLists(lists, start, mid),
                            mergeKLists(lists, mid + 1, end));
    }

   public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return mergeKLists(lists, 0, lists.size() - 1);
    }
};
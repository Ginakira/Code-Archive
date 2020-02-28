// 合并K个排序链表
#include <queue>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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
class Solution2 {
   public:
    struct cmp {
        bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return nullptr;
        priority_queue<ListNode *, vector<ListNode *>, cmp> q;
        ListNode *ret = new ListNode(-1), *p = ret;
        for (auto &i : lists) {
            if (i) q.push(i);
        }
        while (!q.empty()) {
            ListNode *tmp = q.top();
            p->next = tmp, p = p->next;
            if (tmp->next) q.push(tmp->next);
            q.pop();
        }
        return ret->next;
    }
};
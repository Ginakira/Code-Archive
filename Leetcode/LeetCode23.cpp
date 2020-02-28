// 合并K个排序链表
#include <queue>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 使用优先队列遍历原链表同时入队 然后遍历队列生成新链表 32ms
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
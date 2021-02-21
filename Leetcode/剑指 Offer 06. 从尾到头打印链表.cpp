// 剑指 Offer 06. 从尾到头打印链表
#include <stack>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// STL
class Solution {
   public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> ret;
        ListNode* p = head;
        while (p) {
            ret.emplace_back(p->val);
            p = p->next;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

// Stack
class Solution2 {
   public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> stk;
        vector<int> ret;
        ListNode* p = head;
        while (p != nullptr) {
            stk.push(p->val);
            p = p->next;
        }
        while (!stk.empty()) {
            ret.emplace_back(stk.top());
            stk.pop();
        }
        return ret;
    }
};
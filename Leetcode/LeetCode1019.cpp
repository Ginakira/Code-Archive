// LeetCode 1019 链表中的下一个更大节点

#include <algorithm>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<pair<int, int>> stk;
        int ind = 0;
        ListNode* p = head;
        while (p) {
            ans.emplace_back(0);
            while (!stk.empty() && stk.top().second < p->val) {
                ans[stk.top().first] = p->val;
                stk.pop();
            }
            stk.emplace(ind, p->val);
            ++ind;
            p = p->next;
        }
        return ans;
    }
};
// LeetCode 1171 从链表中删去总和值为零的连续节点

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode *removeZeroSumSublists(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        unordered_map<int, ListNode *> mp;
        int prefix = 0;
        for (ListNode *p = dummy; p; p = p->next) {
            prefix += p->val;
            mp[prefix] = p;
        }
        prefix = 0;
        for (ListNode *p = dummy; p; p = p->next) {
            prefix += p->val;
            p->next = mp[prefix]->next;
        }
        return dummy->next;
    }
};
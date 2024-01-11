// LeetCode 2807 在链表中插入最大公约数

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
    ListNode *insertGreatestCommonDivisors(ListNode *head) {
        ListNode *p = head;
        while (p && p->next) {
            ListNode *pn = p->next;
            ListNode *node = new ListNode(__gcd(p->val, pn->val));
            node->next = pn;
            p->next = node;
            p = pn;
        }
        return head;
    }
};
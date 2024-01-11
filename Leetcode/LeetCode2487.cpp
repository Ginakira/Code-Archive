// LeetCode 2487 从链表中移除节点

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
    ListNode *removeNodes(ListNode *head) {
        std::vector<ListNode *> nodes;
        ListNode *p = head;
        while (p) {
            nodes.emplace_back(p);
            p = p->next;
        }
        ListNode dummy;
        int pre = 0;
        for (auto it = nodes.rbegin(); it != nodes.rend(); ++it) {
            auto &node = *it;
            if (node->val >= pre) {
                pre = node->val;
                node->next = dummy.next;
                dummy.next = node;
            }
        }
        return dummy.next;
    }
};
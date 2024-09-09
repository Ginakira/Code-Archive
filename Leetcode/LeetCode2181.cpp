// LeetCode 2181 合并零之间的节点

#include <algorithm>
#include <array>
#include <memory>
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
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* mergeNodes(ListNode* head) {
        auto new_dummy = std::make_shared<ListNode>();
        ListNode* new_cur = new_dummy.get();
        ListNode* cur = head->next;
        int cur_sum = 0;
        while (cur) {
            cur_sum += cur->val;
            if (cur->val == 0) {
                new_cur->next = new ListNode(cur_sum);
                cur_sum = 0;
                new_cur = new_cur->next;
            }
            cur = cur->next;
        }
        return new_dummy->next;
    }
};
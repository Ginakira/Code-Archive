// LeetCode 2095 删除链表的中间节点

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
class Solution {
 public:
  ListNode* deleteMiddle(ListNode* head) {
    ListNode _dummy(0, head), *dummy = &_dummy;
    ListNode *fast = dummy, *slow = dummy, *pre = nullptr;
    while (fast && fast->next) {
      pre = slow;
      fast = fast->next->next;
      slow = slow->next;
    }
    if (fast) {
      slow->next = slow->next->next;
      // delete slow->next;
    } else {
      pre->next = slow->next;
      // delete slow;
    }
    return dummy->next;
  }
};
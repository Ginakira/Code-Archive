// LeetCode 2130 链表最大孪生和

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
  int pairSum(ListNode* head) {
    stack<int> nums;
    int max_sum = 0;
    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
      nums.push(slow->val);
      fast = fast->next->next;
      slow = slow->next;
    }
    while (slow) {
      max_sum = max(max_sum, slow->val + nums.top());
      nums.pop();
      slow = slow->next;
    }
    return max_sum;
  }
};
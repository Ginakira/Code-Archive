// LeetCode 3217 从链表中移除在数组中存在的节点

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
  ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    // std::unordered_set<int> us(nums.begin(), nums.end());
    std::array<int, 100001> mark{0};
    for (int num : nums) {
      mark[num] = 1;
    }
    ListNode _dummy{-1, head}, *dummy = &_dummy;
    ListNode* p = dummy;
    while (p->next) {
      ListNode* q = p->next;
      // if (us.count(q->val)) {
      if (mark[q->val]) {
        p->next = q->next;
      } else {
        p = q;
      }
    }
    return dummy->next;
  }
};
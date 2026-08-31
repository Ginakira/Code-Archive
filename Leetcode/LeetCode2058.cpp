// LeetCode 2058 找出临界点之间的最小和最大距离

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
  vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    int max_dis = -1, min_dis = -1;
    int pre_val = head->val;
    ListNode* p = head->next;
    int idx = 1, first_idx = -1, last_idx = -1;
    while (p && p->next) {
      if ((p->val < pre_val && p->val < p->next->val) ||
          (p->val > pre_val && p->val > p->next->val)) {
        if (first_idx == -1) {
          first_idx = idx;
        } else if (min_dis == -1 || idx - last_idx < min_dis) {
          min_dis = idx - last_idx;
        }
        last_idx = idx;
      }
      ++idx;
      pre_val = p->val;
      p = p->next;
    }
    max_dis = (first_idx == last_idx) ? -1 : last_idx - first_idx;

    return {min_dis, max_dis};
  }
};
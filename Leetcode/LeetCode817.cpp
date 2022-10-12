// LeetCode 817 链表组件

#include <algorithm>
#include <numeric>
#include <string>
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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> mark;
        for (int num : nums) {
            mark.emplace(num);
        }
        ListNode* p = head;
        bool in_set = false;
        int ans = 0;
        while (p != nullptr) {
            if (mark.count(p->val)) {
                if (!in_set) {
                    ++ans;
                }
                in_set = true;
            } else {
                in_set = false;
            }
            p = p->next;
        }
        return ans;
    }
};
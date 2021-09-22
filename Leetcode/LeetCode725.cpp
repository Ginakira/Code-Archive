// LeetCode 725 分隔链表

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
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
   private:
    int get_len(ListNode *head) {
        ListNode *cur = head;
        int count = 0;
        while (cur != nullptr) {
            ++count;
            cur = cur->next;
        }
        return count;
    }

   public:
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        int n = get_len(head);
        int target_count = n / k;
        vector<ListNode *> result(k);
        ListNode *cur = head;

        for (int i = 0; i < k; ++i) {
            ListNode *next_node = cur;
            int count = (i < n % k ? target_count : target_count - 1);
            for (int j = 0; j < count && next_node != nullptr; ++j) {
                next_node = next_node->next;
            }
            result[i] = cur;
            if (next_node != nullptr) {
                cur = next_node->next;
                next_node->next = nullptr;
            }
        }
        return result;
    }
};
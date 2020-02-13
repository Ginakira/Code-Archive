#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//解法1: 快慢指针法
class Solution {
   public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode *slow = head, *fast = head->next;
        while (slow != fast) {
            if (!fast || !fast->next) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

//解法2: 哈希表法（使用set）
//set.count(item)返回的是item在集合中出现的次数，只有0或1
class Solution2 {
   public:
    bool hasCycle(ListNode *head) {
        set<ListNode *> hash;
        ListNode *current = head;
        while (current) {
            if (hash.count(current)) return true;
            hash.insert(current);
            current = current->next;
        }
        return false;
    }
};
// LeetCOde 445 两数相加 II

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
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack<int> stk1, stk2;
        ListNode *p1 = l1, *p2 = l2;

        while (p1) {
            stk1.emplace(p1->val);
            p1 = p1->next;
        }
        while (p2) {
            stk2.emplace(p2->val);
            p2 = p2->next;
        }

        ListNode* p_ans = nullptr;
        int carry = 0;
        while (!stk1.empty() || !stk2.empty() || carry > 0) {
            int num1 = 0, num2 = 0;
            if (!stk1.empty()) {
                num1 = stk1.top();
                stk1.pop();
            }
            if (!stk2.empty()) {
                num2 = stk2.top();
                stk2.pop();
            }
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            sum %= 10;
            auto cur_node = new ListNode(sum, p_ans);
            p_ans = cur_node;
        }
        return p_ans;
    }
};

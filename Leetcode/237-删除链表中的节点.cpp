struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next() {}
};

//没有给head 很因吹斯汀
class Solution {
   public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
        return;
    }
};
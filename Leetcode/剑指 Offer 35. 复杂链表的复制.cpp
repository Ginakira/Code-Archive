// 剑指 Offer 35. 复杂链表的复制

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
   public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
   public:
    Node *copyRandomList(Node *head) {
        unordered_map<Node *, Node *> mp;
        mp[nullptr] = nullptr;

        Node *cur = head;
        while (cur != nullptr) {
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while (cur != nullptr) {
            mp[cur]->next = mp[cur->next];
            mp[cur]->random = mp[cur->random];
            cur = cur->next;
        }
        return mp[head];
    }
};
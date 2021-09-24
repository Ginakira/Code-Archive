// LeetCode 430 扁平化多级双向链表
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
    Node *prev;
    Node *next;
    Node *child;
};

class Solution {
   public:
    Node *flatten(Node *head) {
        Node *cur = head, *prev = nullptr;
        while (cur != nullptr) {
            if (prev != nullptr) {
                prev->next = cur;
            }
            cur->prev = prev;
            if (cur->child != nullptr) {
                Node *ori_next_node = cur->next;
                Node *flattened_node = flatten(cur->child);
                flattened_node->prev = cur;
                cur->next = flattened_node;
                cur->child = nullptr;

                // 跳转到末尾
                Node *temp = flattened_node;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                prev = temp;
                temp->next = ori_next_node;
                cur = ori_next_node;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
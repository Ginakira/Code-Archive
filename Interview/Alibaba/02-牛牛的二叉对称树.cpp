#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    Node() : val(-1), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    int val;
    Node *left, *right;
};

vector<int> pre_order, in_order, weight;

Node *build(int pre_start, int pre_end, int in_start, int in_end) {
    if (pre_start > pre_end || in_start > in_end) return nullptr;
    int root_elem = pre_order[pre_start];
    Node *root = new Node(root_elem);

    int root_index = 0;
    for (int i = in_start; i <= in_end; ++i) {
        if (in_order[i] == root_elem) {
            root_index = i;
            break;
        }
    }

    root->left = build(pre_start + 1, pre_start + (root_index - in_start),
                       in_start, root_index - 1);
    root->right = build(pre_start + (root_index - in_start) + 1, pre_end,
                        root_index + 1, in_end);
    return root;
}

int main() {
    int n;
    cin >> n;
    pre_order.resize(n);
    in_order.resize(n);
    weight.resize(n);
    for (int i = 0; i < n; ++i) cin >> weight[i];
    for (int i = 0; i < n; ++i) cin >> pre_order[i];
    for (int i = 0; i < n; ++i) cin >> in_order[i];
    Node *root = build(0, n - 1, 0, n - 1);
    return 0;
}
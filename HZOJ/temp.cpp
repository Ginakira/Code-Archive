#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ans;
void findCombinations(int n, int k, int begin, vector<int> &pre) {
    if (pre.size() == k) {
        ans.push_back(pre);
        return;
    }
    for (int i = begin; i <= n; ++i) {
        pre.push_back(i);
        findCombinations(n, k, i + 1, pre);
        pre.pop_back();
    }
    return;
}
vector<vector<int>> combine(int n, int k) {
    if (n <= 0 || k <= 0 || n < k) {
        return ans;
    }
    vector<int> pre;
    findCombinations(n, k, 1, pre);
    return ans;
}

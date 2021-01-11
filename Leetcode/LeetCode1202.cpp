// LeetCode 1202 交换字符串中的元素
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 并查集
// 由于交换具有传递性，所以我们将pairs作为边输入到并查集中
// 最后将连通块的各个索引对应的字符按字典序重排修改回去即可
class Solution {
   public:
    struct UnionSet {
        int *father;

        UnionSet(int n) {
            father = new int[n];
            for (int i = 0; i < n; ++i) father[i] = i;
        }

        int find(int x) {
            return father[x] == x ? x : father[x] = find(father[x]);
        }

        void merge(int a, int b) {
            int ra = find(a), rb = find(b);
            if (ra == rb) return;
            father[rb] = ra;
            return;
        }

        ~UnionSet() { delete[] father; }
    };

    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
        int n = s.size();
        UnionSet u(n);
        for (auto &pair : pairs) {
            u.merge(pair[0], pair[1]);
        }

        unordered_map<int, vector<char>> mp;
        for (int i = 0; i < n; ++i) {
            mp[u.find(i)].emplace_back(s[i]);
        }

        for (auto &[ind, v] : mp) {
            sort(v.begin(), v.end(), greater<int>());
        }

        for (int i = 0; i < n; ++i) {
            int ri = u.find(i);
            s[i] = mp[ri].back();
            mp[ri].pop_back();
        }
        return s;
    }
};
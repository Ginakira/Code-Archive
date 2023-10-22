// LeetCode 2316 统计无向图中无法互相到达点对数

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

class Solution {
   private:
    class DisjointSet {
       public:
        DisjointSet(int n) : n_(n), cnt_(n, 1) {
            father_.resize(n, -1);
            iota(father_.begin(), father_.end(), 0);
        }

        int find(int x) {
            return father_[x] == x ? x : father_[x] = find(father_[x]);
        }

        void merge(int a, int b) {
            int fa = find(a), fb = find(b);
            if (fa == fb) {
                return;
            }
            father_[fb] = fa;
            cnt_[fa] += cnt_[fb];
        }

        int get_cnt(int x) { return cnt_[x]; }

       private:
        int n_;
        vector<int> father_;
        vector<int> cnt_;
    };

   public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            ds.merge(u, v);
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += n - ds.get_cnt(ds.find(i));
        }
        return ans / 2;
    }
};
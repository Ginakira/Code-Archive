// LeetCode 399 除法求值
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 带路径压缩的带权并查集 0ms
class Solution {
   public:
    struct UnionSet {
        int* father;
        double* value;

        UnionSet() {
            father = new int[25];
            value = new double[25];
            for (int i = 0; i < 25; ++i) father[i] = i, value[i] = 1;
        }

        double get(int x) { return value[x]; }

        int find(int x) {
            if (father[x] == x) return x;
            int rx = find(father[x]);
            value[x] *= value[father[x]];
            father[x] = rx;
            return rx;
        }

        void merge(int a, int b, double val) {
            int ra = find(a), rb = find(b);
            if (ra == rb) return;
            father[rb] = ra;
            value[rb] = val * value[a] / value[b];
            return;
        }

        ~UnionSet() {
            delete[] father;
            delete[] value;
        }
    };

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        vector<double> ans;
        unordered_map<string, int> mp;
        UnionSet u;
        for (int i = 0, id = 0; i < equations.size(); ++i) {
            string sa = equations[i][0], sb = equations[i][1];
            if (mp.find(sa) == mp.end()) mp[sa] = id++;
            if (mp.find(sb) == mp.end()) mp[sb] = id++;
            u.merge(mp[sa], mp[sb], values[i]);
        }

        for (auto& query : queries) {
            double result = -1;
            if (mp.find(query[0]) != mp.end() &&
                mp.find(query[1]) != mp.end()) {
                int ra = u.find(mp[query[0]]), rb = u.find(mp[query[1]]);
                if (ra == rb) {
                    result = u.get(mp[query[1]]) / u.get(mp[query[0]]);
                }
            }
            ans.push_back(result);
        }
        return ans;
    }
};
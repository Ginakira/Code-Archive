// LeetCode 1418 点菜展示表
#include <algorithm>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<string>> displayTable(vector<vector<string>> &orders) {
        set<string> foods;
        unordered_map<int, unordered_map<string, int>> mp;  // 餐桌[菜品，数量]

        for (auto &order : orders) {
            int table = stoi(order[1]);
            string food = order[2];
            foods.insert(food);
            mp[table][food]++;
        }

        vector<int> tables;
        for (auto &[table, _] : mp) {
            tables.push_back(table);
        }
        sort(tables.begin(), tables.end());

        int n = mp.size() + 1, m = foods.size() + 1;

        vector<vector<string>> result(n, vector<string>(m));
        result[0][0] = "Table";
        copy(foods.begin(), foods.end(), result[0].begin() + 1);

        for (int i = 1; i < n; ++i) {
            int table = tables[i - 1];
            result[i][0] = to_string(table);
            for (int j = 1; j < m; ++j) {
                result[i][j] = to_string(mp[table][result[0][j]]);
            }
        }
        return result;
    }
};
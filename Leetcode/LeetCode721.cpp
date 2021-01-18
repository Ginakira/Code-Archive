// LeetCode 721 账户合并
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class UnionFind {
   private:
    vector<int> father;

   public:
    UnionFind(int n) : father(n) {
        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }
    }

    int find(int x) { return father[x] == x ? x : father[x] = find(father[x]); }

    void merge(int a, int b) { father[find(b)] = find(a); }
};

class Solution {
   public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        unordered_map<string, int> emailToIndex;
        unordered_map<string, string> emailToName;
        int emailCount = 0;
        // 将邮箱地址离散化为ID
        // 并存储邮箱地址与ID，邮箱地址与所有者名字的映射关系
        for (auto &account : accounts) {
            string &name = account[0];
            for (int i = 1; i < account.size(); ++i) {
                if (emailToIndex.find(account[i]) == emailToIndex.end()) {
                    emailToIndex[account[i]] = emailCount++;
                    emailToName[account[i]] = name;
                }
            }
        }
        UnionFind uf(emailCount);
        // 遍历每个用户的所有邮箱，使用邮箱映射的ID简历并查集
        for (auto &account : accounts) {
            int firstIndex = emailToIndex[account[1]];
            for (int i = 2; i < account.size(); ++i) {
                uf.merge(firstIndex, emailToIndex[account[i]]);
            }
        }
        unordered_map<int, vector<string>> indexToEmails;
        // 并查集合并完后遍历所有的邮箱，map中的邮箱已被去重
        // 将属于同一个所有者的邮箱存储到对应id的邮箱数组中
        for (auto &[email, _] : emailToIndex) {
            int index = uf.find(emailToIndex[email]);
            indexToEmails[index].emplace_back(email);
        }
        vector<vector<string>> merged;
        // 遍历已经分类好所有者的邮箱，排序后加入答案
        for (auto &[_, emails] : indexToEmails) {
            sort(emails.begin(), emails.end());
            vector<string> account;
            account.emplace_back(emailToName[emails[0]]);
            for (auto &email : emails) {
                account.emplace_back(email);
            }
            merged.emplace_back(account);
        }
        return merged;
    }
};
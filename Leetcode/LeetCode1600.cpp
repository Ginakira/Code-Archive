// LeetCode 1600 皇位继承顺序
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// 多叉树前序遍历
class ThroneInheritance {
   private:
    string king;
    unordered_map<string, vector<string>> edges;
    unordered_set<string> dead;

   public:
    ThroneInheritance(string kingName) : king(kingName) {}

    void birth(string parentName, string childName) {
        edges[move(parentName)].emplace_back(move(childName));
    }

    void death(string name) { dead.insert(move(name)); }

    vector<string> getInheritanceOrder() {
        vector<string> result;

        function<void(const string &)> pre_order = [&](const string &name) {
            if (!dead.count(name)) {
                result.emplace_back(name);
            }

            for (const string &child : edges[name]) {
                pre_order(child);
            }
        };

        pre_order(king);
        return result;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
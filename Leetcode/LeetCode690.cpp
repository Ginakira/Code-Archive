// LeetCode 690 员工的重要性
#include <unordered_map>
#include <vector>
using namespace std;

// Definition for Employee.
class Employee {
   public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
   private:
    int get_importance(unordered_map<int, Employee *> &mp, int id) {
        int ret = mp[id]->importance;
        for (int &sid : mp[id]->subordinates) {
            ret += get_importance(mp, sid);
        }
        return ret;
    }

   public:
    int getImportance(vector<Employee *> employees, int id) {
        unordered_map<int, Employee *> mp;
        for (auto &employee : employees) {
            mp[employee->id] = employee;
        }
        return get_importance(mp, id);
    }
};
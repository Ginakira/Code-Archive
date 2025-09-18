// LeetCode 3408 设计任务管理器

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

class TaskManager {
 private:
  using TIII = tuple<int, int, int>;
  using SetType = set<TIII, greater<TIII>>;
  SetType task_q_;
  unordered_map<int, SetType::iterator> task_id_to_it_;

 public:
  TaskManager(vector<vector<int>>& tasks) {
    for (const auto& task : tasks) {
      add(task[0], task[1], task[2]);
    }
  }

  void add(int userId, int taskId, int priority) {
    auto [it, _] = task_q_.emplace(priority, taskId, userId);
    task_id_to_it_[taskId] = it;
  }

  void edit(int taskId, int newPriority) {
    int user_id = std::get<2>(*task_id_to_it_[taskId]);
    rmv(taskId);
    add(user_id, taskId, newPriority);
  }

  void rmv(int taskId) {
    auto it = task_id_to_it_[taskId];
    task_q_.erase(it);
    task_id_to_it_.erase(taskId);
  }

  int execTop() {
    if (task_q_.empty()) {
      return -1;
    }
    auto [_, task_id, user_id] = *task_q_.begin();
    rmv(task_id);
    return user_id;
  }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
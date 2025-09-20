// LeetCode 3508 设计路由器

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

class Router {
 private:
  int mem_limit_;
  deque<tuple<int, int, int>> pkts_;
  set<tuple<int, int, int>> mark_;
  unordered_map<int, deque<int>> dst_to_stmp_;

 public:
  Router(int memoryLimit) : mem_limit_(memoryLimit) {}

  bool addPacket(int source, int destination, int timestamp) {
    auto pkt = make_tuple(source, destination, timestamp);
    if (mark_.count(pkt)) {
      return false;
    }
    if (pkts_.size() == mem_limit_) {
      forwardPacket();
    }
    pkts_.emplace_back(pkt);
    dst_to_stmp_[destination].emplace_back(timestamp);
    mark_.emplace(pkt);
    return true;
  }

  vector<int> forwardPacket() {
    if (pkts_.empty()) {
      return {};
    }
    auto [src, dst, stmp] = pkts_.front();
    mark_.erase(pkts_.front());
    pkts_.erase(pkts_.begin());
    dst_to_stmp_[dst].pop_front();
    return {src, dst, stmp};
  }

  int getCount(int destination, int startTime, int endTime) {
    auto& stmps = dst_to_stmp_[destination];
    return distance(ranges::lower_bound(stmps, startTime),
                    ranges::upper_bound(stmps, endTime));
  }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
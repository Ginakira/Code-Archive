// LeetCode 1845 座位预约管理系统

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

class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> pq_;
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; ++i) {
            pq_.emplace(i);
        }
    }
    
    int reserve() {
        int ret = pq_.top();
        pq_.pop();
        return ret;
    }
    
    void unreserve(int seatNumber) {
        pq_.emplace(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
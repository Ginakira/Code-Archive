// 最近的请求次数
#include <queue>
using namespace std;

// 维护一个当前队首与t差值不大于3000的队列 因为t是严格递增的
// 所以每次循环判断队首弹出直到差值小于等于3000即可
class RecentCounter {
   private:
    queue<int> q;

   public:
    RecentCounter() {}

    int ping(int t) {
        q.push(t);
        while (t - q.front() > 3000) q.pop();
        return q.size();
    }
};
// LeetCode 911 在线选举

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class TopVotedCandidate {
   private:
    vector<int> tops_;
    vector<int> times_;

   public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int, int> ticket_count;
        times_ = times;
        int top = -1;
        ticket_count[-1] = -1;
        for (auto& p : persons) {
            ++ticket_count[p];
            if (ticket_count[p] >= ticket_count[top]) {
                top = p;
            }
            tops_.emplace_back(top);
        }
    }

    int q(int t) {
        int pos =
            upper_bound(times_.begin(), times_.end(), t) - times_.begin() - 1;
        return tops_[pos];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
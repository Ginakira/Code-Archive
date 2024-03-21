// LeetCode 2671

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

class FrequencyTracker {
   private:
    unordered_map<int, int> num_cnt_;
    unordered_map<int, int> freq_cnt_;

   public:
    FrequencyTracker() {}

    void add(int number) {
        auto &cnt = num_cnt_[number];
        if (cnt) {
            --freq_cnt_[cnt];
        }
        ++cnt;
        ++freq_cnt_[cnt];
    }

    void deleteOne(int number) {
        auto &cnt = num_cnt_[number];
        if (cnt > 0) {
            --freq_cnt_[cnt];
            --cnt;
        }
        if (cnt) {
            ++freq_cnt_[cnt];
        }
    }

    bool hasFrequency(int frequency) { return freq_cnt_[frequency] > 0; }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
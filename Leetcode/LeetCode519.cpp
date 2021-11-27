// LeetCode 519 随机翻转矩阵

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 二维映射一维 + 洗牌算法变形
class Solution {
   private:
    int m_;
    int n_;
    int total_;
    unordered_map<int, int> mp;

   public:
    Solution(int m, int n) : m_(m), n_(n), total_(m * n) {
        srand(time(nullptr));
    }

    vector<int> flip() {
        int x = rand() % total_;
        vector<int> ans;
        --total_;
        if (mp.count(x)) {
            ans = {mp[x] / n_, mp[x] % n_};
        } else {
            ans = {x / n_, x % n_};
        }
        if (mp.count(total_)) {
            mp[x] = mp[total_];
        } else {
            mp[x] = total_;
        }
        return ans;
    }

    void reset() {
        total_ = n_ * m_;
        mp.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
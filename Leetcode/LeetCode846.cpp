// LeetCode 846 一手顺子

#include <algorithm>
#include <numeric>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) {
            return false;
        }
        map<int, int> cnt;
        for (int num : hand) {
            ++cnt[num];
        }

        int group_count = n / groupSize;
        for (int i = 0; i < group_count; ++i) {
            int first_num = cnt.begin()->first;
            --cnt[first_num];
            if (cnt[first_num] == 0) {
                cnt.erase(first_num);
            }
            for (int j = 1; j < groupSize; ++j) {
                if (cnt.find(first_num + j) == cnt.end()) {
                    return false;
                } else {
                    --cnt[first_num + j];
                    if (cnt[first_num + j] == 0) {
                        cnt.erase(first_num + j);
                    }
                }
            }
        }
        return true;
    }
};
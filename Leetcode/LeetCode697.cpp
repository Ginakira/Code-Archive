// LeetCode 697 数组的度
#include <unordered_map>
#include <vector>
using namespace std;

// 哈希表
class Solution {
   public:
    int findShortestSubArray(vector<int> &nums) {
        int n = nums.size();
        unordered_map<int, Record *> mp;
        int max_count = 0, min_len = 0x3f3f3f3f;
        for (int i = 0; i < n; ++i) {
            if (mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = new Record(i, i, 1);
            }
            Record *rec = mp[nums[i]];
            rec->last_index = i;
            ++rec->count;
            if (rec->count > max_count) {
                max_count = rec->count;
                min_len = rec->last_index - rec->first_index + 1;
            } else if (rec->count == max_count) {
                max_count = rec->count;
                min_len = min(min_len, rec->last_index - rec->first_index + 1);
            }
        }
        return min_len;
    }

   private:
    struct Record {
        Record(int f_ind, int l_ind, int cnt)
            : first_index(f_ind), last_index(l_ind), count(cnt) {}
        int first_index;
        int last_index;
        int count;
    };
};

// 同理 更简洁的写法
class Solution2 {
   public:
    int findShortestSubArray(vector<int> &nums) {
        int n = nums.size();
        // mp中value含义：[首次出现位置，最后出现位置，出现次数]]
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            if (mp.count(nums[i])) {
                mp[nums[i]][1] = i;
                ++mp[nums[i]][2];
            } else {
                mp[nums[i]] = {i, i, 1};
            }
        }
        int max_count = 0, min_len = 0x3f3f3f3f;
        for (auto &[_, vec] : mp) {
            if (vec[2] > max_count) {
                max_count = vec[2];
                min_len = vec[1] - vec[0] + 1;
            } else if (vec[2] == max_count) {
                min_len = min(min_len, vec[1] - vec[0] + 1);
            }
        }
        return min_len;
    }
};
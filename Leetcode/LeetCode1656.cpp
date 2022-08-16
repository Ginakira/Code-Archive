// LeetCode 1656 设计有序流

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class OrderedStream {
   private:
    int ptr_ = 0;
    int n_ = 0;
    vector<string> data_;

   public:
    OrderedStream(int n) : n_(n) { data_.resize(n); }

    vector<string> insert(int idKey, string value) {
        vector<string> ret;
        data_[idKey - 1] = value;
        while (ptr_ < n_ && !data_[ptr_].empty()) {
            ret.emplace_back(data_[ptr_]);
            ++ptr_;
        }
        return ret;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
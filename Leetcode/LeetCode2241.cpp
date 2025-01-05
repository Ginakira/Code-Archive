// LeetCode 2241 设计一个 ATM 机器

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

class ATM {
   private:
    static constexpr int kCashKinds = 5;
    std::array<int, kCashKinds> balance_{{0}};
    static constexpr std::array<int, kCashKinds> idx_to_deno_{
        {20, 50, 100, 200, 500}};

   public:
    ATM() {}

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < kCashKinds; ++i) {
            balance_[i] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        std::vector<int> res(kCashKinds, 0);
        for (int i = kCashKinds - 1; i >= 0; --i) {
            int cur = 0;
            int deno = idx_to_deno_[i];
            if (amount >= deno) {
                cur = min(balance_[i], amount / deno);
            }
            res[i] = cur;
            amount -= cur * deno;
        }
        if (amount > 0) {
            return {-1};
        }
        for (int i = 0; i < kCashKinds; ++i) {
            balance_[i] -= res[i];
        }
        return res;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
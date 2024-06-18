// LeetCode 2288 价格减免

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

class Solution {
   public:
    std::string discountPrices(const std::string& sentence, int discount) {
        std::stringstream input(sentence);
        std::stringstream output;
        std::string item;
        const char delimiter = ' ';
        const char dollar = '$';

        while (getline(input, item, delimiter)) {
            if (item[0] == dollar && isValidNumber(item.substr(1))) {
                try {
                    double price = std::stod(item.substr(1));
                    double discountedPrice = price * (1 - discount / 100.0);
                    output << dollar << std::fixed << std::setprecision(2)
                           << discountedPrice;
                } catch (...) {
                    output << item;
                }
            } else {
                output << item;
            }
            output << delimiter;
        }

        std::string res = output.str();
        if (!res.empty()) {
            res.pop_back();
        }
        return res;
    }

   private:
    bool isValidNumber(const std::string& s) {
        return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
    }
};
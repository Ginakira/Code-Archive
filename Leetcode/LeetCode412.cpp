// LeetCode 412 Fizz Buzz
#include <functional>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        vector<function<string(int)>> rules = {
            [](int n) -> string { return n % 3 == 0 ? "Fizz" : ""; },
            [](int n) -> string { return n % 5 == 0 ? "Buzz" : ""; },
        };

        for (int i = 1; i <= n; ++i) {
            string s = "";
            for (auto &rule : rules) {
                s += rule(i);
            }
            if (s == "") s += to_string(i);
            ans.push_back(s);
        }
        return ans;
    }
};
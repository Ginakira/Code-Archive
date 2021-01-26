// LeetCode 415 字符串相加
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    string addStrings(string num1, string num2) {
        if (num1.size() < num2.size()) swap(num1, num2);
        num1 = "0" + num1;
        for (int ind = 1; ind <= num1.size(); ++ind) {
            int p1 = num1.size() - ind, p2 = num2.size() - ind;
            if (p2 >= 0) num1[p1] += num2[p2] - '0';
            if (num1[p1] > '9') {
                num1[p1 - 1]++;
                num1[p1] = (num1[p1] - '0') % 10 + '0';
            }
        }
        if (num1[0] == '0' && num1.size() > 1) num1.erase(0, 1);
        return num1;
    }
};

// BigInt类
class BigInt : vector<int> {
   public:
    BigInt(string s) {
        int n = s.size();
        for (int i = n - 1; i >= 0; --i) {
            emplace_back(s[i] - '0');
        }
    }

    BigInt operator+(BigInt &b) {
        BigInt result = *this;
        int n = b.size(), len = result.size() > n ? result.size() : n;
        result.resize(len);
        for (int i = 0; i < len; ++i) {
            if (i < n) {
                result[i] += b[i];
            }
            if (result[i] >= 10) {
                if (i + 1 == result.size()) {
                    result.emplace_back(0);
                }
                result[i + 1] += result[i] / 10;
                result[i] %= 10;
            }
        }
        return result;
    }

    string stringify() {
        string s;
        for (auto it = rbegin(); it != rend(); ++it) {
            s.push_back(*it + '0');
        }
        return s;
    }
};

class Solution2 {
   public:
    string addStrings(string num1, string num2) {
        BigInt a(num1), b(num2);
        return (a + b).stringify();
    }
};
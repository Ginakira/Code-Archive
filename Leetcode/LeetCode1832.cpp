// LeetCOde 1832 判断句子是否为全字母句

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool checkIfPangram(string sentence) {
        if (sentence.size() < 26) {
            return false;
        }
        bitset<26> bs;
        for (char c : sentence) {
            bs.set(c - 'a');
        }
        return bs.all();
    }
};
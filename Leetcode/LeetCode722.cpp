// LeetCode 722 删除注释

#include <algorithm>
#include <array>
#include <iostream>
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
   private:
    void PrintLines(const vector<string> &source) {
        for (auto &line : source) {
            std::cout << line << std::endl;
        }
    }

   public:
    vector<string> removeComments(vector<string> &source) {
        // join all lines
        string one_line;
        for (auto &line : source) {
            one_line += line + '\n';
        }

        for (int i = 1; i < one_line.size(); ++i) {
            if (one_line[i - 1] != '/') {
                continue;
            }
            switch (one_line[i]) {
                case '/': {
                    one_line[i] = one_line[i - 1] = 0;
                    while (i < one_line.size() && one_line[i] != '\n') {
                        one_line[i] = 0;
                        ++i;
                    }
                } break;
                case '*': {
                    one_line[i] = one_line[i - 1] = 0;
                    while (i < one_line.size() &&
                           (one_line[i] != '*' || one_line[i + 1] != '/')) {
                        one_line[i] = 0;
                        ++i;
                    }
                    if (one_line[i] == '*' && one_line[i + 1] == '/') {
                        one_line[i] = one_line[i + 1] = 0;
                        ++i;
                    }
                } break;
                default:
                    break;
            }
        }

        // split to lines
        vector<string> ans;
        string line;
        for (auto i = 0; i < one_line.size(); ++i) {
            if (one_line[i] == '\n') {
                if (!line.empty()) {
                    ans.emplace_back(line);
                    line.clear();
                }
                continue;
            }
            if (one_line[i] == 0) {
                continue;
            }
            line.push_back(one_line[i]);
        }
        // PrintLines(ans);
        return ans;
    }
};

// LeetCode 649 Dota2参议院
#include <string>
#include <vector>
using namespace std;

// Solution1: 纯模拟 1800ms
// 优先ban掉后面的第一个敌方议员 到末尾了就从头ban
class Solution {
   public:
    string predictPartyVictory(string senate) {
        int n = senate.size(), rcnt = 0, dcnt = 0;
        vector<bool> mark(n, true);
        for (const char &c : senate) {
            if (c == 'R')
                ++rcnt;
            else
                ++dcnt;
        }
        for (int i = 0;; i = (i + 1) % n) {
            if (!mark[i]) continue;
            if (rcnt == 0) {
                return "Dire";
            } else if (dcnt == 0) {
                return "Radiant";
            } else {
                if (senate[i] == 'R') {
                    banFirstEnemy(senate, mark, i, n, 'D', dcnt);
                } else {
                    banFirstEnemy(senate, mark, i, n, 'R', rcnt);
                }
            }
        }
        return "";
    }

    void banFirstEnemy(string &s, vector<bool> &mark, int ind, int n,
                       char target, int &cnt) {
        for (int i = (ind + 1) % n; i != ind; i = (i + 1) % n) {
            if (mark[i] && s[i] == target) {
                mark[i] = false;
                --cnt;
                break;
            }
        }
        return;
    }
};
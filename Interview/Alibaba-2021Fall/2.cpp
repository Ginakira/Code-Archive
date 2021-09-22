#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<int, int> primes;

void init_prime() {
    primes[1] = 0;
    int count = 1;
    for (int i = 2; i < 100000; ++i) {
        bool mark = true;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                mark = false;
                break;
            }
        }
        if (mark) {
            primes[i] = count++;
        }
    }
}

void dfs(int ind, const string &s, int len, vector<int> &cur,
         vector<int> &ans) {
    if (ind == len) {
        if (cur.size() > ans.size()) {
            ans = cur;
        }
        return;
    }
    if ((len - ind) < ((int)ans.size() - (int)cur.size())) {
        return;
    }

    int num = 0;
    for (int i = ind; i < ind + 4; ++i) {
        num = num * 10 + s[i] - '0';
        if (num == 0) {
            return;
        }
        if (primes.find(num) == primes.end()) {
            continue;
        }
        cur.push_back(primes[num]);
        dfs(i + 1, s, len, cur, ans);
        cur.pop_back();
    }
}

// 23.64%
int main() {
    init_prime();
    string s;
    cin >> s;
    int len = s.size();

    vector<int> ans;
    vector<int> cur;

    dfs(0, s, len, cur, ans);

    cout << ans.size() << endl;
    for (int num : ans) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}
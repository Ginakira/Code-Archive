#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// AC
int StringSplit(string str) {
    int n = str.size();
    if (n < 2) {
        return 0;
    }
    int total_b = count(str.begin(), str.end(), 'b');
    int max_score = 0;
    int cur_left_a = 0, cur_right_b = total_b;
    for (int i = 0; i < n - 1; ++i) {
        if (str[i] == 'a') {
            ++cur_left_a;
        } else if (str[i] == 'b') {
            --cur_right_b;
        }
        int score = cur_left_a + cur_right_b;
        max_score = max(score, max_score);
    }
    return max_score;
}

int main() {
    cout << StringSplit("abbbab") << endl;
    cout << StringSplit("aabbb") << endl;
    cout << StringSplit("bbbb") << endl;

    return 0;
}
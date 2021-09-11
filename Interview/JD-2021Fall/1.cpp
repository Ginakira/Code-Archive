#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n, m, x, y, z;
    cin >> n >> m >> x >> y >> z;
    unordered_map<char, tuple<int, int>> keyboard;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            keyboard[c] = make_tuple(i, j);
        }
    }
    string target;
    cin >> target;

    long long time = 0;
    int cur_x = 0, cur_y = 0;
    for (char ch : target) {
        auto [target_x, target_y] = keyboard[ch];
        // move
        time += (abs(target_x - cur_x) + abs(target_y - cur_y)) * x;
        if (target_x != cur_x && target_y != cur_y) {
            time += y;
        }
        // click
        time += z;
        cur_x = target_x;
        cur_y = target_y;
    }

    cout << time << endl;

    return 0;
}

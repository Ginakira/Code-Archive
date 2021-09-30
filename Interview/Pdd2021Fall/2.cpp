#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// AC
int main() {
    constexpr int INF = numeric_limits<int>::max();
    int n, start_x, start_y, target_x, target_y;
    cin >> n >> start_x >> start_y >> target_x >> target_y;

    int min_day = INF;
    int dx = target_x - start_x, dy = target_y - start_y;
    int day = 0;
    for (day = 0; day < n; ++day) {
        char wind;
        cin >> wind;
        if (dx == 0 && dy == 0) {
            min_day = day;
            break;
        }
        switch (wind) {
            case 'N': {
                if (dy > 0) {
                    --dy;
                }
            } break;
            case 'S': {
                if (dy < 0) {
                    ++dy;
                }
            } break;
            case 'W': {
                if (dx < 0) {
                    ++dx;
                }
            } break;
            case 'E': {
                if (dx > 0) {
                    --dx;
                }
            } break;
            default: {
            } break;
        }
    }
    if (day == n && dx == 0 && dy == 0) {
        min_day = n;
    }
    cout << (min_day == INF ? -1 : min_day) << endl;
    return 0;
}
#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

struct Oil {
    int x, y;
};

Oil oil[10010];

bool cmp(Oil a, Oil b) {
    return a.y > b.y;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> oil[i].x >> oil[i].y;
    }
    sort(oil, oil + n, cmp);
    int mins = INT_MAX;
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        sum = 0;
        int line = oil[i].y;
        for(int j = 0; j < n; ++j) {
            if(oil[j].y == line) continue;
            else sum += abs(oil[j].y - line);
        }
        //cout << "#SUM " << sum << endl;
        mins = min(mins, sum);
    }
    cout << mins << endl;
    return 0;
}
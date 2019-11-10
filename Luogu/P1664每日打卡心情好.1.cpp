#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, t;
    bool flag = true;
    int day = 0, score = 0, miss = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> t;
        if(t == 0) miss++, flag = false;
        else {
            if(!flag) {
                day -= pow(2, miss - 1);
                if(day < 0) day = 0;
            }
            miss = 0, day++;
            flag = true;
            if(day >= 0 && day < 3) score++;
            else if(day >= 3 && day < 7) score += 2;
            else if(day >= 7 && day < 30) score += 3;
            else if(day >= 30 && day < 120) score += 4;
            else if(day >= 120 && day < 365) score += 5;
            else score += 6;
        }
        //cout << "day" << day << ' ' << score << endl;
    }
    cout << score;
    return 0;
}
/************************************************************
    File Name : #481-冰壶比赛.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/02/06 11:24:50
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int da[8], db[8];

void score_cal(int &score, int other_min, int dis[], int r) {
    for (int i = 0; i < 8; ++i) {
        if (dis[i] < other_min && dis[i] <= r) score++;
    }
    return;
}

int main() {
    int r, total_a = 0, total_b = 0, cnt = 0;
    bool abstain = false;
    cin >> r;
    while (true && !abstain && cnt < 10) {
        int min_a = 2333, min_b = 2333;
        for (int i = 0; i < 8 && !abstain; ++i) {
            cin >> da[i];
            if (da[i] == -1) abstain = true;
            min_a = min(min_a, da[i]);
        }
        for (int i = 0; i < 8 && !abstain; ++i) {
            cin >> db[i];
            min_b = min(min_b, db[i]);
        }
        if (abstain) break;
        int score_a = 0, score_b = 0;
        if (min_a < min_b)
            score_cal(score_a, min_b, da, r);
        else
            score_cal(score_b, min_a, db, r);
        cout << score_a << ":" << score_b << endl;
        total_a += score_a, total_b += score_b;
        cnt++;
    }
    cout << total_a << ":" << total_b << endl;
    return 0;
}
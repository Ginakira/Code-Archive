/************************************************************
    File Name : #598-MySQL.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/06 16:25:05
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 500
#define MAX_M 50

string info[MAX_N + 5][MAX_M + 5];
int max_len[MAX_M + 5];

void split(string s, int ind, int m) {
    string sub;
    stringstream ss(s);
    for (int j = 1; j <= m; ++j) {
        getline(ss, sub, ',');
        info[ind][j] = sub;
    }
    return;
}

void count_max(int n, int m) {
    for (int j = 1; j <= m; ++j) {
        for (int i = 0; i <= n; ++i) {
            max_len[j] = max(max_len[j], (int)info[i][j].size());
        }
    }
    return;
}

void print_line(int n, int m) {
    for (int j = 1; j <= m; ++j) {
        j == 1 && cout << '+';
        for (int k = 0; k < max_len[j] + 2; ++k) cout << '-';
        cout << '+';
    }
    cout << endl;
    return;
}

void print_item(int ind, int n, int m) {
    for (int j = 1; j <= m; ++j) {
        j == 1 && cout << '|';
        cout << " " << info[ind][j];
        int cnt = max_len[j] - (int)info[ind][j].size();
        for (int k = 0; k < cnt; ++k) cout << ' ';
        cout << " |";
    }
    cout << endl;
    return;
}

void print_body(int n, int m) {
    for (int i = 1; i <= n; ++i) {
        print_item(i, n, m);
    }
    return;
}

int main() {
    int n, m;
    cin >> n >> m;
    string temp;
    cin >> temp;
    split(temp, 0, m);
    for (int i = 1; i <= n; ++i) {
        cin >> temp;
        split(temp, i, m);
    }
    count_max(n, m);
    print_line(n, m);
    print_item(0, n, m);
    print_line(n, m);
    print_body(n, m);
    print_line(n, m);
    return 0;
}
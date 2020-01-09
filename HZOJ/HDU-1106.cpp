/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/01/04 22:40:43
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#define MAXN 1000
using namespace std;

vector<string> nums;

int main() {
    stringstream ss;
    string s;
    while (cin >> s) {
        int start = 0;
        size_t pos = s.find("5", start);
        while (pos != s.npos) {
            if (pos != start) nums.push_back(s.substr(start, (pos - start)));
            start = pos + 1;
            pos = s.find("5", start);
        }
        if (start < s.length())
            nums.push_back(s.substr(start, s.length() - start));
        int len = nums.size();
        int real_num[MAXN + 5];
        for (int i = 0; i < len; ++i) {
            ss.clear();
            ss << nums[i];
            ss >> real_num[i];
        }
        sort(real_num, real_num + len);
        for (int i = 0; i < len; ++i) {
            i > 0 && cout << " ";
            cout << real_num[i];
        }
        cout << endl;
        nums.clear();
    }
    return 0;
}
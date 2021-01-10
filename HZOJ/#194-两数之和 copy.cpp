/************************************************************
    File Name : #194-两数之和 copy.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2021/01/10 20:44:39
************************************************************/
#include <cstdio>
using namespace std;

int main() {
    int n, m;
    scanf("%d", &n);
    int num[n + 5];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
    }
    scanf("%d", &m);
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = num[left] + num[right];
        if (sum == m) {
            printf("Yes\n");
            return 0;
        } else if (sum < m) {
            ++left;
        } else {
            --right;
        }
    }
    printf("No\n");
    return 0;
}
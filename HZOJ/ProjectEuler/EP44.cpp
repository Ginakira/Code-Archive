/************************************************************
    File Name : EP44.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/24 18:59:25
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
typedef long long int1;

int1 Pentagonal(int1 n) { return n * (3 * n - 1) / 2; }

int binary_search(int1 (*func)(int1), int1 n, int1 x) {
    int1 head = 1, tail = n, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (func(mid) == x) return mid;
        if (func(mid) < x)
            head = mid + 1;
        else
            tail = mid - 1;
    }
    return 0;
}

int main() {
    int1 n = 2, D = INT_MAX, pk, pj;
    while (Pentagonal(n) - Pentagonal(n - 1) < D) {
        pk = Pentagonal(n);
        // printf("pk = %lld, D = %lld\n", pk, D);
        for (int1 j = n - 1; j >= 1; --j) {
            pj = Pentagonal(j);
            if (pk - pj >= D) break;
            int flag = 1;
            flag = binary_search(Pentagonal, 2 * n, pk + pj);
            flag = flag && binary_search(Pentagonal, n, pk - pj);
            if (flag) {
                D = pk - pj;
            }
        }
        n++;
    }
    printf("%lld\n", D);
    return 0;
}
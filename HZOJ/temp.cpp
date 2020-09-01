
#include <stdio.h>

#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void quick_sort(int* num, int l, int r) {
    if (r < l) return;
    int x = l, y = r, z = num[l];
    while (x < y) {
        while (x < y && num[y] >= z) y--;
        if (x < y) num[x++] = num[y];
        while (x < y && num[x] <= z) x++;
        if (x < y) num[y++] = num[x];
    }
    num[x] = z;
    quick_sort(num, l, x - 1);
    quick_sort(num, x + 1, r);
    return;
}

void quicksort(vector<int>& num, int l, int r) {
    if (r < l) return;
    int x = l, y = r, z = num[l];
    while (x < y) {
        while (x < y && num[y] >= z) y--;
        if (x < y) num[x++] = num[y];
        while (x < y && num[x] <= z) x++;
        if (x < y) num[y--] = num[x];
    }
    num[x] = z;
    quicksort(num, l, x - 1);
    quicksort(num, x + 1, r);
    return;
}

int main() {
    vector<int> num(7);
    num = {1, 3, 4, 6, 9, 5, 2};
    int arr[7] = {1, 3, 4, 6, 9, 5, 2};
    for (int i = 0; i < 7; i++) {
        // cin >> arr[i];
    }
    quicksort(num, 0, 6);
    for (int i = 0; i < 7; i++) {
        cout << num[i] << " ";
    }
    cout << endl;
    return 0;
}

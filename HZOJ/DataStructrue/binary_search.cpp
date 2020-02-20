#include <stdio.h>

#define P(func, args...) \
    { printf("%s = %d\n", #func, func(args)); }

// 1 3 5 7 9 10
int binary_search_original(int *num, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == x) return mid;
        if (num[mid] < x)
            head = mid + 1;
        else
            tail = mid - 1;
    }
    return -1;
}

// 1111111100000 - Find the last '1'
int binary_search_lastvalid(int *num, int n) {
    int head = -1, tail = n - 1, mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (num[mid] == 1)
            head = mid;
        else
            tail = mid - 1;
    }
    return head;
}

// 0000000011111 - Find the first '1'
int binary_search_firstvalid(int *num, int n) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == 1)
            tail = mid;
        else
            head = mid + 1;
    }
    return head == n ? -1 : head;
}

int main() {
    int arr1[10] = {1, 3, 5, 7, 9, 11, 13, 17, 19, 21};
    int arr2[10] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
    int arr3[10] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1};
    P(binary_search_original, arr1, 10, 7);
    P(binary_search_lastvalid, arr2, 10);
    P(binary_search_firstvalid, arr3, 10);
    return 0;
}
#include <stdio.h>

struct person {
    int n;
    char a;
    char arr[1000];
    int b;
};

int main() {
    int cnt = 0, flag = 0;
    double count = 0;
    struct person p;
    scanf("%d", &p.n);
    for (int i = 0; i < p.n; i++) {
        scanf(" %c", &p.a);
        if (p.a == 'C') {
            scanf("%s", p.arr);
            flag++;
        } else if (p.a == 'N') {
            scanf("%d", &p.b);
            count += p.b;
        }
        // printf("%c %s flag=%d\n", p.a, p.arr, flag);
    }
    printf("%d %1.lf\n", flag, count / (p.n - flag));

    return 0;
}
#include <stdio.h>
#include <string.h>

const char *target = "Ban_smoking";
const char *replace = "No_smoking";

void solve() {
    char origin[23333] = {0};
    char answer[23333] = {0};
    scanf("%s", origin);
    char *answer_p = answer, *origin_p = origin;
    char *find_result;
    int left_count = strlen(origin);
    while ((find_result = strstr(origin_p, target)) != NULL) {
        size_t sz = find_result - origin_p;
        strncpy(answer_p, origin_p, sz);
        left_count -= sz + 11;
        origin_p += sz + 11;
        answer_p += sz;
        strncpy(answer_p, replace, 10);
        answer_p += 10;
    }
    if (left_count > 0) {
        strncpy(answer_p, origin_p, left_count);
    }
    printf("%s\n", answer);
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    char c[n][5000];
    while (n--) {
        solve();
    }
    return 0;
}
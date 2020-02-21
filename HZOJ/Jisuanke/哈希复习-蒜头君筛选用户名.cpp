#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HashTable {
    char **data;
    int size;
} HashTable;

void init(HashTable *h, int n) {
    if (!h) return;
    h->data = (char **)malloc(sizeof(char *) * n);
    memset(h->data, 0, sizeof(char *) * n);
    h->size = n;
    return;
}

int hash(HashTable *h, char *str) {
    unsigned int code = 0;
    for (int i = 0; str[i]; ++i) {
        code = (code << 3) ^ str[i];
    }
    return (int)(code % h->size);
}

int search(HashTable *h, char *str, int *pos) {
    int times = 0;
    *pos = hash(h, str);
    //printf("%d\n", *pos);
    while (h->data[*pos] && strcmp(h->data[*pos], str)) {
        ++times;
        (*pos) += times;
        (*pos) %= h->size;
    }
    if (h->data[*pos]) {
        return 1;
    } else {
        return 0;
    }
}

int insert(HashTable *h, char *str) {
    int pos;
    if (search(h, str, &pos)) return 0;
    h->data[pos] = strdup(str);
    return 1;
}

void clear(HashTable *h) {
    free(h->data);
    free(h);
    return;
}

void str_to_lower(char *str) {
    for (int i = 0; str[i]; ++i) {
        str[i] = tolower(str[i]);
    }
    return;
}

int main() {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    int n;
    scanf("%d", &n);
    init(h, n * 4);
    char str[105];
    while (n--) {
        scanf("%s", str);
        str_to_lower(str);
        printf("%s\n", insert(h, str) ? "No" : "Yes");
    }
    clear(h);
    return 0;
}
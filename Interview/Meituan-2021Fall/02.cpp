#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

constexpr int MOD = 1e9 + 7;

void backtrace(vector<int> &books, vector<int> &store, vector<int> &vis,
               int ind, int n, int &ans) {
    if (ind == n) {
        ans = (ans + 1) % MOD;
        return;
    }
    auto ii =
        lower_bound(store.begin(), store.end(), books[ind]) - store.begin();
    for (int i = ii; i < n; ++i) {
        if (vis[i]) {
            continue;
        }
        vis[i] = true;
        backtrace(books, store, vis, ind + 1, n, ans);
        vis[i] = false;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> books(n);
    vector<int> store(n);
    vector<int> vis(n, false);
    for (int i = 0; i < n; ++i) {
        cin >> books[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> store[i];
    }
    sort(books.begin(), books.end());
    sort(store.begin(), store.end());

    int ans = 0;
    backtrace(books, store, vis, 0, n, ans);
    cout << ans << endl;
    return 0;
}
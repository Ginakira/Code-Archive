#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> trees(n);
    for (int i = 0;i < n; ++i) {
        cin >> trees[i];
    }
    
    int ind = 0;
    int ans = 0;
    set<int> st;
    
    while (ind < n) {
        int temp_ind = ind;
        while (temp_ind < n && trees[temp_ind] == trees[ind]) {
            ++temp_ind;
        }

        int count = 0;
        for (int num : st) {
            if (num >= trees[ind]) break;
            ++count;
        }

        ans += count * (temp_ind - ind);
        st.insert(trees[ind]);
        ind = temp_ind;
        cout << "ans=" << ans << endl;
    }
    
    cout << ans << endl;
    return 0;
}
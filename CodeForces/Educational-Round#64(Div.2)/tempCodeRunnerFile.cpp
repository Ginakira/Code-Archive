#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> num;
bool flag[200001] = {0};
int main() {
    int n, z, ans = 0;
    cin >> n >> z;
    while(n--) {
        int t;
        cin >> t;
        num.push_back(t);
    }
    sort(num.begin(), num.end());
    for(int i = 0; i < num.size() - 1; ++i) {
        if(flag[num[i]]) continue;
        for(int j = i + 1; j < num.size(); ++j) {
            if(flag[num[j]]) continue;
            if(num[j] - num[i] >= z) {
                ans++;
                flag[i] = 1, flag[j] = 1;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
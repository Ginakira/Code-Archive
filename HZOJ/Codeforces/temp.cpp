#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int a, b;
};

vector<Node> aa(100005);
vector<Node> bb(1000005);
int main() {
    int k, n;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> aa[i].a;
    }
    for (int i = 0; i < k; i++) {
        cin >> aa[i].b;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> bb[i].a;
    }
    for (int i = 0; i < n; i++) {
        cin >> bb[i].b;
    }

    for (int i = 0; i < n; i++) {
        int cur = i;
        int j = 0;
        while (j < k) {
            if (bb[cur].a != aa[j].a || bb[cur].b != aa[j].b) {
                break;
            } else {
                j++;
                cur++;
            }
            cout << "j = " << j << " cur = " << cur << endl;
        }
        if (j == k) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}

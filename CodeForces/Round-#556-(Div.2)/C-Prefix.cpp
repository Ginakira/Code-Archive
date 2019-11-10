#include <iostream>
#include <stack>
using namespace std;

int num[200001];
int main() {
    int n, sum = 0, one = 0, two = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> num[i];
        sum += num[i];
        if(num[i] == 1) one++;
        else two++;
    }
    
    return 0;
}
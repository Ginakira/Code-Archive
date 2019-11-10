#include <iostream>
#include <cmath>
using namespace std;

double life = 10, exps = 0;
bool alive = true;
int main() {
    int n;
    cin >> n;
    double life_cost, exp_add;
    for(int i = 0; i < n; ++i) {
        cin >> life_cost >> exp_add;
        if(life - life_cost > 0 && alive) {
            life -= life_cost;
            exps += exp_add;
            if(life > 10) life = 10;
        }
        else {
            alive = false;
        }
    }
    int level = 0;
    while(exps >= pow(2, level)) {
        exps -= pow(2, level++);
    }
    cout << level << ' ' << exps << endl;
    return 0;
}
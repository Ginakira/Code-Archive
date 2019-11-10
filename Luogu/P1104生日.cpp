#include <iostream>
#include <algorithm>
using namespace std;

struct Student {
    string name;
    int id, y, m, d;
};

Student stu[101];

bool cmp(Student a, Student b) {
    if(a.y == b.y) {
        if(a.m == b.m) {
            if(a.d == b.d) {
                return a.id > b.id;
            }
            return a.d < b.d;
        }
        return a.m < b.m;
    }
    else return a.y < b.y;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        stu[i].id = i;
        cin >> stu[i].name >> stu[i].y >> stu[i].m >> stu[i].d;
    }
    sort(stu, stu + n, cmp);
    for(int i = 0; i < n; ++i) {
        cout << stu[i].name << endl;
    }
    return 0;
}
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void get_n_m(const string &s, int &n, int &m) {
    string tmp;
    stringstream ss(s);
    getline(ss, tmp, ',');
    m = stoi(tmp.substr(2));
    getline(ss, tmp, ',');
    n = stoi(tmp.substr(2));
}

void get_nums(vector<int> &vec, int n, const string &s) {
    string tmp;
    stringstream ss(s);
    for (int i = 0; i < n; ++i) {
        getline(ss, tmp, ',');
        vec[i] = stoi(tmp);
    }
}

void merge_vec(vector<int> &vec_a, int m, vector<int> &vec_b, int n) {
    vec_a.resize(m + n);
    int cur = n + m - 1, ia = m - 1, ib = n - 1;
    while (cur > 0) {
        if (ib < 0 || (ia >= 0 && vec_a[ia] >= vec_b[ib])) {
            vec_a[cur] = vec_a[ia];
            --ia;
        } else {
            vec_a[cur] = vec_b[ib];
            --ib;
        }
        --cur;
    }
}

void output(const vector<int> &vec) {
    for (int num : vec) {
        cout << num << ' ';
    }
    cout << endl;
}

int main() {
    string tmp;
    cin >> tmp;
    int n, m;
    get_n_m(tmp, n, m);

    vector<int> vec_a(m), vec_b(n);
    cin >> tmp;
    get_nums(vec_a, m, tmp);
    cin >> tmp;
    get_nums(vec_b, n, tmp);

    merge_vec(vec_a, m, vec_b, n);
    output(vec_a);
    return 0;
}
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

constexpr int STOPPED = 0;
constexpr int RUNNING = 1;

void start_service(int id, vector<int> &status,
                   const vector<vector<int>> &requirements,
                   unordered_set<int> &finished) {
    if (finished.count(id)) return;
    status[id] = RUNNING;
    finished.insert(id);
    for (auto service_id : requirements[id]) {
        start_service(service_id, status, requirements, finished);
    }
}

void stop_service(int id, vector<int> &status,
                  const vector<vector<int>> &requirements,
                  unordered_set<int> &finished) {
    if (finished.count(id)) return;
    status[id] = STOPPED;
    finished.insert(id);
    for (auto service_id : requirements[id]) {
        stop_service(service_id, status, requirements, finished);
    }
}

int running_count(vector<int> &status) {
    return accumulate(status.begin(), status.end(), 0);
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> status(n + 1, STOPPED);
    vector<vector<int>> start_requirements(n + 1);
    vector<vector<int>> stop_requirements(n + 1);

    for (int i = 1; i <= n; ++i) {
        int c;
        cin >> c;
        for (int j = 0; j < c; ++j) {
            int id;
            cin >> id;
            start_requirements[i].push_back(id);
            stop_requirements[id].push_back(i);
        }
    }

    // query
    for (int i = 0; i < q; ++i) {
        int opt, id;
        cin >> opt >> id;
        unordered_set<int> finished;
        if (opt == 1) {
            start_service(id, status, start_requirements, finished);
        } else if (opt == 0) {
            stop_service(id, status, stop_requirements, finished);
        }
        int count = running_count(status);
        cout << count << endl;
    }
    return 0;
}
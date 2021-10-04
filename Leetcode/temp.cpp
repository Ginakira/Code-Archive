#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <utility>
using namespace std;

void func1(int &n, mutex &m, const string &thread_name) {
    for (int i = 0; i < 25; ++i) {
        lock_guard<mutex> lg(m);
        ++n;
        cout << "Thread " << thread_name << " executing. Current " << n << endl;
    }
}

int main() {
    int n = 0;
    mutex m;
    thread t1(func1, ref(n), ref(m), "Thread 1");
    thread t2(func1, ref(n), ref(m), "Thread 2");
    thread t3(func1, ref(n), ref(m), "Thread 3");
    thread t4(func1, ref(n), ref(m), "Thread 4");
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    cout << n << endl;
    return 0;
}
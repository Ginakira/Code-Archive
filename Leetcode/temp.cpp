#include <algorithm>
#include <chrono>
#include <future>
#include <iostream>
#include <thread>
using namespace std;
using namespace std::chrono;

int foo(int num) {
    cout << "Thread start sleep for 5s...\n";
    this_thread::sleep_for(seconds(5));
    return num * 100;
}

int main() {
    packaged_task<int(int)> pt(foo);
    auto fu = async(bind(foo, 10));

    thread t(move(pt), 10);
    cout << "Main before get value from prom\n";
    int ret = 0;
    ret = fu.get();
    if (ret) {
        cout << "Got value: " << ret << "\n";
    } else {
        cout << "Not got\n";
    }
    t.join();
    cout << "After join\n";

    return 0;
}
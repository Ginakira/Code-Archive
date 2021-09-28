#include <iostream>

using namespace std;

template <int k>
struct Bigger {
    static constexpr const char* en = (k >= 60 ? "yes" : "no");
};

int main() { return 0; }
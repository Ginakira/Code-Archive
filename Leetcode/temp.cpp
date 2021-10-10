#include <iostream>
using namespace std;

template <typename T, typename L>
void foo(T v, L l) {
    cout << "type ?, value " << v << ", size of letter " << sizeof(l)
         << ", letter " << l << endl;
}

template <typename T, typename L>
void foo(float v, L l) {
    cout << "type float, value " << v << ", size of letter " << sizeof(l)
         << ", letter " << l << endl;
}

template <typename T, typename L>
void foo(double v, L l) {
    cout << "type double, value " << v << ", size of letter " << sizeof(l)
         << ", letter " << l << endl;
}

int main() {
    float f = 2;
    double d = 3;
    char l = 'a';
    foo<float>(f, l);
    foo<double>(d, l);
    return 0;
}

/************************************************************
    File Name : 34.turning.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/13 14:25:55
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Even
template <int n>
struct IsEven {
    static constexpr int r = !(n % 2);
};

// Add
template <int a, int b>
struct Add {
    static constexpr int r = (a + b);
};

// Sum
template <int n>
struct Sum {
    static constexpr int r = n + Sum<n - 1>::r;
};

template <>
struct Sum<0> {
    static constexpr int r = 0;
};

// Factorial
template <int n>
struct Factorial {
    static constexpr int r = n * Factorial<n - 1>::r;
};

template <>
struct Factorial<0> {
    static constexpr int r = 1;
};

// IsPrime
template <int n, int i>
struct getNextN {
    static constexpr int r = (i * i > n ? 0 : n);
};

template <int n, int i>
struct getNextI {
    static constexpr int r = (n % i == 0 ? 0 : i + 1);
};

template <int n, int i>
struct IsTest {
    static constexpr int r = IsTest<getNextN<n, i>::r, getNextI<n, i>::r>::r;
};

template <int i>
struct IsTest<0, i> {
    static constexpr int r = 1;
};

template <int n>
struct IsTest<n, 0> {
    static constexpr int r = 0;
};

template <int i>
struct IsTest<2, i> {
    static constexpr int r = 1;
};

template <int n>
struct IsPrime {
    static constexpr int r = IsTest<n, 2>::r;
};
/* Another way:
    template<int n, int m>
    struct Check{
        static constexpr bool r = (n%m != 0) && Check<n, m-1>::r;
    };

    template<int n>
    struct Check<n, 2>{
        static constexpr bool r = (n%2 != 0);
    };


    template<int n>
    struct IsPrime{
        static constexpr int r = Check<n, (int)sqrt(n)>::r;
    };
*/

// SumPrime
template <int n>
struct SumPrime {
    static constexpr int r = (n * IsPrime<n>::r + SumPrime<n - 1>::r);
};

template <>
struct SumPrime<1> {
    static constexpr int r = 0;
};

// 输出n以内所有素数

int main() {
    cout << IsEven<123>::r << endl;
    cout << IsEven<124>::r << endl;

    cout << Add<123, 456>::r << endl;
    cout << Add<-123, -456>::r << endl;

    cout << Sum<10>::r << endl;
    cout << Sum<100>::r << endl;

    cout << Factorial<5>::r << endl;
    cout << Factorial<10>::r << endl;

    cout << IsPrime<9973>::r << endl;
    cout << IsPrime<87>::r << endl;
    cout << IsPrime<1537>::r << endl;
    cout << IsPrime<65>::r << endl;

    cout << SumPrime<10>::r << endl;
    cout << SumPrime<40>::r << endl;
    return 0;
}
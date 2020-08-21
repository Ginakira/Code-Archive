/************************************************************
    File Name : 40.shared_ptr.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/20 15:29:48
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace haizei {
template <typename T>
class shared_ptr {
   public:
    shared_ptr() : ptr(nullptr), pcnt(nullptr) {}
    shared_ptr(T *ptr) : ptr(ptr), pcnt(new int(1)) {}
    shared_ptr(const shared_ptr<T> &p) : ptr(p.ptr), pcnt(p.pcnt) {
        *pcnt += 1;
    }
    shared_ptr<T> &operator=(shared_ptr<T> &p) {
        this->use_count_des();
        this->ptr = p.ptr;
        this->pcnt = p.pcnt;
        *pcnt += 1;
        return *this;
    }
    int use_count() { return (pcnt ? *pcnt : 0); }
    T &operator*() { return *(this->ptr); }
    T *operator->() { return this->ptr; }
    ~shared_ptr() { this->use_count_des(); }

   private:
    void use_count_des() {
        if (pcnt) {
            *pcnt -= 1;
            if (*pcnt == 0) {
                delete pcnt;
                delete ptr;
            }
        }
        return;
    }
    T *ptr;
    int *pcnt;
};

class A {
   public:
    A() : x(123), y(456) { cout << this << " constructor" << endl; }
    int x, y;
    ~A() { cout << this << " destructor" << endl; }
    haizei::shared_ptr<A> p;
};

}  // end of namespace haizei

int main() {
    haizei::shared_ptr<haizei::A> p(new haizei::A()), q = p;
    haizei::shared_ptr<haizei::A> k(new haizei::A());
    cout << p->x << " " << p->y << endl;
    cout << q->x << " " << q->y << endl;
    cout << p.use_count() << endl;  // 2
    q = k;
    cout << p.use_count() << endl;  // 1
    // p = k;
    // cout << p.use_count() << endl;
    p->p = k;
    k->p = p;
    return 0;
}

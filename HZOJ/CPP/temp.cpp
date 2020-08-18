#include <functional>
#include <iostream>
using namespace std;

int add(int a, int b) { return a + b; }

struct maxclass {
    int operator()(int a, int b) { return a > b ? a : b; }
};

namespace haizei {

template <typename RT, typename... PARAMS>
class function {};
template <typename RT, typename... PARAMS>
class function<RT(PARAMS...)> {
   public:
    function(RT (*func)(PARAMS...)) : ptr(nullptr) {
        cout << "normal function constr" << endl;
    }
    template <typename T>
    function(T &&a) : ptr(nullptr) {
        cout << "class object function constr" << endl;
    }
    ~function() { delete ptr; }

   private:
    int *ptr;
};

};  // namespace haizei

int main() {
    maxclass max1;
    haizei::function<int(int, int)> g1(add);
    haizei::function<int(int, int)> g2(max1);
    haizei::function<int(int, int)> g3(maxclass{});
    return 0;
}
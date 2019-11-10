#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
	auto s = 1.7666666;
	cout << s << endl;
	cout << typeid(s).name() << endl;
	return 0;
}
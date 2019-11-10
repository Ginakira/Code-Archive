#include<iostream>
using namespace std;

template <typename type>
void swap1(type &a, type &b) {
	type t;
	t = a;
	a = b;
	b = t;
}

int main() {
	int a, b;
	cin>>a>>b;
	swap1 <int> (a,b);
	cout<<a<<" "<<b;
	return 0;
}


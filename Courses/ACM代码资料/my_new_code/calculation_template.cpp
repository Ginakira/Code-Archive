#include<iostream>
#include<stdlib.h>
using namespace std;
template <class type> 
class calculation {
	public:
		type add(type x, type y);
		type minus(type x, type y);
		type multiply(type x, type y);
		type divide(type x, type y);
};
template <class type>
type calculation<type>::add(type x, type y) {
	return x + y;
}
template <class type> 
type calculation<type>::minus(type x, type y) {
	return x - y;
}
template <class type>
type calculation<type>::multiply(type x, type y) {
	return x * y;
}
template <class type>
type calculation<type>::divide(type x, type y) {
	return x / y;
}
int main() {
	calculation <float> as;
	float a, b;
	cin>>a>>b;
	cout<<as.add(a,b) ; 
	return 0;
}

#include<iostream>
#include<stdlib.h>
using namespace std;
template <class type>
class stack {
	private:
		type *top;
		type *base;
		int stacksize;
	public:
		void init();
		void push(type e);
		void pop();
		type gettop();
		int empty();
		int getlen();
		void destory();
};
template <class type>
void stack<type>::init() {
	base = (type*)malloc(sizeof(type));
	if(!base) {
		exit(0);
	}
	top = base;
	stacksize = 1;
}
template <class type>
void stack<type>::push(type e) {
	type *p;
	if(top - base >= stacksize) {
		p = (type*)realloc(base,(stacksize + 1) * sizeof(type));
		if(!p) {
			exit(0);
		}
		base = p; 
		top = base + stacksize;
		stacksize++;
	}
	*top = e;
	top++;
} 
template <class type>
void stack<type>::pop() {
	if(top == base) {
		return ;
	}
	--top;
}
template <class type>
type stack<type>::gettop() {
	if(base == top) {
		return 0;
	}
	type e;
	e = *(top - 1);
	return e;
}
template <class type>
int stack<type>::empty() {
	return top == base;
}
template <class type>
int stack<type>::getlen() {
	return top - base;
}
template <class type>
void stack<type>::destory() {
	if(!stacksize) {
		exit(0);
	}
	free(base);
}
int main() {
	int n;
	char num;
	cin>>n;
	stack <char> q;
	q.init() ;
	while(n--) {
		cin>>num;
		q.push(num); 
	}
	while(!q.empty() ) {
		cout<<q.gettop() <<" ";
		q.pop() ;
	}
	q.destory() ;
	return 0;
}


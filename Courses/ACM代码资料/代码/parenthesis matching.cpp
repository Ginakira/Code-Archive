#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<string.h>
using namespace std;
class _stack {
	private:
		char *top;
		char *base;
		int s;
	public:
		int init();
		int _push(char c);
		int _pop();
		char _top();
		int _empty();
		int destroy();
};
int _stack::init() {
	base = (char*)malloc(sizeof(char));
	top =  base;
	s= 0;
	return 1;
}
int _stack::_push(char c) {
	char *p;
	if(top - base >= s) {
		p = (char*)realloc(base,(s + 1) * sizeof(char));
		base = p;
		top = base + s;
		s++;
	}
	*top = c;
	top++;
	return 1;
} 
int _stack::_pop() {
	if(top == base) {
		return 0;
	}
	--top;
	return 1;
	
}
char _stack::_top() {
	if(top == base) {
		return 0;
	}
	return *(top - 1);
}
int _stack::_empty() {
	return (top == base);
}
int _stack::destroy() {
	if(!s) {
		exit(0);
	}
	free(base);
	s = 0;
	return 1;
}
int main() {
	_stack q;
	q.init() ;
	char c;
	c = getchar();
	while(c != '@' ) {
		if(c == '(') {
			q._push(c); 
		}
		if(c == ')') {
			if(q._empty() ) {
				cout<<"NO"<<endl;
				return 0;
			}
			q._pop() ;
		}
		c = getchar();
	}
	if(q._empty() ) {
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}
	return 0;
}
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class sqlist {
	private:
		int *elem;
		int length;
		int size;
	public:
		int init();
		int creat(int n);
		int destroy();
		int _push(int i, int e);
		int _pop(int i);
		int getlen();
		int getelem(int i);
		int find(int e);
};
int sqlist::find {
	for(int i = 0;i < length;++i) {
		if(e == elem[i]) {
			return i;
		}
	}
	return -1;
}
int sqlist::creat(int n) {
	for(int i = 0;i < n;++i) {
		cin>>elem[i];
		length++;
		size++;
	}
	return 1;
} 
int sqlist::destroy() {
	free(elem);
	length = 0;
	size = 0;
	return 1;
}
int sqlist::init() {
	elem = (int*)malloc(sizeof(int));
	if(!elem ) {
		exit(0);
	}
	length = 0;
	size = 0;
	return 1;
}
int sqlist::_push(int i, int e) {
	int *p = NULL, *q = NULL, *newbase = NULL;
	if(i < 1 || i > length + 1) {
		return 0;
	}
	if(length >= size ) {
		newbase = (int*)realloc(elem,sizeof(int));
		if(!newbase) {
			exit(0);
		}
		elem = newbase;
		size++;
	}
	q = &(elem[i-1]);
	for(p = &(elem[length - 1]);p >= q;--p) {
		*(p + 1) = *p;
	}
	*q = e;
	length ++;
	return 1;
} 
int sqlist::_pop(int i) {
	int *p, *q;
	if(i < 1 || i > length ) {
		return 0;
	}
	q = &(elem[i-1]);
	p = elem + length - 1;
	for(++q;q <= p;++q) {
		*(q-1) = *q;
	}
	length --;
	return 1;
} 
int sqlist::getlen() {
	return length ;
}
int sqlist::getelem(int i) {
	return elem[i]; 
}
int main() {
	int n = 4;
	sqlist q;
	q.init() ;
	q.creat(n);  
	cout<<q.getlen() <<endl;
	for(int i = 0;i < q.getlen() ;++i) {
		cout<<q.getelem(i) <<" ";
	}
	q.destroy() ;
	cout<<endl;
	return 0;
}

#include<iostream>
#include<stdlib.h>
using namespace std;
template <class type>
struct node {
	type data;
	node <type> *next;
};
template <class type>
class linkqueue {
	private:
		node <type> *front;
		node <type> *rear;
	public:
		void init();
		void _push(type e);
		void _pop();
		type _top();
		int _empty();
		void destory();
};
template <class type>
void linkqueue<type>::init() {
	front = (node<type>*)malloc(sizeof(node<type>));
	if(!front) {
		exit(0);
	}
	front -> next = NULL;
	rear = front;
	return ;
}
template <class type>
void linkqueue<type>::_push(type e) {
	node <type> *p;
	p = (node<type>*)malloc(sizeof(node<type>));
	if(!p) {
		exit(0);
	}
	p -> data = e;
	p -> next = NULL;
	rear -> next = p;
	rear = p;
	return ;
} 
template <class type>
void linkqueue<type>::_pop() {
	node <type> *p;
	if(front == rear) {
		return ;
	}
	p = front -> next;
	front -> next = p -> next;
	if(p == rear) {
		rear = front;
	}
	free(p);
	return;
}
template <class type>
type linkqueue<type>::_top() {
	type e;
	if(front == rear) {
		return 0;
	}
	e = front -> next -> data;
	return e;
}
template <class type>
int linkqueue<type>::_empty() {
	return rear == front;
}
template <class type>
void linkqueue<type>::destory() {
	while(front) {
		rear = front -> next;
		free(front);
		front = rear;
	}
}
int main() {
	int n;
	cin>>n;
	int num;
	linkqueue <int> q;
	q.init() ;
	while(n--) {
		cin>>num;
		q._push(num); 
	}
	while(!q._empty() ) {
		cout<<q._top() <<" ";
		q._pop() ;
	}
	q.destory() ;
	return 0;
}

#include<iostream>
#include<stdlib.h>
using namespace std;
struct node {
	int data;
	struct node* next;
};
class linkqueue {
	private:
		node *front;
		node *rear;
	public:
		int init();
		int _push(int e);
		int _pop();
		int _top();
		int _empty();
		int destory();
};
int linkqueue::init() {
	front = (node*)malloc(sizeof(node));
	if(!front) {
		exit(0);
	}
	front -> next = NULL;
	rear = front;
	return 1;
}
int linkqueue::_push(int e) {
	node *p;
	p = (node*)malloc(sizeof(node));
	if(!p) {
		exit(0);
	}
	p -> data = e;
	p -> next = NULL;
	rear -> next = p;
	rear = p;
	return 1;
} 
int linkqueue::_pop() {
	node *p;
	if(front == rear) {
		return 0;
	}
	p = front -> next;
	front -> next = p -> next;
	if(p == rear) {
		rear = front;
	}
	free(p);
	return 1;
}
int linkqueue::_top() {
	int e;
	if(front == rear) {
		return 0;
	}
	e = front -> next -> data;
	return e;
}
int linkqueue::_empty() {
	if(front == rear) {
		return 1;
	} else {
		return 0;
	}
}
int linkqueue::destory() {
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
	linkqueue q;
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

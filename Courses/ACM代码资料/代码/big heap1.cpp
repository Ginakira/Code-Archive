#include<iostream>
#define max 10000000
using namespace std;
int size = 0, heap[max];
void swap(int *a, int *b) {
	int *c;
	c = a;
	a = b;
	b = c;
}
void _push(int e){
    heap[++size] = e;
    int son = size, father = son / 2;
    while(heap[son] > heap[father] && father >= 1){
        swap(heap[son],heap[father]);
        son = father,father = son / 2;
    }
}
void _pop(){
    swap(heap[1],heap[size]);
    heap[size--]=0;
    int father=1,son=2;
    while(son<=size){
        if(son<size && heap[son]<heap[son+1]) son++;
        if(heap[father]<heap[son]){
            swap(heap[father],heap[son]);
            father=son,son=father*2;
        }else break;
    }
}
int _top(){
    return heap[1];
}
int main() {
	int n = 10;
	while(n--) {
		int a;
		cin>>a;
		_push(a);
	}
	while(size) {
		cout<<_top()<<" ";
		_pop();
	}
	return 0;
}


#include<iostream>
#define maxn 10000000
using namespace std;
void swap(int *a, int *b) {
	int *c = a;
	a = b;
	b = c;
}
int n ,heap[maxn],size = 0;
void up(int p) {
  while(p > 1) {
    if(heap[p] < heap[p / 2]) {
      swap(heap[p],heap[p / 2]);
      p /= 2;
    } else {
    	break;
	}
  }
}
void insert(int val) {
  heap[++size] = val;
  up(size);
}
void down(int p) {
  int s = p * 2;
  while(s <= size) { 
    if(s < size && heap[s+1] < heap[s]) {
    	s++;
	} 
    if(heap[s] < heap[p]) {
      swap(heap[s],heap[p]);
      p = s;
	  s = p * 2;
    } else {
    	break;
	}
  }
}
void extract() {
  heap[1] = heap[size--];
  down(1);
}
int gettop() {
  return heap[1];
}
int main() {
  cin>>n;
  for(int i=0; i<n; i++) {
    int a; 
	cin>>a;
    insert(a); 
  }
  while(size) {
  	cout<<gettop()<<" ";
  	extract() ;
  }
  cout<<endl;
  return 0;
}

#include<iostream>
#include<stdlib.h>
using namespace std;
struct node {
	int data;
	node *next;
};
class linklist {
	private:
		node *head;
	public:
		int init();
		int destroy();
		int creat(int n);
		int insert(int i, int e);
		int del(int i);
		int getelem(int i);
		int find(int e);
		int getlen();
		void display();
		int _empty();
};
int linklist::_empty() {
	return (head -> next == NULL);
}
void linklist::display()  {
	  node *p;
      p = head->next;
      while(p) {
        cout<<p->data<<" ";
        p = p->next;
      }
      cout<<endl;
}
int linklist::getlen() {
	  int len = 0;
      node *p;  
      p = head;     
      while(p->next) {
        len++;
        p = p->next;
      }
      return len;  
}
int linklist::find(int e) {
	  int j = 1;
      node *p;
      p = head -> next;
      while(p && p -> data != e) {
        p = p->next;
        j++;
      }
      if(!p ) {
          return 0;
      } else {
          return j;
      }
      return 1;
} 
int linklist::getelem(int i) {
	  node *p;     
      p = head -> next; 
      int j = 1;    
      while(p && j < i) {
          p = p->next;
          j++;
      }
      if(!p || j>i){
          exit(0);
      } else {
         return p->data;
      }
      return 1;
} 
int linklist::del(int i) {
	 	int e;
        node *p, *q;
        p = head;  
        int j = 0; 
        while(p -> next && j < i - 1) {
          p = p->next;
          j++;
        }
        if(!p->next || j>i-1) {
        	exit(0);
		} else {
          q = p->next;      
          p->next = q->next;
          e = q->data;      
          delete q;         
          return e;         
        }
        return 1;
} 
int linklist::insert(int i, int e) {
	  int j = 0;
      node *p;
      p = head;        
      while(p && j < i - 1) {
        p = p -> next;
        j++;
      }
      if(!p || j > i - 1) {
      	exit(0);
	  } else {
        node *s;
        s = new node(); 
        s->data = e;
        s->next = p->next;
        p->next = s;
      }
      return 1;
} 
int linklist::creat(int n) {
	node *p,*s;  
    p = head;
    for(int i = 0;i < n;i++) {
        s = new node();  
        cin>>s -> data;      
        s -> next = p -> next; 
        p -> next = s;
        p = s;             
      }
      return 1;
} 
int linklist::init() {
	head = new node();
	head -> next = NULL;
	return 1;
}
int linklist::destroy() {
	node *p;
	while(head) {
		p = head;
		head = head -> next;
		delete p;
	}
	head = NULL;
	return 1;
}
int main() {
	linklist q;
	q.init() ;
	q.creat(5);
	q.display() ;
	q.destroy() ; 
	return 0;
}

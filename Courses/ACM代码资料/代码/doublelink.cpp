 #include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct node {
	int data;
	node *pre;
	node *next; 
};
class dlink {
	private:
		node *l;
		int len;
	public:
		int init();
		int creat(int n);
		int destroy();
		int del_vaule(int e);
		int display();
		int insertback_value(int e, int k);
		int insertbefore_value(int e, int k);
		int insert_subscript(int i, int e);
		int del_subscript(int i);
		node *locate(int e);
		int gethead();
		int gettail();
		int creathead(int e);
		int creattail(int e);
		int getlen();
};
int dlink::getlen() {
	return len;
}
int dlink::creattail(int e) {
	node *p = new node();
	node *last = l;
	p -> data = e;
	p->next = NULL;
	if (last == NULL) {
		p->pre = NULL;
		last = p;
		return 1;
	}
	while (last -> next != NULL) {
		last = last -> next;
	}
	last -> next = p;
	p->pre = last;
	len++;
	return 1;
} 
int dlink::creathead(int e) {
	node *p = new node();
	p -> data = e;
	p->next = l;
	p->pre = NULL;
	if(l != NULL) {
		l -> pre = p;
	}
	l = p;
	len++;
	return 1;
} 
int dlink::gethead() {
	return l -> data;
}
int dlink::gettail() {
	node *p = l;
	while(p -> next) {
		p = p -> next;
	}
	return p -> data;
}

int dlink::insertbefore_value(int e, int k) {
	node *p, *s;
    p = locate(e);
	if(!p) {
		return 0;
	}
	s = new node();
	s -> data = k;
	s->pre  = p->pre ;
	p->pre = s;
	s->next =p;
	if (s->pre  != NULL)
		s->pre ->next = s;
	len++;
	return 1;
} 
int dlink::insertback_value(int e, int k) {
	node *p, *s;
    p = locate(e);
	if(!p) {
		return 0;
	}
	s = new node();
 	s -> data = k;
	s->next = p->next;
	p->next = s;
	s->pre = p;
	if (s->next != NULL) {
		s->next->pre = s;
	}
	len++;
	return 1;
} 
int dlink::display() {
	node *p = l;
	while(p -> next) {
		cout<<p -> data<<" ";
		p = p -> next;
	}
	cout<<p -> data;
	return 1;
}
int dlink::insert_subscript(int i, int e) {
	int j = 0;
	if(i < 1 || i > len + 1) {
		return 0;
	}
	node *p = l;
	while(p && j < i - 1) {
		p = p -> next;
		j++;
	}
	if(!p || j > i - 1) {
		return 0;
	} else {
		node *s = new node();
		s -> data = e;
		s -> pre = p -> pre;
		p -> pre -> next = s;
		s -> next = p;
		p -> pre = s;
	}
	len++;
	return 1;
} 
int dlink::del_vaule(int e) {
	node *p1, *p2;  
    p1 = l;  
    while (p1->next && e != p1->data) {  
        p1=p1->next;  
    }  
    if (e == p1->data) {  
        if (p1 == l) {
            l = l->next;  
            l -> pre = NULL;  
        } else if(p1->next) {  
            p1->next->pre = p1->pre;  
            p1->pre->next=p1->next;  
        } else {  
            p1 -> pre -> next = NULL;  
            free(p1);  
        }  
    } 
    len--;
    return 1;  
} 
int dlink::destroy() {
	node *p;
    while(l) {  
	  p = l->next; 
	  free(l);
	  l = p;
   }
   len = 0;
	return 1;
}
int dlink::init() {
	l = new node();
	l -> next = l;
	l -> pre = l;
	return 1;
}
int dlink::creat(int n) {
	node *p, *s;
	p = l;
    for(int i = 0;i < n;i++) {		
		s = new node();
		s -> data = i + 1;
		p->next = s;
		s->pre = p;
		p = s;
	}
	p -> next = NULL;
	l = l -> next;
	l -> pre = NULL;
	len = n;
	return 1;
} 
node *dlink::locate(int e) {
	node *p;
    p = l;
    while((p -> next) != l && p){
	  	if(e == p -> data) {
	  		return p;
		  }
		p = p->next;
  }
  return NULL;
} 
int dlink::del_subscript(int i) {
	if(i < 1 || i > len) {
		return 0;
	}
	int j = 1;
	node *p = l -> next;
	while((p) && j < i ) {
		 p = p -> next;
		 j++;
	}
	if(!p || j > i - 1) {
		return 0;
	} else {
		p -> pre -> next = p -> next;
		p -> next -> pre = p -> pre;
	}
	len--;
	int num = p -> data;
	delete p;
	return 1;
} 
int main() {
	dlink q;
	q.init() ;
	q.creat(5); 
	//在头结点前插入用creathead 
	q.del_subscript(5); 
	q.display();
	cout<<endl;
	//del_subscript未完成 
	cout<<q.getlen() <<endl;
	q.destroy();
	return 0;
}


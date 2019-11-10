#include<iostream>
#include<queue>
using namespace std;
typedef struct node{
      char data;
      node *lchild, *rchild;
  }BiNode,*BiTree;
BiTree create(){
     char ch;
     BiTree T;
     cin>>ch;
    if(ch=='#'){
        T=NULL;
     }else{
         T=new BiNode;
         T->data=ch;
         T->lchild=create();
         T->rchild=create();
     }
     return T;
 }
void visit(BiTree T){
     cout<<T->data;
 }
void xianxu(BiTree T) {
 	if(T == NULL) {
 		return;
	 } else {
	    visit(T);
	   	xianxu(T -> lchild );
	 	xianxu(T -> rchild );
	 }
 }
void zhongxu(BiTree T) {
 	if(T == NULL) {
 		return;
	} else {
	    zhongxu(T -> lchild );
	 	visit(T);
	 	zhongxu(T -> rchild );
		 
	}
}
void houxu(BiTree T) {
 	if(T == NULL) {
 		return;
	} else {
	   	houxu(T -> lchild );	
	 	houxu(T -> rchild );
	 	visit(T);
		 
	}
}
void chengchi(BiTree T){
     queue<BiTree>q;
     q.push(T);
     BiTree p;
     while(!q.empty()){
         cout<<q.front()->data;
         p=q.front();
         q.pop();
         if(p->lchild!=NULL){q.push(p->lchild);
         }
         if(p->rchild!=NULL){q.push(p->rchild);
         }
     }
}
int destroy(BiTree  T) {
 	if(T != NULL) {
 		destroy(T -> lchild);
 		destroy(T -> rchild);
 		 delete T;
	 }
	 return 1;
 }
 int main(){
     BiTree Tree=create();
     xianxu(Tree);
     cout<<endl;
     zhongxu(Tree);
     cout<<endl;
     houxu(Tree);
     destroy(Tree);
     return 0;
} 


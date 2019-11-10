#include <stdio.h>
#include <stdlib.h>
typedef struct tree{
	struct tree *lchild,*rchild;
	int data;
}*BiTree,BiNode;
 
void Insert(BiTree bt,int data)
{//关键字的插入 
	BiTree p,s,parent;
	p=bt;
	while(p)
	{
		if(data<p->data)
		{
			parent=p;
			p=p->lchild;
		}
		
		else if(data>p->data)
		{
			parent=p;
			p=p->rchild;
		}
		else
			return ;
	}
	
	s=(BiTree)malloc(sizeof(BiNode));
	s->data=data;
	s->lchild=s->rchild=NULL;
	if(s->data<parent->data)
		parent->lchild=s;
	else
		parent->rchild=s;
}
 
void InitTree(BiTree &bt,int n)
{//建立二叉排序树 
	int data,i;
	scanf("%d",&data);
	bt=(BiTree)malloc(sizeof(BiNode));
	bt->data=data;
	bt->lchild=bt->rchild=NULL;
	for(i=1;i<n;i++)
	{
		scanf("%d",&data);
		Insert(bt,data);
	}
}
 
void InOrder(BiTree bt)
{//树的中序遍历 
	if(!bt)
		return ;
 
	InOrder(bt->lchild);
	printf("%d ",bt->data);
	InOrder(bt->rchild);
}
 
int Search(BiTree bt,int key)
{
	BiTree p;
	p=bt;
	while(p)
	{
		if(key<p->data)
			p=p->lchild;
		else if(key>p->data)
			p=p->rchild;
		else
		{
			printf("数字%d查找成功。\n",key);
			return 1;
		}
	}
	printf("未找到数据%d。\n",key); 
	return 0;
}
 
void Delete_BiTree(BiTree &bt,int key)
{
	BiTree p,cur,par;
	p=bt;
	while(p){
		if(key==p->data)
			break;
		else if(key<p->data){
			par=p;
			p=p->lchild;
		}
		else{
			par=p;
			p=p->rchild;
		}	
	}
	
	if(!p){
		printf("该数据不存在.\n");
		return ;
	}
	
	if(!p->lchild)		//没有左子树 
	{
		if(p==bt)
			bt=p->rchild; 
		else if(par->lchild==p)
			par->lchild=p->rchild;
		else
			par->rchild=p->rchild;
		free(p);
	}
	
 
	else
	{
		cur=p->lchild;
		par=cur;
		while(cur->rchild)
		{
			par=cur;
			cur=cur->rchild;
		}
		
		if(par==p->lchild)			//p的左孩子没有右子树 
		{
			p->data=par->data;
			p->lchild=par->lchild;
			free(par);
		}
		else						//p的左孩子有右子树 
		{
			p->data=cur->data;
			par->rchild=cur->lchild;
			free(cur);
		}
	}
	printf("删除成功.\n");
}
 
 
int main()
{
	BiTree bt;
	int n,key,selet;	
	while(1)
	{
		printf("		------------------\n");
		printf("		1、建立二叉排序树\n");
		printf("		2、输出中序遍历结果\n");
		printf("		3、搜索数据\n");
		printf("		4、删除数据\n");
		printf("		5、插入数据\n");
		printf("		6、退出\n"); 
		printf("		------------------\n");
		
		scanf("%d",&selet);
		switch(selet)
		{
			case 1:
				printf("输入数字的个数:");
				scanf("%d",&n);
				printf("请输入每个数字:");
				InitTree(bt,n);
				break;
			case 2:	
				printf("中序遍历结果为：");
				InOrder(bt);
				putchar('\n');
				break;
			case 3:
				printf("请输入查找的关键字：");
				scanf("%d",&key);
				Search(bt,key);
				break;
			case 4:
				printf("请输入删除的关键字：");
				scanf("%d",&key);
				Delete_BiTree(bt,key);
				break;
			case 5:
				printf("请输入要插入的数据：");
				scanf("%d",&key); 
				Insert(bt,key);
				printf("插入成功.\n");
				break;
			default:
				return 0;
		}
	}
}


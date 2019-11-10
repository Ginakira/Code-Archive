#include<iostream>

using namespace std;

/*
https://www.cnblogs.com/xzxl/p/7226557.html

解释的非常有趣 
*/
int pre[10010];
int find(int k){
    if(pre[k] == k) {
    	return k;
	}
    return pre[k] = find(pre[k]);
}
void join(int x,int y) {
    int prex = find(x), prey = find(y);            
    if(prex != prey)                             
        pre[prex] = prey;                      
}
int main() {
    for(int i = 1;i <= 100;i++) { //初始化  每个人都是自己的掌门 
    	pre[i] = i;
	}
    join(2,3);
    return 0;
}

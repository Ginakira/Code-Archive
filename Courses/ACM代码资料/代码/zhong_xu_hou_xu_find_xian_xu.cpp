#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
void dfs(string a,string b){
    if (a.size() > 0){
        char ch = b[b.size() - 1];
        cout<<ch;
        int k = a.find(ch);
        dfs(a.substr(0,k),b.substr(0,k));
        dfs(a.substr(k+1),b.substr(k,a.size()-k-1));
    }
}
int main(){
    string a, b;
    cin>>a;
	cin>>b;
    dfs(a,b);
	cout<<endl;
    return 0;
}
//a.substr(0,k)
//获得字符串s中 从第0位开始的长度为k的字符串 // 默认时的长度为从开始位置到尾

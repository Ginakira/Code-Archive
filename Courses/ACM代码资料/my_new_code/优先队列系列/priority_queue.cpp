#include <iostream>
#include <queue> 
using namespace std; 
int main(){
	//priority_queue <int, vector<int>,greater<int> > p; //从小到大 
    priority_queue <double> q;
	int n;
	cin>>n;
	while(n--) {
		double a;
		cin>>a;
		q.push(a);
	}
	while(!q.empty()) {
		cout<<q.top()<<endl;
		q.pop();
	}
	system("pause");
    return 0;
}


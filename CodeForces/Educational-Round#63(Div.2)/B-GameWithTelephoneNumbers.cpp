#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
int main(){
	int n;
	size_t pos;
	int v, p;
	cin >> n;
	cin >> s;
	int cnt;
	cnt = n - 11;
	if(cnt % 2 == 0){
		v = cnt / 2;
		p = cnt / 2;
	} 
	else{
		v = cnt / 2 + 1;
		p = cnt / 2;
	}
	int flag = 0;
	flag = count(s.begin(), s.end(), '8');
	if(flag <= p){
		cout << "NO" << endl;
		return 0;
	} 
	else{
		for(int i = 0; i < p; i++){
			pos = s.find('8');
			s = s.erase(pos, 1);
		}
		pos = s.find('8');
		if(pos > v){
			cout << "NO" << endl;
			return 0;
		}
		else{
			cout << "YES" << endl;
		}
	}
    return 0;
}
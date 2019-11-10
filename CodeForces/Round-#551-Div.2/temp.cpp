/*************************************************************************
	> File Name: temp.cpp
	> Author: 坂田银串
	> Mail: ginakira@foxmail.com
	> Created Time: 2019年04月15日 星期一 23时11分09秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
    int time[10001];
    int flag = 0;
    int bus, at, t1, t2;
    cin >> bus >> at;
    int temp = 0;
    for(int i = 1; i <= bus; i++){
        cin >> t1 >> t2;
        if(temp > t1){
            temp = t1;
            flag = i;
        }
        time[i] = t1 + t2;
    }
    for(int i = 1; i <= bus; i++){
        if(time[i] < temp){
            temp = time[i];
            flag = i;
        }
    }
    cout << flag << endl;
    return 0;
}

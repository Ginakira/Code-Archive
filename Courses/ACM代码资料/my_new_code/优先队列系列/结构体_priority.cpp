#include <iostream>
#include <queue>
using namespace std;
 
struct Node{
    int value;
    int key;
    Node(int x,int y):key(x),value(y){} //³õÊ¼»¯¸³Öµ 
};//p[10]
 
struct cmp{
    bool operator()(Node a,Node b){
        if(a.key == b.key){
            return a.value > b.value;
        }
        return a.key > b.key;
    }
};
 
int main(){
 
    priority_queue<Node,vector<Node>,cmp> heap;
    /*
	for(int i = 0;i < 5;++i) {
    	cin>>p[i].key >>p[i].value ;
    	heap.push(p[i]); 
	}
	*/
    Node node0(5,6);
    Node node1(3,3);
    Node node2(2,4);
    Node node3(2,3);
    Node node4(1,3);
 
    heap.push(node0);
    heap.push(node1);
    heap.push(node2);
    heap.push(node3);
    heap.push(node4);
 
    while(!heap.empty()){
        Node node = heap.top();
        cout<<"Key->"<<node.key<<" Value->"<<node.value<<endl;
        heap.pop();
    }
}


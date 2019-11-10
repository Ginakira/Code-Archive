#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;

template <class type>
class priority_queue {
    private:
        vector<type> data;         
    public:
        void push(type t){ 
            data.push_back(t); 
            push_heap( data.begin(), data.end()); 
        }         
        void pop(){
            pop_heap( data.begin(), data.end() );
            data.pop_back();
        }         
        type top() { return data.front(); }
        int size() { return data.size(); }
        bool empty() { return data.empty(); }
};  

int main() {
    priority_queue <int> test; 
    test.push( 3 );
    test.push( 5 );
    test.push( 2 );
    test.push( 4 );     
    while( !test.empty() ){
        cout << test.top() << endl;
        test.pop(); 
    }         
    return 0; 
}


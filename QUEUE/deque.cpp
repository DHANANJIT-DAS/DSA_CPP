#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> dq;
    dq.push_front(2);
    dq.push_back(3);
    dq.push_back(4);
    dq.push_front(1);
    while(!dq.empty()){
        cout<<dq.back()<<endl;
        dq.pop_back();
    }
    return 0;
}
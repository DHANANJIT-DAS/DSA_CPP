#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;

int main(){

    priority_queue<int>pq;     // default priority element/top element is the maximum element

    priority_queue<int,vector<int>,greater<int>>pq;     // priority element is minimum element
    pq.push(3);
    pq.push(35);
    pq.push(12);
    pq.push(7);
    pq.push(64);
    pq.push(39);

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }

    return 0;
}

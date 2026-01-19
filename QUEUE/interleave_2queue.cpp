#include<iostream>
#include<queue>
using namespace std;

void interleave(queue<int> &Q){
    queue<int>first;

    int n=Q.size();
    
    for(int i=1;i<=n/2;i++){
        first.push(Q.front());
        Q.pop();
    }
    while(!first.empty()){
        Q.push(first.front());
        first.pop();
        Q.push(Q.front());
        Q.pop();
    }
}
int main(){
    queue<int>Q;
    for(int i=1;i<=10;i++){
        Q.push(i);
    }
    interleave(Q);
    while(!Q.empty()){
        cout<<Q.front()<<" ";
        Q.pop();
    }

    return 0;
}
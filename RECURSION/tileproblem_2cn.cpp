#include<iostream>
using namespace std;

int ways(int n){
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    return ways(n-1)+ways(n-2);

}
int main(){
    cout<<ways(5);

    return 0;
}
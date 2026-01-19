#include<iostream>
using namespace std;

void func(int n){
    if(n==0){
        return;
    }

    cout<<n<<" ";
    func(n-1);

}


int main(){
    func(10);
    return 0;
}
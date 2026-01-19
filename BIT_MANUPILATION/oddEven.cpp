#include<iostream>
using namespace std;

void odd_even(int n){
    if(!(n&1)){
        cout<<"even\n";
    }
    else{
        cout<<"odd\n";
    }
}



int main(){

    odd_even(5);
    odd_even(6);
    return 0;
}

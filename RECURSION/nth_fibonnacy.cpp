#include<iostream>
using namespace std;

int fibonacy(int n){
    if(n==1){
        return 1;
    }
    if(n==0){
        return 0;
    }

    
    return fibonacy(n-1)+fibonacy(n-2);

    
    return 0;

}


int main(){

   cout<< fibonacy(5);

    return 0;
}
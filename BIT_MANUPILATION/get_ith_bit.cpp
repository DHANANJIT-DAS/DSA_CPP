#include<iostream>
using namespace std;

bool get_ith_bit(int n,int i){

   if(!(n&(1<<i))){
    return 0;
   }
   else{
    return 1;
   }

}


int main(){
    cout<<get_ith_bit(-4,25);
    return 0;
}
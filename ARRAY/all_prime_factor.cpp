#include<iostream>
#include<vector>
using namespace std;


vector<int> all_prime_factor(int n){

    vector<int>result;

    for(int i=2;i*i<=n;i++){

        if(n%i==0){
            result.push_back(i);

            while(n%i ==0){
                n=n/i;
            }
        }

    }

    if(n!=1){
        result.push_back(n);
    }



    return result;
}

int main(){

    vector<int>prime_fac=all_prime_factor(49);

    for(int i=0;i<prime_fac.size();i++){
        cout<<prime_fac[i]<<" ";
    }
    cout<<endl;

    return 0;
}
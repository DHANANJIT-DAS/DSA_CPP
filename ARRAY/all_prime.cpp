#include<iostream>
#include<vector>
using namespace std;




void printAllPrime(int n){


    vector<bool>primes(n+1,true);
    primes[0]=primes[1]=false;

    
    for(int i=2;i*i<=n;i++){
        if(primes[i]==false){
            continue;
        }
        
        for(int j=i;i*j<=n;j++){
            primes[i*j]=false;
        }
    }

    for(int i=0;i<=n;i++){
        if(primes[i]){
            cout<<i<<" ";
        }
    }

}




int main(){

    printAllPrime(1000);
    return 0;
}

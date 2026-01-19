#include<iostream>
#include<vector>
using namespace std;



void factorization(vector<int>elements){

    int n=elements.size();

    int _max=0;
    for(int i=0;i<n;i++){
        _max=max(_max,elements[i]);
    }

    

    vector<int>primes(_max+1);
    for(int i=0;i<=_max;i++){
        primes[i]=i;
    }

    for(int i=2;i*i<=_max;i++){
        if(primes[i]!=i){
            continue;
        }

        for(int j=i;i*j<=_max;j++){

            if(primes[i*j]==i*j){
                primes[i*j]=i;
            }
        }
    }


    for(int i=0;i<n;i++){

        int el=elements[i];

        while(el!=1){
            cout<<primes[el]<<" ";
            el=el/primes[el];
        }

        cout<<endl;

    }
}


int main(){

    factorization({10,35,67,23,65});
    return 0;
}
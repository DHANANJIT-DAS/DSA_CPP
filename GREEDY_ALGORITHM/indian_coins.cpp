#include<iostream>
#include<vector>
using namespace std;


int min_coins(int amount){

    vector<int>indian_coins={2000,500,200,100,50,20,10,5,2,1};

    int ans=0;

    
    for(int i=0;i<indian_coins.size() && amount > 0;i++){
        if(amount >= indian_coins[i]){

            ans=ans+(amount/indian_coins[i]);

            amount=amount%indian_coins[i];
                
        }
    }
    

    return ans;
}

int main(){
    int amount=21750;
    cout<<min_coins(amount);
    return 0;
}
#include<iostream>
#include<vector>
#include<stack>
using namespace std;


int max_profit(vector<int>price){
    int n=price.size();
    stack<int>S;

    int max_profit=0;

    
    int bottom=0;

    for(int i=n-1;i>=0;i--){
        while(!S.empty() && S.top()<price[i]){
            max_profit=max(max_profit,bottom-S.top());
            S.pop();
        }

        if(S.empty()){
            S.push(price[i]);
            bottom=S.top();
        }
        else{
            S.push(price[i]);
        }
    }

    max_profit=max(max_profit,bottom-S.top());

    return max_profit;
    
}


int max_profit_Greedy(vector<int>prices){
    
    int n=prices.size();
    vector<int>max_sell(n,-1);
    max_sell[n-1]=prices[n-1];

    for(int i=n-2;i>=0;i--){
        max_sell[i]=max(prices[i],max_sell[i+1]);
    }

    int max_profit=0;

    for(int i=0;i<n;i++){
        max_profit=max(max_profit,max_sell[i]-prices[i]);
    }

    return max_profit;
}


int main(){
    vector<int>prices={7,1,5,3,6,4};
    cout<<max_profit_Greedy(prices);
    return 0;
}
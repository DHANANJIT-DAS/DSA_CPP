#include<iostream>
#include<vector>
#include<stack>
using namespace std;



void print(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


/*

vector<int> stock_span(vector<int>&stock){
    vector<int>span;
    for(int i=0;i<stock.size();i++){
        int count=0;

        int price=stock[i];
        int j=i;
        while(stock[j]<=price && j>=0){
            count++;
            j--;
        }
        span.push_back(count);

    }
    return span;
}


*/


// using stack

vector<int> stock_span(vector<int>&stock){
    vector<int>span;
    stack<int>index;

    int idx;

    for(int i=0;i<stock.size();i++){

        while(! index.empty() && stock[i]>=stock[index.top()]){
            index.pop();
        }

        if(index.empty()){
            idx=-1;
        }
        else{
            idx=index.top();
        }

        span.push_back(i-idx);
        index.push(i);

    }

    return span;

    
}


int main(){
    vector<int>stock={100,80,60,70,60,85,100};
    vector<int>span=stock_span(stock);
    print(stock);
    print(span);
    return 0;
}






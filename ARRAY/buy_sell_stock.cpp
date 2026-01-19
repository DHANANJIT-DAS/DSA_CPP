#include<iostream>
#include<vector>
#include<climits>

using namespace std;


int max_profit(int arr[],int n){

    int max_profit=0;

    int _min=arr[0];

    for(int i=0;i<n;i++){

        if(_min < arr[i]){
            max_profit=max(max_profit,(arr[i]-_min));

        }
        _min=min(_min,arr[i]);
    }

    return max_profit;
}


int main(){
    int arr[6]={7,1,5,3,6,4};

    cout<<max_profit(arr,6);
    return 0;
}
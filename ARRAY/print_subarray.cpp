#include<iostream>
#include<vector>
using namespace std;


void print_subarray(int arr[],int n){

    for(int start=0;start< n;start++){
        for(int end=start;end< n;end++){
            for(int i=start;i<=end;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
}
int main(){

    int arr[5]={1,2,3,4,5};

    print_subarray(arr,5);

    
    return 0;
}
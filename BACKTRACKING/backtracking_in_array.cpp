#include<iostream>
using namespace std;

void func(int arr[],int i){
    if(i==5){
        for(int i=0;i<5;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }

    arr[i]=i+1;
    func(arr,i+1);
    arr[i]=arr[i]-2;//backtracking
    

}

int main(){
    int arr[5];
    func(arr,0);
     for(int i=0;i<5;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;


    return 0;
}
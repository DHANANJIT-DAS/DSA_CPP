#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(vector<int>&arr,int strt,int end){
    int pivot=arr[end];
    int i=strt-1;
    int j=strt;

    while(j<end){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    i++;
    swap(arr[i],arr[end]);

    return i;


}

void quickSort(vector<int>&arr,int strt,int end){

    if(strt>=end){
        return;
    }


    

   int pivotIdx= partition(arr,strt,end);

   quickSort(arr,strt,pivotIdx-1); // left
   quickSort(arr,pivotIdx+1,end); // right


}


int main(){

    vector<int>arr={5,6,7,4,52,3,6,8,56,3,4,5,35,678,23,46,34};
    int n=arr.size();
    quickSort(arr,0,n-1);

    print(arr);
    


    return 0;
}
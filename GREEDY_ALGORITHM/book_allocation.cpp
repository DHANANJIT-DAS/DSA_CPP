#include<iostream>
#include<vector>
using namespace std;


bool isValid(vector<int>&pages,int &student,int mid){
    int count=1;
    int current_page=pages[0];
    for(int i=1;i<pages.size();i++){
        if(current_page+pages[i] <=mid){
            current_page+=pages[i];
        }
        else{
            current_page=pages[i];
            count++;
            if(count>student){
                return false;
            }
        }
    }
    return true;

}

int book_allocation(vector<int>&pages,int &student){

    if(student>pages.size()){
        return -1;
    }

    int start=INT32_MIN;
    int end=0;

    for(int i=0;i<pages.size();i++){
        start=max(start,pages[i]);
        end+=pages[i];
    }

    int max_pages=0;

    while(start<=end){

        int mid=(start+end)/2;

        if(isValid(pages,student,mid)){
            max_pages=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }

    return max_pages;

}


int main(){
    vector<int>pages={4,6,8,2,4,10,12};
    int student=5;
    cout<<book_allocation(pages,student);
    return 0;
}
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> left_min(vector<int> &histogram){
    stack<int>temp;
    vector<int>left_next_min(histogram.size(),0);
    for(int i=0;i<histogram.size();i++){
        while(!temp.empty() && histogram[temp.top()]>=histogram[i]){
            temp.pop();
        }
        if(temp.empty()){
            left_next_min[i]=-1;
            temp.push(i);
        }
        else{
            left_next_min[i]=temp.top();
            temp.push(i);
        }
    }

    
    return left_next_min;
}

vector<int> right_min(vector<int> &histogram){
    int n=histogram.size();
    vector<int>right_next_min(n,0);
    stack<int>temp;

    for(int i=n-1;i>=0;i--){
        while(!temp.empty() && histogram[temp.top()]>=histogram[i]){
            temp.pop();
        }
        if(temp.empty()){
            right_next_min[i]=n;
            temp.push(i);
        }else{
            right_next_min[i]=temp.top();
            temp.push(i);
        }

    }
    
    return right_next_min;
}

int maxArea(vector<int>&histogram){
    vector<int> left_next_min=left_min(histogram);
    vector<int> right_next_min=right_min(histogram);
    int max_area=INT32_MIN;

    for(int i=0;i<histogram.size();i++){
        int height=histogram[i];
        int width=right_next_min[i]-left_next_min[i]-1;
        int area=height*width;
        if(area>=max_area){
            max_area=area;
        }
    }
    return max_area;

}

int main(){
    vector<int>histogram={2,1,5,6,2,3};
    cout<<maxArea(histogram);
    return 0;
}
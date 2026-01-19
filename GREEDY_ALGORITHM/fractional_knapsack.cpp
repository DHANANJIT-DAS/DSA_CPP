#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool compare(pair<double,int>p1 , pair<double,int>p2){

    return p1.first > p2.first;
}

double fractional_knapsack(vector<int>&value,vector<int>&weight,int total_weight){

    vector<pair<double,int>>ValPerKg_weight(value.size(),make_pair(0.0,0)); // (value per kg,weight)

    for(int i=0;i<ValPerKg_weight.size();i++){
        ValPerKg_weight[i]=make_pair(((double)value[i]/(double)weight[i]),weight[i]);
    }

    

    sort(ValPerKg_weight.begin(),ValPerKg_weight.end(),compare);

    


    double ans=0.0;
    int i=0;

    while(total_weight > 0 && i<ValPerKg_weight.size()){
        if(total_weight >= ValPerKg_weight[i].second){

            double val=ValPerKg_weight[i].first * ValPerKg_weight[i].second;
            ans=ans+val;
            total_weight = total_weight - ValPerKg_weight[i].second;
        }
        else{
            ans= ans+ total_weight * ValPerKg_weight[i].first;
            break;
        }
        i++;
        
    }

    return ans;
}

int main(){
    vector<int>value={60,100,120};
    vector<int>weight={10,20,30};
    int total_weight=50;

    cout<<fractional_knapsack(value,weight,total_weight);
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class job{
    public:

    int id;
    int deadline;
    int profit;
};



void printVec(vector<int>arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


bool compare(job j1,job j2){
    return j1.profit > j2.profit;
}

pair<int,vector<int>> max_profit_and_job_sequence(vector<job>&jobs){

    sort(jobs.begin(),jobs.end(),compare);

    int max_deadline=0;
    for(int i=0;i<jobs.size();i++){
        max_deadline=max(max_deadline,jobs[i].deadline);
    }
    

    vector<int>job_sequence(max_deadline+1,-1);

    int max_profit=0;

    for(int i=0;i<jobs.size();i++){
        for(int j=jobs[i].deadline;j>0;j--){
            if(job_sequence[j]==-1){
                max_profit=max_profit+jobs[i].profit;
                job_sequence[j]=jobs[i].id;
                break;
            }
        }
    }

    return make_pair(max_profit,job_sequence);

}

int main(){
    vector<job>jobs={{7,2,10},{4,6,65},{1,4,20},{8,2,22},{6,2,80},{3,6,70},{2,5,60},{5,4,25}};
    

    pair<int,vector<int>> result=max_profit_and_job_sequence(jobs);

    cout<<result.first<<endl;

    for(int i=1;i<result.second.size();i++){
        cout<<result.second[i]<<" ";
    }

    return 0;
}
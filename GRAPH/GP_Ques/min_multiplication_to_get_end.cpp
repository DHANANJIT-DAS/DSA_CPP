#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;



int minMultiplication(vector<int>nums,int start,int end){

    vector<int>steps(1e5+1,INT_MAX);
    steps[start]=0;

    queue<pair<int,int>>Q;  // (num,step)
    Q.push(make_pair(start,0));

    while(!Q.empty()){

        int currNum=Q.front().first;
        int currStep=Q.front().second;
        Q.pop();

        if(currNum==end){
            return currStep;
        }

        for(int i=0;i<nums.size();i++){

            int nextNum=(currNum*nums[i])% 100000 ;

            if(steps[nextNum]==INT_MAX){
                steps[nextNum]=currStep+1;
                Q.push(make_pair(nextNum,currStep+1));
            }
            
        }
    }

    return -1;
}



int main(){
    return 0;
}


/*

    Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array 
    and then mod operation with 100000 is done to get the new start.

    Your task is to find the minimum steps in which end can be achieved starting from start. 
    If it is not possible to reach end, then return -1.

    Ex-

    Input:  arr[] = {2, 5, 7} ,start = 3, end = 30

    Output: 2

    Explanation:
    Step 1: 3*2 = 6 % 100000 = 6 
    Step 2: 6*5 = 30 % 100000 = 30

*/
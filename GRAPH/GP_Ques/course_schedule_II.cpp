/*

There are a total of 'numCourses' courses you have to take, labeled from '0' to 'numCourses - 1'.
You are given an array 'prerequisites' where prerequisites[i] = [ai, bi] indicates that you must
take course 'bi' first if you want to take course 'ai'.

For example, the pair [0, 1], indicates that to take course '0' you have to first take course '1'.
Return the ordering of courses you should take to finish all courses. 
If there are many valid answers, return any of them. 
If it is impossible to finish all courses, return an empty array.

*/


// the problem is basically find the topological sorted array


#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;


void topoSorted(int current,vector<bool>&visit,stack<int>&S,vector<vector<int>>&prerequisites){

    visit[current]=true;

    for(int i=0;i<prerequisites.size();i++){
        int u=prerequisites[i][1];
        int v=prerequisites[i][0];

        if(u==current){

            if(!visit[v]){
                topoSorted(v,visit,S,prerequisites);
            }


        }
    }

    S.push(current);
}


bool isCycle(int current,vector<bool>&visit,vector<bool>&path,vector<vector<int>>&prerequisites){

    visit[current]=true;
    path[current]=true;

    for(int i=0;i<prerequisites.size();i++){
        int u=prerequisites[i][1];
        int v=prerequisites[i][0];

        if(u==current){

            if(!visit[v]){
                if(isCycle(v,visit,path,prerequisites)) return true;
            }
            else{
                if(path[v]) return true;
            }


            
        }
    }

    path[current]=false;
    return false;

}

vector<int> findOrder(int numCourses,vector<vector<int>> prerequisites){

    vector<bool>visit(numCourses,false);
    vector<bool>path(numCourses,false);

    for(int i=0;i<numCourses;i++){
        if(!visit[i]){
            if(isCycle(i,visit,path,prerequisites)) return {};
        }
    }

    for(int i=0;i<numCourses;i++){
        visit[i]=false;
    }
    stack<int>S;
    vector<int>sorted;

    for(int i=0;i<numCourses;i++){
        if(!visit[i]){
            topoSorted(i,visit,S,prerequisites);
        }
    }

    while(!S.empty()){
        sorted.push_back(S.top());
        S.pop();
    }

    return sorted;
}




int main(){


    return 0;
}
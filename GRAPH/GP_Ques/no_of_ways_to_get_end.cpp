#include<iostream>
#include<vector>
#include<list>
#include<set>
using namespace std;


int no_of_ways(int V,vector<vector<int>>&edges,int src,int end){

    list<pair<int,int>>* l=new list<pair<int,int>> [V];

    for(int i=0;i<edges.size();i++){
        l[edges[i][0]].push_back(make_pair(edges[i][1],edges[i][2]));
        l[edges[i][1]].push_back(make_pair(edges[i][0],edges[i][2]));
    }

    vector<int>dist(V,1e9);
    vector<int>path(V,0);
    dist[src]=0;
    path[src]=1;

    set< pair<int,int> > S;
    S.insert(make_pair(0,src));

    while(!S.empty()){

        auto curr=S.begin();
        int currDist=curr->first;
        int currNode=curr->second;
        S.erase(curr);

        list<pair<int,int>>nbr=l[currNode];

        for(auto el:nbr){

            int v=el.first;
            int d=el.second;

            if(currDist+d < dist[v]){

                if(dist[v]!=1e9){
                    S.erase(make_pair(dist[v],v));
                }
                dist[v]=currDist+d;
                path[v]=path[currNode];
                S.insert(make_pair(dist[v],v));
                
            }
            else if(currDist+d == dist[v]){
                path[v]+=path[currNode];
                S.insert(make_pair(dist[v],v));
            }
        }

    }

    return path[end];
   
}


int main(){
    return 0;
}




/*
    You are given an undirected weighted graph with V vertices numbered from 0 to V-1 and E edges, 
    represented as a 2D array edges[][], where edges[i] = [u(i), v(i), dist(i)] means that there is an undirected edge between 
    nodes u(i) and v(i) that takes dist(i) to reach.

    Your task is to return in how many ways you can travel from node src to node end in the shortest dist.


    Ex--

    Input: V = 4, edges[][] = [[0, 1, 2], [1, 2, 3], [0, 3, 5], [1, 3, 3], [2, 3, 4]], src=0, end=4

    Output: 2

    Explanation: The shortest path from 0 to 3 is 5.
    Two ways to reach 3 in 5 minutes are:
    0 -> 3
    0 -> 1 -> 3

*/

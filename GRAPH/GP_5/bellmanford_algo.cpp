#include<iostream>
#include<vector>
#define INT_MAX 1e9
using namespace std;


vector<int> shortestDist(int V,vector<vector<int>>&edges,int src){

    vector<int>dist(V,INT_MAX);
    dist[src]=0;

    for(int i=0;i<V-1;i++){

        for(int j=0;j<edges.size();j++){
            
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];

            if(dist[u]+wt<dist[v]){
                dist[v]=dist[u]+wt;
            }
        }
    }

    return dist;

}

int main(){
    return 0;
}
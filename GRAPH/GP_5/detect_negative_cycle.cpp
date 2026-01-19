#include<iostream>
#include<vector>
#define INT_MAX 1e9
using namespace std;

bool isNegativeCycle(int V,vector<vector<int>>&edges){

    vector<int>dist(V,INT_MAX);
    
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

    for(int i=0;i<edges.size();i++){

        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];

        if(dist[u]+wt<dist[v]){
                
            dist[v]=dist[u]+wt;
            return true;
        }
    }

    return false;
}

int main(){
    
    vector<vector<int>>edges={{0,1,-1},{1,2,-1},{2,1,-1}};
    cout<<isNegativeCycle(3,edges);
    
    return 0;
}
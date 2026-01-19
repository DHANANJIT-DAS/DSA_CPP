#include<iostream>
#include<vector>
#define INT_MAX 1e9
using namespace std;


void shortestDist(int V,vector<vector<int>>&edges){

    vector<vector<int>>dist(V,vector<int>(V,INT_MAX));

    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        dist[u][v]=wt;
    }

    for(int i=0;i<V;i++){
        dist[i][i]=0;
    }

    for(int k=0;k<V;k++){

        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }

}



int main(){

    int V=6;
    vector<vector<int>>edges={{0,1,1},{1,2,3},{2,3,-2},{3,4,8},{4,5,0}};
    shortestDist(V,edges);
    return 0;
}
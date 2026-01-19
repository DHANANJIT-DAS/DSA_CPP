#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


class Graph{
    int vertex;
    list<pair<int,int>>* l;

public:

    Graph(int vertex){
        this->vertex=vertex;
        l=new list<pair<int,int>> [vertex];
    }

    void addEdge(int u,int v,int weight){
        l[u].emplace_back(v,weight);
    }

    void DFS_toposort(int current,vector<bool>&visit,stack<int>&S){

        visit[current]=true;

        list<pair<int,int>>neibor=l[current];

        for(auto x:neibor){

            if(!visit[x.first]){
                DFS_toposort(x.first,visit,S);
            }
        }

        S.push(current);
    }


    vector<int> sortestPath(int src){       // it can be also solved by Dijkstras algorithm.

        vector<bool>visit(vertex,false);
        stack<int>S;

        for(int i=0;i<vertex;i++){
            if(!visit[i]){
                DFS_toposort(i,visit,S);
            }
        }

        vector<int>dist(vertex,INT32_MAX);
        dist[src]=0;

        while(!S.empty()){
            int curr=S.top();
            S.pop();

            list<pair<int,int>>nbr=l[curr];

            for(auto el:nbr){
                int v=el.first;
                int d=el.second;

                dist[v]=min(dist[v],dist[curr]+d);
            }
        }

        for(int i=0;i<vertex;i++){
            if(dist[i]==INT32_MAX){
                dist[i]=-1;
            }
        }

        return dist;

    }


    
};



int main(){

    Graph G(5);


    return 0;
}
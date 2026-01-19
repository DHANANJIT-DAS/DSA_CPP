#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{

    int totalVertex;
    list<int>* l;
    bool isDirected;

public:

    Graph(int n,bool isDirected=false){
        this->totalVertex=n;
        l=new list<int> [totalVertex];
        this->isDirected=isDirected;
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        if(!isDirected){
            l[v].push_back(u);
        }
    }

    void path_DFS(int start,int end,vector<int>&path,vector<bool>&visit){

        visit[start]=true;
        path.push_back(start);

        if(start==end){
            for(int i=0;i<path.size();i++){
                cout<<path[i]<<" ";
            }
            cout<<endl;
        }
        
        list<int> neibor=l[start];

        for(int x: neibor){
            if(!visit[x]){
                path_DFS(x,end,path,visit);
            }
            
        }

        visit[start]=false;
        path.pop_back();

    }

    void totalPath(int start,int end){
        vector<bool>visit(totalVertex,false);
        vector<int>path;

        path_DFS(start,end,path,visit);
        
    }

};

int main(){

    Graph G(6);
    G.addEdge(5,2);
    G.addEdge(5,0);
    G.addEdge(2,3);
    G.addEdge(0,3);
    G.addEdge(4,0);
    G.addEdge(4,1);
    G.addEdge(3,1);

    G.totalPath(5,1);


    return 0;
}
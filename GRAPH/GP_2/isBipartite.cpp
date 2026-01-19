#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;



class Graph{

public:

    int totalVertix;
    list<int>* l;
    bool isDirected;

    Graph(int n,bool isDirected=false){
        this->totalVertix=n;
        l =new list<int> [totalVertix];
        this->isDirected=isDirected;
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        if(!isDirected){
            l[v].push_back(u);
        }
        
    }

    bool bipartite_check(int src,vector<bool>&visit,vector<int>&color){

        queue<int>Q;
        Q.push(src);
        visit[src]=true;
        color[src]=0;

        while(!Q.empty()){
            int current=Q.front();
            Q.pop();

            list<int>neibor=l[current];

            for(int x : neibor){

                if(!visit[x]){
                    Q.push(x);
                    visit[x]=true;
                    color[x]=(color[current]==0 ? 1:0);


                }
                else{
                    if(color[x]==color[current]){
                        return false;
                    }
                }
            }
        }

        return true;

    }
    
    bool isBipartite(){
        vector<bool>visit(totalVertix,false);
        vector<int>color(totalVertix,-1);
        return bipartite_check(0,visit,color);

    }
};




int main(){

    Graph G(5);

    G.addEdge(0,1);
    G.addEdge(1,2);
    G.addEdge(2,3);
    G.addEdge(3,4);
    G.addEdge(4,0);
    cout<<G.isBipartite();
    

    

    return 0;
}
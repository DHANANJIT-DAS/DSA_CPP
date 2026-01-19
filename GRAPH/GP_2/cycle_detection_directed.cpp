#include<iostream>
#include<vector>
#include<list>
using namespace std;


class Graph{

    int vertex;
    list<int>* l;
    bool isDirected;

public:

    Graph(int vertex,bool isDirected=false){
        this->vertex=vertex;
        l=new list<int> [vertex];
        this->isDirected=isDirected;
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        if(!isDirected){
            l[v].push_back(u);
        }
        
    }



    bool detectCycle(int current, vector<bool>&visit, vector<bool>&recPath){  // DFS

        visit[current]=true;
        recPath[current]=true;

        list<int>neibor=l[current];

        for(auto x: neibor){
            if(!visit[x]){
                if(detectCycle(x,visit,recPath)){
                    return true;
                }
            }
            else{
                if(recPath[x]){
                    return true;
                }
            }
        }
        recPath[current]=false;

        return false;
    }


    bool isCycleDirected(){
        vector<bool>visit(vertex,false);
        vector<bool>recPath(vertex,false);

        for(int i=0;i<vertex;i++){
            if(!visit[i]){
                if(detectCycle(i,visit,recPath)){
                    return true;
                }
            }
        }

        return false;
        
    }


    
};

int main(){

    Graph G(5,true);

    G.addEdge(0,1);
    G.addEdge(2,1);
    G.addEdge(2,3);
    G.addEdge(3,4);
    G.addEdge(4,2);
    cout<<G.isCycleDirected();


    return 0;
}
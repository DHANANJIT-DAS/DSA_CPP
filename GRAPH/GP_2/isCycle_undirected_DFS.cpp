#include<iostream>
#include<vector>
#include<list>
using namespace std;


class Graph{

    int vertex;
    list<int>* l;

public:

    Graph(int vertex){
        this->vertex=vertex;
        l=new list<int> [vertex];
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }


    bool detect_cycle(int current,vector<bool>&visit,int parent){

        visit[current]=true;

        list<int>neibor=l[current];

        for(auto x: neibor){
            if(!visit[x]){
                if(detect_cycle(x,visit,current)){
                    return true;
                }
            }
            else{
                if(x!=parent){
                    return true;
                }
            }
        }
        return false;

    }

    bool isCycleUndirected(){             //  DFS
        vector<bool>visit(vertex,false);

        for(int i=0;i<vertex;i++){
            if(!visit[i]){

                if(detect_cycle(i,visit,-1)){
                    return true;
                }

            }
            
        }

        return false;
    }

};

int main(){
    Graph G(4);
    G.addEdge(0,1);
    G.addEdge(2,1);
    G.addEdge(2,3);
    

    cout<<G.isCycleUndirected();

    return 0;
}
#include<iostream>
#include<list>
#include<vector>
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


    void print(){
        for(int i=0;i<vertex;i++){
            cout<<i<<": ";
            list<int>neibor=l[i];
            for(auto x:neibor){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }



    void treverse(int current,vector<bool>&visit){

        visit[current]=true;

        list<int>neibor=l[current];
        cout<<current<<" ";

        for(auto x: neibor){
            if(!visit[x]){
                treverse(x,visit);
            }
        }

    }

    void DFS(){
        vector<bool>visit(vertex,false);

        for(int i=0;i<vertex;i++){
            if(!visit[i]){
                treverse(i,visit);
                cout<<endl;
            }
        }
    }



};


int main(){


    Graph G(10);

    G.addEdge(1,6);
    G.addEdge(6,4);
    G.addEdge(4,9);
    G.addEdge(4,3);
    G.addEdge(3,8);
    G.addEdge(3,7);
    G.addEdge(2,5);
    G.addEdge(2,0);

    G.DFS();

    return 0;
}
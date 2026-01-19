#include<iostream>
#include<vector>
#include<list>
using namespace std;



class Graph{

public:

    int totalVertix;
    list<int>* l;

    Graph(int n){
        this->totalVertix=n;
        l =new list<int> [totalVertix];
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int i=0;i<totalVertix;i++){
            cout<<i<<": ";
            list<int>neighbour=l[i];
            for(int j:neighbour){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }


    void treverse(int current,vector<bool>&visit){

        visit[current]=true;

        cout<<current<<" ";

        list<int>neighbor=l[current];

        for(int el:neighbor){
            if(visit[el]!=true){
                treverse(el,visit);
            }
        }

    }

    void DFS(){

        vector<bool>visit(totalVertix,false);

        treverse(0,visit);
    }

};




int main(){


    Graph G(5);

    G.addEdge(0,1);
    
    G.addEdge(1,2);
    G.addEdge(1,3);
    
    G.addEdge(2,3);
    G.addEdge(2,4);
    
    G.DFS();
    return 0;
}

#include<iostream>
#include<vector>
#include<list>
using namespace std;


class Graph{

    int totalVertx;
    vector<vector<int>>list;

public:

    Graph(int totalVertex){
        this->totalVertx=totalVertex;
        list.resize(totalVertex);
    }

    void addEdge(int u,int v){
        list[u].push_back(v);
        list[v].push_back(u);
    }

    void printGraph(){
        for(int i=0;i<totalVertx;i++){
            cout<<i<<":";
            for(int j=0;j<list[i].size();j++){
                cout<<list[i][j]<<" ";
            }
            cout<<endl;
        }
    }

};

int main(){

    Graph G(5);

    G.addEdge(0,1);
    
    G.addEdge(1,2);
    G.addEdge(1,3);
    
    G.addEdge(2,3);
    G.addEdge(2,4);

    G.printGraph();

}
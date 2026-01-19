#include<iostream>
#include<vector>
#include<stack>
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
    }



    void DFS(int current,vector<bool>&visit,stack<int>&S){

        visit[current]=true;

        list<int>neibor=l[current];

        for(int x:neibor){
            if(!visit[x]){
                DFS(x,visit,S);
            }
        }

        S.push(current);
    }


    void topo_sort(){

        vector<bool>visit(vertex,false);
        stack<int>S;

        for(int i=0;i<vertex;i++){
            if(!visit[i]){
                DFS(i,visit,S);
            }
        }

        vector<int>sorted;
        while(!S.empty()){
            sorted.push_back(S.top());
            S.pop();
        }

        for(int i=0;i<sorted.size();i++){
            cout<<sorted[i]<<" ";
        }
        cout<<endl;
    }

};



int main(){
    Graph G(6);

    G.addEdge(5,0);
    G.addEdge(4,0);
    G.addEdge(5,2);
    G.addEdge(2,3);
    G.addEdge(3,1);
    G.addEdge(4,1);

    G.topo_sort();

    return 0;
}
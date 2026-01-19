#include<iostream>
#include<list>
#include<vector>
#include<queue>
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

    bool detect_cycle(int start,vector<bool>&visit){

        queue<pair<int,int>>Q;   // (current node,parent node)
        Q.push(make_pair(start,-1));
        visit[start]=true;

        while(!Q.empty()){

            int curr=Q.front().first;
            int parent=Q.front().second;
            Q.pop();

            list<int>neibor=l[curr];

            for(auto el:neibor){
                if(!visit[el]){
                    Q.push(make_pair(el,curr));
                    visit[el]=true;
                }
                else if(el!=parent){
                    return true;
                }
            }
        }

        return false;

    }

    bool isCycle(){
        vector<bool>visit(vertex,false);

        for(int i=0;i<vertex;i++){
            if(!visit[i]){
                if(detect_cycle(i,visit)){
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

    cout<<G.isCycle();

    return 0;
}
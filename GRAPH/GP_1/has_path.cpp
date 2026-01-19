#include<iostream>
#include<vector>
#include<list>
#include<queue>
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

    


};


bool treverse(list<int>* l,int current,int end,vector<bool>&visit){

    visit[current]=true;

    if(current==end){
        return true;
    }
    else{
        list<int>neighbor=l[current];

        for(int j:neighbor){
            if(!visit[j]){

                if(treverse(l,j,end,visit)){
                    return true;
                }
            }
        }
    }

    return false;

}

bool hasPath_DFS(list<int>* l,int start,int end,int totalVertex){

    

    vector<bool>visit(7,false);

    return treverse(l,start,end,visit);

}


bool hasPath_BFS(list<int>* l,int start,int end,int totalVertex){

    vector<bool>visit(totalVertex,false);

    queue<int>Q;

    Q.push(start);
    visit[start]=true;

    while(!Q.empty()){

        int current=Q.front();
        Q.pop();

        if(current==end){
            return true;
        }

        list<int>neighbor=l[current];
        for(int el:neighbor){
            if(!visit[el]){
                Q.push(el);
                visit[el]=true;
            }
        }
    }
    return false;
}


int main(){


    int totalVertex=5;

    Graph G(totalVertex);

    G.addEdge(0,1);
    
    G.addEdge(1,2);
    G.addEdge(1,3);
    
    G.addEdge(2,3);
    G.addEdge(2,4);

    cout<<hasPath_BFS(G.l,2,7,totalVertex);
    
    
    return 0;
}

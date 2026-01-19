#include<iostream>
#include<vector>
#include<list>
using namespace std;


class Graph{
    int v;
    list<pair<int,int>>*l;
public:
    Graph(int v){
        this->v=v;
        l=new list<pair<int,int>>[v];
    }

    void addEdge(int u,int v,int weight){
        l[u].push_back(make_pair(v,weight));
        l[v].push_back(make_pair(u,weight));
    }

    void print(){
        for(int i=0;i<v;i++){
            list<pair<int,int>> neighbors=l[i];
            cout<<i<<" : [";
            for(pair<int,int> j:neighbors){
                cout<<"("<<j.first<<","<<j.second<<")";
            }
            cout<<"]"<<endl;
        }
    }
};


int main(){
    Graph G(5);
    G.addEdge(0,1,5);
    G.addEdge(1,2,1);
    G.addEdge(1,3,3);
    G.addEdge(2,3,1);
    G.addEdge(2,4,7);
    
    G.print();
    return 0;
}
#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    int v;
    list<int>* l;
public:
    Graph(int v){
        this->v=v;
        l=new list<int> [v];
    }

    void addEdge(int u,int v){ //u----v
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void print(){
        for(int i=0;i<v;i++){
            list<int>neighbors=l[i];
            cout<<i<<" : ";
            for(int j:neighbors){
                cout<<j<<" ";
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
    
    G.print();


    
    

    return 0;
}
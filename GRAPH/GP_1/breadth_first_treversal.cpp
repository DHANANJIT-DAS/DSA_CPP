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



    void BFS(){     // O(v + E)
        vector<bool>visit(totalVertix,false);
        queue<int>Q;

        Q.push(0);
        visit[0]=true;

        while(!Q.empty()){

            int current=Q.front();
            Q.pop();
            cout<<current<<" ";

            list<int>neighbor=l[current];

            for(int j:neighbor){
                if(visit[j]!=true){
                    Q.push(j);
                    visit[j]=true;
                }
            }

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
    
    // G.print();

    G.BFS();
    

    return 0;
}
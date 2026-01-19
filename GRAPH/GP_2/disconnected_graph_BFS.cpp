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



    void BFS_(int i,vector<bool>&visit){     // O(v + E)
        
        queue<int>Q;
        Q.push(i);
        visit[i]=true;
            
            

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

    void BFS(){

        vector<bool>visit(totalVertix,false);

        for(int i=0;i<totalVertix;i++){
            if(!visit[i]){
                BFS_(i,visit);
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

    G.BFS();

    

    return 0;
}
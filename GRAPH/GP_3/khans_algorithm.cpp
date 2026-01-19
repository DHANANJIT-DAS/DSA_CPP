#include<iostream>
#include<vector>
#include<stack>
#include<list>
#include<queue>
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


    void calIndegree(vector<int>&indegree){

        for(int u=0;u<vertex;u++){

            list<int>neibor=l[u];

            for(int v : neibor){
                indegree[v]++;
            }
        }
    }


    void khans_algo(){

        vector<int>indegree(vertex,0);
        calIndegree(indegree);

        queue<int>Q;
        vector<int>sorted;

        for(int i=0;i<vertex;i++){
            if(indegree[i]==0){
                Q.push(i);
            }
        }

        while(!Q.empty()){

            int current=Q.front();
            Q.pop();
            sorted.push_back(current);
            
            list<int>neibor=l[current];
            for(int v: neibor){
                indegree[v]--;
                if(indegree[v]==0){
                    Q.push(v);
                }
            }
        }


        for(int i=0;i<sorted.size();i++){
            cout<<sorted[i]<<" ";
        }
        cout<<endl;

    }

    bool isCycle(){

        vector<int>indegree(vertex,0);
        calIndegree(indegree);

        queue<int>Q;

        for(int i=0;i<vertex;i++){
            if(indegree[i]==0){
                Q.push(i);
            }
        }

        while(!Q.empty()){

            int current=Q.front();
            Q.pop();
            
            list<int>neibor=l[current];
            for(int v: neibor){
                indegree[v]--;
                if(indegree[v]==0){
                    Q.push(v);
                }
            }
        }


        for(int i=0;i<vertex;i++){
            if(indegree[i]!=0){
                return true;
            }
        }

        return false;

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

    G.khans_algo();

    return 0;
}
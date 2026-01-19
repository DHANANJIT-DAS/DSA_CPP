#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<climits>
using namespace std;


class Graph{
    int vertex;
    list<pair<int,int>>* l;

public:

    Graph(int vertex){
        this->vertex=vertex;
        l=new list<pair<int,int>> [vertex];
    }

    void addEdge(int u,int v,int wt){
        l[u].emplace_back(v,wt);
        l[v].emplace_back(u,wt);
    }

    vector<int> shortestDist(int src){     // using Queue --  time complexity is more

        vector<int>dist(vertex,INT_MAX);
        dist[src]=0;

        queue<int>Q;
        Q.push(src);

        while(!Q.empty()){

            int curr=Q.front();
            Q.pop();

            list<pair<int,int>>nbr=l[curr];

            for(auto el:nbr){

                int v=el.first;
                int d=el.second;

                if(dist[curr]+d < dist[v]){
                    dist[v]=dist[curr]+d;
                    Q.push(v);
                }

            }
        }

        return dist;


    }
};



int main(){



    return 0;
}
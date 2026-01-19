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

    vector<int> shortestDist(int src){     // using priority Queue --  time complexity is little less

        vector<int>dist(vertex,INT_MAX);
        dist[src]=0;

        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >Q;

        Q.push(make_pair(0,src));

        while(!Q.empty()){

            int currDis=Q.top().first;   // currDistance has no use here,it just helps to be in top in PQ.
            int currNode=Q.top().second;
            Q.pop();

            list<pair<int,int>>nbr=l[currNode];

            for(auto el:nbr){

                int v=el.first;
                int d=el.second;

                if(currDis+d < dist[v]){
                    dist[v]=dist[currNode]+d;
                    Q.push(make_pair(dist[v],v));
                }

            }
        }

        return dist;


    }
};


int main(){
    return 0;
}
#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<set>
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

    vector<int> shortestDist(int src){     // using priority Queue --  more optimised O(E log(V))

        vector<int>dist(vertex,INT_MAX);
        dist[src]=0;

        set< pair<int,int> >S;

        S.insert(make_pair(0,src));

        while(!S.empty()){

            auto it=S.begin();

            int currDis=it->first;
            int currNode=it->second;
            S.erase(it);

            list<pair<int,int>>nbr=l[currNode];

            for(auto el:nbr){

                int v=el.first;
                int d=el.second;

                if(currDis+d < dist[v]){

                    if(dist[v]!=INT_MAX){
                        S.erase(make_pair(dist[v],v));
                    }
                    dist[v]=currDis+d;
                    S.insert(make_pair(dist[v],v));
                    
                }

            }
        }

        return dist;


    }
};


int main(){
    return 0;
}
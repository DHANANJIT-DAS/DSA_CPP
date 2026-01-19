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

    vector<int> shortestPath(int src,int des){     

        vector<pair<int,int>>dist(vertex,make_pair(INT_MAX,-1));
        dist[src].first=0;

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

                if(currDis+d < dist[v].first){

                    if(dist[v].first!=INT_MAX){
                        S.erase(make_pair(dist[v].first,v));
                    }
                    dist[v].first=currDis+d;
                    dist[v].second=currNode;
                    S.insert(make_pair(dist[v].first,v));
                    
                }

            }
        }

        vector<int>path;

        int loc=des;

        if(dist[des].first==INT_MAX){
            return {-1};
        }

        while(loc!=-1){
            path.push_back(loc);
            loc=dist[loc].second;
        }

        path.push_back(dist[des].first);

        int strt=0;
        int end=path.size()-1;

        while(strt<end){
            swap(path[strt],path[end]);
            strt++;
            end--;
        }

        return path;

    }
};


int main(){

    
    return 0;
}


/*
    You are given a weighted undirected graph with n vertices and m edges along with their weights. 
    Find the shortest path between vertex 'src' and vertex 'des'.

    If a path exists, return a list of integers of the nodes along that path (from 'src' to 'des'). 
    If no path exists, return a list containing only {-1}.

*/
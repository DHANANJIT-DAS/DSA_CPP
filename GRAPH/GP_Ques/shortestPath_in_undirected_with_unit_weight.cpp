#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

class Graph{
    int vertex;
    list<int>* l;

public:

    Graph(int vertex,bool isDirected=false){
        this->vertex=vertex;
        l=new list<int> [vertex];
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    vector<int> shortestPath(int src){

        vector<int>dist(vertex,INT_MAX);
        dist[src]=0;

        queue<pair<int,int>>Q;
        Q.push(make_pair(src,0));
        

        while(!Q.empty()){

            int currNode=Q.front().first;
            int currDist=Q.front().second;
            Q.pop();

            list<int>nbr=l[currNode];

            for(auto el:nbr){

                if(dist[el]==INT_MAX){
                    dist[el]=currDist+1;
                    Q.push(make_pair(el,dist[el]));
                }
            }
        }

        for(int i=0;i<vertex;i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }


        return dist;
    }
};


vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
    Graph G(V);
    for(int i=0;i<edges.size();i++){
        G.addEdge(edges[i][0],edges[i][1]);
    }

    return G.shortestPath(src);
        
}


int main(){
    return 0;
}




/*
    You are given an undirected graph with V vertices numbered from 0 to V-1 and E edges, 
    represented as a 2D array edges[][], where each element edges[i] = [u, v] represents an undirected edge 
    between vertices u and v.

    Your task is to find the shortest path distance from a given source vertex src to all other vertices in the graph.
    If a vertex is not reachable from the source, return -1 for that vertex.


    Note: All edges have unit weight (1).

    Ex--

    Input: V = 9, E = 10, 
           edges[][] = [[0, 1], [0, 3], [1, 2], [3, 4], [4, 5], [2, 6], [5, 6], [6, 7], [6, 8], [7, 8]],
           src = 0

    Output: [0, 1, 2, 1, 2, 3, 3, 4, 4]

*/
#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;


class Graph{
    int v;
    list<int>* l;
public:
    Graph(int v){
        this->v=v;
        l=new list<int> [v];
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
    }

    bool DFS(int src,vector<int>&visit,vector<bool>&path){
        visit[src]=1;
        path[src]=true;

        list<int>neibor=l[src];

        for(int el:neibor){
            if(!visit[el]){
                if(!DFS(el,visit,path)){
                    visit[src]=2;
                    return false;
                }
            }
            else if(path[el] || visit[el]==2){
                visit[src]=2;
                return false;
            }
            
        }
        path[src]=false;
        return true;
    }

    void topoSort(queue<int>&Q,vector<int>&indeg,vector<int>&ans){

        while(!Q.empty()){
            int curr=Q.front();
            Q.pop();
            ans.push_back(curr);

            list<int>neibor=l[curr];

            for(auto el:neibor){
                indeg[el]--;
                if(indeg[el]==0){
                    Q.push(el);
                }
            }
        }
    }
    
};


vector<int> safeNodes(int V, vector<vector<int>>& edges) {

    Graph G(V);
    for(int i=0;i<edges.size();i++){
        G.addEdge(edges[i][0],edges[i][1]);
    }

    vector<int>visit(V,0);

    vector<bool>path(V,false);

    for(int i=0;i<V;i++){
        if(!visit[i]){
            G.DFS(i,visit,path);
        }
    }

    vector<int>safe;

    for(int i=0;i<V;i++){
        if(visit[i]==1){
            safe.push_back(i);
        }
    }

    return safe;

    

        
}





// By indegree calculation method

/*
    First we reverse the edge and calculate the indegree of every node .
    and do the toposort algorithm the nodes in the ans is safe node.
*/

vector<int> safeNodes2(int V, vector<vector<int>>& edges) {

    Graph G(V);
    vector<int>indeg(V,0);

    for(int i=0;i<edges.size();i++){
        G.addEdge(edges[i][1],edges[i][0]);
        indeg[edges[i][0]]++;
    }

    queue<int>Q;
    for(int i=0;i<V;i++){
        if(indeg[i]==0){
            Q.push(i);
        }
    }
    vector<int>ans;

    G.topoSort(Q,indeg,ans);

    return ans;
    

}


int main(){

    int V=5;
    vector<vector<int>>edges={{1, 0}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {3, 4}};

    vector<int>safe=safeNodes2(V,edges);

    for(int i=0;i<safe.size();i++){
        cout<<safe[i]<<" ";
    }
    cout<<endl;
    return 0;
}




/*
    Given a directed graph with V vertices numbered from '0' to 'V-1' and 'E' directed edges, 
    represented as a 2D array edges[][], where each element edges[i] = [u, v] represents a directed edge
    from vertex u to vertex v. Return all Safe Nodes of the graph.

    A vertex with no outgoing edges is called a terminal node. A vertex is considered safe if every path 
    starting from it eventually reaches a terminal node.

    Ex--

    Input: V = 5, E = 6, edges[][] = [[1, 0], [1, 2], [1, 3], [1, 4], [2, 3], [3, 4]]

    Output: [0, 1, 2, 3, 4]

    Explanation: 4 and 0 is the terminal node, and all the paths from 1, 2, 3 lead to terminal node, i.e., 4.

 

*/



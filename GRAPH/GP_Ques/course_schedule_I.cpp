#include<iostream>
#include<vector>
#include<list>
using namespace std;


class Graph{
    int vertex;
    list<int>* l;
    bool isDirected;

public:

    Graph(int vertex,bool isDirected=false){
        this->vertex=vertex;
        l=new list<int> [vertex];
        this->isDirected=isDirected;
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        if(!isDirected){
            l[v].push_back(u);
        }
    }


    bool cycle_DFS(int current,vector<bool>&visit,vector<bool>&path){

        visit[current]=true;
        path[current]=true;

        list<int> neibor=l[current];

        for(int x: neibor){
            if(!visit[x]){
                if(cycle_DFS(x,visit,path)){
                    return true;
                }
            }
            else{
                if(path[x]){
                    return true;
                }
            }
        }

        path[current]=false;

        return false;
    }

    bool isCycle_directed(){
        vector<bool>visit(vertex,false);
        vector<bool>path(vertex,false);

        for(int i=0;i<vertex;i++){
            if(cycle_DFS(i,visit,path)) return true;
        }


        return false;

    }

};

bool isPossible(int totalCourses,vector<vector<int>>courses){

    Graph G(totalCourses,true);

    for(int i=0;i<courses.size();i++){
        G.addEdge(courses[i][1],courses[i][0]);
    }

    if(G.isCycle_directed()){
        return false;
    }

    return true;
}

int main(){

    cout<<isPossible(2,{{0,1},{1,0}});

    return 0;
}



/*
    There are a total of 'totalCourses' courses you have to take, labeled from '0' to 'totalCourses - 1'.
    You are given an array 'courses' where courses[i] = [ai, bi] indicates that you must
    take course 'bi' first if you want to take course 'ai'.

    For example, the pair [0, 1], indicates that to take course '0' you have to first take course '1'.
    Return true if you can finish all courses. Otherwise, return false.
*/ 



// the problem is to detect is there any possible way to create a non directed acyclic graph
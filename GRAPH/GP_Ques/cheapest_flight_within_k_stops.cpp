#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<list>
using namespace std;


class Node{

public:
    int K;
    int Cost;
    int Nod;

    Node(int K,int Cost,int Nod){
        this->K=K;
        this->Cost=Cost;
        this->Nod=Nod;
    }

    bool operator < (const Node &a) const{

        if(this->K !=a.K){
            return this->K < a.K;
        }
        else if(this->Cost !=a.Cost){
            return this->Cost < a.Cost;
        }
        else{
            return this->Nod < a.Nod;
        }

    }

    bool operator > (const Node &a) const{

        if(this->K !=a.K){
            return this->K > a.K;
        }
        else if(this->Cost !=a.Cost){
            return this->Cost > a.Cost;
        }
        else{
            return this->Nod > a.Nod;
        }

    }

};


class Graph{

public:

    int totalVertix;
    list<pair<int,int>>* l;

    Graph(int n){
        this->totalVertix=n;
        l =new list<pair<int,int>> [totalVertix];
    }

    void addEdge(int u,int v,int wt){
        l[u].push_back(make_pair(v,wt));
        
    }


    int cheapest_flight(int n,int src, int dst, int k_stop){


        vector<int>Price(n,1e9);
        Price[src]=0;

        priority_queue< Node, vector<Node>, greater<Node> >Q;

        Q.push(Node(0,0,src));

        while(!Q.empty()){

            int k=Q.top().K;
            int currCost=Q.top().Cost;
            int currNode=Q.top().Nod;

            Q.pop();

            if(k==k_stop+1){
                break;
            }


            list<pair<int,int>>nbr=l[currNode];

            for(auto el: nbr){
                int v=el.first;
                int c=el.second;

                if(currCost+c < Price[v]){
                    Price[v]=currCost+c;
                    Q.push(Node(k+1,Price[v],v));
                }
            }
        }


        return Price[dst]==1e9 ? -1:Price[dst];
    }


};



int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
    Graph G(n);

    for(int i=0;i<flights.size();i++){
        G.addEdge(flights[i][0],flights[i][1],flights[i][2]);
    }

    return G.cheapest_flight(n,src,dst,K);

        
        
}




int main(){

    vector<vector<int>>flights={{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    cout<<CheapestFLight(4,flights,0,3,1);
    return 0;
}
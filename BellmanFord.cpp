/******************************************************************************

                            **BellMan Ford's Algorithm**

It's an alternaive to Dijkstra algorithm bcuz Dijkstra's algo won't work if there is a negative cycle in it.
BellMan Ford Algorithm is used to detect a negative cycle is present or not
if not it gives the Shorest path to every nodes from source node.

mechanishm behind it:
    ->  relax all the edges V-1 times
        (
         relaxation -> if(dist[u] + wt(u,v) < dist[v])
         then dist[v] = dist[u] + wt(u,v)
        )

    ->  after V-1 times, we get the shortest path to every node from source vertex
    ->  Again we relax it for one more time,
        if the shortest distance reduces, then it as a negative cycle in it.
        else no negative cycle we can get the shortest distance.



*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

struct node{
    int u;
    int v;
    int wt;
    node(int a, int b, int weight){
        u = a;
        v = b;
        wt = weight;
    }
};

int main()
{
    int V,E,src;

    cout<<"Enter the vertex: ";
    cin>>V;

    cout<<"Enter the Edges: ";
    cin>>E;

    vector<node> edges;

    for(int i=0; i<E; i++){
        int u,v,wt;
        cout<<"Enter the edges along with height: ";
        cin>>u>>v>>wt;

        edges.push_back(node(u, v, wt));
    }

    cout<<"Enter the source vertex: ";
    cin>>src;

    if(!(src>=1) && (src<=V)){
        cout<<"Invalid source vertex!";
        exit(0);
    }

    vector<int> dist(V+1, INT_MAX);
    dist[src]=0;

    for(int i=1; i<=V-1; i++){

        for(auto it : edges){
            if(dist[it.u] + it.wt < dist[it.v]){
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }

    int flag = 0;

    for(auto it : edges){
        if(dist[it.u] + it.wt < dist[it.v]){
            flag = 1;
            break;
        }
    }

    if(!flag){
        cout<<"The Shorest path to every node from source vertex "<<src<<" is: \n";
        for(int i=1; i<=V; i++){
            cout<<i<<" -> "<<dist[i]<<endl;
        }
    }else{
        cout<<"Negative Weightage in a given graph :(";
    }
    return 0;
}

/******************************************************************************

OUTPUT:

//for Negative cycle graphh

Enter the vertex: 3
Enter the Edges: 3
Enter the edges along with height: 1 2 -1
Enter the edges along with height: 2 3 -2
Enter the edges along with height: 3 1 -4
Enter the source vertex: 1

Negative Weightage in a given graph :(


*******************************************************************************/

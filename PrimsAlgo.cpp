/******************************************************************************

Prims Algorithm to find the Minimum Spanning Tree(MST),
returning the parent vector, and calculating the weight of the MST.

Mechanishm:

initialize the parent vector with -1, key vector with the value i, mstSet vector with 0.
starting node's key value will be initialized to 0

loop(V-1 times):
    find the minimal in the key array
    for that find the adjacent and update the key and parent vector

parent vector will give the minimum Spanning tree.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

vector<int> Prims(vector<pair<int, int>> adj[], int V){
    bool mstSet[V+1];
    vector<int> parent(V+1);
    int key[V+1];
    int totalweight=0;
    for(int i=1; i<=V; i++){
        mstSet[i] = 0;
        parent[i] = -1;
        key[i] = INT_MAX;
    }
    key[1] = 0;
    for(int count = 1; count<=V-1; count++){
        int min = INT_MAX, ind;
        for(int i=1; i<=V; i++){
            if(key[i]<min && mstSet[i]==0){
                min = key[i];
                ind = i;
            }
        }
        mstSet[ind] = 1;
        for(auto it : adj[ind]){
            int v = it.first;
            int weight = it.second;
            if(mstSet[v]==0 && weight < key[v]){
                totalweight+=weight;
                key[v] = weight;
                parent[v] = ind;
            }
        }
    }
    cout<<"\nWeight of the Minimum Spanning Tree is: "<<totalweight<<endl;
    return parent;
}

int main()
{
    int V,E;

    cout<<"Enter the vertex: ";
    cin>>V;

    cout<<"Enter the Edges: ";
    cin>>E;

    vector<pair<int,int>> adj[V+1];

    for(int i=0; i<E; i++){
        int u,v,w;
        cout<<"Enter the edges along with the weight: ";
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> mstArray = Prims(adj, V);

    cout<<"The Parent vector array is:\n";

    for(int i=1; i<=V; i++){
        cout<<i<<" -> "<<mstArray[i]<<endl;
    }

    return 0;
}

/******************************************************************************

OUTPUT:

Enter the vertex: 5
Enter the Edges: 6
Enter the edges along with the weight: 1 4 6
Enter the edges along with the weight: 4 2 8
Enter the edges along with the weight: 1 2 2
Enter the edges along with the weight: 2 3 3
Enter the edges along with the weight: 2 5 3
Enter the edges along with the weight: 5 3 7

Weight of the Minimum Spanning Tree is: 14
The Parent vector array is:
1 -> -1
2 -> 1
3 -> 2
4 -> 1
5 -> 2

*******************************************************************************/

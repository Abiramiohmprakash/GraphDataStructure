/******************************************************************************

To detect cycle in a DIRECTED GRAPH using Khan's algorithm.
Khan's algorithm is used to topological sort (topological sort can be find only for non-cyclic graphs).
So if we cant able to find topological sort using khan's algorithm then it has a cycle in it.
else it doesn't have a cycle in it.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

bool isCyclic(vector<int> adj[], int V){

    queue<int> q;
    vector<int> indeg(V+1, 0);

    for(int i=1; i<=V; i++){
        for(int it: adj[i]){
            indeg[it]++;
        }
    }

    for(int i=1;i<=V;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }

    int count = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        count++;

        for(int it: adj[node]){
            indeg[it]--;
            if(indeg[it]==0){
                q.push(it);
            }
        }
    }

    if(count == V){
        return false;
    }
    return true;

}


int main()
{
    int V,E;

    cout<<"Enter no of vertixes: ";
    cin>>V;

    cout<<"Enter no of edges: ";
    cin>>E;

    vector<int> adj[V+1];

    for(int i=0; i<E; i++){
        int u,v;
        cout<<"Enter the edges: ";
        cin>>u>>v;

        adj[u].push_back(v);
    }

    if(isCyclic(adj, V)){
        cout<<"\nYes! It has a cycle.";
    }else{
        cout<<"No! It doesn't have a cycle.";
    }

    return 0;
}

/******************************************************************************

OUTPUT:

Enter no of vertixes: 4
Enter no of edges: 4
Enter the edges: 1 2
Enter the edges: 2 3
Enter the edges: 3 4
Enter the edges: 4 2

Yes! It has a cycle.

*******************************************************************************/



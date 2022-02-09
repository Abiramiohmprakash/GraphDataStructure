/******************************************************************************

                                **Topological sort using DFS**
1. Create a temporary stack.
2. Call the recursive function for any one of the vertex.
3. Recursively call topological sorting for all of its adjacent vertices,
   then push it to the stack.
4. Atlast, print the elements in the stack.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

void helpTopo(int node, vector<int> adj[], vector<int> &vis, stack<int> &s){

    vis[node]=1;

    for(auto it : adj[node]){
        if(vis[it]==0){
            helpTopo(it, adj, vis, s);
        }
    }
    s.push(node);
}

vector<int> findTopo(vector<int> adj[], int V){

    stack<int> s;
    vector<int> vis(V+1, 0);

    for(int i=1; i<=V; i++){
        if(vis[i]==0){
            helpTopo(i, adj, vis, s);
        }
    }

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;

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

    vector<int> ans = findTopo(adj, V);

    cout<<"\nTopological Sort: ";
    for(int it: ans){
        cout<<it<<" ";
    }
    return 0;
}

/******************************************************************************

OUTPUT:

Enter no of vertixes: 6
Enter no of edges: 6
Enter the edges: 6 1
Enter the edges: 6 3
Enter the edges: 3 4
Enter the edges: 4 2
Enter the edges: 5 2
Enter the edges: 5 1

Topological Sort: 6 5 3 4 2 1

*******************************************************************************/

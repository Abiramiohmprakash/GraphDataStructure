/******************************************************************************

                                    **DFS TRAVERSAL**
1. call the dfs function with any one of the graph's vertices.
2. add it to the dfs vector and mark it as visited.
3. Iterate through the vertex's adjacent nodes. call the recursie dfs function for the adjacent nodes which aren't not visited.
4. Keep repeating steps 2 and 3 until all the nodes are visited.

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;
void solveDfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &dfs)
{
    dfs.push_back(node);
    vis[node]=1;
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            solveDfs(it, vis, adj, dfs);
        }

    }

}
vector<int> FindDfs(int V, vector<int> adj[])
{
    vector<int> dfs;
    vector<int> vis(V+1,0);
    for(int i=1;i<=V;i++)
    {
        if(!vis[i])
        {
            solveDfs(i, vis, adj, dfs);
        }

    }
    return dfs;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    int V,E;
    cout<<"Enter number of vertixes: ";
    cin>>V;
    cout<<"Enter number of edges: ";
    cin>>E;
    vector<int> adj[V+1];
    for(int i=0;i<E;i++)
    {
        int u,v;
        cout<<"Enter edges: ";
        cin>>u>>v;
        addEdge(adj, u, v);

    }
    vector<int> ans = FindDfs(V,adj);
    cout<<"\nDFS Traversal -> ";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" -> ";

    }
    return 0;

}

/******************************************************************************

OUTPUT:

Enter number of vertixes: 7
Enter number of edges: 6
Enter edges: 1 2
Enter edges: 2 4
Enter edges: 4 6
Enter edges: 6 7
Enter edges: 2 7
Enter edges: 3 5

DFS Traversal -> 1 -> 2 -> 4 -> 6 -> 7 -> 3 -> 5

*******************************************************************************/

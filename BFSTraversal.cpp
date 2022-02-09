/******************************************************************************

                                **BFS TARVERSAL OF A GRAPH**
1. Use a for loop so that if a graph has multiple components it can be covered
2. Start by putting graph's vertices at the back of a queue and mark it as visited.
3. Take the front item of the queue and add it to the bfs vector(the one which is going to be returned form this function).
4. Iterate the vertex's adjacent nodes. Add the ones which aren't in the visited list to the back of the queue and mark it as visited.
5. Keep repeating steps 3 and 4 until the queue is empty.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

vector<int> FindBfs(int V, vector<int> adj[]){

    vector<int> bfs;
    vector<int> vis(V+1, 0);

    for(int i=1; i<=V; i++){

        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i]=1;

            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for(int it : adj[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
        }
    }
    return bfs;

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

	for(int i=0;i<E;i++){
        int u,v;
        cout<<"Enter edges: ";
        cin>>u>>v;
        addEdge(adj, u, v);
	}


    vector<int> ans = FindBfs(V,adj);

    cout<<"\n\nThe BFS Traversal for the given graph is:\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}


/******************************************************************************

OUTPUT:

Enter number of vertixes: 7
Enter number of edges: 6
Enter edges: 1 2
Enter edges: 2 3
Enter edges: 3 5
Enter edges: 5 7
Enter edges: 2 7
Enter edges: 4 6


The BFS Traversal for the given graph is:
1 2 3 7 5 4 6

*******************************************************************************/

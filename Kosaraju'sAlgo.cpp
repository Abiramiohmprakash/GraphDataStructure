/******************************************************************************
                                 KosaRaju's Algorithm
                    Strong Connected Components in a given graph

1. Sort the edges in order of their finishing time (i.e by Topological sort)
2. Transpose the given graph (changing the direction of the edge)
3. Call the recursive DFS function for Transposed graph according to the Topological sort.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &isVis, vector<int> adj[], stack<int> &st){
    isVis[node] = 1;
    for(auto it : adj[node]){
        if(!isVis[it]){
            dfs(it, isVis, adj, st);
        }
    }
    st.push(node);
}

void revDfs(int node, vector<int> &isVis, vector<int> transpose[]){

    cout<<node<<" ";
    isVis[node] = 1;
    for(auto it : transpose[node]){
        if(!isVis[it]){
            revDfs(it, isVis, transpose);
        }
    }
}



int main()
{
    int V,E;

    cout<<"Enter the vertex: ";
    cin>>V;

    cout<<"Enter the Edges: ";
    cin>>E;

    vector<int> adj[V+1];

    for(int i=0; i<E; i++){
        int u,v;
        cout<<"Enter the edges: ";
        cin>>u>>v;

        adj[u].push_back(v);
    }

    stack<int> st;
    vector<int> isVis(V+1, 0);
    for(int i=1; i<=V; i++){
        if(!isVis[i]){
            dfs(i, isVis, adj, st);
        }
    }

    vector<int> transpose[V+1];

    for(int i=1; i<=V; i++){
        isVis[i] = 0;
        for(auto it : adj[i]){
            transpose[it].push_back(i);
        }
    }

    cout<<"\nStrong Connected Components are: "<<endl;
    while(!st.empty()){
        int node = st.top();
        st.pop();

        if(!isVis[node]){
            revDfs(node, isVis, transpose);
            cout<<endl;
        }
    }

    return 0;
}

/******************************************************************************

OUTPUT:

Enter the edges: 2 3
Enter the edges: 3 1
Enter the edges: 2 4
Enter the edges: 4 5

Strong Connected Components are:
1 3 2
4
5

*******************************************************************************/


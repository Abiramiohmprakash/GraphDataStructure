/******************************************************************************

                        Minimum spanning Tree using Krukal's algorithm

1. create rank vector with initialization of 0 and parent vector with i.
2. sort the graph (adjaceny list) in increasing order of weights.
3. iterate through the edges
4. if the edge's vertexes doesn't belong to the same component(check it using findParent function),
   add it to parent vector, and make the two vertexes as single component using union function
5. after iterating all the edges, parent vector will have the MST.


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

bool comparator(node a, node b){
    return a.wt < b.wt;
}

int findParent(int u, vector<int> &parent){
   if(u == parent[u]){
       return u;
   }
   return parent[u] = findParent(parent[u], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank){

    u = findParent(u, parent);
    v = findParent(v, parent);

    if(rank[u] < rank[v]){
        parent[u] = v;
    }else if (rank[v] < rank[u]){
        parent[v] = u;
    }else{
        parent[v] = u;
        rank[u]++;
    }

}

int main()
{
    int V,E;
    cout<<"Enter the no of vertexes: ";
    cin>>V;

    cout<<"Enter the no of Edges: ";
    cin>>E;

    vector<node> edges;
    for(int i=0; i<E; i++){
        int u,v,wt;
        cout<<"Enter the edges along with the weight: ";
        cin>>u>>v>>wt;
        edges.push_back(node(u,v,wt));
    }
    sort(edges.begin(), edges.end(), comparator);

    vector<int> parent(V+1);
    vector<int> rank(V+1, 0);

    for(int i=1; i<=V; i++){
        parent[i] = i;
    }

    int costOfMst = 0;
    vector<pair<int,int>> mst;

    for(auto it : edges){
        if(findParent(it.v, parent) != findParent(it.u, parent)){
            costOfMst += it.wt;
            mst.push_back({it.u, it.v});
            unionn(it.u, it.v, parent, rank);
        }
    }

    cout<<"\nCost of the Minumum Spanning Tree is: "<<costOfMst<<endl;
    for(auto it:mst){
        cout<<it.first<<" -> "<<it.second<<endl;
    }
    return 0;
}

/******************************************************************************

OUTPUT:

Enter the no of vertexes: 6
Enter the no of Edges: 9
Enter the edges along with the weight: 5 1 4
Enter the edges along with the weight: 5 4 9
Enter the edges along with the weight: 4 1 1
Enter the edges along with the weight: 1 2 2
Enter the edges along with the weight: 4 2 3
Enter the edges along with the weight: 4 3 5
Enter the edges along with the weight: 3 2 3
Enter the edges along with the weight: 3 6 8
Enter the edges along with the weight: 2 6 7

Cost of the Minumum Spanning Tree is: 17
4 -> 1
1 -> 2
3 -> 2
5 -> 1
2 -> 6



*******************************************************************************/

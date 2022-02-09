/******************************************************************************

-->Dijkstra's Algorithm to find the shortest Path
   from source vertex to each and every vertex in a undirected graph.
-->Here priority_queue is used(min_heap), set can  also be used.

1. store a maximum value(infinity) to all the vertexes except source(which will be initialized as 0) in distance vector.
2. push it into the priority_queue.
3. start traversing the queue, compare the top element with the adjacent element distance.
4. if current distance + next vertex Distance < distance[nextVertex]
   change it as distance[nextVertex] = current distance + next vertex Distance
   push it to the priority_queue
5. continue the above steps until the queue is empty.
6. Distance vector will store the distance from source vertex to other vertexes.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

vector<int> Dijkstra(vector<pair<int,int>> adj[], int V, int src){

    priority_queue< pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    vector<int> distTo(V+1, INT_MAX);

    distTo[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){

        int currdist = pq.top().first;
        int currVex = pq.top().second;
        pq.pop();

        for(auto it : adj[currVex]){

            int nextVex = it.first;
            int nextDist = it.second;

            if(currdist + nextDist < distTo[nextVex]){
                distTo[nextVex] = currdist + nextDist;
                pq.push({distTo[nextVex], nextVex});
            }
        }
    }

    return distTo;

}

int main()
{
    int V,E,src;

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


    cout<<"Enter the source vertex: ";
    cin>>src;
    if(!(src>=1 && src<=V)){
        cout<<"Invalid source vertex!";
        exit(0);
    }

    vector<int> shortPath = Dijkstra(adj, V, src);

    cout<<"\nShorest distance from "<<src<<" to each node is:\n";

    for(int i=1; i<=V; i++){
        cout<<i<<" -> "<<shortPath[i]<<endl;
    }

    return 0;
}

/******************************************************************************

OUTPUT:

Enter the vertex: 5
Enter the Edges: 6
Enter the edges along with the weight: 1 2 2
Enter the edges along with the weight: 2 5 5
Enter the edges along with the weight: 1 4 1
Enter the edges along with the weight: 4 3 3
Enter the edges along with the weight: 2 3 4
Enter the edges along with the weight: 3 5 1
Enter the source vertex: 1

Shorest distance from 1 to each node is:
1 -> 0
2 -> 2
3 -> 4
4 -> 1
5 -> 5

*******************************************************************************/

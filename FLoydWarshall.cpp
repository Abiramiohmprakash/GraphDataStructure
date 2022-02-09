/******************************************************************************

The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem.
It helps to find shortest distances between every pair of vertices
   in a given edge weighted directed Graph using dynamic Programming


*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define INF 1000000
#define MAX 100

void floydWarshall(int adj[MAX][MAX], int V) {

      int matrix[V+1][V+1];
      int i, j, k;

      for (i = 1; i <=V; i++)
        for (j = 1; j <=V; j++)
          matrix[i][j] = adj[i][j];


      for (k = 1; k <=V; k++) {
        for (i = 1; i <=V; i++) {
          for (j = 1; j <=V; j++) {
            if (matrix[i][k] + matrix[k][j] < matrix[i][j])
              matrix[i][j] = matrix[i][k] + matrix[k][j];
          }
        }
      }

     cout<<"\n\nShortest Distance from each node to other nodes: "<<endl;
     for (int i = 1; i <= 4; i++) {
         cout<<i<<" ->";
        for (int j = 1; j <= 4; j++) {
            if (matrix[i][j] == INF)
            cout<<" INF ";
            else
            cout<<"  "<<matrix[i][j]<<"  ";
        }
        cout<<"\n";
      }
}


int main() {

  int V,E;
  cout<<"Enter no of vertexes : ";
  cin>>V;
  cout<<"Enter no of edges: ";
  cin>>E;
  int adj[MAX][MAX];

  for(int i=1; i<=V; i++){
      for(int j=1; j<=V; j++){
          adj[i][j] = INF;
      }
      adj[i][i]=0;
  }

  for(int i=1; i<=E; i++){
      int u,v,wt;
      cout<<"Enter the Edges alomg with the weight: ";
      cin>>u>>v>>wt;
      adj[u][v] = wt;
  }

  floydWarshall(adj, V);
  return 0;
}

/******************************************************************************

OUTPUT:

Enter no of vertexes : 4
Enter no of edges: 6
Enter the Edges alomg with the weight: 1 2 3
Enter the Edges alomg with the weight: 2 1 2
Enter the Edges alomg with the weight: 3 2 1
Enter the Edges alomg with the weight: 1 4 5
Enter the Edges alomg with the weight: 4 3 2
Enter the Edges alomg with the weight: 2 4 4


Shortest Distance from each node to other nodes:
1 ->  0    3    7    5
2 ->  2    0    6    4
3 ->  3    1    0    5
4 ->  5    3    2    0


*******************************************************************************/

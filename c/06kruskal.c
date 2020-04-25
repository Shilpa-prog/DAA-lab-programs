/*
  Find Minimum Cost Spanning Tree of a given undirected graph using Kruskal's algorithm.
*/

#include <stdio.h>
#include <stdlib.h>

int i, j, k, a, b, u, v, n, ne = 1, min, mincost = 0, cost[9][9], parent[9];

int find(int i)
{
  while(parent[i])
    i=parent[i];
  return i;
}

int uni(int i,int j)
{
  if (i!=j)
  {
    parent[j]=i;
    return 1;
  }
  return 0;
}

int main(int argc, char const *argv[])
{
  printf("Implementation of Kruskal's algorithm\n");
	printf("Enter the no. of vertices\n");
	scanf("%d", &n);
	printf("Enter the cost adjacency matrix\n");
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			scanf("%d", &cost[i][j]);

  // condition to check wether graph is connected or not
  for (i = 1; i <=n ; i++)
  {
    int isdisconneted=1;    // let the graph is diconnected
    for (j = 1; j <=n ; j++)
    {
      if (cost[i][j] > 0 && cost[i][j] < 999)
      {
        isdisconneted=0; // not disconnected
      }
    }
    if (isdisconneted)
    {
      printf("Given geaph is disconnected\n");
      return 0;
    }
  }

  printf("The edge of Minimum Spanning tree is \n");
  while (ne < n)
  {
    for (i = 1, min = 999 ; i <= n; i++)
    {
      for (j = 1; j <= n; j++)
      {
        if (cost[i][j] < min)
        {
          min = cost[i][j];
          a = u = i;
          b = v = j;
        }
      }
    }
    u = find(u);
    v = find(v);
    if (uni(u,v))
    {
      printf("%d edge(%d, %d) = %d\n",ne++,a,b,min);
      mincost += min;
    }
    cost[a][b]=cost[b][a]=999;
  }
  printf("Minimum cost  =  %d\n", mincost);
  return 0;
}

/*Output
Implementation of Kruskal's algorithm
Enter the no. of vertices
6
Enter the cost adjacency matrix
0 3 999 1 999 999
3 0 1 3 999 999
999 1 0 1 5 4
1 3 1 0 6 999
999 999 5 6 0 2
999 999 4 999 2 0
The edge of Minimum Spanning tree is
1 edge(1, 4) = 1
2 edge(2, 3) = 1
3 edge(3, 4) = 1
4 edge(5, 6) = 2
5 edge(3, 6) = 4
Minimum cost  =  9
*/
